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

The four records use public access. They have no vptr or virtual slot.

`include/tech.h` owns the four records. `src/tech.cpp` carries the 33
reconstructed bodies in contribution order. It is not a proven PDB source
owner. The bodies use `RGE_Player`, `TRIBE_World`, `RGE_Effects`, and
`TRIBE_History_Info` from their providers.

The source manifest is `config/source_modules/tech.json`.
Every body has status `observed`. No body has a PDB source or symbol owner.

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

## No-line PDB validation

`inventory/pdb/module_streams/0027_tech.json` records the original PDB
module stream. The PDB hash is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The raw `cvdump -s -M039` dump identifies `Release\tech.obj`. It has zero
`S_GPROC32` records.

This proves only that the PDB has a Tech compiland. It does not identify an
owning function or decorated symbol for any VA. The 29 byte-equal functions
are observed. They are not registered as exact owners.

`validate_candidate_tu.py` compiled the complete direct source. Its report
has 29 observed byte matches, four observed mismatches, and no generated
entry.
