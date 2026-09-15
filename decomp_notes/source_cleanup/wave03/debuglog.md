# `src/debuglog.cpp` cleanup

## Delivery

- Module: `src/debuglog.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: pending until commit
- Changed files:
  - `src/debuglog.cpp`
  - `decomp_notes/source_cleanup/wave03/debuglog.md`
- Branch: `cleanup/staging-20260915-194`

The source owner is `src/debuglog.cpp`. The shared header remains unchanged.

## Evidence reviewed

- `config/functions/src/debuglog.cpp.json`
- `inventory/pdb/scoped_symbols.json`
- The selected original packets under `inventory/functions/0043/`:
  `00436220`, `004362A0`, `004362B0`, `004362F0`, `00436330`, `00436360`,
  `004363A0`, `00436430`, `00436470`, `004364B0`, `004365A0`, `004365C0`,
  `00436610`, and `00436810`.
- `orig/ghidra_decomp/debuglog.cpp.decomp`
- `orig/ghidra_decomp/debuglog.cpp.asm`
- The preserved pre-cleanup object at
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/debuglog.obj`

The registry has 14 normal functions. All 14 received original-name review.
The tail-jump destructor at `004362A0` remains a tail jump to `CloseLog`.

## Original-name review

The names below come from the procedure-scoped PDB records. Types, scopes,
storage, declaration order, calls, and expressions remain unchanged.

| VA | Function | Review and result |
| --- | --- | --- |
| `00436220` | `TDebuggingLog::TDebuggingLog` | No scoped parameters or locals. No rename. |
| `004362A0` | `TDebuggingLog::~TDebuggingLog` | No scoped parameters or locals. The packet proves the tail jump to `004365C0`; no source change. |
| `004362B0` | `LogFile` | PDB parameter `DoLog` replaces `value`. |
| `004362F0` | `LogOutput` | PDB parameter `DoLog` replaces `value`. |
| `00436330` | `LogTimestamp` | PDB parameter `DoTimestamp` replaces `value`. |
| `00436360` | `LogDateTimestamp` | PDB parameter `DoTimestamp` replaces `value`. |
| `004363A0` | `Time` | PDB locals `fTicksElapsed` and `ltime` map to the elapsed float and existing `ltime`. The elapsed float now uses `fTicksElapsed`. `ticks`, `timeinfo`, and `timestr` have no matching scoped names and remain unchanged. |
| `00436430` | `FlushToDisk` | PDB parameter `DoFlush` replaces `value`. |
| `00436470` | `LogSequence` | PDB parameter `DoSequence` replaces `value`. |
| `004364B0` | `OpenLog` | PDB local `nLoop` maps to the loop counter formerly named `i`. The Ghidra `local_4` label was not forced into a second source declaration. |
| `004365A0` | `FlushLog` | No scoped parameters or locals. No rename. |
| `004365C0` | `CloseLog` | No scoped parameters or locals. No rename. |
| `00436610` | `Log` | PDB parameter `fmt` replaces `format`. PDB locals `s1`, `s2`, `s3`, `s4`, and `ltime` already match the source. The PDB also records the stack `this`; the implicit member object was not changed. |
| `00436810` | `YesOrNo` | PDB parameter `TorF` replaces `value`. |

No new invented names were added. Existing names without a safe scoped PDB
mapping remain in place. In `Log`, these include `buffer`, `args`, `ticks`,
and `elapsed`. No declaration mapping was forced from reused or unnamed stack
slots.

The shared declaration in `include/debuglog.h` still uses its old parameter
spellings. The header owner may align those declaration-only names with the
recovered PDB names in a coordinated header change. This does not alter the
ABI or function symbols.

## Constants, resources, and comments

No constants or resource IDs changed. No resource lookup exists in this module.
The source keeps the original numeric line arguments `0x78` and `0xA3`, the
loop limit `25`, string literals, format strings, and literal types.

No comment was added. The source preserves the proven behavior in
`LogDateTimestamp`: it passes `Timestamp` to `YesOrNo` after setting
`DateTimestamp`. The original packet and executable listing support this
expression, so it was not repaired.

## Code-generation and ABI review

Only parameter and local identifier spellings changed:
`DoLog`, `DoTimestamp`, `fTicksElapsed`, `DoFlush`, `DoSequence`, `nLoop`,
`fmt`, and `TorF`. Types, declaration scope, storage duration, statement
order, expressions, calls, literals, public names, layout, calling
conventions, and symbol identity did not change. Generated output was not
checked in this phase.

## Shared requests and unresolved questions

- Request: the owner of `include/debuglog.h` can update declaration-only
  parameter spellings to match the recovered PDB names.
- No other shared declaration or resource mapping is needed.
- No unresolved behavior question blocks this source cleanup.

## Validation limits

Compilation, matching, audits, and tests were not run. No build, compiler,
game, or runtime check was run. Evidence inspection and Git diff review only.
