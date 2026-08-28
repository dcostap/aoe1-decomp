# dlg_dip.cpp source reunification

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\dlg_dip.cpp`.
The eight normal owners span lines 77 through 903 and keep this address order:

`0043C930`, `0043D6E0`, `0043D8A0`, `0043E530`, `0043E5C0`, `0043E650`,
`0043E6E0`, `0043E770`.

All eight owners belong to `TribeDiplomacyDialog`. The scalar deleting
destructor at `0043D6C0` is compiler generated and has no source-line owner.

The two exact resource checks are the registered anchors. The constructor,
destructor, action, and draw packets provide the source-line bands, direct
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
Shape members use ordinary `delete`, and shared constants use their proven
literal values.

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

The old exact claims are not fresh exact claims after migration. Only
`0043E530` and `0043E5C0` remain registered exact owners. `0043D6E0`,
`0043E650`, and `0043E6E0` are scratch.

The final provider cleanup check compares every normal owner and the generated
destructor. The two registered checks match. The generated destructor at
`0043D6C0` also matches its 30-byte body. The constructor differs by 3,023
bytes, the action by 2,856 bytes, the draw by 166 bytes, and the natural
destructor by 19 bytes.

The constructor calls `get_font(1)` as a separate statement. The PDB assembly
shows that it discards the return value before the text creation call. The
text call then uses font ID 1. The five tribute constants use the proven
values 100.0f, 0.0f, 0.0, -1.0f, and -100.0f.

## Evidence blocker

The natural module has no full exact context. The constrained candidate result
shows direct symbol ownership for all eight normal owners, but it also shows
boundary escapes for three old exact bodies and relocation mismatches in the
constructor and action. The latest provider cleanup check confirms the
generated deleting destructor separately. Fresh exact repair must use the
existing module response file and inspect all eight normal owners plus that
generated destructor.
