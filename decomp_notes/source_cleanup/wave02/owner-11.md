# Wave 02 owner 11: additional screens

## Delivery scope

- Group branch: `cleanup/staging-20260915-91`
- Common base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Initial reviewed group head: `ad4e8c9b917e77b44b12c04fe87b46e762421355`
- Correction review head before this ledger update: `9daf9fe7a64a05dde6cff1e529128f9482fa219b`
- Sources: `src/scr_ach.cpp`, `src/scr_cred.cpp`, `src/scr_end.cpp`, `src/scr_info.cpp`, `src/scr_mp.cpp`, `src/scr_mps.cpp`, `src/scr_stms.cpp`, and `src/scr_trb.cpp`
- Headers: `include/scr_ach.h`, `include/scr_cred.h`, `include/scr_end.h`, `include/scr_info.h`, `include/scr_mp.h`, `include/scr_mps.h`, `include/scr_stms.h`, and `include/scr_trb.h`
- Module reports: the eight matching files under `decomp_notes/source_cleanup/wave02/`
- Owner ledger: `decomp_notes/source_cleanup/wave02/owner-11.md`

All eight modules remain reviewed but unvalidated.

## Workers and integration

Every worker started from the common base above.

| Module | Worker | Final worker head | Worker commits | Integrated commits |
| --- | --- | --- | --- | --- |
| `scr_ach` | `sa-0fb9a985` | `6af0bc7087f80f5ca7dc9f4eaef7da69318f32c3` | `7f952f638fd0b1878b080638cb609f2df9d8f6c0`, `e99a69943c9f34c99d29a05468b619e2370442f3`, `8c9d4f5906e9e3fad85af1f3602100285744da61`, `48b5a12f9afef3b5ab6af8f30d7450d68b827894`, `6af0bc7087f80f5ca7dc9f4eaef7da69318f32c3` | `5ff8f61938a13e97540b8317dc579f9e24110294`, `21ec5272da5223f5a0621c9e2996722d234d6b33`, `f568f3c5d6ce2051b458016574dcac586070ab38`, `b0e8aa43373226cea5e700a6b05d7d080682037f`, `28e17981e7f591c1470bb0331d7ec7d235da8f3f` |
| `scr_cred` | `sa-14ad86eb` | `4e5475964355af9a46ef8bad33f3be8a1db257c1` | `5b99767f8e35251ae5420efd086f1b5fda3d1ea1`, `3b2e9770d9064ee5a539aa5c70035db9118899b7`, `4e5475964355af9a46ef8bad33f3be8a1db257c1` | `640eed9abd3452e7e24318491cdc67f1c18c4ef5`, `5aaf769e4e28e5e89384d981a9a98a62b821d5f2`, `941ac7e1cbae2d43714a732bb22ef3bd39a6b155` |
| `scr_end` | `sa-62140373` | `15422022152dc29c9b43c0fa41b13b4fbf745110` | `e252a26e474b9dac0f2c1acc4365f663336a3f01`, `15422022152dc29c9b43c0fa41b13b4fbf745110` | `0f15797b6a7df7dc06408fdec328fe6f4dd13079`, `78c72bcdd0cc57ddf1814fc1e0d984bb2284a883` |
| `scr_info` | `sa-0f7d6148` | `d8f7ae3e5efeacef038616546049b0970ef33fe4` | `1c0c10bd6edd401f7c70b1a47173fa854bf5c8fc`, `d8f7ae3e5efeacef038616546049b0970ef33fe4` | `75dfcd966941b06b350ae25f9fce065e4371d110`, `9ebaef0b62a8f65fdd972fe7f64f326bde1afd72` |
| `scr_mp` | `sa-f8e3143f` | `eae6a694178e13319b6a461281f71c9062b76265` | `912b0bfcbbab02983140042a44b5c7d010d9fd75`, `c0be67dfc08e3d6a7711dd4b18d346fac930d61a`, `f3206b33cc4eacada5ed0c74d11971392e24032a`, `0a0f4dffe28d63d8279ef278b8d4d0551317ddbf`, `eae6a694178e13319b6a461281f71c9062b76265` | `9ea35d2f5b68fc0a1d032c985413d355539fc692`, `d217c0f9b37e697ab074ae4b5faedbeff584b8d4`, `85bbd8bbcadf99d43a4de693e4c7406348bc9f93`, `8a1158c247da1300e62fed893c2374af9c882933`, `1457e9da1a60a1e80c5c421765a6ada657977fa6` |
| `scr_mps` | `sa-c692cf41` | `efcb419a4ad3b37f757cb24fa57163752b987e9e` | `7363d3718ae27a56c842b0946e59c94c39a56125`, `381ac8ad845101418d11c79da39d61adfe9399c7`, `f6dae9c2b92f5ce44d004afdf869bef095f03581`, `4e01c849aea86f105483aef6252bce68c536738a`, `efcb419a4ad3b37f757cb24fa57163752b987e9e` | `b2d924e7711f215940b16ae8bbd37e9f23b3e414`, `571f29acecf605a4121419fce639d7b2962eaf36`, `9328eb61063d93dfe47555ddf70516cb799f367d`, `d0a7adedd1d52bcb1995d84655da2cb3b730381a`, `b43f9bc9bfcda87493e5ff13569a8a5c39d4bf42` |
| `scr_stms` | `sa-987f1b67` | `f2a61a1487ce302dffc28a9091e84ac537eff6c3` | `d249dd19f628068cd4e96e260b5c10e8a37d6e1a`, `f2a61a1487ce302dffc28a9091e84ac537eff6c3` | `621ae246a00cc6eda019fe9b2d2fe0d187850fd2`, `cd517d3e9fd07e2e81d0930f4051d1697510b93f` |
| `scr_trb` | `sa-4992bfbc` | `0d1dd96c0d6479e07e64c26e2706e938207adc80` | `6ced4d26dd1c9bf873c58ba8649f46971dea79b6`, `a5909d1b9ce46a9006aa5297e47fc6cfc8ec4f90`, `0d1dd96c0d6479e07e64c26e2706e938207adc80` | `872e046ac4359ee50ee9f116009ba30f22602960`, `b6a5154d6407cf49e5cb4cbcb159ab1d9965a8ff`, `f8da83e41a68349f516ba41b9b5cf0e8ea6ef495` |

The `scr_trb` worker created intermediate correction object
`9ddbb8ae246de4fa28b04f55d514443f264c2ff3`. Its final amended correction
superseded it. The object was not integrated.

Owner header commit: `412be0cccf0a953760519ce7b7bc350406874ddb`.

Focused root review required presentation and evidence corrections after the
initial integration. The correction chains remain separate commits.

| Module | Corrected worker head | Additional worker commits | Additional integrated commits |
| --- | --- | --- | --- |
| `scr_ach` | `c4670cbe9f6e0461ecafa8905ebc343679ff804f` | `575575b0b6f8e7774bb68d45eedfb0737be8bce7`, `c4670cbe9f6e0461ecafa8905ebc343679ff804f` | `86ff13705d905d821d80975238ccf2a7b9073f47`, `f468d160e3ec03d4925c3847f27a44a2d672f1a8` |
| `scr_cred` | `66ea3e0f4c9f41d9fdea133bb10b7beb8d6703f2` | `5842248aa71cd3ccdf2f800902f44ad476f51210`, `e92959ab36b06198a74c28146b499c037f0a8216`, `641a1218013c112de1707d8f3e471c26bb92b4a1`, `4fa0ec14605f7bd6a1c05e8ee713efb4041a9d20`, `3b9305d6a03f6913dd71ac1686467467337fba75`, `690da0d79225b7126cdff62836b1d591f97dfc92`, `66ea3e0f4c9f41d9fdea133bb10b7beb8d6703f2` | `95c9b04e3f0855e0bf61661416ca4eb5b24623d4`, `a9919fe8ae5cd292e090b9bedeba807ec686f49d`, `5742d6deb62b7053b0d8c56c7f9d6633f207ee9a`, `afb677dc6f1c575ad9bc2aa3ff74757dc2f6f425`, `4f32bced31b5ba3e0124b9c36765cb4e2ce961b6`, `54f812c794a332fbd41ccfc4c131bf8bee3d25a9`, `7ed1ef9a9dfff2f41319a615ad9eb76d576f707b` |
| `scr_end` | `59fe2d19bc70e61c3ff86af792485b6579b25ec2` | `87b8556a3ec3d4084e2ec55a88d8f0e91b251702`, `59fe2d19bc70e61c3ff86af792485b6579b25ec2` | `1eb69fd1134025d60ce362c5d5c993a10c8ac46d`, `1da92e2dbc4ed86d664e207c3dd2766e32b67e2c` |
| `scr_info` | `4fea9d562931344d3f4af6d54a9b8acbfdf26524` | `f31e86c42def400fb8747401707c153426dc7ff1`, `4fea9d562931344d3f4af6d54a9b8acbfdf26524` | `b7e62ed24bcd65a4f048b63550c1156e117f6054`, `9833b6686fbe4a23a1b4b8abad4c03b4b4cba758` |
| `scr_mps` | `87b578a1333cfa985e7c9de24b8935e04824b846` | `913677d4e6fb0d1f831d5de47fd8247e51cf43c6`, `5dccb06ffd7366df9a34487424b79f8d27bad237`, `b091d3a5fcf0925e958de79b2f6338d6c20b0fd0`, `9709313fb7e9a7e930448b54eafb545a9fba7c32`, `87b578a1333cfa985e7c9de24b8935e04824b846` | `934dc3fa3086b24b483fc71fe54e1dbe39dc7206`, `bced0177307e6fe3883d1cbeefe8dda3093349d3`, `74866e19e2eb326dc1a66761a49b730007b51980`, `dc1673f961ec9bb429dc132b7d1f707c68d03cf9`, `7b701b8bfde46237eab1acec33bc626f1c5a782f` |

The matching header presentation correction is
`9daf9fe7a64a05dde6cff1e529128f9482fa219b`.

## Review findings and corrections

I read every complete worker diff and module report.

- `scr_ach`: returned for the constructor brace and absolute evidence paths.
- `scr_mp`: returned for the constructor brace and the four-parameter action line.
- `scr_mps`: returned for a wrong PDB hash and one split `else` clause.
- `scr_trb`: returned for the constructor brace, header-request wrapping, and correction history.
- `scr_cred`, `scr_end`, and `scr_info`: returned after root review for compact
  signatures and calls. The credits correction also required direct coordinate
  evidence and one restored uncertain local name.
- `scr_mps`: returned after root review to restore two uncertain local names and
  document direct readiness-pointer evidence.
- `scr_stms`: approved on first review.

The header commit restores the same PDB parameter spellings in declarations.
It changes no type, order, virtual slot, or layout. It also removes one
incomplete comment from `include/scr_info.h`.

Combined review found no competing resource definitions. The source changes
reuse only existing macros. All pending macros remain numeric in source.

## Recovered names and unresolved mappings

The module reports contain the procedure-by-procedure PDB coverage.
The main recovered declaration groups are:

- Screen actions: `fromPanel`, `actionIn`, `a1`, and `a2`, or the exact
  underscore forms recorded for the applicable screen.
- Input handlers: exact `mouse_button_in`, key modifier, `wParam`, and `lParam`
  names.
- Screen-specific names include `titleText`, `end_flag`, `backgroundName`,
  `message_in`, `lobbyTimeout`, `line_no`, `really_kicked`, `tabList`, and
  the credits palette names.
- `scr_cred` adds the descriptive local `action_result`. It keeps the baseline
  `second_text_x` because the PDB `x` home does not match the instruction store.

The following mappings remain unresolved and unchanged:

- `scr_ach`: overlapping PDB `txt[30]` and `temptxt[50]` records share storage.
- `scr_cred`: constructor PDB `size` is `long`; source keeps its existing `int`.
  The source also keeps `second_text_x`; the instruction store uses the reused
  `draw_row` home at entry `ESP+08h`, not the PDB `x` home at `ESP+10h`.
- `scr_mp`: PDB array sizes for `Data` and `temp_str` differ from source.
- `scr_mps`: source keeps `position_used[9]`, `selected_position`,
  `first_any_color_index`, the readiness alias mapping, and the `file_scratch`
  union despite narrower, reused, or instruction-unproved PDB records.
- `scr_stms` and `scr_trb`: unrecorded readable locals remain unchanged.

## Shared resource requests

Root owns `include/resource_ids.h`. No worker added a new shared definition.
All names below are new descriptive cleanup names unless marked existing.

Common resource evidence:

- Base: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Runtime expansion: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`,
  SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Original expansion: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`,
  SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
- Language: `0x0409`.
- The checked expansion files miss all requested IDs. They do not contain
  empty slots for these requests. The runtime base file supplies the text.
- `TRIBE_Game::get_string` checks the expansion table before base fallback.
  The `scr_mp` panel helper path resolves these IDs from the base table.

### Achievements and end screens

The call sites use these IDs for screen text, buttons, results, and headings.
`scr_end` independently confirms the `0x269E` title role.

| ID | Requested name | Base text or purpose |
| --- | --- | --- |
| `0x0C1D` | `IDS_CONFIRM_QUIT_GAME` | `Are you sure you want to quit this game?` |
| `0x0FA3` | `IDS_BUTTON_YES` | `Yes` |
| `0x269C` | `IDS_ACHIEVEMENTS_CLOSE` | `Close` |
| `0x269E` | `IDS_ACHIEVEMENTS_TITLE` | `Achievements` |
| `0x269F` | `IDS_ACHIEVEMENTS_RESTART` | `Restart` |
| `0x26AC` | `IDS_ACHIEVEMENTS_MILITARY` | `Military` |
| `0x26AD` | `IDS_ACHIEVEMENTS_ECONOMY` | `Economy` |
| `0x26AE` | `IDS_ACHIEVEMENTS_RELIGION` | `Religion` |
| `0x26AF` | `IDS_ACHIEVEMENTS_TECHNOLOGY` | `Technology` |
| `0x26B1` | `IDS_ACHIEVEMENTS_TOTAL_SCORE_SUMMARY` | Summary `Total Score` |
| `0x26B2` | `IDS_ACHIEVEMENTS_AFTERMATH` | `Aftermath` |
| `0x26B5` | `IDS_ACHIEVEMENTS_TOTAL_SCORE_CATEGORY` | Category `Total Score` |
| `0x26B6` | `IDS_ACHIEVEMENTS_KILLS` | `Kills` |
| `0x26B7` | `IDS_ACHIEVEMENTS_RAZINGS` | `Razings` |
| `0x26B8` | `IDS_ACHIEVEMENTS_KILLS_LOSSES` | `Kills - Losses` |
| `0x26B9` | `IDS_ACHIEVEMENTS_LOSSES` | `Losses` |
| `0x26BA` | `IDS_ACHIEVEMENTS_LARGEST_ARMY` | `Largest Army` |
| `0x26BE` | `IDS_ACHIEVEMENTS_GOLD_COLLECTED` | `Gold Collected` |
| `0x26BF` | `IDS_ACHIEVEMENTS_VILLAGER_HIGH` | `Villager High` |
| `0x26C0` | `IDS_ACHIEVEMENTS_VILLAGER_BONUS` | `Villager Bonus` |
| `0x26C1` | `IDS_ACHIEVEMENTS_EXPLORATION` | `Exploration` |
| `0x26C2` | `IDS_ACHIEVEMENTS_MOST_EXPLORED` | `Most Explored` |
| `0x26C3` | `IDS_ACHIEVEMENTS_TRIBUTE_GIVEN` | `Tribute Given` |
| `0x26C6` | `IDS_ACHIEVEMENTS_CONVERSIONS` | `Conversions` |
| `0x26C7` | `IDS_ACHIEVEMENTS_MOST_CONVERSIONS` | `Most Conversions` |
| `0x26C8` | `IDS_ACHIEVEMENTS_RUINS` | `Ruins` |
| `0x26C9` | `IDS_ACHIEVEMENTS_ARTIFACTS` | `Artifacts` |
| `0x26CA` | `IDS_ACHIEVEMENTS_TEMPLES` | `Temples` |
| `0x26CE` | `IDS_ACHIEVEMENTS_TECHNOLOGIES` | `Technologies` |
| `0x26CF` | `IDS_ACHIEVEMENTS_BRONZE_AGE_FIRST` | `Bronze Age First` |
| `0x26D0` | `IDS_ACHIEVEMENTS_IRON_AGE_FIRST` | `Iron Age First` |
| `0x26D1` | `IDS_ACHIEVEMENTS_MOST_TECHNOLOGIES` | `Most Technologies` |
| `0x26D6` | `IDS_ACHIEVEMENTS_SURVIVAL` | `Survival` |
| `0x26D7` | `IDS_ACHIEVEMENTS_WONDER` | `Wonder` |
| `0x26D8` | `IDS_ACHIEVEMENTS_TIMELINE` | `Timeline` |
| `0x26D9` | `IDS_ACHIEVEMENTS_SUMMARY` | `Summary` |
| `0x26DA` | `IDS_ACHIEVEMENTS_BACK` | `Back` |
| `0x26DB` | `IDS_ACHIEVEMENTS_COLUMN_INSTRUCTION` | `Click a column for more details.` |
| `0x26DC` | `IDS_ACHIEVEMENTS_ALL_ARTIFACTS_RUINS` | `All Artifacts/Ruins.` |

`IDS_BUTTON_CLOSE` for `0x03EA` already exists and is reused.
The binary `RESFILE` IDs `0xC389`, `0xC38A`, and `0xC38D` remain a separate,
unresolved namespace request.

### Multiplayer startup screen

| ID | Requested name | Base text |
| --- | --- | --- |
| `0x258B` | `IDS_MULTIPLAYER_CONNECTION_TITLE` | `Multiplayer Connection` |
| `0x258C` | `IDS_MULTIPLAYER_NAME_LABEL` | `Name` |
| `0x258D` | `IDS_MULTIPLAYER_CONNECTION_TYPE_LABEL` | `Connection Type` |
| `0x258E` | `IDS_MULTIPLAYER_GAMING_ZONE` | `Microsoft Internet Gaming Zone` |
| `0x258F` | `IDS_ERROR_PLAYER_NAME_REQUIRED` | `You must enter a valid player name.` |
| `0x2592` | `IDS_ERROR_NO_MULTIPLAYER_CONNECTIONS` | `No multiplayer connections are available.` |
| `0x2593` | `IDS_CONFIRM_START_GAMING_ZONE` | `Start your Web browser and go to The Internet Gaming Zone?` |
| `0x7595` | `IDS_HELP_MULTIPLAYER_PLAYER_NAME` | `Type your player name.` |
| `0x7596` | `IDS_HELP_MULTIPLAYER_CONNECTION_TYPE` | `Select the type of connection to make. For more information, click More Help.` |

The module also reuses existing `IDS_BUTTON_OK`, `IDS_BUTTON_CANCEL`,
`IDS_BUTTON_CLOSE`, `IDS_HELP_OK`, and `IDS_HELP_CANCEL`.

### Multiplayer setup screens

| ID | Requested name | Base text |
| --- | --- | --- |
| `0x0FA9` | `IDS_BUTTON_HELP` | `?` |
| `0x238C` | `IDS_HOST_NAME_FORMAT` | `Host name: %s` |
| `0x238D` | `IDS_NO_IP_INFO_ERROR` | `No IP addressing information is available.` |
| `0x25AE` | `IDS_MP_PLAYER_COLOR_LABEL` | `Player` |
| `0x25AF` | `IDS_MP_TEAM_LABEL` | `Team` |
| `0x25B5` | `IDS_RANDOM_MAP` | `Random Map` |
| `0x25BF` | `IDS_MP_READY_LABEL` | `I'm Ready!` |
| `0x25C8` | `IDS_KICK_PLAYER_PROMPT` | `Do you want to eject %s?` |
| `0x25C9` | `IDS_PLAYER_DROPPED_NOTICE` | `You were dropped from the game.` |
| `0x25CA` | `IDS_GAME_CANCELED_NOTICE` | `The game was canceled.` |
| `0x25CB` | `IDS_VICTORY_PERCENT_LABEL` | `Percent` |
| `0x25CC` | `IDS_VICTORY_COUNT_LABEL` | `Count` |
| `0x25CD` | `IDS_VICTORY_QUANTITY_LABEL` | `Quantity` |
| `0x25D0` | `IDS_MP_PLAYER_NAME_LABEL` | `Name` |
| `0x25D1` | `IDS_MP_CIV_LABEL` | `Civ` |
| `0x25D2` | `IDS_MP_SETTINGS_LABEL` | `Settings` |
| `0x25D3` | `IDS_MP_COMPUTER_LABEL` | `Computer` |
| `0x25D4` | `IDS_MP_CLOSED_LABEL` | `Closed` |
| `0x25D5` | `IDS_MP_OPEN_LABEL` | `Open` |
| `0x25D6` | `IDS_MP_NONE_LABEL` | `None` |
| `0x25D7` | `IDS_MP_CHAT_LABEL` | `Chat` |
| `0x25D8` | `IDS_MP_NUMBER_PLAYERS_LABEL` | `Number of Players` |
| `0x25E1` | `IDS_SCENARIO_VERSION_ERROR` | Scenario version mismatch format |
| `0x25E2` | `IDS_PLAYER_VERSION_ERROR` | Player version mismatch text |
| `0x25E3` | `IDS_HOST_VERSION_ERROR` | Host version mismatch text |
| `0x25ED` | `IDS_SCENARIO_FORMAT` | `Scenario: %s` |
| `0x25EE` | `IDS_START_GAME` | `Start Game` |
| `0x25EF` | `IDS_IP_LABEL` | `IP` |
| `0x25F0` | `IDS_POPULATION_LIMIT_FORMAT` | `Population Limit: %d` |
| `0x25F1` | `IDS_PATH_FINDING_FORMAT` | `Path Finding: %s` |

See `decomp_notes/source_cleanup/wave02/scr_mps.md` for the complete long
version-message payloads and per-call purpose.

## Validation status

I ran evidence extraction, SHA256 checks, full worker-diff review, combined
source/header review, and `git diff --check`.

Compilation, matching, audits, tests, builds, and games were not run.
Generated code, data, relocations, and call targets remain unvalidated.
