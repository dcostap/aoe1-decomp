# 004249D0 `RGE_Communications_Addresses::RGE_Communications_Addresses`

- PDB source: `com_addr.cpp`, lines 8 to 79.
- Original size: 227 bytes.
- Flags: `config/flags/004249D0_RGE_Communications_Addresses.rsp`.

## Recovery record

1. The natural constructor used `new IPAD[8]`, the hostname methods, and `/GX`.
2. A canonical hostname array with the old gap changed three bytes.
3. Removing the redundant gap produced an exact result.
4. A typed `WSADATA` member kept the exact result.

The merged source keeps the proven class layout and call order.
