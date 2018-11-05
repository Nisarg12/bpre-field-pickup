#include "defines.h"

u16 pickup_common_items[PU_NUM_COMMON_ITEMS] = {
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_SUPERPOTION,
    ITEM_GREATBALL,
    ITEM_REPEL,
    ITEM_ESCAPEROPE,
    ITEM_XATTACK,
    ITEM_FULLHEAL,
    ITEM_ULTRABALL,
    ITEM_HYPERPOTION,
    ITEM_RARECANDY,
    ITEM_PROTEIN,
    ITEM_REVIVE,
    ITEM_HPUP,
    ITEM_FULLRESTORE,
    ITEM_MAXREVIVE,
    ITEM_PPUP,
    ITEM_MAXELIXIR
};

u16 pickup_rare_items[PU_NUM_RARE_ITEMS] = {
    ITEM_HYPERPOTION,
    ITEM_NUGGET,
    ITEM_KINGSROCK,
    ITEM_FULLRESTORE,
    ITEM_ETHER,
    ITEM_WHITEHERB,
    ITEM_TM44,
    ITEM_ELIXIR,
    ITEM_TM01,
    ITEM_LEFTOVERS,
    ITEM_TM26
};

// -----------------------------------------------------------------------------

u32 pickup_common_item_ceilings[PU_COMMON_PER_ROW] = {
    19661, 26214, 32768, 39322, 45875, 52429, 58982, 61604, 64225
};

u32 pickup_rare_item_ceilings[PU_RARE_PER_ROW] = { 64881, 65536 };
