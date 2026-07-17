# Function checker diagnostics

`python tools/check_function.py --va <VA>` is both the exact promotion gate and
the normal iteration guide.

The concise report is deliberately ordered from global invariants to local bytes:

1. rebuilt meaningful code size versus the original size;
2. stack frame and entry callee-save set;
3. instruction-shape alignment and longest aligned run;
4. direct/virtual call sequence, per-target call-count deltas, and coarse CFG signals;
5. strict positional byte equality;
6. change impact relative to the previous run;
7. a workflow stage and the next highest-value diagnostic hunk.

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

For structural mismatches, the report lists aggregate call-target count differences
as `rebuilt/original`, ordered by the largest absolute gap. It also reports which
target counts changed in the latest iteration. These counts expose missing or extra
behavioral calls but do not replace the ordered first-call divergence: equal totals
can still hide reordered calls, shared-tail placement changes, or wrong control flow.

Use `--verbose` for subprocess details and `--refresh-original` only when the
pinned original inputs changed. Original extraction is otherwise cached.
