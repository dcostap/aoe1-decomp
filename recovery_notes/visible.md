# `visible.cpp` source-module migration

- PDB source: `C:\\msdev\\work\\age1_x1\\visible.cpp`.
- Source: `src/visible.cpp`.
- Header: `include/visible.h`.
- Flags: `config/flags/default.rsp`.

The PDB owns 27 normal functions in this order:

- `0053C1B0` `RGE_Visible_Map::RGE_Visible_Map(RGE_Map*, RGE_Player*)`, lines 226 to 256.
- `0053C290` `RGE_Visible_Map::RGE_Visible_Map(int, RGE_Game_World*)`, lines 265 to 307.
- `0053C3C0` `RGE_Visible_Map::~RGE_Visible_Map`, lines 313 to 329.
- `0053C400` `RGE_Visible_Map::save`, lines 336 to 350.
- `0053C490` `RGE_Visible_Map::get_visible`, lines 361 to 382.
- `0053C4D0` `RGE_Visible_Map::set_all`, lines 389 to 436.
- `0053C5D0` `RGE_Visible_Map::explore_all`, lines 442 to 467.
- `0053C670` `RGE_Visible_Map::percentExplored`, lines 474 to 476.
- `0053C680` `RGE_Visible_Map::recomputeExplored`, lines 483 to 497.
- `0053C6C0` `RGE_Visible_Map::get_los_table`, lines 504 to 514.
- `0053C6F0` `RGE_Visible_Map::explore_terrain`, lines 521 to 658.
- `0053C920` `RGE_Visible_Map::unexplore_terrain`, lines 665 to 767.
- `0053CAC0` `RGE_Visible_Map::explore_terrain_sq`, lines 775 to 883.
- `0053CCF0` `RGE_Visible_Map::unexplore_terrain_sq`, lines 891 to 975.
- `0053CE70` `RGE_Visible_Map::checksum_visible_inputs`, lines 983 to 990.
- `0053CE80` `RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int, int)`, lines 1005 to 1026.
- `0053CEE0` `RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int, RGE_Game_World*)`, lines 1032 to 1042.
- `0053CF10` `RGE_Unified_Visible_Map::load`, lines 1046 to 1074.
- `0053CFC0` `RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map`, lines 1079 to 1084.
- `0053CFF0` `RGE_Unified_Visible_Map::save`, lines 1088 to 1095.
- `0053D040` `RGE_Unified_Visible_Map::reset`, lines 1099 to 1106.
- `0053D070` `RGE_Unified_Visible_Map::Set_Map_Offsets`, lines 1111 to 1119.
- `0053D0C0` `RGE_Unified_Visible_Map::suppress_updates`, lines 1123 to 1125.
- `0053D0D0` `RGE_Visible_Map::checksumVisible`, lines 1132 to 1140.
- `0053D110` `RGE_Visible_Map::checksumUnifiedVisible`, lines 1146 to 1154.
- `0053D150` `log_map_call`, lines 1162 to 1196.
- `0053D200` `dump_vismap_log`, lines 1199 to 1249.

The complete source keeps this PDB order. The former wrapper, source-bank
fragments, fallback declarations, and context header were removed. The bodies
were moved without byte-tuning changes.

The source-bank states are 19 matching, four accepted-drift, and four scratch
owners. The accepted-drift owners are `0053C5D0`, `0053C680`, `0053D0D0`, and
`0053D200`. The terrain owners `0053C6F0`, `0053C920`, `0053CAC0`, and
`0053CCF0` remain scratch because their prior sources have broad codegen drift.

The prior accepted-drift evidence is local. `0053C680` differs by one SIB
address-encoding byte. `0053D0D0` differs by one SIB addressing-order byte.
`0053C5D0` retains equivalent row-pointer traversal with inner-loop scheduling
drift. `0053D200` retains equivalent log output and differs in its final
register-pop and close-call order.
