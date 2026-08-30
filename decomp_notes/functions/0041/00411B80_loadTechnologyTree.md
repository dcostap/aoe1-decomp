# Function notes: 00411B80 `loadTechnologyTree`

## Earlier notes from `decomp_notes/functions/0041/00411B80_loadTechnologyTree.md`

This section is historical. Use the status query for current state.

## 00411B80 `ResearchAIModule::loadTechnologyTree`

- PDB source: `airchmod.cpp`, lines 159 to 206.
- Original size: 637 bytes.
- Former owner: `src/matching/00411B80_loadTechnologyTree.cpp`.

The former isolated owner matched exactly with `/GX`.

`rc` has five elements. `sscanf` writes the item ID to `rc[0]` and four costs to `rc[1]` through `rc[4]`. This model gives the required object lifetime and stack use.

The function creates a temporary `ResourceItem` from the four costs. It passes that object by value to a new `TechnologyItem`. The item is inserted before the embedded list item. A `.tmp` file is removed after loading.

The null-name branch is unreachable for the embedded name array. The source retains it because the executable proves this branch order.

The source now lives in `src/airchmod.cpp`. This move removes the isolated owner only. It does not change the recovered behavior.
