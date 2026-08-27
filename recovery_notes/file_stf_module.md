# file_stf source module

Source module: `C:\\msdev\\work\\age1_x1\\file_stf.cpp`.

The module now owns all 22 normal PDB owners in address and source order.
The compiler-facing source is `src/file_stf.cpp`.
The normal declarations are in `include/file_stf.h`.

The old wrapper, context header, and 22 fragment files were removed.
The translation-unit entry is `file_stf`.
The module metadata lists all 22 owners.

## Validation

Before migration, the grouped packet had 21 registered exact owners and one
accepted-drift owner. The final source keeps that status split.

The accepted-drift owner is `00449710 compareFilenameStrings`. Its source and
binary behavior are equivalent, but its register allocation and return sequence
differ from the executable. The old source recorded 35 of 59 edit-equal bytes.

The natural reunified form of `00449710` rebuilt to 63 bytes with 57 differing
bytes. It remains accepted drift because the source behavior is unchanged.

The natural reunified form of `00449990 numberOfFilesWithFilenameOrAttribute`
rebuilt to 162 bytes against the original 144 bytes, with 146 differing bytes.
Its frame stayed 0x118 and all four direct calls kept their target identity, but
its early-return control flow changed the emitted block layout. It is scratch,
not exact, until a later source recovery pass resolves that regression.

The other 21 owners were exact before migration. Reunification keeps their
natural source bodies and one compiler-facing owner in PDB order.

The post-migration grouped check must be rerun after this source move. Any
changed result is a source-reunification regression, not a new exact claim.
