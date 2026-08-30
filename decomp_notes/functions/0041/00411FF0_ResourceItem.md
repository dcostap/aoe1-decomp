# Function notes: 00411FF0 `ResourceItem`

## Earlier notes from `decomp_notes/functions/0041/00411FF0_ResourceItem.md`

This section is historical. Use the status query for current state.

## 00411FF0 `ResourceItem::ResourceItem(const ResourceItem &)`

- PDB source: `airesitm.cpp`, lines 78 to 84.
- Original size: 82 bytes.

The constructor resets links and copies the item count. It copies each active
value, sorted-value, and sorted-index lane. It does not initialize lanes above
the count.

The former fragment used local and pointer shapes to control VC5 scheduling.
The merged module uses direct member copies.
