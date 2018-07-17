#pragma once

#include "types.h"
#include "pokemon_data_request.h"
#include "pokemon.h"
#include "abilities.h"
#include "items.h"
#include "pickup_items.h"

u16 rand(void);
ability_t b_copy_species_ability(pokemon_species_t, u8, u32);

extern pokemon_t party_player[6];
extern u32 b_movescr_cursor;

item_t __attribute__((long_call)) choose_item (u8 level);