# Logic review: 0041F560 `RGE_Base_Game::setup_fonts`

## Phase transition

The main agent suspended ordinary exact matching after five claims and 20 meaningful probes.

The candidate is `src/scratch/0041F560_setup_fonts.cpp`.

Current validation:

- rebuilt and original size: 410 bytes;
- calls, instruction count, and control flow align;
- strict difference: 50 bytes;
- rebuilt frame is `0x3C`; original frame is `0x40`.

Focused local-order, lifetime, parameter-home, and typed interior-pointer probes
all emitted duplicate code. The retained source preserves the executable's
interior `GetTextMetricsA` output pointer.

### Semantic questions at entry

1. Verify allocation, storage, and failure behavior, including the DC failure leak.
2. Verify each font ID, italic flag, and null-font path.
3. Verify the interior `TEXTMETRICA` pointer and shifted output interpretation.
4. Verify font array index selection and every width and height store.
5. Verify object selection, restoration, DC release, fault order, and returns.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-861ea07a` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-ca972dfc` — `deepseek/deepseek-v4-flash`, high

Both reviewers reported one stored-state difference after passing
`&tm.tmAscent` to `GetTextMetricsA`. They interpreted the later ESP-relative
reads without the two arguments already pushed for the restoring
`SelectObject` call.

Allocation, font selection, calls, failure leaks, object restoration, release,
and return paths otherwise matched.

### Round 2 — corrected-source check and conflict, 2026-08-12

- `sa-9e9332f2` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-079bf055` — `deepseek/deepseek-v4-flash`, high

Luna accepted the temporary field correction. DeepSeek found the missing stack
adjustment and rejected it. At `0041F697` and `0041F698`, the executable pushes
two arguments before it reads the metrics. Thus, the effective reads are
`tmMaxCharWidth`, `tmAscent`, and `tmAveCharWidth`.

## Main-agent adjudication

The round-one metric finding is invalid. Direct instruction-level stack
accounting confirms the original source expressions. The main agent restored
them. A fresh blind cohort must review the restored candidate.

### Round 3 — final restored-source cohort, 2026-08-12

- `sa-a6f616ff` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-03ef04f8` — `deepseek/deepseek-v4-flash`, high

Both reviewers tracked ESP across the two pending `SelectObject` arguments.
They confirmed `tmMaxCharWidth` and `tmAscent + tmAveCharWidth`. They found no
behavioral difference in allocation, font selection, metric storage, failure
paths, object restoration, release, or returns.

## Final decision

No behavioral uncertainty remains. The retained source preserves the unusual
interior metrics pointer and all resulting shifted values. Remaining drift is
the four-byte frame and register allocation.

Promote to `src/verified_logic`.
