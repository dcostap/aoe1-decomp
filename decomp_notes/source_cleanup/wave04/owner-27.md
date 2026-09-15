# Owner 27: Game core and victory

## Scope

- Group: Game core and victory.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Integration branch: `cleanup/staging-20260915-235`.
- Sources: `src/basegame.cpp`, `src/tribegam.cpp`, `src/main.cpp`, `src/getdxver.cpp`, `src/tech.cpp`, `src/teffects.cpp`, `src/victory.cpp`, and `src/tvictory.cpp`.
- Owner headers: `include/basegame.h`, `include/tribegam.h`, `include/main.h`, `include/getdxver.h`, `include/tech.h`, `include/teffects.h`, `include/victory.h`, and `include/tvictory.h`.
- Owner report: this file.

The owner reviewed each complete worker diff and report. The owner integrated every approved worker commit without omitted hunks.

## Module ledger

| Module | Worker | Worker commits | Review and correction history | Integration commits | Status |
| --- | --- | --- | --- | --- | --- |
| `basegame` | `sa-bd1b7a2a` | `e2add30e8ef690448fd884c6a2c2fae024e624ed`, `eab5868075fa5496110e7241f205c94341864ee1`, `479e131d4ab37c319112f7d4c2e744a3bf81cc98`, `f03541ef415e9dab018f91c953b1d6841bf6dac8`, `c10cc03fd57655d65b0b9f3cca6c7a0cb5bb5b82` | The first review accepted PDB names and the shared-buffer comment. It required full 1TBS formatting and an owner-header label request. The resumed worker added both. Final review required the report to retain the pending `IDS_HELP_WINDOW_TITLE` request. | `c2e854bf41d87cb715b5bf8fa717874bccee0809`, `8fb2d796a470f521742678356059ed2ed60a12c9`, `45a0b2d1398e7caa564c55ebfa2b3d914e474c77`, `51c6bb53449a2cd4fb268a5b98941556d778546a`, `02eaf1577e588823c3b67cdffc27592b078b01ba` | Integrated, reviewed, unvalidated. |
| `tribegam` | `sa-9c6e5856` | `934bc31f8521b39f468a3c22af8fd1c653d68b99`, `7fdb5801c8a2477470830c45abdb7a788fe79a86`, `050afa4f0a5fa2f23c3f72ce342acc3fc36e2d94`, `c94d6435a9f4e3ee5a2a82381cd09e85516093a2` | The first run stopped after the late chat mapping and left changes uncommitted. The resumed worker completed all 118 PDB records, formatting, resources, and commits. Later reviews required the exact source hash, owner-header labels, and separate root approval and import provenance. | `13a7af9bc1f910cbcbc194a6ab7fe84e6433c74b`, `2e10a84f6388a63ae773d57eeb3f7b67fa7a2d40`, `5df150dfbd59a8f189cbc492c3d84063f593a664`, `f1c0e83b23eaf31b517a20722f3434f9acbd1114` | Integrated, reviewed, unvalidated. |
| `main` | `sa-b9b9ea03` | `7ee16156ed3c8ed8e0e13d3df57432e8b6200d90`, `729a840ed533911fb1d69a94b6553d488f209ab8`, `fea76f18237366684de41e8f7e934b9d500d3872`, `553533156bea1d6ae75661158e9e079d54e1d5e4`, `a2cf020aaf2324f616c6084b1394734e200f68a7` | Review accepted names, `MB_ICONHAND`, and the discarded-status comment. It rejected unrelated `0x1440` resource evidence. Root then approved `IDS_ERROR_TITLE`. The resumed worker used it for only the title lookup and recorded its evidence. | `677ca04cde8fcff430d3a0f4d3e86bea33dace6f`, `e6e9cf40967c36c212c6c080c91883bfc9f2684e`, `774eeb42cc8849b857ceae18e873f034cacd2da5`, `0e954138560c2992588f8acef4fb659bb8cfc7af`, `6ec8636120e8a8279eb77a1b0b77db951eaeb5df` | Integrated, reviewed, unvalidated. |
| `getdxver` | `sa-5efff5c4` | `6ba3b41613f37ac7e918aa5df166ab413b4fab3a`, `e37de6ebb5c9437772a39fd5b411a6993f511d84`, `4c93f670b298833bf3c804f46fa2c551b77cf747`, `3924329b33d03be2b4e096e4a3554a9715938792` | Review accepted PDB names and pinned SDK constants. It rejected `sizeof(osVer)` because the original explicit-length form was not proved. The resumed worker restored `0x94` and added the header request. | `3e5ee313785cae85b9f47fc023c7e492c183dbe8`, `61db80f2b40023c847dd36500e55730e7a9b4cc5`, `a0bf644703a32d3160f90ace4044101d24399cc0`, `16aec424d664a480354c30c4e3d2f3db8bc4d24b` | Integrated, reviewed, unvalidated. |
| `tech` | `sa-e0b22385` | `87fa48bff8ba7e220ed59b3ca1e8b920594248c3`, `672c30032b738d8a136d002e4a9e30788bd1b458` | Review confirmed that the PDB module has no procedure records. The formatting-only source change kept all tokens and declarations. No correction was required. | `310e41cec52d64e0528e006493df3a103f631400`, `b39c1a92b6bf1d67847f4dcbbb9c4d42057e5606` | Integrated, reviewed, unvalidated. |
| `teffects` | `sa-ae9d8b93` | `829abf45ec73d95397b05e9a6944f4ca5621d197`, `e76f8f8c7be80a1eeb58af465cd4e35064d0e786`, `fae01a9d553a63263b1d7fd06a0dc2cd0bd8fb94` | Review accepted the four PDB-backed parameter renames and unchanged constants. No correction was required. | `e69bfe4171672343ca9095c327be27a9a0ddf19d`, `cafaf4cb453a35b43ecafb133d982b734b14301e`, `3f5722e2c0b135280c1a99932796a5c5dec59356` | Integrated, reviewed, unvalidated. |
| `victory` | `sa-3ec6c2c2` | `8bd1e5ae824fd6bf3e888ad6952fa659930c02a5`, `90664ad01da5056fecaabcf02c83045576689503` | Review covered the complete source diff and all 58 PDB records. It accepted recovered names, unresolved reused homes, and new cleanup names. No correction was required. | `fef60af2abddfadbbaa8e33978862793b2f4b8f7`, `726dc96e88297f87b9dc073e853fa809e202d878` | Integrated, reviewed, unvalidated. |
| `tvictory` | `sa-48d9d496` | `f8d77b08c50df11a6fa74d30ec369a829bd2ddbb`, `35d5fcfcb520942826f1eb5f9277ee448fec2386`, `3510232dfde13dca446702e451434bd68b97b985` | The first delivery used a nonexistent source hash and omitted three header labels. A failed cherry-pick of that nonexistent hash changed no files. The resumed worker copied the exact hash and completed the request. | `598368b7924a3f1ea4e9db67c91b120c2c1376d4`, `829d12482331ba688d9ca4649cb1be680390144f`, `1f596a0d6ee566e1a3d18cb55f6c8373598dcee9` | Integrated, reviewed, unvalidated. |

## Header integration

Owner commit `b2c011d0de031bfbb9cb314ca4011ac3f71e448c` updates parameter labels in:

- `include/basegame.h`;
- `include/tribegam.h`;
- `include/getdxver.h`;
- `include/teffects.h`;
- `include/victory.h`; and
- `include/tvictory.h`.

The labels follow the reviewed PDB-backed source definitions. The commit changes no type, order, calling convention, layout, value, or ABI symbol.

`include/main.h` and `include/tech.h` need no change. The Main header has no `WinMain` declaration. The Tech PDB module has no procedure records.

## Shared integration and requests

Owner commit `7d1f640427c39ecdd2ccd306890379c02703c384` imports only two root-owned headers:

- `include/chat.h` from Owner 22 commit `c0ce37473c32dfd6511e884ea1ead7dace6b5cce`;
- `include/resource_ids.h` from root commit `0aa69b43219d638bf1a6667b832257d633635ccf`.

The chat header supplies `CHAT_RECEIVED` as `0x17D5`. Root approved the 22
resource mappings in commit `bf943f3339643ee5beca7dd74e98b4cb729e48d3`.
That approval produced `include/resource_ids.h` blob
`3670c49563f971137b89644d4a0069796cf3d2af`. Later commit
`3f5867e84cda53a3103593a0e74f952a3f0798b7` imported the same blob. These
mappings were not in the common base. Root commit
`0aa69b43219d638bf1a6667b832257d633635ccf` also adds `IDS_ERROR_TITLE` as
`0x07D1`.

One historical shared request remains pending. Root has not approved
`IDS_HELP_WINDOW_TITLE` for `0x03EB`. `src/basegame.cpp` keeps the numeric value.
The destructor passes the loaded text to `FindWindowA("MS_WINHELP", str)`.

## Review limits

The owner reviewed all complete worker diffs, worker reports, correction diffs, the combined header changes, and the combined group file list.

Compilation, matching, audits, validation commands, tests, and games were not run. The group remains reviewed but unvalidated. Final generated-output comparison must use the preserved pre-cleanup build and retain its prior original-executable differences.
