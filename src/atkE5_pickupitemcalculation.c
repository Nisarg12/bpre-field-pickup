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