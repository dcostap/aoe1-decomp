# Linked image comparison

Run the tool help before use:

```text
python tools/diff_linked_image.py --help
```

Supply a successful build directory and a new output directory under `build/`.
For example:

```text
python tools/diff_linked_image.py --build build/executable/RUN --output build/linked-image-diff/RUN
```

The tool checks the recorded EXE, map, and object hashes, the source inputs, and the current registry.
Rebuild after a source change before running it.
It checks the original EXE against the pinned hash.

Use `--structural-only` for a historical build with a different registry.
This mode checks the EXE hash but makes no symbol or storage claims.

## Reports

- `summary.json` records input hashes, byte counts, results, and limits.
- `structure.json` records PE fields, sections, directories, imports, exports, and resource payload hashes.
- `ranges.csv` partitions the complete file lengths into equal, different, and unmatched ranges.
- `functions.csv` compares original-size windows at independently paired function symbols.
- `data.csv` compares reviewed storage bytes and explicit pointer fields through the existing storage audit.
- `unknown_ranges.csv` lists changed positional ranges without semantic attribution.
- `linked_checks.csv` lists relocated fields of exact functions that have an independent expectation.
- `linked_pairs.csv` lists every rebuilt target paired with original addresses.
- `linked_items.csv` compares the contents of paired data items.
- `report.md` gives the short result and limits.

## Linked pairing

Function matching masks relocated fields, so it cannot see the strings, constants, and tables that a matching
function addresses. Linked pairing checks them.

It starts from each `matching` registry function. The function's section in the object that the map names as its
owner must equal the linked bytes and the original bytes everywhere except relocated fields. Each relocated field
then gives one pair: the rebuilt target is the linked value minus the object addend, and the original target is the
original value at the same offset minus the same addend. The relocation names the target symbol, so no pair is
inferred from byte patterns.

`linked_checks.csv` records fields with an independent expectation:

- `function`: the target symbol has a unique registry VA, and the original field must address it;
- `import`: the original and rebuilt import slots must name the same DLL function;
- `internal_label`: a label inside the same function, such as a switch table, must keep its offset.

Other targets become pairs in `linked_pairs.csv`. A rebuilt item that pairs with several original addresses is a
`conflict`. An original item that pairs with several rebuilt items is a `split`; the original kept one copy where the
rebuild has two, or the reverse for `conflict`. Both describe layout, not necessarily behavior.

Each paired data item is compared in `linked_items.csv`. The defining object gives the item extent: the next symbol
in its section. A character string is compared through its terminator, a scalar global through the size its
decoration encodes, and a `__real@` constant through its encoded width. Relocated fields inside an item are paired
in turn, so pointer tables and virtual tables are checked through the same evidence. Results:

- `equal`: all compared bytes agree;
- `different`: a compared byte differs, and the exact function reads that byte from a different value;
- `tail_unproved`: only our trailing zero padding differs, and the item size is not proved;
- `zero_fill`: uninitialized storage; only the pairing is checked;
- `conflict`: the item has no single original address.

Items that no exact function reaches stay unchecked. A `different` item in an exact function is a real defect in the
rebuilt program: the same instructions read different data.

Offsets and sizes use decimal bytes. Ranges exclude their end offset.
Hex previews show at most 16 bytes per range and file.
The unmatched tail has bytes in only one file.
Raw byte counts cover file storage, not virtual zero-fill.
Reviewed storage checks can include virtual zero-fill.

## Interpretation

Moved code can make most positional bytes differ. This is not a behavior score.
Section names label raw ranges. They do not prove function or data ownership.
The tool does not infer constants, jump tables, virtual tables, or padding from byte patterns.
Reviewed tables use explicit storage owners and pointer offsets.
Unknown targets stay unknown.

Function rows compare original-size windows, not proved rebuilt function boundaries.
These windows can overlap or extend beyond a changed rebuilt function.
An equal window is not a function matching claim.
Aligned instruction windows also receive supported address-field checks.
Each recognized target needs an independent function identity or a reviewed storage owner.
An equal supported window does not prove unrecognized address operands or rebuilt boundaries.
Complete semantic byte attribution remains future work.
Resource payload equality does not prove equal resource directory bytes.

The command returns zero when it completes the report, even when images differ.
Input validation failures stop the report.

## First measured comparison

The tested build is `human-civ-effect-repair/20260914T215953270395Z` under `build/executable/`.

- Original SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Rebuilt SHA256: `75ea997f420d64395b314f25d0b3b6bf75bb121c5dc962ee41f8f425bf58278b`.
- Equal positional bytes: 78,541.
- Different positional bytes: 1,483,571.
- Original-only tail: 232,960 bytes.
- Resource payloads agree.
- All 61 reviewed storage checks pass.
- 2,805 supported normalized code windows agree; 5,185 remain unknown.

These counts describe this image pair, not all later builds.
The normalized window count is not a function matching count or a gameplay result.
Reports reside under `build/linked-image-diff/current/`.

## First linked pairing, 2026-10-13

The tested build is `build/noref-build/20261013T021925797320Z`, the first `/OPT:NOREF` link.

- 5,012 of 5,013 exact functions verified as seeds against their objects.
- Reference checks: 23,495 function, 785 import, and 270 internal-label fields pass; one import fails.
- Pairs: 4,705 functions, 2,311 consistent data items, 302 external targets, 152 splits, and 6 conflicts.
- Paired items: 2,122 equal, 85 different, 254 zero-fill, 2 tail-unproved, and 6 conflicts.

The findings are recorded in [linked data findings](../decomp_notes/linked_data_findings.md).
