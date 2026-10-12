# Independent review of stopped worker `sa-e7f1e0db`

## Scope and verdict

Reviewer ID: `sa-fd9c85a1`.
Worktree: `C:/Projects/my_decomps/aoe1_reviewer_wave_09`.
Branch: `reviewer-wave-09`.
Pinned base: `0ac0f344c5bc67a997c0c9e76c749c2ad91857d2`.

The review covers `RESFILE_open_new_resource_file` (`0047EE90`) and one
retained source-only change. The verdict is `APPROVE` for source retention
only. Keep the target status as `scratch`. Do not promote it to `exact`,
`verified_logic`, or `accepted_drift`.

The source change removes the temporary `int n` and compares each `read`
result directly:

```diff
-            int n;
             ...
-            n = read(fHandle, &rHdr, sizeof(rHdr));
-            if (n != sizeof(rHdr)) {
+            if (read(fHandle, &rHdr, sizeof(rHdr)) != sizeof(rHdr)) {
                 ...
             }
             ...
-            n = read(fHandle, node->header, rHdr.directory_size);
-            if (n != rHdr.directory_size) {
+            if (read(fHandle, node->header, rHdr.directory_size) !=
+                rHdr.directory_size) {
```

The worker changed only `src/Res_file.cpp` and its function note. It changed
no header, flag, registry, inventory, test, or behavior-oracle file.

## Reviewed states and events

The baseline state is
`b2f9aec2b1f46a2499d5b5e46a36e508d8241e39f0f1ec867b1d9952bd48d5c4`.
Its run event is
`e8e98a26374e7d5939680afa0a933dcc829ad93d23b9f8f6d537470f12369f46`.
Its source hash is
`98f9c9d0e34e866f5b031e31961e7c47d6d3e7dc725e1a3b9112ec7a928057b3`.

The retained child state is
`50f59a2420e77880c92cde9b5b4a60f61469a6b3859f0cec592b4869f3e3cc2b`.
Its compiler-input fingerprint is
`1ae98b576309367fc3cc0fa2a9ff9715e42cf05c766bf0b0f3fd9bf965d59e11`.
Its run events are
`fdd9edf85dbb7bcd65de70ec29afcc5b3bc74e5172d67c8d1ff81ae53c0a1c81` and
`ad75e1979414b097ef0ee63cd184b3bb45f693ab7dacb4e100704ed67cdec438`.
Its source hash is
`de6e9603021dc7937de6740dfa47e249f1c264266e0eda717dfc0695f3a06926`.
The worker finding event is
`3a1b76c9b64a2b8be39b1face3010aba9fbc71e3a3bf407b9fe82ec5b4a1d01c`.

I read the complete state metadata and compared the baseline and child input
diffs. The child changes only `src/Res_file.cpp`, as shown above. Both states
use the same base, default response file, toolchain, headers, and compiler
fingerprint. The child source hash matches the current source hash.

## Behavior

The source delta is behavior-neutral. In both forms, the first `read` runs
once after `lseek(fHandle, 0, 1)`. Its returned `int` is compared with the
same `sizeof(rHdr)` value. A short result takes the same error path. The
second `read` also runs once after `lseek(fHandle, 0, 0)`, and its result is
compared with the same `rHdr.directory_size` value. A short result takes the
same error path.

The removed `n` has no address use, alias, call argument, later read, write,
or return use. It is a scalar temporary for the immediately following
condition. The direct expression does not change evaluation order, calls,
arguments, integer conversion, branch condition, memory effects, cleanup, or
fault order. It does not alter the publication order or the later password
and version checks.

The original assembly compares the first `read` result in EAX at `0047F006`
and the second result in EAX against `[ebp-0x0C]` at `0047F057`. It has no
store of either result to a separate `n` home. The original short first read
reaches `INT3` at `0047F00B`, then the parent-owned error fragment at
`0047F00C`. The retained source leaves that existing fault behavior unchanged.

No runtime harness or fixture was available. Malformed files, short reads,
allocation failures, invalid names, and exception behavior were not executed.
This review proves the delta's equivalence from source and executable
structure; it does not prove the whole non-exact reconstruction for every
runtime input.

## Source

The edit preserves the canonical `ResFileHdr` and `resfile_header` types,
field offsets, pointer widths, ABI, calls, and natural source ownership. It
removes an artificial lifetime without adding an alias, helper, volatility,
wrapper, or compiler-specific construct.

The target dossier's `PdbScopedSymbols` lists `rHeader` at stack `-0x48`,
`fHandle`, `mapped_file_data`, and the buffers. It lists no read-result local.
The absence of a PDB symbol is not proof that no source local existed, but it
supports the direct comparison together with the original EAX compare pattern.
The source delta does not rely on absence alone.

The added function-note text accurately records the hypothesis, state and
event identities, output equality, closure, and unresolved target boundary.
No documentation correction is required.

## Bytes

The authoritative baseline and retained checks both report:

- `MISMATCH`, checker exit code `1`;
- original effective size `740`, rebuilt size `787`;
- frame `0x19C` original and `0x198` rebuilt;
- strict positional diff `757` bytes;
- shape similarity `88.32%`;
- `23/23` ordered calls, with equal call-site status for all 23;
- owner symbol match for `?RESFILE_open_new_resource_file@@YAXPAD00H@Z`;
- matching CFG counts of 18 conditional branches, 4 unconditional branches,
  and 8 returns; and
- rebuilt output SHA-256
  `adbed4c393a8bb6db88b7b43add2ed7333253b7d105bb97e3b7f7dd5e0908d84`.

`experiment_history.py compare` reports the same result, diff, output hash,
and no changed compiled owners. The target remains non-exact. The checker
reports two boundary escapes and 47 non-padding bytes beyond the 740-byte
effective boundary. The inventory has three compared body ranges and
parent-owned fragments at `0047F00C` and `0047F076`; the split ownership and
boundary problem remain unresolved. No relocation target mismatch is reported.

The equal output hash is expected because VC5 already kept the `read` result
in EAX for both source forms. The source improvement is still useful because
it removes an unsupported temporary and better represents the observed
operation without claiming a byte match.

## Integration

| proposal | technical verdict | source decision | status decision | preservation decision |
| --- | --- | --- | --- | --- |
| direct-read comparison source | `APPROVE` | retain `src/Res_file.cpp` | keep `0047EE90` as `scratch` | preserve child state, both run events, finding, and artifacts |
| exact promotion | not proposed | none | no status change | preserve the mismatch and boundary evidence |
| accepted-drift promotion | not proposed | none | no status change | preserve the mismatch and boundary evidence |
| worker function note | `APPROVE` | retain the added note | no registry change | preserve this review and the worker finding |

The retained one-job `res_file` closure compiled all nine owners. It reports
six exact matching neighbors, the known one-byte mismatch at `0047F320`, and
the known 644-byte mismatch at `0047F5C0`. No neighbor changed. The closure
report is `build/experiment_runs/41f92bb78e7f4f748fdee8057984ee72/closure/report.txt`.

Validation used:

- `python tools/experiment_history.py compare b2f9aec2b1f46a2499d5b5e46a36e508d8241e39f0f1ec867b1d9952bd48d5c4 50f59a2420e77880c92cde9b5b4a60f61469a6b3859f0cec592b4869f3e3cc2b`:
  same `MISMATCH`, diff `757`, output hash, and no changed owners;
- `python tools/experiment_history.py inspect 50f59a2420e77880c92cde9b5b4a60f61469a6b3859f0cec592b4869f3e3cc2b`:
  child inputs and events match the reviewed package;
- `python tools/check_function.py --va 0047EE90 --no-build --no-history --detail full --call-map-unmatched --block-map-differences --stack-map`:
  exit `1` with the expected `MISMATCH`, owner match, 23 equal calls, diff
  `757`, and two boundary escapes; and
- `git diff --check -- src/Res_file.cpp workflow/decomp_notes/functions/0047/0047EE90.md`:
  passed with no output.

The report artifact itself is durable at this path. There is no blocker for
source-only retention. Further target work needs new ownership, source, type,
or compiler-context evidence. Do not tune bytes only to remove the remaining
boundary and frame differences.
