# tscenaro.cpp source module

The module owns 82 normal functions in PDB source order.

The direct translation unit keeps 79 matching owners. The following owners stay accepted drift:

- `0052B5F0` has an 8-byte grouped difference.
- `0052B630` has an 8-byte grouped difference.
- `0052C0B0` has a 7-byte scheduling difference.

The source merge does not change their recovery status.

`tscenaro.h` includes `tplayer.h`. It no longer defines a local TRIBE_Player
or TRIBE_Player_Tech surface. Calls use tech_abling(long, unsigned char).
tscenaro.cpp includes tech.h for check_for_new_tech().
The fanout candidate has 79 exact matches.
