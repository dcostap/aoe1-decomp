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
