# Path.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\Path.cpp`.
- Source: `src/Path.cpp`.
- Header: `include/path.h`.
- Flags: `config/flags/0046A8E0_operator.rsp`.
- PDB lines: 36 to 367.
- Normal owners: 30, in PDB address order from `0046A740` through `0046AFE0`.

## Module ownership

The module uses one `Path` class declaration and one `Waypoint` declaration.
`Waypoint` is a 16-byte record. `Path` is a 0x34-byte object. The header keeps
`growMaxSize` and `setMaxSize` inline because the assignment body uses the
original inline resize surface.

The source owns all 30 normal bodies in PDB order:

1. `0046A740` constructor.
2. `0046A7F0` destructor.
3. `0046A810` stream output.
4. `0046A8E0` path addition.
5. `0046A9E0` assignment.
6. `0046AAE0` equality.
7. `0046AB60` through `0046AFE0` path operations and accessors.

The previous wrapper, context header, per-function source fragments, fallback
class declarations, and recovery context macros are removed. The translation
unit entry now points to `src/Path.cpp` and keeps only its prior registered
exact owners. The module manifest records all 30 normal owners, including the
unregistered observed owners.

## Recovery state

The manifest records 27 matching owners, two scratch owners, and one accepted
source drift owner. The accepted owner is `0046AAE0`. The scratch owners are
`0046A810` and `0046A9E0`. This source-shape migration does not promote those
owners or tune their code generation.

`0046A8E0` retains its reviewed custom response-file context. Its natural source
uses the two source-array indices required by the original copy loops.

## Behavior notes

`Path::length` preserves a shipped expression defect. The first z-axis product
subtracts the previous waypoint's x value. The executable's x87 instruction
sequence proves this behavior. The source marks it as an `ORIGINAL BUG`.

`Path::operator==` keeps the reviewed equivalent source. Its remaining drift is
limited to the pre-loop register setup. The loop body and return paths remain
behavior-equivalent.

The migration preserves the reviewed bodies and behavior. It accepts temporary
exactness regressions caused by the complete natural source module. Compile and
exact checks after migration are evidence only; this task does not perform byte
tuning.

Focused checks after the merge compiled the complete module. `0046A7F0` and
`0046AFE0` still report `MATCH` with `0.0000%` difference. The constructor
`0046A740` emits 162 bytes with a four-byte positional difference. The source
module and translation-unit validation tests pass.
