.gba
.thumb
.open "test.gba", 0x8000000

.org allocation
.area allocation_size
    .importobj "build/src/relocatable.o"
.endarea

.org _atkE5_pickupitemcalculation_
.area 0xE8, 0xFF
    .importobj "build/src/atkE5_pickupitemcalculation.o"
.endarea

.close

.include "functions.s"

.arm
.include "constants.s"
