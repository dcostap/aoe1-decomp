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

No review has started.
