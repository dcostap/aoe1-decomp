# Function notes: 0042EC10 `FreeOptions`

Module notes: `decomp_notes/com_hand_module.md`.

## Translation-unit context

- PDB module: `Com_hand.cpp`, lines 6622-6631.
- Natural owner: `TCommunications_Handler::FreeOptions` in `src/com_hand.cpp`.
- Original owner symbol: `?FreeOptions@TCommunications_Handler@@IAEXXZ`.
- The wave found that the header declared this method public and emitted `QAE`.
  Coordinator review restored protected access and the original `IAE` symbol.
- Original body order is: test `OptionsData`, clear
  `PlayerOptions.DataSizeToFollow`, call canonical `operator delete`, then clear
  `OptionsData`.

## Current result

- Fresh natural TU evidence: 38 bytes, no frame, one direct
  `operator_delete` call, and the expected three this-relative accesses at
  `0x4`, `0x171C`, and `0x4`.
- The fresh TU emits the expected instruction sequence and canonical
  `??3@YAXPAX@Z` relocation.
- Coordinator review moved the declaration into the PDB-proven protected
  section. The owner is now `IAE` and matches the original symbol.
- Final focused result: `MATCH`, `0.0000%`, 38/38 bytes.
- Final grouped audit: `build/audits/integration/wave10-comhand-header/`.
  All 99 prior registered owners match, and this target is the only exact
  unregistered row before promotion.

## Recovered attempt history

- The existing natural body already preserves the original cleanup order and
  canonical DirectPlay-era CRT delete surface. No source body change survived
  this assignment.
- Fresh TU rebuild completed after the stale evidence warning. It confirmed the
  body bytes and call relocation, but it could not satisfy owner-symbol
  validation because access belongs to the shared class declaration.

## Open questions

- None for this target.

## Next useful approaches

- Preserve the protected declaration and natural cleanup body.

## Worker updates

- 2026-08-29, `wave10-comhand`: Retained the existing natural body. Fresh TU
  evidence confirms exact control flow and canonical delete relocation. The
  only blocker is the public-vs-protected owner declaration, which cannot be
  fixed within the assigned source body. No source file changed.
- Pause with the required blocker reason was attempted once. It failed before
  state validation because `target_session.py` timed out waiting for
  `build/target_sessions/sessions.lock`. Do not retry the global lock here.
- Coordinator review corrected only the shared access declaration. The target
  then matched exactly without a body change.
