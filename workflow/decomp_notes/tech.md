# Tech module recovery

## Current review

The latest review repairs two comparison-literal types and checks all instructions in the four remaining functions.
See `workflow/decomp_notes/tech_stack_review.md` for the stack proof and the caller-alias review.
`0050C730` and `0050CA9E` are completed accepted-drift results after the
caller-alias review in their function ledgers. `0050CC25` and `0050CE68`
remain open because their follow-up review is not complete.

Original public symbols and section contributions now establish all 33 entry identities.
See `workflow/decomp_notes/tech_public_identity_review.md` for the evidence, compiler results, and remaining limits.
The older missing-symbol conclusions below describe the previous evidence set, not the current build route.

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

The function registry is `config/functions/src/tech.cpp.json`.
No function has a proved PDB source or build symbol.

Sources:

- `orig/age1_x1.pdb`
- `inventory/pdb/function_source_map.csv`
- `inventory/types/dumps/Tech_Tree.txt`
- `inventory/types/dumps/Tech_Player_Tree.txt`
- `inventory/types/dumps/TRIBE_Tech.txt`
- `inventory/types/dumps/TRIBE_Player_Tech.txt`

## Historical direct-source results

`0050C730` keeps ordinary local variables. The prior exact form used a
synthetic local record. It is not a source fact. Direct-source validation
gives 27 differing bytes, or 3.0752%.

`0050CA9E` keeps ordinary scan variables. The prior exact form used a
synthetic local record. It is not a source fact. Direct-source validation
gives 33 differing bytes, or 8.4399%.

The `0050CC25` candidate differed only in stack-slot allocation.
Direct-source validation found 22 differing bytes, or 6.5868%.

`0050CE68` keeps ordinary scan variables. The prior exact form used a
synthetic local record. The executable proves that `changed` is cleared and
never set. Direct-source validation gives 28 differing bytes, or 5.2830%.

The other 29 normal functions passed the historical direct-source comparison.
The compiled object had no compiler-generated entry in this range.

## No-line PDB validation

`inventory/pdb/module_streams/0027_tech.json` records the original PDB
module stream. The PDB hash is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The raw `cvdump -s -M039` dump identifies `Release\tech.obj`. It has zero
`S_GPROC32` records.

This proves only that the PDB has a Tech compiland. It does not identify an
owning function or decorated symbol for any VA. The 29 byte-equal results do
not prove source ownership or a build route.

`validate_candidate_tu.py` compiled the complete direct source.
Its report had 29 byte matches, four mismatches, and no generated entry.

## Follow-up target results

The retained natural source probes reduce the four target results without
changing their boundaries, ABIs, call sets, or external memory effects:

| VA | Function | Current differing bytes | Status |
|---|---|---:|---|
| `0050C730` | `tech_cost` | 15 | accepted drift |
| `0050CA9E` | `check_tech_cost` | 16 | accepted drift |
| `0050CC25` | `start_research` | 8 | open |
| `0050CE68` | `check_for_new_tech` | 14 | open |

Each result retains the original size and frame. No target is exact. The
remaining differences are private stack displacement coloring. The caller-alias
review completes the accepted-drift decisions for the first two rows. The
stack-overlap and linked-storage review remains open for the latter two rows.
