# 0047E530 `XYZ::operator+`

- PDB source: `point.cpp`, lines 70 to 73.
- Flags: `config/flags/default.rsp`.
- Original size: 75 bytes.

The original builds a temporary with `XYZ(int, int, int)`. It then copies the temporary to hidden return storage.

## Recovery record

1. A named constructor temporary without `game_globals.h` gave 36% parity. VC5 moved `this->zValue` before stack allocation.
2. Temporary variables and expression order tests gave the same 36% result.
3. Five variant tests changed constructor, assignment, direct return, and operand order. All constructor-temporary variants stayed at 36% without the context include.
4. `game_globals.h` gave the required compiler context. The grouped build then matched exactly.

The function remains `scratch`. The fragment wrapper had a seven-byte grouped difference. Do not promote this observed result without review.

## Module merge transition

The fragment wrapper build had a seven-byte grouped difference. `src/point.cpp` has the same body and flags. It removes only fragment and context scaffolding.

The merged module has a zero-byte grouped result. It still has no proved owning symbol. The result stays `scratch` until a main-agent source and ownership review.

Tests moved `math.h` to its former source-order position. A repeated normal header include did not change the result. An explicit `this` form and a local third sum also gave a zero-byte result. The final source keeps the original direct temporary form.
