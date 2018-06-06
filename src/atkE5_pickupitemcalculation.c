#include "atkE5_pickupitemcalculation.h"

void atkE5_pickupitemcalculation (void) {
    for (u32 i = 0; i < 6; ++i) {
        pokemon_t* pokemon = party_player + i;
        
        if (pokemon_getattr(pokemon, REQ_SPECIES) == PKMN_NONE) break;
        if (pokemon_getattr(pokemon, REQ_EGG)) continue;
        
        pokemon_species_t species = pokemon_getattr(pokemon, REQ_SPECIES);
        u8 ability_bit = pokemon_getattr(pokemon, REQ_ABILITY);
        u32 personality = pokemon_getattr(pokemon, REQ_PERSONALITY);
        
        // ~10% chance of pickup to activate
        // 6554 / 65536 ~= 10%
        if (b_copy_species_ability(species, ability_bit, personality) != ABILITY_PICKUP
            || pokemon_getattr(pokemon, REQ_HELDITEM) != ITEM_NONE
            || rand() >= 6554) continue;
        
        item_t item = choose_item(pokemon_getattr(pokemon, REQ_LEVEL));
        pokemon_setattr(pokemon, REQ_HELDITEM, &item);
    }
    
    ++b_movescr_cursor;
}

item_t choose_item (u8 level) {
    u32 row_num = (level - 1) / 10;
    item_t* common_row = pickup_common_items + row_num;
    item_t* rare_row = pickup_rare_items + row_num;
    
    u16 k = rand();
    
    for (u32 i = 0; i < PU_COMMON_PER_ROW; ++i)
        if (k < pickup_common_item_ceilings[i])
            return common_row[i];
            
    for (u32 i = 0; i < PU_RARE_PER_ROW; ++i)
        if (k < pickup_rare_item_ceilings[i])
            return rare_row[i];
            
    // will never be reached
    return ITEM_NONE;
}