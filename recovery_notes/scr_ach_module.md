# scr_ach.cpp source reunification

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_ach.cpp`.
The eight normal owners span lines 110 through 936 and keep this address order:

`0048D530`, `0048E210`, `0048E400`, `0048F0B0`, `0048F190`, `0048F280`,
`0048F500`, `0048F530`.

All owners are `TribeAchievementsScreen` members. The vector-deleting
destructor at `0048E1F0` is compiler generated and has no ordinary source
owner.

The constructor and mode setup own the long setup and statistics paths. The
remaining owners are the destructor, draw, input, action, idle, and window
handlers. The PDB line bands, address sequence, base-constructor anchor, and
ordered panel, player, victory-condition, and game calls establish this
translation-unit context.

`0048D530` ends at `0048E1D2`; the generated vector-deleting destructor at
`0048E1F0` is outside handwritten ownership. `0048F530` ends at `0048F5C1`;
padding follows to the next compiland owner.

## Source ownership

`src/scr_ach.cpp` contains all eight handwritten owners in PDB order. The
module uses `include/scr_ach.h` for its declarations and has no wrapper,
function-fragment include, context macro, or fallback declaration block.

The constructor and `set_mode` retain the reviewed typed panel, player, world,
and victory-condition surfaces. They also retain the shipped partial `memset`
tails and ordered mode-3 victory-ID calls. These facts preserve observed local
state and fault order.

The constructor uses the period `set_positioning` and `set_tab_order` virtual
surfaces. The call arguments and slots are proved by the original calls at
`0048DA18`, `0048E17E`, and `0048E18C`. The previous `vf_*` declarations were
codegen-only residue and are removed.

The accepted-drift owner `0048E400` remains observed. The scratch constructor
`0048D530` remains unresolved. The other six owners remain registered matching
owners.

## Function notes

The constructor uses 260-byte `info_file` storage. A 256-byte probe matched
the frame but lacks packet support. The natural 50-byte `temptxt` and its
15-byte tail clear are retained. The player loop keeps its observed decremented
index comparison with eight. The source has the explicit mode-selection branch
and the panel surface proved by the translation-unit packet.

The constructor remains scratch at the current 2877-byte difference and two
boundary escapes. A rejected 48-byte local variant matched the frame but used
compiler steering. An uninitialized temporary was also rejected because VC5
removed it and changed the frame. The next useful evidence is a fresh exact
constructor context check after the module move.

`set_mode` retains the accepted typed-index reconstruction. The five setup
hunks differ only by initial index-store placement, and the accepted audit
found no call, memory, or control-flow difference. A raw two-byte player
cursor can recover the five setup blocks but reverses the mode-3 victory-ID
calls at `0048ED20` and `0048ED2A`; that form is rejected because it changes
fault order. The natural source keeps explicit sequencing.

## Validation and regressions

The pre-migration wrapper was `src/scr_ach_tu.cpp`. It included one source
fragment for each owner and selected `include/scr_ach_context.h` with a context
macro. The migrated source uses one direct compiler-facing owner and the
module-local header.

The constrained grouped audit was run once as
`python tools/audit_translation_unit_observed.py --group scr_ach --jobs 1
--output-dir build/audits/scr_ach_final --print-full`. It compiled all eight
owners and found six registered exact owners with zero positional differences,
zero relocation mismatches, and zero boundary escapes. The scratch constructor
was observed at 2877 differing bytes with two boundary escapes. The accepted
drift owner was first listed as registered by the temporary config and was then
removed from the exact-owner list. The final config registers only the six
matching owners.

The three cached standalone checks attempted for `0048E210`, `0048F0B0`, and
`0048F280` rejected stale artifacts after the final source/config cleanup.
They did not rebuild because the assignment permits cached checks only. The
module test passes with two tests.

The constructor natural-name cleanup and protected `set_mode` declaration occur
only in the unregistered observed owners or their local target identity. No
registered owner was changed after the grouped exact results, but a fresh
standalone cache is still required for final confirmation.

## Evidence blocker

The candidate-TU validator expects exact owners in `src/matching` and one
wrapper include for each owner. It cannot validate this direct module source
until it supports registered source-module owners. Use the focused grouped
check as the constrained validation for this migration.
