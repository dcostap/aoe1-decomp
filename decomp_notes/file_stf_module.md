# file_stf source module

Source module: `C:\\msdev\\work\\age1_x1\\file_stf.cpp`.

The module now owns all 22 normal PDB owners in address and source order.
The compiler-facing source is `src/file_stf.cpp`.
The normal declarations are in `include/file_stf.h`.

The old wrapper, context header, and 22 fragment files were removed.
The translation-unit entry is `file_stf`.
The module metadata lists all 22 owners.

## Validation

Before migration, the grouped packet had 20 registered exact owners, one
scratch owner, and one accepted-drift owner.

The former accepted-drift owner is `00449710 compareFilenameStrings`. Its
source and binary behavior are equivalent, but its register allocation and
return sequence differ from the executable. The old source recorded 35 of 59
edit-equal bytes.

The natural reunified form of `00449710` rebuilt to 63 bytes with 57 differing
bytes and one boundary escape. Its source status is scratch because the
boundary is not equivalent.

The natural reunified form of `00449990 numberOfFilesWithFilenameOrAttribute`
rebuilt to 162 bytes against the original 144 bytes, with 146 differing bytes.
Its frame stayed 0x118 and all four direct calls kept their target identity, but
its early return changed the emitted block layout. The current source restores
the parent matching candidate's `goto done` shape. The grouped check reports
`MATCH`, `0.0000%`, correct ownership, boundaries, and relocations. The owner
is registered as matching.

The other 20 exact owners remain exact after migration. Reunification keeps their
natural source bodies and one compiler-facing owner in PDB order.

The final grouped check has 21 registered exact owners. `00449710` remains an
observed scratch owner with one boundary escape.
