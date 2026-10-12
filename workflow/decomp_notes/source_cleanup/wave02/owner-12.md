# Wave 02 owner 12 integration ledger

## Scope

Owner 12 integrated these communication modules:

- `src/com_addr.cpp` and `include/com_addr.h`
- `src/com_err.cpp` and `include/com_err.h`
- `src/com_loby.cpp` and `include/com_loby.h`
- `src/com_q.cpp` and `include/com_q.h`
- `src/com_serv.cpp` and `include/com_serv.h`
- `src/com_sess.cpp` and `include/com_sess.h`
- `src/com_spd.cpp` and `include/com_spd.h`
- `src/com_sync.cpp` and `include/com_sync.h`

The common base was `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
The initial reviewed pre-ledger head was `2c809b219a009c395ace2d9f7e907d2da9d00888`.
The reviewed follow-up head was `b0ef4585700912af1a06c6c741aad32da2479cb7`.

## Workers and integration commits

### `com_addr`

- Worker: `sa-32d6a813`
- Worker branch: `cleanup/staging-20260915-101`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker head: `b2545d3f417b104f6db9714b4c5e9a199f04d267`
- Worker commits: `04abef9192d97f572b31fc84eb5f81f010cda39e`, `b2545d3f417b104f6db9714b4c5e9a199f04d267`
- Integrated commits: `4f09eaeab3e96a66103dbe8209a8284ec1cb5090`, `62b8541ee3482350976799ca193dab53d548f62c`
- Header commit: `cabc24c4094ff292c72c39f7d0beb266165483bd`

Recovered mappings were `handler` to `CommIn`, `out_buffer` to `sz`, and `index` to `Num`.
The source retained locals without PDB records.
These include `wsResult`, `buffer`, `he`, `alias_ptr`, `alias`, `host`, `address_ptr`, and `address`.

### `com_err`

- Worker: `sa-5013b32c`
- Worker branch: `cleanup/staging-20260915-102`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker head: `938876f15328ec46aec250caef0541a5349cde00`
- Worker commits: `a7d93f5c181cd5be30a60dd5c81756d8faf9d394`, `938876f15328ec46aec250caef0541a5349cde00`
- Integrated commits: `2354d7052ada112dcbe070922d43183ce51b6860`, `c22a2d47d511b79b36aff05bb87de7ed043a5ae1`
- Header commit: `33339bdafe88dee3927817cdd4a4e82dd0ec65f1`

Recovered mappings were `param` to `Host`, `param` to `lparam`, `code` to `hr`, and `context` to `Text`.
The four functions had no unresolved scoped local mappings.

### `com_loby`

- Worker: `sa-848b8927`
- Worker branch: `cleanup/staging-20260915-103`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Initial worker head: `92fce4b20a1ebaf257b65684a22a0e49cd30c7cc`
- Corrected worker head: `df006999e04a57cf19b8825ba73fcbf406c218ac`
- Worker commits: `371a67c44fa9287b9235eed340c0f611431ef87a`, `92fce4b20a1ebaf257b65684a22a0e49cd30c7cc`, `df006999e04a57cf19b8825ba73fcbf406c218ac`
- Integrated commits: `69f818d4166c9f3d8f593a406f857c5c52f5dbc1`, `6009d03f2795f712dca8e5632904b85e9ad6f5fe`, `1b122b877d241b5b94403fc289b006bc725a6a1a`
- Header commit: `1c09b3ecbf35678e7c6ea46e75ef4e4e7eac5400`

Recovered names include `Host`, `pidID`, `direct_play`, `player_name`, `info`, `Data`, and `dwSize`.
The source retained `result`, `connectionBuffer`, `pLobby`, `message`, `dwMessageType`, `msgType`, `total`, and `header`.
The PDB has no scoped records for those names.

Owner review found an incorrect function count in the first report.
The worker corrected 14 to 13 in a new commit.

### `com_q`

- Worker: `sa-0c787195`
- Worker branch: `cleanup/staging-20260915-104`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Initial worker head: `75e88b61ffbf7b8d2137b75f1550449797981707`
- Corrected worker head: `c7618ef157f76577db9b344474119ad4c05db800`
- Worker commits: `6ed37f20af52505b7d632bbddb6819378f11b1a7`, `75e88b61ffbf7b8d2137b75f1550449797981707`, `dfdfa04fda23e9c58af7354c684fbc5a27341a14`, `c7618ef157f76577db9b344474119ad4c05db800`
- Integrated commits: `5ddb06d52673d4ebaff8eef9e4665ee5a878bf4c`, `01aeccb5d1a94fe20d1c74cd1ddc0703e2e3a75b`, `10d798e19ea808ac20d0c678432c15542d184e45`, `b0ef4585700912af1a06c6c741aad32da2479cb7`
- Header commit: `2b96dafa530caa7306545be91900324e2dc9d0fa`

Recovered names include `MaxSize`, `NewQSize`, `TurnID`, `PlayerNo`, `LowRange`, `HiRange`, and `Count`.
They also include `ExecuteOnTurn`, `command`, `nBytes`, `PFrom`, `InSequence`, and `ControlCommand`.
Other recovered names include `FromPlayer`, `Seq`, `Size`, `ThisTurn`, `SendMsg`, and `p`.

The source retained locals without PDB records.
The module report lists these unresolved names by function.
No reused stack slot received a forced mapping.

Root review requested 1TBS formatting for two standalone `else` lines.
The same worker made the whitespace-only correction and updated its report.

### `com_serv`

- Worker: `sa-b6248b9b`
- Worker branch: `cleanup/staging-20260915-105`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker head: `23c76ef3a1099ec9ac2dfa61794c3cc6e6c52ca4`
- Worker commits: `d5b80fde34c8c9df93ab2d71497a4831d607b560`, `23c76ef3a1099ec9ac2dfa61794c3cc6e6c52ca4`
- Integrated commits: `ef5e7375ce27f12c35e5404978469d084709526c`, `539577c382d33dfe1f290289d17ca1cf41ad7d63`
- Header commit: `d3ab55db673bc68dacf2447cf19126ceb1c67bf2`

Recovered mappings include `index` to `id`, `serviceIndex` to `id`, and `name` to `Text`.
They also include `guid` to `gid`, `active` to `state`, and callback names from PDB.
The callback local `directPlay` became `lpIDC`.
The hidden `__$ReturnUdt` record remains compiler-owned storage.

The source retained `i`, `services`, `count`, and `result` without original-name claims.

### `com_sess`

- Worker: `sa-21b0753a`
- Worker branch: `cleanup/staging-20260915-106`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker head: `26ccde35223d02151eda7e2468786f0b661f2bba`
- Worker commits: `0c5c24a2deaca1e91000b488d304bf9ff864f6ca`, `26ccde35223d02151eda7e2468786f0b661f2bba`
- Integrated commits: `c3360cf00614da2fe79a6f0bdb89def437f3108a`, `d98dc4f2b789e59687b7bb3b413aa4b42932ec7d`
- Header commit: `a6b6d74dd85d03216b37cedb7101895eb6c90090`

Recovered mappings include `handler` to `Comm` and four `index` parameters to `id`.
`AddSession` now uses the ten PDB names from `Instance` through `User4`.
`Refresh` local `desc` became `dpDesc`.
The callback and GUID comparison parameters now use their PDB names.
No unresolved scoped source-local mapping remains.

### `com_spd`

- Worker: `sa-49f33844`
- Worker branch: `cleanup/staging-20260915-107`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker head: `4b8d33d5a1bceede306fccd4f683e7dcfa166a42`
- Worker commits: `1604a42cb8c509560becb37130e8cfdf47f32ef8`, `4b8d33d5a1bceede306fccd4f683e7dcfa166a42`
- Integrated commits: `74d658ad38e6d063d50b2248e937416cb98b13c5`, `8776067c19a28bb799d223b2de8263a6ce285876`
- Header commits: `ac45faef382b5d7a1394a35abe4f30c8d418d390`, `2c809b219a009c395ace2d9f7e907d2da9d00888`

Recovered parameters include `c`, `PlayerNo`, `AvgFramesMsec`, `HiLatencyCenti`, `Msec`, `BuffCount`, and `BuffGran`.
They also include `ExecTurn`, `TorF`, `current_turn`, `v1`, and `v2`.
`AnalyzeGameSpeed` already used `NewGranularity`, `NewBufferFrames`, and `ChangeAlso`.
Owner 12 restored those names in its declaration.
Recovered function-static names are `buf`, `speedstr`, and `Info`.

The PDB reports smaller source array types for `buf` and `Info`.
The source retains the proved baseline sizes of 152 and 256 bytes.
The source retained locals without PDB records.
The module report lists each retained name.

### `com_sync`

- Worker: `sa-e6d1f1c2`
- Worker branch: `cleanup/staging-20260915-108`
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker head: `b8fef90d79ab60e3966247f5ed919033bdfd3814`
- Worker commits: `ccf8c2ef4f8c259b2bcc229cdef7b11b9e8e4883`, `11dd95f006b7556403907b4ae4ab24911f5d530d`, `d6b1ce77114eaba8afadfd24188ffcde75eea1ce`, `b8fef90d79ab60e3966247f5ed919033bdfd3814`
- Integrated commits: `48c1b2ec883f95e398ddac73feab524467605ed0`, `129e3454c95519cfcf6517700a73ecdccbeb3b47`, `b3186e2edde5a4f73e7808d74097d02e9f102443`, `b3d42a0bc0336fb67b21c3efbf02a3b8e755386c`
- Header commit: `00722a506a5ed095719e840c1b22f4305144a76d`

Recovered names include `c`, `player`, `worldtime`, `worldturn`, `worldrandom`, and `cs1` through `cs5`.
They also include `lwr`, `Status`, and the existing `IsPlayerOutOfSync` PDB names.
`player_index` is a new cleanup name.
It resolves a local conflict with the recovered `player` parameter.

The source retained locals without PDB records.
The module report lists them by function.
No uncertain storage mapping changed.

## Header review

Owner 12 applied each worker's PDB-supported parameter names.
The header edits preserve types, declaration order, calling conventions, and layouts.
No public symbol, member, enum, macro value, or shared layout changed.

The combined review found no header name collision or macro effect.
All source and matching header parameter types agree by inspection.

## Shared and resource requests

No module uses a resource lookup.
No resource ID mapping is pending.
No request targets `include/resource_ids.h` or `include/game_globals.h`.
No cross-group declaration request is pending.
All owner-owned header requests are complete.

## Review and validation status

Owner 12 read every complete worker diff and report.
Owner 12 reviewed the combined source and header diff.
`git diff --check` passed for each worker and the integrated group.

The review found identifier, comment-reference, and brace-placement changes only.
The source retains casts, types, scopes, evaluation order, calls, literals, and known defects.
No structural rewrite, helper, layout change, or assembly was added.

Compilation, matching, audits, and tests were not run.
No build, game, or executable validation command was run.
All results remain reviewed but unvalidated.
