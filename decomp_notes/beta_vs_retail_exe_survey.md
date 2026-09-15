# July beta versus September release EXE

## Conclusion

The binaries share substantial code. This survey supports direct reuse of much beta analysis for the release.
It does not establish a percentage of unchanged gameplay.

A strict address-masked search found 2,627 unique instruction-pattern candidates in the release.
That is 60.3% of the 4,358 eligible beta inventory entries.
Those candidates represent 45.1% of eligible beta entry bytes.
These are candidate correspondences, not proved function or behavior matches.

The release EXE is 15.7% smaller. Its main code section is 11.0% smaller.
Removed debug records explain part of the file reduction.
Numerous missing diagnostic strings suggest that removed diagnostics also explain some code reduction.
The survey does not quantify that contribution.

## Inputs and identity

Beta input:

`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- PE timestamp: `1998-07-17 19:23:29 UTC`.
- Version string: `00.03.01.0717`.
- The repository's `_original_empiresx_from_beta_that_was_decompiled.exe` has the same hash.

Release input came from this local disc image:

`C:/Users/Darius/Downloads/aoe iso/test/Age of Empires - The Rise of Rome Expansion (USA) (Rev 1) (Track 01).bin`

- Track SHA-256: `58ebe941f3eaee27ecbfb28dc834f17924517a01d1cbb95555dc8cd5d00c787f`.
- CUE format: MODE1/2352.
- Extracted member: `GAME/EMPIRESX.EXE`.
- EXE SHA-256: `8e0e6d047b2f90d0769fb5a1b16c1b1973582efdbe73a5d11395a43557215845`.
- PE timestamp: `1998-09-01 23:39:46 UTC`.
- Version string: `00.04.2.0901`.
- Product version: `1.0`.

Both EXEs report linker version 5.0. Their PE timestamps are about 46 days apart.
These fields identify the compared builds. They do not prove compiler flags or release dates.
The disc filename identifies a USA Rev 1 image. No external disc checksum verification ran.
This report does not cover a later patched release, such as 1.0a.

### Why the installed EXE was not the final input

`E:/GamesInstalled/Age of Empires/EMPIRESX.EXE` has SHA-256:

`5c12603573e410d0cc37b0f9c12442824ba1c4c3b44a0473b5b2cf149ad18eda`

It has changed PE sections and three changed `.text` bytes relative to the disc EXE:

| VA | Disc byte | Installed byte |
|---|---:|---:|
| `00419C90` | `74` | `90` |
| `00419C91` | `12` | `90` |
| `0044DBD8` | `BF` | `FF` |

The installed `.rdata`, `.data`, `.idata`, and `.rsrc` raw sections equal the disc sections.
The installed `EMPIRESX - Copy.EXE` restores only the last byte from this table.
Neither installed copy is the disc EXE. Their patch purpose was not established.

## Measured binary changes

| Measure | Beta | Disc release | Change |
|---|---:|---:|---:|
| File bytes | 1,795,072 | 1,513,984 | -281,088; -15.7% |
| `.text` virtual bytes | 1,445,968 | 1,286,517 | -159,451; -11.0% |
| `.text` raw bytes | 1,446,400 | 1,286,656 | -159,744 |
| `.rdata` raw bytes | 69,632 | 63,488 | -6,144 |
| `.data` raw bytes | 80,896 | 62,976 | -17,920 |
| `.data` virtual bytes | 3,188,244 | 2,633,428 | -554,816 |
| Bytes after raw sections | 97,792 | 0 | -97,792 |

The beta debug directory describes miscellaneous, FPO, and CodeView records after the sections.
The release has no PE debug directory.
The beta FPO record alone occupies 97,216 bytes.
Thus, much file shrinkage is not a change to executable instructions.
Virtual data size includes uninitialized storage. It is not measured runtime memory use.

Both disc and beta contain `THIS_COD`, `THIS_DAT`, and `Inf32Dat` sections.
`THIS_DAT` and `Inf32Dat` are byte-identical. `THIS_COD` has equal size but different contents.
The main `.text` comparison does not measure code outside `.text`.

The release imports no new API names. It removes 15 beta imports.
Examples include `GetTickCount`, `SetConsoleCtrlHandler`, `mmioWrite`, and several GDI functions.
This does not establish whether particular game features were removed.

## Function-pattern survey

The survey used `inventory/all_functions.csv` for beta starts and sizes.
This inventory is reference evidence, not proof of release function boundaries.

The script decoded each eligible beta body with Capstone in x86 mode.
It retained instruction bytes, local branch offsets, and ordinary constants.
It masked external direct branch operands and selected operands that point into the beta image.
It searched the release `.text` for each complete masked pattern.
A candidate required exactly one occurrence, at least 32 body bytes, and at least 24 retained bytes.

| Result | Beta entries | Sum of entry sizes |
|---|---:|---:|
| Unique pattern candidate | 2,627 | 595,817 |
| No complete pattern found | 1,595 | 712,086 |
| Multiple pattern occurrences | 136 | 14,295 |
| Too small for this method | 3,054 | 38,072 |
| Incomplete linear decode | 7 | 2,553 |
| Outside the beta `.text` range | 571 | 34,765 |
| Total inventory | 7,990 | 1,397,588 |

Eligible entries comprise the first three rows: 4,358 entries and 1,322,198 bytes.
These are entry-size sums, not independently proved disjoint section coverage.
The inventory includes compiler and library entries. It is not a count of gameplay functions.

Among eligible entries with `.c` or `.cpp` source names, 2,382 of 3,911 have unique candidates.
Their byte sums are 552,601 out of 1,240,805.
This subset still does not establish reviewed source ownership.

Of the 2,627 candidates, 588 have identical raw byte ranges, totaling 60,128 bytes.
Only 481 candidates have no masked references, totaling 44,689 bytes.
Even raw equality at different addresses can preserve bytes while changing relative call targets.
None of these counts is a repository exact-function claim.

### Reference cross-check

Candidate references produced these results:

- 6,993 references agree with other unique candidate start mappings.
- 634 imported targets agree by DLL and import name or ordinal.
- 818 readable string targets agree.
- Five readable string references differ.
- Two references disagree with the candidate start mapping.
- 8,732 references remain unresolved.

Candidate-map agreement is supporting evidence from the same survey, not independent symbol proof.
The two mapping disagreements can indicate wrong candidates or changed targets. Neither was resolved.
Many unresolved references address mutable globals, tables, or small excluded functions.
Their identity and contents still need review.

### Concrete differences inside matching patterns

These strings differ despite matching instruction patterns:

| Beta function VA | Release candidate VA | Beta string | Release string |
|---|---|---|---|
| `004549E0` | `00444490` | `Age of Empires, Roman Expansion` | `Age of Empires Expansion` |
| `004549E0` | `00444490` | `00.03.01.0717` | `00.04.2.0901` |
| `00461A30` | `00450AA0` | `%smusic%d.mid` | `%sxmusic%d.mid` |
| `00462200` | `00451250` | `%smusic%d.mid` | `%sxmusic%d.mid` |
| `00523F10` | `00503060` | `open.mid` | `xopen.mid` |

This is a direct example of why masked instruction equality does not prove behavior equality.

## Where comparison looks easier or harder

The following percentages use candidate byte sums divided by all inventory byte sums for each module.
They measure complete-pattern coverage, not the percentage of unchanged behavior.

| Beta source module | Unique-pattern byte coverage |
|---|---:|
| `gameinfo.cpp` | 95.5% |
| `m_s_obj.cpp` | 94.7% |
| `Drawarea.cpp` | 87.6% |
| `map.cpp` | 79.2% |
| `tmap.cpp` | 78.8% |
| `Act_atak.cpp` | 65.4% |
| `taiinfmd.cpp` | 59.1% |
| `taitacmd.cpp` | 49.7% |
| `scr_game.cpp` | 15.4% |
| `Com_hand.cpp` | 15.2% |
| `tplayer.cpp` | 13.2% |
| `pathsys.cpp` | 8.1% |

Map, drawing, and several object modules offer many useful starting points.
Player, communication, game-screen, and pathfinding modules need more manual comparison.
Low coverage can result from removed logging, small edits, compilation changes, or actual logic changes.
It does not prove a rewrite.

Beta-only text includes many `SEND CMD`, network trace, path dump, and unit-state diagnostic messages.
Release-only text includes additional multiplayer join error messages and expansion music filenames.
The printable-string scan includes accidental instruction text. Its raw string counts are not feature counts.

## Confidence limits

High confidence applies to hashes, sizes, section contents, imports, and directly observed string changes.
Moderate confidence applies to many substantial, unique instruction-pattern correspondences.
Confidence rises when independent boundaries, callers, callees, tables, and data targets agree.

This survey does not prove:

- the release boundary or owning symbol of each candidate;
- equal virtual-call targets, global layouts, or pointed-to data;
- a percentage of changed source lines or gameplay behavior;
- removal of every function without a complete pattern;
- the number of release-only functions;
- equal game assets, balance tables, scenarios, or localization;
- multiplayer, save-format, replay, or full-game compatibility.

The method can miss indexed absolute references and functions containing inline data.
A single changed instruction can reject an otherwise nearly identical large function.
Conversely, masking an address can hide a meaningful change.
Short wrappers and shared code can also produce misleading correspondences.

## Useful next investigation

Use the substantial unique candidates as initial beta-to-release address mappings.
Then check release boundaries and caller relationships before transferring beta names.
Resolve direct targets, vtables, strings, constants, and mutable data separately.
Classify remaining differences as diagnostics, compilation changes, data changes, or logic changes.
Start manual review with `tplayer.cpp`, `pathsys.cpp`, `Com_hand.cpp`, and their known callers.
Compare original game data files separately before making gameplay claims.

## Artifacts and validation

Generated artifacts remain under `build/beta-release-investigation/`:

- `compare.py`: survey implementation.
- `disc.py`: MODE1/2352 extraction preparation.
- `details.py`: focused summary and reference inspection.
- `disc/EMPIRESX.EXE`: extracted release input.
- `retail/report.json`: primary measurements and per-entry candidate results.
- `retail/beta_only_strings.txt` and `retail/release_only_strings.txt`: printable-string differences.
- `main/report.json`: preliminary comparison against the modified installed EXE.
- `self-check/report.json`: identical-input control.

The main survey command was:

```sh
python build/beta-release-investigation/compare.py \
  --beta orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe \
  --release build/beta-release-investigation/disc/EMPIRESX.EXE \
  --output build/beta-release-investigation/retail
```

Static parsing, disc extraction, and both beta-to-release surveys completed with exit code zero.
The identical-beta control also completed with exit code zero.
All 4,358 eligible patterns appeared: 4,137 were unique and 221 were ambiguous.
All unique control candidates had equal raw bytes. The control found no reference disagreements.
This checks basic search consistency. It does not validate cross-build candidate identity.
No original file or game source changed.
No compilation, registry audit, linked-image audit, automated game test, or runtime gameplay comparison ran.
Those stages do not follow from this read-only binary survey.
