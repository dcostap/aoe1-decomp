# 00411E20 `ResearchAIModule::removeOldTechTree`

- PDB source: `airchmod.cpp`, lines 225 to 236.
- Original size: 66 bytes.
- Former owner: `src/matching/00411E20_removeOldTechTree.cpp`.

The former isolated owner matched exactly.

The function deletes every item before the embedded list item. It then restores both self links and clears the item count.

The source now lives in `src/airchmod.cpp`. This move removes the isolated owner only. It does not change the recovered behavior.
