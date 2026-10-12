# Age of Empires: Rise of Rome decompilation

C++ source for the 17 July 1998 beta of *Age of Empires: The Rise of Rome* (`empiresx.exe`),
recovered function by function. It is compiled with the original Visual C++ 5.0
compiler and checked against the original executable. This is a build (that you can find around the web) which dates back a few months before the actual release of the DLC. I haven't analyzed nor found any obvious differences between this beta and the final release.

| Status | Functions | % of functions | Bytes | % of bytes | Meaning |
| --- | ---: | ---: | ---: | ---: | --- |
| `matching` | 5,013 | 92.39% | 871.04 KB | 68.81% | byte-identical to the original |
| `accepted_drift` | 140 | 2.58% | 59.00 KB | 4.66% | almost a match, small harmless compiler-output differences |
| `accepted_logic` | 217 | 4.00% | 299.77 KB | 23.68% | ... hopefully same behavior? I couldn't get to match these, VC5 quirks make it extremely hard on some functions, so we mostly just launch a looping cascade of reviews until all agents agree that the function _probably_ matches the original logic.    |
| `nonmatching` | 56 | 1.03% | 35.97 KB | 2.84% | not deeply analyzed yet - but these would probably fit right in accepted_logic |
| **total** | **5,426** | **100.00%** | **1,265.78 KB** | **100.00%** | |

Byte totals use original function sizes from `inventory/all_functions.csv`. 1 KB = 1,000 bytes. Percentages can differ from 100% due to rounding.

It all compiles and links into a complete `empiresx.exe`.

## You need

- Windows and Python 3.12: `pip install pefile iced-x86 capstone pytest`
- Visual C++ 5.0. Set `VC5_DIR` if it is not in `C:\Program Files (x86)\DevStudio`.
- MASM `ml.exe` 14.36 from Visual Studio 2022 (see `config/assembly_toolchain.json`)
- `DPLAYX.LIB` and `DXGUID.LIB` from Visual C++ 6.0 in `third_party/directplay/lib/x86/`
- A retail Age of Empires + Rise of Rome install in `runtime/` ([details](runtime/README.md)).
  The build takes the program icon from it, and the game runs on its data.

That is enough to build and play. The build uses no files from the beta: every
part of the executable is compiled or assembled from this repository.

Only for comparing with the original and for decompilation work: the beta `empiresx.exe`
and `age1_x1.pdb` in `orig/` ([details](orig/README.md)). `game.cmd original`, the tests
that compare against the original, and the research tools need them.

## Build and play

```bat
game.cmd setup      :: one-time: graphics wrapper and harness dependencies
game.cmd build      :: compile and link everything
game.cmd rebuilt    :: play the rebuilt game
game.cmd original   :: play the original, for comparison
python tools\check_function.py --va 00448A80   :: compare one function
```

## How it was made

Via a massive orchestration of AI agents, working under a customized harness. See [`workflow/`](workflow/README.md) for details.
