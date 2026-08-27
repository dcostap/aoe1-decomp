# dlg_dip.cpp source reunification

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\dlg_dip.cpp`.
The eight normal owners span lines 77 through 903 and keep this address order:

`0043C930`, `0043D6E0`, `0043D8A0`, `0043E530`, `0043E5C0`, `0043E650`,
`0043E6E0`, `0043E770`.

All eight owners belong to `TribeDiplomacyDialog`. The scalar deleting
destructor at `0043D6C0` is compiler generated and has no source-line owner.

The exact destructor and four resource checks are the registered anchors. The
constructor, action, and draw packets provide the source-line bands, direct
call targets, field offsets, and the sibling address sequence.

## Migration

`src/dlg_dip.cpp` now contains all eight normal function bodies in PDB order.
`include/dlg_dip.h` is the module-local declaration header. The old wrapper and
per-function source-bank files were removed. The source has no `.cpp` owner
includes, context macro, placeholder virtual surface, inline assembly, raw
vtable field, or standalone fallback declaration block.

The source uses named dialog arrays and typed player, world, button, shape, and
resource fields. It replaces compiler-steering cursor arithmetic with direct
array indexing. It also uses one ordinary temporary buffer for formatted text.
The explicit `TShape` destruction and `operator_delete` calls remain because
this is the established period ownership form used by the neighboring panel
sources.

Before migration, the constructor's best clean checkpoint was 3,474 rebuilt
bytes against 3,457 original bytes, with 112 of 112 calls and a 0x128 frame.
The action checkpoint was 3,115 rebuilt bytes against 3,201 original bytes,
with 124 of 124 calls, a 0x108 frame, and 2,868 differing bytes. The destructor
and four resource checks were standalone exact matches. The draw body had 193
of 195 positional bytes and one accepted compare instruction difference.

These metrics describe the old per-function sources. They are not claims about
the migrated source.

## Validation

The constrained candidate validation was started with:

`python tools/validate_candidate_tu.py --proposal build/dlg_dip_candidate.json --output-dir build/candidate_tus/dlg_dip_natural`

The first compile stopped before comparison at `src/dlg_dip.cpp(388)` with VC5
error C2374. The destructor declared `i` in two same-scope `for` statements.
The source then declared that loop variable once and completed the constrained
candidate comparison. The candidate compiled all eight owners. Two of five
previous exact owners remained exact: `0043E530` and `0043E5C0`. The other three
previous exact owners differed: `0043D6E0` differed by 104 bytes and escaped its
boundary twice, `0043E650` differed by 146 bytes and escaped once, and
`0043E6E0` differed by 147 bytes and escaped once. All three observed owners
remained nonexact. The constructor differed by 3,025 bytes with two relocation
target mismatches. The action differed by 2,953 bytes with two relocation target
mismatches. The draw differed by 165 bytes. The check report is in
`build/candidate_tus/dlg_dip_natural/report.json`.

The old exact claims are therefore not fresh exact claims after migration. The
module keeps their reviewed statuses for later exact repair.

## Evidence blocker

The natural module has no full exact context. The constrained candidate result
shows direct symbol ownership for all eight normal owners, but it also shows
boundary escapes for three old exact bodies and relocation mismatches in the
constructor and action. It does not compare the generated deleting destructor.
Fresh exact repair must use the existing module response file and inspect all
eight normal owners plus the generated deleting destructor.
