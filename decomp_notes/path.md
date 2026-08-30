# Path.cpp source-module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\Path.cpp`.
- Source: `src/Path.cpp`.
- Header: `include/path.h`.
- Flags: `config/flags/gx.rsp`.
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
class declarations, and recovery context macros are removed.
The function registry now names `src/Path.cpp` and all 30 normal functions.

## Recovery state

The migration checkpoint had 26 exact functions, three nonexact functions,
and one accepted source-drift function. The accepted function was `0046AAE0`.
The nonexact functions were
`0046A740`, `0046A810`, and `0046A9E0`. These are source-bank classifications
from the reviewed pre-migration work. They are not grouped exact claims.

The merged candidate audit checked all 30 owners. The three byte-equal operator
bodies are unregistered ownership problems because the generic audit does not
prove the `??6`, `??H`, and `??4` operator decorations. Their candidate results
are `0046A810` 206/206, `0046A8E0` 253/253, and `0046A9E0` 241/241, each with
zero masked byte differences and zero relocation-target differences. Keep the
existing source-bank classifications until their grouped symbol ownership is
reviewed.

`0046AAE0` remains the reviewed accepted-drift source, but its merged candidate
has 108 differing bytes in a 122-byte comparison. The old isolated 9-byte
pre-loop drift is not a current grouped exact result. The audit classifies this
as `accepted_drift_observed`; do not register it as an exact owner.

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

The constructor is a source-module regression. It still emits 162 bytes with
matching frame, calls, CFG, owner, and relocations, but has four positional byte
differences. At offsets `+005A`, `+0066`, `+0070`, and `+007A`, the original byte
is `02` and the rebuilt byte is `10`. These bytes are the displacement in the
four copied-waypoint stores. The difference is a register-map drift, not a
source behavior change. It is scratch and is not a grouped exact claim.

Focused checks after the merge compiled the complete module. `0046A7F0` and
`0046AFE0` still report `MATCH` with `0.0000%` difference. The source-module
and translation-unit structural checks pass. The complete candidate audit
reports 25 grouped matches, one constructor regression, three operator
ownership problems, and one accepted-drift observation.
