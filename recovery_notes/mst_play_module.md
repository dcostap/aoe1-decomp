# `mst_play.cpp` direct-source checkpoint

## Scope and ownership

The PDB source is `C:\\msdev\\work\\age1_x1\\mst_play.cpp`.

`src/mst_play.cpp` is the direct source for the eight normal owners, in PDB
source and address order:

1. `00460FD0` `RGE_Master_Player::RGE_Master_Player(FILE*)`;
2. `004610C0` `RGE_Master_Player::RGE_Master_Player(int)`;
3. `00461150` `RGE_Master_Player::~RGE_Master_Player()`;
4. `004611D0` `RGE_Master_Player::finish_init`;
5. `00461270` `RGE_Master_Player::load_master_object`;
6. `00461530` `RGE_Master_Player::create_master_object_space`;
7. `00461560` `RGE_Master_Player::load_object`; and
8. `00461840` `RGE_Master_Player::save`.

The nearby `004614D9` entry is a padding-only inventory entry. It has no
handwritten source owner.

## Canonical composition

`include/mst_play.h` owns `RGE_Master_Player` and includes the canonical
`m_mi_obj.h` and owner-only `m_dg_obj.h` headers. The missile class comes from
`m_mi_obj.h`. The doppleganger class comes from `m_dg_obj.h`, which derives from
the canonical animated-master owner.

The source uses natural C++ class construction, destruction, virtual dispatch,
and derived-to-base conversion. It does not use `mst_play_context.h`, a
function-fragment include, a local carrier, a copied foreign layout, or a
manual vptr store. The source uses `config/flags/00461270_load_master_object.rsp`
with `/nologo /c /O2 /Oy /GX`.

## Current-main composition result

The grouped candidate is
`build/candidate_tus/mst_play_current_main_final/report.json`.
It compiles `src/mst_play.cpp` with the current-main owner-only header
composition. All eight normal owners report `MATCH` and `0.0000%` positional
difference:

- `00460FD0`: 200 bytes;
- `004610C0`: 134 bytes;
- `00461150`: 123 bytes;
- `004611D0`: 153 bytes;
- `00461270`: 617 bytes;
- `00461530`: 38 bytes;
- `00461560`: 648 bytes; and
- `00461840`: 198 bytes.

The candidate reports zero comparison errors, relocation-target mismatches,
and boundary escapes. Owner symbols and direct call targets match. The focused
`00461270` check also reports `MATCH` and `0.0000%`.

This result uses the current-main `m_dg_obj.h` content from `c7845ff83`.
No `m_dg_obj.cpp` source change is included.
