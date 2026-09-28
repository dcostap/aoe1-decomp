# AI history repair and exact promotions

## Scope

The starting commit is `54b1abc1a`.
The only game-source change selects the correct unit-history writer in `src/taiinfmd.cpp`.
See `functions/004D/004D7CB0.md` for the original instruction evidence.

## Fresh exact checks

The complete module audit compiled 225 groups and checked 5,426 normal functions.
All 4,971 existing matching claims passed.
Ten other functions produced exact results, including seven with `new_verified_logic` status.
The queue lists only three promotions because it preserves `new_verified_logic` status by default.
This task explicitly requests promotion of all exact nonmatching functions.

Each target also passed a separate `check_function.py --no-history --detail concise` check.
Each result proves positional byte equality, the original boundary, ownership, and supported direct-target identity.
Supported numeric checks passed or remained explicitly unknown; unknown linked storage is not an exactness claim.

Reports are under `build/validation/ai-history-promotions/`:

- `functions/report.json`: complete initial module audit;
- `check-<VA>.txt`: ten direct target checks;
- `functions-final/report.json`: complete audit after status updates.

## Source review and decisions

| VA | Function | Source review |
|---|---|---|
| `0041E7D0` | `RGE_Base_Game::setup_main_window` | Normal Windows calls, rectangle adjustment, focus, and IME setup. |
| `004348B0` | `RGE_Command::do_command_create` | Typed player and master-object lookup, followed by the original virtual call. |
| `0043E9E0` | `THelpDialog::setup_help` | Normal layout, text, button, and tab-order operations. |
| `0044F040` | `InfluenceMap::maxValue` | Preserves the first-element read before the size check and the signed maximum comparison. |
| `0046B620` | `PathingSystem::incrementObstruction` | Preserves the packed two-bit field and saturation at three. |
| `00473D60` | `TDialogPanel::setup` | Preserves setup failure, modal registration, and parent-focus updates. |
| `004C3B30` | `RGE_Static_Object::draw_frame` | Uses normal drawing calls and preserves health conversion and integer division. |
| `004D7CB0` | `TribeInformationAIModule::~TribeInformationAIModule` | Corrects the world field; preserves writes, cleanup, and the `0xFF` writer case. |
| `00521790` | `TRIBE_Game::setup` | Preserves resource order, startup branches, and the repeated month in log dates. |
| `00538710` | `RGE_View::draw_tile` | Preserves border order, terrain calls, and neighbor redraw flags. |

Promote all ten to `matching`. Keep existing behavior-review links.
No assembly wrappers, new compiler tricks, or source changes support these status updates.
The destructor retains its exact byte-offset iteration over memory records; this task does not alter those loops.
Exact emitted code supports that existing source form under the repository policy.

The complete initial audit also reports 21 boundary problems in other nonmatching functions.
Those results do not qualify for promotion. This task does not repair them.
Unresolved build routes and unconfigured emissions remain outside the module audit's coverage.

## Final validation

- Registry validation passed with `--no-build-checks`.
- The final complete module audit passed all 4,981 matching claims.
- The matching-owner audit found zero owner mismatches and zero class/free-function mismatches.
- `game.py build` compiled all 226 sources and linked without unresolved symbols.
- The linked dependency audit reported 11,360 passes, no failures, and 47,881 unknown checks.
- Full pytest: 1,000 passed, 2 skipped, and 31 subtests passed.
- Both skipped tests require unavailable optional historical builds.
- `game.py test-traces` passed all five cases on original and rebuilt executables.
- The chaos case passed its written-file check, including `learn/Default.uh`.
- `git diff --check` passed.

Build directory:
`build/executable/user/20260928T205030198504Z-8e26643d8a85/20260928T205030434490Z`.

Rebuilt executable SHA-256:
`c14e88d083f1d01ff76394b1a4daaf03d06db594106b34c109cc1633206548ba`.

Trace report:
`build/runtime/traces-20260928T205318959856Z-98dc777cce10/report.json`.

Menu captures and the paced parity suite were not rerun.
Passing traces do not prove complete gameplay or multiplayer correctness.

A concurrent edit joined two lines in `TRIBE_Game::start_video` after validation started.
Leave that unrelated edit uncommitted.
The follow-up `tribegam-format-followup` audit passed all 114 matching claims in that module.
The trace and linked reports apply to the recorded build, not later source edits.
