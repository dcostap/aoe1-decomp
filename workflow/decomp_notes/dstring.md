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

The accepted-drift reviews for `004471F0 append`, `00447420 uppercase`, and
`004474E0 lowercase` were reopened by `drift-022-dstring`. No behavior defect
was proved. Natural probes did not change the small SIB-address differences.
No source or registry change remains.
The other eight unresolved owners remain scratch. A shared-worktree trial proved
`00446D30 operator char*` exact after the tools learned its VC5 conversion-
operator symbol. Do not restore copied stream layouts or manual CRT declarations
to promote the remaining functions.

The ten-worker wave also proved `00446710 operator<<` exact without a source
change. The period stream declaration emits the correct owner, call, boundary,
and all 27 bytes.

## Second accepted-drift review: drift2-012-dstring

The review checked complete original bodies and PdbScopedSymbols for
`004471F0`, `00447420`, and `004474E0`. It found no proved source defect.
Their local differences remain scale-one address-term order only.
The function notes record instruction evidence, states, events, and open checks.

No compiler-facing source changed. The fresh baseline states are
`19350e5f84c7c5516006bb4745605665df2251b3a3cd9d24eb616e90739102c6`,
`8c2f9bedbd48cb085eeb9fc7e0b484a056b0171d1f4c6a98825c30cec3e9bfb3`, and
`28785aeb59872bd3c70b9b820283db255b708581e08999d288ae81a960e70583`.
The worker audit checked 50 owners: 47 exact results and three drift observations.
It found no exact-neighbor regression.
Report: `build/drift2-012-dstring/module-audit-final/report.txt` in the worker worktree.

The integration review retains the narrow uppercase and lowercase approvals.
The changed SIB encodings use the same scale-one sums and default DS segment.
Registers, flags, calls, signed input bytes, cleanup, and access order stay equal.
Neither function is byte-exact. High-byte, locale, and memory-fault cases were not run.

The append SEH references remain unresolved. The current linked map does not
name its owner, so that game image cannot supply the requested linked proof.
Its prior approval is withdrawn to `scratch`; no source defect is proved.
Allocation-failure and exception paths were not tested. A later review must prove
the scope table, unwind code, and handler identity before approving this target.
