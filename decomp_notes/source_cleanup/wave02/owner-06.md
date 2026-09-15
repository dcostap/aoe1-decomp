# Wave 02 owner 06 ledger

## Scope

Owner 06 integrated these eight modules:

- `src/aibitm.cpp` and `include/aibitm.h`
- `src/aiblditm.cpp` and `include/aiblditm.h`
- `src/aibobj.cpp` and `include/aibobj.h`
- `src/aiconitm.cpp` and `include/aiconitm.h`
- `src/airesitm.cpp` and `include/airesitm.h`
- `src/aitchitm.cpp` and `include/aitchitm.h`
- `src/aibldmod.cpp` and `include/aibldmod.h`
- `src/aiconmod.cpp` and `include/aiconmod.h`

The common base is `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
The owner branch is `cleanup/staging-20260915-46`.
The reviewed integration head before this ledger commit is
`52afc0a7c56bf333dbc5f2665d8469d8c3558fde`.
The correction-round integration head before this ledger update is
`a57dc7fc493421b0eca1801c4e621d0774c8704d`.

## Workers and integration

| Module | Worker | Worker source commits | Worker final head | Integrated commits |
| --- | --- | --- | --- | --- |
| `aibitm` | `sa-f919e8ba` | `91ed643da59fb039560bb8a4e0b3bb1531ccc4a1`, `9a9674d08e5aec06e90b825eb52f812d39a56c4e` | `63d4afd33327cde5dd319b9db8f330c913278872` | `983abedcb647b01778145d5244330a2a5e593233`, `52a593bfb3df67adbbee595e8d5aef888ba461d5`, `d804f0840e2ed0b4b56bd180dc2f2c6b87eb0893`, `28f85cdd4e5f785f86bc4780e33d242caeb1897e` |
| `aiblditm` | `sa-557c869d` | `f2a2b3915c0dfadf533aa0dea139c218069674df`, `85465df59c336ac9f37f49648a60f34909b5e7df` | `98a55421f39003459469b6d2d8772ec397e6e04e` | `60471e822691ec20b9652a20790ad2e69e1c1219`, `050ba7ffe71d7debdc9b67d04703c75fcf26e875`, `8da2ce1cb729a0e1976c7b04244bbcce715a4b8a`, `c6e8abf8b6b1002ede840629d51d0d8abe9104df` |
| `aibobj` | `sa-ea44d64d` | `3428f377ef82b12af699ea52799d64ca3616ae2b`, `ec0fe00806d16ad5a5257994a7622bb8c37d08b7` | `bdd0357555af1035f0be702074c5aaec1d71eb58` | `ba57dd19b2e7ff93578710855068d71943dc97d9`, `98c9463cdd51e7a9cbc27d30f421b81e150836d6`, `092ce45f2b75e0419ebe4c71c6665e506f909418`, `948b39d29d1fe51ae4821f747dcbbedf4394ea61` |
| `aiconitm` | `sa-1b3cfb2c` | `f6db0125c423506bff5f30ce20f5337d9a56fd88`, `151a911e1acea79628f543738fd3c393d7815eba`, `891620b9264a5a6fd2f7319a3e8e9875ff860465` | `f5aafd9ad7147276d97221d6b364ff41a24bce50` | `53dedf3b5118db95d2bea8444b7f3ff2d1815025`, `2c3c3fd0d416607893950ec3ef385f684bfb5902`, `543eaffa835f4d350894eeb89b9450b46e7f15c4`, `bf594c02cd83145f5947f1cdd54b653c773ff50b`, `f9cc019209e92d2f06482d4d1673e3d379f63832`, `16032de60ebf571d192bd862f5bcb53dd6b592b5` |
| `airesitm` | `sa-ab9843f5` | `a7914437e13b44d43e1bc1470238240ae991e677` | `120d6c16be45053560668b23bc2d44aaa540379c` | `15c0e9d3c5fdbfcd155435b0100ea0588f9d059c`, `789ac8fad3be080846293a8656b1e22701b7183f` |
| `aitchitm` | `sa-b009e34f` | `676a6b609b8d016a684ab63691ca1a5ec09425d9` | `97d3a6083d7415e519eea396c7841cf2817002fe` | `783675a9813df9b28a1404f0818d028791e66fa3`, `b77019bf391137c275cf8bac2a19b53152762bf4` |
| `aibldmod` | `sa-0ed8a341` | `9f6b6017a31a4474860ff7c0af427fe088f3cfe3`, `022396649e084d169c083353c5438e98e087700f` | `bb01598261b710ffefc039673c97161f31cf1cf5` | `d336992cc19253ba02574bbee935f35735284244`, `2be145e17ed463bf94a378b7e555a1b135713758`, `7e3cb1b1c83fdfcbd40dab2bf11d7538974db1e9`, `aea451c028260131b3fbc6c0f225022fb217e1d9` |
| `aiconmod` | `sa-f3a9b78f` | `9c10e5929358cab5ba4fe0757594b8222fe1e4db`, `1b3e5335170c9f93bfa35211beb694adc87070cd`, `1546ddb642e74f0f388fcd4f111d15a6f903dc33` | `6e00e15338683cbbfd39afcd75aba8e2fa1866f0` | `4bd58a65daa6deb0a74a3b9049754d83291dbf55`, `7d1660f66f007baee56494b7b8aa30b88badbe25`, `c6b4ef3e6d3fb81f0e9752d371a1b567dd05e0d0`, `122c2879ea78e568ebf307d5ca928a1e5b844305`, `65af4d929649227e5ff0bf2114544c93e479d91c`, `a0ab826172f7325168d9993b24342309ca30b9cd` |

The header commit is
`52afc0a7c56bf333dbc5f2665d8469d8c3558fde`.
It aligns declaration parameter names with all eight cleaned definitions.
It also completes the existing `BuildAIModule` virtual-slot comment.

Header correction commit
`a57dc7fc493421b0eca1801c4e621d0774c8704d` compacts the corrected
`aiblditm`, `aibobj`, and `aibldmod` declarations.

## Name mappings

All recovered names in this section come from procedure-scoped PDB records.

- `aibitm` restores `tid`, `gid`, `uid`, `n`, `xs`, `ys`, `zs`, `bi`, `one`, `two`, and setter `v` names.
- `aiblditm` restores `bc`, `ti`, `bi`, `n`, `p`, `bf`, `tSet`, `tOne`, `tTwo`, `pEle`, `one`, `two`, and setter names.
- `aibobj` restores constructor names from `gri` through `maxp`. It also restores `bo`, `one`, `two`, `v`, `x`, `y`, and `z`.
- `aiconitm` restores `xs`, `ys`, `zs`, `ti`, `n`, `ci`, `one`, `two`, `p`, `b`, and `v`.
- `airesitm` restores `n`, `v`, `ri`, `one`, `two`, and `num`.
- `aitchitm` restores `i`, `n`, `r`, `ti`, `one`, and `two`.
- `aibldmod` restores `pW`, `playerID`, `infile`, `outfile`, `lName`, filter names, list-query names, and serialized local names.
- `aiconmod` restores constructor, file, plan, reference, item, decrement, count, and coordinate names.

`aiconmod` adds one descriptive name, `i_value`.
The recovered loop name `i` conflicts with this existing inner local.
The new name keeps the declaration, type, scope, and raw-bit access unchanged.

The module reports contain the complete VA-to-name mappings.
They also list every inspected parameter, local, and register record.

## Review findings and corrections

I read each complete worker diff and report against the common base.
I checked file ownership, PDB coverage, types, scopes, casts, calls, literals, and comments.
I also checked source order, 1TBS braces, and report evidence.

Six modules passed the first review without a correction request.

The first `aiconitm` result kept four short operator signatures wrapped.
The same worker joined those signatures in
`151a911e1acea79628f543738fd3c393d7815eba`.
The worker updated its report in
`9d84897381fd3d864b6e6c5e77cbb2ee30dc060e`.

The first `aiconmod` result kept two constructor braces on separate lines.
Its report also had one mistyped executable hash.
The same worker fixed both issues in
`1b3e5335170c9f93bfa35211beb694adc87070cd` and
`cbed63e44b7b6d4f1221d665d092eb2312e83d16`.

I retained all initial and correction commits.
I integrated each approved worker commit without partial hunk selection.

Root correction round 2 found four presentation issues and one evidence limit.

- The `aiconmod` PDB home labels did not prove four local names in both loops.
  The worker restored baseline names and documented the reused homes.
- The worker added spaces to both `aiconmod` loop headers.
- The `aibldmod` worker split packed declarations and statements in `save`.
- The same worker compacted the `insertItem` signature.
- The `aibitm`, `aiblditm`, `aibobj`, and `aiconitm` workers compacted touched
  constructor signatures.

I reviewed each correction diff and report before integration.

## Unresolved evidence

`airesitm` has existing descriptive locals without procedure-scoped PDB records.
Their stack mappings remain uncertain and unchanged.

`aiconmod` has reused and overlapping stack homes in both load procedures.
The worker restored unsupported constructor names to their baseline spellings.
It left uncertain type, buffer, and local mappings unchanged.
The module report gives the affected names and VA records.

No other assigned parameter mapping remains unresolved.
No worker changed a type, layout, call target, literal value, or public symbol.

## Shared and resource requests

No cross-group header request is pending.
No new resource macro request is pending.
No assigned module changed a resource lookup or resource ID.

The `aibldmod` report records why numeric module ID `0x3E9` is not a resource ID.
The source keeps that literal unchanged.

## Validation status

I ran full Git diff reviews and `git diff --check` only.
I did not run compilation, matching, audits, builds, tests, or games.
All integrated work remains reviewed but unvalidated.
