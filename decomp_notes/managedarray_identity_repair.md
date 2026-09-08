# ManagedArray identity repair

## Behavior

The original 70-byte `contains` body at `004DE980` uses a non-const receiver.
The corrected template emits all 70 bytes exactly, without relocations.
It reads numberValue first, returns zero for nonpositive counts, then limits each iteration by maximumSizeValue.
Within each iteration, it reads the array pointer, referenced item, and array element in the original instruction order.
It returns one on equality and zero on exhaustion. It neither writes memory nor calls another function.
This retains the original bounds, aliases, and data-fault order.

No game was run. The qualifier change does not add any source-body operation.

## Source

Original FPO linkage is `?contains@?$ManagedArray@H@@QAEHABH@Z`.
The previous declaration incorrectly added receiver const qualification and emitted the QBE spelling.
Remove that qualifier from the declaration and template definition. Keep the const item reference.
Do not change public/protected access or suppress the separate resize disagreement in this repair.

## Bytes

Baseline state: `f1e462fa69414ebd00074542ac4b46ee72adb19f44cff2979b78c6936634f4f8`.
Corrected state: `abbb99e8a2d3761723c56036ebd150de072b9710b02092e8620b38d45aa88349`.
Run event: `26e9566f1173bb538fe77349fbfc8b812bd6fae55ceac6b880c647c283c571d2`.
The removeObject target `004F1090` changes from 16 differing call-address bytes to `MATCH`, `0.0000%`.
Its emitted instruction bytes remain identical; the four external call symbols now name the original helper.

The 90-module audit compiles 2,764 normal functions.
It retains prior missing-target gaps and the two explicit resize disagreements. They are not reported as passes.
The complete comparison also records the separately reviewed main-view destructor repair.

After resolving actual local code/data labels and the reviewed contains symbol change, two scratch bodies change code generation:
`004F7870` and `004F81A0`. Their section sizes remain 2,512 and 1,056 bytes.
Their source bodies are unchanged. They remain scratch; no behavioral-equivalence or exactness promotion is claimed for them.
The numberWarshipsWithPriority difference includes changed resize inlining. Keep this as a compiler-context investigation lead.
No other normal body changes bytes or target identities beyond the intended contains binding.

## Integration

Accept the canonical declaration repair, not an equivalence promotion for the two scratch functions.
Preserve both states, the exact caller candidate, and the complete closure evidence.
Canonical candidate path: `decomp_notes/candidates/004F/004F1090_exact_candidate.patch`.
The tested integration base is `729d94ca0`; the preserved states include additional compiler inputs.
Event `44905ca4db61cb5b56be2282d5cd39dfaa15b499e80894e619bde5e1c4b2f2e7` preserves the audit and comparison script.
Public resize access remains a source repair problem. Its original protected linkage must not be treated as an alias.
