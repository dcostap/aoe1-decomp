# Padding-only corpus entries

`padding_only` entries contain only reviewed non-behavioral bytes such as:

- `nop`;
- repeated `nop`;
- `mov edi, edi`;
- combinations of those instructions.

They usually occur between a real function and switch-table data, or between
compiler-generated thunks. Inventory metadata can label these byte ranges as
functions even though they have no call, branch, return, or memory effect.

The reviewed VA list lives in:

```text
config/padding_only_functions.txt
```

Keep the exact byte shim in `src/matching` when the isolated matching build needs
it. Do not create scratch, accepted-drift, or verified-logic work for these
entries. Do not move them to the handwritten-assembly workstream.

The 2026-08-16 audit reviewed 194 matching files with inline-assembly syntax:

- 185 were padding-only entries;
- eight were real normal functions using forbidden inline assembly;
- one was a parent-owned fragment of `00535FE0 view_function`.

The eight real functions moved to `src/scratch` for later typed C++ recovery.
The parent-owned fragment `00536932` now lives in the parent-owned manifest.
