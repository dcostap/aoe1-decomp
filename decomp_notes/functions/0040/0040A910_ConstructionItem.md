# Function notes: 0040A910 `ConstructionItem`

## Earlier notes from `decomp_notes/functions/0040/0040A910_ConstructionItem.md`

This section is historical. Use the status query for current state.

## 0040A910 `ConstructionItem::ConstructionItem(const ConstructionItem&)`

- PDB source: `aiconitm.cpp`, lines 63 to 64.
- Original size: 53 bytes.

The base initializer calls `BaseItem::BaseItem(const BaseItem&)`. The initializer list keeps the derived vptr store after all derived field stores.
