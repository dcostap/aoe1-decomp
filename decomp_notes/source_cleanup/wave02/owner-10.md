# Owner 10 dialog cleanup ledger

## Scope

Owner 10 integrated these eight modules from base
`ef1c4d2e33bac077e7e4e21598f1c18722a721c6`:

- `src/dlg_abt.cpp` and `include/dlg_abt.h`
- `src/dlg_conf.cpp` and `include/dlg_conf.h`
- `src/dlg_dip.cpp` and `include/dlg_dip.h`
- `src/dlg_help.cpp` and `include/dlg_help.h`
- `src/dlg_list.cpp` and `include/dlg_list.h`
- `src/dlg_menu.cpp` and `include/dlg_menu.h`
- `src/dlg_msg.cpp` and `include/dlg_msg.h`
- `src/dlg_sedm.cpp` and `include/dlg_sedm.h`

Each worker changed only its source and module report. Owner 10 changed only the eight assigned headers and this ledger.

## Workers and integration

All workers used `openai-codex-secondary/gpt-5.6-luna` with `xhigh` thinking.
Each worker started at the common base above.

| Module | Worker | Worker final head | Worker commits | Integrated commits |
| --- | --- | --- | --- | --- |
| `dlg_abt` | `sa-2ef92585` | `305cadcc34ee05a3db7c8d309b2ead2347f5b508` | `d70f7ddbae5959ed116b0d2bd51ae96c412070a4`, `305cadcc34ee05a3db7c8d309b2ead2347f5b508` | `18c9d9de0f841421c33945216a8e4db6044bcde7`, `3220775d7f00ebaf03cab4dbb3ee6fef514b43e0` |
| `dlg_conf` | `sa-b9c4678c` | `7f88b0d7c516f83f96aeeadb5f4e07eade8ade40` | `0580398dc0aef51fa019add9cb0a7a96c09eb528`, `7f88b0d7c516f83f96aeeadb5f4e07eade8ade40` | `c96242d162d38b2d18ff096bbde8be9373b1abc7`, `749c80067692e1d8481fcdb72ce5acd7bd78758a` |
| `dlg_dip` | `sa-5274a054` | `61dbb6ae3d91aedf6eea80279691dea99ce860e4` | `d0855b8b272c3d10d8c41aa82a98532ea6ef3c96`, `61dbb6ae3d91aedf6eea80279691dea99ce860e4` | `3d3295ef383cccb5eaaa5668cea4ea16c4a1e713`, `bad544b0b605519aad7954afd87b6f1ad1518452` |
| `dlg_help` | `sa-281c2378` | `9e873050d6241e2e75bf9dde6f99f52943eb3d3c` | `7333ff58036a73e1d7fac31869df3bed37d9604b`, `9e873050d6241e2e75bf9dde6f99f52943eb3d3c` | `13cd7b0a27ccdb8431d61133f843aa1547321315`, `1a61aa5bf0cb4e7431553192e60a0af36d777d55` |
| `dlg_list` | `sa-3604241b` | `5deec481c3d70b25968aab57365880085c0310af` | `e35339a1abc5f1350e26a7f8b44aea3fd4008088`, `5deec481c3d70b25968aab57365880085c0310af` | `9e269879458fda8ba62d071f5d2c1777f20f9f8c`, `cdd6852563dd011a1e8f331cc4ad8439055c5447` |
| `dlg_menu` | `sa-c49b8138` | `75ee6aa221d37c780e4c79d39301064ba151e6dc` | `0abf8b997ccc16a0888fefbbfdfae9f2836afe0b`, `1d278e22b922ffad4e619160f740c99e5d7d8b43`, `89164609b53506a51edc3473a2bf3bfe92479ea1`, `75ee6aa221d37c780e4c79d39301064ba151e6dc` | `95d7e3b918b62496cd09f3f01ab08df8270920bf`, `70aa3008dad0d9aee5add0ff5ecd78f00a8db442`, `e3795413f4994e4966e48b98a5ecd5a394bb1a37`, `d4b176c8fd893432a69cc6dac8209c058ae075ca` |
| `dlg_msg` | `sa-9bad2e00` | `68e9810dfe00f9454a776a38e8af82cdbd965aa8` | `271528deff0e82898e192751675c56855b7a09a4`, `68e9810dfe00f9454a776a38e8af82cdbd965aa8` | `ffb9d1c8ef924f8deae44a3efefe6ab0c1fc88ad`, `53498bd15df34842652c35332e673dd6cfb798b1` |
| `dlg_sedm` | `sa-189d0416` | `8243d31a4276905a4a367c411916ef6716e9f98b` | `b43aab2ed74523e70c0a514fa59be3807540d245`, `8243d31a4276905a4a367c411916ef6716e9f98b` | `6b739cd552a5939384e4d2d06fef01796df58705`, `f78ba81d505cabf35cac0575752bdc999a43ca52` |

The initial owner header commit is `2967c3e5b7c892bd29c30cdb64b7451721114688`.
Root approved the shared definitions in `8c56055b7feee1526f296bd306036a4c34f38041`.
Owner 10 imported only `include/resource_ids.h` in
`c6d5f27ea995a8c4e887d0ad0e4541c807e42a98`.
Owner 10 compacted the assigned declarations in
`e2d0f7d5846fbbaa2e25877222bdd9095665afa0`.

## Correction history

Owner 10 resumed the same seven workers after root approved the resource IDs.
`dlg_list` needed no resource correction.

| Module | Worker resource commit | Worker source and final head | Integrated correction commits |
| --- | --- | --- | --- |
| `dlg_abt` | `ea9e4c8f74c8f42512971e615be92cde24539fd5` | `f92c8da2a2f14174eadcef05585e4cb16d006c25`, `fe005b89878a1a0d82b02818dfaf3e250d4af36a` | `1cf30d183bb36e730c0dc0a644195edb3680e56b`, `38ef2f75f7cdda3aafcc3cba93d34534cdaa6317` |
| `dlg_conf` | `3caba12fa62d4d07a0626fcb9f77e3425b9181ff` | `4bb1f30e5b844c4ea0c51cc29308ca22f2825333`, `c281b0909f0057b25574d8ab208f93a1d000840c` | `2cfe1f5430a9ccc6a46827f7b73a54fb6a943536`, `61b4327fad3654ad153b2d0af1ac5370305999eb` |
| `dlg_dip` | `46805ee2a76f12ba7a50fa925461d1f787a00e61` | `f9d038289fa1d7a46a81b2667839ec08f41abf31`, `30a51d4928ec07e189e13e76e37a0e3ccbc3d18d` | `1c87fe5f93a31e5988dea7d1384387fd7db1c8f2`, `d7beb5c299c8143957b2dea0ff15a79a3ee16141` |
| `dlg_help` | `08038221ea7047376f742814ca1185dbf31268e8` | `1c75a1dd6757a05fc717fd9dfe44860656a02905`, `cd2a3bffbe92058416d758d231693df54fe1ff5d` | `f9af5e82f1899ec8df637320ebe9f61fcb61d6c6`, `63e9633c24e72b04b00850f32eab56e3c6dd4015` |
| `dlg_menu` | `5bc93fcb069dce227999254757e001423ec4959e` | `d26604d77fcf83b0b61a08b467c5ab30df85f3dc`, `b25fe65cd60e6facfe985fa08fc457f2b95d544e` | `b2f13e837668d539a3e2a72f5bde7cff746d3846`, `4d5b2134b43099d280e913113aaaa3bdd0d92271` |
| `dlg_msg` | `8adda677299caa9f9be07fbaa96f476c70c30e56` | `fa6cac77c18b489ce2d4892ce13df8858fae9b62`, `9ad2537666b629eb2260931c1936d52e303bb777` | `e38fd314c4bcac557b75f9964b0dc9fa087a5ef8`, `b36901a2ffc579e80f7203eb2eac052d0e365593` |
| `dlg_sedm` | `3bff68f3de98c7273f9a41faf3398b68cc17f15a` | `bc983e07915b974a17516dde307dab8a6d6be818`, `5db875f530849d185885d1722f3b82a06dabcdac` | `0b43d95445599022786a78f01c3237d2b145a9d9`, `b130b8b63266e1c1b69f2e9c84ae61b474b719e5` |

## Recovered mappings

The module reports contain each procedure, stack offset, type, register, and source result.
The main recovered mappings are:

- `dlg_abt`: `parentPanel`, `tabList`, `fromPanel`, `actionIn`, `a1`, and `a2`.
- `dlg_conf`: `m`, `parentPanel`, `tabList`, `val`, `fromPanel`, `actionIn`, `a1`, and `a2`.
- `dlg_dip`: `parentPanel`, `paletteColor`, `tabList`, `tabCount`, `a`, `fromPanel`, `actionIn`, `a1`, `a2`, and `tc`.
- `dlg_help`: both constructor parameter sets, all `setup_help` parameters, `rge_text_font`, `tabList`, `dialog_x`, `panel_height`, and all action and mouse parameters.
- `dlg_list`: both 22-parameter `setup` lists, `str`, all key parameters, and all action parameters.
- `dlg_menu`: `parentPanel`, `fromPanel`, `actionIn`, `a1`, and `a2`.
- `dlg_msg`: both `setup` parameter sets, `button_num`, `space`, `index`, `y`, `str`, all action parameters, and all key parameters.
- `dlg_sedm`: `scenario_editor_in`, `from_panel`, `action_in`, `action_val1`, and `action_val2`.

The assigned headers now use the same recovered parameter spelling.
No type, order, virtual slot, layout, or ABI symbol changed.

## Review findings

I read every complete worker diff and report. I checked worker scope, PDB coverage, resource evidence, name provenance, types, declaration points, and 1TBS changes.

All eight initial worker results were complete and acceptable for the first handoff.
Root then requested focused corrections and approved 79 shared definitions.
Owner 10 resumed the same seven affected workers and reviewed every correction diff.
Each worker preserved uncertain locals that had no reliable PDB mapping.
The `dlg_conf` reused `+0x8` homes remain separate declarations. Their types and uses support the reported mappings.
The `dlg_help` positive reused homes remain separate declarations.
The `dlg_msg` reused argument homes remain separate declarations and types.

The source uses the 79 approved shared resource macros.
The path-finding range preserves `IDS_PATH_FINDING_OPTION_BASE + i`.
No worker edited a header, registry, inventory, build recipe, runtime file, or baseline output.

A combined review checked all eight sources, reports, and assigned headers against the common base.
`git diff --check` found no whitespace errors.

## Unresolved name evidence

Some source locals have no procedure-scoped PDB record. Their existing descriptive names remain unchanged.
The module reports list each such local.
No uncertain PDB stack-slot mapping was forced.

The applied resource macro names are cleanup names. PDB evidence does not establish their original spelling.
No pending resource definition blocks the integrated source.

## Applied shared resource definitions

Root owns `include/resource_ids.h`. Root approved 79 definitions in
`8c56055b7feee1526f296bd306036a4c34f38041`.
The module reports contain exact text, language, hashes, missing or empty results, lookup paths, and purposes.
All uses preserve the base language namespace and expansion-first fallback.

### `dlg_abt`

- `0x241A` `IDS_PRODUCT_VERSION`
- `0x241D` `IDS_COPYRIGHT_ENSEMBLE`
- `0x241E` `IDS_PRODUCT_ID_LABEL`
- `0x241F` `IDS_ABOUT_COPYRIGHT_WARNING`
- `0x2420` `IDS_ABOUT_CREDITS_BUTTON`
- `0x2421` `IDS_ABOUT_CLOSE_BUTTON`
- `0x2423` `IDS_GENIE_ENGINE_COPYRIGHT`

### `dlg_conf`

- `0x24D7` `IDS_GAME_SETTINGS_TITLE`
- `0x24D8` `IDS_GAME_SPEED_NORMAL`
- `0x24D9` `IDS_GAME_SPEED_FAST`
- `0x24DA` `IDS_GAME_SPEED_VERY_FAST`
- `0x24DB` `IDS_MUSIC_VOLUME_TITLE`
- `0x24DC` `IDS_AUDIO_VOLUME_HIGH`
- `0x24DD` `IDS_AUDIO_VOLUME_OFF`
- `0x24DE` `IDS_SOUND_VOLUME_TITLE`
- `0x24DF` `IDS_GAME_SPEED_TITLE`
- `0x24E0` `IDS_SCREEN_SIZE_TITLE`
- `0x24E7` `IDS_SCREEN_SIZE_640X480`
- `0x24E8` `IDS_SCREEN_SIZE_800X600`
- `0x24E9` `IDS_SCREEN_SIZE_1024X768`
- `0x24EA` `IDS_MOUSE_INTERFACE_TITLE`
- `0x24EB` `IDS_MOUSE_INTERFACE_TWO_BUTTONS`
- `0x24EC` `IDS_MOUSE_INTERFACE_ONE_BUTTON`
- `0x24ED` `IDS_ROLLOVER_HELP_TITLE`
- `0x24EE` `IDS_ROLLOVER_HELP_ON`
- `0x24EF` `IDS_ROLLOVER_HELP_OFF`
- `0x24F0` `IDS_SCROLL_SPEED_TITLE`
- `0x24F1` `IDS_SCROLL_SPEED_FAST`
- `0x24F2` `IDS_SCROLL_SPEED_SLOW`
- `0x260D` `IDS_PATH_FINDING_TITLE`
- `0x260E` `IDS_PATH_FINDING_OPTION_BASE`
- `0x0BF3` `IDS_GAME_SPEED_CHANGED`

### `dlg_dip`

- `0x267B` `IDS_DIPLOMACY_TITLE`
- `0x267C` `IDS_DIPLOMACY_CIVILIZATION`
- `0x267D` `IDS_DIPLOMACY_ALLY`
- `0x267E` `IDS_DIPLOMACY_NEUTRAL`
- `0x267F` `IDS_DIPLOMACY_ENEMY`
- `0x2680` `IDS_DIPLOMACY_PAY_TRIBUTE_FORMAT`
- `0x2681` `IDS_DIPLOMACY_ALLIED_VICTORY`
- `0x2683` `IDS_DIPLOMACY_CLEAR_TRIBUTES`
- `0x2686` `IDS_DIPLOMACY_NAME`
- `0x2687` `IDS_DIPLOMACY_NEED_MARKET`
- `0x0FA9` `IDS_BUTTON_HELP`
- `0x7684` `IDS_HELP_DIPLOMACY_ALLY`
- `0x7685` `IDS_HELP_DIPLOMACY_NEUTRAL`
- `0x7686` `IDS_HELP_DIPLOMACY_ENEMY`
- `0x7687` `IDS_HELP_DIPLOMACY_TRIBUTE_WOOD`
- `0x7688` `IDS_HELP_DIPLOMACY_TRIBUTE_FOOD`
- `0x7689` `IDS_HELP_DIPLOMACY_TRIBUTE_GOLD`
- `0x768A` `IDS_HELP_DIPLOMACY_TRIBUTE_STONE`
- `0x768B` `IDS_HELP_DIPLOMACY_CLEAR_TRIBUTES`
- `0x768C` `IDS_HELP_DIPLOMACY_ALLIED_VICTORY`

### `dlg_help`

- `0x243D` `IDS_BUTTON_MORE_HELP`

### `dlg_menu`

- `0x23F9` `IDS_MENU_ABOUT`
- `0x2437` `IDS_MENU_ACHIEVEMENTS`
- `0x2438` `IDS_MENU_SAVE`
- `0x2439` `IDS_MENU_QUIT_GAME`
- `0x243A` `IDS_MENU_GAME_SETTINGS`
- `0x243B` `IDS_MENU_CANCEL`
- `0x243C` `IDS_MENU_LOAD`
- `0x243E` `IDS_MENU_SCENARIO_INSTRUCTIONS`
- `0x243F` `IDS_MENU_RESTART`
- `0x2440` `IDS_MENU_RESIGN`
- `0x269E` `IDS_ACHIEVEMENTS_TITLE`
- `0x0C1C` `IDS_CONFIRM_QUIT_AND_LOAD`
- `0x0C1D` `IDS_CONFIRM_QUIT_GAME`
- `0x0C1E` `IDS_CONFIRM_RESTART_GAME`
- `0x0C1F` `IDS_CONFIRM_RESIGN`

### `dlg_msg`

- `0x0FA3` `IDS_BUTTON_YES`
- `0x0FA4` `IDS_BUTTON_NO`
- `0x0FA5` `IDS_BUTTON_RETRY`
- `0x0FA7` `IDS_BUTTON_ABORT`

### `dlg_sedm`

- `0x2443` `IDS_SCENARIO_MENU_QUIT_TO_MAIN_MENU`
- `0x2441` `IDS_SCENARIO_MENU_SAVE`
- `0x2442` `IDS_SCENARIO_MENU_SAVE_AS`
- `0x2445` `IDS_SCENARIO_MENU_EDIT_SCENARIO`
- `0x242E` `IDS_SCENARIO_MENU_CREATE_SCENARIO`
- `0x2446` `IDS_SCENARIO_MENU_TEST`
- `0x2444` `IDS_SCENARIO_MENU_CANCEL`

`dlg_list` needed no new shared definition.
No shared resource request remains pending.

## Report-only correction history

Root confirmed the complete source correction diff. Root then requested two
report-only corrections. The same affected workers corrected the reports.

Each report now separates root approval
`8c56055b7feee1526f296bd306036a4c34f38041` from its worker-local import
commit. The `dlg_menu` report now identifies the adjacent strings as dialog
panel names. The `dlg_msg` report now records `0043FEAD` as the comparison and
`0043FEAF` as the store.

| Module | Worker final report head | Integrated report commit |
| --- | --- | --- |
| `dlg_abt` | `b4ab8705433c90be053447e6d7c5ec4147d75c3d` | `bce18760d4aa85d69dd9a7924a26f09e92034443` |
| `dlg_conf` | `4741fc2a9dda2d3c406c48e19deeede180b9d9d5` | `0d9e0663c0e17fcfd1cb0f5422eb502038968e05` |
| `dlg_dip` | `0e46df11dd2be9eb91f456e388cc4398cf654ff8` | `7ce42334ed6b0dd218d2dd675339606013464fbb` |
| `dlg_help` | `fe0cd547eb4cda536c6f8e9a72f1d460e9bcbce9` | `ce9a76fda6045d0a20682ed9f593c1229b4dd5ef` |
| `dlg_menu` | `5b983f7bb623d14a3afb393fd7d7059e2d3a6b63` | `f7101de691cb803416c14d332dfb9552e2d0949c` |
| `dlg_msg` | `60f781599a8e1009e8ba2ad45a3b90ec55debdd5` | `7ed4715f6f77898336f7bbcb4ce559ee682d8d3f`, `99ecd363fcc2ab55088bf3fc9982c97f12ee39d4` |
| `dlg_sedm` | `5aaf64d424c1213619316c65dfa3a95f655bbf05` | `883b6ff5d50f93398213ac75ad36f8b39e390a55` |

## Validation status

Compilation, matching, audits, and tests were not run.
No compiler, build, game, or runtime command was run.
All results remain reviewed but unvalidated.
