# Logic review: 0052A510 `TRIBE_Game::disconnect_multiplayer_game`

Current source: `src/tribegam.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching after seven claims, 28
meaningful probes, 46 checks, a 36-case focused variant lab, exact donor work,
and repeated convergence on one register-color basin. The candidate remains
`src/tribegam.cpp`.

Current validated checker state:

- original/rebuilt size: 279/279 bytes;
- frame: none / none;
- saved registers: `EBX`, `EBP`, `ESI`, `EDI` in both;
- calls: 14/14 in exact order with matching targets;
- instructions: 82/82;
- conditional branches: 11/11;
- returns: 2/2;
- instruction shape and exact-block coverage: 100%;
- strict difference: 16 register-encoding bytes;
- edit/resync cost: 16 bytes.

The executable keeps `this` in `EDI` and elapsed time in `ESI`. VC5 keeps
`this` in `ESI` and elapsed time in `EDI`. Matching work tested declaration
order, direct members, base and derived class surfaces, field widths, control
flow, timestamp expressions, translation-unit context, and focused variants.
No natural source changed this register assignment.

The retained source uses named communications, game-mode, and world fields,
typed calls, unsigned timestamp arithmetic, and natural wait loops. It contains
no fake volatility, manual vtable calls, raw offsets, or codegen-only aliases.

### Semantic questions at entry

1. Verify multiplayer and game-mode gates, including all no-op paths.
2. Verify every communications call, argument, order, and repetition.
3. Verify the waiting-message predicates and signed result handling.
4. Verify world null/status exits and the byte status width.
5. Verify unsigned timer subtraction, wraparound, 500-ms polling, and 15-second limit.
6. Verify shared `GameOver` and `UnlinkToLevel` tails for every exit.
7. Verify field offsets, malformed-pointer fault order, and partial effects.
8. Verify calling conventions, caller-saved register relevance, returns, and cleanup.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-3a6c67fc` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-554537ed` — `deepseek/deepseek-v4-flash`, high

#### Luna report

The reviewer found no definite difference.

Verified behavior:

- `multiplayerGame()` runs first. Zero calls only `GameOver`. Nonzero modes
  4, 6, 7, and 5 enter the disconnect path. Other modes return without
  communications calls.
- Allowed modes call `SendIResignMsg`, `ShutdownGameMessages`, then
  `CountWaitingMessages`.
- The initial count test is signed `<=0`. Only positive counts enter the wait.
- Wait setup disables input and calls
  `show_status_message(0x4C0,0,-1)`.
- Each inner iteration tests `world==0` or byte `game_status==1` before shutdown.
- The 500-ms test uses unsigned subtraction and strict `<`.
- After each interval, count zero exits. Negative counts continue because the
  executable tests only zero at this site.
- The 15,000-ms test uses unsigned subtraction and strict `<`.
- Timer line arguments `0x15F8`, `0x1601`, and `0x1605` match.
- Cleanup calls `GameOver`, then `UnlinkToLevel(5)`.
- The source reloads `comm_handler` for each call, matching the executable.
- Fault and side-effect order matches, including world-null before status read.

Plausible concerns were limited to Win32 `unsigned long` width, old-style string
literal conversion, and invalid-pointer C++ rules. The target VC5 ABI resolves
those concerns. Conclusion: semantic equivalence across gates, loops, timer
wraparound, calls, arguments, widths, and cleanup.

#### DeepSeek report

The reviewer verified the raw executable bytes, all direct call targets and
branch displacements, the source string, callee signatures, and field offsets.

Verified control flow:

- Non-multiplayer calls only `GameOver`.
- Multiplayer with a disallowed mode returns without `GameOver`.
- Allowed modes execute the three initial communications calls in order.
- Positive waiting counts enter the nested do-loop; zero or negative counts
  skip it.
- World null or status byte 1 exits to shared cleanup.
- The inner 500-ms subtraction and outer 15,000-ms subtraction are unsigned and
  preserve wraparound.
- Only count zero breaks after the 500-ms interval.
- Every wait exit reaches `GameOver` then `UnlinkToLevel(5)`.

Verified ABI and effects:

- `show_status_message` arguments and cleanup match.
- `disable_input`, all communications calls, and all timer arguments match.
- `comm_handler +0x18C`, `prog_mode +0x1B0`, `world +0x3F4`, and status byte
  `+0x1D` match ground-truth layout.
- The function writes no memory directly and ignores the unlink return value.
- Null and malformed pointer access order matches.

Findings: no definite difference. `game_status` versus ground-truth
`game_state` is a naming-only concern. Original textual spelling is
unestablished. Conclusion: behavior matches, including timer wraparound and all
mode paths.

## Main-agent adjudication

- **Mode gates and no-op paths:** confirmed. Both reviewers independently noted
  the important distinction between non-multiplayer and disallowed multiplayer
  modes.
- **Calls, arguments, and order:** confirmed for all 14 call sites.
- **Wait loops and timer wraparound:** confirmed. The source uses 32-bit
  `unsigned long` under VC5 and matches the executable's `sub` plus unsigned
  `jb` tests.
- **Count signedness:** confirmed. Initial `>0` and later `==0` tests preserve
  the executable's negative-count behavior.
- **Fault and cleanup order:** confirmed, including world checks and shared
  `GameOver`/`UnlinkToLevel` order.
- **Field name:** `game_status` is noncanonical naming but does not affect source
  behavior or auditability. No source change is required for this review.

Round 1 found no substantive open behavior issue. The 16 byte differences are
only the documented ESI/EDI allocation. A second fresh cohort is required before
final promotion.

## Integrated changes

The main agent validated the unchanged normalized source at 279 bytes and 16
strict differing bytes before and after round 1. No source change was made.

### Round 2 — fresh concurrent blind cohort, 2026-08-12

- `sa-7ff19690` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-9bdbfa66` — `deepseek/deepseek-v4-flash`, high

Both reviewers found no definite difference. They verified the multiplayer and
mode gates, all 14 calls, signed message-count tests, world fault order,
unsigned timer wraparound, and the three distinct exit behaviors.

The DeepSeek reviewer also verified raw call targets, timer constants, field
offsets, and shared cleanup. The candidate reloads mutable fields at each use.
No semantic concern remains. The main agent revalidated the unchanged source at
279 bytes with 82/82 instruction-shape parity. The 16 bytes only exchange ESI
and EDI allocation.

## Final decision

Promote to `verified_logic` status. Two fresh cohorts found no behavioral
uncertainty. The remaining 16 bytes are equivalent register allocation.
