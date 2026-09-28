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
They must preserve baseline and tested inputs through `docs/experiments.md`.
They must audit changed modules and the full closure of shared changes.
Workers cannot change registry statuses or commit proposals.

Integration requires source review, fresh exact checks, and affected-owner validation.
Do not renew a behavior approval while material checks remain unresolved.
Keep exactness, behavior findings, and integration decisions separate.

## Session records

The initial assignment manifest is `build/accepted-drift-wave/assignments.json`.
The first launch request is `build/accepted-drift-wave/batch-01.json`.
These are scheduling records, not durable technical evidence.
Workers must record technical findings and preserved experiments in `decomp_notes/`.

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
