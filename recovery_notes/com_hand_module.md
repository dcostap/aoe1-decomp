# Com_hand.cpp source reunification

- PDB source: `C:\\msdev\\work\\age1_x1\\Com_hand.cpp`
- Module source: `src/Com_hand.cpp`
- Normal owners: 146
- Source order: 146 of 146 owners retained in PDB order.
- Current source states: 90 matching, 0 accepted drift, 1 verified logic, 55 scratch.
- Registered exact owners: 90.

The module now owns one compiler-facing source file. The old TU wrapper, 146
source-bank fragments, and four helper context headers were removed. The module
header is `include/com_hand.h`.

The source preserves the prepared function bodies and their reviewed source
comments. The grouped compiler check reports 84 registered owner matches.
Other bodies remain in their recorded source state. Structural reunification
changes their grouped code placement, relocation, boundary, or symbol result;
it does not change their status.

Shard-local repair block:

- PDB methods now use `TCommunications_Handler` ownership.
- DirectPlay call sites use the approved 1997 `dplay.h` surface. The
  DirectPlayCreate call uses old `IDirectPlay`, then queries `IDirectPlay3`.
- Queue cleanup uses `FlushAll`, notifications call `NotifyWindowParam`, and
  force-player paths use the target DirectPlay methods and callback.
- The module uses typed communication globals. It has no absolute global
  address macros or local DirectPlay interface declarations.
- The SDK callback cast is limited to `EnumPlayers`. The game callback keeps
  its PDB `DPNAME*` signature.

Validation on 2026-08-27:

- `plan_translation_unit.py --module Com_hand.cpp`: 146 normal owners.
- Candidate validation: 146 normal bodies and two generated entries compiled.
- Candidate result: 90 exact owner matches and 19 exact observed matches.
- `check_function.py --va 00425750 --rebuild`: `Result: MATCH`, `0.0000%`.
- `git diff --check`: pass.
