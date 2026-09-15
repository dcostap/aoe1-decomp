# Linked-image dependency repair, 2026-09-14

## Scope and inputs

Worker: `image-dependency-repair`.
Branch: `repair/image-dependencies-20260914`.
Prepared HEAD: `07ff7cbd8bef0dfa5407c1637452c95f7b41f2f2`.
Source base: `512b486599425df79db010d683db86c54880d7ff`.
The prepared HEAD includes supplied tools and evidence from `c523ce7b3`.
Preparation and audit imports are not repair commits.
The repair changes five natural source functions, tests, notes, and preserved experiment records.
It changes no headers, registry entries, tool implementations, original files, or unrelated game source.

Original EXE: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Original SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The build, tests, and original-evidence extraction each check this hash.
Original instructions, operand bytes, tables, and independent callee identities support the repairs.
The packets provide source-owner and line references, not the behavior oracle.

The preserved linked baseline remains at:
`build/executable/human-civ-effect-repair/20260914T215953270395Z`.
Its EXE SHA256 remains `75ea997f420d64395b314f25d0b3b6bf75bb121c5dc962ee41f8f425bf58278b`.
A new baseline audit reproduces all 13 findings in `build/dependency-audit/repair-baseline/`.
No existing build or report was replaced.

## Behavior

| Owner | Proven defect | Repair |
| --- | --- | --- |
| `00460EB0 rotate` | Five reads use incorrect float or double approximations | Restore double `6.2831853` and float `6.2831853f` |
| `0051F310 init_timeline` | One float read uses `0.1f` | Use the original float value through `(1.0f / 12.0f)` |
| `00545E00 addObject` | Two growth reads use `1.5f` | Restore `1.1f` on both signed-ID paths |
| `00450D00 modify_percent` | Attributes eight and nine call the inherited modifier | Restore their empty return cases |
| `004C2110 draw_front_frame` | Three outline values select the wrong drawing helper | Map one to cube-front and two/three to square-front |

The function notes contain full branch, call, width, and effect checks:

- `decomp_notes/functions/0046/00460EB0.md`
- `decomp_notes/functions/0051/0051F310.md`
- `decomp_notes/functions/0054/00545E00.md`
- `decomp_notes/functions/0045/00450D00.md`
- `decomp_notes/functions/004C/004C2110.md`

`modify_percent` masks the attribute to a byte, subtracts six, and checks the index with unsigned `ja`.
Its original table entries two and three point past the inherited call to `pop esi; ret 8`.
All other original cases remain unchanged, including case 15 reading missile ID and case 18 replacing its field.

`draw_front_frame` uses an unadjusted unsigned outline byte with a maximum of three.
The original table points to virtual draw, cube-front, square-front, and square-front, in that order.
The separate game-mode-one path still calls cube-front.
No shared enum value changes.

The repair preserves original edge cases rather than improving them.
Examples include the zero timeline rate at page count 12 and strict object-capacity growth comparisons.
No game session, replay, or rendering capture was run.
Static evidence does not establish a gameplay symptom or full runtime parity.

## Source

The game-source patch changes only:

- `src/move_obj.cpp`: five literal spellings in `rotate`.
- `src/tpnl_tml.cpp`: one constant expression in `init_timeline`.
- `src/world.cpp`: two growth literals in `addObject`.
- `src/m_co_obj.cpp`: two empty cases in `modify_percent`.
- `src/stat_obj.cpp`: two case-label lines in `draw_front_frame`.

No inline assembly, wrappers, copied code bytes, forced compiler helpers, or validation exceptions were added.
The original bytes prove numeric values and dispatch effects, not the exact spelling of the old C++ source.
Existing source and note files retain LF line endings.

## Bytes

All five final local checks report `MATCH`, `0.0000%`, correct owners, and supported original boundaries.
Their instruction sizes remain 143, 455, 457, 234, and 125 bytes, respectively.
The three numeric owners previously reported `MISMATCH` despite zero instruction differences.
The two switch owners reported local `MATCH` before the repair because local validation does not check linked tables.
Thus local instruction agreement and linked-data agreement remain separate results.

### Preserved states

Each state uses the pinned VC5 toolchain and `config/flags/gx.rsp`.
Every baseline and repair has a fresh local check and a complete natural translation-unit audit.
Baseline audits use at most two jobs. Repair audits use one job.
The full executable build compiles sequentially.

| Owner | Baseline state ID | Repair state ID |
| --- | --- | --- |
| `00460EB0` | `4274477550eed50942080121ae0badb755288eaec7222fa737b983a30dbe95dd` | `fd90c2a6f0f345ee7ec871bad6bb822d3c2e429fb629f8fb325fe50d57232274` |
| `0051F310` | `276d2c426dc24498f622da87496d183ca3074697f752539f1f88bdf7c368aa37` | `259d4c77924bd10bfbfc8d74b310a76a60bba6230da9d38171660c9f08d7d2d5` |
| `00545E00` | `12884902ffa0cd19f2b9c49ef23f8b3e81d97a8ccc0b173969ef0e457efbe680` | `bf39f709ce49b81223fd64d3934eb78685b85b0c392e0296184f1fd7d7de5faf` |
| `00450D00` | `e30550e2a30a5455aaa6407a9a5856228a1b393748177b25feb72c080e41192a` | `211d63a091ab4b6dffe24c5bb2ee0c041a0066b5399f4b8b31b3f62f9a315947` |
| `004C2110` | `f53a7e13e029a8bb396e1de5d31102fe330ebccd8dc5fd7f25e564f45fb8ff10` | `88b5fdbb480f353df55e33859231cedc346b43649b62c6f26654b2edf404b84b` |

The names use `image-deps-VA-baseline` and `image-deps-VA-repair`.
The immutable store is `decomp_notes/experiments/`.
Its events preserve checker output, input hashes, closure reports, and supplemental evidence.
Automatically exported baseline switch candidates remain historical evidence, not claims of correct linked dispatch.

### Translation-unit checks

| Group | Checked owners | Final local matches | Failed matching claims |
| --- | ---: | ---: | ---: |
| `move_obj` | 51 | 47 | 0 |
| `tpnl_tml` | 25 | 21 | 0 |
| `world` | 92 | 89 | 0 |
| `m_co_obj` | 15 | 13 | 0 |
| `stat_obj` | 116 | 106 | 0 |
| Total | 299 | 276 | 0 |

The other 23 owners retain their prior nonmatching or review categories. Their code was not edited.
No neighbor loses its prior local check result.
`build/image-dependency-repair/closure-comparison.json` records all before/after reports and object hashes.
It also compares all COFF section bytes and resolved local relocation coordinates.

The only changed local target coordinates in `m_co_obj.obj` are the two repaired switch entries.
Seven neighboring owners have compiler-generated label-name changes only:
`0044FE40`, `0044FEC0`, `0044FF30`, `004506D0`, `004507A0`, `00450A00`, and `00450B40`.
Their section bytes and resolved relocation coordinates do not change. All seven remain matching.
The static-object object changes only the three repaired table coordinates.

Rotation constants share existing float storage after repair, reducing its read-only section by four bytes.
The other two numeric modules change only their expected constant bytes.
The linked audit separately checks actual operand values rather than assuming storage identity.

### Fresh executable and linked audit

Build command:

```text
python tools/build_executable.py --output-dir build/executable/image-dependency-repair
```

Fresh build: `build/executable/image-dependency-repair/20260914T232240813249Z/`.
All 226 source files and one assembly source compile. The link has no unresolved symbols or errors.
The build retains only the repository-approved compression and drawing binary dependencies.

- EXE SHA256: `a08f0f55205af277b0c275811aac6e2be7fa67deda5198f930a29dd7051f6081`
- Map SHA256: `8767147f9b6d4f8f13f0d2f503b74f0fa391c9e6f21e70498f24ce06e628e8b3`
- Build-report SHA256: `a501d1c9e3570008b3282f3c6e60bcdf2d5e9983287fda9ed99103e120675329`

Audit command:

```text
python tools/audit_image_dependencies.py --build build/executable/image-dependency-repair/20260914T232240813249Z --output build/dependency-audit/repair-final
```

The audit returns zero: 7,760 pass, zero fail, and 47,025 unknown checks.
All eight numeric failures and five switch failures become passes.
All nine historical numeric reads remain supported passes in the regression tests.
All 136 reviewed initial-storage and pointer checks remain passes.
The audit reports 421 passing switch entries and 11 unknown switch sites.

`build/image-dependency-repair/coverage-comparison.json` compares all 54,785 check identities.
No check disappears or appears. Exactly 13 results change, each from fail to pass.
Unknown reasons and emission counts remain unchanged.
There are no new failures or coverage losses in this audit.

### Tests

`tests/test_image_dependency_repairs.py` verifies original and selected rebuilt image bytes.
It checks all eight repaired reads and the nine historical reads.
It checks all 256 combat attribute routes, no-effect return blocks, and the inherited callee identity.
It checks drawing case targets, helper identities, unsigned bounds, and the separate game-mode branch.
No expected values, existing tests, or audit checks were weakened.

The preserved linked baseline is a negative control: five owner tests fail and 13 tests pass.
This detects the defects even though all five instruction windows align.
Report: `build/image-dependency-repair/baseline-regressions.xml`.

The full suite without a selected rebuilt fixture passes 724 tests and 31 subtests, with ten skips.
Nine skips require the explicit rebuilt fixture. One skip lacks the older broken historical build.
Report: `build/image-dependency-repair/full-suite.xml`.

The focused suite with the fresh linked fixture passes 107 tests, with one historical-build skip.
It includes dependency, linked-image, game-harness, and video-harness tests.
Report: `build/image-dependency-repair/final-focused-corrected.xml`.
An earlier focused command named an absent test file and ran no tests, with exit code four.
Its report remains at `build/image-dependency-repair/final-focused.xml`.
The corrected command uses `tests/test_dependency_validation.py`.

The final full suite enables the exact fresh linked fixture:

```text
AOE_DEPENDENCY_BUILD=build/executable/image-dependency-repair/20260914T232240813249Z python -m pytest -q --junitxml=build/image-dependency-repair/final-full-suite.xml
```

It passes 733 tests and 31 subtests, with one unavailable historical-build skip.
The nine fresh linked-fixture cases pass instead of skipping.

### Evidence archive

`build/image-dependency-repair-validation.zip` contains the complete before/after linked audits and the build report and map.
It also contains original-byte evidence, closure comparisons, check comparisons, analysis scripts, and all test reports.
Final experiment finding events preserve this archive as a hashed object in `decomp_notes/experiments/`.
The archive does not replace the existing reports or the separately preserved compiler input states.

## Integration and limits

Retain the five scoped source repairs and their evidence. No registry status change is needed.
No accepted-drift proposal accompanies this patch.
All shared headers, other workers' source, the accepted human recording, RNG, and rendering inputs remain untouched.

`src/tpnl_tml.cpp` is shared with the separate `draw_special_events` review.
Apply the one `init_timeline` change without replacing that worker's function.
The compiled section comparison finds no emitted owner change elsewhere in the timeline module.

The audit still has 47,025 unknown checks, including unaligned windows and unreviewed storage or dispatch targets.
It does not prove full image ownership, inherited callee behavior, every indirect target, or runtime parity.
The harness unit tests do not establish actual gameplay or rendered-pixel parity.
The older broken executable is unavailable locally, so its optional regression remains skipped.
The preserved civilization-repaired baseline and fresh executable both retain the nine historical repairs.

## Main integration

Main commit `0b0a097e1` imports only repair commit `8c3dbb7a6`, not its preparation commits.
The four unshared source files match the worker's committed blobs.
The timeline merge retains the separately approved `draw_special_events` patch.
All eleven former scratch functions subsequently completed independent dual review.
Their registry status is `new_verified_logic`; their local byte checks remain mismatches.

The final combined build is:
`build/executable/all-review-repairs/20260914T234718323952Z/`.
EXE SHA256: `4b833839dc713ae378e0efbb40509f2ebdc15df17b60df1eb8a7fe63a461a221`.
All game sources compiled and linked.
The final linked audit is `build/dependency-audit/all-review-repairs/`.
It reports 7,760 passes, zero failures, and 47,025 unknown checks.
The full suite with this linked fixture passed 749 tests and 31 subtests.
Test report: `build/all-review-repairs-tests.xml`.

`build/final-dependency-coverage.json` retains the comparison with the original 13-failure audit.
All 54,785 check identities remain. Exactly 13 statuses change from fail to pass.
The stricter unknown-reason equality check fails for one check in `setup_buttons`.
Its reason changes from an unverified containing emission to unaligned instruction windows.
That check remains unknown. No unknown check becomes a pass.
The build directory retains the initial comparison and failed assertion.

Sparse-checkout changes removed the ignored runtime inputs during integration.
The restoration script copied inputs from preserved original runs, not from rebuilt state.
All 414 restored files match the unchanged recording's asset hashes.
Restoration record: `build/runtime-input-restoration.json`.
The local sparse checkout now includes `runtime` and the current review archives.
The recording, original files, prior captures, and prior builds remain unchanged.

The first final parity run is `build/runtime/parity-20260914T235333018159Z/report.json`.
Its short scripted case passed. Both human workers correctly rejected the starting contract.
Sparse checkout had also restored the tracked `runtime/README.md`, an extra repository document.
The game inputs themselves matched all 414 hashes.
Runtime preparation now omits only that root repository document from staged game inputs.
It still copies the installed `Readme.doc`, nested documents, and all other input files.
The recording and contract comparison remain unchanged.
A new test checks this distinction. All 64 focused tests passed.
The failed replay reports and logs remain intact.
