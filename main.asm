.gba
.thumb
.open "test.gba", 0x8000000

.org free_space
.importobj "build/src/relocatable.o"

.org _atkE5_pickupitemcalculation_

.area 232, 0xFF
    ldr r3, =atkE5_pickupitemcalculation|1
    bx r3
    .pool
.endarea

.close

.include "functions.s"

.arm
.include "constants.s"