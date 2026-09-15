# Owner 20: Audio and image support

## Scope

- Base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Integration branch: `cleanup/staging-20260915-172`
- Integration worktree: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-172`
- Group: Audio and image support

The group owns eight source modules and their reports.
Owner 20 owns the eight paired headers.
Root owns all other headers.

## Worker review and integration

| Module | Worker | Worker commits | Integrated commits | Review result |
| --- | --- | --- | --- | --- |
| `src/Cdaudio.cpp` | `sa-f0608576` | `229d74d94d249231d25b7c35da7090ffff83861c`, `b06fe94b077c409200cb41fdae119e81556087b2` | `4daf0e3a64e86877fdbe5064d03ba6f99b5d6099`, `e33e667733b5c6e8159a8f7648e52861dbcb8664` | Approved. The source restores all reliable PDB names. |
| `src/music.cpp` | `sa-d4aa2ce2` | `8cff18b8d9185d8c4769dcbbc11bdcf80e1e407f`, `be45a89c312974f0edcf0cb024229d7e07b62192` | `d44064effde0bf5015b5cee610d8a223aacc9e28`, `6727a00f062cfaff521c75608c74f464cfa77f48` | Approved. The source restores all reliable PDB names and uses 1TBS. |
| `src/Sound.cpp` | `sa-f36ac73c` | `e6e50623c92724fedda3fb605e57c4dcd55e0e13`, `bf9e4f1870ec795d72bd79535aaca5906325a87a`, `2cd293369aa522d75889c3be17a4f2c593e0c5ff`, `3230d0abe4ed917a97dacd45f6fb82beb5c53df7` | `8bc08a134d9575cb580050a9c950c13bd26633f3`, `e0370c17129a0b82e1dc9514498da15b093906d4`, `b1c812922c624d46d63c619e59a52e06f53a5a87`, `52eb8d4881d8608452167100d18e6bc7b3a9285a` | Approved after correction. The worker restored `add_to_play_list` and fixed its report. |
| `src/Sounddrv.cpp` | `sa-cd3df950` | `842ea65f0863f0da9870b4e3959ea8a07028b5b6`, `f31d2d89a749dbc0cff3726b3f812dc9abe5382a`, `d08365e4a46167685602ca959a71d0f0c3d94a42` | `365a43c33b260af3708b46151cc769b198ea3384`, `aae8fe3f6684b2d8013b5fb3b6505f65c6945516`, `248f396085c344a274325653416895be21d7b7b2` | Approved. Pinned SDK macros preserve the reviewed values and call roles. |
| `src/Dsutil.c` | `sa-4ae58ea1` | `3ca1b0b561f6e2ae03a0598a16136369b370f220`, `58159ed815095607e41cb2b813b7ef104ad7d070` | `979cd9e1f457362ce8ea5e9ded1e2cd725af0e41`, `c4e9e728af1b0b2560965106ad1efb3df91c5ef9` | Approved. The source preserves unresolved omitted parameters and type differences. |
| `src/flics.cpp` | `sa-2f4737ab` | `983605284d47d07e749cf2fedfc6e51f17db0c8f`, `03844dace88bdb227fce3565fe75f98ea5c9f3c1` | `be5da4d159b1c8d0d42a838906d0cc2771f205cf`, `ef8d224dc5bca708d40d1a3fc2654d22b96e2a67` | Approved. Pinned CRT macros preserve binary mode and seek origins. |
| `src/Dib.cpp` | `sa-027a8159` | `559e1492c9ad3a8d15d1dbd24b1512fab69f0c48`, `5d0c88372120345220219e6e6dac02ff7ed5134c`, `0789a3591bb8a64f5f162e70c8a696297f36b554`, `8224246088da3631d44f0d534b777cb76a791318` | `9172515a5232b57bf0589dd2c88c5f3c3c317e1f`, `317dd5d755e685bbd77dda6e17b1fd6e1fdc4f52`, `8caee9318f0eb249b4bcec21b5a93d03c50b9521`, `a5f032617012676552ae90b104e58acba005cfa3` | Approved after correction. The worker applied 1TBS and recorded the header request. |
| `src/Picture.cpp` | `sa-5b25c9e2` | `0c57ce1807f4ecb5c87b3ad248728b4434493ec2`, `47ed5de4c0b9fefbd605aa94556c5f4095fed05e` | `3cc8c7837fcd1cf413b240d6a9b03d64fd6141cd`, `54e24442bc068fb8759272d1b7a885ce348a7e85` | Approved. The source restores all reliable PDB parameter names. |

All eight worker worktrees were clean after delivery.
I read each complete source diff and report.
I retained the Sound and Dib correction history.

## Header work

Header commit: `2a9c8ea2ac426219066a27bc4ce919225bdcbae8`

The commit updates parameter names in these owned headers:

- `include/cdaudio.h`
- `include/music.h`
- `include/sound.h`
- `include/sounddrv.h`
- `include/flics.h`
- `include/dib.h`
- `include/Picture.h`

The names match procedure-scoped PDB records and the reviewed source definitions.
No parameter type, function type, layout, or symbol changed.
`include/dsutil.h` contains no matching function declarations, so it needed no change.

## Findings and open items

Each worker inspected every assigned procedure in the scoped PDB records.
The module reports contain function-level evidence and unresolved mappings.

The group made no RT_STRING resource-ID change.
No worker requested a new shared resource macro.
No cross-group header request remains open.

Known limits remain in the module reports.
They include optimized stack aliases, omitted Dsutil parameters, and retained type differences.
The `CCDAudio::GetPosition` PDB names remain semantically unusual.
The cleanup preserves those original names.

## Review and validation state

The combined diff contains only assigned sources, reports, and owned headers.
`git diff --check` passed for each worker and the combined group.
A final placeholder search found no `param_*`, `local_*`, or `a<number>` names in the group scope.

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
All work remains reviewed but unvalidated.
Final validation must compare generated output with the preserved pre-cleanup build.
That comparison must retain its prior original-executable differences.
