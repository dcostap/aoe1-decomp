# Per-function logic-review ledgers

This directory contains the full versioned review history for functions that
have formally left ordinary exact-matching work and entered semantic
verification. Use one file per function:

```text
logic_reviews/<function-slug>.md
```

The designated main agent owns these files. Matching workers and blind reviewers
must not edit them. Blind reviewers must not read them or receive their contents.

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

The ledger is ordinary Markdown tracked by Git. Do not add source hashes,
confidence percentages, voting scores, or a separate manifest. Git records the
source and ledger changes. Version each completed review/adjudication round with
its related source changes so unresolved handoffs remain durable. Folder
placement remains the function's status marker.
