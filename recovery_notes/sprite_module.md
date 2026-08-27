# sprite.cpp source module

- PDB source: `C:\\msdev\\work\\age1_x1\\sprite.cpp`.
- Source: `src/sprite.cpp`.
- Header: `include/sprite.h`.
- The source keeps all 22 normal owners in PDB order.
- The module uses `/O2 /Oy /GX` from `config/flags/004C0960_get_frame.rsp`.

## Module merge

The source moved every sprite owner into one natural C++ module. The header now
owns the sprite, shape, sound, picture-list, color-table, clip-list, and active
sprite layouts used by this source.

The merge removes the owner wrapper, the `sprite_get_frame_tu.cpp` wrapper, all
sprite function fragments, and the old context headers. It does not tune source
for byte output.

The translation-unit manifest keeps the 13 reviewed exact owners registered.
The other nine owners keep their reviewed module states. Temporary exactness
regressions after the merge are expected until grouped recovery runs again.
