---
name: truth-source-lookup
description: Shared lookup workflow for finding and mapping symbols across original truth artifacts (asm/decomp/ground-truth headers). Use when a task needs authoritative source-of-truth evidence.
---

Use this skill when you need to find authoritative truth for a function/class/struct/global, especially when input may be vague, partial, or descriptive.

Primary sources (in order):
1. `src/game/decomp/*.asm`
2. `src/game/decomp/*.decomp`
3. `src/game/include/*.h`

Do not treat reconstructed implementation files as source of truth for parity decisions.

Workflow:
1. Normalize the request
- Accept single symbol, multiple symbols, or descriptive query.
- Produce candidate names/aliases (class-qualified names, decorated/undecorated variants, nearby naming patterns).

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
