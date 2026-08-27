# rdlg_lst.cpp module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\rdlg_lst.cpp`.
- Source: `src/rdlg_lst.cpp`.
- Header: `include/rdlg_lst.h`.
- Flags: `config/flags/default.rsp`.

## Context gate

- PDB source module: proved by the generated `rdlg_lst.cpp` packet.
- Source lines and order: proved by the packet. The ten normal owners span
  lines 38-375 in increasing address and source order.
- Owning class: proved by PDB symbols. Nine owners are `RGE_Dialog_List`
  methods; `0047EAA0` is the module's cdecl compare helper.
- Address sequence: proved by the packet:
  `0047E670`, `0047E6B0`, `0047E830`, `0047E8C0`, `0047E8F0`, `0047E910`,
  `0047EAA0`, `0047EAD0`, `0047EAF0`, and `0047EB60`.
- Exact anchors: proved by the constructor and destructor, the list setup and
  allocation calls, the compare import, and the typed list and player offsets.
- Nearby generated owner: `0047E690` is the compiler-generated scalar
  deleting destructor. It has no handwritten source owner.

## Migration

The module now has one direct source file and one module-local header. The
source keeps all ten normal definitions in PDB order. It has no wrapper,
source-bank include, fallback declaration, context macro, or raw address
residue. The header owns the period class hierarchy, record layout, imported
compare function, global game pointer, and declarations needed by the module.

`0047E910 create_object_list` retains its reviewed accepted-drift source. The
only difference is the adjacent XOR and MOVSX scheduling span recorded by the
prior source attempt. The instructions write independent registers, and no
call, memory access, or branch occurs between them.

The setup source retains its typed list-info reference because the prior exact
finish proved that the reference and declaration-only panel surface are one
required group for the exact 376-byte result.

## Validation and regressions

- Generated packet: `build/source_reunification/terra2/rdlg_lst/rdlg_lst_cpp/packet.{json,txt}`.
- Candidate validation: `build/candidate_tus/rdlg_lst/report.txt` compiled the
  direct source and matched the constructor, setup, destructor, get-list-id,
  compare, sort, and calc-list-line owners. Its first proposal used the wrong
  protected access encodings for `create_list` and `get_cur_id`; both focused
  checks below corrected and matched those symbols. The generated deleting
  destructor matched. The accepted-drift owner retained its five-byte
  scheduling difference.
- Focused checks, all with `--no-history`: `0047E670`, `0047E8F0`, and
  `0047EB60` each report `Result: MATCH` and `0.0000%`, with matching owner,
  boundary, calls, and relocations.
- Migration regressions: none for the nine registered exact owners. The
  accepted-drift owner remains a five-byte adjacent XOR/MOVSX scheduling span.

## Blockers

- None known before constrained validation.
