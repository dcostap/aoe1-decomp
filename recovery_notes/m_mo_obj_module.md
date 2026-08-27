# m_mo_obj.cpp module merge

- PDB source: `m_mo_obj.cpp`.
- Source: `src/m_mo_obj.cpp`.
- Header: `include/m_mo_obj.h`.
- Flags: `config/flags/00451A20_RGE_Master_Moving_Object.rsp`.

## Transition

This module has 14 normal owners.

The source keeps the PDB order.

The header owns the moving-master declarations.

The merge removes fragments, wrapper code, and context switches.

The merge does not keep isolated object byte results.

The function entries keep their reviewed matching status.

The status is not a byte-equality claim.

## Check state

VC5 compiles the merged source.

No grouped exact check ran during this merge.

The old isolated destructor had four different bytes.

The old delta and percent methods each had nine different bytes.

Run grouped exact checks after final module recovery.
