# AoE1 Decompilation Project - AI Protocol v2.1

## 1. Project Mission & Philosophy
We are reconstructing *Age of Empires (1997)* (Rise of Rome Beta) from x86 Assembly to clean C++.

*   **Behavioral Fidelity > Lossless Decompilation:**
    *   We aim for **exact behavior matching**, not a byte-perfect reproduction of the original assembly.
    *   If the original code contains optimization artifacts (e.g., weird loop unrolling) or dead code, you may refactor it into clean, logical C++ *as long as the side effects and logic remain identical*.
*   **Architecture:** Windows x86 (32-bit). Pointers = 4 bytes.
*   **Compiler:** MSVC (1997 era). Default alignment (4 bytes).
*   **Source of Truth:** PDB-enabled Ghidra export.

## 2. Directory Structure
*   `common_types.h`: All POD structs (`RGE_Prog_Info`), global Enums, and GUIDs.
*   `rge/`: Engine classes (prefixed `RGE_`).
*   `tribe/`: Game logic classes (prefixed `TRIBE_`).
*   `global/`: Loose functions or loose code not attached to a class and used in multiple places.

## 3. The "Dependency Driven" Workflow
We implement the code exactly as the Source of Truth dictates. 

1.  **Do not stub** unless absolutely necessary.
2.  **Write missing function calls.** If `TRIBE_Game` calls `RGE_Sound::init()`, write it. Let the compiler error tell us what to implement next.
3.  **Strict Class Definitions:** When provided with a Class Layout, define the **entire** header (Members & VTable), not just the parts used in the function.

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
*   **Action:** You are explicitly **allowed** to extract repetitive, complex inlined assembly into small `private` helper functions or `inline` utility functions to keep the main logic readable.

## 5. Header Verification (MANDATORY)
Every class header (`.h`) must conclude with static assertions to prevent memory corruption.

```cpp
// Verification Example
static_assert(sizeof(TRIBE_Game) == 0x1254, "TRIBE_Game Size Mismatch");
static_assert(offsetof(TRIBE_Game, player_array) == 0x400, "TRIBE_Game Offset Mismatch");
```

## 6. Input Data Format (What I will provide)
I will provide a text block containing:
1.  **[Function]**: The decompiled C code of the function we are working on.
2.  **[Class Layout]**: The specific members and VTable (with function signatures) of the owning class.
3.  **[Parent Class]**: The layout of the base class (if applicable).
4.  **[Struct]**: Definitions of any auxiliary structs used in the function.

## 7. Your Task
Given the input data:
1.  Identify if new `.h` files need to be created (e.g., if I provide a new Struct or Class Layout).
2.  Generate the header file(s) with correct inheritance and VTables.
3.  Generate the `.cpp` implementation for the provided function.
4.  **Do not guess** types. If the input says `undefined4`, use `int` or `void*` based on context, or ask.