# Logic review: 0041E7D0 `RGE_Base_Game::setup_main_window`

## Phase transition

The main agent suspended ordinary exact matching after seven claims and 24 meaningful probes.

The candidate is `src/scratch/0041E7D0_setup_main_window.cpp`.

Current validation:

- original and rebuilt size: 330 bytes;
- all ten calls align in exact order;
- frame and control flow align;
- strict difference: 11 bytes;
- the difference is local rectangle load order before `SetWindowPos`.

A volatile local produced exact output. The source has no evidence for volatile storage.
The retained source uses ordinary Win32 types and direct rectangle arithmetic.

### Semantic questions at entry

1. Verify both `CreateWindowExA` paths and all arguments.
2. Verify failure behavior after window creation.
3. Verify rectangle calls, arithmetic, and `SetWindowPos` arguments.
4. Verify fullscreen call order and ignored Win32 return values.
5. Verify global and member stores, fault order, and success return.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-12

- `sa-4d55bad3` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-24e5c3aa` — `deepseek/deepseek-v4-flash`, high

Both reviewers found no behavioral difference. They verified both window-creation
paths, all ten calls, rectangle arithmetic, success and failure stores, fullscreen
updates, ignored API return values, and fault order.

Both noted the local height-expression order. The source and executable produce
the same 32-bit result. The difference does not add a call, memory access, or
observable side effect.

## Main-agent adjudication

The review found no open behavioral uncertainty. The retained source uses normal
Win32 types and direct arithmetic. Exact matching remains suspended because only
unsupported volatile storage reproduced the executable load schedule.

Promote to `src/verified_logic`.
