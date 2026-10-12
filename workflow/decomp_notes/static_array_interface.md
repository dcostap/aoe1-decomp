# Static-object array interface

## Behavior

The recovered group callers use the existing array operations.
They preserve the original capacity search, failed-allocation write, shifts, count reloads, and zero-count stores.
The guarded update loop retains the original outer group test.
All 103 matching targets pass with protected storage and with unchanged main headers.

The main integration preserves all 185 emitted function bodies.
One private string label changes its compiler number in `check_damage_sprites`.
The string stays at the same section offset with the same bytes.
All 209 non-debug sections preserve their indices, flags, bytes, and relocation locations.
All external symbols preserve their names and locations.
No existing scratch or accepted-drift behavior claim changes.

## Source

Only `src/stat_obj.cpp` changes on main.
Group callers now use `number`, `contains`, `add`, `remove`, and `zeroNumber`.
Complete loops replace expanded allocation and search code.
No shared header, compiler flag, wrapper, or friend declaration changes.

PDB symbols also restore the coordinate names in `changeInfluenceMap`.
The original X coordinate uses `minXTile` at stack offset `-8` and loop variable `x` at `+C`.
The original Y loop uses `y` at `-4`.
Parameter names are `iMap`, `increment`, `usePercentCoverage`, and `useLOS`.
The rename preserves expressions and loop order.

## Bytes

Protected state: `0a6d8d4782dedfedfb285bf55ac4e578150f51bc43e3e5cf5cc36bb9bab62983`.
Protected run: `48c8a5fb4e03a7663f93e63c776f070ed157197145a2a9ace1c5830ff1d5d10f`.
Main-header state: `b2cdf21054107a04be15c4dee2a42898ed3e516c9c9197bdd02b8f85bd2a258d`.
Main-header run: `0594b14b1867a3aefc1794a5a9239180ed4c853048b9bab3059c01125bf7b891`.
Both authoritative update checks report `MATCH`, `0.0000%`.

The first public-operation proposal changed influence code by 119 bytes.
Coordinate renames and clipped initializers alone did not fix that result.
A direct coverage expression changed evaluation order and was rejected.
An unguarded update loop restored influence code but changed update code.
The selected guarded normal loop preserves both exact bodies.
All variants remain in the experiment store.

## Integration

The main audit is `build/static-main-integration/report.json`.
The storage proof is `build/static-main-final-storage-proof.json`.
Tests passed: 415 tests and 31 subtests.
Line-ending and diff checks passed.
No game executable was run. No registry status changed.

The shared-array proposal still needs complete caller recovery and changed-owner review.
This independent source integration does not approve that proposal.
