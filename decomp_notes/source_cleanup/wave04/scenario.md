# Scenario source-cleanup report

## Scope and commits

- Module: `src/scenario.cpp`
- Registry: `config/functions/src/scenario.cpp.json`
- Header read only: `include/scenario.h`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source commit: `cd138ad8ff071550dd4cc712602d6e902b0451e9`
- Report delivery commit: recorded by Git after this report is committed
- Changed files in the source commit:
  - `src/scenario.cpp`
- Changed files in the report commit:
  - `decomp_notes/source_cleanup/wave04/scenario.md`

The source commit contains only the assigned source file. The report commit contains only this assigned report.

## Procedure evidence and coverage

I inspected the registry, the procedure-scoped PDB records, and the original packets.
The PDB source is `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB module is `.\\Release\\scenario.obj`.
The selected packets are under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`.

The registry selects 48 procedures. Each selected VA has a PDB record and an original packet.
The PDB also contains non-registry records for the scalar deleting destructor, `get_object_pointer`, and `rehook`.
Those records were not edited.

The selected VA coverage is:

```text
0048AB10, 0048ABB0, 0048AC70, 0048ACA0, 0048ACC0, 0048AD60, 0048AE10,
0048B5A0, 0048B6C0, 0048B910, 0048B950, 0048B960, 0048B9A0, 0048B9E0,
0048BA20, 0048BA60, 0048BAD0, 0048BB40, 0048BBB0, 0048BBC0, 0048BBE0,
0048BC00, 0048BC20, 0048BC60, 0048BC70, 0048BC80, 0048BC90, 0048BCA0,
0048BCB0, 0048BCC0, 0048BEC0, 0048C0D0, 0048C0E0, 0048C2F0, 0048C360,
0048C370, 0048C390, 0048C3B0, 0048C3D0, 0048C3E0, 0048CC20, 0048CC50,
0048CC80, 0048CCB0, 0048CCC0, 0048CCD0, 0048CD10, 0048CE40
```

## Recovered original names

I restored the PDB names for parameters and locals where the type, stack slot, and use gave a reliable mapping.
The original mixed spelling remains unchanged.

- Header procedures use the recovered names `scenario_info`, `infile`, `outfile`, `desc_size`, and `header_size`.
- Scenario constructors use `w`, `infile`, and `length`.
- Setters use `str`, `which_player`, `WithExtension`, `ver`, `which`, `t`, `c`, `val`, `which`, and `Name` as recorded by the PDB.
- File getters use `which_player`, `WithExtension`, `temp_path`, `none_str`, and `random_str`.
- `GetPlayerPosture`, player getters, `Set_conquest_victory`, `add_description`, `Set_message`, and `Get_message` use the PDB names `which`, `flag`, `new_text`, and `message`.
- `InitializeTextValues` retains the PDB names `default_string` and `none_string`.
- `save` uses the PDB names `outfile`, `temp_file_name`, `length`, and `file_name`.

I did not force the PDB `val` records in the load constructor or `save` into source declarations.
Those records have an `int` type and do not map safely to the existing `text` storage or `float* version` use.

I assigned these cleanup names where the PDB gave no safe source mapping:
`description_text`, `description_source`, `description_size`, `player_index`, `picture`, `slot`, `remaining`,
`new_picture`, `old_picture`, and `message_copy`.
These are cleanup names, not claims about original source spelling.
The loop declarations, types, scopes, storage, and statement order remain unchanged.

## Constants and comments

I read the pinned VC5 headers before replacing numeric SDK values.

- `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H` proves the `_open` flags and permission masks.
  The three read-only binary opens now use `_O_BINARY` instead of `0x8000`.
  The three temporary-file opens now use `_O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY` instead of `0x8301`.
  Their mode now uses `_S_IREAD | _S_IWRITE` instead of `0x180`.
- `SEEK_SET` and `SEEK_END` replace the proven `lseek` origin values `0` and `2`.
- `C:/Program Files (x86)/DevStudio/VC/Include/WINDEF.H` defines `MAX_PATH` as `260`.
  It replaces the proven `GetTempPathA` size `0x104`.

The source keeps the original resource lookups and lookup order.
It keeps the original `free(0)` call in `Set_message`; the original packet proves this no-op branch.
It also keeps the existing cross-field checks in `Get_CityPlan` and `Get_player_AI`.
No behavior repair or structural rewrite was made.

## Resource evidence and shared-file request

`InitializeTextValues`, `Get_BuildList`, `Get_CityPlan`, and `Get_player_AI` call the virtual `rge_base_game->get_string` path.
`RGE_Base_Game::get_string` loads the base string table from `language.dll`.
The game override can load `languagex.dll` first and then fall back to the base path.

The resource inspection used the original runtime files and reported:

| Module | Type | Language | ID | Payload | Proven role |
| --- | --- | --- | --- | --- | --- |
| `runtime/language.dll` | `RT_STRING` | `0x0409` | `0x2775` | `" <None> "` | None sentinel for scenario text and file names |
| `runtime/language.dll` | `RT_STRING` | `0x0409` | `0x277B` | `"Random"` | Random default and file-name sentinel |

Both IDs are missing from `runtime/languagex.dll` and the original XPack `languagex.dll` inspected for this task.
The payload does not prove original macro names.

The shared header owner should add these new cleanup names to `include/resource_ids.h`:

- `IDS_SCENARIO_NONE` for `0x2775`.
- `IDS_SCENARIO_RANDOM` for `0x277B`.

These names are cleanup proposals, not recovered original macro names.
The source worker did not edit the shared header or replace the calls until the owner reviews the mapping.

## Possible generated-code effects

The changes rename parameters and locals, apply 1TBS formatting, add required CRT includes, and use SDK macros with the same values.
They preserve types, scopes, storage, casts, call targets, evaluation order, statement order, resource lookup order, and public signatures.
The source was not compiled, so generated-code stability remains unverified.

## Validation and open items

I reviewed the complete source diff and ran `git diff --check`.
I did not run a compiler, build, matching check, audit, test, or game.

Open items:

- The shared resource-ID owner must review and add the two requested names.
- The PDB `val` records remain unresolved because their recorded types do not map to the existing source declarations.
- Final executable comparison remains required after integration.
