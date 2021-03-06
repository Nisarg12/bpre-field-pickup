## Pickup

In RS and FRLG, Pickup just has a static item list to pick from. Emerald expanded the number of items available for Pickup significantly, and, in the process, changed it from a list to a table - each row corresponds to a particular level range.

This copies Emerald's Pickup behavior into Fire Red.

### How do I customize this?

If you've added custom items and intend to make them available via Pickup, you will need to add appropriate `#define`s to `src/defines/items.h`.

If you don't want to use Emerald's set of items, it can be customized by `pickup_common_items` and `pickup_rare_items` in `src/pickup_items.c`. The best way to understand how the order works is to visualize it with a table, like [this](https://bulbapedia.bulbagarden.net/wiki/Pickup_(Ability)#Pok.C3.A9mon_Emerald) one from Bulbapedia.

`pickup_common_items` traces an L-shape along the common (not 1%) items - basically, start in the top left with Potion, go down to Hyper Potion, and then right to Max Elixir. `pickup_rare_items` does the same for the rare (1%) items - it traces from Hyper Potion down to Leftovers and then right to TM26.

So, if you wanted to change the set of items to that of, say, ORAS, the easiest way would be to scroll down to the table for ORAS on the linked Bulbapedia page, and trace an L-shape for the common items, and one for the rare items.

### How do I build this?

You will need to set an `ARMIPS` environment variable pointing to your `armips.exe`. You also need a `DEVKITARM` environment pointing to devkitARM v45's installation directory (likely `C:\devkitPro\devkitARM`).

Python 3.6 or later is required.

Place your ROM in the project root directory and name it `rom.gba`. Run `python scripts/makinoa`.

Your output is `test.gba`; `rom.gba` will be left unmodified.