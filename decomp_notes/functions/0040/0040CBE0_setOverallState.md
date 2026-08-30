# Function notes: 0040CBE0 `setOverallState`

## Earlier notes from `decomp_notes/functions/0040/0040CBE0_setOverallState.md`

This section is historical. Use the status query for current state.

## 0040CBE0 `EmotionalAIModule::setOverallState`

- PDB source: `aiemomod.cpp`, lines 134 to 187.
- Original size: 382 bytes.

### Recovery record

The switch case body order is `0`, `4`, `1`, `3`, `2`, then `5`. The reviewed `EmotionalAIModule` layout places `stateValue` at offset `0xF4`. The final module retains both facts.
