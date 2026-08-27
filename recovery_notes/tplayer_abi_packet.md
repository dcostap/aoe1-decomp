# tplayer.h ABI packet

Status: owner-header completion only. The `tplayer.cpp` source module remains
held. This header does not move or rebuild any tplayer source owner.

## Ownership and layout

`include/tplayer.h` includes `include/player.h`. `RGE_Player` owns the complete
`0x220` base. `TRIBE_Player` owns the 16 fields from `0x220` through `0x848`.
The fields have no gaps:

- `tech_tree` at `0x220`;
- four update counters and `update_time` at `0x224` through `0x234`;
- `playerAI` at `0x238`;
- six 256-byte status buffers at `0x23C` through `0x83C`;
- `history` at `0x83C`; and
- `ruin_held_time` and `artifact_held_time` at `0x840` and `0x844`.

The natural size check requires `sizeof(TRIBE_Player) == 0x848`.

## Method evidence

The direct virtual declarations follow the inherited and new vtable slots.
Slots not declared by `TRIBE_Player` remain inherited from `RGE_Player`.
The new slots are `0xF8` through `0x128`: `command_give_attribute` through
`notifyAI`.

The declaration list uses these local sources:

- `inventory/pdb/function_source_map.csv`, tplayer owners `00511BD0` through
  `00519D50`, for owner names and source order;
- `build/004AB300_dumpbin_fpo.txt`, tplayer FPO symbols, for decorated owner
  identity, calling convention, and parameter types;
- `inventory/functions/0051/*.txt`, for source lines, boundaries, and calls;
- `inventory/classes/all_class_interfaces_reference.h`, for the reviewed
  inherited and derived slot sequence; and
- `inventory/types/dumps/TRIBE_Player.txt`, for the complete field record.

The nonvirtual list includes the PDB-owned `load_master_object`, `tech_cost`,
and `obj_cost` methods. The FPO records prove their reference and pointer
parameters. The `logMessage` declaration keeps its proven `__cdecl` ABI.

## Limits and blockers

This header uses forward declarations for `TRIBE_Player_Tech`,
`TribeMainDecisionAIModule`, and `TRIBE_History_Info`. It also forward declares
the pointer-only method types. It does not define Map, World, static-object,
master-object, list, node, AI, history, or TRIBE-derived victory types.

The header does not prove source-module closure. `src/tplayer_tu.cpp` and
`src/tplayer_postpad_tu.cpp` still use the held `tplayer_context.h` surface.
The source module still needs a later closure pass against all direct owners,
including the Gaia boundary and compiler-generated destructor entries.

The natural pinned-VC5 header probe passed for the class size and all 16 field
offsets. A fresh standalone `00513DA0` check returned `MATCH` at `0.0000%`.

## Existing target evidence

`00513DA0` is `TRIBE_Player::tech_abling` from `tplayer.cpp:1496-1501`.
Its FPO symbol is `?tech_abling@TRIBE_Player@@QAEXJE@Z`, with `ret 8` and direct
calls to `TRIBE_Player_Tech::enable` at `0050D383` and `disable` at `0050D306`.
The candidate source remains held in `src/scratch/00513DA0_tech_abling.cpp`.
