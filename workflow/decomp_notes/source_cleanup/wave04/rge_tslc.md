# Source cleanup report: `rge_tslc.cpp`

## Delivery

- Module: `src/rge_tslc.cpp`
- Header: `include/rge_tslc.h` (read only; owned by group owner 28)
- Registry: `config/functions/src/rge_tslc.cpp.json`
- Branch: `cleanup/staging-20260915-247`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source-cleanup commit: `53617de0755ee1ae6023e731a71f887e7bdb51ff`
- Changed files:
  - `src/rge_tslc.cpp`
  - `workflow/decomp_notes/source_cleanup/wave04/rge_tslc.md`

The source owns 13 normal functions. The registry selects all 13 functions.
The source order and function boundaries remain unchanged.

## Evidence

I read the complete cleanup, comments, resource-ID, owner, testing, and wave
assignment guides. I read the assigned source and header. I did not edit the
header.

I inspected the original function packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/` for every
assigned VA. The packets provide original boundaries, source lines, calls,
register use, and assembly. I also inspected:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/rge_tslc.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/rge_tslc.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/all_types_ground_truth.h`

The PDB source path is `C:\msdev\work\age1_x1\RGE_TSLC.cpp`. The pinned
original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The pinned PDB SHA-256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/rge_tslc.obj`.
Its SHA-256 is
`0a7e4ab51f89c0c3182d91c1d0299d09740e02907fe5026270aafab16ce07ccc`.
The preserved resource object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/original.res`.
Its SHA-256 is
`edd8f671b15254db0be049b421947cda59bbffdeb46a1d4c93176e42bfe9ee3a`.

The original type inventory records `RGE_TimeSinceLastCall` as 0x2B4 bytes.
It records the existing member offsets and types. This cleanup changes no
member, layout, or storage declaration.

## PDB name-recovery coverage

The table lists every registry-selected procedure. Each class procedure has a
`this` register record in ECX. No procedure has a function-static record.

| VA | Function | PDB lines | PDB size | PDB stack names | Source result |
| --- | --- | ---: | ---: | --- | --- |
| `00480390` | `RGE_TimeSinceLastCall::RGE_TimeSinceLastCall` | 8-19 | 87 | none | `this` in ECX. Existing `time` and `i` have no PDB records and remain unchanged. |
| `004803F0` | `RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall` | 22-22 | 1 | none | `this` in ECX. No rename. |
| `00480400` | `RGE_TimeSinceLastCall::GetAvg` | 59-82 | 81 | `duration: int` at `+0x4` | Recovered `count` as `duration`. Existing `sum`, `index`, and `i` have no PDB records. |
| `00480460` | `RGE_TimeSinceLastCall::Get` | 85-87 | 28 | none | `this` in ECX. No rename. |
| `00480480` | `RGE_TimeSinceLastCall::Set` | 90-113 | 141 | none | `this` in ECX. No rename. |
| `00480510` | `RGE_TimeSinceLastCall::Skip` | 117-122 | 41 | none | `this` in ECX. No rename. |
| `00480540` | `RGE_TimeSinceLastCall::GetAvgInfo` | 126-136 | 37 | `duration: int` at `+0x4` | Recovered `count` as `duration`. Existing `average` has no PDB record. |
| `00480570` | `RGE_TimeSinceLastCall::GetHiLoMaxInfo` | 139-148 | 146 | `duration: int` at `+0x4`; `Hi`, `Avg`, `Lo: unsigned long` at `+0x8` | Recovered `count` as `duration`. The three local records share one optimized stack home. No local mapping was forced. |
| `00480610` | `RGE_TimeSinceLastCall::GetHiLoInfo` | 152-161 | 132 | `duration: int` at `+0x4`; `Hi`, `Avg`, `Lo: unsigned long` at `+0x8` | Recovered `count` as `duration`. The three local records share one optimized stack home. No local mapping was forced. |
| `004806A0` | `RGE_TimeSinceLastCall::CPS` | 164-169 | 28 | none | `this` in ECX. No rename. |
| `004806C0` | `RGE_TimeSinceLastCall::GetFirstCall` | 173-175 | 7 | none | `this` in ECX. No rename. |
| `004806D0` | `RGE_TimeSinceLastCall::GetElapsedFirstCall` | 178-197 | 150 | none | `this` in ECX. Existing `hours`, `minutes`, `now`, and `seconds` have no PDB records. |
| `00480770` | `RGE_TimeSinceLastCall::Test` | 202-205 | 21 | none | `this` in ECX. Existing `i` has no PDB record. |

The PDB records no named locals for the other source declarations. The
recovered original spelling is `duration`. No public function, class, member,
global, type, ABI symbol, or calling convention changed.

## Renamed parameters and unresolved locals

I changed the four definition parameters named `count` to the PDB name
`duration`:

- `GetAvg(int duration)` at `00480400`.
- `GetAvgInfo(int duration)` at `00480540`.
- `GetHiLoMaxInfo(int duration)` at `00480570`.
- `GetHiLoInfo(int duration)` at `00480610`.

The PDB provides `duration` as an `int` at stack offset `+0x4` in each
procedure. The original packets show this value controls the sample count,
loop bound, average divisor, and formatted count field.

The PDB provides `Hi`, `Avg`, and `Lo` at the same `+0x8` stack offset in both
statistics functions. The original assembly also reuses one parameter home
for the loop counter and invalid-count output values. This evidence does not
map those three PDB names safely to the separate source declarations
`maximum`, `average`, and `minimum`. I kept those declarations and the other
existing inferred names. I added no declarations and did not force a reused
stack-slot mapping.

## Constants, resources, and comments

No constant was added, removed, or replaced. The original packets support the
unchanged values and uses:

- `00480390` stores `99999`, clears the fields, and clears 101 samples.
- `00480400` accepts sample counts from 1 through 100 and uses a 1000 threshold.
- `00480570` and `00480610` initialize the local low value to `999999`.
- `00480770` writes 100 samples with value `10`.
- `004806D0` keeps the 1000-millisecond and 60-second conversions.

The fixed source path and debug line arguments remain unchanged. `Skip` still
calls `debug_timeGetTime` twice and discards the first result. The invalid
count reads in `GetHiLoMaxInfo` and `GetHiLoInfo` remain unchanged. The
original packets show the invalid branches loading all three formatted values
from the incoming parameter home.

This module has no resource lookup and no resource ID. Therefore no numeric
ID, language, text, empty slot, missing block, lookup path, or resource name
applies. I ran `python tools/inspect_pe_strings.py --help` before this review.
I did not run resource extraction. For provenance only, the relevant supplied
resource hashes are:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`: SHA-256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`: SHA-256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`:
  SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

The Ghidra annotations for `0x78` and `0x79` in `Skip` are line-argument
annotations. They are not resource lookups. No resource mapping request is
needed.

The existing invalid-count comments remain. I changed only `count home` to
`parameter home` after recovering the parameter name. No new source comment
was needed.

## Code-generation, type, layout, and symbol review

The source changes rename identifiers and move function-definition braces to
1TBS form. They do not change types, declaration points, scopes, storage,
evaluation order, statements, calls, call targets, literals, member order,
function boundaries, relocations, or ABI symbols. The changed names can alter
debug names. Brace placement can alter debug line records. These effects are
not validated here.

The source keeps the original invalid-count reads, the two `Skip` calls, the
narrow integer types, and all existing explicit behavior. The existing module
note records a prior `Set` size mismatch. This cleanup does not address it.

## Header request

The group owner may update these header parameter names in
`include/rge_tslc.h`, without changing types, order, declarations, or ABI:

```cpp
unsigned long GetAvg(int duration);
char* GetAvgInfo(int duration);
char* GetHiLoMaxInfo(int duration);
char* GetHiLoInfo(int duration);
```

The header remains unchanged in this commit. No root-owned header or shared
resource-ID request exists.

## Unresolved questions

- The PDB `Hi`, `Avg`, and `Lo` records share `+0x8`. Their source declaration
  mapping remains unresolved.
- The PDB does not name the remaining source locals.
- The header still uses `count` until its owner reviews the request.
- The existing `Set` matching discrepancy remains outside this cleanup.

## Review and validation status

I reviewed the complete Git diff. I ran `git diff --check` during review.
Compilation, matching, audits, validation commands, tests, and games were
**NOT run**. Generated code, program data, relocations, and direct-target
identity remain unvalidated.

The source-cleanup commit is
`53617de0755ee1ae6023e731a71f887e7bdb51ff`. The report is committed after that
source commit. The final report-commit hash is recorded in the handoff.
