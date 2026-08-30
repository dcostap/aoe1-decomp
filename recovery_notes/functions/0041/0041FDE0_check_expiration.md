# Recovery journal: 0041FDE0 `check_expiration`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/basegame.cpp`.
- PDB source: `C:\msdev\work\age1_x1\basegame.cpp`.
- Earlier recovery note: `recovery_notes/basegame_module.md`.

## Translation-unit context

- PDB module: `basegame.cpp`; natural owner: `src/basegame.cpp`.
- Owning class and symbol: `RGE_Base_Game::check_expiration`, `__thiscall`.
- Original body: `0041FDE0-0041FE45`, 102 bytes, 33 instructions.
- The body has two direct calls, `mktime` and `time`, in that order.
- The original loads `expire_month`, `expire_day`, and `expire_year` from
  `RGE_Prog_Info` offsets `+0x880`, `+0x882`, and `+0x884`.

## Current mismatch

- No current mismatch. The natural source uses a local `struct tm`, zeroes it
  with `memset`, stores the expiration month, day, and year in `tm_mon`,
  `tm_mday`, and `tm_year`, then compares the current time with `mktime`.
- Fresh direct check (`check_function.py --rebuild`): 102/102 bytes, frame
  `0x28`, 33/33 instructions, two aligned calls, safe relocations 2/2,
  correct owner and boundary, and `0` differing bytes (`0.0000%`).

## Recovered attempt history


<!-- recovered:ea3479ddd2ffcf097977 -->
### `e636174a8eb4` `src/matching/0041FDE0_check_expiration.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: zeroed tm-like local, build the expiration date, then compare current time against it
// exact match landed once the tm-like layout started at tm_min and memset zeroed the 9-dword local block before the date fields were filled
```
<!-- end-recovered:ea3479ddd2ffcf097977 -->

## Rejected approaches

- The prior natural field mapping (`tm_year = expire_year - 1`, `tm_mon =
  expire_month`, `tm_wday = expire_day`) produced the right size but six
  differing bytes. It used the wrong `RGE_Prog_Info` field order and shifted
  `tm` homes.
- A historical standalone `tm_like` source matched, but it used a fake local
  type and custom CRT declarations. The current exact source needs neither.

## Open questions

- The first target-session check timed out on the sessions lock. Direct checker
  validation is current, and the lease is now paused.

## Next useful approaches

- Coordinator should review this exact candidate for promotion.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### wave21-basegame

- Changed only `check_expiration` in `src/basegame.cpp`.
- Direct `check_function.py --rebuild` returned `MATCH` and `0.0000%`, with
  the correct owner, boundary, relocations, and direct calls.
- Grouped `basegame_cpp` audit completed under
  `build/audits/workers/wave21-basegame/basegame_cpp`; all 186 registered
  owners matched, including this target. The other 16 rows are existing
  module debt.
