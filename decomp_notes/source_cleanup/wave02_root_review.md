# Cleanup wave 02 root review

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
The task signature continuation columns still need correction. Integration remains pending.

No compiler, build, matching, audit, test, or game command ran during these reviews or integrations.
