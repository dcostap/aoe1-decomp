# Function notes: 004629B0 `end_fade`

## Earlier notes from `decomp_notes/functions/0046/004629B0_end_fade.md`

This section is historical. Use the status query for current state.

## 004629B0 end_fade

The original source is `music.cpp`, lines 958 through 965.

The function clears the fade state. It restores saved volume. It restarts a track range or named file when one exists.

The source uses the executable-proven range-or-file guard.
