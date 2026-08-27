# 00411F10 `ResourceItem::ResourceItem(int)`

- PDB source: `airesitm.cpp`, lines 40 to 51.
- Original size: 98 bytes.

The constructor sets links to null. It stores zero in each active value lane.
It sets each inactive value lane to -1. It sets both sorted lanes to -1.

The former fragment used an initializer list to preserve grouped VC5 store order.
The source module keeps that natural initialization. Exactness needs a new module check.

## Current module result

The focused module check reports `MISMATCH`. The rebuilt body is 95 bytes. The
original body is 98 bytes. The check reports 65 positional diff bytes across
14 spans. The first mismatch is at offset 1.

The natural constructor remains the source body. This owner is scratch and is
not registered as an exact translation-unit owner.
