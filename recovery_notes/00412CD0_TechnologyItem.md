# 00412CD0 `TechnologyItem::TechnologyItem`

- PDB source: `aitchitm.cpp`, lines 46 to 49.
- Flags: `config/flags/default_gx.rsp`.
- Original size: 147 bytes.

The copy constructor allocates its resource cost from
`src.resourceCostValue`. The observed `ResourceItem` size is 0x70 bytes.

VC5 needs `/GX` for this constructor. The source is an exact registered owner.
