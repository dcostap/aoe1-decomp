# Cleanup wave 02 root review

## Owner 11: final substitution review approved

Original reviewer `sa-187152fa` approved `f174e776fb3782c12ddfe2dd726ecade29845a7e` with no blockers.
The assigned final review covered `build/source-cleanup-20260915/owner11-resource-corrections.diff`, 1,525 lines, and changed reports.
It includes the approved resource substitutions and shared chat notification name.
The earlier full review and 824-line correction review remain in effect.
The merge required retention of newer root definitions in `include/resource_ids.h`.
Root read the complete conflict and retained those definitions without changes.
Git diff confirms that the resolved resource and chat headers equal their pre-merge main versions.
Root merged the group as `1be87cdcfdf1d85b53d9ad2a36cc92ac949a952a`.
This completes integration of all wave 02 groups.
Main contains 160 assigned modules plus the pilot: 161 of 225, approximately 71.6%.
Compiler and runtime validation remain deferred.

## Owner 11: approved correction and resource mappings

Reviewer `sa-187152fa` approved all 824 correction-diff lines at `616082391a771bacc7305fad75c21cc2e602a5f4`.
The correction retains supported `x2` and six `userN` names, but restores unproved coordinate and index names.
Root approved 74 new string macros and three separate `BINARY_RESOURCE_ID_` binary layout macros.
Four of the 78 requested string names already exist and are not duplicated.

All 78 string payloads exist in runtime `language.dll`, language `0x0409`.
Its SHA256 is `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
Both runtime and original expansion DLLs miss these IDs; no requested slot is empty.
The lookup retains expansion-first lookup and base fallback.
The pinned original tree lacks the base language file. These English payloads come from staged runtime evidence.
Extraction is under `build/source-cleanup-20260915/reviewer-owner11/`.

The binary layout IDs are `0xC389`, `0xC38A`, and `0xC38D`, under type `0x62696E61`.
They select end-win, end-other, and in-game layouts respectively.
Runtime base `data/Interfac.drs` supplies them; both checked expansion files lack them.
Its SHA256 is `8a7f1b1f9009d4bc0262c7890935d69d62668c80751ec3b861345064a0e63d33`.
The payload hashes, in ID order, are:

- `4ac46eae9163f876966ad385fe43a0097f0d4e96b95e3c96c500595999d0acae`
- `560cd53269166666a75e0836a3139fc6ed18679651ae6969978b21b5d1fd2798`
- `854d2e6e0dc6ed9fc677ff1902831909fbb5226f380452fa4940500c6ccf7cc0`

Workers must preserve all lookup calls, literal types, and the dropped/canceled two-ID arithmetic.
Integration waits for their resource substitutions and correction review. No validation ran.

## Owner 11: corrected delivery queued

Corrected head: `616082391a771bacc7305fad75c21cc2e602a5f4`.
Root saved the complete 824-line correction diff as `build/source-cleanup-20260915/owner11-corrections.diff`.
Delegated correction review waits for one of the three active reviewers to finish.
The 78 string requests and three binary resource requests still need decisions.
No shared resource definition changed in this delivery. Integration remains blocked on review and those decisions.

## Owner 10: approved and integrated

Root read all 340 lines of the final report-only correction diff.
Corrected group head: `3e55e79b436a36893905cfcf1a250c005f31ea41`.
The reports now separate root approval from worker imports and correct the panel-name and instruction citations.
No source or header changed in that correction.
Root merged the complete group as `1c2066ce9aafe171a9b0796ee92061e5d0e05a7f`.
This raises the integrated count to 88 assigned wave modules, plus the pilot.
Final generated-output and runtime validation remain deferred.

## Owner 10: correction review and report fixes

Root read the complete 1,582-line correction diff for `29613ee064d6e99cd4cea0ac2d53e5832ef1cb15`.
The imported resource header equals root commit `8c56055b7feee1526f296bd306036a4c34f38041`.
Source substitutions retain arithmetic, casts, calls, and extra formatting arguments.
Root checked the original instruction chains for `dlg_conf::val`, `dlg_dip::a`, and the four renamed `dlg_msg` locals.

Owner 10 resumed in run 3 for report corrections only:

- Separate worker header-import commits from the actual root approval commit.
- Identify `QuitAndLoadDialog` and related strings as panel names, not resource selectors.
  `src/Panel_ez.cpp` passes these strings to `TMessageDialog` construction.
- Correct the `dlg_msg::index` citation: `0043FEAD` compares; `0043FEAF` stores the updated index.

The group remains outside main until root reviews those corrections.
No compilation, builds, matching checks, audits, tests, or games ran.

## Latest review: Owners 08 and 11

Root read all 922 lines of Owner 08's correction diff and the changed reports.
Corrected head: `c619c6082658e8e8dd9f91d168f32a36aea8f4ea`.
The correction restores `count`, `move_sprite_id`, and `run_sprite_id` where PDB declaration mapping remains uncertain.
Other source corrections change signature formatting only.
Root merged the complete group as `84175ac4d5b4f22ac357cee6076ec55df0d7cca9`.
Main contains 80 assigned wave modules, plus the pilot. These changes remain unvalidated.

Root finished Owner 11's complete 3,768-line diff review.
Owner `sa-296217b8` resumed in run 2 with the same workers for corrections.
Root requested compact short handlers and supporting original-instruction evidence for these local names:

- `scr_cred::draw_scrolled_line`: `x2` and `x`.
- `scr_mps::handle_user_command`: the renamed `userN` declarations.
- `scr_mps::calcRandomPositions`: `pos`.
- `scr_mps::setupSinglePlayerPlayers`: `first_any_player`.

Unproved mappings must retain baseline names, types, scopes, and storage.
Root has not approved Owner 11's 78 string requests or three binary resource requests.
No compilation, builds, matching checks, audits, tests, or games ran.

## Owner 09: returned for corrections

- Delivered head: `619a4b8099a99d03b686c3f140a88d76e10d1cfb`.
- Common base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Root read the complete 3,263-line group diff, including all nine reports.
- Review artifact: `build/source-cleanup-20260915/owner09-review.diff`.

The source changes are name substitutions and formatting. Root found no removed cast or changed executable expression.
However, the missile collision-list `max_y` to `x2` mapping needs stronger declaration evidence.

The original packet `inventory/functions/0045/0045AB20_make_object_collision_list.txt` shows:

- Upper-x conversion result stored at the home labeled `x1`, instruction `0045ABB0`.
- Upper-y conversion result moved into ESI at `0045ABBC`.
- The home labeled `x2` receives the collision-list pointer at `0045ABE7` or `0045ABEF`.

Conversion order does not prove that the upper-y source declaration was `x2`.
Root requested baseline `max_y` unless the same worker supplies reliable declaration evidence.
The report must separate the supported `x1` mapping from the uncertain `x2` mapping.
No type, storage, scope, or expression repair is authorized.

Root also requested shorter presentation for newly wrapped short header declarations.
Examples include `mst_play::finish_init`, `dpl_obj::add_doppleganger_check`, and the two-parameter `tm_tre_o` copy constructor.
The ledger must clearly label invented `dpl_obj` local names, separate from recovered PDB names.

Owner `sa-fe7f217c` resumed in run 2. No part of this group is merged into main yet.
Root preserved all earlier commits and worktrees. No compilation, builds, matching, audits, tests, or games ran.

## Owner 09: corrections approved and integrated

Corrected head: `7c558c4bafe4b99f706efb6d1eead4a3a982511c`.
Root read the complete 398-line correction diff and the changed reports.
The source restores `max_y` and retains the supported `x1` mapping without changing expressions or storage.
The reports now distinguish the uncertain pointer-home evidence and invented descriptive names.
Header corrections change presentation only.

Root merged the complete group without conflicts as `2b9e1412f991eab6819abdc3ab0cac3732f33921`.
This includes eight sources, eight headers, eight module reports, and the owner ledger.
All histories remain preserved. The 32 integrated wave modules remain reviewed and unvalidated.

## Owner 05: returned for corrections

Delivered head: `75fb726c37e61a81933e7ba658a1215295a0fbce`.
Root read the full 2,910-line group diff and all nine reports.
Root found no removed cast or changed executable expression, but identified two uncertain local-name mappings.

- `tact_dar::check_objects` renames the loop variable `x` to `x1`.
  Packet `004CE7A0` stores the first horizontal bound in the `x1` home at `004CE7CD`.
  It clips that bound at `004CE804` and `004CE816`, then reloads it at `004CE86A`.
  Root requested restoration of loop `x` and evidence-based treatment of the lower-bound declaration instead.
- `tact_art::check_ownership` renames `map_x` to `x1` without reliable home mapping.
  Packet `004CCF30` warns that `x1` should be unmapped and gives that home no cross-references.
  Root requested baseline `map_x` unless the worker supplies reliable declaration evidence.
- The `tact_cnv` report cites nonexistent `src/act_lst.cpp` callers.
  The cited `convert` and `die_die_die` procedures belong to `src/t_c_obj.cpp`.
  Root requested actual source paths and call-site evidence.
- Short touched definitions still have unnecessary wrapping, notably conversion work, repair work/movement, and the make-object constructor.

Owner `sa-fb0803db` resumed in run 2 and must use the same source workers for corrections.
No source, type, scope, or behavior repair is authorized. No part of this group is integrated yet.

## Pending delivered groups

Root prepared full diff artifacts for these deliveries but has not yet read their complete diffs or reports:

- Owner 04: `32538789aa6fb57dfb041749f878c122b15a674d`; `build/source-cleanup-20260915/owner04-review.diff`, 3,717 lines.
- Owner 12: `54713c0810fcde59c9aeb665ddcf45685f62f1a1`; `build/source-cleanup-20260915/owner12-review.diff`, 3,379 lines.

No compilation, builds, matching, audits, tests, or games ran during these intakes.

## Further deliveries awaiting root approval

- Owner 08 delivered `124d05ecb3fdcafed676fda16ac3124f415fcac0`.
  Root preserved its complete diff in `build/source-cleanup-20260915/owner08-review.diff`; review remains pending.
- Owner 11 delivered `ad4e8c9b917e77b44b12c04fe87b46e762421355`.
  Root preserved its complete diff in `build/source-cleanup-20260915/owner11-review.diff`; review remains pending.
  The owner reports 78 string-ID requests and three unresolved binary `RESFILE` IDs.
  These requests still need root evidence review.
- Owner 05 delivered corrected head `0738989967a422b57bba6a02c34d88bd904095c8`.
  Root read the complete correction diff in `build/source-cleanup-20260915/owner05-corrections.diff`.
  It restores artifact `map_x`, restores discovery loop `x`, and maps the supported discovery bound to `x1`.
  It also corrects caller paths, short signatures, constructor indentation, and reports.
  Integration remains pending. No new validation ran.

## Owner 05: integrated after correction review

Root merged the complete corrected group as `5b2ff32c1a885c07b9ea5da111422630fd1dda13` without conflicts.
The initial full review and complete correction review cover all delivered source, headers, and reports.
Main now contains 40 assigned wave modules, plus the earlier pilot. All remain unvalidated.

## Owner 04: full review complete; corrections requested

Root read the complete 3,717-line diff and all nine reports.
No removed cast or changed executable expression was found.
Root confirmed the two `act_move` y-coordinate stores at `00405A5F` and `00405B17` in packet `00405850`.
The `yDiff` mappings can remain.

Root requested compact signatures and correct continuation indentation in source and headers.
Root also requested a narrower `task_lst` comment: the code rejects non-positive amounts, not every non-positive-or-unordered value.
The existing comparison must remain unchanged. Owner 04 resumed with the same workers for these corrections.
No compiler, build, matching, audit, test, or game command ran.

## Owner 06: full review complete; corrections requested

Root read the complete 3,674-line diff and all nine reports.
No removed cast or changed executable expression was found.
Several new `aiconmod` local names need stronger declaration evidence in constructor `0040ABB0`.
For example, the first loop passes `inProgressValue.i` to `setGameID` and `skipValue.i` to `setUniqueID`.
The second loop uses several newly named state locals as floating-point sizes.
Reused PDB homes alone do not prove these source declarations.
Root requested per-loop evidence or baseline names, without type, storage, or behavior changes.

Root also requested normal loop spacing, constructor continuation indentation, and separate lines for existing `aibldmod::save` statements.
Owner 06 resumed with the same workers. Integration and validation remain pending.

## Owner 07: reviewed and integrated

Root completed the 3,097-line group review, including the reports and headers.
Root checked the disputed AI mappings against scoped PDB records and original instruction packets.
Root merged `bedc8b4cd3fd6b0a83201c444acf753b4642d1c0` as `ce978edb0b49c34a91482d2eaaa0af048a8906ce`.
The help-window constant request remains separate and pending.
Resource extraction found `Age of Empires Help` at base ID `0x03EB`; the expansion ID was absent.

## Owner 06: corrections reviewed and integrated

Corrected head: `e3443a53a3e80099011e1df13488033417f07012`.
Root read the complete 579-line correction diff, including all changed reports.
The corrections restore unsupported constructor names and change presentation without changing expressions or declaration order.
Root merged the complete group as `76e162f525f5dbb4346c5a5a71516475beb2a300`.
Main now contains 56 assigned wave modules, plus the earlier pilot. All remain unvalidated.

## Owner 08: full review complete; corrections requested

Root read the complete 4,907-line group diff, including reports and headers.
The `00451000` change from `count` to `tot_armor` lacks declaration evidence.
The PDB lists `tot_armor` at `+0x8`; the weapon countdown uses instructions `0045100D`, `0045102B`, and `0045108A`.
Root requested baseline `count` unless stronger evidence proves this mapping.
Root also requested original-save evidence for reversed moving-sprite names and corrected signature presentation.
Owner 08 resumed with the same workers. No part of this group is integrated.

## Owner 04: correction review

Root read all 272 lines of the correction diff for `89e6677deb4cbe1eb59d88de3e811c2912f8be96`.
The comment and compact signatures preserve executable expressions.
Root initially miscounted the task signature columns and withdrew that finding after direct text inspection.
Both continuations correctly align at zero-based columns 41 and 43. Integration remains pending.

No compiler, build, matching, audit, test, or game command ran during these reviews or integrations.

## Owner 04: integrated

Owner 04 confirmed that the withdrawn request caused no edits or commits.
Root merged `89e6677deb4cbe1eb59d88de3e811c2912f8be96` as `b0df1cbb4dd9997f91b90ff0a9bd685892676294`.
Main now contains 64 assigned wave modules, plus the earlier pilot. All remain unvalidated.

## Owner 12: full review complete

Root read the complete 3,379-line diff, including all reports and headers.
Root confirmed `FlushTurnRange` counter names against scoped PDB offsets and instructions `00431A8B`, `00431A8F`, and `00431B01`.
Root found no changed executable expression, cast, type, or storage by source review.
Owner 12 resumed for one whitespace correction: join the existing closing brace and `else` in `com_q::AllocateQueue`.
No new scope or behavior change is authorized.

## Owner 10: full review and resource decisions

Root read the complete 3,651-line group diff, including all reports and headers.
The initial source changes preserve executable expressions, casts, types, and declaration order by review.
Some short signatures still need compact formatting. The reused-home explanations need precise instruction evidence.
Integration remains pending.

Root reviewed all 81 requested resource mappings and independently extracted both runtime DLLs.
Artifacts: `build/source-cleanup-20260915/root-owner10-base.json` and `root-owner10-expansion.json`.
Root also inspected each source resource use in owner 10's delivered tree at `b419f9e35a1621df0ceda896465642291c4d0cf1`.

The base file SHA256 is `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The expansion file SHA256 is `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
All extracted entries use language `0x0409` and type `RT_STRING`.
The module reports retain exact payloads, purpose, and pinned-original expansion evidence.

Root added 79 proposed definitions to `include/resource_ids.h`.
The complete path-finding range contains `Default`, `Medium`, and `High` at `0x260E` through `0x2610`.
Only the range base needs a macro. The two unused interior-ID proposals remain undeclared.
Workers must preserve `STRING_ID_PATH_FINDING_OPTION_BASE + i`, not create a table or switch.

Expansion text overrides the version, About warning, and neutral diplomacy help at `0x241A`, `0x241F`, and `0x7685`.
Its other returned slots are empty; the remaining requested IDs have missing blocks.
The unchanged game lookup uses the base fallback for both empty and missing expansion entries.
These findings do not prove why any slot is empty.

Menu confirmation IDs describe message text, not window titles. Their proposed `STRING_ID_CONFIRM_*` names remain suitable.
Keep the extra player-name argument in the game-speed notification, although the current text has no format placeholder.
Keep distinct IDs for equal captions, all original casts, all buffer sizes, and all lookup calls.
These are new cleanup names, not recovered original macros.

The `STRING_ID_HELP_WINDOW_TITLE` purpose is supported by `basegame.cpp` passing the loaded string to `FindWindowA("MS_WINHELP", str)`.
That unassigned module remains unchanged. Defer its definition and substitution until its own cleanup.

## Wave 03 delivery awaiting review

Owner 18 delivered `3ba4a0385a2999f516bde496c45d3c93dae55806`.
Root saved its complete 3,093-line diff as `build/source-cleanup-20260915/owner18-review.diff`.
Root review remains pending. No validation ran.

## Owner 12: integrated after correction review

Root read the complete correction diff for `6a338e77223b49f7f9b9295bf0b58dadce8086d9`.
Only two existing `else` clauses changed line placement; the report and ledger record that correction.
Root merged the group as `784095d9739266e5e892e374dd129a22b1968d6e`.
Main now contains 72 assigned wave modules, plus the earlier pilot. All remain unvalidated.

Owner 10 resumed with its original workers for resource substitutions, precise reused-home evidence, and focused presentation corrections.
Its shared resource commit is `8c56055b7feee1526f296bd306036a4c34f38041`.

Owner 19 delivered `fea021a8b9836eb0fc357a5a210041828162a328`.
Root saved its complete 3,182-line diff as `build/source-cleanup-20260915/owner19-review.diff`.
Root review remains pending. Its resource requests include competing names for `0x2C24`; no new definition is approved yet.
