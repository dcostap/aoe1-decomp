# Wave 01 owner 03 handoff

## Group

- Branch: `cleanup/staging-20260915-03`
- Base: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Initial handoff integration head: `2fdfc17c35a4ed868558ef3263b939df3ea75f0c`
- Corrected integration head before this ledger update: `be32a0e3515bcaa8500bd176acda4c95fe77c56b`
- Scope: eight screen modules and eight authorized headers.
- Status: reviewed and integrated, but unvalidated.

I read each complete worker diff and report. I also reviewed the complete combined diff.

## Workers and module status

| Module | Worker | Worker final head | Review result |
| --- | --- | --- | --- |
| `src/scr_save.cpp` | `sa-351566d9` | `df6d631d5029eab12edce4fec1fa07aae39fdbf7` | Approved and integrated. |
| `src/scr_name.cpp` | `sa-04ef409c` | `328b549864abf609df551f8c48def819c462e110` | Approved after resource evidence correction. |
| `src/scr_set.cpp` | `sa-5b54177e` | `8ae5d1d955aedd612417c0b94f33145c6d42b14c` | Approved after one correction. |
| `src/scr_sing.cpp` | `sa-793768e4` | `3f8e9fc369ceb826dcfae88741d4d2c8ff69a653` | Approved and integrated. |
| `src/scr_main.cpp` | `sa-6a51283f` | `a09efcf4e41a051e36ee84d4e54dbcd7fbc31a9a` | Approved after mapping correction. |
| `src/scr_cam.cpp` | `sa-5767a2a6` | `806336fd34685422a38760dcbeda457e55ff7e7d` | Approved after evidence correction. |
| `src/scr_cams.cpp` | `sa-97873e72` | `69b52be28d591c669407ca2f36913e9b10551167` | Approved after three corrections. |
| `src/scr_cj.cpp` | `sa-f122e345` | `50dcb4fcba7ebce307f0becff401b99b1b5e3037` | Approved after brace correction. |

Each worker started at the group base above. Each worker changed only its source and module report.

## Review findings

All modules inspected each registered function. Reports cover PDB stack and register records.

Approved changes restore supported PDB names. They preserve mixed original spelling.

Approved inferred names use snake_case. Uncertain reused stack slots remain unchanged.

Existing resource macros keep the same literal values and effective types. No worker defined a new resource macro.

Formatting uses 1TBS where workers changed brace style. No worker changed statement order or declaration scope.

Comments remain sparse. No worker added inline assembly, wrappers, or structural rewrites.

### Correction rounds

`scr_set` first replaced an accurate executable comment. Round one restored that comment.

The same round removed only the separate unsupported intent claim. It also recorded a root-owned header request.

`scr_cams` first had an incomplete report. It also mislabeled SHA-256 as SHA-1.

Round one added full PDB coverage, the header request, output risk, and the correct hash name.

The first `scr_cams` source renamed three uncertain `startGame` locals. Packet evidence warned that one symbol was unmapped.

Round two restored `scen`, `first_human`, and `first_color`. The report records the rejected mapping.

Root review found one unnecessary `scr_cams` call wrap. The same worker restored the call to one line.

Root review found one remaining `scr_cj` constructor brace. The same worker applied 1TBS.

The `scr_main` worker traced `0x1D4F7` through `TMessageDialog::setup`.
The report now proposes `IDS_HELP_NOTICE` for displayed notice text.

The `scr_cam` report first cited old pilot extraction artifacts. The same worker re-extracted data under slot 25.

The corrected report keeps the old citation in its correction record. The worker did not edit the pilot worktree.

The `scr_name` report incorrectly said its help text was unknown. The same worker recorded the base DLL text.

Six workers applied the reviewed shared resource mappings. Their worker-local header cherry-picks were not integrated.

Excluded worker-local shared-header commits:

| Module | Excluded commit |
| --- | --- |
| `scr_save` | `c79bf91c115c5ae13769847e24444d92b7214dc4` |
| `scr_name` | `08253bca4342fefa97129a115b95bd36c97438ef` |
| `scr_sing` | `90059e0b3cccac0e76bc94adfffd52ba42882554` |
| `scr_main` | `ac3ccdedc8b2f4ee50f949205f7e35293cd8da52` |
| `scr_cam` | `b2fabf8d2e4834afa166ba35f9148b286a33a50d` |
| `scr_cj` | `ce7c965ff82f640183c8e7207f7a6d3cbb26d923` |

## Integrated commits

| Local commit | Module or purpose |
| --- | --- |
| `f483660b2906c311607b70bd1c993a9cc805b055` | `scr_cj` source |
| `8db9a14fff6a5f32ddcc4ca6c7da3ac403ff0d95` | `scr_cj` report |
| `3ae1d7b22e885511ba19815eaaa6ef12915507ea` | `scr_cj` report record |
| `f3653c31f7ee11bec0c640c92f65f2ec261ff768` | `scr_main` source |
| `799c514efcc1ed26490fc5dca219d3361c91212b` | `scr_main` report |
| `32da62dd057c254a097ef538246b7d69877c6861` | `scr_save` source |
| `99bdc5431b9d148ca64a42ab9c2a3178f3e26b83` | `scr_save` report |
| `7b8da24f03eba36f5d83c70b12190cd2c0f32452` | `scr_sing` source |
| `fb4a3ffd45b53157545266d1c5a7dda65ddf49ab` | `scr_sing` report |
| `1fd44882ecd6c263602e66d34ae07628a19f0eda` | `scr_name` source |
| `f9740ed022aeda6d8451d2d285cc617eb2f47cef` | `scr_name` report |
| `37391a7e5d81dd64776174bb4410ddceb1e53109` | `scr_cam` source |
| `1395a8544316f0d597e8fbf577c7cda0b2863d1f` | `scr_cam` report |
| `56aa88af339bfd5edef9e357db1792042f1233e1` | `scr_set` source |
| `136460b5044852485cfe5c39d5d77aea63b393e7` | `scr_set` report |
| `f4c26bb6574a7c139aae6850ad3a6e765743698b` | `scr_set` correction |
| `51fb64cfcb84b9ca970dd0a7066bdd26f4da2392` | `scr_cams` source and first report |
| `f6acd6c6869954fc6b276ccc58e2d88c0a45537b` | `scr_cams` report and formatting correction |
| `8abf8359c916416ab99bf77468db41dc26742531` | `scr_cams` uncertain-name correction |
| `2fdfc17c35a4ed868558ef3263b939df3ea75f0c` | Owner header parameter names |
| `cea8702d67fd5dfca54ee652e42455a350ae6e22` | Extended-owner settings header names |
| `14d031ccd9c7a454c2052bc0c08baa158a1464eb` | `scr_cams` call formatting correction |
| `2f804efcdcd5a39deb87c94d976cf83348f5cb96` | `scr_cj` constructor 1TBS correction |
| `e7d3905d058907ac547b352e63836dac3b560981` | `scr_cj` correction record |
| `4d070e0fc816564ea0974c5aa78c0ecd15943e76` | `scr_main` help-notice mapping correction |
| `b4ee11acacf8f2f7f620b2fc5a98e135b565f800` | `scr_cam` extraction provenance correction |
| `fdd449d0a14dd1ba91326282f6f818918b21db60` | Root-reviewed shared resource definitions |
| `ec1d79d939471e37c30e5e038d947b4fe41d28cd` | `scr_sing` resource substitutions |
| `825594a8489de66fbac949e6be5eeaaaf5846bf5` | `scr_sing` resource report |
| `74b0e47f97abc2fcd104ad99e22895cfa1c78871` | `scr_save` resource substitutions |
| `54daa9366b353dc1fbfc516d636ee8b97dd45fb3` | `scr_save` resource report |
| `b20c9cfcfc1f0af708ef7fe6aa04cc25a74071f3` | `scr_cj` resource substitutions and report |
| `ec90e2f8f2b3d197421ad47f16fbd9717365a952` | `scr_cj` resource commit record |
| `7d8dd7939e5d1e96e52ea5c20230549a858de1c6` | `scr_cam` resource substitutions |
| `22d6f6f4106b1bf605d3f8922ff64d7bbb6cd480` | `scr_cam` resource report |
| `e33bbe0afadede9d9bc65b0e704babf410d06010` | `scr_main` resource substitutions |
| `326fdea4ce43820c020f01a4ec90f4e86eb075cc` | `scr_main` resource report |
| `fe6c99a0f18ddde55d50efad386d9d2d5805c447` | `scr_name` resource substitutions and report |
| `be32a0e3515bcaa8500bd176acda4c95fe77c56b` | `scr_name` resource evidence correction |

## Owner header changes

Commits `2fdfc17c35a4ed868558ef3263b939df3ea75f0c` and `cea8702d67fd5dfca54ee652e42455a350ae6e22` change only parameter names.

Changed headers:

- `include/scr_save.h`
- `include/scr_name.h`
- `include/scr_sing.h`
- `include/scr_main.h`
- `include/scr_cam.h`
- `include/scr_cams.h`
- `include/scr_cj.h`
- `include/scr_set_screen.h`

The names match the procedure-scoped PDB records. Types, order, virtual slots, and layouts stay unchanged.

`include/scr_set.h` needed no change. Root extended ownership for `include/scr_set_screen.h` only.

## Extended owner header change

Root extended owner 03 ownership to `include/scr_set_screen.h`.
Commit `cea8702d67fd5dfca54ee652e42455a350ae6e22` adds these PDB names:

```cpp
virtual long handle_user_command(unsigned int wParam, long lParam);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

PDB VAs `004B5C70` and `004B5CB0` prove these names and types.

## Shared resource mappings

Root retains `include/resource_ids.h`.
Root commit `c9ba20d160541d928b5d9e55e1d02dce5a784e0c` added 64 distinct definitions.

The group cherry-pick is `fdd449d0a14dd1ba91326282f6f818918b21db60`.
Six module workers applied their reviewed mappings. No listed mapping remains pending.

All mappings below use `RT_STRING` and language `0x0409`.

The base file is `runtime/language.dll`.
Its SHA-256 is `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.

The override file is `runtime/languagex.dll`.
Its SHA-256 is `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

The pinned XPack file SHA-256 is `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

Most requested IDs are missing from both expansion files. Some `scr_main` IDs have empty or overridden expansion entries.

Each module table below states its expansion provenance. Module reports record exact text, purpose, and format tokens.

### `scr_save`

All requested IDs are missing from both checked expansion files. Runtime lookup falls back to the base file.

| Value | Applied macro | Proven role |
| --- | --- | --- |
| `0x24C3` | `IDS_SAVE_GAME_TITLE_BASE` | Save-screen title range base. |
| `0x24C6` | `IDS_ERROR_SAVE_GAME_NAME_REQUIRED` | Empty save-game name error. |
| `0x24C7` | `IDS_ERROR_SAVE_SCENARIO_NAME_REQUIRED` | Empty scenario name error. |
| `0x24C8` | `IDS_CONFIRM_OVERWRITE_FILE` | Overwrite prompt. |
| `0x7671` | `IDS_HELP_SELECT_SAVED_GAME` | Save-list help. |
| `0x0962` | `IDS_ERROR_CANNOT_SAVE_GAME` | Save-game failure. |
| `0x0963` | `IDS_ERROR_CANNOT_SAVE_SCENARIO` | Scenario-save failure. |
| `0x0450` | `IDS_STATUS_SAVING_SCENARIO` | Scenario-save status. |

### `scr_name`

All requested IDs are missing from both checked expansion files. Runtime lookup falls back to the base file.

| Value | Applied macro | Proven role |
| --- | --- | --- |
| `0x29FE` | `IDS_SELECT_PLAYER_TITLE` | Screen title. |
| `0x29FF` | `IDS_PLAYER_NAME_LABEL` | Player-name label. |
| `0x2A00` | `IDS_BUTTON_NEW_PLAYER` | New-player button. |
| `0x2A01` | `IDS_BUTTON_REMOVE_PLAYER` | Remove-player button. |
| `0x2A02` | `IDS_CONFIRM_REMOVE_PLAYER` | Remove-player format prompt. |
| `0x2A03` | `IDS_NAME_DIALOG_TITLE` | Name-dialog title. |
| `0x2A04` | `IDS_NEW_PLAYER_NAME_LABEL` | New-player label. |
| `0x03EA` | `IDS_BUTTON_CLOSE` | Close control. |
| `0x765C` | `IDS_HELP_PLAYER_NAME_LIST` | Player-list help. |
| `0x765D` | `IDS_HELP_ADD_PLAYER_NAME` | Add-name help. |
| `0x765E` | `IDS_HELP_REMOVE_PLAYER_NAME` | Remove-name help. |

### `scr_sing`

All requested IDs are missing from both checked expansion files. Runtime lookup falls back to the base file.

| Value | Applied macro | Proven role |
| --- | --- | --- |
| `0x03EA` | `IDS_BUTTON_CLOSE` | Close control. |
| `0x2404` | `IDS_MENU_SINGLE_PLAYER_TITLE` | Screen title. |
| `0x2405` | `IDS_MENU_SCENARIO` | Scenario route. |
| `0x2407` | `IDS_MENU_SAVED_GAME` | Saved-game route. |
| `0x2408` | `IDS_MENU_CAMPAIGN` | Campaign route. |
| `0x2409` | `IDS_MENU_SINGLE_PLAYER_CANCEL` | Return route. |
| `0x240A` | `IDS_MENU_RANDOM_MAP` | Random-map route. |
| `0x240B` | `IDS_MENU_DEATH_MATCH` | Death-match route. |

### `scr_main`

| Value | Applied macro | Proven role | Runtime expansion | Pinned expansion |
| --- | --- | --- | --- | --- |
| `0x23F2` | `IDS_MENU_SINGLE_PLAYER` | Single-player route. | Missing | Missing |
| `0x23F3` | `IDS_MENU_MULTIPLAYER` | Multiplayer route. | Missing | Missing |
| `0x23F5` | `IDS_MENU_HELP` | Help route. | Missing | Missing |
| `0x23F6` | `IDS_MENU_SCENARIO_BUILDER` | Scenario-builder route. | Missing | Missing |
| `0x23F7` | `IDS_MENU_EXIT` | Exit route. | Missing | Missing |
| `0x2419` | `IDS_PRODUCT_TITLE` | Product title. | Override text | Override text |
| `0x241B` | `IDS_COPYRIGHT_PREFIX` | Copyright prefix. | Empty | Empty |
| `0x241C` | `IDS_COPYRIGHT_SUFFIX` | Copyright suffix. | Override text | Override text |
| `0x2424` | `IDS_COPYRIGHT_SEPARATOR` | Copyright separator. | Empty | Missing |
| `0x2425` | `IDS_COPYRIGHT_WARNING` | Copyright warning. | Empty | Missing |
| `0x03EA` | `IDS_BUTTON_CLOSE` | Close control. | Missing | Missing |
| `0x07D7` | `IDS_ERROR_LOAD_GAME_DATA` | Data-load error. | Empty | Missing |
| `0x07D8` | `IDS_ERROR_INSERT_CD_SINGLE_PLAYER` | Single-player CD error. | Empty | Missing |
| `0x07DA` | `IDS_ERROR_INSERT_CD_SCENARIO_BUILDER` | Scenario-builder CD error. | Empty | Missing |
| `0x1D4F7` | `IDS_HELP_NOTICE` | Displayed help notice; exact text unknown. | Missing | Missing |

### `scr_cam`

All requested IDs are missing from both checked expansion files. Runtime lookup falls back to the base file.

| Value | Applied macro | Proven role |
| --- | --- | --- |
| `0x2BC1` | `IDS_CAMPAIGN_EDITOR_TITLE` | Editor title. |
| `0x2BC2` | `IDS_CAMPAIGN_FILENAME_LABEL` | Filename label. |
| `0x2BC4` | `IDS_BUTTON_SAVE` | Save button. |
| `0x2BC5` | `IDS_BUTTON_ADD` | Add button. |
| `0x2BC6` | `IDS_BUTTON_REMOVE` | Remove button. |
| `0x2BC7` | `IDS_SCENARIOS_TITLE` | Available-scenarios label. |
| `0x2BC8` | `IDS_CAMPAIGN_SCENARIOS_TITLE` | Campaign-scenarios label. |
| `0x2BC9` | `IDS_CONFIRM_SAVE_CAMPAIGN` | Save-changes format prompt. |
| `0x2BCA` | `IDS_DEFAULT_CAMPAIGN_NAME` | Default campaign name. |
| `0x2BCB` | `IDS_ERROR_CAMPAIGN_REQUIRES_SCENARIO` | Empty-campaign error. |
| `0x2BCC` | `IDS_ERROR_CAMPAIGN_NAME_REQUIRED` | Empty-name error. |
| `0x2BD5` | `IDS_BUTTON_MOVE_SCENARIO_UP` | Move-up button. |
| `0x2BD6` | `IDS_BUTTON_MOVE_SCENARIO_DOWN` | Move-down button. |

### `scr_cj`

All requested IDs are missing from both checked expansion files. Runtime lookup falls back to the base file.

| Value | Applied macro | Proven role |
| --- | --- | --- |
| `0x25A0` | `IDS_MULTIPLAYER_JOIN` | Join button. |
| `0x25A1` | `IDS_MULTIPLAYER_SHOW_GAMES` | Show-games button. |
| `0x25A2` | `IDS_MULTIPLAYER_CREATE` | Create button. |
| `0x25A3` | `IDS_MULTIPLAYER_UNABLE_TO_JOIN_GAME` | Join-failure message. |
| `0x25A4` | `IDS_MULTIPLAYER_NO_GAMES_TO_JOIN` | No-games message. |
| `0x25A6` | `IDS_MULTIPLAYER_CREATE_GAME_TITLE` | Create-game title. |
| `0x25A8` | `IDS_MULTIPLAYER_SELECT_GAME_TO_JOIN` | Join-list title. |
| `0x25A9` | `IDS_MULTIPLAYER_LOOKING_FOR_GAMES` | Refresh progress. |
| `0x25AA` | `IDS_MULTIPLAYER_GAME_NAME` | Game-name label. |
| `0x25AB` | `IDS_MULTIPLAYER_NO_GAMES_INSTRUCTIONS` | Empty-list instructions. |
| `0x25AD` | `IDS_MULTIPLAYER_UNABLE_TO_CREATE_GAME` | Create-failure message. |

`scr_set` and `scr_cams` needed no new resource definitions.

## Validation

I ran Git status, full diff review, `git diff --check`, and read-only evidence inspection.

Compilation, builds, matching, audits, tests, and games were not run. The wave forbids them.

Generated code, data, relocations, calls, and runtime behavior remain unvalidated.
