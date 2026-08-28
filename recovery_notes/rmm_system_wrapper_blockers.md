# RMM and system wrapper blocker inventory

Date: 2026-08-28.

This inventory covers the remaining Terra 4 RMM and system wrappers.
It does not move owners, change status, or approve a provider.

## Rank 1: Com_hand.cpp

- Wrapper: `src/com_hand_tu.cpp`.
- PDB owner: `TCommunications_Handler`.
- Normal range: `00425750` through `0042F270`.
- Blocking provider: an approved period DirectPlay 2/3 and Lobby SDK surface.
- Required PDB ABI: `DPCAPS` is `0x28` bytes with ten `DWORD` fields. The
  persistent DirectPlay value and `GetDPInterface` use `IDirectPlay3*`.
- Required SDK headers: `<dplay.h>` with DirectPlay 2/3 A types, and
  `<dplobby.h>` with Lobby A types.
- Pinned state: the configured VC5 `DPLAY.H` has DirectPlay 1 only and a
  `0x1C` `DPCAPS`. It has no `DPLOBBY.H`.
- Lobby dependency: the owned `RGE_Lobby` surface also needs the Lobby SDK
  declarations.
- Required project headers: `include/com_types.h`, `include/com_q.h`,
  `include/com_err.h`, `include/com_addr.h`, and `include/com_spd.h`.
- Existing owner header: `include/com_hand.h` must consume approved SDK types
  when they are available.

Do not use `include/com_hand_context.h`. It has copied COM ABI, copied records,
and duplicate global declarations.

Evidence: `recovery_notes/com_hand_owner_audit.md` and
`recovery_notes/directplay_header_probe.md`.

## Rank 2: Com_loby.cpp

- PDB owner: `RGE_Lobby`.
- Normal range: `0042F290` through `0042F830`.
- Blocking provider: the same approved DirectPlay 2/3 and Lobby SDK surface.
- Required SDK headers: `<dplay.h>` and `<dplobby.h>` with their A declarations.
- Required project headers: `include/com_err.h` and `include/debuglog.h`.
- Owner header: `include/com_loby.h` exists only on the held branch.

The natural source must stay branch-only. The pinned VC5 include path has no
`DPLOBBY.H`. Do not use `C:\msv6\VC98\Include`.

Evidence: `recovery_notes/com_loby_directplay_header_blocker.md` and
`recovery_notes/directplay_header_probe.md`.

## Rank 3: Com_obj.cpp

- Wrapper: `src/com_obj_tu.cpp`.
- PDB owner: `RGE_Combat_Object`.
- This is Terra 6 object work. It is not a Terra 4 task.
- Required owner headers: `include/com_obj.h`, `include/act_obj.h`,
  `include/m_co_obj.h`, `include/act_list.h`, `include/action.h`,
  `include/act_atak.h`, `include/act_entr.h`, `include/act_expl.h`,
  `include/act_gath.h`, `include/act_move.h`, and `include/act_tran.h`.
- Required object providers: `include/misl_obj.h`, `include/vis_unit.h`,
  `include/map.h`, `include/player.h`, and `include/world.h`.

Do not use `include/com_obj_context.h`, `include/com_obj_enter_context.h`, or
`src/com_obj_phase2_context.h`. They copy foreign ABI and use raw fields.

## RMM state

No RMM wrapper remains in this backlog. Each RMM PDB module has one direct
source owner and a source-module manifest:

- `rmm_base`, `rmm_clif`, `rmm_cntr`, `rmm_dbct`, and `rmm_elev`;
- `rmm_land`, `rmm_obj`, `rmm_shal`, `rmm_tdbc`, and `rmm_terr`.

Their scratch and accepted-drift rows need focused recovery. They are not
wrapper migrations.

## Other system state

`com_addr`, `com_err`, `com_q`, `com_serv`, `com_sess`, `com_spd`, and
`com_sync` already have direct source owners. They are not wrapper work.
