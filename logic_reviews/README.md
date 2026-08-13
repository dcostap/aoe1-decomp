# Per-function logic-review ledgers

This directory contains the full versioned review history for functions that
have formally left ordinary exact-matching work and entered semantic
verification. Use one file per function:

```text
logic_reviews/<function-slug>.md
```

The designated main agent owns these files. Matching workers and blind reviewers
must not edit them. Blind reviewers must not read them or receive their contents.
Phase-readiness auditors may use matching attempt/history evidence but are not
blind reviewers and do not count toward a review cohort.

Each ledger should contain:

1. **Phase transition** — why exact matching was suspended, current checker
   metrics and structural differences, cumulative matching work, and open
   semantic questions at entry.
2. **Review rounds** — the complete returned report from every reviewer, with the
   reviewer's assigned scope.
3. **Main-agent adjudication** — each finding classified as confirmed,
   unresolved, or cleared, with binary evidence and reasoning.
4. **Integrated changes** — bounded source fixes made by the main agent and the
   resulting validation.
5. **Further rounds** — fresh independent review after meaningful changes.
6. **Final decision** — remaining nonsemantic differences, confirmation that no
   substantive finding remains open, and the rationale for promotion or return
   to scratch work.

Use practical executable reachability when classifying a finding. Theoretical
observation by a debugger, injected code, or an absent runtime-introspection
routine does not make compiler bookkeeping substantive. Clear such a difference
only after bounded review finds no reachable shipped observer and shows no
cleanup, handler, call, state, result, exception, or fault outcome changes.
Record that evidence and its search scope. Exact matching remains byte-strict.

Before the first formal round, the main agent should normalize the candidate away
from exact-matching experiment residue and toward plausible original-developer
C/C++: canonical types and fields, explicit statements, natural control flow,
and typed calls. Comma-expression scheduling tricks, fake volatility, raw vtable
casts, manual offsets, and decompiler scaffolding should not survive merely
because they improve byte metrics. Retain an odd form only when executable
evidence proves it expresses real behavior, and document that evidence in this
ledger. Record validation after normalization even when the nonsemantic diff
worsens.

The ledger is ordinary Markdown tracked by Git. Do not add source hashes,
confidence percentages, voting scores, or a separate manifest. Git records the
source and ledger changes. Version each completed review/adjudication round with
its related source changes so unresolved handoffs remain durable. Folder
placement remains the function's status marker.

Launch each formal round as a complete concurrent cohort of at least two fresh
reviewers. If the user-supplied concurrency ceiling cannot provide two read-only
slots together, defer the round rather than running a one-person pseudo-cohort.
