# `scr_save.cpp` provider hold

Do not register a direct `scr_save.cpp` translation unit yet.

The module needs two source-owned provider types:

- `TRIBE_Screen_Sed` for `need_to_save_flag` at `+0x4C0`;
- `TRIBE_Screen_Sed_Open` for the real `0x490`-byte construction.

The current `scr_sed` and `scr_sedo` headers still define duplicate panel
surfaces. They do not compose with the canonical panel headers. Do not add a
partial screen class, a size-only class, or a local construction provider.

Keep the registered wrapper and current normal owners until those modules
publish full canonical owner headers. Then recover one direct source module in
PDB order. Use typed game and screen pointers. Use typed child deletion or
natural deletion. Do not cast child-pointer addresses to `TPanel**`.

The unpublished candidate validated four exact normal bodies and one generated
destructor. Its `action` body stayed scratch at a 665-byte positional
difference. Treat those values as local codegen evidence only.
