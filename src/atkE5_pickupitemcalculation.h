#pragma once

#include "types.h"
#include "pokemon_data_request.h"
#include "pokemon.h"
#include "abilities.h"
#include "items.h"
#include "pickup_items.h"

typedef u16 (*rand_t) (void);
#define rand ((rand_t) (0x08044EC8 |1))

typedef ability_t (*b_copy_species_ability_t) (pokemon_species_t, u8, u32);
#define b_copy_species_ability ((b_copy_species_ability_t) (0x08040D38 |1))

#define party_player ((pokemon_t*) 0x02024284)
#define b_movescr_cursor (*((u32*) 0x02023D74))

item_t choose_item (u8 level);