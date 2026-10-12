# `tact_wnd.cpp` cleanup report

## Module and commits

- Module: `src/tact_wnd.cpp`.
- PDB source: `C:\\msdev\\work\\age1_x1\\tact_wnd.cpp`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Initial source commit: `1aa46a4526f1e468e831d2552c08e43329a77314`.
- Initial report commit: `1bd74c08be703207a9c636edfbeac0af54760187`.
- This correction commit follows. Its full hash is in the final handoff.
- Changed files:
  - `src/tact_wnd.cpp`.
  - `workflow/decomp_notes/source_cleanup/wave03/tact_wnd.md`.
- `include/tact_wnd.h` was read but not changed.
- No other header was changed.

The source module has six handwritten owners. The registry marks all six
owners `matching` at this base. I did not recheck those claims.

## Original-name recovery

I inspected procedure-scoped parameters, locals, and registers for every
handwritten owner. The evidence is in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB records `this` in `ecx` for every owner.

| VA | Owner | Recovered parameters | Recovered locals |
| --- | --- | --- | --- |
| `004D3470` | first constructor | `infile`, `obj_in` | none recorded |
| `004D34C0` | second constructor | `obj_in` | none recorded |
| `004D34F0` | destructor | none | `players` |
| `004D3690` | `first_in_stack` | `first_time` | none recorded |
| `004D36B0` | `set_state` | `new_state` | none recorded |
| `004D3810` | `update` | none | none recorded |

The source now uses the recovered names `infile`, `obj_in`, `players`,
`first_time`, and `new_state`.
The constructor names replaced `id` and `object`.
The action methods replaced `value`.

The PDB has no local records for `update`.
I retained its existing declaration structure and used cleanup names
`time_delta`, `player_id`, and `owner` for its readable local mappings.
The file-scope static `LIMIT` name remains unchanged.
The PDB has no reliable original name for that static.

The destructor's `world`, `player_num`, `current`, `i`, `found`, `owner`,
`node`, `action`, and `master` names are descriptive cleanup names.
They are not claimed as original names.
I did not force names across reused or optimized stack slots.
There are no unresolved parameter declaration mappings.
Optimized locals without PDB records remain cleanup mappings.

The nearby `004D34A0` scalar deleting destructor is compiler-generated.
It has no handwritten source owner and was not changed.

## Source cleanup and evidence

- Applied 1TBS brace placement to all function definitions.
- Kept statement order, declaration scope, types, casts, calls, literals, and evaluation order.
- Added no comments.
- Added no macros, enums, or resource declarations.
- Added no helper, layout, ABI, or structural rewrite.
- Changed no public function, class, member, global, or ABI symbol name.

The function evidence packets are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D3470_TRIBE_Action_Wonder.txt`
  SHA256 `994fd8db940e955b9ef4832c818b04f9798e0d1a20b44bf2aa15f6e07f04b29d`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D34C0_TRIBE_Action_Wonder.txt`
  SHA256 `be5ee69fffa5ab4be53b94da56aabf61257d857d26eee3856299511fd690651a`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D34F0_TRIBE_Action_Wonder.txt`
  SHA256 `33cf4ef625a277468eeead3286188daaeffa1a09ba1d494629273206140c9b48`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D3690_first_in_stack.txt`
  SHA256 `729df6affc92e94d0b787f33fca4c640d8b4e22c894e8d4788221bef1faa3bba`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D36B0_set_state.txt`
  SHA256 `2e1beed964fe5b296b076664680f246c242284f76059aaeaffdc6b64003ace26`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D3810_update.txt`
  SHA256 `7083a9931e0bf64ccb7b879087f2e4f3fd95f1e46dc11e73d7d3d882aadd8a51`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

The original packets are:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tact_wnd.cpp.asm`
  SHA256 `33a5d3e907c74f92e06d94c081b14b974e97206196b658886e4937d834e88a3a`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tact_wnd.cpp.decomp`
  SHA256 `ad0a9aba0f2b7f4fcdbce74ea757180470f68449123301fbcfece74b2cb94d66`.

The original global inventory records `005753D8` as `2000.0f`:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/globals/all_globals.csv`
  SHA256 `329f6a619cfc7762a2751b7c931751248df68d19bc632e8dc136b77b013ab464`.

The preserved executable and baseline object were available at these paths:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tact_wnd.obj`
  SHA256 `6b361ff161fcfa487bdb4f51a8e98393f169cf4e932a7ae65589728ac6da9ba1`.

## Constants and resources

The file-scope static `LIMIT` remains `2000.0f`.
No reliable original PDB name supports a rename, so `LIMIT` stays unchanged.
The original decompiler packet tests the timer against `2000.0`.
The global inventory records the same value at `005753D8`.
The value and floating-point type remain unchanged.

The action type `0x78`, master ID `0x114`, notification IDs `0x6C`, `0x6D`,
and `0x6E`, and countdown value `2000` remain numeric.
Their call targets and argument order establish action, object, notification,
and timer roles. No shared constant request is needed.

This module has no resource lookup.
No resource ID was investigated, renamed, or added.
No language DLL extraction was needed.
The generated packet's language comments for numeric collisions are not
resource lookup evidence.

## Shared requests and unresolved questions

- Header request for `include/tact_wnd.h`: none.
- Shared `include/resource_ids.h` request: none.
- Shared `include/game_globals.h` request: none.
- No shared declaration request is pending.
- The PDB does not provide names for optimized `update` locals.
  Those names remain cleanup names.

The name and formatting changes can affect debug names and line records.
No type, object layout, call target, relocation, or symbol identity changed.
No claim about generated-code equality is made before final validation.

## Validation limits

I reviewed the complete source and report diff.
`git diff --check` passed before the source commit.
Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime command was run.
