# tribegam.cpp source reunification

PDB source: `C:\msdev\work\age1_x1\tribegam.cpp`.

The module owns 118 normal functions. Their source order follows the PDB line bands from 160 through 5691. The compiler-facing source is `src/tribegam.cpp`. The shared module declarations are in `include/tribegam.h`.

## Terra 6 header checkpoint

`include/tribegam.h` now includes the canonical `include/basegame.h`.
It owns only these records:

- `TRIBE_Game`;
- `TRIBE_Game::TRIBE_Game_Options`;
- the five nested option enums; and
- `MouseClickInfo`.

All other class names are forward declarations from the canonical base header
or from this header. The header has no copied base-game, object, player, world,
sound, panel, draw, map, or CRT class layout.

The PDB type dumps prove this layout:

- `RGE_Base_Game`: base size `0xA24` (`inventory/types/dumps/RGE_Base_Game.txt`);
- `TRIBE_Game`: derived size `0x1254`, with fields from `+0xA24`
  (`inventory/types/dumps/TRIBE_Game.txt`);
- `TRIBE_Game_Options`: size `0x6C`, with enum-typed fields
  (`inventory/types/dumps/TRIBE_Game_TRIBE_Game_Options.txt`); and
- `MouseClickInfo`: struct size `0x2C`
  (`inventory/types/dumps/MouseClickInfo.txt`).

The VC5 layout probe passed. It checked sizes `0x2C`, `0x6C`, and `0x1254`.
The probe neutralized `__stdcall` only to work around the current canonical
`basegame.h` declaration. A normal probe remains blocked because the PDB
`RGE_Base_Game::wnd_proc` symbol uses `__stdcall` (`UAG`), while
`basegame.h` does not publish that calling convention. This base-game repair
belongs to the Base Game owner, not this checkpoint.

## Source hold after the header split

`src/tribegam.cpp` is intentionally held. It still needs complete definitions
for `RGE_Prog_Info`, `RGE_Game_Info`, `RGE_Game_World`, `TRIBE_World`,
`RGE_Player`, `RGE_Scenario`, `RGE_Scenario_Header`, `TRIBE_Scenario_Header`,
`T_Scenario`, `TPanel` and its screen types, `TMusic_System`, `TSound_Driver`,
and `TCommunications_Handler`.

The source now consumes `main.h`, `gameinfo.h`, `world.h`, `tworld.h`,
`player.h`, `scenario.h`, `tscenaro.h`, `music.h`, `sounddrv.h`, `panel.h`,
`panel_ez.h`, `scr_*`, and `com_hand.h`. These providers share the canonical
Base Game layout without local fallback declarations.

The source still uses external PDB data symbols for `DAT_0086BCE0`, the two
click-table families, `video_codec_available`, and the run-log state. Their
storage definitions are not present in this worktree. The resource-file and
Video for Windows imports remain external SDK interfaces. The canonical Base
Game, panel, world, sound, scenario, player, and communications headers now
publish the helper surface used here.

`include/game_globals.h` now declares the eight-entry `DAT_0086bcac` palette
table. This changes a scalar placeholder into its proven array provider.

## Evidence

- The fresh module status lists 21 matching, 96 scratch, and one verified-logic owner.
- The packet lists the compiler-generated vector-deleting destructor at `00521380`, symbol `??_ETRIBE_Game@@UAEPAXI@Z`, size 30. It is emitted by the natural `TRIBE_Game` virtual destructor surface. It is not a normal source owner.
- The pre-migration wrapper and final source object both emit the weak `??_E` identity and the defined `??_G` fallback body. The generated body has the same four relocation-placeholder differences in both objects.
- The grouped source order is the packet order. It is not VA order at the start because `video_sub_wnd_proc` precedes the constructor in the PDB line stream.
- Before this header split, the full source compiled with the pinned VC5 compiler and `config/flags/00521120_TRIBE_Game.rsp` (`/nologo /c /O2 /Oy /GX`).
- The earlier mechanical consolidation matched the pre-migration wrapper for the 115 publicly named normal owners checked. Static owners at `00523AE0` and `00526170` need address-based grouped validation.
- The final source cleanup uses the period SDK record and API names in `setup`. This changes that existing scratch owner from the wrapper's 1984-byte emitted body to a 2000-byte emitted body. The packet boundary is 2061 bytes. This is a recorded source-recovery regression, not an exactness promotion.
- The existing 21 registered exact anchors remain byte-identical in the final source object. The 2-byte `calc_timing_text` difference was already present between the wrapper and the normalized source context.

## Migration changes

- Merged all 118 reviewed source-bank bodies into one natural source file in PDB order.
- Replaced the wrapper-only local context with the module header.
- Removed source-bank fallback class declarations and context-selection guards from the compiler-facing source.
- Normalized fragment-relative include paths for the new source location.
- Kept the existing nonexact source states. This migration does not promote accepted drift, scratch, or verified logic.

## Exactness regression record

The reunified source preserves the pre-migration wrapper object for the 21 registered exact anchors and for the publicly named owners not affected by the SDK cleanup. The `00521790` setup change is the only new broad difference. The prior grouped wrapper already had nonexact owners outside its 21 registered exact anchors. Those results remain unresolved and are not promoted by this migration.

The source-module metadata records the complete normal owner set. The
`tribegam_prefix` registration now uses `src/tribegam.cpp`.

## Open work

- The post-repair candidate validates all 21 registered owners. Each reports
  `MATCH` and `0.0000%`, with matching ownership, boundaries, relocations, and
  direct targets.
- Keep the generated destructor as a separate generated-entry check.

## Screen integration boundary

The screen integration changes only the two `TRIBE_Game` getter calls in
`src/tribegam.cpp`. The existing source debt above remains open. This change
does not repair the held `tribegam` source context or its missing declarations.
A fresh getter proof was blocked by that debt before comparison. It reported
the existing `setMapSize`, `panel_system`, `RGE_Prog_Info`, and related missing
declarations. The two getter owners remain unclaimed and unproven.

## Natural provider cleanup

The module now includes the canonical Base Game, world, scenario, panel, sound,
player, object, and communications declarations. It no longer declares local
provider layouts or carrier classes. The source uses named fields and virtual
providers for world loading, scenario cinematics, player commands, panel
selection, sound mute state, and the window procedure.

The `wnd_proc` override uses `__stdcall`. The SDK `CALLBACK` declaration in
`basegame.h` and the PDB `UAG` symbol agree on this convention.

The old address overlays are replaced with canonical global declarations and
the named click-table records. The original encoded cheat strings and sound
file names are source literals recovered from the original data image.

All gotos, C-style casts, raw object-offset views, absolute-address macros,
provider copies, and fake carrier declarations were removed from the source.
The source still owns all 118 normal bodies in PDB order.

## Fresh status checkpoint

The registered `tribegam_prefix` group was validated after this cleanup. It
reports `MATCH` and `0.0000%` for all 21 exact owners. The source module keeps
only those 21 proven `matching` rows. The other 88 old matching or accepted
drift rows moved to `scratch` with this note. Their bodies remain in the
natural module and need fresh evidence before promotion.

The canonical providers expose no complete `TribeMPSetupScreen` owner in this
worktree. `scr_mps_types.h` records its PDB field surface for the two screen
constructors used by this module. The load-game debug path cannot use the old
decompiler carrier for doppleganger movement fields, so it records only fields
owned by the canonical object classes. Reopen this work when a complete PDB
provider for that debug surface is available.
