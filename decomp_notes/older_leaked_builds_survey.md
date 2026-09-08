# Older leaked builds: evidence survey

## Scope

Input root: `C:\Users\Darius\Downloads\age_of_empires_leaked_builds`.

This survey inspected 4,087 loose files through an Everything inventory.
It also inspected five ISO directory listings and three demo installer listings with 7-Zip.
It extracted their game executables under `build/leak_survey/` for static PE inspection.
No original executable or installer ran. No game source, registry, or build configuration changed.

This is a reference survey, not a function matching or semantic review.
The July 1998 Rise of Rome executable remains the behavior oracle.
Older symbols, layouts, data, and documents require checks against that executable.

## Highest-value result: January executable and linker map

Both these folders contain identical copies of `PTRIBE.EXE` and `PTRIBE.MAP`:

- `AoE 1 Alpha 0.5/AoE 1 Alpha 0.5/GAME/`
- `aoe 2 4 1997/aoe 2 4 1997/Game/`

Hashes (SHA-256):

| File | Hash |
| --- | --- |
| PTRIBE.EXE | `7421b6d8beef75d886a33ac4290b98c94aa66358f1aeb826d6608e66d33ecc75` |
| PTRIBE.MAP | `e8c13f099be87e496138caff0ba2760c3eaf751568990ac74829eb0666ba51eb` |

The map names the image `ztribe`. Its timestamp is `32ee67ac`, dated January 28, 1997.
The executable has that timestamp and image base `00400000`.
Its `.text` and `THIS_COD` virtual sizes agree with the map: `16cc3a` and `a459`.
These checks support the pairing. They do not validate every map entry or function boundary.

The map parser found:

- 6,766 symbol rows with addresses and object ownership;
- 5,625 rows marked `f`;
- 439 distinct object-owner strings, including libraries and `<common>`; and
- 3,117 distinct `f` symbols also present in the current function registry.

The overlap counts identical decorated names, not identical behavior.
The map provides addresses, C++ signatures, globals, vtables, and object ownership for this older build.
It does not provide PDB local variables, complete class layouts, or source text.

### Concrete source-recovery use

At `0040184E`, the map identifies `TPanelSystem::currentPanel`.
The executable stores `this` on the stack and returns the pointer at offset `0x0c`.
It saves three registers and uses an unnecessary return jump.
This sample shows debug-style code with much less optimization than the target.

At `004518C8`, the map identifies `RGE_Action_Bird::set_state`.
One inspected branch calls `005539F0`, which the map identifies as `LIBCD:rand.obj`'s `_rand`.
It multiplies by ten, performs signed integer division by `0x7fff`, and adds five.
It then converts that integer result to a float.
This supports the integer arithmetic already recovered in `src/act_bird.cpp`.
It is not a new target correction or a complete function comparison.

Practical use: resolve a difficult target function by its shared decorated name, then inspect the older implementation.
Use this to propose source forms, not to transfer offsets or behavior without checks.

### Drawing limitation

The map identifies `Asm_draw.obj` and these older public entries:

- `_SHAPE_DRAW_PROCS`
- `_ASMSet_Shadowing`
- `_ASMSet_Surface_Info`
- `_ASMSet_Color_Xform`
- `_ASMSet_Xlate_Table`
- `_ASMDraw_Sprite`

It does not supply assembly source or internal codelet labels.
The older drawing section has a different size from the target.
This does not remove the current drawing-source recovery problem.

## Other debug evidence

The February folder contains several distinct debug-style builds:
`dcptribe.exe`, `etribemp.exe`, `ptribe.exe`, `tribe2.exe`, and `tribed.exe`.
Their CodeView entries use `NB10` and reference external `ztribe.pdb` files.
Those PDB files were not found in the inspected loose files or archive listings.
A PDB path inside an executable is not an embedded PDB.

The April 24 ISO contains a debug-style `GAME/EMPIRES.EXE`.
It references `C:\ZTRIBE\Debug\ztribe.pdb` and contains 8,384 bytes of FPO records.
Its SHA-256 is `47417999c6c9206832069ad97823f54c767293c3a0a3e1e795c574f1c5009562`.
This offers a later debug implementation, but lacks the January map's direct name lookup.

The June 13 ISO contains a release executable with 81,264 bytes of FPO records.
That gives 5,079 fixed-size records for stack and function-range evidence.
It references `C:\ZTRIBE\Release\ztribe.pdb`, which was not found.
Its SHA-256 is `0a013bd4559c4336089da46ee3c96e4336831d23960ef254265f51e74b4cddf4`.
FPO records do not supply function names or complete coverage.

The inspected April 29, June 6, July, August, and demo game executables had no PE debug directory.
These still provide intermediate implementations for selected cross-build comparisons.
The game executables from the 1997 beta folders report linker version 4.20.
Do not use them as evidence for the target's VC5 compiler flags.

Folder dates are not reliable build identities.
For example, the executable in the April 29 ISO has PE timestamp `338df436`.
Use hashes, PE metadata, archive metadata, and internal version evidence together.
Keep the July 16 `CRACK/EMPIRES.EXE` separate from its `GAME/EMPIRES.EXE`.
Their hashes differ despite equal PE timestamps and section layouts.

## Developer AI documents

High-value paths include:

- `aoe 6 6 1997/aoe 6 6 1997/GAME/DATA/AI.DOC`
- `aoe 7 16 1997/AoE_beta_July1997/DOCS/`
- `aoe 8 15 1997/aoebeta_8-15-1997/DOCS/`

The later document sets contain `AI.DOC`, `PERSNLTY.DOC`, `PLAYBOOK.DOC`, `STRATSMP.DOC`, and `STRATTYP.DOC`.
Printable-text inspection confirmed actual developer documentation, not just suggestive filenames.
This inspection did not fully extract or visually validate Word tables.

`PERSNLTY.DOC` explains strategic-number meanings, bounds, parser rules, and group decisions.
Examples include:

- `SNGroupFillMethod` (40): sequential group filling versus balanced filling;
- `SNGroupCommanderSelectionMethod` (75): most health, least health, or most range; and
- `SNFoodGathererPercentage` through `SNWoodGathererPercentage` (117–120).

It also explains when the AI selects and replaces a commander.
These descriptions can help interpret branches and numeric constants in tactical AI.
An exact-name search found no occurrences of the first two names in current source, headers, notes, or docs.
That does not prove the underlying behavior is unknown.

`PLAYBOOK.DOC` describes the play system, its mid-level commander, and its input language.
It defines play types, unit limits, overflow choices, target filters, and other fields.
`STRATTYP.DOC` lists strategy files and intended attack ages and unit choices.

Document versions already disagree in useful ways.
The older AI document specifies three initialization layers: code defaults, `default.vc`, then the selected file.
The later personality document describes two layers: code defaults and the selected file.
This shows why target code must decide behavior, rather than either document alone.

## Text databases and development files

The February `Game/` folder contains text data absent from the current original-file set:

- `tr_obj.txt` (about 2 MB): named objects and structured numeric records;
- `tr_spr.txt`, `tr_snd.txt`, `tr_eff.txt`, `tr_terr.txt`, and other `tr_*.txt` tables;
- `tr_resource.txt` and `Tr_slp_files.txt`;
- `Default_build_list01.txt`, `Default_city_plan01.txt`, and `AiConst.txt`; and
- named `.DAT` databases and saved-game material.

These offer input examples for text loaders, object IDs, resource links, and old database formats.
`AiConst.txt` contains numeric data rows, not C constant declarations.
The text tables do not label every field. Pair them with loader code before assigning field meanings.

`profit.bat` records a developer profiling procedure, credited to `mterrano` on January 7, 1997.
It uses `PREP`, `PROFILE`, and `PLIST`, with a matching executable and map.
This explains the intended profiling use of maps. It does not establish compiler flags.

The folder also includes `MAKE_SHP.EXE`, `SHA_FLI.EXE`, and `shapescn.exe`.
These are possible asset-tool references. Their names alone do not establish supported formats or behavior.

## What did not add new evidence

The downloaded Rise of Rome files match the repo-local originals byte for byte:

- `empiresx.exe`
- `age1_x1.pdb`
- `vc50.pdb`

No additional loose PDB, C/C++ source, header, assembly source, object, or library files were found.
No such additional files appeared in the inspected ISO and demo installer listings.
The alpha InstallShield CAB contents were not separately audited.
Unallocated ISO sectors and arbitrary embedded payloads were not searched.

## Recommended order

1. Index the January map as a separate, hash-pinned reference build.
2. Add name-based access to its disassembly for difficult current functions.
3. Extract the AI documents with table-aware Word support.
4. Use the text databases when reviewing their corresponding loaders.
5. Compare other builds only when a specific function or format needs more evidence.

Do not decompile all builds in parallel by default.
The January named debug code and AI documents offer the clearest immediate value.

## Reproduction artifacts

Temporary scripts, archive listings, extracted executables, and output remain under `build/leak_survey/`.
Key outputs are `survey.txt`, `details.txt`, and `map_common.json`.
This note preserves the conclusions and key input hashes outside that temporary directory.
No exactness, accepted drift, or source-integration claim results from this survey.
