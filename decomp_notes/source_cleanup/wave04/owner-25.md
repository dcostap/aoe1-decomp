# Wave 04 owner 25: players and commands

## Scope

Owner 25 reviewed and integrated these source owners:

- `src/player.cpp`
- `src/tplayer.cpp`
- `src/tmplayer.cpp`
- `src/com_hand.cpp`
- `src/com_obj.cpp`
- `src/Command.cpp`
- `src/tcommand.cpp`
- `src/tobj_lst.cpp`

The common base is `c22ba4258c45b1178181e185d60a3b09a1add617`.
The owner also updated the eight matching headers.

## Worker deliveries

| Module | Worker commits | Integration commits |
| --- | --- | --- |
| `player.cpp` | `ee934757e344c476cfb56fb5ae84113690603d3b`, `21904e686bf21c1327b89c11ae2a1b5d7ad2403a` | `a1d2a5c4d555bac10bf9eeaad0a7a2d2378b9640`, `d70f19344f30e49f1cb6e078dd989cbb274ef9a7` |
| `tplayer.cpp` | `b55b6d4e480488bf47d0a8ceed53639dc70ca6ae`, `93bec630cac14f33d4dcab822779006a3d114ec4` | `34aee64465a3daad581964f0bdc3afbec3b041ad`, `2e1a6e41103318f946e76f54463c7160a848dcec` |
| `tmplayer.cpp` | `a540c0409504a58501d7fe0a97b87e7b5e68c52f`, `0f6b6f8454d2cb980007a4a1cb0eb70a239897a9` | `fa54a8cdc59b8e0732617a450f82419711dbc1f6`, `74b9b72b2518e8b85310233f9e447b4283da8773` |
| `com_hand.cpp` | `6d0a12480437318b0590c5f956844dcb3be8d30b`, `2190866426979b55ee91c0c86050a37242e7e2c9` | `9941de0c4230bcd866ae517f318c14a1be2774ae`, `3e0a2fff3a931d88ef4db0208d1903ee7031a094` |
| `com_obj.cpp` | `81c9c0021f91a9b63fb38448f87bb51379763d67`, `0738f55c91c4b2b054d7b95dc4160c7ed074a785`, `97fd3db53fce3a4e152a59267a0720ea16e69f6d` | `53c88a39b6e1ae33da4896d4e2e516a91e0a569e`, `53888e2371907dce197a97240406563f4e2540c1`, `46837748ec2d2222f8f1bafae15060e4263e58ff` |
| `Command.cpp` | `559ed5444e83cf575323b39bb3aecbb39d123b9c`, `900642e750154d59bd053eefc2fec8f51feacbd5` | `7b3d0f97c59e099dc9d025777416fbdbdff9b4a6`, `11dead6da3d2ab82bda7004e748bd8b157acd456` |
| `tcommand.cpp` | `47c1f1ba9015c9bd92c144a13b2555694ed0976e`, `83e3072b6b4d64fc8d6d36bdf25f2fd3e9d39db9` | `341e2911715f5365d702bab268815cdeb90c947b`, `a17b29e8053ee087a158a2254ba00325cacf3f5f` |
| `tobj_lst.cpp` | `97869ea32d964341c47cde51aad0bad7ac4fc487`, `7d1721744a59341567035c1b1aeccd4554e2bc68`, `a4ac5c9bbd2f169b18a81209f177ad0a3be73225` | `20a213053d2bd65ae250cd35f4ba0dcb73801f15`, `dfbf5a8a0f211a3199f0cf6f524de858642d48e3`, `e163e3d85af4a17211c77c00abb67e521f8ce4ef` |

## Review findings and corrections

The owner reviewed each complete source diff and report.
The edits recover procedure-scoped PDB names and apply the required source style.
They do not intentionally change behavior, types, scopes, calls, literals, or layouts.

The owner returned `com_obj.cpp` for an incorrect header ownership statement.
The correction now assigns `include/com_obj.h` to owner 25.

The owner returned `player.cpp` and `tcommand.cpp` for exact delivery hashes.
Both reports now contain complete delivery history.

The owner returned `tplayer.cpp` and `com_hand.cpp` for 1TBS corrections.
Both reports now include complete resource evidence and correction history.

Header names use reviewed source or procedure-scoped PDB evidence.
The owner did not add unsupported names for three ambiguous `player.h` declarations.
The owner did not add the reported `reallyLoadAI` name to the three-argument constructor.

## Header changes

The owner updated these declarations without changing their types or ABI:

- `include/player.h`
- `include/tplayer.h`
- `include/tmplayer.h`
- `include/com_hand.h`
- `include/com_obj.h`
- `include/Command.h`
- `include/tcommand.h`
- `include/tobj_lst.h`

The changes add proved parameter names and wrap long declarations.

## Shared requests to root

No worker changed `include/resource_ids.h` or `include/game_globals.h`.

`tcommand.cpp` requests review of `IDS_ERROR_SYNC` for `0x0966`.
The base DLL text and the out-of-sync call site support this request.

`tplayer.cpp` requests review of these proposed mappings:

- `IDS_TPLAYER_NONE` for `0x2775`.
- `IDS_TPLAYER_RANDOM` for `0x277B`.
- `IDS_CIVILIZATION_NAME_BASE` for `0x27F6`.
- `IDS_BUILD_LIST_NAME_BASE` for `0x26930`.

The first two IDs have exact base DLL text.
The civilization expression selects the documented `0x27F7..0x2806` range.
All inspected DLLs miss the complete build-list range.
Root should not add the build-list name without more evidence.
The module reports contain DLL paths, hashes, languages, and lookup results.

No shared global or layout request remains open.

## Validation status

The owner used Git status, diff, log, and whitespace review commands.
No compiler, build, match, audit, validation, test, or game command ran.
This integrated group is reviewed but unvalidated.
