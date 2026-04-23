# VC5 EH/compiler-runtime helper audit

Date: 2026-04-22

## Goal

Expand the high-confidence toolchain-supplied catalog with the next conservative tier of
obvious VC5 exception-handling and compiler-runtime helpers, then review any newly surfaced
hidden-label hits.

## Exact-name promotions added to the safe catalog

The generator's exact-name allowlist was expanded to cover obvious VC5 EH/compiler-runtime helpers,
including these visible inventory names:

- `__CxxUnhandledExceptionFilter`
- `___CxxFrameHandler`
- `___InternalCxxFrameHandler`
- `___FrameUnwindToState`
- `_UnwindNestedFrames`
- `__global_unwind2`
- `__local_unwind2`
- `__seh_longjmp_unwind@4`
- `__ArrayUnwind`
- `_CallCatchBlock2`
- `_CallMemberFunction0`
- `_CallMemberFunction1`
- `_CallMemberFunction2`
- `__CallSettingFrame@12`
- `__NLG_Notify`
- `__NLG_Notify1`
- `_DestructExceptionObject`
- `_ValidateExecute`
- `_inconsistency`
- `__except1`
- `__heap_alloc`
- `` `eh_vector_constructor_iterator' ``
- `` `eh_vector_destructor_iterator' ``

Hidden-label-only safe exact names were also added so the review queue could surface them:

- `__except_handler3`
- `__except2`
- `___CxxLongjmpUnwind@4`

## Why these exact names were safe to add

These names are strongly characteristic VC5/CRT/compiler-runtime helper names rather than project-authored
code. In the reviewed packets they show the expected runtime behavior patterns:

- SEH/EH frame registration through `FS:[0]`
- unwind helpers built around `_RtlUnwind@16`
- catch/unwind dispatch into `__CallSettingFrame@12`, `__NLG_Notify`, and local unwind helpers
- exception-object cleanup through `_DestructExceptionObject`
- vector constructor/destructor iterator helpers with compiler-helper names
- CRT heap fallback helper `__heap_alloc`
- execute-probe wrapper `_ValidateExecute` over `IsBadCodePtr`

None of the reviewed entries showed project state, game-specific data, or authored gameplay logic.

## Newly surfaced hidden-label hits

After the exact-name expansion, the unhandled hidden-label review queue surfaced exactly three new hits:

- `0054B2DC_FUN_0054b2dc` -> `___CxxLongjmpUnwind@4`
- `00554DEA_FUN_00554dea` -> `__except_handler3`
- `005556FC_FUN_005556fc` -> `__except2`

All three were reviewed and promoted by exact VA region.

## Region promotions added after review

- `0054B2DC-0054B2FC`
  - hidden VC5 C++ EH helper `___CxxLongjmpUnwind@4`
  - tiny bridge into `___FrameUnwindToState`

- `00554DEA-00554EB4`
  - hidden VC5 SEH dispatcher `__except_handler3`
  - used by the surrounding compiler-generated EH-framed helpers

- `005556FC-005557ED`
  - hidden CRT math exception helper `__except2`
  - sibling to visible `__except1`, using the same `__handle_exc` / `__raise_exc` / `__umatherr` family

## Generator outcome after this pass

After the exact-name expansion plus the three region promotions:

- hidden-label safe candidates: `32`
- hidden-label unhandled candidates: `0`

## Bottom line

The conservative scripted lane is still working as intended:

- exact-name VC5 helper additions cleanly pull obvious compiler/runtime helpers out of the normal corpus,
- hidden-label-only helpers still require review,
- and region manifests remain the safe place to record those reviewed hidden-label promotions when the
  inventory function name is still generic.
