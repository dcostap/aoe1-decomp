# registry.cpp source module

`src/registry.cpp` owns all eight normal PDB functions in source order.
`include/registry.h` owns only `TRegistry`.

The source uses Windows registry API declarations from `<windows.h>`. It has no
wrapper, context header, copied API function types, or explicit padding.

`0047EB80`, `0047EC00`, `0047EC40`, `0047ECA0`, `0047ED00`, `0047ED60`, and
`0047EE20` report `MATCH` and `0.0000%` from the direct module.

`0047EDD0 RegGet` is scratch. The direct source uses a natural registry type
local. The prior exact form overwrote the `dataSize` pointer local through a
cast. Do not restore that aliasing form.
