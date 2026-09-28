# player.cpp direct composition

## Ownership

`src/player.cpp` owns the complete Player module.
It contains all 117 normal `player.cpp` PDB owners in source order.
The header-owned `RGE_Player::logStatus(FILE*, int)` body is included by this
module and emits its original symbol.

The PDB maps `0046ED40` to `player.h:300`.
The original `player.cpp` compiland emits its three-byte body.
Keep the header definition before the `player.cpp` owner sequence.
The direct object matches `0046ED40` at `0.0000%`.

`0046E750` remains compiler-generated.
It is not a handwritten source body.

## Canonical provider pass

The direct source uses canonical Player, World, Command, object, victory, visibility, and AI headers.
It does not include `player_tu_context.h` or `rge_player_context.h`.

The prior Player context used false field and method names.
The direct source now uses these proven calls:

- `RGE_Game_World::commands` at `+0x58`.
- `UnitAIModule::order` at virtual slot `+0x10`.
- `RGE_Command::command_add_waypoint(int, int, XYZBYTEPoint*, int)`.
- `RGE_Command::command_give_attribute(int, int, int, float)` at virtual slot `+0x0C`.
- `RGE_Static_Object::addUserDefinedWaypoint(XYZBYTEPoint*, int)`.
- `RGE_Object_List::update` at Player `+0x30`.
- `RGE_Doppleganger_Creator::perform_doppleganger_checks` at Player `+0x40`.
- `RGE_Visible_Map::set_all` at Player `+0x38`.

The Player source has no local class layouts or raw field offsets.

## Direct validation

The canonical full source compiled with `config/flags/gx.rsp`.
The resulting object matched all 106 registered exact owners.
Each result was `MATCH` and `0.0000%`.

The earlier grouped summary listed `0046E770`: 18 and `004706B0`: 3.
`00470CB0`: 8. It listed `0046FF90` as 13, but that was an effective-size
shortfall, not a positional byte difference. See the checksum re-review below.

The scratch rows have these byte differences.
`0046F420`: 252. `00471550`: 4 and one relocation mismatch.
`00471760`: 43 and two boundary escapes. `004718C0`: 1.
`00471940`: 1. `00471AA0`: 1.

## Selection-count source repair

The command methods use one natural `short count` output local.
They pass that local to `get_selected_objects_to_command` without casts.

This repair covers `command_make_move`, `command_make_work`, and `command_make_do`.
It also covers `command_stop`, `command_formation`, and `command_stand_ground`.

The full 117-body candidate still matches all 106 registered exact owners.
The remaining eleven rows keep their recorded status and mismatch data.

The removed wrapper and its context had no remaining consumers.

## Header-owner closure

The seven standalone header probes from the source bank are deleted. Their
bodies now live in `include/player.h` in PDB order, including the proved
return defaults. The direct Player candidate emits `0046ED40` as
`?logStatus@RGE_Player@@UAEXPAU_iobuf@@H@Z` and reports `MATCH`, `0.0000%`,
with no relocation mismatch or boundary escape.

The same candidate keeps 104 of 105 registered owners exact. `004705A0`
`set_color_table` changes by 20 bytes and one boundary escape after the
header body closure. Its register-color change is recorded as a structural
migration regression. Twenty natural variants emitted the same 28-byte basin.
The original is 27 bytes. The owner is now scratch and is not registered as
exact. The direct natural source remains unchanged.

## Historical checksum re-review — superseded 2026-09-28

The old `13` entry was the effective-size shortfall, not the positional byte
difference. A fresh baseline at state
`8844a4cd2923d3d5ee7a0395cbf56dc3419d5d33791b0e569b31364271f9e052` emitted
264 bytes against 277 and reported 213 strict differences.

The retained source repair restores the period source order, `int` attribute
countdown, and signed-short attribute test. State
`bbaa19d45a4065295a273e3e0751bbc62ef2e2ceba9abfe66af4b03b41237eb0` emits
268 bytes and reports 180 strict differences. It has the correct owner, five
aligned calls, four conditional branches, one return, and no boundary escape.

The checksum arithmetic and field ownership follow the executable. The
attribute loop truncates each float through `__ftol`. The object loop adds
state, held amount, master ID, waypoint checksum, and action checksum. It
rereads `list->node` after the waypoint call for position and action data.
The position sum stores a single-precision value after each object. The final
checksum packs the signed prefix, object count, object checksum, and attribute
checksum in base 256.

The result is blocked from accepted-drift proof. The original reads
`object_state` before the held-amount load and conversion. VC5 emits the
retained source with the float load and `__ftol` first. The original also uses
a `0x18` frame, stores the loop-carried object checksum at `[esp+20h]`, and
stores the prefix at `[esp+24h]`. The rebuilt body uses a `0x14` frame, keeps
the object checksum in `EBP`, and uses `[esp+20h]` for the prefix. These are
different stack writes and fault order. No exact source form is known.

The final closure event is
`32c9f7b9d0c466136fb742cbe340a0521ade2cb7fb728379df08e51627df5e31`. It
compiled all 125 Player owners. All 120 exact owners stayed exact, with no
exact-neighbor regressions. The registry status remains unchanged.

## Current accepted-drift re-review — 2026-09-28

This section supersedes the older checksum and closure results above for the
four assigned functions. The current body for `0046FF90` is 277 bytes, not the
older 268-byte body.

### Behavior

`0046FF90` has one proved fault-order difference for invalid mixed list
pointers. The original reads the sleeping-list count before the doppelganger
count. The rebuild reads them in reverse order. Normal-state reachability of a
one-invalid-pointer state is unknown. No source repair succeeded.

`004706B0` keeps its one relation call, arguments, count writes, and cleanup.
Its three-byte difference reverses the loop-exit branch polarity. The signed
compare and both paths are unchanged.

`00470CB0` now matches all 101 original bytes. The loops clear the original
25 selection pointers and 127 group bytes.

`00470F80` has six SIB-byte differences. Each swaps scale-one base and index
registers from EAX, ECX, and EDX. No EBP or ESP register appears, so the
default segment remains DS. The effective addresses are equal. The original
out-of-range group-index behavior remains.

No gameplay runtime test ran. The checksum pointer invariant and the normal
reachability of an invalid pointer state remain unknown.

### Source

Only `src/player.cpp` changed.
`check_ally_group` now uses a short-circuit condition and `break`.
`reset_selected` now uses two ascending array loops.
No checksum or group source change remains.
No status, registry, or header changed.

### Bytes

Final states and events:

- `0046FF90`: state `2583bfedcfaaa4f401f66289de625e9c5c6441313dbd22903c17ce0a5e030ba3`, event `e2c16eff98cea7b98ed6b32164191b7bda5ccbaf7c9e755dbc183325a1f21a37`; two-byte mismatch.
- `004706B0`: state `a2bbc19f77f4d773c1324ddb4042c7e0beb13baf457e86a1b4c16ee97870fc44`, event `5dc96560c0e0c79401482fd1c1f07f1a54ae77464f7d36f5e34243c41b2455bc`; three-byte mismatch.
- `00470CB0`: state `4e5d13c1072cdf1b5e5db72628e3f0cb8afcf78a0b241fa0efdcf5756b3c8298`, event `62f15dd8152affc4e5607359e09b62ea9cc28ba24f8eaedf006368e1f8aa1acf`; exact match.
- `00470F80`: state `58f53f4de53c7c746ebbba4b62f337439d99a11fff0d9b3651268107440b1e78`, event `c0556a9174be451544fe574608593f7387a665d95324c5a9c606fda28c91702e`; six-byte mismatch.

The final module report is
`build/validation/drift-014-player-review/report.txt`.
It covers 125 normal functions: 120 exact matches, three accepted-drift
observations, one grouped exact match for review, and one new verified-logic
observation. It reports no exact-neighbor regression.

### Integration

The audit command was
`python tools/audit_translation_unit_functions.py --affected-by src/player.cpp --jobs 1 --output-dir build/validation/drift-014-player-review`.
The queue recommends promotion review for `00470CB0`.
This work makes no status approval and changes no registry entry.

Proposal: promote `00470CB0` to exact after review.
Proposal: review accepted drift for `004706B0` and `00470F80`.
Do not approve `0046FF90` as behavior-equivalent drift until fault order is
proved safe or source repair is found.
