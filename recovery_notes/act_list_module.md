# `act_list.cpp` recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\act_list.cpp`.
- Source: `src/act_list.cpp`.
- Header: `include/act_list.h`.
- Flags: `config/flags/00404200_create_task_action.rsp`.
- Normal owners: 25. The PDB line order is `00403EA0` through `004048C0`.

## Ownership

`RGE_Action_List` owns this module. The source uses canonical Action, task,
object, combat-master, file-I/O, and Unit-AI declarations. It has one source
owner. It has no context header, wrapper, copied class, raw vtable, or padding
carrier.

The PDB source path, class-qualified symbols, line bands, and address sequence
prove this owner. `004041C2` and `0040496E` are padding-only neighbors. They do
not have source bodies here.

## Status

The following owners remain exact in the direct compiland: `00403EA0`,
`00403EC0`, `00403ED0`, `00403F40`, `00403F60`, `00403FA0`, `00403FC0`,
`004044A0`, `004044F0`, `00404540`, `00404710`, `00404760`, `00404770`,
`00404790`, `004047C0`, `004047F0`, `00404810`, `00404840`, `00404850`,
`00404860`, `00404890`, and `004048C0`.

`00404200` remains accepted drift. Its canonical typed task-action factory has
489 differing bytes and one boundary escape. `00404590` remains accepted drift.
It has two differing bytes. `00404610` remains scratch. It has 179 differing
bytes. The scratch source keeps the typed allocation, type scan, queue insert,
and notification behavior. It does not retain codegen-only source forms.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/act_list_natural_proposal.json --output-dir
build/candidate_tus/act_list_natural` compiled the direct source.

All 22 matching owners report `MATCH`, `0.0000%`, correct ownership,
relocations, and boundaries. The three nonexact owners have correct owner and
relocation identity. The source-module manifest records their honest status.

The shared `config/translation_units.json` entry still names the removed
wrapper. The parent integration pass must update it to `src/act_list.cpp` and
register the direct owners.
