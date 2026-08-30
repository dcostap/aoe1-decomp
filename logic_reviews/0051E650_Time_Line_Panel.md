# Logic review: 0051E650 `Time_Line_Panel::Time_Line_Panel`

Current source: `src/tpnl_tml.cpp`. This ledger contains historical review evidence.

## Phase transition

The main agent suspended ordinary exact matching after three claims, 22 meaningful
probes, 32 checks, donor work, initializer variants, and canonical base-layout
reconstruction.

The candidate is `src/tpnl_tml.cpp`. It now models the
canonical 0xF4-byte `TPanel` and `TEasy_Panel` ownership through 0x478.

Current validation:

- original/rebuilt size: 276/276 bytes;
- instructions: 47/47;
- frame: none / none;
- calls: 1/1;
- strict difference: 125 bytes.

The exact blocker is constructor store scheduling. The same fields receive the
same final values, but VC5 emits a different order for early text-style, color,
and derived-vptr stores. Canonical layout did not alter that basin.

### Semantic questions at entry

1. Verify the base constructor call and derived-vptr lifetime.
2. Verify every field offset, width, value, and final object state.
3. Verify store order where alias, fault, or partial construction can expose it.
4. Verify signed constants, byte fields, null pointers, and floating values.
5. Verify EH, calling convention, cleanup, and constructor-failure behavior.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-2c36da0c` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-f9afde2c` — `deepseek/deepseek-v4-flash`, high

Both reviewers traced the complete constructor and found no definite behavior
difference. They confirmed the base call, canonical class sizes, all field
offsets, store widths and values, derived vptr, uninitialized field set, return,
and partial-construction behavior.

DeepSeek identified `text_style` first as a possible original initializer order.
A subsequent normal matching pass tested that order. It emitted identical code.
A body assignment worsened the result and was restored.

### Round 2 — fresh concurrent blind cohort, 2026-08-12

- `sa-0de96621` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-5beeeefd` — `deepseek/deepseek-v4-flash`, high

Both reviewers independently confirmed every derived store, width, value,
untouched field, base call, vptr lifetime, EH condition, and final object state.
No definite difference was found.

DeepSeek also verified the allocation size `0x52C` and the executable vtable.
`Time_Line_Panel` overrides only the destructor and slot-12 `draw`; this matches
the candidate's derived override set. No call or observer occurs between the
independent constant stores.

## Main-agent adjudication

- **Field state, widths, vptr, base lifetime, and EH:** confirmed by both reviewers.
- **Store scheduling:** independent constant stores with no interleaved call,
  read, callback, or possible observer. No semantic issue remains.
- **Color signedness:** 32-bit bit patterns match. The canonical shared surface
  can adopt unsigned names later without changing this constructor.
- **Minimal local base virtual surface:** no constructor behavior issue. The
  executable vtable and override set were checked directly in round two.

## Integrated changes

The main agent validated the canonical-layout candidate before phase entry and
after both review rounds.

## Final decision

Promote to `verified_logic` status. Two fresh blind cohorts converged with no open
behavior uncertainty. The remaining drift is independent store scheduling.
