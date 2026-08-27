# 00412240 `ResourceItem::sortLarge`

- PDB source: `airesitm.cpp`, lines 200 to 327.
- Original size: 200 bytes.

The method copies active values into the sorted lanes. It then uses descending
selection sort. It swaps each value and its original index together.

A prior isolated build differed by one SIB byte at the maximum-value compare.
Both forms addressed `sortedValue[maxIndex]`. The grouped result later reported
an exact owner. The merged source keeps the direct typed selection sort. It does
not retain pointer or register-control forms.
