# Source-cleanup wave 04: owner 24

## Group identity

- Group: Paths and views.
- Integration worktree: `build/source-cleanup-20260915/wave-worktrees/slot-208`.
- Branch: `cleanup/staging-20260915-208`.
- Common base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Owner header commit: `8914583aa90e90763728773777a53c92103edef5`.

This group owns eight source modules and seven headers.
`include/vw_main.h` serves both `vw_main.cpp` and `tvw_main.cpp`.
Root owns all other headers.
I reviewed each complete worker diff and report against the common base.
I integrated each approved worker commit without omitted hunks.

## Module ledger

### `src/Path.cpp`

- Worker: `sa-687403ad`.
- Worker commits: `67af8d2f4413adea5af92136602734a987d61fc8`, `410ccb2b4cf99559d65c6dc4bbbce7ca8fb7740c`, `dd36d9b93d668bb6a833937e71147b3d62998787`, `2bc40cff58a9ced1f01d23451b656c303945b95c`.
- Integration commits: `e7451316871a24f9e70c08359f54dc02524674c9`, `db635e75738f7b64dc41ef45b9bf99ed21857d64`, `16ebb87a746b818d7274044c0f56c15b3c455592`, `2e2b01bafedfed6455b1cbd2c5ca0fb5d5d44e4f`.
- Report: `decomp_notes/source_cleanup/wave04/Path.md`.
- Review found Allman braces after the initial delivery.
- The same worker applied 1TBS and recorded the correction.
- The owner added the recovered PDB parameter names to `include/path.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/pathsys.cpp`

- Worker: `sa-b2333792`.
- Worker commits: `307f74ba2c02befb00b09eb5a7ebf1df28673cec`, `e0865f625d8e1307c26232ae1465689e69a2b280`, `d9cd60d02a02d893a4a16f65d3149f9e675428ad`, `a3974bd830ee7735dd6af40e7e911cbbdaf24cac`, `64fffbe78c0c2d09fc0ff7f291bbba352039a4e9`, `894dd685e8533cf14dfea013dbe027782c7cfc53`.
- Integration commits: `ac369d46b5c479ddc40b9d5f8f6b80ef7d92c67b`, `c1137dcd812945259a06daa4d57405b19c1c2246`, `99b9a5d948be891c798c8a72514ed2f107aef9e5`, `e245a95056b87ea04976be18b02ad55bdfe26266`, `78be8fd70585e436d038d06e39b3d519446e1dce`, `66a43308f0b68c55e354c5407a7099e14766896c`.
- Report: `decomp_notes/source_cleanup/wave04/pathsys.md`.
- Review rejected a new constructor local declaration.
- The same worker restored the merged `aiPS` lifetime and recorded the unresolved mapping.
- The worker also corrected signature wrapping and two indentation errors.
- The owner added supported parameter names to `include/pathsys.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/diam_map.cpp`

- Worker: `sa-52b69f61`.
- Worker commits: `ef4716b4fbe13c21122ed62269471dda8740b9dc`, `d5b86f71284dba65d033b62e76c859d58419ec55`, `7707e16f808c4a12629e3ad49380eb8eb8bb8836`, `ff35c063adefbb7238b185d2c8a0fac519f980c0`, `8a2878786a0a1cbb29f0c461c051bcfa4b6af87a`, `862dc64576de762544179128ce654f84954469c4`.
- Integration commits: `2ac8aa65524c9232f7f2fe201c0026733f966705`, `808eea3584a817b6ff0c7c943057da1e9a958b18`, `d508b7358c4eed27dd046e9fe77e20a99d869646`, `03fcf0e0b494f619ce9dfbc94331030fd5f278f9`, `0067f5fc46fb9a6543e9c332bf4e812c83b368f0`, `4fb0f89335f2a441b2f9cbf03f82cee7880dd5b1`.
- Report: `decomp_notes/source_cleanup/wave04/diam_map.md`.
- Review required short signature wrapping and a precise header request.
- The same worker corrected both items.
- Final review corrected the `00437760` PDB reference size to 1216 bytes.
- The report does not claim new executable boundary proof from that metadata.
- The owner added the recovered parameter names to `include/diam_map.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/view.cpp`

- Worker: `sa-6350ea36`.
- Initial worker commit: `e2182159345429652b16d887b8549fb63ad8cf15`.
- The worker replaced that commit during correction with `dd1e6f50e70f9b242ce4ff651a83f8db4b8fd788`.
- Later worker commits: `321a8b461a41ed4d91faae9fa1634e3b2b7c1482`, `8c6ffb71511181a93cd80f6c07bcf9c157c31718`, `fa8ef2138e7c0fea16927e2215388e470573c009`.
- Integration commits: `41353e56d3c470ae6243c93d50deaa03d4176804`, `254559d86d9be64b3ee9cb66e7d7d9e61e34f22a`, `cb91159e2b26f8f5e28649118022ff7058054880`, `455bf77ddb4e88a326f716483d260b8875e0c2c5`.
- Report: `decomp_notes/source_cleanup/wave04/view.md`.
- Review found forced names from reused homes in `view_function`.
- Review also found incomplete 1TBS formatting and an incomplete report.
- The same worker restored the role-based names and documented the unresolved PDB aliases.
- The worker then completed formatting, coverage, and the exact header request.
- Final review clarified that only the original executable is the behavior oracle.
- The report now identifies the PDB and inventory as reference evidence.
- The owner added the supported parameter names to `include/view.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/vw_dimap.cpp`

- Worker: `sa-29c5196c`.
- Worker commits: `4cb1e213de2df2525ac7df95e07c82d562c09abe`, `fe2aeb4321e2cf2cf31fd22aa1cfacb63706bd8d`, `338b6ffbd67b57f5acc377543bdc9e3d5119a0d6`.
- Integration commits: `dc2c564b395fd233954722e3490066659b19e559`, `93c365a343973a71761b70696992143e53d42ef6`, `da2017adaa60fc252aa194757c25862a5d4860c9`.
- Report: `decomp_notes/source_cleanup/wave04/vw_dimap.md`.
- Review found that the report omitted the required header request.
- The same worker added the precise request and correction history.
- The owner added the recovered parameter names to `include/vw_dimap.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/vw_main.cpp`

- Worker: `sa-b5b9af8e`.
- Worker commits: `99447c02545d8313a21bab928c9fd77bcb294e5b`, `bd8d0300265b3eebc157ea2464075b20c073b053`, `ac0aa099946a77f8c5a4a0643fe8db7cbc62fdeb`, `e915249698d5fc72704b335d222ab3a0e4342ecd`.
- Integration commits: `9bf2c05d8e968ecda22215b271624edcf2180935`, `e3e6877c56e543525fd4ffe9cd7ba2e8c6a370a6`, `431f91acc61674e054a1d7230aa0cbb3ccb097c8`, `3f48f77521c39a4e82565a3f1a3a75f32d16a812`.
- Report: `decomp_notes/source_cleanup/wave04/vw_main.md`.
- Review required short signature wrapping and a complete shared-header request.
- The same worker corrected both items.
- The owner resolved this request with the `tvw_main.cpp` request in one header edit.
- Status: integrated, reviewed, and unvalidated.

### `src/tvw_dmap.cpp`

- Worker: `sa-a60c08d2`.
- Worker commits: `04074397d97c118efc8d1a6f4a93348f0e68fe56`, `6bcffbc5a3ba8c91ff148320b59ed2aed9dc590d`.
- Integration commits: `977a9cbc6bf3a80cce98df18fc8078fb847b05b5`, `32305b5e6f3f7fa5c641889d9d206e7c6e27c4cf`.
- Report: `decomp_notes/source_cleanup/wave04/tvw_dmap.md`.
- Review accepted the recovered PDB names and presentation changes.
- The owner added the recovered parameter names to `include/tvw_dmap.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/tvw_main.cpp`

- Worker: `sa-f1d0f77f`.
- Worker commits: `b7ec693e8adf1c0c226f534d1a6787ccd77cdb3f`, `9ad776afb338ba76fbac6763d6d333eca3a30d9d`, `ac33781ca5718e8912559c67f478d6f896369505`, `6c2a1178f042685d90915232ac3d7067bdc87044`.
- Integration commits: `b09995de9e754a10fadf81b730604428c25c0305`, `a80c4355ed53167645928f6359c8dbff41f10f52`, `efcf6b46500893d3be9fbb4ec9ae63881953e32b`, `cf6ad778a1b3f91f74fd90b8ad7e63a73ceb7bb8`.
- Report: `decomp_notes/source_cleanup/wave04/tvw_main.md`.
- Review required one-line signatures and complete PDB register coverage.
- The same worker corrected both items and added resource-scope notes.
- The owner resolved this request with the `vw_main.cpp` request in `include/vw_main.h`.
- Status: integrated, reviewed, and unvalidated.

## Header review

The owner changed only the seven assigned headers.
The changes add PDB-backed parameter names to existing declarations.
The changes preserve parameter types, order, access, virtual slots, layouts, and symbols.
`include/vw_main.h` contains one coordinated edit for both source modules.
No duplicate `TRIBE_Main_View` declaration was added.

## Shared requests

No worker requested a new resource ID.
No request targets `include/resource_ids.h`, `include/game_globals.h`, or another owner.
No cross-group request remains open.

## Review and validation status

I reviewed each worker's complete source diff and report.
I reviewed the complete combined source and header diff.
I used `git diff --check` for whitespace review.
Compilation, matching, audits, and tests were not run.
No compiler, build, audit, test, validation, or game command ran in this cleanup group.
Generated code, data, relocations, and call targets remain unvalidated.
Final comparison must use the preserved pre-cleanup build.
That baseline includes its earlier differences from the original executable.
