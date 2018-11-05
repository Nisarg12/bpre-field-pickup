#pragma once
#include "types.h"

void pokemon_setattr(struct pokemon*, u8, void*);
 u32 pokemon_getattr(struct pokemon*, u8, void*);

u16 rand(void);
u8 b_copy_species_ability(u16, u8, u32);