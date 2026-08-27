# 00411F80 `ResourceItem::ResourceItem(int, int *)`

- PDB source: `airesitm.cpp`, lines 59 to 70.
- Original size: 105 bytes.

The first loop copies at most eight input values. It sets both sorted lanes to -1.
The second loop sets every remaining lane to -1.

The former fragment kept a top capacity guard and a shared final exit. It also
kept a VC5 induction-update order. Those forms controlled bytes only. The
merged module uses the direct indexed loops that describe the observed behavior.
