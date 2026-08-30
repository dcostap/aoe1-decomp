# Function notes: 004D2290 `~TRIBE_Action_Make_Tech`

Module notes: `decomp_notes/tact_tek_module.md`.

## Recovered attempt history

<!-- recovered:9434d8f8f90f99771ca3 -->
### `c6c70134c94b` `src/scratch/004D2290_TRIBE_Action_Make_Tech.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech destructor
// VA: 004D2290
// PDB: tact_tek.cpp:49-64
// EH-framed, needs /GX
// FLAGS: config/flags/004D2290_TRIBE_Action_Make_Tech.rsp
// added /GX rsp after extract showed EH-framed original; current source now extracts full size but has broad register/layout drift
// likely next fixes mirror matched siblings: accurate RGE_Action_Object layout, no fake extra vptr padding, and typed RGE_Base_Game member-call surface
// applied sibling object layout and typed RGE_Base_Game notify; edit diff improved, but EH prolog still has extra EDI save and destructor tail/register topology remains broad
```
<!-- end-recovered:9434d8f8f90f99771ca3 -->
