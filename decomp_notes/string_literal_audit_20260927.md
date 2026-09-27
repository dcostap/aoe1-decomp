# Linked string review, 2026-09-27

The byte check masks relocated references. A matching function can therefore
refer to a different string in the rebuilt image. Compare linked strings with
the original image before accepting a string-sensitive source change.

An exploratory scan found 79 functions with different sequences of referenced
printable bytes before the AI setup repair. This count is not a count of defects.
The scan treats four-byte version fields and adjacent string arrays as strings.
It can also assign data after a function boundary to the wrong function.
Check each call site against the original image and its argument type.

Confirmed differences repaired in source:

- `src/aibldmod.cpp`, `loadBuildList`: the original `sscanf` format starts
  with `%c`, not a space. Blank input then reaches the category check.
- `src/tplayer.cpp`, `loadAIInformation` and
  `intelligentBuildListAndRulesSelection`: the original selects the city-plan
  name `NONE` and rule-set marker `RandomGameSpecialized`. Its messages also
  differ. The city-plan name changed saved-game bytes.
- `src/basegame.cpp`, `setup_cmd_options`: the original searches for `NO MOUSE`
  and for `=` in each valued option name. The separate `LOGAI` flag check does
  not use `=`. The old value searches could advance past a missing `=`.
- `src/sprite.cpp`, text sprite constructor: the original scan format has one
  fewer `%hd` before the floats. Do not add a destination to compensate:
  preserve the original argument list and partial-scan behavior.
- `src/m_s_obj.cpp`, `setup`, and `src/tech.cpp`, constructor: the original
  formats use `%d` for the three 32-bit help fields, not `%ld`. The tech
  constructor also reads a tech index with `%d` into a short stack slot.
  Assembly at `0050BC38` through `0050BC50` confirms this unusual width.
- `src/scr_ach.cpp`, `set_mode`: the original formats the value as `%d%%`.

`shape_version_110` in `src/game_globals.cpp` is a four-byte integer,
`0x30312E31`. The scan reads past its fourth byte and joins neighboring data.
Do not add a NUL byte to this field based on the scan.

The `Panel_ez.cpp` scan formats differ in spaces between conversion fields.
`sscanf` treats each format-space run as a request to skip input spaces.
This finding does not change the parsed fields.

Remaining findings include debug messages, logs, diagnostics, and other
input formats. They need call-site review. A differing printable string alone
does not prove a game defect. A matching code result alone does not prove
equal linked data or equal gameplay behavior.

The local `save-check` trace still fails at world update 56,688. The first
different RNG record is 4,034,042: the original next calls `tplayer.cpp:607`;
the rebuilt next calls `asprite.cpp:183`. Both return 20,949 at that record.
The first state difference is update 56,694. The save written at update 8,785
matches after the AI setup repair. The first RNG call-site difference does not
identify the function that caused the earlier state change. Keep this replay
failure open; do not claim a whole-game parity pass.
This replay report is under
`build/runtime/traces-20260927T222151457247Z-00957913927f/report.json`.
