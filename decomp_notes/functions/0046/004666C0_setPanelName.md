# Function notes: 004666C0 `TPanel::setPanelName`

## Current reconstruction

`Panel.cpp` is the compiler-facing owner for the PDB `Panel.cpp` compiland.
The target is `TPanel::setPanelName(char*)`, at `004666C0-00466765`, with
PDB lines 2398-2413. The class field `panel_name` is the reviewed `TPanel`
field at `this+0x1C`.

The natural exact source keeps the original null, reuse, free, allocate, and
copy flow. After the old-name null guard, it stores the new-name length in one
unsigned local before it evaluates the old-name length:

```cpp
        unsigned int name_length;
        if (old == 0) goto alloc;
        name_length = strlen(name);
        if (strlen(old) >= name_length) goto copy;
```

This local is source-level state, not a compiler-only alias. The executable
proves the new-name scan first, keeps that result in `EBP`, scans the old name
second, and compares the old length in `ECX` against the saved new length.
The old length does not need a second source local.

## Evidence and probes

- Baseline after canonical-header migration: 166 bytes and identical CFG,
  frame, calls, owner, and boundaries, but three register-encoding bytes
  differed. The candidate scanned `old` before `name`; the executable scanned
  `name` before `old`.
- Direct equivalent spelling `strlen(name) <= strlen(old)` changed the scan
  order, but emitted `JBE` and remained non-exact. The source comparison
  spelling controls the target `CMP`/`JAE` form.
- Function-scope `size_t name_length` and `old_length`, assigned in name-then-old
  order, produced `MATCH`, `0.0000%`.
- Replacing `size_t` with `unsigned int` produced the same exact bytes.
- Removing the redundant `old_length` local while retaining one unsigned
  `name_length` local kept exact output.
- A signed `int` walkback emitted `JGE` and missed one byte. The unsigned type
  is required by the executable branch form.
- Nested local scope, split declaration and assignment, and the final
  unscoped declaration after `old` all emitted the same exact bytes. The final
  form is the smallest natural source form tested.
- The final focused check reports `MATCH`, `0.0000%`, 166/166 bytes, 76/76
  instructions, 3/3 ordered direct calls, correct owner, relocations, CFG,
  and boundary.

An initialized local placed after the `goto alloc` guard was also tested, but
its first form was rejected by VC5 because the goto skipped initialization.
The final uninitialized declaration plus explicit assignment avoids that
syntax issue and matches period source style.

## Translation-unit validation

The final `Panel.cpp` source was compiled as the complete registered `Panel`
translation unit. The observed sweep included 117 normal functions and 105
registered owners. All 105 registered owners reported `registered_owner_match`.
The known unregistered and non-exact module entries remain outside this repair.
No shared header, global storage, registry, or status file changed.

The final exact source was checked again after the complete-module audit. The
baseline three-byte mismatch is resolved by the one local and the source
comparison form. The exact checkpoint is `final-exact` in the target session.
