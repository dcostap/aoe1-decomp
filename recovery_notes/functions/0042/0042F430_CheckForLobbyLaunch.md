# Recovery journal: 0042F430 `CheckForLobbyLaunch`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_loby.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_loby.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:934088465d5dc0b4182a -->
### `target-session` `build/target_sessions/0042F430_CheckForLobbyLaunch.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Baseline current TU: positional bytes match, but rebuilt decorated parameter uses class IDirectPlay3 (PAV) instead of original struct IDirectPlay3 (PAU).
probe 2 abi; result=MATCH; diff=0; shape=100.0: Changed the shared DirectPlay3 declaration from class to struct. MSVC decorated the reference parameter as PAU, matching the original ABI while preserving the exact body. [same emitted code as probe 1]
```
<!-- end-recovered:934088465d5dc0b4182a -->

<!-- recovered:0fcb061ef2e4fbff2d10 -->
### `a5fb96a1e6de` `src/scratch/0042F430_CheckForLobbyLaunch.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0042F430 CheckForLobbyLaunch
// 514 bytes, __thiscall, RGE_Lobby method
// probe 5: 480/514 bytes (34 short)
// tried: natural virtual calls (448B), raw vtable pointer casts (480B), function pointer casts (464B)
// tried: correct member layout (glpDPL+4, glpDPL2+8, glpDP+C, glpdplConnection+10, lobby_game+14, Err+18)
// tried: DPLCONNECTION allocation with operator new(41), session desc field setup
// BLOCKER: 34 bytes short despite correct core logic. Original has extra stack setup
//   (mov [esp+10h],29h), extra push instructions before DirectPlayLobbyCreateA call,
//   and different COM vtable dispatch pattern (call dword [edx+20h] vs natural vcall).
//   Core logic correct: ClearLobbyInfo, DirectPlayLobbyCreateA, QI for IDirectPlayLobby2A,
//   Connect, Log calls, DPLCONNECTION alloc, SendMessage, second Connect, QI for IDirectPlay3A,
//   EnumPlayersCallbackLobby call.
```
<!-- end-recovered:0fcb061ef2e4fbff2d10 -->

<!-- recovered:efedcc7b43e84bc64f0e -->
### `a5fb96a1e6de` `src/scratch/0042F430_CheckForLobbyLaunch.cpp:53-71`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Connect via vtable slot at +0x20 (slot 5)
// [non-comment lines omitted during migration]
    *(unsigned int*)((unsigned char*)sessionDesc + 4) = 0x44;
    *(unsigned int*)((unsigned char*)sessionDesc + 0x28) = 9;

    // SendMessage via slot 5 (same as Connect, original uses slot 5)
```
<!-- end-recovered:efedcc7b43e84bc64f0e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
