---
name: truth-source-lookup
description: Shared lookup workflow for finding and mapping symbols across original truth artifacts (asm/decomp/ground-truth headers). Use when a task needs authoritative source-of-truth evidence.
---

Use this skill when you need to find authoritative truth for a function/class/struct/global, especially when input may be vague, partial, or descriptive.

Repository structure optimization (decomp project specific):
- Truth lives primarily in paired module dumps under `src/game/decomp`:
  - `<module>.cpp.decomp`
  - `<module>.cpp.asm`
- When module is known, search only that pair first.
- Use `Offset: 0x...` anchors in decomp files to land directly on function slices.
- Use asm around the same offset for signedness, copy size, and branch opcode validation.
- Pull `src/game/include/*.h` only when call signatures, field offsets, or layout checks are required.

Primary sources (in order):
1. `src/game/decomp/*.asm`
2. `src/game/decomp/*.decomp`
3. `src/game/include/*.h`

Do not treat reconstructed implementation files as source of truth for parity decisions.

Workflow:
1. Normalize the request
- Accept single symbol, multiple symbols, or descriptive query.
- Produce candidate names/aliases (class-qualified names, decorated/undecorated variants, nearby naming patterns).

1b. Choose lookup mode
- Module-known mode: shard to one module pair (`<module>.cpp.decomp` + `<module>.cpp.asm`).
- Module-unknown mode: do narrow discovery to identify candidate modules first, then switch to module-known mode.

2. Locate candidate definitions/references
- Search asm/decomp for exact and fuzzy matches.
- Capture offsets, function labels, and nearby related symbols.
- Locate matching declarations/layout hints in headers.

3. Expand one hop for dependencies
- Pull directly relevant callees/types/globals referenced by the target.
- Avoid deep uncontrolled graph expansion unless asked.

4. Resolve ambiguity
- If multiple matches exist, rank by evidence strength and context fit.
- Explicitly mark uncertain mappings and what additional context would disambiguate.

5. Prepare verifier-ready exhibits
- Build compact evidence packets suitable for per-function audit:
  - exact truth pointers (file + offset/line)
  - short excerpt text
  - why the excerpt is relevant to parity
- Prefer exhibit-style outputs over large dumps.

6. Emit packet-friendly evidence keys
- For each target function, include stable keys:
  - `target.function`
  - `target.module`
  - `truth.decomp.offset`
  - `truth.decomp.excerpt`
  - `truth.asm.offset_or_range`
  - `truth.asm.excerpt`
  - `truth.header.path_and_excerpt` (if needed)
  - `notes.assumptions`

Suggested output style (not strict):
- Request interpreted
- Best-match candidates
- Evidence list:
  - file path
  - line/offset/label
  - brief reason it matters
- Related symbols to inspect next
- Confidence and caveats

Quality bar:
- Prefer precise, high-signal evidence over large noisy dumps.
- Include enough context to enable immediate decompilation/audit work.
- Be scope-disciplined: avoid broad exploration unless explicitly requested.
- Do not dump full decomp functions when a compact offset-anchored excerpt is sufficient.
