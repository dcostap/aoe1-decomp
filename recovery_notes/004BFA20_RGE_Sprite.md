# 004BFA20 `RGE_Sprite::RGE_Sprite`

- PDB source: `sprite.cpp`, lines 140 to 262.
- Original size: 701 bytes.
- State: accepted drift.

The source parses the text sprite record. It converts the name, resolves the
main sound, sets flags, and creates picture and sound records. It preserves the
three sound slots per facet and the parser order.

The rebuilt function keeps the proven calls, field targets, parser order,
allocation order, publication order, fault order, and return behavior. The
remaining drift is the draw-record address schedule. The natural typed source
is retained.

## Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes duplicate
helper and context declarations from the old fragment.
