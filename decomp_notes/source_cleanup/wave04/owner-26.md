# Owner 26 cleanup ledger

## Scope

- Group: Worlds and scenarios.
- Integration branch: `cleanup/staging-20260915-226`.
- Common base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Owner headers: `include/world.h`, `include/tworld.h`, `include/scenario.h`, `include/tscenaro.h`, `include/sceninfo.h`, `include/campaign.h`, `include/rmm_tdbc.h`, and `include/effects.h`.
- Header commit: `b7206d1420aedc1750a3e4f7ec986dd4e30a9d2b`.
- Root resource-header import: `004f675a3d2b7b7e487cab0fe1a442ac11dbe4e7` from `bf943f3339643ee5beca7dd74e98b4cb729e48d3`.
- Validation state: reviewed but unvalidated.

The owner read each complete worker diff and report.
The owner also checked each reported PDB parameter mapping before changing declarations.

## Module integration

| Module | Worker | Worker commits | Integration commits | Result |
| --- | --- | --- | --- | --- |
| `src/world.cpp` | `sa-8cc6c385` | `79849d74ecf5ec1c5fa84cd08d1c38b4169b65c5`, `b659e2e1d9e1a92e8e7fb95c64329346896a0562`, `a76d02bdb0e6470c6906f7c1b032a43adc693db5`, `9bff91190ebfdeaa242d41a37080e8386ada655e`, `f986575872f097f2907aceab5443329b2a8e8fe4`, `c6d823db2bf121f7e0d59c603163f0bb38c911c9` | `945d1a741dcc0afc9e9c2cbd53150b85f702c94d`, `323bee3a7be05718e817d4f43cfd4ce7791a81a1`, `7688b330205b9a4c7f15d9dada607d78e9fb77a0`, `eedd7202a79060242b925b9c1421e05f2f3f0a19`, `6aa7dcc5a78df47213b7e20abd94c27978d3caf8`, `ce98398a768b5c4dc72d3b62dd93762d9e54ec29` | Integrated after reviewer correction and resource approval. |
| `src/tworld.cpp` | `sa-4672320c` | `891a0e6263b753a59f3caef970c66311498d9328`, `cde37ac57e36cdfff6644ef18080ddc908440250`, `cad41fd0133f640144cb7cfb774f39c4a12be364`, `72fe153494f42409f66797cd6fbd39e68422e8eb`, `9bdac484a9a9c1c393f01bf89df1b74d574be131`, `cb00ce396f9b2a5bc0ad4cf9a1f6ee323607248a`, `b1a138720126836367f4271ad44a589e8fdc7c53`, `17c8f34772d6ee06c7a8cdfd2a70910621f7ccc3`, `d8d75f1203c61f3020f1c6e312394d7b8e8e0721`, `9435f1c4e3a36d5bd98f2f43b39d34ebc9a21821`, `3255b49562c14cc6e986a2b1c28f491762516c96`, `e5aa641007c0d22bf60a060c803c5002677fed36` | `fe20586c17a265304c466f801cf466a1380b65d0`, `8bd4c077004f7e57204d6b9465014185029dc950`, `5d8d908ebbbc077f6eb607b7802cc783b2bf8062`, `6a8630c6fb8a1dbbebfdf6c57f710dfce3f5beb9`, `f54064a38bbfe782ceee57aca1dd58d835653ea9`, `d79dc54796e931c9675d11a3c334fb02956f5349`, `04ef265c1e6076664234a3e07e5f380addb42a27`, `63eefae19e1e31d84723c32e6f99af06bea64ac6`, `18a228b8dea33be6b86f14720cd4fc88bc805ea3`, `445b31a10ea9bdb10e2492ae15d584295e92109d`, `2d6466d1391cc5a4fd9b5310564400de08293f0d`, `7d88572159eebf65a97098c996b43c2e0b1758db` | Integrated after scope, positional parameter, and resource corrections. |
| `src/scenario.cpp` | `sa-2f3c0f29` | `cd138ad8ff071550dd4cc712602d6e902b0451e9`, `22dd8c8762fe0b0539da53f7bdb55963e13de15e`, `cb94bde475313ae67b354086859ec91efc89313c`, `6e79038729eb2facd63d696a989bbbf260520d33` | `b70fac44ce4be90efb98a664460422a76330b98e`, `d8cecdd6e5962b006fdcfffd40493578186d176c`, `afe1de3ebf92ba9c90c9fc5252139925f535f9da`, `f3e86a7ab596e434a90b711fe3f94df0ff021832` | Integrated after review and resource approval. |
| `src/tscenaro.cpp` | `sa-f0da3c57` | `e896c380c3d7bbb45736022ccc5004250870896e`, `93c60e96615042ecf88d2c55563892933cb1fb04`, `737feddf256e322c479324df82fff509327a521b` | `6ab175f35df4f7b0184a0bd456bbc6b58591b502`, `7f01e706ebc445257a202e87bf39c54a17ae2332`, `e8597b313eb3d5259648ec595efe213acfb18be9` | Integrated after report and header-request correction. |
| `src/sceninfo.cpp` | `sa-8608f994` | `fed8be14c04f867bfd65a07f23c6ea077adf7599`, `20d5f1b6c4abb91c362d589366620aec17009a85`, `b0919453d571da4dd2c18a8b9db2f6333bb2dba9` | `24b84c499750872031303bb0db3b7c84537e7cff`, `0632256d60b8febc10f6aeeb0013ab50dbe0bc40`, `d845b593ec512fc6d65c96ee7158a7de611eaa0a` | Integrated after report commit correction. |
| `src/campaign.cpp` | `sa-51f9fe54` | `3f4317178392417903a58fa4364c02d9e16fc0be`, `dc55b87bb95d24da0f8733a172b01e7c56b426e4`, `30d8d1cdbedb461484a4bfb97dffce642d00a84a` | `85fd5723fc981dec9f1fa9fc8353f35c224129e2`, `73fa5520d5d5c38b6d762f106ad187f32b9cf153`, `22ee4068f295b51f8919aaf36acaf922b1a6b67b` | Integrated after wrapping and report correction. |
| `src/rmm_tdbc.cpp` | `sa-a6a2e734` | `5df422526a5fb85e1fbc5213ee0c748fa8b78ad7`, `52c19609b735b7002f80859acced969624d22a79`, `010d32a56cd38b01b47acf268989c4c86e3515b2` | `d5d6f132498c60ccb616fb690fb52c1a23a91e22`, `fb4e153394cb5a50b336542de80f56f3c1207e70`, `936f58f238e48befbb91e6682fa213cf55978c2d` | Integrated after hash, path, header-request, and wrapping corrections. |
| `src/effects.cpp` | `sa-ec913733` | `956b86418ac3abc0bfc54e730ba1cb6a02d8521f`, `6df2677e7c5d5e301dc14d487565d1c615dbcd3c`, `f059e50f9b4cb7f0d2eb4032bd2f31b72b83189c` | `cc70db501d10827811cb0b16dfb99522419506ef`, `aefc820317fb309a1c45e8060418760a69a35789`, `79c5f7d1dd57a4d3a34c55c06c68670b521d3d77` | Integrated after report commit correction. |

## Review findings and corrections

- The first `world` result changed declaration structure, order, and types.
- The same worker restored most base declarations and applied consistent 1TBS formatting.
- A reviewer found one split `load_scenario6` declaration. The worker restored its grouped form.
- The first `world` result also used tabs. The correction restored four-space indentation.
- The first `tworld` result changed positional parameter use in `scenario_make_player`.
- The same worker restored each base parameter identity.
- A reviewer found a missing `case 101` scope brace. The worker restored all baseline scope tokens.
- The `scenario` bug comment did not state the leak trigger and effect.
- The same worker corrected the comment and completed resource evidence.
- Several reports omitted report commits or copied an incorrect hash.
- The same workers corrected all found report records.
- All correction commits remain in history.
- No worker reported a prohibited command incident.

## Header result

The header commit adds reviewed PDB parameter names to all eight assigned headers.
It changes no parameter type, order, virtual slot, storage, layout, or symbol.

The base `RGE_Game_World::logStatus` PDB uses two `__formal` names.
The owner kept that declaration unnamed.
The `TRIBE_World::logStatus` declaration uses its own `out` and `firstTime` PDB names.

## Resource result and deferrals

Root approved the direct substitutions in `bf943f3339643ee5beca7dd74e98b4cb729e48d3`.
`scenario.cpp` uses `IDS_FILE_NONE` for `0x2775` and `IDS_AI_FILE_RANDOM` for `0x277B`.
`world.cpp` uses `IDS_AI_FILE_RANDOM` for `0x277B`.
`tworld.cpp` uses the approved descriptions, bases, formats, Nomad, default, and difficulty symbols.

The victory-log base `0x28A6` remains numeric because its payload is empty.
The age expression `age + 0x1067` remains numeric.
The source does not reuse `HELP_AGE_*` names for this option role.
The resource-level expression `res + 0x25E5` remains unchanged.
Direct map switch IDs remain numeric because root approved only the range bases.
No alias was introduced for `IDS_FILE_NONE` or `IDS_AI_FILE_RANDOM`.

## Validation limits

The owner performed evidence extraction and full Git diff review only.
Compilation, builds, matching checks, audits, validation commands, tests, and games were not run.
Historical artifacts do not validate this cleanup.
