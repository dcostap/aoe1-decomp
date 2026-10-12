# `taimdmd.cpp` cleanup report

## Delivery

- Module: `src/taimdmd.cpp`
- Read-only header: `include/taimdmd.h`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `57cacf09c454b32016bc1dee399ab42d811b3c66`
- Changed files in the source commit: `src/taimdmd.cpp`
- Complete delivery files: `src/taimdmd.cpp` and
  `workflow/decomp_notes/source_cleanup/wave03/taimdmd.md`
- The report is a follow-up change in this worktree. The source commit is the
  final module candidate commit.

The work changed only the assigned source and this assigned report. It did not
change `include/taimdmd.h` or another header.

## Original-name recovery coverage

The registry selects 19 normal functions in `config/functions/src/taimdmd.cpp.json`.
I inspected every selected procedure record in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json` and
its packet under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/`.
The packet names, VAs, and source order agree with the registry.

| VA | Function | Recovered names or coverage |
| --- | --- | --- |
| `004E4800` | constructor | `pW`, `playerID`, `playerName`, `aiP`, `buildListName`, `cityPlanName`, `ruleSetName` |
| `004E4B80` | load constructor | `playerID`, `playerName`, `aiP`, `infile` |
| `004E4EC0` | destructor | No parameters or locals in the procedure record. |
| `004E4FA0` | `setLogHistory` | `v` |
| `004E5050` | `update` | `timeLimit`, `tempString`, `i`, `world`, `numberComputerPlayers`, `numberHumanPlayers`, `numberNeutralCPs`, `neutralList`, `numberSwayable`, `swayableCPs`, `resAmount`, `temp2`, and `newEnemy` are supported by the scoped record and source use. The final neutral-player loop keeps the baseline `neutralPlayer` and `target` names for VC5 scope compatibility. |
| `004E5DB0` | `save` | `outfile` |
| `004E5F30` | `kick` | `m` |
| `004E5FA0` | `addObject` | `bo` |
| `004E5FE0` | `removeObject` | `id` |
| `004E6020` | `objectGroupThatCanPerformAction` | `a` |
| `004E6090` | `canPerformAction` | `id`, `a` |
| `004E60D0` | `detask` | `uID` |
| `004E60F0` | `isMoveable` | `o` |
| `004E6160` | `updateBuildAIWithObjects` | No local records. Existing `i` and `object` remain concise inferred names. |
| `004E6250` | `tributeNotify` | `playerID`, `resourceID`, `amount`, `tempString`, and `newAlly` |
| `004E6490` | `revokeTributeAlliance` | `tempString`; no parameter records |
| `004E6580` | `setTributeChat` | No parameter or local records |
| `004E6600` | `processAICommand` | `caller`, `mType`, `p1`, `p2`, and `p3` |
| `004E6870` | `currentScore` | `playerID` |

The compiler-generated scalar deleting destructor at `004E4B60` is outside the
normal source owner. Its `__flags` record was inspected and it was not edited.

### Unresolved mappings

The `update` record lists `iFood`, `iGold`, `iStone`, and `iWood` at the
same stack offset. The current source has one `int value` declaration reused
for those four reads. I did not split the declaration or force four names onto
one stack slot. This preserves the current declaration and evaluation order.
The four names remain unresolved in the source. The record also has no local
records for the inferred `tactical`, `tribute_elapsed`, `expiration_timeout`,
`selection`, and `other` names. I did not claim those names as originals.

The `updateBuildAIWithObjects` record has no local records. Its existing `i`
and `object` names remain unclaimed inferred names.

The `tributeNotify`, `revokeTributeAlliance`, and `setTributeChat` records do
not name the inferred `tactical` local. The `processAICommand` record does not
name the inferred `current` local. Those names remain unclaimed.

## Evidence

Primary evidence was the original procedure-scoped PDB data and packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E4800_TribeMainDecisionAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E4B80_TribeMainDecisionAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E5050_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E5DB0_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6250_tributeNotify.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6600_processAICommand.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004E/004E6870_currentScore.txt`

I also checked the prior natural-source evidence at commit
`cfae1d2b07c324b9deb0fabf081b0e7d60e3d612`, which uses the PDB-supported
`timeLimit`, `numberComputerPlayers`, `numberHumanPlayers`,
`numberNeutralCPs`, `numberSwayable`, `resAmount`, and `temp2` spellings.
The current source keeps the reviewed current control flow and does not copy
that commit's rejected structural changes.

Formatting now uses 1TBS function definitions and `} else {` blocks. The
incomplete comment before `setTributeChat` was removed. No new comment was
needed.

## Constants and resource IDs

No numeric constant was replaced. No resource macro was added. The source
keeps the original string lookups, buffer size `0x100`, lookup order, and
fallback behavior.

The inspected runtime lookup is `rge_base_game->get_string(id, tempString,
0x100)` in `taimdmd.cpp`. The actual virtual path is
`TRIBE_Game::get_string` in `src/tribegam.cpp`, which tries `StringTableX`
from `languagex.dll` and then calls the base lookup in `src/basegame.cpp`,
which reads `language.dll`. The checked files were:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

All runtime `languagex.dll` and original XPack `languagex.dll` lookups below
are missing in RT_STRING resources. The staged runtime `language.dll` has
English language `0x0409` text for every ID.

| ID | Staged runtime `language.dll` text, language `0x0409` | `languagex.dll` status in both checked files | Lookup path and purpose |
| --- | --- | --- | --- |
| `0x08FD` | `You traitorous wretch! Vengeance will be mine!` | Missing | `revokeTributeAlliance`, `taimdmd.cpp:697`; alliance revoked |
| `0x08FE` | `It was wise to do as I requested.` | Missing | `update`, `taimdmd.cpp:325`; tribute accepted |
| `0x08FF` | `You have made a wise choice -- together we shall rule the world.` | Missing | `update`, `taimdmd.cpp:316`; tribute alliance accepted |
| `0x0900` | `Alas! We could have made an unstoppable team.` | Missing | `update`, `taimdmd.cpp:298`; alliance request expired |
| `0x0901` | `You dare defy me?! Prepare to die!` | Missing | `update`, `taimdmd.cpp:290`; tribute request refused |
| `0x0902` | `Tribute %d more gold to me or you will be destroyed!` | Missing | `update`, `taimdmd.cpp:255`; enemy demand with prior tribute |
| `0x0903` | `Tribute %d gold to me or you will be destroyed!` | Missing | `update`, `taimdmd.cpp:260`; enemy demand without prior tribute |
| `0x0904` | `If you tribute me %d gold, I will ally with you.` | Missing | `update`, `taimdmd.cpp:267`; alliance demand with prior tribute |
| `0x0905` | `If you tribute me %d more gold, I will ally with you.` | Missing | `update`, `taimdmd.cpp:272`; alliance demand without prior tribute |
| `0x0906` | `Your petty offerings will not sway my determination to crush your empire!` | Missing | `tributeNotify`, `taimdmd.cpp:680`; enemy tribute response |
| `0x0907` | `Your empire is worthy of my allegiance.` | Missing | `tributeNotify`, `taimdmd.cpp:662`; neutral alliance response |

The resource extraction outputs are under this worker's ignored
`build/resource-strings/` directory. The source did not add names because
`0x08FD` through `0x0907` also occur in
`src/drawarea.cpp::TDrawSystem::GetCreateErrorNum` as DirectDraw error
numbers. These roles do not prove one shared macro namespace. No shared
resource declaration request is submitted. Root should use a domain-qualified
mapping only after it reviews the collision.

## Recovered versus invented names

Recovered original spellings are the names in the coverage table. This keeps
mixed styles such as `pW`, `aiP`, `uID`, `mType`, `numberNeutralCPs`, and
`resAmount` instead of normalizing them.

The cleanup names `tribute_elapsed`, `expiration_timeout`, and `random_value`
are descriptive names assigned where no original local record established a
name. The source also retains short inferred names such as `tactical`,
`selection`, `other`, `object`, `current`, and `tribute`; these are not
claimed as recovered PDB names.

## Correction history

Full diff review found that the recovered `timeLimit` parameter name did not
authorize reuse of that parameter as storage. The local declaration is now
`diplomacy_start_time` again. Its declaration and storage remain distinct from
the unused `timeLimit` parameter.

Post-cleanup compilation then found VC5 error C2374 near `taimdmd.cpp:440`.
The final loop's `i` declaration collided with an earlier for-initializer.
The repair restores the baseline `neutralPlayer` and `target` names without
adding a scope or changing declarations, types, storage, or statement order.
The finding is recorded in
`C:/Projects/my_decomps/aoe1_attempt3/build/executable/user/20260915T215425319815Z/20260915T215425568371Z/report.json`.

## Code-generation and ownership risks

Parameter and local identifier changes do not change types, layout, storage,
call targets, literals, casts, or ABI symbols. The source keeps explicit
`this->` uses and source order. The update keeps the `timeLimit` parameter
distinct from the `diplomacy_start_time` local. The local declaration and
storage remain unchanged by this correction.
The brace and comment changes can affect debug line records. No assembly,
helper, wrapper, layout, macro-context fragment, or behavior repair was added.

No shared-file request blocks this source. The owner header remains unchanged.

## Validation status

I ran `git diff --check` and reviewed the complete source diff. I ran the
resource extraction tool after reading its `--help`. I did not run a
compiler, build, matching check, audit, test, or game. Compilation, matching,
audits, and tests were not run.
