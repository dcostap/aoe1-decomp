# getdxver.cpp source module

`src/getdxver.cpp` owns both normal PDB functions in source order.
`include/getdxver.h` owns only the required Windows and DirectX API surface.

The header uses pinned SDK declarations. It declares the missing legacy GUIDs
as imports. It does not define GUID data or copy COM interface records.

`0044DAC0 GetDXVersion` and `0044DEE0 IsDPlay501a` report `MATCH` and
`0.0000%` from the direct module.

The module has no wrapper, context header, source-bank owner, or explicit
alignment padding.
