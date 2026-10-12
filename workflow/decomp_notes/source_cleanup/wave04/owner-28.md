# Owner 28 cleanup ledger

## Scope

- Group: Resources and timelines.
- Integration branch: `cleanup/staging-20260915-244`.
- Common base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Initial reviewed pre-ledger head: `633fa736b16bc30e8fedbf870f5bad85747860ea`.
- Source modules: `Res_file`, `rge_fio`, `rge_tslc`, `t_histry`, `Timeline`, `tpnl_tml`, `tpnl_txl`, and `trig`.
- Owner headers: the eight matching headers under `include/`.

All worker source and report diffs were reviewed against the common base. The review checked scope, PDB coverage, name evidence, constants, comments, resource evidence, and file ownership.

## Module integration

| Module | Worker | Worker commits | Integration commits | Review result |
| --- | --- | --- | --- | --- |
| `src/Res_file.cpp` | `sa-5bfc6c9b` | `c2076994499a18cee6bed677491feef1c3a11e67`, `abd244bd27c8c3f20cd234fb982635cef4260baf` | `dd1c071c02cc20d1532c0b0183546de246d67c49`, `8954be30f371f8a2fd1b7eb5bedeadeddda4442f` | Approved. PDB names and pinned VC5 SDK/CRT constants have local evidence. |
| `src/rge_fio.cpp` | `sa-289335a3` | `ee91789eb61073d843829581fc22bae7349710a1`, `0de7cf7c04edc0daefb857c7ef91b1af9e6efc40` | `507e794a3b9113576c058267d54b422e2bac6638`, `02a5335090112bdbd69035cdb66f547c15dbd2c0` | Approved. Reused PDB homes did not cause type, scope, or storage changes. |
| `src/rge_tslc.cpp` | `sa-b539b77c` | `53617de0755ee1ae6023e731a71f887e7bdb51ff`, `a4db71eafa2aac5926f264f0f9483052cdb85c33` | `2970340638eea97c1e2e3fead29ef17b65f888d0`, `b4dc34dddac7ba647cfa6e2034d9d5d870058f9f` | Approved. Ambiguous `Hi`, `Avg`, and `Lo` stack-home mappings remain unchanged. |
| `src/t_histry.cpp` | `sa-d4b9e672` | `f5cf89b8070dd8bbd443f65ceb7d7527b08a6979`, `e8aad6b89351db0f947ae297aa5da270c89224da`, `7a9cb60fe74a1cc45b4a3a159d90a8dedc941fec` | `66ba4c26f9fdccec723e795e15546a7bfeb776e2`, `f4b1ac09c148e1ea6688eaad6f0c38dfe7608d45`, `6dc22173d62f6fb0029a23849bafc544df5e3c39` | Approved. The original indexed-event defect remains unchanged. |
| `src/Timeline.cpp` | `sa-c9cf03da` | `915cc2f3d97ec6f2fa35ddbb0be9aa30e91cddb5`, `cf5e947ce5d6cd351c5e424edc5943e38738811d`, `868a4e9577e038ab0766774b23976d13bdd10a62` | `079ea66d10eb02939acd2260fb602397573ad155`, `a15b92f28dae33957d051545d75989e223e26e57`, `ed76f86190152010aebb7436f4fc66e4a55ee018` | Approved after comment correction. Two proven original lookup defects have accurate `//! @bug` comments. No defect was repaired. |
| `src/tpnl_tml.cpp` | `sa-78b85a77` | `320ebf88394be8a8f5c032c6f1b72e7d9cfd4032`, `a37f59faf13f56e3ecf610b084f6b4f8dac0aec9`, `859a2107c1227c23eb7819b332dcd35c92ce5780`, `19a341ab0d0161c891a87ff87396fc323b7bcf0f` | `2cd90f3810bd214bc30be1e24c174f97a620d5eb`, `0148d005ebbe516247dc8dc4f242ce498776dcb8`, `6f532a1cfa56add2c046fa08f4430f7cd4d72e68`, `f3a4940a311b82afc25cd4b38b9af0b8ce5c4270` | Approved after reviewer correction. Unsupported PDB-home mappings were restored. Three approved resource macros are used. Resource evidence now records the exact virtual lookup path and missing expansion entries. |
| `src/tpnl_txl.cpp` | `sa-157756ad` | `9350ce7e589cf658334099f4c7681edd6e511df3`, `229ac7b17ce36dcde956834a6add1981e6cbd17e` | `bd0175b2287066a3ea4dbfbefae811ea605a60a3`, `f26c757cbc4295ed4dd6274d16dbc233477bb407` | Approved. A false register-save comment and an incorrect `ecx` comment were removed with packet evidence. |
| `src/trig.cpp` | `sa-93321037` | `fba05245c8bb77870ec4f1e7e532316a5129823f`, `1159a46c26d9e872533bcefd450e045ff68597ba` | `1ba2bf37d13f9285cac275b614006226553159f6`, `c72944fe753f952e3ea57b5cc6f974d1115e9916` | Approved after report correction. The source uses the PDB parameter name `angle`. |

No worker commit or approved hunk was omitted. The `t_histry` worker had three commits. All three were integrated in order.

## Corrections

- `trig`: the first report used a delivery-record placeholder. The same worker added the reviewed source/report commit hash in `1159a46c26d9e872533bcefd450e045ff68597ba`.
- `tpnl_tml`: the first source used three macros absent from `include/resource_ids.h`. The same worker removed the include and restored numeric IDs in `a37f59faf13f56e3ecf610b084f6b4f8dac0aec9`.
- Reviewer `sa-f1296ef0` found forced PDB-home mappings in `tpnl_tml`. The same worker restored the baseline descriptive names in `859a2107c1227c23eb7819b332dcd35c92ce5780`.
- The reviewer corrected the `Timeline` constructor comment. The second lookup tests `this_player_id` but indexes `target_player_id`.
- A final report review corrected the `tpnl_tml` resource lookup path and missing-entry wording. No source or header change was needed.

## Header integration

Owner header commit: `633fa736b16bc30e8fedbf870f5bad85747860ea`.

The commit updates declaration parameter names in:

- `include/Res_file.h`
- `include/rge_fio.h`
- `include/rge_tslc.h`
- `include/t_histry.h`
- `include/Timeline.h`
- `include/tpnl_tml.h`
- `include/tpnl_txl.h`
- `include/trig.h`

The header changes use procedure-scoped PDB names from the worker reports. They do not change types, order, calling conventions, layouts, values, or ABI symbols.

The root-approved `include/resource_ids.h` from `bf943f3339643ee5beca7dd74e98b4cb729e48d3` was imported as integration commit `3f5867e84cda53a3103593a0e74f952a3f0798b7`.

## Approved shared resource mapping

Root approved these existing base-language mappings for only the three `tpnl_tml` call sites:

| ID | Language | Text | Proposed cleanup name |
| --- | --- | --- | --- |
| `0x106A` | `0x0409` | `Tool Age` | `STRING_ID_HELP_AGE_TOOL` |
| `0x106B` | `0x0409` | `Bronze Age` | `STRING_ID_HELP_AGE_BRONZE` |
| `0x106C` | `0x0409` | `Iron Age` | `STRING_ID_HELP_AGE_IRON` |

Lookup path: `Time_Line_Panel::draw_icon` calls `TPanel::get_string`, which calls the virtual game method. `TRIBE_Game::get_string` tries `StringTableX` first, then the base-game fallback.

Base DLL: `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/language.dll`.
SHA-256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.

The IDs are present and nonempty in the base DLL. They are missing from the expansion DLL, not empty slots:
`C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/languagex.dll`.
SHA-256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

Exact extraction evidence:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner28/language-age-ids.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner28/languagex-age-ids.json`

The source replaces only these three literals. No other resource substitution was approved.

## Review and validation status

The final combined source and header diff was reviewed. `git diff --check` found no whitespace errors.

Compilation, matching, audits, validation commands, tests, and games were not run. The integrated group remains reviewed but unvalidated. Final output comparison must use the preserved pre-cleanup build and keep its earlier original-executable differences visible.
