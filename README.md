# Age of Empires: Rise of Rome decompilation

C++ source for the 17 July 1998 beta of *Rise of Rome* (`empiresx.exe`),
recovered function by function. It is compiled with the original Visual C++ 5.0
compiler and checked against the original executable.

| Status | Functions | Meaning |
| --- | ---: | --- |
| `matching` | 5,013 | byte-identical to the original |
| `accepted_drift` | 140 | same behavior, small compiler-output differences |
| `accepted_logic` | 217 | same behavior, proved by review; code differs more |
| `nonmatching` | 56 | not done yet |
| **total** | **5,426** | |

The whole game compiles and links into a complete `empiresx.exe`.

## You need

- Windows and Python 3.12: `pip install pefile iced-x86 capstone pytest`
- Visual C++ 5.0. Set `VC5_DIR` if it is not in `C:\Program Files (x86)\DevStudio`.
- MASM `ml.exe` 14.36 from Visual Studio 2022 (see `config/assembly_toolchain.json`)
- `DPLAYX.LIB` and `DXGUID.LIB` from Visual C++ 6.0 in `third_party/directplay/lib/x86/`
- The beta `empiresx.exe` and `age1_x1.pdb` in `orig/` ([details](orig/README.md))
- A retail Age of Empires + Rise of Rome install in `runtime/` ([details](runtime/README.md))

## Build and play

```bat
game.cmd setup      :: one-time: graphics wrapper and harness dependencies
game.cmd build      :: compile and link everything
game.cmd rebuilt    :: play the rebuilt game
game.cmd original   :: play the original, for comparison
python tools\check_function.py --va 00448A80   :: compare one function
```

## How it was made

Mostly by AI agents, working under a review process. [`workflow/`](workflow/README.md)
has the whole story: roles, docs, tools, and every function note and review.

---

This repository contains no game code or assets; you need your own copy of the game.
Not affiliated with Microsoft or Ensemble Studios. Released under CC0 1.0 Universal, see [LICENSE](LICENSE).
