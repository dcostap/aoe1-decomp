# Function notes: 004CE070 `update`

## Earlier notes from `decomp_notes/functions/004C/004CE070_update.md`

This section is historical. Use the status query for current state.

## 004CE070 `TRIBE_Action_Convert::update`

- PDB source: `tact_cnv.cpp`, lines 311 to 522.
- Original size: 906 bytes.

### Recovery record

The recovery fixed the action, player, world, object, and master layouts from the original memory effects. It then matched the target lookup guards, ally path, state dispatch, nested task results, conversion gate, random chance path, notification arguments, and work-rate product order.

The PDB handler order for states 4, 11, 6, 7, 1, and 13 recovered the call and control-flow shape. Named canonical virtual methods and direct field ownership completed the standalone body.

After natural `TRIBE_Action_Convert` alignment cleanup, the grouped candidate differs by one byte. Ownership, relocations, and boundaries match. The owner is scratch pending a separate review. The source does not add padding to recover the prior result.
