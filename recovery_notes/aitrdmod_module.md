# aitrdmod.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aitrdmod.cpp`.
- The module has five normal owners.
- The normal owner byte total is 131 bytes.
- The PDB source-line bands are 23-24, 31-32, 37, 43-45, and 50-52.
- The owner address order is `00412E40`, `00412EA0`, `00412ED0`,
  `00412EE0`, and `00412EF0`.
- The owning class is `TradeAIModule`, derived from `AIModule`.
- The class inventory proves a `0xF4` `TradeAIModule` size and `md` at `+0xF0`.
- The natural module header reuses canonical `include/aimodule.h`.

## Source result

The module has one compiler-facing source file: `src/aitrdmod.cpp`.
It contains all five normal owners in PDB order.
The old wrapper, fragment includes, context macro, fallback declarations, and
per-function source files were removed.

Before migration, all five owners used the `src/matching` bank:

- `00412E40` `TradeAIModule(void*, int)`
- `00412EA0` `TradeAIModule(int, int)`
- `00412ED0` `TradeAIModule::~TradeAIModule()`
- `00412EE0` `TradeAIModule::setMainDecisionAI(MainDecisionAIModule*)`
- `00412EF0` `TradeAIModule::save(int)`

After migration, all five owners use direct ownership in `src/aitrdmod.cpp`.
Their matching status remains unchanged.

## Exact anchors

- Both constructors call the `AIModule` constructor, clear `md`, and restore
  the derived vptr.
- The destructor restores the derived vptr and jumps to the base destructor.
- `setMainDecisionAI` stores its pointer at `+0xF0`.
- `save` returns the shipped constant `1`.
- The constructor symbols are explicitly mapped because both display the same
  PDB name.

## Generated entries

The nearby compiler-generated scalar deleting destructor remains
`00412E80`. It has no normal source definition. Candidate validation emitted and
matched its authentic VC5 weak `??_E` and `??_G` pair.

## Validation

- Flags: `config/flags/default.rsp`.
- Command: `python tools/validate_candidate_tu.py --proposal
  build/candidate_tus/aitrdmod.json`.
- Result: six of six entries matched. All five normal owners report zero byte
  difference, zero relocation-target mismatches, and zero boundary escapes.
- The generated destructor also reports zero byte difference, zero relocation
  target mismatches, and zero boundary escapes.

No inline assembly, synthetic owner, duplicate `AIModule` declaration, or
codegen-only source machinery was added.
