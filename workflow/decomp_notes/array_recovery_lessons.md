# Array recovery evidence

## Scope

These results support the recovery priorities in `workflow/vc5_lessons.md`.
They do not approve the shared array repair for integration.
The tested main base is `767991a0b6ca728d3f009431454ad822926d4945`.
All source proposals remain in the isolated resize worktree.
No game executable was run.

## Complete natural source

- Tactical save uses ordinary loops instead of handwritten growth blocks and member-function pointers.
  `004EF4E0` reports `MATCH`, `0.0000%`, and 3,230 bytes.
  State: `resize-order-complete-save`.
- Dropsite handling uses a normal loop and direct array insertion.
  `004E3C90` reports `MATCH`, `0.0000%`, and 509 bytes.
  Direct argument substitution alone did not match.
  State: `resize-order-natural-dropsites`.
- Natural template removal loops and caller array operations restore `004F1090`.
  It reports `MATCH`, `0.0000%`, and 765 bytes.
  Caller-only replacements did not match with the earlier helper definition.
  State: `resize-order-natural-removal`.
- Strategy save uses public array operations and the PDB's 257-byte temporary string.
  `004E9DA0` retains `MATCH`, `0.0000%`, and 902 bytes.
  State: `resize-order-public-strategy-save`.
- Complete strategy update loops reduced the difference to 13 bytes.
  Restoring the original initializer order produced `MATCH`, `0.0000%`, and 1,391 bytes at `004E9820`.
  State: `resize-order-public-strategy-update`.

These results support complete helper and caller recovery, not a rule that every simpler form will match.
The later combined strategy-query rewrite still failed its target check.

## Access evidence

Original PDB field list `0x1683` marks all four `ManagedArray<int>` storage fields protected.
It also marks `resize` protected.
The generated layout dump presents public fields; that presentation is not access evidence.
The two repository copies of the original game PDB have the same SHA-256:

`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`

Event `e616d2e02dce06caaa6d728a34fbfc49e0197692ba6ea886b238fd242bb555ae` preserves the type dump and complete source snapshot.

## Safety limits

The complete removal-state comparison covers 90 modules and 3,584 emitted functions.
It identifies 81 changed function records, including byte changes and reference-description changes.
That list is not a correctness result.

A static counterexample proves that changed saves in `0046B5E0` alter stack-overlapping input.
The original returns zero; the candidate returns one.
Event `f87a083b0594809d2421ca55004e44f9cbbaaf68f8c7e041b2209ea8d4cd9f79` preserves the checked proof.
The separate [command repair note](command_order_repair.md) records another failed stack-overlap proof.

Target experiment states freeze target dependencies, not every changed caller source.
Automatic candidate patches therefore need a separate complete source snapshot for shared repairs.
Do not treat target success, equal instruction counts, or a smaller difference as integration approval.
