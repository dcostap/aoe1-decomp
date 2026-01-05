# AoE1 Decompilation Project - AI Protocol v3

## 1. Project Mission & Philosophy
We are reconstructing *Age of Empires (1997)* (Rise of Rome Beta) from x86 Assembly to clean C++.

*   **Behavioral Fidelity > Lossless Decompilation:**
    *   We aim for **exact behavior matching**, not a byte-perfect reproduction of the original assembly.
    *   If the original code contains optimization artifacts (e.g., weird loop unrolling) or dead code, you may refactor it into clean, logical C++ *as long as the side effects and logic remain identical*.
    *   We aim for simple, C-like, C++ code, avoiding complex C++ features
*   **Architecture:** Windows x86 (32-bit). Pointers = 4 bytes.
*   **Compiler:** MSVC (1997 era). Default alignment (4 bytes).
*   **Source of Truth:** PDB-enabled Ghidra export.
*   **Current situation**: 99% of structs, functions, and classes, were recovered from the PDB + Ghidra. Most .h files are complete, but they may need adjustments in imports, forward declarations, or minor tweaks. Most that weren't still involved in the current main code path probably don't compile straight away.
*   **Naming Conventions:** All the existing names of files and functions and classes are straight from the PDB. Do not change them or rename them.

## 2. Handling Ambiguity & Refactoring

### A. Unresolved VTable Calls
Sometimes Ghidra cannot identify the function name and shows a raw offset call (e.g., `(this->vtable + 0x14)(...)`).
*   **Action:** If you cannot map it to a named function in the header, **preserve the raw logic** using a cast, but tag it.
*   **Format:**
    ```cpp
    // TODO: Resolve VTable Index 0x5 (Offset 0x14)
    (*((void(__thiscall **)(void*))(*(int*)this + 0x14)))(this);
    ```

### B. Inline Helpers
The original code often aggressively inlined logic (macros, linked list manipulation).
*   **Action:** You are **allowed** to extract repetitive, complex inlined assembly into small `private` helper functions to keep the main logic readable. Include this in your final report.

### 3. Task
We are mostly lacking the main implementation of the functions. 99% of the functions are included as stubs, with an empty body that just includes, as commented code, the original assembly for that function. 
Our job is to implement the actual code. This may introduce new dependencies, global variables, etc. 
You will be provided a bunch of context. We will never provide every full file, only the probably relevant parts. You will have to ask for more context if you need it. You will be provided stubbed functions, which are the ones you have to implement.
1. Analyze the stubbed functions I provide, with the dump of commented assembly inside the body. Analyze, with the context you have about the project, if we're ready to start implementing the code right now.
   a) You may be missing context about the definition of a struct, class or function, as the code may be manipulating that data. Thus, ask the user, and WAIT FOR HIS ANSWER.
   b) There may be access to global variables, which may already be defined, but the context doesn't make clear. Thus, ask the user, and WAIT FOR HIS ANSWER.
2. Once everything is settled, you actually implement the code, being as faithful as possible to the original assembly logic, and adding plentiful comments to explain your reasoning. You output all the new code: every function you implemented, every new global variable, etc, with helpful commentary to let the user know what to copy paste and where.
