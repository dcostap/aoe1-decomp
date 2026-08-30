# Recovery journal: 004174A0 `seekAndDestroy`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/aiuaimod.cpp`.
- PDB source: `C:\msdev\work\age1_x1\aiuaimod.cpp`.

## Translation-unit context

- PDB module: `aiuaimod.cpp`, source lines 3753-3767.
- Natural owner: `src/aiuaimod.cpp`, `UnitAIModule::seekAndDestroy`.
- Address sequence: 004174A0-00417501, 98 bytes, `__thiscall`.
- The body has two early-return paths and one success path.
- The original success path calls the object virtual at vslot `0x150`, then
  `setCurrentAction`, then `setCurrentTarget`.

## Current mismatch

- Fresh direct check: rebuilt 98/98 bytes, 37/37 instructions, no frame, and
  saved registers `esi` and `edi`.
- Boundaries, owner symbol, CFG shape, and both returns match.
- Calls have the same count and positions. The first call target differs:
  original vslot `0x150`; rebuilt vslot `0x14C`.
- Strict diff: 1 byte (1.0204%), at function offset `+0x1F` (`50` versus
  `4C`). Two relocations remain safely masked.
- Result: `MISMATCH`.

## Recovered attempt history


<!-- recovered:dce44a5e3d1040328af0 -->
### `d050eea3c` `src/aiuaimod.cpp:2797-2797`

Mapping: `strong`. next mapped function definition is seekAndDestroy at old line 2819.

```text
// --- matching/00417440_defendPosition.cpp ---
```
<!-- end-recovered:dce44a5e3d1040328af0 -->

<!-- recovered:aff0a84a919f546db349 -->
### `d050eea3c` `src/aiuaimod.cpp:2821-2821`

Mapping: `strong`. comment lies after mapped function seekAndDestroy at old line 2819.

```text
// --- matching/004174A0_seekAndDestroy.cpp ---
```
<!-- end-recovered:aff0a84a919f546db349 -->

## Rejected approaches

- The natural body remains the simplest behavior-backed form. It gates on
  `param_4 != 0` or `currentActionValue == -1`, calls `attack(param_1,
  param_4)`, sets action `0x26E`, stores the two integer coordinates as
  floats, and passes `1.0f` as the final target coordinate.
- A temporary explicit `RGE_Combat_Object*` cast, with its header included for
  the experiment, still emitted vslot `0x14C`. It was not retained.
- A pointer-to-member spelling emitted a 95-byte body and a direct unknown
  call. It was not retained.
- No body-only natural spelling changed the overload slot. Do not use a raw
  vtable access, wrapper, or compiler-steering form.

## Open questions

- `include/stat_obj.h` currently declares the `attack(float,float,float,int)`
  overload before `attack(int,int)`. VC5 emits the two-argument call at
  vslot `0x14C` from this declaration surface.
- The old standalone source artifact in `build/asm/rebuilt_004174A0_seekAndDestroy.cod`
  emits the required `+0x150` call. Its historical `aiuaimod_context.h`
  declared `attack(int,int)` before the float overload. This supports a
  shared header-order investigation, but does not permit a worker header edit.

## Next useful approaches

- Test the overload declaration order in an isolated shared-header experiment.
  The original packet requires `RGE_Static_Object::attack(int,int)` at
  vslot `0x150`.
- If the header-order experiment restores the byte, repair the shared ABI
  declaration through the coordinator, then rerun the complete aiuaimod audit.

## Worker updates

- `wave21-aiuaimod`: source unchanged; current natural reconstruction is
  behavior-complete but misses one overload-slot byte. Focused check and the
  grouped audit both report this same one-byte mismatch. The target-session
  baseline recording timed out on the shared session lock; no retry was made.
