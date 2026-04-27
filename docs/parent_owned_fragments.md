# Parent-owned fragments

Some inventory `FUN_...` entries are real bytes in the game executable but are not
independent source functions. They are basic blocks that Ghidra/PDB packeting split
out because control flow has non-contiguous ranges, switch landing pads, shared
case bodies, or early error tails.

These entries use corpus bucket `parent_owned_fragment` and are listed in:

- `config/parent_owned_fragments.txt`

## Meaning

A parent-owned fragment:

- is game code, not CRT/toolchain code;
- is not presumed handwritten assembly;
- often has no prolog and may rely on live registers or stack locals from the
  containing function;
- may jump outside its packet range into a shared continuation or epilogue;
- should not get its own normal `src/scratch/<VA>_...cpp` target.

The correct matching unit is the parent function named in the manifest. When the
parent function exact-matches, the fragment bytes are covered by that parent.

## Manifest format

Each non-comment line is:

```text
<fragment-va> <parent-va> <parent-name> <kind/reason>
```

Example:

```text
00502451 00502310 checkForAttackResponseBuildInsertions switch_case_codelet
```

This means VA `00502451` is a switch/case codelet inside
`checkForAttackResponseBuildInsertions` at `00502310`.

## Current reviewed clusters

- `0047F00C`, `0047F076` are internal error/tail blocks owned by
  `0047EE90 RESFILE_open_new_resource_file`.
- `00502451` through `005024B3` listed in the manifest are switch case codelets
  or a shared case body owned by
  `00502310 checkForAttackResponseBuildInsertions`.
- `00536912`, `00536957` are switch/traversal continuation blocks owned by
  `00535FE0 view_function`.

## Workflow rules

- Exclude `parent_owned_fragment` rows from normal target selection.
- Do not move these fragments to `toolchain_supplied` or `asm_special` just
  because they are not normal one-function targets.
- Do not force standalone C++ or inline asm to make fragment checks green.
- Reconstruct and validate the owning parent function instead, e.g.:

```bat
python tools\check_function.py --va 00502310
```

The status dashboard reports these fragments separately from the normal corpus,
with `parent_va`, `parent_name`, and `parent_fragment_reason` columns in
`project_full_status.csv`.
