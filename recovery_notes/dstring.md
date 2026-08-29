# dstring.cpp source module

`src/dstring.cpp` owns all 50 normal PDB functions in source order.
`include/dstring.h` owns the DString and DKeyString declarations.

The source uses pinned VC5 `<iostream.h>`, CRT, and character headers. It has
no wrapper, context macro, copied stream class, private stream access, stream
member surrogate, or explicit alignment padding.

`operator>>` uses the public inline `istream::get(buffer, 0x100)` overload.
The source keeps the required DString call-identity overrides only.

## Status

The direct source reports `MATCH` and `0.0000%` for 42 registered owners.
These include the constructors, string accessors, word helpers, conversion
helpers, case-copy helpers, and DKeyString owners.

`00447420 uppercase` and `004474E0 lowercase` are scratch. The canonical
`<ctype.h>` declarations cause two bytes of direct code drift in each owner.
The other eight unresolved owners remain scratch. A shared-worktree trial proved
`00446D30 operator char*` exact after the tools learned its VC5 conversion-
operator symbol. Do not restore copied stream layouts or manual CRT declarations
to promote the remaining functions.

The ten-worker wave also proved `00446710 operator<<` exact without a source
change. The period stream declaration emits the correct owner, call, boundary,
and all 27 bytes.
