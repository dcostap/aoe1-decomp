# Owner 17: Core panels

## Scope

- Base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Integration branch: `cleanup/staging-20260915-145`
- Integration worktree: `build/source-cleanup-20260915/wave-worktrees/slot-145`
- Group state: reviewed and integrated; validation not run

The delivery response records the final group head after this ledger commit.

## Worker ledger

| Module | Worker | Worker head | Integration commits | Review and correction history |
| --- | --- | --- | --- | --- |
| `src/Panel.cpp` | `sa-3a16bed8` | `7462ce539c8f560654cec1c0358cc278687e7d1d` | `925d2a7cd2a1983478b55e345e42d07a5030207c`, `5747e07d4dc81f98070af040be881191cc52d81b`, `2c90078dd53a6b9cb2ef2c71bc5730102b788dec`, `921077f6047b726cea34b364f66e904f8baf535d` | Review found stale `left` and `top` uses after parameter recovery. Run 2 fixed both uses and reviewed all renamed parameters. |
| `src/Panel_ez.cpp` | `sa-274a01d0` | `5747539bc7a673479bc8c27665f720df081a88f1` | `0504430de946fd2e22d430c85b2be755e79d6327`, `2e7bbd94b9606df5aacf651a7c1ff3397f02ca20`, `6150f715406a583ea3053a7f0407e811f1ff0d78`, `e1f26ddd94cefec8f34de72a32321992891b2c08` | Review rejected local names forced from reused stack homes. Run 2 restored unresolved names. Run 3 restored the unrelated `ideal_h` local. |
| `src/pnl_btn.cpp` | `sa-71768b66` | `37e8513fc4ab2c110a72b6d3a6b5d89bfdc3bfde` | `b646797b02699e05086961920826c9f6434776e1`, `379fcdf4526c3b76943e381bb0c7a375579773be`, `83d0607e2171367455c81436dc0daf04933f0f27` | Review found one-parameter-per-line formatting and expanded simple bodies. Run 2 corrected the formatting. |
| `src/Pnl_drop.cpp` | `sa-1785b4e5` | `6357b42267fd04cbcf9c00b379e78d32adae9c95` | `1235b3743e9e81d35860f7acf4479d0f2223c301`, `2cf5f1d7e81090461afcac0ce320170842981c67`, `e2f9965fbfe611f05c00876d5faac92b9463b1c5` | Run 1 passed source and report review. |
| `src/pnl_edit.cpp` | `sa-c161efbd` | `e4975343f32c0a87a4eb8a9911d15a261591d189` | `9d245621fe667d0a0bd859e728de3755987db648`, `748eeccadf6384c10a8404d10416131d413f0b90` | Run 1 passed source and report review. |
| `src/pnl_lst.cpp` | `sa-549a27b0` | `cf4f4f4b621506cffea93908014ef930484531a9` | `10f4d549b47bae64c4ae977d24d100f6699e1ae1`, `3bfda3c2c79e04e16d9f8e22ec5b1b65cdcb4522`, `a6a7ff311a77282991f0132694fe5c5d93a38959`, `55cefe7deb1d3c08f066d1ed33199cdeda9b6993`, `67886b6afe40935aa86e8a7deccdc7b1f8e2d93c` | Review found that the report called recovered local `r` unchanged. Run 2 corrected the report and recovery count. |
| `src/Pnl_txt.cpp` | `sa-f1126b1a` | `f3c6e206b09890259bbedaeac443e4c70063e4eb` | `bc8ac77cd93b1bcdfbad9c3506e4e3ab7a664f75`, `77cb211b8bb36a6aea2d29f4322d22adb33f9362`, `64f748d079ae8a29912333e10440181a0530dcdd` | Review found the wrong preserved baseline path and alternate executable path. Run 2 recorded the required paths and object hash. |
| `src/Pnl_scbr.cpp` | `sa-90029504` | `564f2a1e8fca5f1110280702c9d64145367e0571` | `532fe862cce27d04655e866fc253b272e4e1281d`, `9d5a8ff3ba7c21f0e4e61f73096c11a6411d647f` | Run 1 passed source and report review. Its header request was approved. |

Each integration includes the complete approved worker commit sequence.
No source or report hunk was omitted.

## Header review

Owner commit `ab9e6e690674c4e4dd807bb99f65bcf34907eb61` adds proven parameter names to `include/Pnl_scbr.h`.
It changes no type, value, layout, calling convention, or symbol.
The source reports requested no other header change.
The other seven owned headers remain unchanged.

## Shared requests

No resource mapping or root-owned header request remains open.
No cross-group request remains open.

## Combined review

The combined diff changes the eight assigned sources, their eight reports, `include/Pnl_scbr.h`, and this ledger.
The source changes recover PDB names, apply 1TBS formatting, and use proved existing SDK or panel symbols.
No worker added a helper, layout, assembly block, resource macro, or behavior repair.

The reports keep unresolved optimized local mappings visible.
The reports also keep existing matching and behavior limits visible.

## Validation

Compilation, matching checks, audits, tests, and games were not run.
The group remains reviewed but unvalidated until the final validation stage.
