# Agentic matching workflow

The late corpus is dominated by large functions whose behavior, ABI surface, and
VC5 source shape cannot safely be solved as one undifferentiated problem. This
document describes the coordination and evidence tools intended for parallel
agent work.

The original EXE remains the behavior oracle. A generated dossier, generated
type dump, Ghidra output, checkpoint score, or agent lease never overrides the
normal exact-match and review rules in `AGENTS.md`.

## Select a target without flooding context

```bat
python tools\query_project_status.py --unclaimed --normal --no-blockers ^
  --unleased --smallest --triage --leases --limit 12
```

`--triage` adds PDB line span, frame, EH, unique direct-call targets, virtual
slots, saved registers, and decompiler availability only after sorting and
`--limit`. Use it to shortlist candidates, then open at most two or three full
packets. An explicitly assigned VA needs no candidate-shopping phase.

## Start or inspect a target session

`target_session.py` keeps advisory per-target leases under the ignored
`build\target_sessions\` directory. Agents sharing one working tree can use the
leases to avoid editing the same target concurrently.

```bat
python tools\target_session.py start --va 005204A0 --owner AgentName --budget 10
python tools\target_session.py status --va 005204A0
python tools\target_session.py list --active
python tools\query_project_status.py --remaining --normal --unleased --leases
```

Use a stable owner name for the life of the session. An unexpired lease blocks a
different owner unless they explicitly use `--force`. A paused or released
session retains its notebook but no longer blocks another owner.

The budget counts **meaningful interpreted hypotheses**, not compiler launches.
It applies to the current claim; the target's cumulative probe history remains in
the notebook across pauses and owner changes. The briefing fingerprints source,
flags, compiler configuration, and repo-local includes before calling recorded
checker metrics current.
After a checker run, record what was tested and what the result means:

```bat
python tools\check_function.py --va 005204A0 --checkpoint direct-member-guard
python tools\target_session.py probe --va 005204A0 --owner AgentName ^
  --kind liveness --checkpoint direct-member-guard ^
  --note "replaced history alias with direct member reload; frame unchanged, first divergence moved into inner loop"
```

Valid probe kinds are `baseline`, `behavior`, `abi`, `layout`, `control-flow`,
`liveness`, `context`, `flags`, `variant`, `restore`, and `other`. Use `baseline`
for the first successful reconstruction check. A `restore` check is recorded but
does not consume the meaningful-hypothesis budget.

Prefer the integrated form for normal work. It verifies the active owner, runs
the checker, creates a checkpoint, snapshots source/flags and emitted-code
identity hashes, detects repeats of earlier codegen, and records metric deltas
only after a completed check:

```bat
python tools\target_session.py check --va 005204A0 --owner AgentName ^
  --kind liveness --note "direct member reload probe" -- --detail concise
```

When stopping:

```bat
python tools\target_session.py pause --va 005204A0 --owner AgentName ^
  --reason "needs a proven player/history layout before more source-shape work"
```

`--note` is accepted as an alias for `--reason`. A default autonomous matching
assignment uses a budget of ten meaningful hypotheses unless the user requests a
different bound; the complete short-prompt contract is in `AGENTS.md`.

The scratch-file attempt log remains the durable project notebook. Session files
are local coordination state and are not committed; copy durable conclusions into
the scratch header before pausing or releasing a target.

## Generate a binary-evidence dossier

```bat
python tools\target_dossier.py --va 005204A0
python tools\target_dossier.py --va 005204A0 --class-name Time_Line_Panel
```

The command writes:

- `build\dossiers\<slug>.txt`
- `build\dossiers\<slug>.json`

The dossier collects:

- ordered direct/indirect/virtual calls and nearby push/cleanup clues;
- candidate `this`-relative accesses with widths and read/write direction;
- absolute memory references joined to generated global metadata when possible;
- ESP/EBP accesses normalized to entry ESP while stack changes remain provable;
- writes/address-taking in incoming parameter homes;
- PDB line attribution;
- nonempty PDB line-change evidence bands joining calls, candidate fields,
  normalized stack references, globals, and block starts;
- a narrow conflict check between fixed observed offsets and a generated class
  size.

### Evidence limits

The dossier is deliberately conservative:

- `this` fields come from register-alias tracking and are **candidates** to verify
  in the original assembly;
- entry-relative stack coordinates account for explicit pushes, pops, and stack
  adjustments plus direct callees with one proven `ret N` cleanup;
- normalization deliberately stops after unresolved direct/indirect cleanup or
  stack rebasing, so some rows remain raw/unknown;
- generated class size and global names are reference metadata, not behavior
  truth;
- indexed accesses do not prove an array bound or complete object extent;
- the tool does not infer true inheritance, local lifetimes, source expressions,
  or why VC5 selected a register.

Use the dossier to expose contradictions and missing facts, not to auto-generate a
speculative shared class.

## Query ABI and declaration provenance

Before redeclaring a helper, global, or class surface, query the generated
metadata together with living exact-source evidence:

```bat
python tools\query_abi.py --symbol rge_read
python tools\query_abi.py --symbol strategicNumber
python tools\query_abi.py --class TRIBE_Player
python tools\query_abi.py --global save_game_version
python tools\query_abi.py --va 00480080 --json
```

By default, source references come only from `src\matching`. Use
`--include-nonexact` when scratch and accepted-drift context is diagnostically
useful; those rows are labeled separately. Symbol queries can find generated
class methods as well as function/global/type names. Declaration-like rows are
grouped by exact textual spelling with separate exact/nonexact occurrence counts,
so linkage/calling-convention disagreements remain visible instead of being
silently merged.

Provenance levels are intentionally explicit:

- function records are PDB/Ghidra inventory metadata;
- class layouts, virtual declarations, and globals are generated reference
  candidates with their existing confidence/evidence fields;
- matching-source rows prove that a declaration or context participated in one
  exact function;
- nonexact rows are working hypotheses only.

An exact local stub may be deliberately narrow or codegen-active. Do not promote
it into a shared header solely because `query_abi.py` found it. Seek agreement
across exact donors and verify symbol identity, calling convention, widths,
virtual slot, and object layout against the binary.

`query_abi.py` additionally normalizes declaration candidates by linkage, calling
convention, member/free form, return type, parameter types, and trailing member
`const`. Parameter names no longer split otherwise identical candidates, while C
versus C++ linkage and calling-convention disagreements remain separate.

## Find exact function donors

```bat
python tools\find_function_donors.py --va 004407A0 --limit 20
```

The donor finder starts from exact matching owners and ranks a bounded candidate
pool using same PDB TU, inferred owner class, constructor/destructor/helper family,
calling convention, size, name tokens, direct-call targets, virtual slots, raw
memory displacements, EH-frame class, frame size, and saved registers. Accepted
drift is opt-in and labeled.

This is a discovery ranking. It does not prove that two functions shared a source
file declaration surface, and raw displacement similarity is intentionally low
weight. Read the donor source and packet before reusing its declarations/context.

## Phase-gated work

Treat large targets as four phases:

1. **Behavior** — calls, predicates, memory effects, and stack cleanup.
2. **ABI/layout** — signatures, virtual slots, object offsets, sizes, globals, and
   EH ownership.
3. **Structure** — frame, local topology, loops, blocks, and call ordering.
4. **Exact codegen** — localized source-shape, declaration-context, and variant
   experiments.

Do not start broad variant labs while calls are missing, direct targets are wrong,
the frame is unexplained, or field layout is contradictory. The session briefing
uses the checker's recorded workflow stage as its primary recommendation. Treat
that checker stage as authoritative for workflow: structural reconstruction comes
before register coloring even when the frame and per-target call counts match.

Equal call counts or an empty per-target count delta do not prove ordered call
parity. Read call similarity and the `delete`/`insert`/`replace` site counts. For
example, 47 original and 47 rebuilt calls with `-2/+2` gaps remain structurally
unresolved; use `--call-map-unmatched` before claiming an aligned call set.

## Use focused diagnostics before full maps

The checker already provides bounded views for giant functions:

```bat
python tools\check_function.py --va 005204A0 --detail concise
python tools\check_function.py --va 005204A0 --call-map-unmatched --map-limit 40
python tools\check_function.py --va 005204A0 --block-map-differences --map-limit 40
python tools\check_function.py --va 005204A0 --stack-map --no-build
python tools\check_function.py --va 005204A0 --range orig:+0300-+0380
python tools\check_function.py --va 005204A0 --history
```

Use full call/block maps only when the filtered view is insufficient. Repeated
diagnostic queries reuse fingerprinted artifacts when source, flags, compiler, and
repo-local includes are unchanged.

## Region experiments are still whole-function experiments

`variant_lab.py` supports localized splice templates:

```bat
python tools\variant_lab.py --va 005204A0 --template build\temp\gate.tpl.cpp ^
  --splice-base src\scratch\005204A0_draw_timeline.cpp ^
  --splice-start "// LAB START gate" --splice-end "// LAB END gate"
```

For an understood localized mismatch, focus scoring and preserve hard invariants:

```bat
python tools\variant_lab.py --va 004524E0 --template build\temp\sprite_loop.tpl.cpp ^
  --splice-base src\scratch\004524E0_setup.cpp ^
  --splice-start "// LAB START sprite" --splice-end "// LAB END sprite" ^
  --focus-range +0490-+04B0 --require-size --require-frame --require-call-set
```

The reports retain ineligible groups but rank invariant-preserving groups first.
Focused diff fields and invariant failures are written to `variants.tsv`,
`groups.tsv`, group reports, summaries, and the run manifest. Exact outputs are
copied to `matches\` only when all requested gates pass.
Stable-prefix and gained/lost exact-block deltas are computed only when the
current checker baseline passes the same source/flags/compiler/include fingerprint
freshness check used by target sessions; stale baselines are reported as
unavailable rather than compared.

The lab edits one source region but compiles and compares the whole function.
This is intentional: VC5 register allocation, stack homes, block placement, and
branch distances are whole-function effects. Do not treat a separately compiled
loop/helper as proof of the parent function's codegen.

## Parallel roles for difficult targets

Several agents may investigate one large function, but one owner should edit the
canonical scratch source at a time. Useful independent roles are:

- evidence reconstruction;
- ABI/type/global validation against exact sibling donors;
- donor-TU/header context investigation;
- localized codegen experiments;
- final exactness and policy review.

Analysts should return evidence or proposed patches to the target owner rather
than creating competing scratch owners.

## Stop conditions

Pause rather than churn when:

- behavior or call ownership is still uncertain;
- an observed offset contradicts the active class model;
- several meaningful probes collapse to the same broad mismatch family;
- a later edit changes the prologue globally without clarifying the cause;
- the remaining mismatch is broad and cannot be reviewed as safe drift.

Record the blocker and the next fact needed in the source header. A bounded,
well-documented pause is useful project state; a broad unexplained accepted drift
is not.
