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

The tool checks the recorded EXE and map hashes and the current registry.
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
- `report.md` gives the short result and limits.

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
