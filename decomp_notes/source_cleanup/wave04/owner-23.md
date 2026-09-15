# Source-cleanup wave 04: owner 23

## Group identity

- Group: drawing and sprite support.
- Integration worktree: `build/source-cleanup-20260915/wave-worktrees/slot-199`.
- Branch: `cleanup/staging-20260915-199`.
- Common base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Owner header commit: `390c1d44bd7adc5f7e229780672cdf0f675f362e`.

This group owns eight source modules and eight paired headers. Root owns all other headers.
I reviewed each complete worker diff and report against the common base.
I integrated each approved worker commit without omitted hunks.

## Module ledger

### `src/point.cpp`

- Worker: `sa-3a1a901d`.
- Worker commits: `5d8b041d307096bbaf217f847c5e7ffa9e810f20`, `8a97e17215889fd9142aab0efc8ab6d8663b0da3`, `10ae482037415ccb1b508aea4d9ced1bd0e59352`, `44a132a636301ab777f8d2d7e244b9542c54f383`, `4d4a612cd2c039cf4f03b1eb0279e087465d0f0f`.
- Integration commits: `227b1ab1273fe62f0660690104dfe95186780519`, `963be56daa38e0281ad6e4a3c15dab676cbe41b1`, `26442d2f15c02b24df8426561083a247da6ff5e1`, `fed22adff6ae0f7a8a3762af527290197465063b`, `05a8b89d676b1875a1930f7f359588d3e8bb9c55`.
- Report: `decomp_notes/source_cleanup/wave04/point.md`.
- Review required evidence wording and one short signature correction.
- The same worker made both corrections and recorded them.
- The owner added proved declaration names to `include/point.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/Mouseptr.cpp`

- Worker: `sa-37d7caf9`.
- Worker commits: `bc965c6300baff1c6e00e5894ef6240cb08a3ce1`, `bda788a71850724134e6dbcff8885cf39b24a87a`, `b178b76537813a721d1a30e6fb55d96c3a6b3bef`, `574b9da6c949fa2a9bd3916b9a29823a775a4078`.
- Integration commits: `c33644bbf2e60ed2025a1cdb7fd601147cb8c1c6`, `28412313d4f59a9f6c85353d4c89ca8ce9b1f45c`, `13f39785badce50cb4ad82fb375ba829787beeb8`, `84132f866afa4769f29a145409587300bdbae62f`.
- Report: `decomp_notes/source_cleanup/wave04/Mouseptr.md`.
- Review required the short `setup` signature on one line.
- The same worker made the correction and updated the report.
- The owner added proved declaration names to `include/Mouseptr.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/asp_list.cpp`

- Worker: `sa-c23fb016`.
- Worker commits: `a1096f481186165355c3be6ddcef2fc5fd0ff305`, `840b1f1cf9fbdf9b026f7e885b419e3ab29b3018`.
- Integration commits: `058c2a8827796bb60a715e720f1af77c5ffc46f0`, `c776947c660ba1646b979edf704ad53705174831`.
- Report: `decomp_notes/source_cleanup/wave04/asp_list.md`.
- Review required two short signatures on one line and removal of one duplicate comment.
- The same worker made the corrections and recorded them.
- The owner added proved declaration names to `include/asp_list.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/asprite.cpp`

- Worker: `sa-e1d7cfbc`.
- Worker commits: `a99d06fa03378a6f7758b2a19322377d52f36200`, `7e3e6e79bffe98e55a8367587488e4adcf8ffb2b`, `cee47c1b02e097b46319df648e3b89907b49aa75`, `fac2992775c439d0940434328cb32d1b41354ec3`, `78e2ff19c76cebe290eb3b74abc8e8c6fdd74166`, `a45d1437a8fa96602c961a81969d9bcf577c62d6`.
- Integration commits: `2e30a2fae17663502e1afa20f4e65d1fa72222d0`, `fbf6144f6d4c9e14fbb43c5f768dd5117fc7d62c`, `c803f1adc0752c5ed0e2a1c2842afaea20e6c472`, `890cf650bf89ab8be01bcb9603d564d468301259`, `f58223bcceea3a755b6dcb6fb2e6b9bcb329717e`, `8635d6e0d58ef771d13a337c104ba38f5cc7f97b`.
- Report: `decomp_notes/source_cleanup/wave04/asprite.md`.
- Review required three short signatures and one short call on one line.
- The same worker made both corrections and recorded them.
- `include/asprite.h` has no declarations. The owner left it unchanged.
- The matching declarations in `include/asp_list.h` received proved names.
- Status: integrated, reviewed, and unvalidated.

### `src/drawarea.cpp`

- Worker: `sa-09e5227e`.
- Worker commits: `8f3614a40c104690b286f317826bf243819ef24d`, `70786af872caf21fe9cac982976b978a73db7496`, `3e1717b9d3b7cc264bcdb63748cdd442c5aa4e32`, `0f3b3ba8c8a7f4494b884f237f8e9909db9a428b`, `fbb40e6e7c479823c8a4348b68e525950cd3bcbd`.
- Integration commits: `3999c9c5e9a1d619d4c94e53423c6eb2a0e26e44`, `61934d92d797078a317e00955063c3833ee51a37`, `be665b4ffc99f540cc485f3ab60eb0a57be90ad1`, `9ee0fe81e5a0007aaa74edd6d0964b3deaf6c591`, `f374b3171e8750eab2c528ec333f4c3d9dd4fabb`.
- Report: `decomp_notes/source_cleanup/wave04/drawarea.md`.
- Review required 1TBS formatting and report correction history.
- The same worker made the correction and recorded it.
- The owner added proved declaration names to `include/drawarea.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/spanlist.cpp`

- Worker: `sa-f3e185d2`.
- Worker commits: `092cafdf58aa0e6be50e126a6a046b66ea29508e`, `44841477e550b0a1e07180a7945d42f9a752be83`, `324bf1c3c410408df64f3b65c1b3389ec37f9602`, `4767dab8ef922a8e2aee74be8c4fbea3db63b33a`, `2c9e9c7737e4362a25f9168c8d8906d123f85ab4`, `6600cb6f6393d50ddff4eccbab02ea55acc0864f`.
- Integration commits: `dac62c8abdc3eb9f754624d092df7414238ebd49`, `eeacd4ddcad030a50962eb927df6619aac34bc52`, `c93d7959832500dcc68d291b86f051e3bf4319de`, `b602559e8879dd7d1ac06773ae05711ddabd65e4`, `a967c4b2df1b814c21eec2a5e67ee4f168888eb4`, `5c0e2dbf07c5a5165e087890abdf3157bcc1b242`.
- Report: `decomp_notes/source_cleanup/wave04/spanlist.md`.
- Review required 1TBS, short signatures, and removal of one redundant comment.
- The same worker made the corrections and recorded them.
- `include/spanlist.h` has no declarations. The owner left it unchanged.
- The matching declarations in `include/drawarea.h` received proved names.
- Status: integrated, reviewed, and unvalidated.

### `src/sprite.cpp`

- Worker: `sa-474631c6`.
- Worker commits: `e08c04ec673f459c01a049107868db2aecf4a4d5`, `080c03fc194a7587c3550de7593aaf5228b78b22`, `98b8100b1b9c4c4792312b6b7f54b10afab33715`, `e49c73ec2474b62ee92eb50afaf2d85437e8036f`, `5b80c2bd7e5e958b8d03d7e8b2c7bc2942d15915`, `691b89266f871ea7502df26292a1c2b00a02f687`, `bc6f22ca4f1815a870644eda4c94d9fae45bb25b`.
- Integration commits: `400f6e9cf312466620ded7b6c4c79d28b8c8d56f`, `56284ea9ea715fd4e18e7fc8e4e00c833caf1553`, `4c2f8a916390834dbbd82471411e3c616b8b36e3`, `c42183066b98ac740296d63ee8f8775b1447758f`, `2d00fc5ca8c02ea54f69937323b126539e29391f`, `75c0214a33b86b667fa998786d243ae324df24ae`, `c4de16b4c7e8c328c1f93a129b8a73a2d11ca72f`.
- Report: `decomp_notes/source_cleanup/wave04/sprite.md`.
- Review required name alignment, evidence wording, 1TBS, and five short signatures.
- The same worker made all corrections and recorded them.
- The owner added proved declaration names to `include/sprite.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/Shape.cpp`

- Worker: `sa-d8f10f9a`.
- Worker commits: `a36f10970e39040f9cba4b4b05a4c24c4aeb6408`, `5b1db5700ce11f0f9226273615cac0d78806e53a`, `9daf4149ed986fbb4683ab8a6774efa2f0e9265c`, `e063f8ce9a00c69355010f7abe0c3863edeb3057`.
- Integration commits: `7bd64195505f9c9ac07c0068e793fff91c4a59a4`, `764b0e10d531615a3a7a61aad2b3f349da014163`, `0c641cf1789a1293119c1055c111e6b3c62f5a52`, `7f2e1f55fbb63bbef653ef8dada16bcd2393f23b`.
- Report: `decomp_notes/source_cleanup/wave04/Shape.md`.
- Review removed unsupported resource-file claims and corrected the header ownership statement.
- Review also required PDB declaration names and ten short signatures.
- The same worker made all corrections and recorded them.
- The owner added proved declaration names to `include/Shape.h`.
- Status: integrated, reviewed, and unvalidated.

## Header review

The owner reviewed all eight assigned headers.
The owner changed six headers with declarations: `Mouseptr.h`, `Shape.h`, `asp_list.h`, `drawarea.h`, `point.h`, and `sprite.h`.
The owner left `asprite.h` and `spanlist.h` unchanged because they only include their declaration owners.
The changes preserve parameter types, order, access, virtual slots, layouts, and symbols.

## Findings

The PDB stack-home reuse does not prove names for some local variables.
The module reports keep those mappings unresolved instead of forcing names.
The `drawarea.cpp` report notes a PDB `int` record for the existing `long rect_wid` local.
This cleanup keeps the source type because name evidence alone does not prove a type change.

## Shared requests

All declaration-name requests targeted headers owned by owner 23.
The owner resolved those requests where the assigned header contains declarations.
No worker requested a new resource ID.
No request targets `include/resource_ids.h`, `include/game_globals.h`, or another owner.
No cross-group request remains open.

## Review and validation status

I reviewed the complete combined source, report, and header diff.
Compilation, matching, audits, validation, and tests were not run.
No compiler, build, audit, test, or game command ran in this cleanup group.
Generated code, data, relocations, and call targets remain unvalidated.
Final comparison must use the preserved pre-cleanup build.
