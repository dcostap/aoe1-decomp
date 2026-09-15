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
| `src/scr_game.cpp` | `sa-7592d2d5` | `fcf4ac9da7d74531e4012e0b60bf06047e83f329`, `d12cc4a7c2a7b0bdf26df0df6d4d61db2b87ec35`, `3415854c8d148ce993b285c57c4e68639fe54362`, `0adf5675caeeb2df4edf1c223235f6321776378a`, `b08bf0343d663cc66c26e8d04e12900c6da39a02`, `924992b4bb6947b0b1155588d09d6832d730dbe7` | `7710a7426f82cdf4961516d13710ae3559cd80d5`, `cb6e02ac3e89f1407e3614d3f7ff7fec2c986328`, `685dac4ee8a3150253f51bb733708ae7a4b7cfcd`, `5442da315447ea37b391c437a71dde43ba958b5f`, `b01b29a1ffcb24c82111c71dc45655c161a529a5`, `4febe3b21cf3b1c5e093262bf12f7791969379b9` | Integrated after structural correction. |
| `src/scr_sed.cpp` | `sa-14dbeaf6` | `03c9158e16142b5e246a646d0e08605d2e3f924a`, `f560fa3a68d804b9978a38d55e1c6cda569b7465`, `785eac73d03094f363c74d56d381c635c844c0ca`, `2d1978a607c033ceaa0c80f964fdf0c0ed0f63e1` | `97ba25c18f5c3fd4e1ed5935f12d47ef5c1f41ea`, `cb434a15e09404f8e6e298a1737dd1394d4765dc`, `6c83322f0f3c3b126a806a108744066ba5e9051f`, `33204bbc6286f2cb0b58606d2100688c61f15883` | Integrated after 1TBS correction. |
| `src/scr_sed2.cpp` | `sa-ce4cceef` | `990afb1a237c12b38a9b88ccbf3bd0d56f7c5bb1`, `1992ad258c67006b91896e4efdd37f62f20881df` | `b9e9aa30b9be47cc1292cea29ef5fc62065a5ed9`, `8a7895b2be0606258c1d6a736c2c505aa69c5492` | Integrated. |
| `src/scr_sedm.cpp` | `sa-2cfdeec0` | `9649a6df2ff1ff8be90ae9acc5a546746b026cbb`, `67137c7ae8e5d06f3c1f7610150b132ebd350920`, `38cc53fad625c7d1bf79122fdf3ef577539b933a` | `ccb6776269fad743a576e356e72903bcd380a526`, `b30ff5a454901641d2ab498609dd2d736a2ad291`, `5e2cbb4f42d674f85b75cbb945d284e19d6417f8` | Integrated. |
| `src/scr_sedo.cpp` | `sa-cfd7a24e` | `0fff4f5e95f094dd31ce9439f0ec2bb6c54a15a9`, `76816578b5f66645eed000fdb6926f7b247aa0bb`, `b249684deea3ff2fb648ad376804ba5ea770b763`, `e194ebfef2e0da76b57209086ab864c4b460ca40` | `9b98e65d36f1a0fe00c670ec7782f6fcbf6ebfed`, `7dd407d785df14fd3fd0738cd91b220657c4dbbb`, `b7c78672e54677449e785c6b1e2ffc27598b7842`, `b331440deac4df3b1a5147c094a373710d68ddfe` | Integrated after header-ownership correction. |
| `src/Scr_sels.cpp` | `sa-2984d82a` | `f4c24344757acbb864d7deef11aad91759946e4a`, `df983109a9635d1dad1543fc686d2bd5435dd4fa`, `6021deac4abc39b7e592a52eae9bdf54e1a701e7` | `26804c64675ecc304c076ba56c94e1b0a2a2ecc4`, `3462b1255e7da2d202b06a2203d641cc7cd4b71c`, `96cc9456100c429f759a3e387e560aa49d5548d3` | Integrated after report correction. |
| `src/scr_vc.cpp` | `sa-943b28e5` | `3ec6d5735700829768fbcc49e5fd384a5019703d`, `e21f9ab8a6e7d4cf255cf515001b30a2bb7cb362` | `d23a353ef518eb7206fd46946227abd0f720c0ab`, `411d64c9f46c800d9ecf05c984bb3979b7b0b128` | Integrated. |
| `src/dlg_smsg.cpp` | `sa-822f29ba` | `98afc1fe063aff8ca93bb15c31386bdc197969fc`, `997647303c22a93ba483e8f160d14abd9d23f3ca`, `8fc5420596ec5025b05f8b802b1a1e3035aad8f4`, `cea437a479bb0a918fb13f68010e1c836d8a15a5` | `5e702ad9684e8b002153c3ea78da202c8bc561de`, `c4b67bfe64809550381a4de5fab50da62f8b8645`, `df5a6958ad767c99b362fa1eceb3a7e047b09bb7`, `7eb1cc6a0bf6b8bba83f4588952610cf15a95ce5` | Integrated after constructor-brace correction. |

## Review findings and corrections

- The first managed runs stopped. The owner resumed each same worker without changing its worktree.
- The first `scr_game` result reorganized `setup_buttons`. The owner rejected that structure. The same worker restored base control flow, scopes, expressions, and statement order. The final token review found identifier changes only.
- The first `scr_sed` result did not apply full 1TBS formatting. The same worker added a formatting correction.
- The first `scr_sedo` result edited its owner header. The same worker restored the base header and corrected its report. The owner made the reviewed declaration change in the group header commit.
- The first `Scr_sels` report omitted its report commit hash. The same worker added a report correction.
- The first `dlg_smsg` result left two constructor braces off the initializer lines. The same worker corrected them.
- All correction commits remain in history.
- No worker reported a prohibited command incident.

## Header result

The header commit adds original PDB parameter names. It changes no parameter type, order, virtual slot, layout, or symbol. It also removes the incomplete comment in `include/scr_sed2.h`.

The edited declarations match the reviewed source definitions. Uncertain reused PDB slots did not cause new parameters or type changes.

## Outstanding root-owned resource requests

These requests do not block the integrated source. Each source keeps unapproved literals numeric. Full DLL hashes, languages, payload status, lookup paths, and role evidence are in the listed module reports.

- `scr_game.md`: base-language requests for `0x0BE0`-`0x0BE5`, `0x0BEC`, `0x0BED`, `0x0BF3`, `0x0BF4`, `0x0BFE`, `0x1023`, `0x1024`, `0x1037`-`0x104E`, `0x1069`-`0x106C`, `0x2329`, `0x232E`, `0x4E25`, `0x4E33`, and `0x4E35`. It also requests the complete documented help-ID set from `0x19BB8` through `0x265AF`. Preserve the proved `0x1040 + i` range. The report leaves `0x0FA9` unresolved.
- `scr_sedm.md`: `IDS_SCENARIO_EDITOR_TITLE` `0x242D`, `IDS_BUTTON_CREATE_SCENARIO` `0x242E`, `IDS_BUTTON_EDIT_SCENARIO` `0x242F`, `IDS_SCENARIO_EDITOR_CANCEL` `0x2430`, and `IDS_MENU_CAMPAIGN_EDITOR` `0x2431`.
- `scr_sedo.md`: `IDS_SELECT_SCENARIO_TITLE` `0x24CD` and `IDS_ERROR_CANNOT_LOAD_SCENARIO` `0x24CF`.
- `Scr_sels.md`: `IDS_SCENARIO_SELECTION_TITLE` `0x25FA`, `IDS_SCENARIO_LIST_LOADING` `0x25FD`, `IDS_SELECT_SCENARIO_TITLE` `0x25FE`, `IDS_SCENARIO_PLAYERS_TITLE` `0x25FF`, and `IDS_SCENARIO_INSTRUCTIONS_TITLE` `0x2600`.
- `scr_vc.md`: `IDS_MISSION_TITLE_INSTRUCTIONS` `0x2655`, `IDS_MISSION_HISTORY` `0x2A31`, `IDS_MISSION_INSTRUCTIONS` `0x2A32`, and `IDS_MISSION_HINTS` `0x2A37`.
- `dlg_smsg.md`: `IDS_SEND_MESSAGE_TITLE` through `IDS_SEND_MESSAGE_SELECT_PLAYER` for `0x2667`-`0x266E`; civilization mappings for `0x27F7`-`0x2809`; and chat-help mappings for `0x767A`-`0x767F`.

Two workers proposed `IDS_SELECT_SCENARIO_TITLE` for different IDs. Root must not add both names. Suggested distinct names are `IDS_SCENARIO_OPEN_TITLE` for `0x24CD` and `IDS_SCENARIO_LIST_TITLE` for `0x25FE`.

The civilization values in `dlg_smsg.md` are data reached through `get_string2`. They have no direct substitution in this module. Root can defer those macros without blocking this group.

## Validation limits

The owner performed evidence extraction and full Git diff review only. Compilation, builds, matching checks, audits, validation commands, tests, and games were not run. Historical artifacts do not validate this cleanup.
