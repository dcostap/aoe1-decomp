# Video stage names

## Scope

`src/tribegam.cpp` defines local `TRIBE_VIDEO_STAGE_*` macros for its video sequence.
The cleanup names the constructor sentinel, playback arguments, saved-stage switch labels, and stopped-stage sentinel.
It replaces all 14 numeric stage uses in this module.
These values select the next clip or screen. They are not unique AVI file identifiers.

The names are new descriptive names, not recovered original constants.
The PDB supplies the existing `cur_video`, `video_num`, `save_vid_num`, and `goto_next_video` names.
The cleanup keeps those names, declarations, types, and scopes.

The constants remain in the existing source module because no other handwritten module uses these stage values.
Numeric macros avoid new enum declarations and new header inputs.
The earlier object-state cleanup showed that both can change VC5 output outside the intended edits.
See [object lifecycle states](object_lifecycle_states.md).

## Original instruction evidence

The behavior source is the repository-local original expansion-beta executable.
Its SHA-256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
Fresh extraction covers these functions:

| Address | Function | Relevant observation |
| --- | --- | --- |
| `00521120` | `TRIBE_Game` constructor | Stores `-1` in the current-stage field. |
| `00521790` | `setup` | Calls `start_video` with stage 0 and `logo1`. |
| `005237B0` | `start_video` | Stores the supplied stage before attempting playback. |
| `00523B10` | `stop_video` | Saves the stage, resets it to `-1`, and selects its completion path. |
| `00525D20` | `start_game` | Calls stage 3 with the scenario's `Cine_PreGame` array. |
| `00526DC0` | `do_game_over` | Calls stage 4 with either `Cine_Victory` or `Cine_Loss`. |

The original stop function resets the field at instruction `00523B3F`.
Its switch reads six targets from `00523EF8`.
The targets are `00523C1E`, `00523C4B`, `00523C78`, `00523CA2`, `00523D7E`, and `00523C78`.
Thus, stages 2 and 5 use the same menu-return block.
That block calls `start_menu` at `00523C7A`, then closes the program if menu creation fails.

Original strings at `0058B980`, `0058BC00`, and `0058BBF8` are `logo1`, `logo2`, and `introx`.
The instructions select stages 0, 1, and 2 for those clips.

## Values

| Value | Macro suffix | Established role |
| --- | --- | --- |
| -1 | `NONE` | No current video stage after construction or stopping. |
| 0 | `FIRST_LOGO` | Plays `logo1`; completion can advance to the second logo or return to the menu. |
| 1 | `SECOND_LOGO` | Plays `logo2`; completion can advance to the intro or return to the menu. |
| 2 | `INTRO` | Plays `introx`; completion returns to the menu. |
| 3 | `PRE_GAME` | Uses `Cine_PreGame`; completion shows a mission description when applicable, or creates the game screen. |
| 4 | `POST_GAME` | Uses the victory or loss clip; completion selects the achievements path when a world exists. |
| 5 | `MENU_RETURN` | Shares the intro's menu-return block. Its clip and producer remain unidentified. |

The recovered source has no `start_video` call that supplies stage 5.
The name states its proven completion behavior, not a guessed clip or historical purpose.
Stages 3 and 4 can select different scenario clips. Do not treat the stage as a file index.

`start_video` can select completion paths when a file is missing, playback is unavailable, or multiplayer prevents playback.
The cleanup preserves those paths. It does not require a video window before handling the saved stage.

## Storage and interface preservation

PDB layout evidence places `cur_video` at offset `0xBF0` with four-byte `int` storage.
Original start and stop instructions read and write that field as a dword.
The field and `start_video(int, char*)` signature remain unchanged.
`stop_video(unsigned char)` also retains its parameter type.

The `goto_next_video` argument remains a Boolean control, separate from the stage values.
Only the two logo branches test it. Other stage branches retain their existing behavior.
The cleanup does not change these Boolean literals, Windows messages, playback flags, music tracks, or program modes.
It also keeps switch fallthrough, call order, filenames, error handling, and original debug paths and line values.

## Validation

The pre-cleanup source commit is `06631c5a598ef4f8a2d948eb078b4e71f32c53d2`.
Reports remain under `build/video-stage-cleanup/`.

| Check | Result | Report |
| --- | --- | --- |
| Registry configuration | Passed with `--no-build-checks`; this does not check compiled artifacts. | Tool output. |
| Pre-cleanup full function audit | Exit 0. All 225 groups compiled; 5,013 exact claims passed. | `before/functions/report.json` |
| Post-cleanup full function audit | Exit 0. All 225 groups compiled; 5,013 exact claims passed. | `after/functions/report.json` |
| Before/after object comparison | Exit 0. All 225 non-debug object payloads retain identical bytes, sizes, flags, and relocation targets. | `object-comparison.json` |
| Post-cleanup owner audit | Exit 0. No owner or class/free mismatches among 5,013 matching functions. | `after/owners.json` |
| Source-scope check | Exit 0. Restoring all 14 operands and removing the constant block restores the exact baseline source. | `source-scope.json` |
| Original switch and string check | Read the switch table and all three startup filenames from the original image. | `original-stage-data.json` |
| Whitespace and line endings | `git diff --check` and the line-ending check passed. | Tool output. |

The object comparison checks allocated symbols and external relocation symbol names.
It identifies private compiler labels by section and offset, not generated serial numbers.
It excludes debug sections and COFF timestamps.
Its script does not cover every auxiliary COFF record or undefined-symbol detail.

Both full audits cover 5,426 normal functions.
The remaining 413 observations retain their categories: 217 logic-approved, 140 accepted-drift, 44 mismatches, and 12 boundary problems.
Their existing limits remain. External linked storage remains unproved by these object checks.

An independent `openai-codex/gpt-6.1-sol` reviewer used `high` thinking and found no actionable issues.
The reviewer checked all six extractions, the switch table, startup strings, source restoration, fingerprints, and 450 object hashes.
Additional checks found unchanged COMDAT auxiliary records, common/undefined symbols, weak-symbol fallback data, and relevant COFF headers.
These checks supplement the comparison script's stated limits. The reviewer did not compile or run games.

No linked executable, automated regression tests, or gameplay tests have run for this cleanup.
Static instruction evidence and output comparison do not establish full runtime or original-game agreement.
