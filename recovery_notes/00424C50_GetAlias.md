# 00424C50 `RGE_Communications_Addresses::GetAlias`

- PDB source: `com_addr.cpp`, lines 146 to 154.
- Original size: 42 bytes.

## Recovery record

The direct `winsock.h` and `stdio.h` context fixed the final SIB byte.
Removing `stdio.h` restored a one-byte difference. Other natural forms kept that difference.

Fresh grouped validation after migration and IPAD restoration produced
`MATCH`, `0.0000%`, with the complete owner and boundary checks.

The method keeps the shipped `>` count test. The count itself selects the next record.
