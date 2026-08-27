# aibobj.cpp source reunification

## Authentic translation-unit context

- **Proved PDB source module:** `C:\msdev\work\age1_x1\aibobj.cpp`.
- **Proved source-line band:** lines 43-544.
- **Proved source order:** normal owners run from `00409FA0` through `0040A7F0`.
- **Proved class owner:** `BaseObject` owns all 54 normal functions.
- **Proved layout:** the PDB type record and emitted field accesses place the
  virtual destructor at `+0x00`, with the data ending at `+0x9C`; `sizeof` is
  `0xA0`.
- **Proved generated entry:** `0040A040` is the compiler-generated vector
  deleting destructor. It has no handwritten source owner.
- **Proved exact anchors before migration:** `00409FA0`, `0040A060`,
  `0040A130`, `0040A240`, `0040A350`, and `0040A3F0` through `0040A7F0`
  matched from the prior module wrapper. The four comparison operators had
  scratch sources and no registered exact result.

## Source decisions

The former per-function files used fallback class declarations and the former
module wrapper used a context macro. The final source has one `BaseObject`
declaration in `include/aibobj.h` and one definition owner in
`src/aibobj.cpp`. The field names use one canonical `Value` form. The four
constructors keep their shipped overloads, including the non-const pointer copy
overload. The constructors copy at most 63 name bytes and do not add a null
terminator. This preserves the observed call and fault behavior.

The four comparison operators compare `gameIDValue` and return `int`. Their
prior scratch sources could not produce a checker record because the extractor
could not select a defined operator name. The final source emits the four
expected decorated symbols and matches each original 24-byte body.

## Migration validation

The final source uses `config/flags/default.rsp` and the registered
translation-unit entry must point to `src/aibobj.cpp`. A direct final-source
compile matched all 54 normal owners and the 30-byte generated destructor.
The old wrapper and all 54 owned fragments are removed. Any exactness change
after this source move is a structural regression. Restore exactness only with
ordinary source and reviewed context; do not add byte forcing or a codegen-only
form.

## Reopening conditions

The parent agent must update the registered translation-unit owner map before
the grouped checker can validate this final source. Reopen constructor or
operator matching only if that grouped check changes a boundary, symbol, call
target, or byte result.
