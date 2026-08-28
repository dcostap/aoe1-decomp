# scr_cams.cpp provider hold

## Context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_cams.cpp`. The packet
reports eight normal owners in source order:

`004909D0`, `00490E30`, `00490EA0`, `00490F90`, `00490FF0`, `004911A0`,
`00491290`, and `00491350`.

Their source-line bands are 48-125, 131-152, 158-171, 177-190, 196-241,
247-278, 284-312, and 318-419. The vector-deleting destructor at `00490E10`
is compiler generated. The current wrapper owns all eight exact source-bank
definitions and uses the target `/GX` response file.

## Hold

This module cannot move to a natural direct owner in the current provider
graph. `include/scr_cams_context.h` is a copied panel and screen hierarchy.
It cannot remain in a natural module. No canonical `include/scr_cams.h` owner
surface exists in this checkout.

The cancel path constructs `TRIBE_Screen_Name`. The current
`include/scr_name.h` redeclares `TPanel`, `TEasy_Panel`, `TScreenPanel`,
`RGE_Base_Game`, `RGE_Game_Info`, and the foreign screen layouts. Including it
with the canonical Panel, Base Game, game-info, and screen providers causes
duplicate type ownership. A forward declaration cannot support the natural
constructor expression or its required `0x4A0` allocation.

`include/com_hand.h`, `include/gameinfo.h`, `include/scenario.h`, and
`include/tribegam.h` provide the communication, game-info, scenario, and game
surfaces needed by the body. The unresolved screen owner is still enough to
block the complete direct translation unit. Do not add a wrapper, fragment,
partial class, raw address, or private-symbol alias to bypass this hold.

## Reopen condition

After the screen providers publish owner-only headers, add
`include/scr_cams.h` for `TRIBE_Screen_Campaign_Selection`, write all eight
bodies in PDB order in `src/scr_cams.cpp`, and include only canonical Panel,
Base Game, game-info, campaign, game, communications, scenario, and screen
providers. Use the recovered literals and named fields. Remove
`src/scr_cams_tu.cpp`, `include/scr_cams_context.h`, and the eight source-bank
owners only after the grouped candidate validates every normal and generated
owner.

Require `MATCH`, `0.0000%`, correct ownership and boundaries, zero relocation
and direct-target errors, and a clean generated-function result before
registering the direct module.

