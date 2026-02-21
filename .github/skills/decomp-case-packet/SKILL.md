---
name: decomp-case-packet
description: Build compact, verifier-ready case packets for decomp parity audits so subagents avoid redundant repository re-reading.
---

Use this skill when preparing any verifier subagent call.

Goal:
- Ensure verifier receives all required exhibits up front.
- Minimize redundant truth-source searching inside verifier runs.

Case packet template:

1) Target metadata
- `target.function`: fully qualified function name
- `target.impl_path`: implementation file path
- `target.impl_range`: line range in implementation file
- `target.module`: decomp module name (for example `com_hand.cpp`)

2) Candidate exhibit
- `candidate.body`: exact code under audit (verbatim)
- `candidate.notes`: any temporary stubs/guards/intentional deviations

3) Truth exhibits
- `truth.decomp.path`
- `truth.decomp.offset`
- `truth.decomp.excerpt` (compact)
- `truth.asm.path` (if branch/memcpy/signedness sensitive)
- `truth.asm.offset_or_range`
- `truth.asm.excerpt` (compact)
- `truth.header.path` + `truth.header.excerpt` (only if layout/signature relevant)

4) Audit request
- `audit.depth`: `lite` or `deep`
- `audit.focus`: short checklist (for example signedness, payload size, turn math)
- `audit.open_questions`: explicit unresolved assumptions

5) Output contract requested from verifier
- verdict
- exhibits used
- mismatches grouped by blocker/risky/low
- concrete minimal fixes

Rules:
- One function/slice per packet whenever possible.
- Avoid mixing unrelated functions in one packet.
- Keep excerpts short but sufficient to decide parity.
- Prefer module-sharded truth references (`src/game/decomp/<module>.cpp.decomp/.asm`).

Quick checklist before sending verifier call:
- Candidate body included verbatim
- At least one decomp exhibit included
- ASM exhibit included when offset/branch/sign risk exists
- Header exhibit included when struct/call-layout risk exists
- Audit focus explicitly stated
