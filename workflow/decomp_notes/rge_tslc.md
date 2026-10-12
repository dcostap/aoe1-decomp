# RGE_TSLC.cpp recovery notes

The PDB maps 13 normal functions to `RGE_TSLC.cpp`.
The functions are in VA and PDB order in `src/rge_tslc.cpp`.

The original code proves a 256-byte text buffer at offset zero.
It also proves 101 timing samples and the fields after the buffer.
The module header records this class layout.

`GetHiLoMaxInfo` and `GetHiLoInfo` leave output values unset for invalid counts.
The original code reads the incoming count home in that path.
The recovered source keeps the unset output values.

## Original invalid-count reads

`GetHiLoMaxInfo` tests the count before assigning `average`, `minimum`, and
`maximum`. It then passes those automatic values to `sprintf` for an invalid
count.

ORIGINAL BUG: The executable reads these unset automatic values for invalid
counts. Its invalid branch loads all three values from the incoming count home
before `sprintf`. Keep this behavior. Initializing them would change the
shipped output and the read order.

`GetHiLoInfo` has the same invalid-count path. It passes unset `average`,
`minimum`, and `maximum` values to `sprintf`.

ORIGINAL BUG: The executable reads these unset automatic values for invalid
counts. Its invalid branch loads all three values from the incoming count home
before `sprintf`. Keep this behavior. Initializing them would change the
shipped output and the read order.

`Skip` calls `debug_timeGetTime` two times.
The first return value is discarded.
This behavior is present in the original code.

## Set migration regression

The direct source uses simple field updates for the low and high values.
The behavior is unchanged.

`check_function.py --va 00480480` reports a mismatch after migration.
The original size is 141 bytes. The rebuilt size is 133 bytes.
The strict positional difference is 34 bytes, or 24.1135 percent.

The source module keeps this function in `scratch` because no logic-review
ledger supports a `verified_logic` status. Exact repair must use the final
module source.
