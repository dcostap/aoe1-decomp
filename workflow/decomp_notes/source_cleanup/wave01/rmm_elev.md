# Source cleanup: `src/rmm_elev.cpp`

## Handoff

- Module: `src/rmm_elev.cpp`
- Branch: `cleanup/staging-20260915-15`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source-cleanup commit: `7457c117b3fe2547b95686ff348c8c17489c61e2`
- Changed files:
  - `src/rmm_elev.cpp`
  - `workflow/decomp_notes/source_cleanup/wave01/rmm_elev.md`

The source correction is committed in the final source-cleanup commit above. This correction round also has a separate report commit.

## Scope and evidence

I read the repository contract and the complete source-cleanup, source-comment, resource-ID, owner, assignment, and testing guides. I read `include/rmm_elev.h` and did not edit it.

I inspected every registry VA in `config/functions/src/rmm_elev.cpp.json`:

- `004846C0` constructor
- `00484700` `generate`
- `004847C0` `check_start_elevation`
- `004848A0` `check_elevation`
- `00484A40` `generate_modifiers`
- `00484B30` `fig_chance`
- `00484B50` `count_map_tiles`
- `00484B90` `link_stack_randomly`
- `00484C80` `remove_area_from_lists`
- `00484D00` `base_elevation_generate`

I inspected each matching packet under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`. I also inspected all procedure-scoped PDB parameter, local, and register records for these VAs in `inventory/pdb/scoped_symbols.json`. Each procedure has a `this` register record for `RGE_RMM_Elevation_Generator*`.

Reference fingerprints inspected during evidence review:

- Original executable `orig/empiresx.exe`: SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline executable: SHA-256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- Preserved baseline `rmm_elev.obj`: SHA-256 `e3e0b4cbd3df42e0e9df9656c767aa9f6a18c0d160912d558190ea7a9f09c755`.
- Runtime `runtime/language.dll`: SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Runtime `runtime/languagex.dll`: SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

The module has no resource lookup. I did not extract resource strings.

## PDB name recovery

The sections below list every PDB record and its source mapping. I did not change types, storage, scope, declaration order, function symbols, calls, or control flow.

### `004846C0` — constructor

PDB stack parameters:

- `in_map`, `RGE_Map*`, `+0x4`
- `parent_module`, `RGE_Random_Map_Module*`, `+0x8`
- `in_info`, `RGE_Elevation_Info*`, `+0xc`

Renamed the three definition parameters from `map`, `parent`, and `info` to these exact PDB names. The header was not changed.

### `00484700` — `generate`

The PDB has no stack symbols or parameters. The source keeps `row`, `column`, `tile`, `index`, and `line`. These names have no procedure-scoped PDB mapping, so I do not claim them as recovered originals.

### `004847C0` — `check_start_elevation`

PDB parameters are `x`, `y`, `base_terrain`, `base_elevation`, and `spacing`. The source now uses all five exact names.

PDB locals are `index1` and `y1`. `index1` shares stack slot `+0x8` with parameter `y`, so I do not claim that mapping. `y1` has a distinct slot and the source keeps that name. Other locals have no PDB record and remain unchanged.

### `004848A0` — `check_elevation`

PDB parameters are `target`, `x`, `y`, `spacing`, `base_terrain`, and `base_elevation`. Renamed `elev`, `radius`, `terrain`, and `min_elev` to the exact PDB names. `x` and `y` already matched.

PDB locals are `index1`, `y1`, `x1`, and `count`. `index1` and `count` have distinct slots and the source keeps those names. The `x1` and `y1` records share stack slots with parameters and occur across separate source blocks, so I do not claim those mappings. I preserved the existing declarations and scopes. Other locals have no PDB record.

### `00484A40` — `generate_modifiers`

The only PDB local is `modifier`. The source already uses that name. No other local has a procedure-scoped PDB record.

### `00484B30` — `fig_chance`

PDB parameters are `count`, `x`, and `y`. Renamed `p0`, `p1`, and `p2` to these exact names. The function uses only `count`, as shown by the original assembly.

### `00484B50` — `count_map_tiles`

The PDB parameter is `terrain`. Renamed `tile_type` to `terrain`.

### `00484B90` — `link_stack_randomly`

The PDB parameter is `loc_stack`. Renamed `param_1` to `loc_stack`.

The PDB has no other local records. Existing `stack`, `width`, `height`, `max_x`, `max_y`, `last`, `node`, and loop locals remain unchanged.

### `00484C80` — `remove_area_from_lists`

PDB parameters are `x`, `y`, and `spacing`. Renamed `radius` to `spacing`. `x` and `y` already matched.

PDB locals are `x1` and `y_index`. The PDB `x1` record shares stack slot `+0x8` with parameter `y`, so I kept the existing descriptive name `start_x` and do not claim this mapping. The distinct-slot `y_index` record maps to the existing row loop name. Other locals have no PDB record and remain unchanged.

### `00484D00` — `base_elevation_generate`

The PDB parameter is `info_line`, `RGE_Elevation_Info_Line`. Renamed `line` to `info_line` throughout the definition.

PDB locals are `clump_size`, `in_zone`, `y`, `loc_stack`, `x`, `done`, `stack`, `max_y`, `max_x`, and `chance`. The source already uses the exact names except for `in_zone`; renamed `cost` to `in_zone`. The existing `clump_size` declarations keep their scopes.

The source also has `chance_count`, `clump_count`, `area`, `stack_ptr`, and loop `count` locals. They have no procedure-scoped PDB records. I did not force mappings or change their declarations.

## Constants, resources, and comments

No new constants or resource-ID names were added. The module has no resource lookup. Numeric values such as `0xFF`, `100`, `101`, `0xFA`, and `0x7FFF` remain unchanged because no shared symbol with proven identical meaning was found for these uses.

No new source comment was needed. The existing module comment remains unchanged. It records the typed ownership model for map tiles and stack nodes.

## Code-generation-sensitive points

The change renames parameters and locals only. It also applies 1TBS braces to function definitions and keeps the stack-removal call on one line. It preserves source order, scopes, types, storage, casts, evaluation order, literals, string data, calls, direct targets, and public signatures.

The source string `C:\\msdev\\work\\age1_x1\\rmm_elev.cpp` remains unchanged. No `__LINE__` or other line-dependent macro appears in this module. Generated code, data, relocations, and call-target identity remain unvalidated.

## Header requests

No header edit is requested. `include/rmm_elev.h` needs no declaration change because definition parameter names can differ from the unchanged declaration names. No resource-ID mapping is requested from the root owner.

## Validation status

Compilation, matching, audits, tests, and games were **not run**. I ran only evidence inspection, source review, Git diff review, and `git diff --check`. Compiler output equality and runtime behavior remain unvalidated.

## Correction round

Root review requested one presentation correction. The source now keeps this call on one line:

```cpp
this->remove_stack_node(this->stack_offsets[y_index] + column);
```

The source correction is commit `7457c117b3fe2547b95686ff348c8c17489c61e2`. I inspected the full source diff for this round and found no non-name token changes. I also reviewed the complete assigned diff against the base commit. No other source or report content changed in this round except the documented report updates.

Compilation, build, matching, audit, test, and game commands were not run.
