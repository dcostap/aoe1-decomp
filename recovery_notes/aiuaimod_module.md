# aiuaimod.cpp source module

## Context

- PDB source: `C:\msdev\work\age1_x1\aiuaimod.cpp`.
- The module has 114 normal owners in ascending PDB address order.
- The normal owner byte total is 27,557 bytes.
- The source owner is `src/aiuaimod.cpp`.
- The shared module header is `include/aiuaimod.h`.
- The module uses `/O2 /Oy /GX` from `config/flags/00412F00_UnitAIModule.rsp`.
- `UnitAIModule` has the proven 0x134-byte layout and complete 56-slot virtual
  surface. Its destructor is a real virtual destructor.

## Natural source changes

- Removed `__declspec(novtable)` from `UnitAIModule`.
- Removed all handwritten vptr stores. VC5 now emits the class vtable and the
  scalar and vector deleting surfaces. `00413070` stays compiler generated.
- Kept `00413070` out of normal source ownership and out of the TU owner map.
- Moved the UnitAIModule class to the canonical owner header.
- Replaced copied provider class views with the owner headers for action lists,
  AI playbooks, base game, map, master objects, players, static objects,
  visible maps, visible units, and the world.
- Replaced the copied managed array with canonical `ManagedArray<int>`.
- Replaced the load carrier overlay with typed `OrderEvent`, `NotifyEvent`, and
  a separate play-status flag.
- Replaced visible-unit pointer and count overlays with the typed
  `VisibleUnitList` and `VisibleUnitList_Size` globals owned by `vis_unit.cpp`.
- Replaced the map absolute-address macro with `view.h`'s typed table.
- Replaced all UnitAIModule absolute global reads with typed global storage in
  `game_globals.h` and `game_globals.cpp`.
- Removed source attempt logs and compiler-shaping macros.

## Status

The source module manifest keeps 114 normal owners in PDB order. Current source
status is:

- 102 `matching` owners in the source manifest after removing the two
  natural-shape regressions below.
- 3 `accepted_drift` owners: `00413150`, `00414D40`, and `0041A020`.
- 9 `scratch` owners: the seven prior scratch owners plus `00412F00` and
  `00413450`.

The current exact TU registration excludes all accepted-drift and scratch
owners. It contains 101 owners. `004195F0` remains a matching source owner but
is not registered in the grouped TU.

## Focused validation

The full source compiled with the pinned VC5 compiler and module response file.
Focused checks after canonicalization report `MATCH` and `0.0000%` for these
anchors:

- `00413090` `~UnitAIModule`
- `00413810` `owner`
- `004138E0` `orderQueueElement`
- `00414E80` `notify`
- `00415CA0` `closestObject`
- `00415E50` `closestResourceObject`
- `00415F40` `closestUndiscoveredTile`
- `004161D0` `waypoint`
- `004171F0` `runAwayFromAttackers`
- `00417730` `visibleStatus`
- `00417860` `lookAround`
- `00419510` `processGroupNotify`
- `00419650` `processMisc`
- `00419BC0` `processRetryableOrder`
- `00419C70` `addToOrderQueue`

Natural source regressions are deliberate and documented:

- `00412F00` changes because VC5 owns the real class vptr publication.
- `00413450` changes because the load source uses typed records instead of the
  former stack carrier overlay.

No new provider was invented for unresolved behavior. The seven prior scratch
owners remain scratch. Their full natural bodies remain in this source file.
