.gba
.thumb
.open "test.gba", 0x8000000

.freespace
.importobj "build/linked.o"

.org 0x0802CE48
ldr r3, =atkE5_pickupitemcalculation|1
bx r3
.pool

.close
