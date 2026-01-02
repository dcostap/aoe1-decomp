# AoE1 Decompilation Project - AI Protocol v2.1

## 1. Project Mission & Philosophy
We are reconstructing *Age of Empires (1997)* (Rise of Rome Beta) from x86 Assembly to clean C++.

*   **Behavioral Fidelity > Lossless Decompilation:**
    *   We aim for **exact behavior matching**, not a byte-perfect reproduction of the original assembly.
    *   If the original code contains optimization artifacts (e.g., weird loop unrolling) or dead code, you may refactor it into clean, logical C++ *as long as the side effects and logic remain identical*.
    *   We aim for simple, C-like, C++ code, avoiding complex C++ features
    *   NO FORWARD DECLARATIONS. Every type must be fully defined before use. If you don't have the source of truth for a type yet, completely ignore it for now.
*   **Architecture:** Windows x86 (32-bit). Pointers = 4 bytes.
*   **Compiler:** MSVC (1997 era). Default alignment (4 bytes).
*   **Source of Truth:** PDB-enabled Ghidra export.

## 2. Directory Structure
*   `common.h`: All POD structs (`RGE_Prog_Info`), global Enums, GUIDs, etc.
*   `common.cpp`: Code for loose functions or loose code not attached to a class and used in multiple places.
*   `rge/`: Engine classes (prefixed `RGE_`) and any other engine-related classes.
*   `tribe/`: Game logic classes (prefixed `TRIBE_`) and any other game-specific classes.

## 3. The "Dependency Driven" Workflow
We implement the code exactly as the Source of Truth dictates. 

1.  **Do not stub** unless absolutely necessary.
2.  **Write missing function calls.** If `TRIBE_Game` calls `RGE_Sound::init()`, but we don't have the source of truth for that function yet, write the call still. Let the compiler errors tell us what to implement next.
3.  **Strict Class Definitions:** When provided with a new Class Layout, define the **entire** header (Members & VTable), not just the parts used in the function. 
4.  When provided with a new Class Layout, do also output the entire .cpp file with stubs and a `// TODO: stub` comment inside each of the functions we don't know the implementation to yet.

## 4. Handling Ambiguity & Refactoring

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
*   **Action:** You are **allowed** to extract repetitive, complex inlined assembly into small `private` helper functions to keep the main logic readable.

## 5. Header Verification (MANDATORY)
Every class header (`.h`) must conclude with static assertions, given the information of the source of truth, to preserve memory layout stability during the decompilation.

```cpp
// Verification Example
static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game Size Mismatch");
static_assert(offsetof(TRIBE_Game, player_array) == 0x400, "TRIBE_Game Offset Mismatch");
```

## 6. Input Data Format (What I MAY provide)
I MAY provide a text block containing:
1.  **[Function]**: The decompiled C code of the function we are working on.
2.  **[Class Layout]**: The specific members and VTable (with function signatures) of the owning class.
3.  **[Parent Class]**: The layout of the base class (if applicable).
4.  **[Struct]**: Definitions of any auxiliary structs used in the function.

## 7. Your Task
Given the input data and the information you have available, your task is to:
1.  Identify if new `.h` files need to be created (e.g., if I provide a new Struct or Class Layout).
2.  Generate the needed new header file(s) with correct inheritance and VTables.
3.  Generate the needed new `.cpp` files.
4.  **Do not guess** types or code. If the input says `undefined4`, use `int` or `void*` based on context, or ask. 
5.  If impossible to implement something essential, or essential information is missing for the correct decompilation process, just don't output code and report back.
6.  You may completely ignore thunk empty functions that have no XREFS.