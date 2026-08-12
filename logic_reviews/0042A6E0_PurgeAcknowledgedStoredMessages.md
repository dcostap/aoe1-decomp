# Logic review: 0042A6E0 `TCommunications_Handler::PurgeAcknowledgedStoredMessages`

## Phase transition

The main agent suspended ordinary exact matching after five claims, 39 meaningful
probes, 47 checks, donor work, focused pointer/index variants, and final source
normalization.

The candidate is `src/scratch/0042A6E0_PurgeAcknowledgedStoredMessages.cpp`.
It uses the proven 0x38-byte `RESENDER` layout and named fields `TimeSent`,
`Serial`, `ResendMsg`, `Length`, and `DestMap`.

Current validation:

- original/rebuilt size: 283/255 bytes;
- frame: `0xC` / `0xC`;
- calls: 3/3 in exact order;
- branches: 10/10;
- strict difference: 266 bytes;
- instruction shape: 80.90%.

The exact blocker is VC5 induction and stack-home topology. Diagnostic flat-cursor
source reached a small diff but was compiler steering. The retained source uses
ordinary typed indexing.

### Semantic questions at entry

1. Verify slot bounds, player bounds, and all loop termination behavior.
2. Verify human-player filtering and `DestMap` tests.
3. Verify release conditions, logging arguments, delete order, and field clears.
4. Verify the final waiting-count scan, limits, and returned value.
5. Verify widths, layout, calling conventions, malformed pointers, and partial effects.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-b8897ac1` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-ece02b72` — `deepseek/deepseek-v4-flash`, high

Both reviewers independently traced the complete function and found no definite
behavior difference. They confirmed the 0x38-byte record layout, 502-record
loops, one-based player bounds, human-player gate, unsigned `DestMap` test,
logging arguments, delete and clear order, final accumulating count, ABI, and
return value.

Both noted that the executable reloads `this->Resend` after calls while the
source carries one typed record pointer. Neither found evidence that
`IsPlayerHuman` or `Log` can replace the resend array. This remains the only
round-one concern.

### Round 2 — fresh concurrent blind cohort, 2026-08-12

- `sa-5b54e3d5` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-4f35352e` — `deepseek/deepseek-v4-flash`, high

Both reviewers again confirmed all loops, bounds, record geometry, calls,
arguments, purge order, faults, final count, cleanup, and return.

Luna retained the cached-record pointer as an adversarial re-entry concern.
DeepSeek inspected every intervening callee. `IsPlayerHuman` is read-only.
`Log` receives no handler pointer and only changes logging state. `operator
delete` only frees its argument. None can replace `this->Resend`. Thus, every
executable reload returns the pointer carried by the source.

## Main-agent adjudication

- **Layout, loops, calls, widths, and effects:** confirmed by both reviewers.
- **Cached record pointer:** no established behavior difference. The two callees
  cannot mutate the resend-array owner. Round two cleared this concern.
- **WaitingForAck signedness:** the executable performs one 32-bit increment per
  live record, at most 502 times in this function. The pinned VC5 object emits
  the same dword operation. No open behavior issue remains.

## Integrated changes

The main agent validated the unchanged normalized candidate before phase entry
and after both review rounds.

## Final decision

Promote to `src/verified_logic`. Two fresh blind cohorts converged with no open
behavior uncertainty after direct callee inspection.
