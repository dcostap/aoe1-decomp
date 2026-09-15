# Source cleanup owner 15

## Scope

- Group: Active objects and remaining actions.
- Integration branch: `cleanup/staging-20260915-127`.
- Common base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Sources: `src/act_obj.cpp`, `src/move_obj.cpp`, `src/stat_obj.cpp`, `src/t_b_obj.cpp`, `src/t_c_obj.cpp`, `src/tact_tek.cpp`, `src/tact_trd.cpp`, and `src/tact_wnd.cpp`.
- Headers: the matching eight headers under `include/`.
- Worker model: `openai-codex-secondary/gpt-5.6-luna`, thinking `xhigh`.

## Module ledger

| Module | Worker | Worker commits | Integrated commits | Review result |
| --- | --- | --- | --- | --- |
| `act_obj` | `sa-443d7055` | `02326a5d4b85d232ef1278e7b95753bbf4371121` | `d7412756f150fb6508de335023a4d774d3297b8b` | Approved after full diff and report review. |
| `move_obj` | `sa-50d9e010` | `819293c71043fd471befad2dbfc7d3f86395d19e`, `be26cbf860b59dc718fecb84402284206ddb67d1`, `42ed429b3bced3e592dbf7dc0ea98f10ba137d0e`, `d9571240fb921b11820edc5d4b93203da2ba2f7d`, `ff6f42778162569c3559f6cf89588bfabc1c2125`, `a2f74b0d8fce9baaf699c532e8ef4c53843f1b7a` | `27cca98fd7de51c8c4a47747015f8592c51f36ad`, `249b278f4bc19eee10445fecc530f98e33165c86`, `4ecef4dac117d27717ba320d46830c877e8a0519`, `40111a771af1618da1ccc31a653bdd499a7602a2`, `346fa2e0d2fcbf2f12eaa45ce38f7c1b5067fbda`, `de94f08c1e734045b4b970df32982e4b1558bc3a` | Approved after one correction run. |
| `stat_obj` | `sa-df7d1c41` | `cc341af8c2183170cbb69c34e57414782e7eeb40`, `169d38909163f617f39566076d24d3fc9485f950`, `5719dfd55ac6ebcc5ff87fc69e703e980220ffac`, `2ea15f34bd5cf34a173200a5e2d40d024169bafb`, `057f6dd4cf284bdd7e086742ac98b137f6c65761`, `1b33fd18d102d1f300d48700772c745948ce9d3d` | `d8690b20a8031ffb66a5a1885ec2a3db39272a93`, `27e6beea381655b9d6539030f735bb44d2ad938b`, `ffc314aaf5ba9fc98f4bf2b6006d299d3df59f46`, `3e0fe5be9211aa2251a7815d9d985b659ec033ab`, `4e350ceae4cac2b018587f9ce5e3c8be65582f66`, `0ff87f3436b0423fe278ca2573022246ce11e008` | Approved after one correction run. |
| `t_b_obj` | `sa-e26d3049` | `23691bb50f331536eb6d0480d63fa4f2639e5448`, `ce54aeea79327942d6aa6005f0afa4e196f4f7b7`, `42976ff1b31ca09f91210dd990affd86e6a31dce` | `5239a99a5020453710b47b7449619d0cbffcc7a4`, `1d27d5981b58a80cb9ce1a1219e77430395fef46`, `22245158c010f9b454d4aa6e0c2e91b9d0dbe50b` | Approved after full diff and report review. |
| `t_c_obj` | `sa-0db0192a` | `bf2b9f6c5d2c281741d6ebcc97fdb908447a3d45`, `7e467407978935c070283e1a6247c1fa2c8926f4` | `9a0a19acaf7f9118137f1d44112cc762e75d3821`, `46ac3a142f14cc30e532b1f2b6726ea74190edcd` | Approved after full diff and report review. |
| `tact_tek` | `sa-b2d894e8` | `f9c32ca108a355223b365202cc2846249df79e24`, `1fb117c7d28a8310b7aecc1eafbc1f81bc4d554b` | `dcc9696dcb5bfc52de8c2939c266c5662c210295`, `e72172e5220bd8fbcd29ddca2961be177089605f` | Approved after full diff and report review. |
| `tact_trd` | `sa-384ce5a7` | `2ee1d15b3ddf7f1f3a68b948ccfcbfd64b0eb24c`, `deb9d811a11df989a10c24fd74ebce833b974bb4`, `d7f5d31435be8208d738804a257970bdca27ab3c`, `04ae39bf15a402da43bed10ed4a5d355bbac577f`, `400c60b7168d4c5eab2269fbd4aa827f53281710`, `c33bc0d25a7640f45e242b86f40f886da538ad00`, `fc05fa5484dc5a54ab503dbdaad7f840e6baace8` | `eebc0ff36c18a06d618458415249fcfd1229e9d2`, `1837d9a74c8398179b673ef3da4846563dc27991`, `1902ebededd9724d408fff37b6c4230f83b61b77`, `76695585739477c860001c741ad6f1693df3cc93`, `beebece80e12d7a9d52bf06773bde1b08d4a4510`, `5ea419ad5cb9d0016d66c0ca4d8538722b68a3a0`, `413ea5e4704df118636c8a927439e312a20829e8` | Approved after one correction run. |
| `tact_wnd` | `sa-1fab2969` | `1aa46a4526f1e468e831d2552c08e43329a77314`, `1bd74c08be703207a9c636edfbeac0af54760187`, `1f8e0ef3f4f3a87eb0eab698beb6d896e9fdefce` | `acd3aeccb1fcdcd58e98e4faf0f225bb9d157da5`, `76101d5ea2b54ae2447ee1d7bf5f5fe56feffd5b`, `6730bbc8ffe05b30892dbf8ed9124234af7b20ee` | Approved after one correction run. |

Header parameter recovery is in `42972dc4bc83cedd6b77220871cf8ceb9acc75d0`.

## Review findings and corrections

- All workers inspected procedure-scoped PDB records for every assigned function.
- The source keeps proved original spelling, including mixed and terse names.
- Reports identify uncertain optimized stack-slot mappings. Workers did not force those mappings.
- `tact_wnd` first renamed the file-scope `LIMIT`. The correction restored it because no original name supports a rename.
- `tact_trd` needed shorter signature formatting and consistent condition wrapping.
- `move_obj` first removed four useful evidence notes. The correction restored concise forms.
- `stat_obj` first left next-line braces and incorrect indentation. The correction applied 1TBS and fixed indentation.
- Header edits add PDB-supported parameter names. They do not change types, order, access, layout, or ABI symbols.
- The final combined review found no new resource IDs, constants, helpers, layouts, or behavior repairs.

## Shared requests and limits

- No resource-ID mapping request is outstanding.
- No `game_globals.h` request is outstanding.
- No cross-group header request is outstanding.
- Optimized local mappings listed in the module reports remain unresolved.
- All work is reviewed but unvalidated.
- Compilation, matching checks, audits, tests, and games were not run.
- Final validation must compare against the preserved pre-cleanup build and retain its prior original-executable differences.
