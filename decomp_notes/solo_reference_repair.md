# Static reference and source repair

## Scope and behavior

No original or rebuilt game was run. No subagent was used.
`AGENTS.md` now records the no-game rule.
The work uses original executable bytes, PDB evidence, the pinned compiler, and static linked-image checks.
Existing unrelated workspace changes remain intact. This report records validation before commit.

## Integrated source

- `src/Scr_sels.cpp`: call the original `TEasy_Panel::action` fallback at `004B42E0`.
- `include/vw_main.h`, `src/vw_main.cpp`: restore implicit destructor generation; remove the unsupported intermediate vptr write.
- `include/utmarray.h`: remove the incorrect receiver const qualifier from `contains`.
- `include/tech.h`, `src/tech.cpp`: restore six short references in `tech_cost`.
- `src/tplayer.cpp`, `src/scr_game.cpp`: pass the same four callers' output locations through that reference signature.

The shared headers changed are `include/vw_main.h`, `include/utmarray.h`, and `include/tech.h`.
The view, array, and Tech dependency checks cover 9, 90, and 14 modules, respectively.
Detailed reviews and experiment records are linked below.

The array declaration changes code generation in two existing scratch functions: `004F7870` and `004F81A0`.
Neither received an equivalence approval or status promotion.
The exact caller patch is `decomp_notes/candidates/004F/004F1090_exact_candidate.patch`.
The tested source base is `729d94ca0`; preserved states include the complete additional inputs.

## Evidence and build routes

Hash-checked CRT evidence establishes missing identities and target-scoped legacy aliases.
The checks do not treat public/protected access or receiver qualification as aliases.

The registry now routes 97 header functions through natural source emissions.
All remain scratch, including the differing RESENDER constructor.
Original public symbols and the module contribution establish 33 Tech identities.
`config/flags/unoptimized.rsp` gives those functions a normal source build route.
They also remain scratch. Twenty-nine produce local matches; four retain differences.

Registry totals: 4,722 matching, 287 accepted drift, 16 verified logic, 365 scratch, and 36 unresolved.
No function is unclaimed or in conflict. These are registry labels, not a claim that every check passes.

## Source experiments

The Tech lab tests six declaration orders under two optimization profiles.
The idle-civilian lab tests eight combinations of array access and local-variable scope.
Neither family produced an exact candidate. No metric-only source variant was integrated.

The first runs exposed a real lab defect: it ignored the configured compiler profile.
`tools/variant_lab.py` now freezes that profile and its hash before compilation.
The corrected runs and the incorrect-profile evidence both remain in the experiment store.
Regression tests cover the Tech profile, a header emission profile, and response-file changes.
The flag audit also distinguishes a routed header from a second source module.
It still rejects a header route that points to another module.

## Integrated validation

The full function audit compiles all 225 configured modules and checks 5,390 functions.
Of 4,722 matching claims, 4,675 pass, 45 lack reference evidence, and two have explicit symbol disagreements.
The earlier audit passed 4,390 claims. Thus 285 additional claims now pass the stronger check.
The audit still exits nonzero. Unknown results do not count as passes.

The two remaining disagreements are `004EA280` and `004EF4E0`.
Both concern ManagedArray resize access. The original protected linkage remains a source repair issue.
Their current matching registry labels remain contradicted by the strict audit; neither is presented as validated.

Fresh authoritative checks report `Result: MATCH` and `0.0000%` for:

- `004B42E0`: panel action, 528 bytes;
- `004F1090`: removeObject, 765 bytes;
- `00512BF0`: Tech caller, 49 bytes;
- `0050C2FA`: Tech help getter, 57 bytes.

The executable build compiles all 226 C/C++ sources and one assembly source.
It links without unresolved symbols. Build directory:
`build/executable/solo-final/20260908T140714494917Z`.
This is a build result, not a gameplay result.

The linked audit reports 6,846 passes, 5,237 unknowns, and zero failures.
The previous destructor failure now passes: `00495490` targets rebuilt `RGE_View::~RGE_View` at `00519FB0`.
Initial storage has 124 equal rows and no differing rows.
There remain 107 type/startup reviews, 60 unmapped names, and one invalid original section.

The fresh header audit reports 98 matching emissions, 34 unknowns, and one difference.
Two previously uncertain emissions now have evidence. Their registry routes were not automatically changed.
The RESENDER difference remains open.

The vtable audit finds 207 definitions and locates 206 tables.
It reports no conflicting definitions or unresolved-symbol slots. This does not prove all table boundaries.

Reports are under `build/validation/solo-*`.
The full suite passes: 400 tests and 31 subtests.
Ownership validation, line endings, and `git diff --check` pass.
The flag audit has no blocking issue. Its 27 frame-related warnings remain visible.
The function audit fingerprint still matches the final tool inputs.

Final input state: `4e0f70a98509d744f47d39b4fe3b41686312fd02fac510893b837376f030c7ec`.
Event `574c766580b3d317b65376a423fafd75bff5a50ac3615bc9867e5b5d199ffea0` preserves the complete validation archive.
The archive includes function, linked-reference, header, initializer, vtable, flag, test, and build reports.

## Detailed reviews and remaining work

- `decomp_notes/crt_reference_identity_review.md`
- `decomp_notes/functions/004B/004B42E0.md`
- `decomp_notes/view_destructor_repair.md`
- `decomp_notes/managedarray_identity_repair.md`
- `decomp_notes/header_emission_routes.md`
- `decomp_notes/tech_public_identity_review.md`
- `decomp_notes/functions/004F/004F81A0.md`

Next, repair resize access through its complete caller closure.
Resolve the 45 matching-claim evidence gaps without weakening identity checks.
Review the new header selections, then continue natural Tech and scratch source experiments.
The Tech compiler-context explanation remains a hypothesis, not a proved cause.
