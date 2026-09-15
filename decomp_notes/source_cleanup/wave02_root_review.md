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
