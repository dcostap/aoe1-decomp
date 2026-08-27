# 0040A8D0 `ConstructionItem::ConstructionItem(ConstructionItem*)`

- PDB source: `aiconitm.cpp`, lines 51 to 52.
- Original size: 53 bytes.

The initializer list keeps the derived vptr store after all derived field stores. Body assignments move that store earlier in VC5 output.
