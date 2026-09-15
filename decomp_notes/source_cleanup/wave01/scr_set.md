# Source-cleanup handoff: `src/scr_set.cpp`

## Handoff

- Module: `src/scr_set.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source cleanup commit: `4adf17c4f532a7376a43c2db026c98ee5bcdf5fd`
- Final report commit: this report commit; the full hash is in Git output and the final handoff.
- Branch: `cleanup/staging-20260915-22`
- Changed files:
  - `src/scr_set.cpp`
  - `decomp_notes/source_cleanup/wave01/scr_set.md`

## Scope and evidence

This worker performed source cleanup only. I read the repository contract and the complete source-cleanup, comments, resource-ID, owner, testing, and wave-assignment guides.

I read `include/scr_set.h` and `include/scr_set_screen.h`. The module has twelve registered functions with `gx` flags. I inspected the twelve packets under `inventory/functions/004B/`, the matching registry, the scoped PDB records, the existing durable `decomp_notes/scr_set.md`, and the original source evidence.

The original executable reference is `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`, SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`. I did not execute it.

The scoped PDB records cover all twelve functions. Each record has register `this` in ECX with type `TribeGameSettingsScreen*`. No additional register-local name records are present. The source keeps all functions in the existing order and keeps the existing declarations, types, scopes, storage, calls, relocations, and data.

## Original-name recovery

The PDB names below are recovered originals. Names listed as inferred have no safe PDB mapping. I did not force mappings for optimized or reused stack slots.

| VA | Function | PDB evidence and source result |
| --- | --- | --- |
| `004B4880` | `TribeGameSettingsScreen::TribeGameSettingsScreen` | PDB stack record `num_str`, `char[5]`, matches the source. `setup_file`, `multiplayer`, and `draw_area` have no procedure-scoped record and remain inferred. |
| `004B5810` | `init_vars` | No stack names. The local array-loop `i` remains inferred. |
| `004B5920` | `~TribeGameSettingsScreen` | No stack names. The cleanup locals `p`, `n`, and `i` remain inferred. |
| `004B5BB0` | `handle_idle` | No stack names. `cur_time` remains an inferred local. The timer calls and order are unchanged. |
| `004B5C70` | `handle_user_command` | PDB names `wParam` (`unsigned int`) and `lParam` (`long`) were restored in the definition and uses. The shared header declaration has no parameter names and needs no edit. |
| `004B5CB0` | `action` | PDB names `fromPanel` (`TPanel*`), `actionIn` (`long`), `a1` (`unsigned long`), and `a2` (`unsigned long`) were restored in the definition, tests, forwarding call, and uses. |
| `004B5E00` | `fillScenarios` | PDB names `i`, `scenario_file`, `player_str`, `file_name`, and `scenario_info_file` match the source. The pointer formerly named `info` was renamed to recovered `scenario_info_file`; its type and declaration stayed unchanged. `name`, `len`, `entry`, and `players` have no safe PDB mapping and remain inferred. The packet shows optimized stack reuse; no declaration or buffer was split or merged. |
| `004B6160` | `fillMissionText` | No stack names. `line` and `id` remain inferred locals. The two negative scenario IDs and lookup order are unchanged. |
| `004B6230` | `getSettings` | No stack names. The local `line` remains inferred. All setting reads and casts are unchanged. |
| `004B6500` | `sendSettings` | No stack names. No local rename was needed. All setting writes and enum casts are unchanged. |
| `004B6740` | `activatePanels` | PDB stack record `tabList`, `TPanel*[12 bytes]`, matches the source. `is_scenario` and `count` have no safe PDB mapping. `is_scenario` is a new snake_case cleanup name for the former `isScenario`. |
| `004B6870` | `activateVictoryPanels` | No stack names. `first_line` and `second_line` are new snake_case cleanup names for the former `firstLine` and `secondLine`. Both calls to `get_line()` remain separate and in order. |

The source also retains concise inferred names such as `cancel_button`, `second_column_pos`, `result`, `players`, and `cur_time`. These are not claimed as original developer names. No public function, class, member, global, type, ABI symbol, layout, calling convention, or parameter type changed.

## Constants, resource IDs, and comments

The source now directly includes the root-owned `include/resource_ids.h` and reuses these existing macros:

| Macro | Value | Uses |
| --- | --- | --- |
| `IDS_BUTTON_OK` | `0x0FA1` | Settings-screen OK button caption. |
| `IDS_BUTTON_CANCEL` | `0x0FA2` | Settings-screen Cancel button caption. |
| `IDS_HELP_OK` | `0x7531` | OK button help ID. |
| `IDS_HELP_CANCEL` | `0x7532` | Cancel button help ID. |

These are existing shared definitions, not new resource names. No new resource mapping request is proposed. Other numeric resource IDs remain unchanged because no reviewed shared mapping was available. No new non-resource constant was added.

I restored the existing accurate evidence comment above `second_column_pos`: `The executable computes this position before it reloads scenarioList, then uses signed divide by ideal_width.` I kept removal of the separate unsupported `LIKELY INTENT` comment. The calculation, signed division, source order, and call are unchanged. No other new comments were needed.

## Header and resource requests

- Proposed edits to `include/scr_set.h`: none. It remains the module include surface.
- Proposed root-owned edit to `include/scr_set_screen.h`: add the recovered parameter names without changing types or order, if the declarations remain present:
  - `virtual long handle_user_command(unsigned int wParam, long lParam);`
  - `virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);`
  The PDB records for `004B5C70` and `004B5CB0` prove these names and types. This worker did not edit the header.
- Proposed edits to `include/resource_ids.h`: none. Root owns the existing shared macros.
- Resource extraction request: none. This change reuses existing reviewed macros and does not add a mapping.

## Output risk and unresolved items

The identifier changes do not change types, storage, expressions, control flow, calls, or symbol identity. The resource macros expand to the existing integer values. The `IDS_BUTTON_OK` and `IDS_BUTTON_CANCEL` definitions use `0x0FA1` and `0x0FA2`, which have the same effective integer type and value as the former literals.

Formatting and comment changes can alter debug line records. A direct include and macro substitutions can also alter line mapping. No compiler-output, program-data, relocation, or direct-target comparison was run. The PDB provides no safe original mappings for the inferred locals listed above. The optimized scenario-loop stack reuse remains an unresolved storage-mapping detail, and this cleanup does not imitate it.

## Commits

1. `4adf17c4f532a7376a43c2db026c98ee5bcdf5fd` — Clean up scr_set source names and IDs.
2. This report commit — Document scr_set cleanup handoff. Git output and the final handoff provide its full hash.

## Validation status

Compilation, matching, audits, tests, and games were **NOT run**. Only evidence inspection and complete Git diff review were performed. Generated-output equality remains unvalidated.
