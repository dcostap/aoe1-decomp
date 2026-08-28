# Tech module recovery

## Context

The PDB contribution is `0050B840-0050D456` from
`.\Release\tech.obj`. It contains 33 normal functions in address order.
The PDB has no function line records for this contribution. Therefore, a
PDB source path cannot identify its owner functions.

The CodeView type dumps prove these records:

- `Tech_Tree` is a class of size `0x3C`.
- `Tech_Player_Tree` is a class of size `0x08`.
- `TRIBE_Tech` is a class of size `0x0C`.
- `TRIBE_Player_Tech` is a class of size `0x10`.

`include/tech.h` owns the four records. `src/tech.cpp` owns all normal
functions in contribution order. It uses `RGE_Player`, `TRIBE_World`,
`RGE_Effects`, and `TRIBE_History_Info` from their providers.

Sources:

- `orig/age1_x1.pdb`
- `inventory/pdb/function_source_map.csv`
- `inventory/types/dumps/Tech_Tree.txt`
- `inventory/types/dumps/Tech_Player_Tree.txt`
- `inventory/types/dumps/TRIBE_Tech.txt`
- `inventory/types/dumps/TRIBE_Player_Tech.txt`

## Current nonexact functions

`0050C730` keeps ordinary local variables. The prior exact form used a
synthetic local record. It is not a source fact. Direct-source validation
gives 27 differing bytes, or 3.0752%.

`0050CA9E` keeps ordinary scan variables. The prior exact form used a
synthetic local record. It is not a source fact. Direct-source validation
gives 33 differing bytes, or 8.4399%.

`0050CC25` remains accepted drift. The remaining difference is stack-slot
allocation for the integer attribute and float cost locals. Direct-source
validation gives 22 differing bytes, or 6.5868%.

`0050CE68` keeps ordinary scan variables. The prior exact form used a
synthetic local record. The executable proves that `changed` is cleared and
never set. Direct-source validation gives 28 differing bytes, or 5.2830%.

The other 29 normal functions pass direct-source validation with `MATCH` and
`0.0000%`. The compiled object has no compiler-generated entry in this range.

## Validation blocker

`validate_candidate_tu.py` requires one PDB source path for every owner.
The PDB rows for this contribution have empty source paths and symbols. It
cannot validate or register this module until new CodeView source evidence is
available. The direct VC5 compile remains valid build evidence.
