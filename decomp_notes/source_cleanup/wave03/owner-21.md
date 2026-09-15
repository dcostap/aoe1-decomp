# Owner 21 cleanup ledger

## Scope

- Group: Game and editor screens.
- Integration branch: `cleanup/staging-20260915-181`.
- Common base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Owner headers: `include/scr_game.h`, `include/scr_sed.h`, `include/scr_sed2.h`, `include/scr_sedm.h`, `include/scr_sedo.h`, `include/scr_sels.h`, `include/scr_vc.h`, and `include/dlg_smsg.h`.
- Header commit: `4c5feee491544158f7c4a077a1cfa815a7849ce9`.
- Validation state: reviewed but unvalidated.

The owner inspected the complete worker diffs and reports. The owner also inspected the assigned PDB parameter records in `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.

## Module integration

| Module | Worker | Worker commits | Integration commits | Result |
| --- | --- | --- | --- | --- |
| `src/scr_game.cpp` | `sa-7592d2d5` | `fcf4ac9da7d74531e4012e0b60bf06047e83f329`, `d12cc4a7c2a7b0bdf26df0df6d4d61db2b87ec35`, `3415854c8d148ce993b285c57c4e68639fe54362`, `0adf5675caeeb2df4edf1c223235f6321776378a`, `b08bf0343d663cc66c26e8d04e12900c6da39a02`, `924992b4bb6947b0b1155588d09d6832d730dbe7`, `2c102c6dc0fa08035493388370fc6faa8a9617dd`, `b67b99de2fbc67991645445df80d99df6e18f939`, `f8db2f87fe8e5745284d4c9986ccc464f9883d7f`, `446d208c8e95720105750c6438fe0d437b0e47b0`, `edfd6f7454df0d6a487c96f2912f6be01e5fbe61`, `7d50116c57c6bbab86f2448df4b3937d11d464ae`, `25ec757f0b00deda0019a35b724bf47ce8a0ff49` | `7710a7426f82cdf4961516d13710ae3559cd80d5`, `cb6e02ac3e89f1407e3614d3f7ff7fec2c986328`, `685dac4ee8a3150253f51bb733708ae7a4b7cfcd`, `5442da315447ea37b391c437a71dde43ba958b5f`, `b01b29a1ffcb24c82111c71dc45655c161a529a5`, `4febe3b21cf3b1c5e093262bf12f7791969379b9`, `80de0725fb83b4237702bc8eb8c63aa7c211ca44`, `993150c0b0b43955ada5c87f4c6fa8b9e846ba31`, `ddc6fa7a7ecd4e508e51b0cbc3424ca8923e5ba5`, `c67d2821cd54e565416514987eee97ec65c908e2`, `db71485881628c1889ba6f12031b84802b734812`, `4975a1d0e20fe3dc608896583d6ca585674ea553`, `29ea470a85bed1b616c7d7c58ae2e69fdbb560af` | Integrated after structural, evidence, and type corrections. |
| `src/scr_sed.cpp` | `sa-14dbeaf6` | `03c9158e16142b5e246a646d0e08605d2e3f924a`, `f560fa3a68d804b9978a38d55e1c6cda569b7465`, `785eac73d03094f363c74d56d381c635c844c0ca`, `2d1978a607c033ceaa0c80f964fdf0c0ed0f63e1` | `97ba25c18f5c3fd4e1ed5935f12d47ef5c1f41ea`, `cb434a15e09404f8e6e298a1737dd1394d4765dc`, `6c83322f0f3c3b126a806a108744066ba5e9051f`, `33204bbc6286f2cb0b58606d2100688c61f15883` | Integrated after 1TBS correction. |
| `src/scr_sed2.cpp` | `sa-ce4cceef` | `990afb1a237c12b38a9b88ccbf3bd0d56f7c5bb1`, `1992ad258c67006b91896e4efdd37f62f20881df`, `e763d0635fd57058de43f03b04ff46317fb54131`, `65cf5c008b93eb4cd8857612b4d0b54d2920100e`, `2496be3a4a7ffa0340d96afa5a7e9c1581072e06` | `b9e9aa30b9be47cc1292cea29ef5fc62065a5ed9`, `8a7895b2be0606258c1d6a736c2c505aa69c5492`, `20842fd0e11fb4009d5184bbd85d3da5b1f02c8b`, `4ffa0fc15638b1c248d40571b6d29f610e2e0b34`, `f09a10d7615983b027bde1f008a22e2994d6ff4a` | Integrated after cast and report corrections. |
| `src/scr_sedm.cpp` | `sa-2cfdeec0` | `9649a6df2ff1ff8be90ae9acc5a546746b026cbb`, `67137c7ae8e5d06f3c1f7610150b132ebd350920`, `38cc53fad625c7d1bf79122fdf3ef577539b933a`, `e749f5516dc100bf3d06f20475a453c2dacaae36`, `798426c809e09cbabd6b7570014046cacc92f406`, `583dd22308e40f66a78eb00d1d4ba291d7d141ea`, `7a2e6283a3476c9a280598ff2ebfe57aa4fca748` | `ccb6776269fad743a576e356e72903bcd380a526`, `b30ff5a454901641d2ab498609dd2d736a2ad291`, `5e2cbb4f42d674f85b75cbb945d284e19d6417f8`, `670dbf3e357228a78d8fbfa85f1d7fce11a7b153`, `c622b47bd7b9990cc38f1b18c2ecbd2a69c055e0`, `e14373fbe67fc8fcdf70a338900b3510ad521704`, `ef8f1b41639038bba7277143de007af3de65b9fa` | Integrated after 1TBS correction and resource approval. |
| `src/scr_sedo.cpp` | `sa-cfd7a24e` | `0fff4f5e95f094dd31ce9439f0ec2bb6c54a15a9`, `76816578b5f66645eed000fdb6926f7b247aa0bb`, `b249684deea3ff2fb648ad376804ba5ea770b763`, `e194ebfef2e0da76b57209086ab864c4b460ca40`, `cc350e5cbab2079d151ef0c88b5c0299e765445f`, `8737fa5a2126f2afb1be1eb6664d414fa14167a4` | `9b98e65d36f1a0fe00c670ec7782f6fcbf6ebfed`, `7dd407d785df14fd3fd0738cd91b220657c4dbbb`, `b7c78672e54677449e785c6b1e2ffc27598b7842`, `b331440deac4df3b1a5147c094a373710d68ddfe`, `704b18880a828c22173fe075d0ed625fa930cd62`, `176c792bc3ae0df7d5c58688436f5c9597b3eb38` | Integrated after ownership correction and resource approval. |
| `src/Scr_sels.cpp` | `sa-2984d82a` | `f4c24344757acbb864d7deef11aad91759946e4a`, `df983109a9635d1dad1543fc686d2bd5435dd4fa`, `6021deac4abc39b7e592a52eae9bdf54e1a701e7`, `43d87a91f0eb0b1d8070c7df1b588880bbd26d56`, `a9c6d6d4ff638a2b6f0fe45965619f571e9759ca`, `dd20bab0a05ee854cc1ff2fd57229796d8fdff9f` | `26804c64675ecc304c076ba56c94e1b0a2a2ecc4`, `3462b1255e7da2d202b06a2203d641cc7cd4b71c`, `96cc9456100c429f759a3e387e560aa49d5548d3`, `503d8a51a0f3199ffd0e688b000fe6eb9f1f9161`, `b934e2cd5982781c1295dbbc76188a046cac0c0b`, `8ca046d2c0d13262b7b2bf521af771d609de5066` | Integrated after report corrections and resource approval. |
| `src/scr_vc.cpp` | `sa-943b28e5` | `3ec6d5735700829768fbcc49e5fd384a5019703d`, `e21f9ab8a6e7d4cf255cf515001b30a2bb7cb362`, `c9ae9f1135a82501d4d8275d2a82cf7080b7b017`, `901a1653314c90efec38b748ccceb29e5c4e829f`, `f8aeef9f75a2f44f6afc49828f21b03f00b9d5bb` | `d23a353ef518eb7206fd46946227abd0f720c0ab`, `411d64c9f46c800d9ecf05c984bb3979b7b0b128`, `cb2a2081fcb2fdf76d5d7e109b42a3694f9ddb2d`, `8909f39bda0349586a7fff07d95816898b0ad12e`, `c62f08fe375b97eb1ab93782615108c9f75914fb` | Integrated with approved resources and corrected report wording. |
| `src/dlg_smsg.cpp` | `sa-822f29ba` | `98afc1fe063aff8ca93bb15c31386bdc197969fc`, `997647303c22a93ba483e8f160d14abd9d23f3ca`, `8fc5420596ec5025b05f8b802b1a1e3035aad8f4`, `cea437a479bb0a918fb13f68010e1c836d8a15a5`, `7a215da761716b64223ba9efa7009c1c6a5d6c01`, `f10d1e8a97af37527c0c5ccc741ef6af062489ce` | `5e702ad9684e8b002153c3ea78da202c8bc561de`, `c4b67bfe64809550381a4de5fab50da62f8b8645`, `df5a6958ad767c99b362fa1eceb3a7e047b09bb7`, `7eb1cc6a0bf6b8bba83f4588952610cf15a95ce5`, `d24bcf8efc3f6f342f9e5ff0bdedf224541ae9f2`, `73c107f3101813be3b11191718c41e4b407f561d` | Integrated after brace correction and resource approval. |

## Review findings and corrections

- The first managed runs stopped. The owner resumed each same worker without changing its worktree.
- The first `scr_game` result reorganized `setup_buttons`. The owner rejected that structure. The same worker restored base control flow, scopes, expressions, and statement order. The final token review found identifier changes only.
- The first `scr_sed` result did not apply full 1TBS formatting. The same worker added a formatting correction.
- The final combined review found three remaining `scr_sedm` function braces. The same worker corrected them.
- The first `scr_sedo` result edited its owner header. The same worker restored the base header and corrected its report. The owner made the reviewed declaration change in the group header commit.
- The first `Scr_sels` report omitted its report commit hash. The same worker added a report correction.
- The first `dlg_smsg` result left two constructor braces off the initializer lines. The same worker corrected them.
- A delegated review found 13 lost `scr_sed2` casts. The same worker restored each baseline cast.
- The delegated review corrected four `scr_game` hotkey payloads and the empty `0x103C` slot.
- The approved hotkey ranges are `0x1037`-`0x103B` and `0x103D`-`0x104E`.
- Slot `0x103C` is empty. Reviewed source has no call for it and requests no macro.
- Resource substitution first changed the `0x1023L` token type. The same worker restored that literal.
- Final review corrected stale cast wording in `scr_sed2.md` and one heading in `scr_vc.md`.
- All correction commits remain in history.
- No worker reported a prohibited command incident.

## Header result

The header commit adds original PDB parameter names. It changes no parameter type, order, virtual slot, layout, or symbol. It also removes the incomplete comment in `include/scr_sed2.h`.

The edited declarations match the reviewed source definitions. Uncertain reused PDB slots did not cause new parameters or type changes.

## Resource approval and remaining numeric values

Root approved payload-backed definitions in
`f5b7d6668f785b97811119493bea0e04403d1d10`. The owner imported only
`include/resource_ids.h` in `5def467bb9a13fefbc03dcf4d18a333062e9aa0c`.

The same workers applied eligible direct resource macros. Their reports keep
the staged runtime-base hashes and precise missing, empty, fallback, and
expansion-override results. Each report separates worker evidence from root
name approval.

- `0x242E` uses existing `IDS_SCENARIO_MENU_CREATE_SCENARIO`.
- `0x0BF3` uses existing `IDS_GAME_SPEED_CHANGED`.
- The building hotkey keeps `i + IDS_HOTKEY_SELECT_BUILDING_BASE`.
- No macro exists or is requested for empty slot `0x103C`.
- `0x1023L` stays numeric because its `L` suffix preserves the token type.
- `0x0FA9` stays numeric because its role remains unresolved.
- Unapproved purpose-only missing-help values stay numeric.
- The unrelated `Scr_sels` scrollbar value `0x7532` stays numeric.

Civilization resource IDs do not equal master-player IDs. The dialog keeps
`get_string2(0x69, master_player_id, ...)` and makes no civilization-ID
substitution.

## Validation limits

The owner performed evidence extraction and full Git diff review only. Compilation, builds, matching checks, audits, validation commands, tests, and games were not run. Historical artifacts do not validate this cleanup.
