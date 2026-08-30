# Logic review: 0047F320 `RESFILE_load`

Current source: `src/Res_file.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching after four claims and 25 meaningful probes.

The candidate is `src/Res_file.cpp`.

Current validation:

- original and rebuilt size: 346 bytes;
- all eight calls align in exact order;
- frame and control flow align;
- strict difference: one byte at `0047F3CA`;
- original and rebuilt code differ only in commutative LEA base/index encoding.

Pointer, integer, union, cast, operand-order, and compound forms reproduced the same result.
The retained source uses the natural mapped pointer plus byte offset expression.

### Semantic questions at entry

1. Verify output initialization and resource-location output ownership.
2. Verify missing-resource diagnostics and return paths.
3. Verify mapped-data address addition, including 32-bit wrap and malformed offsets.
4. Verify allocation, seek, read, error paths, and intentional allocation retention after read failure.
5. Verify call arguments, return values, fault order, and all memory effects.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-b646640c` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-6a3dff3b` — `deepseek/deepseek-v4-flash`, high

Both reviewers verified the ABI, output stores, mapped and allocated paths,
failure leaks, file calls, malformed-size behavior, and fault order.

DeepSeek found one definite data-reference defect. The error format string lacked
the executable's `, not found` suffix. The function-body check could not detect
this because both strings use the same relocation site.

## Main-agent adjudication

The format-string finding is valid. The main agent restored the exact executable
text. One more fresh blind cohort must confirm the corrected candidate before
promotion.

### Round 2 — fresh corrected-source cohort, 2026-08-12

- `sa-561463a6` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-6df60284` — `deepseek/deepseek-v4-flash`, high

Both reviewers found no behavioral difference after the string correction.
They verified the complete locate, mapped, allocation, seek, read, diagnostic,
and failure paths. They also verified all output stores, exact strings, call
arguments, leaks, malformed-value behavior, and fault order.

## Final decision

No behavioral uncertainty remains. The one-byte difference selects the opposite
SIB base and index for the same pointer addition.

Promote to `verified_logic` status.
