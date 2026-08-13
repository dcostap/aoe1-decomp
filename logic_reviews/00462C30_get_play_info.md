# Logic review: 00462C30 `TMusic_System::get_play_info`

## Phase transition

The main agent suspended exact matching after bounded work exhausted natural
control-flow forms for two MCI call sites and one shared status tail.

Candidate: `src/scratch/00462C30_get_play_info.cpp`.

Current validation:

- original size: 309 bytes; rebuilt size: 328 bytes;
- frame, saved registers, and both MCI calls align;
- the remaining drift is duplicated status-store and return-tail topology.

## Semantic questions

1. Verify output initialization and guard returns.
2. Verify active-track output copy behavior.
3. Verify both MCI calls and the status-record fields.
4. Verify MCI failure and default-type returns.

## Review rounds

### Round 1 — concurrent blind cohort, 2026-08-13

- `sa-a9ad649f` — `openai-codex-secondary/gpt-5.6-luna`, xhigh
- `sa-74ae2394` — `openai-codex-secondary/gpt-5.6-luna`, xhigh

Both reviewers found no definite behavioral difference.

They verified:

- output initialization, device-closed return, and inactive-track return;
- active track, filename, loop, and position copies;
- `music_type` 1 and 2 MCI calls using device ID, command `0x814`, and flags
  `0x102`;
- `dwItem` at status-record offset `+8` and `dwReturn` at `+4`;
- status-position write on success and zero retention on MCI failure;
- the default type return.

The reviewers accounted for pending stack arguments. They rejected misleading
decompiler labels for the status fields.

## Final decision

No behavioral uncertainty remains for supported MCI use. The remaining
difference is shared-tail control-flow drift. Promote to `src/verified_logic`.
