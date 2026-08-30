# Function notes: 00525D20 `start_game`

Module notes: `decomp_notes/tribegam_module.md`.

## Recovered attempt history

<!-- recovered:8a7311a301205a2effb9 -->
### `912332e8f578` `src/matching/00525D20_start_game.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00525D20 TRIBE_Game::start_game (299 B)
// PDB source: tribegam.cpp, lines 2586-2638
// Attempt log:
// baseline: natural start-game flow with period string-copy, status-message,
// world/scenario, and member-call surfaces reconstructed from the packet and
// same-TU donors; size/frame/call set matched, with only three LEA bytes off.
// declaration-order and register/local-result probes were codegen duplicates.
// 260-byte and 252-byte buffers changed the frame (104h/0fch); union overlay
// changed the copy topology; all were rolled back.
// exact: using the named 256-byte info_file directly (rather than the inferred
// decompiler +4 prefix) reproduces the original stack address and all 299 bytes.
// Main-agent audit restored the donor-backed scenario/world/base-game virtual
// slot declarations; the natural start-game source remains exact.
```
<!-- end-recovered:8a7311a301205a2effb9 -->
