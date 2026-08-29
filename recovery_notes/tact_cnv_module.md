# tact_cnv grouped compile note

The registered group is `src/tact_cnv.cpp` with `default_gx.rsp`.

## Compile debt repair

`basegame.h` already declares `debug_rand` with C++ linkage.  The module had
an extra `extern "C"` declaration, which contradicted that ABI.  Removing the
duplicate declaration keeps the original `debug_rand(char*, int)` symbol.

The group now compiles with `python tools/build_function.py --va 004CD9E0
--force`.  Representative owner `004CD9E0` reports `MATCH` and `0.0000%`.
No `basegame.h` change was needed.
