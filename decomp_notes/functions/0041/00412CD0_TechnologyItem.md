# Function notes: 00412CD0 `TechnologyItem`

## Earlier notes from `decomp_notes/functions/0041/00412CD0_TechnologyItem.md`

This section is historical. Use the status query for current state.

## 00412CD0 `TechnologyItem::TechnologyItem`

- PDB source: `aitchitm.cpp`, lines 46 to 49.
- Flags: `config/flags/default_gx.rsp`.
- Original size: 147 bytes.

The copy constructor allocates its resource cost from
`src.resourceCostValue`. The observed `ResourceItem` size is 0x70 bytes.

VC5 needs `/GX` for this constructor. The source is an exact registered owner.
