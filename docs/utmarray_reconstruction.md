# `utmarray.h` reconstruction

`include/utmarray.h` reconstructs the original `ManagedArray<T>` template.

## Binary-supported class surface

The original CodeView type records prove this `ManagedArray<int>` layout:

| Offset | Field | Type |
|---:|---|---|
| `0x00` | `value` | `int*` |
| `0x04` | `numberValue` | `int` |
| `0x08` | `desiredNumberValue` | `int` |
| `0x0C` | `maximumSizeValue` | `int` |

The total size is `0x10`. All four fields are protected.

The same type records prove these methods and access levels:

| Method | Access | Evidence |
|---|---|---|
| `ManagedArray(int)` | public | exact signature and default-constructor closure |
| `~ManagedArray()` | public | exact signature and body |
| `operator[](int)` | public | exact signature and body |
| `enlarge(int)` | public | exact signature |
| `shrink(int)` | public | exact signature |
| `contains(const T&) const` | public | exact signature and body |
| `position(T&)` | public | exact signature |
| `add(T)` | public | exact signature and body |
| `remove(T)` | public | exact signature and body |
| `number() const` | public | exact signature |
| `desiredNumber() const` | public | exact signature |
| `setDesiredNumber(int)` | public | exact signature |
| `zeroNumber()` | public | exact signature |
| `maximumSize() const` | public | exact signature |
| `sort(int (__cdecl*)(T,T))` | public | exact signature |
| `resize(int)` | protected | exact signature and body |

## Exact code evidence

Pinned VC5 compiles five emitted `ManagedArray<int>` methods from the shared
header to the original bytes:

| VA | Method | Size |
|---:|---|---:|
| `00408D20` | destructor | 47 |
| `004DE980` | `contains` | 70 |
| `004DE9D0` | `add` | 154 |
| `004EA750` | `operator[]` | 102 |
| `004F1390` | `remove` | 89 |

The PDB proves that `ManagedArray<int>::resize(int)` is protected. The current
reconstructed header keeps `resize` public because reconstructed external
callers still depend on that access. Its body now has canonical header
ownership. `tools/validate_utmarray.py` reports the missing protected
signature `?resize@?$ManagedArray@H@@IAEHH@Z` under this header. This is an open
access and owner blocker. Do not change the header access or external callers
until that boundary is resolved. The other five emitted exact methods remain
valid.

Run this command to check the header. It currently stops at the missing
protected `resize` signature noted above:

```text
python tools/validate_utmarray.py
```

The validator also checks all 16 PDB-proven decorated method signatures.

## Inferred inline bodies

No standalone executable body exists for the constructor, `enlarge`,
`shrink`, `position`, the three accessors, `setDesiredNumber`, `zeroNumber`,
or `sort`.

Their signatures, access, field types, and class order are exact. Their bodies
use the smallest behavior consistent with those facts and observed inline
array behavior. Treat these bodies as strong source recovery, not positional
byte proof.

The `sort` body has the weakest call-site evidence. Its comparator signature is
exact. Its simple comparison-and-swap implementation remains an inference.
