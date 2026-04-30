---
description: Instructions for a function matching job in this repo
argument-hint: "<target>"
---
You are matching a function in this repo.

Start from the function packet and original asm. Build or refine a natural source model, then iterate from diffs. Do not preserve decompiler shape unless the binary earns it.

## 1. First orient yourself

Find the current state of the target:

- If it already has a file in `src/scratch/`, continue from that file and preserve/extend its attempt log.
- If it is already in `src/matching/`, verify before touching it; do not create a duplicate owner.
- If it is unclaimed, create one scratch file: `src/scratch/<VA>_<slug>.cpp`.
- Check that the target is normal corpus, not an excluded/non-independent entry.

Then read the function packet in `inventory/functions/...` and use original asm as the behavioral oracle.

## 2. First pass / next pass goal

If starting fresh, get a full behavioral skeleton compiling before obsessing over one early hunk.

If continuing existing scratch, first understand the current notes and reproduce the current `check_function.py` result before making changes.

Prioritize:

- correct call set,
- correct stack cleanup,
- exact field/global widths where visible,
- plausible local stack layout,
- natural source shape.

## 3. Natural source is the default

When stuck, stop and read your source as source.

Ask:

- Would a human have written this?
- Or am I preserving Ghidra/decompiler scaffolding?
- Is this temp/result/local pointer actually needed?
- Does original asm preserve this value, or just test/use it immediately?

Prefer direct, natural forms unless a probe proves otherwise.

Especially watch for decompiler-created predicate locals:

```cpp
tmp = call(...);
if (tmp || (tmp = call(...)) || ...)
```

If the return is only truth-tested, try:

```cpp
if (call(...) || call(...) || ...)
```

Do not apply this blindly when the returned value is consumed later.

## 4. Diagnose pressure cliffs correctly

If rebuilt has:

- exact/near-exact size,
- wrong prologue,
- wrong `this` register,
- hidden `this` stack home,
- frame size off by 4/8,

think **whole-function liveness/register pressure**, not just local syntax.

If deleting/reordering a late block fixes the prologue, treat it as a pressure-threshold clue. Then look for artificial long-lived temps, saved object pointers, predicate result locals, wrong helper surfaces, or wrong global/field widths.

## 5. Use original asm to decide what should be live

Before adding a local, ask whether asm actually carries that value.

- If original repeatedly reloads `this->foo`, don’t save `foo` early.
- If original immediately tests a call result, don’t preserve a result local.
- If original carries a pointer across several operations, then a shared local may be right.

## 6. Fix binary-proven surfaces before variant churn

Before launching labs, verify:

- field offsets/sizes,
- global widths (`byte` vs `int` matters),
- call declarations and calling conventions,
- IAT calls modeled as function pointers when original uses `call dword [addr]`,
- return widths if original tests `al`/`dl` vs `eax`.

Wrong surface facts can masquerade as source-shape problems.

## 7. Variant labs: focused only

Use `variant_lab.py` after behavior/calls/stack are understood.

Good labs test one hypothesis:

- predicate direct vs assignment local,
- local pointer vs direct member reload,
- loop iterator topology,
- guard nesting/order,
- helper/import surface,
- one pressure-sensitive region.

Avoid whole-function random sweeps. If a lab finds a clue, reduce it manually and validate normally.

## 8. Attempt notes should capture deductions

Keep or add compact notes near the top of the scratch file, for example:

```cpp
// direct predicate OR removed hidden this home; kept
// late block deletion fixes prologue => pressure clue, not source-order proof
// byte global width fixed final late mismatch
// local prog_info pointer worsened register allocation; rolled back
```

The goal is not just “tried variants”; it’s to leave a reasoning trail.

## 9. Finish correctly

When exact, move the file from `src/scratch/` to `src/matching/` and re-run validation after the move. The VA should have exactly one compiler-facing owner.

Your one and only job now is to match: $ARGUMENTS
