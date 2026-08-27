# 00412240 `ResourceItem::sortLarge`

- PDB source: `airesitm.cpp`, lines 200 to 327.
- Original size: 200 bytes.

The method copies active values into the sorted lanes. It then uses descending
selection sort. It swaps each value and its original index together.

A prior isolated build differed by one SIB byte at the maximum-value compare.
Both forms addressed `sortedValue[maxIndex]`. The grouped result later reported
an exact owner. The merged source keeps the direct typed selection sort. It does
not retain pointer or register-control forms.

## Current module result

The focused module check reports `MISMATCH`. Both bodies are 200 bytes. One
positional byte differs at offset 104. The mismatch is a register recolor:
the rebuilt body swaps the `EBX` and `ECX` roles for this compare form.

The natural direct typed selection sort remains the source body. This owner is
scratch and is not registered as an exact translation-unit owner.
