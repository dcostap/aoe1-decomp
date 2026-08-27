# `Scr_main.cpp` source-module migration

- PDB source: `C:\\msdev\\work\\age1_x1\\Scr_main.cpp`.
- Source: `src/scr_main.cpp`.
- Header: `include/scr_main.h`.
- Flags: `config/flags/default_gx.rsp`.

The PDB owns eleven normal functions in this order:

- `0049E6D0` `TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu`, lines 85 to 193, 1281 bytes.
- `0049EC00` `TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu`, lines 199 to 214, 203 bytes.
- `0049ECD0` `TRIBE_Screen_Main_Menu::handle_idle`, lines 220 to 225, 33 bytes.
- `0049ED00` `TRIBE_Screen_Main_Menu::key_down_action`, lines 231 to 258, 250 bytes.
- `0049EE00` `TRIBE_Screen_Main_Menu::action`, lines 264 to 387, 715 bytes.
- `0049F0D0` `TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error`, lines 395 to 420, 335 bytes.
- `0049F240` `TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error`, lines 426 to 429, 100 bytes.
- `0049F2B0` `TRIBE_Screen_Main_Error::set_text(char*)`, lines 435 to 437, 22 bytes.
- `0049F2D0` `TRIBE_Screen_Main_Error::set_text(long)`, lines 443 to 445, 22 bytes.
- `0049F2F0` `TRIBE_Screen_Main_Error::action`, lines 451 to 474, 80 bytes.
- `0049F340` `TRIBE_Screen_Main_Error::handle_idle`, lines 480 to 484, 33 bytes.

The complete source keeps this PDB order. The former wrapper, source-bank
fragments, fallback declarations, and context header were removed. The bodies
were moved without byte-tuning changes.

The standalone source had nine matching owners and two scratch owners. The
standalone exact owners were `0049EC00`, `0049ECD0`, `0049ED00`, `0049F0D0`,
`0049F240`, `0049F2B0`, `0049F2D0`, `0049F2F0`, and `0049F340`. The constructor
and menu action remain scratch because their prior sources reported mismatches.
The module build can report temporary grouped regressions during this source
shape migration. Exact repair resumes on the final source tree.

The nearby entries `0049EBE0` scalar deleting destructor and `0049F220` vector
deleting destructor are compiler-generated. They are not normal source owners.
