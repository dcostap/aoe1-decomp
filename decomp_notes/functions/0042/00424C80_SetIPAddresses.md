# Function notes: 00424C80 `SetIPAddresses`

## Earlier notes from `decomp_notes/functions/0042/00424C80_SetIPAddresses.md`

This section is historical. Use the status query for current state.

## 00424C80 `RGE_Communications_Addresses::SetIPAddresses`

- PDB source: `com_addr.cpp`, lines 157 to 198.
- Original size: 260 bytes.

### Recovery record

1. The natural address traversal produced a 256-byte body.
2. An unsigned-byte address view restored the required byte promotion sequence.
3. The canonical class layout kept the exact result.

The merged source keeps the unsigned address view and copy order.
