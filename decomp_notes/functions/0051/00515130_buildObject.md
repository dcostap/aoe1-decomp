# Function notes: 00515130 `buildObject`

## Translation-unit context

The PDB module is `tplayer.cpp`, and the natural owner is `src/tplayer.cpp`.
The function is `TRIBE_Player::buildObject`, a `__thiscall` virtual override at
vtable slot 63. The original body spans `00515130-0051517C` and saves `esi` and
`edi`. It calls `calloc(1, 4)`, `TRIBE_Command::command_build`, and `free`, in
that order. The command receives the player's 16-bit `id`, a heap `int` whose
value is `first`, `1`, and the remaining four arguments. The command object is
`this->world->commands`.

## Current mismatch

No mismatch remains. The current natural source has no local frame, emits 77
bytes and 31 instructions, and saves `esi` and `edi`. The standalone checker
reports `MATCH`, `0.0000%`, closed boundaries, three aligned direct calls, and
three of three safely masked relocations. The rebuilt owner symbol matches
`?buildObject@TRIBE_Player@@UAEXHHMMH@Z`.

## Recovered attempt history

The initial natural source stored `first` in a stack `int` and passed its
address to `command_build`. A fresh target-session baseline emitted 54 bytes,
missed `calloc` and `free`, and differed by 70 bytes (90.9091%). Replacing the
stack value with `static_cast<int*>(calloc(1, 4))`, assigning `first`, and
calling `free` after `command_build` restores the binary call surface and exact
code generation.

Direct validation:

```text
python tools/target_session.py check --va 00515130 --owner wave21-tplayer --kind validation --note "revalidate natural calloc/free reconstruction and direct call surface" --checkpoint wave21-final -- --detail full
Result: MATCH
Strict positional diff: 0 bytes (0.0000%), 0 span(s)
```

The no-build call map confirms exact call order and offsets: `calloc` at
`+0008`, `command_build` at `+003A`, and cleanup `free` at `+0040`. The
focused result has the correct owner symbol, closed boundaries, and three of
three safely masked relocations.

The worker audit at
`build/audits/workers/wave21-tplayer/tplayer/report.txt` includes this target
as exact with zero grouped diff, correct ownership, closed boundaries, and no
relocation problems. Its 67 registered-owner rows also remain exact.

## Rejected approaches

The stack-local `int objectId` form is rejected because it removes the proven
`calloc` allocation and `free` cleanup, changes the call surface, and emits 54
bytes instead of 77.

## Open questions

No behavior or code-generation questions remain for this function. The final
target-session validation check and the grouped tplayer audit both completed.

## Next useful approaches

Review this exact natural reconstruction for promotion from `scratch` to
`matching`. Do not replace the heap allocation with a stack local.

## Worker updates

### wave21-tplayer

- Recovered the original heap `int` lifetime around `command_build`.
- Changed only `src/tplayer.cpp` function `TRIBE_Player::buildObject`.
- Final standalone result: `MATCH`, `0.0000%`, 77/77 bytes, 31/31
  instructions, 3/3 calls, and safe relocations 3/3.
- Translation-unit audit: target exact; 67 registered-owner rows exact.
- Final target-session validation check is recorded as `wave21-final`.
