# Source cleanup report: `src/com_addr.cpp`

## Delivery

- Module: `src/com_addr.cpp`.
- Branch: `cleanup/staging-20260915-101`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `04abef9192d97f572b31fc84eb5f81f010cda39e`.
- Changed files: `src/com_addr.cpp` and this report.
- Header read: `include/com_addr.h`. It was not changed.
- The source registry is `config/functions/src/com_addr.cpp.json`.
- The header emission registry is `config/functions/include/com_addr.h.json`.

The source keeps its eight source-registry functions in source order. The two
inline `IPAD` functions remain header-owned emissions. The cleanup changes
names and function-brace presentation only. It keeps types, scopes, storage,
statements, calls, casts, literals, and member layout.

## Evidence coverage

I inspected every VA in `config/functions/src/com_addr.cpp.json` and the two
header-owned emission VAs in `config/functions/include/com_addr.h.json`.
I selected the packets from those registry entries and inspected each packet
under the absolute main-root path
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/`:

- `004249D0_RGE_Communications_Addresses.txt`
- `00424B10_RGE_Communications_Addresses.txt`
- `00424B60_GetHostName.txt`
- `00424B80_SetIPAliases.txt`
- `00424C20_GetAddress.txt`
- `00424C50_GetAlias.txt`
- `00424C80_SetIPAddresses.txt`
- `00424D90_EraseInformation.txt`
- `00424DD0_IPAD.txt`
- `00424E30_IPAD.txt`

I inspected every assigned procedure's scoped PDB record in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The original PDB source is `C:\msdev\work\age1_x1\com_addr.cpp` for the eight
source functions and `C:\msdev\work\age1_x1\com_addr.h` for the two `IPAD`
functions. The original executable behavior reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The complete scoped-symbol coverage is:

| VA | Procedure | PDB stack names | PDB register names |
| --- | --- | --- | --- |
| `004249D0` | `RGE_Communications_Addresses::RGE_Communications_Addresses` | `CommIn` (`+0x4`, `TCommunications_Handler*`) | `this` (`ecx`) |
| `00424B10` | `RGE_Communications_Addresses::~RGE_Communications_Addresses` | none | `this` (`ecx`) |
| `00424B60` | `RGE_Communications_Addresses::GetHostName` | none | `this` (`ecx`) |
| `00424B80` | `RGE_Communications_Addresses::SetIPAliases` | `sz` (`+0x4`, `char*`) | `this` (`ecx`) |
| `00424C20` | `RGE_Communications_Addresses::GetAddress` | `Num` (`+0x4`, `unsigned int`) | `this` (`ecx`) |
| `00424C50` | `RGE_Communications_Addresses::GetAlias` | `Num` (`+0x4`, `unsigned int`) | `this` (`ecx`) |
| `00424C80` | `RGE_Communications_Addresses::SetIPAddresses` | `sz` (`+0x4`, `char*`), `temp` (`-0x1c`, `char[25]`) | `this` (`ecx`) |
| `00424D90` | `RGE_Communications_Addresses::EraseInformation` | none | `this` (`ecx`) |
| `00424DD0` | `IPAD::IPAD` (header emission) | none | `this` (`ecx`) |
| `00424E30` | `IPAD::~IPAD` (header emission) | none | `this` (`ecx`) |

All ten records have no function-static symbols. The scoped-symbol inventory
also has compiler-generated vector deleting destructor `00424AC0`, with
`__flags` at `+0x4` and `this` in `ecx`. It is not a registry source function
and has no handwritten source declaration in this module; it was not changed.

## Recovered original names

The source restores these procedure-scoped PDB names:

- `004249D0`: `handler` became `CommIn`.
- `00424B80`: `out_buffer` became `sz`.
- `00424C20`: `index` became `Num`.
- `00424C50`: `index` became `Num`.
- `00424C80`: `out_buffer` became `sz`.

The `00424C80` local `temp` already matched the PDB and remains unchanged.
The `this` register name and all class, member, and function names remain
unchanged. The source uses the exact mixed-case PDB spellings `CommIn` and
`Num`.

The PDB has no source-local records for `wsResult`, `buffer`, `he`,
`alias_ptr`, `alias`, `host`, `address_ptr`, `address`, or the local variables
in the other procedures. The source retains these existing descriptive names.
They are not claimed as recovered original names. No invented identifier was
added.

## Constants, resources, and comments

No numeric constant changed. The packet assembly confirms the existing values
and order for `WSAStartup(0x101, ...)`, the eight-element `IPAD` allocation,
the `0xFF` temporary buffer, the `0x80` hostname length, the `0xA0` `IPAD`
stride, and the address format string. No new enum, macro, or constant was
added.

This module has no resource lookup and no resource ID. The runtime resource
files were not used for this module, and no resource mapping or resource
header request is needed.

No new source comment was added. I updated two existing comments so their
parameter references use recovered `Num` and `sz` names. The retained comments
record behavior supported by the packets and prior function notes:

- The constructor and destructor comments record observed member offsets and
  call or cleanup order.
- The address getter comment records pointer formation before the count test.
- The alias getter comment records the shipped `>` test and its resulting
  count-equal access behavior. The source does not correct that behavior.
- The address-loader and alias-loader comments record buffer publication and
  counter-update order.

## Code-generation-sensitive review

The source changes rename identifiers and move function opening braces to
1TBS. They do not change declaration types, storage, declaration scope,
expression order, casts, control flow, calls, literals, member order, class
layout, function boundaries, direct targets, relocations, or ABI symbols.
The original `GetAddress` pointer arithmetic and `GetAlias` comparison remain
unchanged.

The brace and comment changes can alter debug line records. Final validation
must compare generated code, data, relocations, and call targets with the
preserved pre-cleanup build at
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.
No such validation was run here.

## Header and shared-file requests

Owner 12 controls `include/com_addr.h`. Please add the recovered parameter
names without changing types, order, access, layout, or ABI:

```cpp
RGE_Communications_Addresses(TCommunications_Handler* CommIn);
int SetIPAliases(char* sz);
int SetIPAddresses(char* sz);
char* GetAddress(unsigned int Num);
char* GetAlias(unsigned int Num);
```

No root-owned header request exists. No request exists for
`include/resource_ids.h` or `include/game_globals.h`.

## Validation

I ran the required evidence-tool help commands before evidence inspection. I
reviewed the complete source diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or executable validation command was run.
