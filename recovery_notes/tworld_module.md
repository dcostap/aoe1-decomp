# TWorld.cpp source module

`src/tworld.cpp` owns all 30 normal PDB bodies from `tworld.cpp`, in source
and address order. The module uses `include/tworld.h` and canonical RGE,
TRIBE, Scenario, Map, Player, and communications owners.

The three scratch bodies remain honest natural reconstructions:
`0052EAC0`, `0052EF30`, and `005303F0`. Their bodies compile in the complete
module and keep the known behavior and call surfaces. They are not exact-owner
claims.

## Accepted-drift evidence

The seven rows below retain reviewed, behavior-equivalent drift. They remain
unregistered. Only the 20 matching bodies have exact translation-unit owners.

- `0052E220 data_load_players_type`: The source loads `p2` before FS setup,
  while the executable loads it after FS setup. No throwing operation occurs
  between those steps. Calls, predicates, EH cleanup, allocation, constructor,
  stores, and memory effects match. The remaining differences are register
  scheduling and an equivalent base/index swap.
- `0052E4C0 map_init`: The natural `/GX` new/null/constructor/common-store
  form adds a dead `test eax,eax; jne +0` join. It shifts four epilogue bytes
  into padding, with no behavior or memory difference.
- `0052E530 command_init`: The same `/GX` common-store join adds the dead
  `test eax,eax; jne +0` sequence. It shifts four epilogue bytes into padding;
  calls, stores, and memory effects match.
- `0052E590 scenario_init(int, RGE_Game_World*)`: The same constructor,
  null, and common-store pattern adds the dead four-byte join sequence. Only
  the epilogue and padding shift; behavior is unchanged.
- `0052E5F0 scenario_init(RGE_Game_World*)`: The same `/GX` phi-merge artifact
  adds `test eax,eax; jne +0` before the common store. The four-byte shift is
  confined to the epilogue and padding.
- `0052E650 effects_init`: The natural common-store form converges on the same
  dead `/GX` join sequence. Calls, construction, store, and memory effects
  match; only four epilogue bytes move into padding.
- `0052E920 setup_gaia`: The natural `/GX` new/null/constructor/common-store
  form adds the same dead four-byte join. The first 81 bytes match, and the
  remaining shift affects only the epilogue and padding.

The old prefix and phase wrappers are migration scaffolds and must not be
restored. The unified source uses typed fields, canonical globals, named string
data, standard CRT declarations, and structured control flow. It has no
absolute address expressions or C-style casts.

`TRIBE_Zone_High_Score_Info` uses the `struct` tag. The original
`00531240 fill_in_score` symbol encodes this record with `U`, and the exact
owner requires that tag. This direct symbol evidence overrides the generated
type dump's `class` label.

## Communications access

The PDB marks `TCommunications_Handler::WasKicked` private. It does not record
friend declarations. Exact bytes for `00531350 send_zone_score_info` prove that
`TRIBE_World` reads this field directly. `TCommunications_Handler` therefore
declares `TRIBE_World` as a friend and keeps `WasKicked` private. No getter or
raw access shim is present.
