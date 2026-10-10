# Redundant extern redeclaration removal

## Scope

The starting commit is `6251aeb40`.
This change removes 12 single-line `extern` redeclarations of project symbols from nine modules.
In each case, an included header already declares the symbol. CRT prototypes were out of scope.
Project headers such as `flics.h` and `drawarea.h` also hand-declare CRT functions on purpose.

| Module | Removed redeclarations |
| --- | --- |
| `Pnl_scbr.cpp`, `pnl_btn.cpp`, `pnl_lst.cpp`, `tpnl_inv.cpp` | `debug_timeGetTime` |
| `Scr_sels.cpp`, `scr_sedm.cpp` | `panel_system` |
| `t_c_obj.cpp` | `debug_rand` |
| `taiuaimd.cpp` | `str_fmt_stopObject`, `debug_rand` |
| `tscenaro.cpp` | `rge_read_uncompressed`, `rge_write_uncompressed` |

## Candidates that were kept

A script found 86 project-symbol redeclarations in 48 modules whose names also appear in `include/`.
Each was removed in a trial, and then the full audit ran. Most were not redundant:

- **36 modules failed with `C2065`.** They do not include the declaring header, so the local `extern` is their only declaration.
  Including those headers instead is a separate change, and its output risk is untested.
- **`vw_main.cpp` regressed.** Removing its `debug_timeGetTime` and `color_log` redeclarations changed
  `RGE_Main_View::pick_best_target` (`00540010`) from matching to nonmatching. `draw` also needed review.
- **`tribegam.cpp` and `view.cpp` drifted.** All their exact claims still passed, but `.text` bytes in
  nonmatching functions changed.

In these three VC5 modules, a declaration-only removal changed generated code.
This agrees with the program-mode note, which found `vw_main` sensitive to declaration context.
The trial did not establish the mechanism. Keep these redeclarations until a dedicated investigation explains it.

## Validation

Artifacts are under `build/cleanup-2026-10-10/`. They include the `externs-1` trial and the `externs-3` final run.
The baseline is the full audit at `c41e6039a`.
The earlier commits in this session did not change the nine modules or their headers.

- All nine affected groups compiled. All 289 exact claims passed.
- All nine non-debug object payloads match the baseline.
- No source uses `__LINE__`, so shifted lines cannot change emitted constants.
- `git diff --check` and the line-ending check passed.

No linked executable build, image audit, automated tests, or runtime suites ran.
