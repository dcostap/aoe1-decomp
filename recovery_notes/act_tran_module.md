# act_tran.cpp module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\act_tran.cpp`.
- Source order follows the address and line sequence from 00406D60 through
  00407420.
- The module has 10 normal owners and 1,629 normal bytes.
- The 00406D90 vector-deleting destructor is compiler generated.
- The module uses `config/flags/00406E50_set_state.rsp`.
  This response file keeps `/GX` for the original EH frame.

## Ownership

The normal owners are:

- 00406D60 `RGE_Action_Transport` constructor
- 00406DC0 `RGE_Action_Transport` constructor
- 00406E00 `first_in_stack` (accepted drift)
- 00406E50 `set_state`
- 00406F90 `update`
- 00407160 `stop`
- 00407170 `move_to`
- 004071A0 `work`
- 004072B0 `next_to_drop_off_terrain`
- 00407420 `targetZone`

The old grouped source had nine exact owners and one accepted-drift owner.
The migrated source keeps the same status order. The direct candidate now
matches all nine exact owners. `first_in_stack` remains accepted drift.

## Header and dependency closure

`include/act_tran.h` is the direct module header. It owns the
`RGE_Action_Transport` declaration. It uses the canonical `RGE_Action` base
surface from `include/action.h`.

`act_tran.h` includes `include/act_move.h` because `set_state` constructs a
complete `RGE_Action_Move_To`. The `act_move.h` owner supplies its proven
constructor surface and 0x44 size. `act_tran.h` does not redeclare that class.

Terra 1 `tact_lst` depends on `include/act_tran.h` for the canonical
`RGE_Action_Transport` owner. This header-only pass records the dependency;
it does not change the tact_lst source or context header.

`inventory/types/dumps/RGE_Action_Transport.txt` records an empty
`RGE_Action`-derived body with no fields or gaps and size `0x40`. The
transport overrides retain the base slots for `first_in_stack` (`+0x1C`),
`update` (`+0x28`), `stop` (`+0x2C`), `move_to` (`+0x30`), `work` (`+0x34`),
and `set_state` (`+0x5C`). `next_to_drop_off_terrain` uses the derived slot at
`+0x60`. The two PDB constructors and `targetZone` are nonvirtual.

`src/act_tran.cpp` includes these complete owner headers:

- `include/act_tran.h`
- `include/act_obj.h` for the action-object inheritance and fields
- `include/act_list.h` for action-list fields and methods
- `include/map.h` for map dimensions and terrain lookup
- `include/player.h` for player world and notification methods
- `include/task.h` for task terrain and move-sprite fields
- `include/world.h` for the world map field

The action-object include chain supplies the canonical `move_obj.h`,
`ani_obj.h`, `stat_obj.h`, and `m_s_obj.h` owner surfaces. No context header,
local class layout, context macro, source wrapper, or inline assembly remains
in the migrated module.

## Migration

The former `src/act_tran_tu.cpp` wrapper and its ten source-bank fragments were
replaced by the one compiler-facing owner `src/act_tran.cpp`. The definitions
remain in PDB source order.

The transport sentinel keeps the proven stored-dword test for `-1.0f`.
The notification order, terrain checks, and state transitions remain unchanged.
In `update` case `0x0D`, explicit `int` casts on both `id` arguments and
explicit `long` casts on the final three arguments select the original
virtual six-argument `notify` slot. Without these casts, canonical overload
resolution selects the nonvirtual helper or reports an ambiguity.

## Validation

The VC5 header probe compiled with `config/flags/default.rsp`. Its typedef
checks confirm `RGE_Action_Transport` is 0x40 bytes and `RGE_Action_Move_To`
is 0x44 bytes. No act_tran source candidate was built in this pass.

Probe source: `build/abi_probe/act_tran_header_probe.cpp`.

Command:

`CL.EXE @config/flags/default.rsp /Iinclude /Fobuild/abi_probe/act_tran_header_probe.obj build/abi_probe/act_tran_header_probe.cpp`

Result:

- return code: `0`;
- compiler output: `act_tran_header_probe.cpp`; and
- object SHA-256: `7c20ff3bef12329dbe8856106d0a3964d153b75e501659b525f5a5ad73b1a818`.

The candidate proposal is `build/candidate_tus/act_tran.json`. It uses
`src/act_tran.cpp`, the `/GX` response file, nine exact owner claims, one
observed accepted-drift owner, and the generated destructor entry.

The direct candidate baseline compiled the natural module source and produced
414 bytes with a 38-byte mismatch in `00406F90 update`. All other exact owners
matched. The checker identified one direct `notify` call in the rebuild where
the executable uses virtual slot `+0x148`.

The following source hypotheses were tested:

- Removing all casts restored the direct helper and the 38-byte mismatch.
- Restoring the full explicit cast set produced `MATCH` and `0.0000%`.
- Removing the redundant-looking `int` casts made VC5 report ambiguous
  `notify` overloads.
- Keeping the `int` casts but removing the trailing `long` casts also made VC5
  report ambiguous overloads.
- Removing all but the first two `int` casts produced the same ambiguity.

The exact source uses this full five-cast set. A walkback to the clean baseline restored
the mismatch. Reapplying the casts restored exact bytes. The final grouped
validation reports 9/9 exact owners, generated destructor `MATCH`, and the
unchanged accepted-drift result for `first_in_stack`.

Validation commands:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/act_tran.json --output-dir build/candidate_tus/act_tran_final`

Result: exact owners 9/9; generated owner 1/1; accepted drift unchanged at
11 differing bytes. The standalone target check also reports `MATCH`,
`0.0000%`, 414/414 bytes, 19/19 aligned calls, and correct owner and boundary.
