# Source-cleanup report: `src/tdlg_lst.cpp`

## Handoff

- Module: `src/tdlg_lst.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source-cleanup commit: `fd42d8b84e0caa87db497a15acf9d97dd90719d9`
- Branch: `cleanup/staging-20260915-162`
- Changed files:
  - `src/tdlg_lst.cpp`
  - `decomp_notes/source_cleanup/wave03/tdlg_lst.md`
- Paired header `include/tdlg_lst.h` was read but not changed.

The report is committed after the source-cleanup commit. The handoff response
records the final report commit hash.

## Scope and evidence

This cleanup covers the six source methods registered for `src/tdlg_lst.cpp`.
The registry is `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tdlg_lst.cpp.json`.
I inspected the selected procedure packets for every assigned VA:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050B450_TRIBE_Dialog_List.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050B4A0_create_list.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050B4D0_create_build_list.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050B5E0_create_train_list.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050B700_create_research_list.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050B820_get_cur_id.txt`

I also inspected the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB source is `C:\msdev\work\age1_x1\tdlg_lst.cpp`.
I preserved source order, declarations, scopes, types, storage, calls, casts,
literals, and control flow.

The scalar deleting destructor at `0050B470` and the destructor at `0050B490`
have PDB records but no source method in this file. They were not changed.

## Name recovery coverage

### `0050B450` — `TRIBE_Dialog_List::TRIBE_Dialog_List`

The PDB records `this` in ECX and the `name` parameter at stack offset `+0x4`
with type `char*`. The source already uses the recovered spelling `name`.

### `0050B4A0` — `create_list`

The PDB records only `this` in ECX. The source has no parameter or local name
to recover. The original packet confirms the three dispatch values and targets.

### `0050B4D0` — `create_build_list`

The PDB records `this` in ECX, `item_num` as `short`, and `item_list` as
`Item_Avail*`. The source now uses recovered original `item_list` instead of
the previous `avail_list` spelling. The packet also lists `item_list` and
confirms the same `Item_Avail` use in the original code.

The source names `player` and `i` have no procedure-scoped PDB records. I did
not force a mapping from optimized registers or reused stack storage.

### `0050B5E0` — `create_train_list`

The PDB records `this` in ECX, `item_num` as `short`, and `item_list` as
`Item_Avail*`. The source now uses recovered original `item_list` in the
declaration, initialization, call, and list-copy loop.

The source names `player` and `i` have no procedure-scoped PDB records. I left
them unchanged because the evidence does not prove different original names.

### `0050B700` — `create_research_list`

The PDB records `this` in ECX, `item_num` as `short`, and `item_list` as
`Item_Avail*`. The source now uses recovered original `item_list` in the
declaration, initialization, call, and list-copy loop.

The source names `player` and `i` have no procedure-scoped PDB records. I left
them unchanged because the evidence does not prove different original names.

### `0050B820` — `get_cur_id`

The PDB records only `this` in ECX. The source has no parameter or local name
to recover. The existing switch form remains unchanged. The registry-selected
exact-lottery record is documented at
`C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/functions/0050/0050B820.md`.

## Recovered and existing names

Recovered original spellings used or retained in this module are `name`,
`item_num`, and `item_list`, based on the procedure-scoped PDB records above.
The cleanup changes only `avail_list` to the recovered `item_list` spelling in
all three list-builder methods.

`player` and `i` remain existing descriptive or unresolved local names. Their
original PDB mappings are not reliable. Public functions, classes, members,
globals, types, signatures, calling conventions, and ABI symbols were not
renamed.

## Constants, resources, and comments

No new constant or enum was added. Existing values remain unchanged:

- `100`, `101`, and `102` select build, train, and research lists. The original
  `create_list` packet shows the subtract/decrement dispatch sequence.
- `4` is passed to `is_group_selected` in the build-list path.
- `0x76` is passed as the group argument to `interface_item_avail`.
- `sizeof(rdlg_list_info)` remains the allocation element size. The paired
  header proves the record size is `0x66` bytes.

The `0x76` argument is not a string-resource lookup. It is an interface group
argument. The packet's generated numeric language match does not establish a
resource role. No resource ID was investigated or changed, so no DLL, language,
text, fallback, or lookup-path record applies.

No source comment was added or changed.

## Output-risk review

- The edit changes local identifier spelling only.
- Types, scopes, declaration order, storage, calls, literals, control flow,
  layouts, relocations, and symbol identity remain unchanged.
- The three recovered `item_list` names are procedure-scoped PDB names. The
  rename changes debug naming only; generated code was not checked in this
  phase.
- No header, resource macro, helper, structural rewrite, assembly, or bug fix
  was added.

## Shared requests and unresolved questions

No header change is requested from owner 18. The paired header remains
unchanged. No shared resource declaration is requested from root.

The original names for `player` and `i` remain unresolved because the
procedure-scoped PDB omits them. The Ghidra packet's `local_4` and `local_8`
labels are optimized scratch or argument storage, not reliable source
mappings. I did not change declarations to force those mappings.

## Validation status

I ran evidence inspection, `git diff --check`, and a complete source diff
review. Compilation, matching, audits, and tests were **NOT run**. I did not
run a compiler, build, game, or validation command. Generated code, program
data, relocations, and final output equality remain unvalidated.
