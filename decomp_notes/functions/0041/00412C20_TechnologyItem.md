# Function notes: 00412C20 `TechnologyItem`

## Earlier notes from `decomp_notes/functions/0041/00412C20_TechnologyItem.md`

This section is historical. Use the status query for current state.

## 00412C20 `TechnologyItem::TechnologyItem`

- PDB source: `aitchitm.cpp`, lines 35 to 38.
- Flags: `config/flags/default_gx.rsp`.
- Original size: 168 bytes.

The constructor receives `ResourceItem` by value. It allocates a copy with
`new ResourceItem(cost)`. The observed `ResourceItem` size is 0x70 bytes.

VC5 needs `/GX` for this constructor. The source is an exact registered owner.
