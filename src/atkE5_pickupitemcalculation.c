#include "defines.h"

u16 long_call choose_item (u8 level);

void atkE5_pickupitemcalculation (void) {
    for (u32 i = 0; i < 6; ++i) {
        struct pokemon* pokemon = party_player + i;
        
        if (pokemon_getattr(pokemon, REQ_SPECIES, NULL) == PKMN_NONE) break;
        if (pokemon_getattr(pokemon, REQ_EGG, NULL)) continue;
        
        u16 species = pokemon_getattr(pokemon, REQ_SPECIES, NULL);
        u8 ability_bit = pokemon_getattr(pokemon, REQ_ABILITY, NULL);
        u32 personality = pokemon_getattr(pokemon, REQ_PERSONALITY, NULL);
        
        // ~10% chance of pickup to activate
        // 6554 / 65536 ~= 10%
        if (b_copy_species_ability(species, ability_bit, personality) != ABILITY_PICKUP
            || pokemon_getattr(pokemon, REQ_HELDITEM, NULL) != ITEM_NONE
            || rand() >= 6554) continue;
        
        u16 item = choose_item(pokemon_getattr(pokemon, REQ_LEVEL, NULL));
        pokemon_setattr(pokemon, REQ_HELDITEM, &item);
    }
    
    ++b_movescr_cursor;
}