# Accepted-drift review wave

## Assignment

The user requested a new review of all accepted-drift functions and renewed exact-matching attempts.
The approved worker model is `openai-codex/gpt-6-luna`, with `xhigh` thinking.
The active limit is 40 matching workers. Each worker uses one compiler job.

The integration baseline is `23f6673f7e701837099507a9888d0197784c1db4`.
That registry contains 228 accepted-drift functions across 89 natural source modules.
The first launch selected the 40 modules with the most accepted-drift targets.
Each module has one worker in its own detached worktree.
New modules start when capacity becomes available.

## Reason for reopening

The old accepted-drift approval for `004D7CB0` concealed a wrong world-field read.
Commit `6e1c3f02c` repaired that defect. The function now matches exactly.
This does not prove that other accepted-drift approvals are wrong.
It does justify checking their original behavioral evidence again.

## Review requirements

Review behavior before byte tuning. Check the complete function against the original executable.
Previous source and approval notes are hypotheses, not substitutes for instruction evidence.
Check field offsets, widths, call arguments, writes, loops, cleanup, aliases, and fault order.
Preserve original bugs. Repair decompilation bugs even when byte similarity gets worse.

Workers may experiment with shared source only inside their isolated worktrees.
They must preserve baseline and tested inputs through `workflow/docs/experiments.md`.
They must audit changed modules and the full closure of shared changes.
Workers cannot change registry statuses or commit proposals.

Integration requires source review, fresh exact checks, and affected-owner validation.
Do not renew a behavior approval while material checks remain unresolved.
Keep exactness, behavior findings, and integration decisions separate.

## Session records

The initial assignment manifest is `build/accepted-drift-wave/assignments.json`.
The first launch request is `build/accepted-drift-wave/batch-01.json`.
These are scheduling records, not durable technical evidence.
Workers must record technical findings and preserved experiments in `workflow/decomp_notes/`.

The user also requested a commit of the pending formatting edit in `src/tribegam.cpp`.
That edit joins two lines without changing tokens. It is outside the workers' initial baseline.

## Integrated review decisions

The first packages covered `scenario`, `Mouseptr`, `dstring`, `visible`, and `dpl_obj`.
Their commits are `48762168e`, `848eb3936`, `e17094f3c`, `390acdaf8`, and `23dd17069`.
The visible-map review withdrew approval for `0053C5D0` and `0053D200`.

The next packages include `basegame`, `fractal`, `scr_sed`, `player`, `scr_game`,
`infmap`, `rmm_elev`, `rmm_terr`, `tcommand`, `com_obj`, `Dib`, `pathsys`, and `pnl_btn`.
Their function notes and experiment events hold the original instruction evidence.

`00470CB0` and `00431250` now match all original bytes with their owning symbols.
The integrated five-module audit found both exact and all 415 matching validation targets exact.
`0044E250` now passes the original `"wa"` mode to `fopen`, not the prior `"wt"` mode.
The original executable contains `"wa"` at the call's data address.
Runtime file output and linked data placement remain untested.

The following targets now have `scratch` status. Their old drift approvals lacked the required proof:

| Target | Open issue |
| --- | --- |
| `0041E920` | Six meaningful code bytes exceed the original boundary. |
| `0046FF90` | List reads have a different fault order. |
| `0046B680` | The typed source removes a boundary escape, but 77 bytes still differ. |
| `004847C0`, `004848A0` | Broad code differences lack complete behavior proof. |
| `00484B90` | Map-dimension reads have a different fault order. |
| `00488B90` | Broad code differences lack complete behavior proof. |
| `00488E60` | Width and height reads have a different fault order. |
| `0043A070` | The 183-byte structural difference lacks complete behavior proof. |
| `004A9CC0`, `004ABCD0` | Reference windows conflict; behavior and linked data remain unproved. |
| `004AB670` | Call setup precedes a row read that the original performs first. |
| `0049B910`, `0049BDB0` | Call setup or receiver loads have an unresolved fault order. |
| `00473930` | The panel-field reads have an unresolved fault order. |
| `0044BCD0` | The center-cell difference lacks proof for invalid indices. |
| `0044BF90` | Different x87 scheduling lacks a numeric equivalence proof. |

`scratch` is not a finding that the source is wrong on normal inputs.
It means the accepted-drift claim remains unproved.
Other reviewed functions retain their present status while their narrow evidence is checked.
No wave-wide approval or gameplay result follows from these module audits.

The next packages cover `view`, `drawarea`, `spanlist`, `stat_obj`, `diam_map`,
`Pnl_scbr`, `aiconmod`, `effects`, `move_obj`, and `point`.
The integrated nine-module audit found all 340 matching validation targets exact.
It reports four boundary problems in nonmatching targets.

`00533EC0`, `00443CB0`, `00444040`, and `00436A10` now match their original bodies.
The isolated exact result for `0040B980` uses unrecorded locals and comma expressions.
That candidate remains in its experiment record; the integrated source keeps the clearer prior form.

The original `004490E0` stores an allocated command-list pointer before its repeated count guard.
The source now does the same. Its remaining compare/store order differs, so its status is `scratch`.

The following additional targets now have `scratch` status:

| Target | Open issue |
| --- | --- |
| `00533AF0`, `00533E10` | Emitted code exceeds the original boundaries. |
| `004BDEA0` | A local removes the old boundary escape, but broad drift remains. |
| `004BEB10` | Broad drift and a control-flow edge lack complete behavior proof. |
| `0047AB20` | Emitted code still exceeds the original boundary. |
| `0047E530` | Original field reads and rebuilt field reads can fault in a different order. |
| `0047E5D0` | The x87 order differs and emitted code exceeds the original boundary. |
| `00438060` | The y-field read order differs for invalid objects. |

The `0047E5D0` and `00473930` source probes were not integrated.
Their function notes separate the isolated probes from the integrated source.

The next packages cover `aiuaimod`, `dlg_smsg`, `m_co_obj`, `map`,
`taiinfmd`, `taitacmd`, and `act_atak`.
The original `00450450` reuses parameter and saved-pointer words as scan outputs.
Its typed source now preserves those values when `fscanf` stops early.
The rebuilt function still crosses its original boundary, so it has `scratch` status.
The worker proposed deferring integration; root retained the proved fallback repair.
The boundary and runtime fault cases remain open.

`004FB2D0` and `004FB550` now match through natural local declarations.
`004E0FD0` matches in the module context after two natural lot-loop changes.
These three exact promotions require fresh integrated-owner checks.
The `00457C50` comparison now spells `>=` directly.
This source expresses the original unordered x87 branch and emits unchanged bytes locally.

The following additional targets have `scratch` status:

| Target | Open issue |
| --- | --- |
| `00414D40` | A reversed early register save has a proved stack-fault counterexample. |
| `004407A0` | Broad drift and linked storage remain unproved. |
| `00458600` | A parser output conflicts with its PDB parameter home. |
| `00458C90` | The rebuild omits a repeated null check. |
| `004D6BB0`, `004DE600`, `004DEA80`, `004E2D10` | Emitted code crosses the original boundaries. |
| `004E0470` | The clearer loop still has broad, unapproved drift. |
| `004F57C0`, `00502310`, `00503070` | Emitted code crosses the original boundaries. |
| `00401170`, `004012B0` | Floating-point and linked-value checks remain open. |

The next packages cover `victory`, `tplayer`, `tvw_main`, `rmm_base`,
`color`, `airesitm`, `act_move`, and `dlg_dip`.
The first `00533240` review misread the original zero-points branch as a loop
edge. It exits the scan. The old source's early `break` was correct.
The review also misread VC5's unordered comparison result. The post-integration
correction restores the original source form. This function remains `scratch`.
`005326F0` and `00514590` have new exact source proposals.
The original `00480A20` leak and tail-match fault remain in the clearer source.

The `GetCommInfo` worker proved that function-static `Lin` has eight rows.
The old seven-row global did not preserve the return for input eight.
An isolated eight-row candidate kept the same two code-byte differences.
Removing its old header declaration caused five failed exact claims.
Keeping that unused declaration, but removing the old global definition,
passed the isolated 157-group exact-claim audit.
The integrated source now uses this form. The header declaration has no
object reference; its compiler-context effect remains unexplained.
At integration time, linked storage remained unknown.
`0042CD50` retains `scratch` status for the remaining checks.

The fresh linked build places function-static `Lin` at `00571268`.
Its `0x800` bytes end at the next named static, and the PE loader zeroes
the range. All eleven function relocations target that static and its rows.
The original PDB records the same owner and extent at `0062C6F0`.
No compiled object references the old global name.
Runtime behavior and the unused header declaration remain open.

`00531750` and `00518090` also have `scratch` status.
The first has broad unproved drift; the second crosses its original boundary.

The following packages add exact proposals for `004C86C0` and `00473FD0`.
The building queue source now uses the original `master_id` output slot,
32-bit counters, separate word copies, and the null old-queue check.
`004C9870` differs by one branch byte and still needs runtime review.
`004C9C80` has a different stack-save fault point and now has `scratch` status.
The original `00542750` body crosses its boundary by one rebuilt byte.
It now has `scratch` status even though its ordinary call paths align.
`00485480`, `00477AF0`, and `004786B0` also have `scratch` status:
their source reads memory in a different order from the original.
Those three results agree for stable, valid objects; fault order remains open.

The `Panel`, `Panel_ez`, `tworld`, and `sceninfo` packages propose exact
matches for `004642C0`, `004675C0`, `0052E920`, and `0048D0E0`.
The scenario source now owns a 256-byte filename and a separate four-byte
version local, as the PDB and original code show. It retains the original
missing `FindClose` behavior.
`005467B0` remains a broad constructor mismatch with unproved fault order.
`0050C730` has a proved output-alias difference for a crafted stack pointer.
`0050CE68` has a known linked zero in the wrong storage section.
Those three targets now have `scratch` status.

The `Command` review proposes an exact `00434FB0` after restoring the
original packet and object read order. The `scr_mps` review makes the
player-version loop simpler, but `004A2060` still has an unresolved
register-map conflict. That target now has `scratch` status.

`00431D30` had a proved saved-register alias defect.
The new source restores EDI after the output write, but crosses its
original boundary by two bytes. It now has `scratch` status.
The action reviews propose exact matches for `004CFFD0` and `004D2250`.

The `sprite`, `Pnl_txt`, and `act_list` reviews found no new source defect.
The sprite source removes one redundant output alias and uses a PDB-backed
`long` facet index. The changes emit the same reviewed target bytes.
The original `0047C640` has a text-wrap path that can fail to advance.
The source retains that behavior. The two-byte `00404590` drift is in an
unreachable block; no source or status change was required.

The `Sound` and `taibldmd` reviews propose exact matches for `004BC270`
and `004D5D40`. The sound source retains unsigned elapsed-time wrap.
The AI build-list loop preserves call order and advances after `continue`.
The `Sounddrv` review found no new defect at `004BCD30` and proposed no
source edit. Root keeps the separate formatting commit `9ce8ef635` intact.

The `t_c_obj` review found a narrow x87 operand-form difference at
`004CC4C0`. NaN payload behavior remains unproved, so this target now
has `scratch` status. The `taiconmd` and `tact_rep` source remains unchanged.

The `scr_ach` source now sums victory-point IDs 16 and 15 with one local.
The original prepares later call arguments before those getter calls.
The source does not preserve that stack-write order, so `0048E400`
now has `scratch` status pending a fault-order proof.

The `rmm_obj` review found that `004862B0` reorders a player-pointer read
and a zone-output stack push. The valid-object path agrees, but invalid
object fault order remains open. This target now has `scratch` status.

The `tact_mob` review found a proved AI history-text defect at `004D0FC0`.
The old source omitted `uniqueID=%d.` from three log formats, although it
passed that argument. The source now contains the original three formats.
The constructor `004D0EB0` reorders vptr and ID stores; partial-object
fault order remains open. Both targets now have `scratch` status.

The `scr_cred` review found that `00492FB0` sent the scroll-end action to
`curr_child`. The original sends it to `parent_panel`. The source now uses
the correct field and has an exact matching candidate.

The `vw_main` review kept the same two-byte timing-register drift and
rewrote the unsigned subtraction as two direct steps. The `tribegam`
review moved one retry-counter declaration to its first use.
Neither edit changed the reviewed target bytes in its isolated module.

The `Timeline` review retained the original second-lookup index bug.
It changed the allocation literal `48` to `sizeof(RGE_Time_Entry)`.
The target still differs by 16 code bytes, and linked vtable storage
remains unverified. This edit does not renew full behavior approval.

The `tact_bld` review retained the original farm carry-loss path.
Its two-byte drift changes the register for one virtual call.
The `vis_unit` review restored a bounded loop over all 17 `NormalLOS`
entries. The low address operands are COFF relocations to that table,
not null pointers. The loop still differs by ten bytes.

All 89 assigned module reviews have now finished.
The `taiuaimd` review found no new behavior defect at `00504750`.
Its clearer source emits the same bytes, but its rebuilt body exceeds the
original boundary by seven bytes. This target now has `scratch` status.

## First integrated validation (before the peer-scan correction)

All 89 workers finished their assigned module reviews.
Of the 228 original accepted-drift entries, 23 now have `matching` status,
63 have `scratch` status, and 142 retain `accepted_drift` status.
These status counts do not establish runtime behavior.

The final serial function audit compiled all 225 groups and 5,426 normal
functions. It reported 5,004 matching results with no failed exact claims.
It also reported 17 boundary problems in non-exact functions.
The owner audit found zero mismatches among the 5,004 matching results.
Reports are in `build/validation/accepted-drift-wave-final-20260929/functions/`
and `build/validation/accepted-drift-wave-final-20260929/owners.txt`.

The final linked build compiled 226 sources and one assembly source.
It linked without unresolved symbols. Its EXE hash is
`6fe3b80148542b0985f1fb362b5978aefb610d8bfe0c48a5bb9d3ec7d87c9eec`.
Its report is
`build/executable/user/20260928T230856214889Z-c379160be343/20260928T230856444341Z/report.json`.
The final image audit found 11,387 passes, no supported failures, and
48,168 unknown checks. Linked references had 7,515 passes and 5,350 unknowns.
Header emissions had 133 matches. The named initializer audit found 124
equal byte ranges, 59 unmapped names, and 107 entries needing further review.
These reports are under `build/validation/accepted-drift-wave-final-20260929/`.

The first full automated run found five tests with old hard-coded status
expectations. Commit `b89285971` updated those tests after the review.
The final run passed 1,000 tests, skipped two, and passed 31 subtests.
Both skips require optional preserved historical builds that are absent.
Its report is `build/validation/accepted-drift-wave-final-20260929/tests-final.xml`.
Replay fixture checks passed. Gameplay suite results must be recorded separately.

### Deterministic trace result

The final five-case fast trace suite failed two cases on the rebuilt EXE.
`save-check` and `chaos-ffa-run-1` stopped at updates 14,744 and 34,900.
`chaos-run-1-cut`, `random-map-opening`, and `saved-game-session-1` passed.
The first failure report is
`build/runtime/traces-20260928T231831418146Z-f683fcfdce7b/report.json`.
A serial `save-check` rerun failed at the same message record, 619,657.
Its report is `build/runtime/traces-20260928T232404708566Z-96e438581c8a/report.json`.
The original and rebuilt observer records agree through update 14,743.
The next recorded message expects a different update count in the rebuilt run.
The first linked run did not pass runtime validation.
An isolated replay of the earlier `c14e88d0` EXE completed all 59,944
`save-check` updates. Its RNG bytes match the original run, and both runs
consumed 1,776,762 messages. The intermediate `843c860d` EXE fails at the
same update and message record as the final `6fe3b801` EXE.
The isolated runs are under `../aoe1-drift-runtime-bisect/build/runtime/`:
`old-save-check-rebuilt-only/` and `intermediate-save-check-rebuilt-only/`.
This brackets a runtime change before the final `taiuaimd` integration.
Commit `63afd3ce2` passed an isolated `save-check` replay, and commit
`8a65f748f` failed it. Reverting only the `victory.cpp` changes in the latter
made the replay pass. Restoring only the old peer scan in `00533240` also
made it pass. The original zero-points store at `005332F6` is after the
loop's exit jump, not before an index update. The removed `break` caused a
score difference that the observer hash did not measure.

With a read-only peer-scan probe, the original gave one player 50 points per
update near update 14,735. The incorrect replacement gave two players 50.
The old source's ordinary equality test also compiles to the original
`test ah,40h`. Its replacement `!(*score < current)` compiles to
`test ah,01h` and changes unordered handling. The source now restores the
early `break` and ordinary `==`. The corrected build and replay results appear
below, separate from the first failed full suite.
The focused `main-credits` UI case passed against the final linked EXE.

The full UI run passed 40 cases and failed `saved-delete-confirmation` on
both original runs and the rebuilt run. The fixture expected exactly one save.
The shared asset set now contains five saves. The test now checks that the
list exists, then compares its controls and pixels between original and rebuilt.
The focused case passed after that fixture change. The first full report is
`build/runtime/ui-main-menu-20260928T233045151121Z-6cc2308cdcc8/report.json`.
The focused report is
`build/runtime/ui-main-menu-20260928T233938677516Z-8417ac1881d8/report.json`.

### Validation after the peer-scan correction

The corrected linked EXE hash is
`26981774a281d9b5430ae00c170937156cc430731fac811b4867f00023bd3df3`.
Its build report is
`build/executable/user/20260929T004702201733Z-776f2388dfbd/20260929T004702433284Z/report.json`.
The rebuilt game passed all five fast deterministic trace cases against the
original. The report is
`build/runtime/traces-20260929T004849722354Z-a6e0ce928056/report.json`.

The final whole-project audit compiled all 225 groups and found 5,004
matching results with no failed exact claims. The owner audit found zero
mismatches among those 5,004 functions. The 17 non-exact boundary problems
remain. Reports are in `build/validation/accepted-drift-peer-correction/`.
The corrected linked image had 11,387 supported dependency passes,
48,168 unknown checks, and no supported failure. Linked references had
7,515 passes and 5,350 unknowns. Header emissions had 133 matches.
The initializer audit found 124 equal byte ranges, 59 unmapped names,
and 107 entries needing type or startup review.
The full automated suite passed 1,000 tests and 31 subtests. It skipped two
tests that need absent optional historical builds. Its report is
`build/validation/accepted-drift-peer-correction/tests.xml`.
The final scripted gameplay parity stage passed on the corrected build.
Its report is
`build/runtime/parity-20260929T010105014803Z-452e7167e6ea/report.json`.
The corrected UI suite passed all 41 cases on original and rebuilt.
Its report is
`build/runtime/ui-main-menu-20260929T180609111360Z-991a019bd71d/report.json`.
