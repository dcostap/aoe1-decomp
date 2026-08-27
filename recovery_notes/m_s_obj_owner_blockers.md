# Master Static owner blockers

## Status

Master Static source remains held.

The earlier 20 matching rows used a context with copied foreign layouts. They
are historical evidence only. They do not support direct-source promotion.

The current direct candidate is
`build/candidate_tus/m_s_obj_audit_current/report.txt`. VC5 first stops at
`src/m_s_obj.cpp:168` because `RGE_Damage_Sprite_Info` is incomplete. Its only
full declaration is in macro-gated `m_co_obj_context.h`. That file is not a
canonical owner.

## Other owner gaps

The current headers do not yet compose:

- `sprite.h` duplicates Sound and Base Game declarations.
- The clipping owner does not publish `DClipInfo_List::AddGDINode` or its
  globals.
- `basegame.h` does not publish the Base Game global used by the candidate.

Two later sites are source and ABI questions. They are not include repairs.
The candidate calls `RGE_Static_Object::copy_obj` with five arguments, while
the canonical declaration takes one. It also assigns an
`RGE_Armor_Weapon_Info*` to `char*`.

Do not add an overload or cast without PDB and direct-target evidence.

## Reopen order

1. Publish `RGE_Damage_Sprite_Info` through its canonical owner.
2. Publish the clipping `AddGDINode` surface and its globals.
3. Reconcile the Sprite, Sound, and Base Game owner headers.
4. Resolve the two source and ABI questions.
5. Run a fresh complete 23-owner candidate check.

Until then, the direct source has no current exact promotion evidence.
