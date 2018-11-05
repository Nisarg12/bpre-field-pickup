#include "defines.h"

u16 choose_item (u8 level) {
    u32 row_num = (level - 1) / 10;
    u16* common_row = pickup_common_items + row_num;
    u16* rare_row = pickup_rare_items + row_num;
    
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