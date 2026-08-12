# Logic review: 004A61A0 `TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect`

## Phase transition

The main agent suspended ordinary exact matching after nine claims, 54 meaningful
probes, same-TU donor work, EH and flag experiments, and final source
normalization.

The candidate is `src/scratch/004A61A0_TRIBE_Screen_Disconnect.cpp`.

Current validation:

- original/rebuilt size: 200/219 bytes;
- calls: 4/4 in exact order;
- saved registers: `ESI`, `EDI` in both;
- strict difference: 91 bytes;
- first mismatch: setup-failure tail at `004A6211`.

The exact blocker is compiler EH-tail sharing. The executable routes setup
failure to one shared epilogue. VC5 emits a separate cleanup and return tail for
the natural constructor. Exact same-TU context did not change this basin.

The retained source uses named fields, ordinary construction and setup control
flow, typed calls, the proven layout, and `/GX`. It contains no unsupported
compiler steering.

### Semantic questions at entry

1. Verify base construction, derived vptr lifetime, and every field store.
2. Verify setup arguments, return test, and failure assignment at `field_D8`.
3. Verify ideal-size and text-control calls, arguments, and conditional paths.
4. Verify constructor return value, EH registration, cleanup, and partial construction.
5. Verify field offsets, widths, malformed pointers, fault order, and side effects.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-97a14b14` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-a45a6ec8` — `deepseek/deepseek-v4-flash`, high

Both reviewers confirmed the complete constructor path: base construction,
field stores, setup call and arguments, failure flag, success calls, return,
EH registration, cleanup ownership, partial construction, and malformed-pointer
fault order.

DeepSeek found no definite difference. Luna found four class-surface ABI risks:
the parameterless `TPanel::setup`, `set_positioning` declaration identity, a
spurious `TScreenPanel::create_button` override, and wrong trailing types on a
`create_text` virtual declaration. These can alter vtable contents outside the
constructor and require correction before review can continue.

### Round 2 — fresh blind cohort after ABI correction, 2026-08-12

- `sa-83101145` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-8ed0563d` — `deepseek/deepseek-v4-flash`, high

Both reviewers confirmed the constructor calls, arguments, stores, return,
fault order, partial construction, and EH cleanup.

DeepSeek recommended pass. Luna inspected the emitted vtable and found five
definite wrong entries. The candidate inherits `TPanel` implementations where
the executable uses `TEasy_Panel` or `TScreenPanel` overrides:

- `+0x28`: `draw_setup`
- `+0x30`: `draw`
- `+0x54`: `handle_paint`
- `+0x70`: `handle_mouse_down`
- `+0xC0`: `set_focus`

These methods affect object behavior after construction. The vtable defect is
therefore a semantic blocker.

## Main-agent adjudication

Constructor behavior is confirmed. Round 1 ABI corrections were valid, but
round 2 found five additional missing overrides. Return this target to normal
source correction. Verify the complete emitted vtable before another cohort.

## Integrated changes

The main agent validated the normalized 219-byte candidate with all four calls in
order before phase entry.

After round 2, a matching worker added the five executable-proven inherited
overrides. The worker also corrected overloaded virtual declaration order.
It compared all 74 emitted vtable slots with executable vtable `00573518`.
Every slot matched by owner and method name. A later review found four
remaining decorated-symbol differences.

The main agent revalidated the constructor. Its 219-byte output and four calls
remain unchanged. The known 19-byte EH-tail blocker also remains unchanged.

### Round 3 — fresh blind cohort after override correction, 2026-08-12

- `sa-947bbb6b` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-30a90570-r2` — `deepseek/deepseek-v4-flash`, high, pending

Luna confirmed constructor behavior, cleanup, and the 74-slot table order.
It found four definite ABI declaration defects:

- `set_positioning` used a global enum instead of `TPanel::PositionMode`;
- `get_true_render_rect` used a pointer instead of a reference;
- `get_help_info` used pointers instead of references;
- slots 57 through 73 used public symbols instead of protected
  `TEasy_Panel` symbols.

The main agent corrected these declarations. The constructor remains 219 bytes
with four ordered calls and the same EH-tail drift.

DeepSeek independently confirmed the constructor, EH state, partial-construction
cleanup, and all 74 slot positions. It found two additional declaration groups:

- slots 8 and 9 required nested `TPanel::RedrawMode`;
- slots 65 through 72 required their typed panel double-pointer outputs.

The main agent corrected both groups from exact executable and donor ABI
evidence. These declaration-only corrections do not change the constructor
output. Final validation remains 219/200 bytes, four ordered calls, and the
known 19-byte duplicated EH return tail.

## Final decision

Promote to `src/verified_logic`. Both reviewers verified constructor behavior,
EH cleanup, and vtable order. The main agent adjudicated every ABI finding and
corrected the complete 74-slot callable surface. No behavioral uncertainty
remains. Exact matching stays suspended only for the VC5 EH-tail sharing basin.
