# Recovery journal: 00534500 `set_player`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `matching`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.

## Translation-unit context

PDB module: `view.cpp`; source owner: `src/view.cpp`; owning class: `RGE_View`.
The original body is 37 bytes at `00534500-00534524`. It reads the parameter
at `[esp+4]`, stores it at `player` (`+0x100`), writes `-9999.0f` to
`last_view_x` (`+0x138`) and `last_view_y` (`+0x13C`), then calls virtual slot
`+0x20` with `TPanel::RedrawImmediate` and returns with `ret 4`.

## Current mismatch

The focused target is exact with the natural source below: 37/37 bytes,
9/9 instructions, one aligned virtual call, zero relocations, and the original
boundary. The translation-unit audit still reports unrelated grouped mismatches.

The fresh baseline used the prior `redraw(2)` call and differed by 18 bytes.
Its direct call did not match the original virtual slot. Replacing it with the
virtual `set_redraw(TPanel::RedrawImmediate)` call removes all target differences.

## Recovered attempt history


<!-- recovered:ca024d6ea63636280ddd -->
### `target-session` `build/target_sessions/00534500_set_player.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 layout; result=MISMATCH; diff=4; shape=100.0: Use natural -9999.0f for canonical shared float fields; grouped output previously converted the integer bit pattern.
```
<!-- end-recovered:ca024d6ea63636280ddd -->

## Rejected approaches

`redraw(2)` is rejected. It emits a direct call to `redraw` and misses the
original virtual `set_redraw` dispatch.

No raw offsets, aliases, wrappers, manual vtables, padding, or compiler
steering are used.

## Open questions

The source status remains `scratch`; promotion is outside this worker lease.

## Next useful approaches

Review the exact source for promotion. Do not alter shared declarations for
this target.

## Worker updates

### wave20-view

Changed only `RGE_View::set_player` in `src/view.cpp`:

```cpp
void RGE_View::set_player(RGE_Player* player) {
    this->player = player;
    last_view_x = -9999.0f;
    last_view_y = -9999.0f;
    set_redraw(TPanel::RedrawImmediate);
}
```

Focused validation: `target_session.py check --kind validation` and
`check_function.py --no-build` both report `Result: MATCH`, `0.0000%`,
37/37 bytes, 9/9 instructions, correct owner and boundary, one aligned
virtual call, and zero relocation differences. The worker audit reports 46
registered-owner matches, including this target, among 47 registered rows;
22 grouped mismatches and other unrelated rows remain.

The worker attempted the required session start before the coordinator reminder;
it timed out on `build/target_sessions/sessions.lock`. The preclaimed active
lease remained valid, so no retry was made. The exact source was pinned and the
session was released after validation.
