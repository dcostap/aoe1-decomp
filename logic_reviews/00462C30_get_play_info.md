# Logic review: 00462C30 `TMusic_System::get_play_info`

## Phase transition

The behavior review is complete. The natural typed reconstruction now matches
in the authentic `music.cpp` translation unit.

Owner: `TMusic_System::get_play_info` at `00462C30`.

Current validation:

- original and rebuilt size: 309 bytes;
- original boundary: `00462C30-00462D64`;
- rebuilt owner: `?get_play_info@TMusic_System@@QAEHPAEPAH11PAD1PAK@Z`;
- frame: `0x10`; saved registers: `ebx`, `ebp`, `esi`, `edi`;
- both indirect `mciSendCommandA@16` calls align at `+0xEC` and `+0x116`;
- grouped bytes, calls, CFG, boundary, and owner match exactly;
- strict positional diff: `0` bytes (`0.0000%`).

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

No behavioral uncertainty remains for supported MCI use. The source is a
natural VC5-era C++ reconstruction in the authentic `music.cpp` context.
Fresh exact validation resolves the former shared-tail concern. Keep the
reviewed output ownership, `dwItem` query field, full status-record call, and
fault order.
