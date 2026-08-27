# `com_err.cpp` source reunification

## Ownership

The PDB source is `C:\\msdev\\work\\age1_x1\\com_err.cpp`.
The module owns four handwritten functions in source and address order:
`00424E40`, `00424E60`, `00424EA0`, and `00424EB0`.

The bytes between these owners remain padding or data. The `ShowReturn` table
follows its body and is not a separate owner.

`src/com_err.cpp` is the sole compiler-facing owner. Its header uses the
canonical debug log declaration and the period Windows header. It does not
depend on the lobby module or DirectPlay declarations.

## Validation

The owner translation unit uses `config/flags/com_err.rsp`. A focused candidate
build checked every owner and returned `MATCH`, `0.0000%`, zero relocation
errors, and zero boundary escapes:

| VA | owner | bytes |
| --- | --- | ---: |
| `00424E40` | `RGE_Comm_Error::RGE_Comm_Error(void*)` | 18 |
| `00424E60` | `RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES, long)` | 53 |
| `00424EA0` | `RGE_Comm_Error::~RGE_Comm_Error()` | 1 |
| `00424EB0` | `RGE_Comm_Error::ShowReturn(long, char*)` | 2184 |

The lobby module remains a separate owner. Its context declarations are not
part of this module.
