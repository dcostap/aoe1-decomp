# Function checker diagnostics

`python tools/check_function.py --va <VA>` is both the exact promotion gate and
the normal iteration guide.

The concise report is deliberately ordered from global invariants to local bytes:

1. rebuilt meaningful code size versus the original size;
2. stack frame and entry callee-save set;
3. instruction-shape alignment and longest aligned run;
4. context-aware direct/virtual call alignment, per-target call-count deltas, and coarse CFG signals;
5. exact normalized basic-block coverage and the first block divergence;
6. strict positional byte equality;
7. change impact relative to the previous run;
8. a workflow stage and the next highest-value diagnostic hunk.

The checker selects the target by its COFF function symbol. It retains ordinary
VC5 section-alignment NOPs only when needed for the original comparison span and
uses entry-reachable control flow at the original boundary to distinguish real
overflow code from adjacent jump-table/EH data. Reachable overflow code is included
in the comparison; auxiliary data is not mistaken for function body bytes. The
checker never silently truncates an oversized rebuilt function.

## Workflow stages

The stage is evidence-driven rather than a per-function instruction:

- `STRUCTURAL RECONSTRUCTION`: size, calls, or instruction topology are still
  materially different. Fix the first paired structural/call hunk before register
  coloring.
- `CALL TARGET INTEGRITY`: instruction structure is aligned, but a direct call
  names a different external symbol.
- `STACK/LOCAL TOPOLOGY`: calls and structure are close, but the frame differs.
- `BLOCK SHAPE AND LIVENESS`: broad structure is close; work from the first paired
  instruction hunk while preserving aligned regions.
- `EXACT CODEGEN`: the mismatch is localized enough for source-shape probes or a
  focused variant lab.
- `COMPLETE`: strict comparison and checked relocation identities match.

## Relocations

A rebuilt relocation is masked only when its containing original and rebuilt
instructions have the same start, mnemonic, and length. Known direct-call target
mismatches are not masked. This avoids manufacturing equal bytes by applying
rebuilt relocation offsets to unrelated original instructions.

The complete machine-readable report is written to `build/diff/<slug>.json`; the
human report is `build/diff/<slug>.txt`. The prior rebuilt output is retained under
`build/history/<slug>/` so each run can report output blast radius and strict
improvements/regressions.

Every completed check also records a deduplicated persistent checkpoint under
`build/history/<slug>/runs/`. A checkpoint contains the source, custom flag state,
generated object/assembly, extraction metadata, and full diff report (large text/JSON
artifacts are gzip-compressed). The compact
`history.json` index stores metrics and a multi-objective Pareto marker. Pareto means
that no other recorded run is at least as good on every tracked structural objective;
it does **not** mean the candidate is exact or preferred after human review.

Useful commands:

```bat
python tools\check_function.py --va 00449750 --checkpoint best-call-prefix
python tools\check_function.py --va 00449750 --history
python tools\check_function.py --va 00449750 --compare-checkpoint best-call-prefix
python tools\check_function.py --va 00449750 --compare-history best-call-prefix @best-shape
python tools\check_function.py --va 00449750 --restore-checkpoint best-call-prefix
python tools\check_function.py --va 00449750 --restore-checkpoint @best-call-prefix
python tools\check_function.py --va 00449750 --prune-history --prune-keep 20
python tools\check_function.py --va 00449750 --prune-history --prune-keep 20 --apply-prune
```

Restore first backs up the current source/custom response file under
`build/history/<slug>/restore-backups/`. It restores source and custom-flag state;
run the checker again to rebuild generated artifacts.

Computed selectors avoid forcing one scalar “best” score: `@latest`,
`@best-call-prefix`, `@best-shape`, `@best-blocks`, `@best-positional`, and
`@closest-size`. These selectors use a primary metric plus a positional-diff
tiebreak; inspect the Pareto history before restoring because different structural
objectives can legitimately favor different candidates.

Checkpoint comparison includes structural deltas in addition to summary metrics:
new/resolved call-alignment issues, newly exact/lost original basic blocks, and the
movement of the first block divergence. Issue comparison uses call kind/target/status
rather than absolute rebuilt offsets, so harmless code shifts do not disguise the
same underlying discrepancy.

History pruning is dry-run by default. It removes only old checkpoints that are
unlabeled, off the Pareto frontier, and outside the requested recent-retention window.
`--apply-prune` is required for deletion; labels, Pareto candidates, and the newest
`--prune-keep` runs are protected.

Programmatic sweeps and labs should pass `--no-history` so thousands of transient
checks do not create checkpoints. Repo batch callers already do this. Ordinary manual
checks retain automatic history. `--quiet` remains accepted for compatibility with
batch callers and selects concise diagnostics.

For structural mismatches, the report lists aggregate call-target count differences
as `rebuilt/original`, ordered by the largest absolute gap. It also reports which
target counts changed in the latest iteration. These counts expose missing or extra
behavioral calls but do not replace call-site alignment: equal totals can still hide
reordered calls, shared-tail placement changes, or wrong control flow.

## Call-site alignment

`--call-map` prints every aligned call occurrence with:

- original offset/VA-derived PDB line and rebuilt offset;
- containing basic-block start;
- direct symbol, indirect kind, or virtual slot;
- inserted/deleted/replaced/equal status;
- high/medium/low confidence;
- normalized argument/setup context for replacements.

The alignment uses a weighted dynamic program over target identity, occurrence
frequency, neighboring calls, setup instructions, and block membership. Repeated
calls therefore receive lower confidence unless their context agrees. VC5 forms that
load a vtable, then load a slot into a register, then `call reg` are recognized in
addition to direct `call dword [vtable+slot]` forms.

Call alignment remains diagnostic. Low-confidence replacements are not proof that two
particular source call sites correspond.

## Basic-block alignment

`--block-map` prints normalized block pairs, call fingerprints, branch successors,
and confidence. The normal report includes exact-block instruction coverage, the
strongest exact block islands, and the first context-aware divergence. Blocks are
aligned using normalized instruction shape, contained calls, terminator shape, and
successor count. Exact promotion still uses positional bytes and relocation identity,
not block similarity.

Functions with multiple original body ranges are decoded at each range's real VA while
retaining combined comparison offsets. This prevents out-of-line case/EH blocks from
being treated as accidental fallthrough and keeps PDB lines/direct-call targets valid.

## Focused ranges

Use `--range` to inspect one source/assembly band without printing the complete maps:

```bat
python tools\check_function.py --va 004F21F0 --range +0340-+0380
python tools\check_function.py --va 004F21F0 --range orig:004F2530-004F2570
python tools\check_function.py --va 004F21F0 --range rebuilt:+0330-+0380
```

The default side is original. Values prefixed with `+` are combined function offsets;
values at or above the function VA are interpreted as real addresses. For discontiguous
original functions, real VAs are mapped to their combined comparison offsets. The report
selects every aligned basic-block row overlapping the range and prints the complete
original block alongside its aligned rebuilt partner, including PDB lines and bytes.

## Output levels

`--detail auto|concise|full` controls console volume. `auto` selects concise mode for
functions at least 2 KB while the full report remains in `build/diff/<slug>.txt` and
JSON. Concise giant-function output shows metric deltas, the highest-priority hard
call discrepancy, and the first block/instruction/call contexts. `--verbose` implies
full detail and also shows subprocess output.

Iteration output ranks the top three improved and regressed ranges instead of listing
neutral churn. Raw edit cost remains available for compatibility, but the console now
also reports bounded edit cost (normalized by both input lengths) and bounded
resynchronized similarity (equal resynchronized bytes divided by the larger input).

Use `--refresh-original` only when the pinned original inputs changed. Original
extraction is otherwise cached.

Core diagnostics also have committed golden fixtures in
`tests/fixtures/function_diagnostics_golden.json`. They cover exact virtual calls,
wrong-slot replacement, a unique missing call between anchors, and discontiguous body
ranges in addition to focused unit tests.
