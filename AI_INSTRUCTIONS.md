# AoE1 Decompilation Project: AI Agent Protocol

## 1. Project Overview
This project is a C++ reconstruction of the original *Age of Empires (1997)* source code. We use a targeted export system (`layout.json`, `logic.cpp`, `globals.json`), run in the Ghidra decompilation project, to generate the (imperfect) data we need. 
We took advantage of a PDB file in a beta build for the Rise of Rome expansion of AoE1.

## 2. Technical Constraints (MANDATORY)
*   **Architecture:** Windows x86 (32-bit). Pointers are **4 bytes**.
*   **Memory Alignment:** **Default MSVC Alignment (4-byte).**
*   **Source of Truth:** What's inside `ghidra_decomp`
*   **Verification:** You **MUST** include `static_assert` checks at the bottom of the header to verify the total size and key member offsets.

## 3. Input Data (The "Context Quad")
For every task, you will be provided with a hierarchy of folders, where we group classes, each into their own folder. The source of truth is what's inside `ghidra_decomp`:
1.  **`layout.json` (one per class)**: Memory schema (Offsets, Sizes, VTable).
2.  **`logic.cpp` (one per class)**: Decompiled C code (Logic).
3.  **`common_types.h`**: Global types (Enums, POD Structs).
4.  **`globals.json`**: Mapping for global variables and string literals.

## 4. Decompilation Workflow

### Step 1: Generate the Header (`.h`)
*   **Inheritance:** Identify the parent from `layout.json`.
*   **VTable:** Define `virtual` functions in the **exact order** of the `vtable` JSON array.
*   **Members:**
    *   Declare members in order.
    *   **Automatic Padding:** Rely on the compiler for small alignment gaps (e.g., `char` -> `int`).
    *   **Manual Gaps:** If `layout.json` shows a large jump (e.g., offset `0x04` to `0x20`), insert a placeholder: `char _gap_0x04[0x1C];`.
    *   **Unknown Members:** If `layout.json` has no members but `size` is `0x100`, create a buffer: `uchar _unknown_data[0x100 - sizeof(Parent)];`.

### Step 2: Verification (Crucial)
At the end of the header, generate assertions:
```cpp
// Verify total size
static_assert(sizeof(ClassName) == 0x240, "ClassName size mismatch");
// Verify specific offsets (Pick 2-3 random members from JSON)
static_assert(offsetof(ClassName, memberName) == 0x54, "ClassName::memberName offset mismatch");
```

### Step 3: Generate the Implementation (`.cpp`)
*   Translate `logic.cpp` into standard C++.
*   **Strings:** Use `globals.json` (or `[HELPER]` comments in `logic.cpp`) to replace symbols like `s_Text` with actual string literals (e.g., `"Text"`).
*   **Globals:** Resolve global pointers (e.g., `L`) using `globals.json`.
*   Replace raw memory casts `*(int*)(this + 0x20)` with the named member `this->variableName`.
*   Keep in mind the original code is C code, reconstructed by Ghidra. Interpret the logic into natural C++ (e.g., `this->func()` instead of `func(this)`).

## 5. Coding Standards

### Example Header
```cpp
#pragma once
#include "RGE_Base_Game.h"

class TRIBE_Game : public RGE_Base_Game {
public:
    // Virtual Functions (Order MUST match layout.json)
    virtual ~TRIBE_Game();
    virtual void update();

    // Members (Offsets must match layout.json)
    /* 0x0120 */ int game_state;
    /* 0x0124 */ char player_name[32]; 
    // Compiler adds implicit padding here if needed to align next int
    /* 0x0144 */ int score;

    // Manual gap example (if JSON skips from 0x148 to 0x200)
    /* 0x0148 */ char _gap_148[0xB8];
    
    /* 0x0200 */ int next_var;
};

// MANDATORY VERIFICATION
static_assert(sizeof(TRIBE_Game) == 0x204, "TRIBE_Game size mismatch");
static_assert(offsetof(TRIBE_Game, next_var) == 0x200, "TRIBE_Game::next_var offset mismatch");
```