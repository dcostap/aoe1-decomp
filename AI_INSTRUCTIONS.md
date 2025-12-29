# AoE1 Decompilation Project: AI Agent Protocol

## 1. Project Overview
This project is a C++ reconstruction of the original *Age of Empires (1997)* source code. We use a targeted export system, ran in the Ghidra decompilation project, to generate the helpful source of truth  we need. 
(We took advantage of a PDB file in a beta build for the Rise of Rome expansion of AoE1, so the output has names, types and layout info)

## 2. Technical Constraints (MANDATORY)
*   **Architecture:** Windows x86 (32-bit). Pointers are **4 bytes**.
*   **Memory Alignment:** **Default MSVC Alignment (4-byte).**
*   **Source of Truth:** What's inside `ghidra_decomp`
*   **Verification:** You **MUST** include `static_assert` checks at the bottom of the header to verify the total size and key member offsets.

## 3. Input Data (The "Context Quad")
For every task, you will be provided with a hierarchy of folders, where we group classes, each into their own folder. The source of truth is what's inside `ghidra_decomp`:
1.  **`<class_name>.c` (one per class)**: At the start, the layout / memory schema (Offsets, Sizes, VTable). Then, Ghidra's decompiled C code (Logic) with all the methods...
2.  **`common_types.h`**: Global types (Enums, POD Structs).
3.  **`globals.json`**: Mapping for global variables and string literals.
4.  **_Global_Functions**: folder with all the global functions.

## 4. Decompilation Workflow

### Step 1: Generate the Header (`.h`)
*   **Inheritance:** Identify the parent from the layout (see the comment at the start of the decompiled `.c` file)
*   **VTable:** Define `virtual` functions in the **exact order** of the `vtable` JSON array.
*   **Members:**
    *   Declare members in order.
    *   **Automatic Padding:** Rely on the compiler for small alignment gaps (e.g., `char` -> `int`).
    *   **Manual Gaps:** If the layout shows a large jump (e.g., offset `0x04` to `0x20`), insert a placeholder: `char _gap_0x04[0x1C];`.
    *   **Unknown Members:** If the layout has no members but `size` is `0x100`, create a buffer: `uchar _unknown_data[0x100 - sizeof(Parent)];`.

### Step 2: Verification (Crucial)
At the end of the header, generate assertions:
```cpp
// Verify total size (get the size from layout source of truth)
static_assert(sizeof(ClassName) == 0x240, "ClassName size mismatch");
// Verify specific offsets (Pick 2-3 random members from JSON)
static_assert(offsetof(ClassName, memberName) == 0x54, "ClassName::memberName offset mismatch");
```

### Step 3: Generate the Implementation (`.cpp`)
*   Translate the source of truth decompiled C code into our standard, cleaned-up C++.
*   **Strings:** Use `globals.json` (or `[HELPER]` comments in `.c`) to replace symbols like `s_Text` with actual string literals (e.g., `"Text"`).
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
    // Virtual Functions (Order MUST match the layout source of truth)
    virtual ~TRIBE_Game();
    virtual void update();

    // Members (Offsets must match layout source of truth)
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

## Mandatory guidelines

1. Avoid speculative changes. Do not invent structure members, virtual functions, or semantics unless they are clearly supported by the decompilation data. When in doubt, leave placeholders.
2. Do not silence errors by removing logic. Build or link failures should be resolved by fixing declarations, definitions, or dependencies—not by deleting or stubbing core behavior.
3. Be precise and reversible. Make small, targeted changes that can be easily reasoned about. If a change causes confusion, revert and reassess rather than layering fixes.
4. Prefer compile-time guarantees over runtime checks. Use static_assert(sizeof / offsetof) as the primary verification method. Runtime size checks are for temporary investigation only.
5. use `build_and_verify.bat` as the main source of truth for build and verification.
6. YOUR SEARCH TOOL MAY NOT BE RELIABLE 'CAUSE THERE ARE A LOT OF FILES IN THE DECOMPILATION FOLDER, RUN THIS POWERSHELL COMMAND INSTEAD TO SEARCH EFFECTIVELY FOR STRINGS (USES REGEX BY DEFAULT):

```
Get-ChildItem -Path .\ghidra_decomp -Recurse -File |
  Select-String -Pattern '<your search regex string goes here>' -SimpleMatch |
  ForEach-Object { "{0}:{1}: {2}" -f $_.Path, $_.LineNumber, $_.Line.Trim() }
```


# AoE1 Decompilation Project - Master Protocol

## 1. The Golden Rule: Source of Truth
**WE DO NOT INVENT CODE.**

*   **Absolute Prohibition:** Never generate class headers, VTables, or function implementations based on guesswork, standard engine patterns, or previous knowledge.
*   **Mandatory Request:** If a specific function or class layout (Source of Truth) has not been provided in the chat history, I **MUST** stop and request it from the user.
*   **No "Standard Logic":** Do not assume standard Win32 or C++ logic (e.g., `CreateWindow` parameters) unless explicitly shown in the decompilation. The game often does things in specific, non-standard ways.

## 2. The "Execution Trace" Workflow
We proceed algorithmically, following the execution path of the engine.

1.  **Trace & Identify:**
    *   Identify the exact point where execution stops, crashes, or requires logic (e.g., "The loop runs, but `handle_idle` is empty").
    *   Identify the **next immediate function** or **class** required to move the trace forward.

2.  **Define the Vessel (Headers):**
    *   Request the **Class Layout** (Size, VTable, Offsets).
    *   Create/Update the `.h` file.
    *   **Mandatory:** Include `static_assert` for `sizeof(Class)` and `offsetof(Member)` at the end of every `.h` file to verify alignment against the Source of Truth.

3.  **Request the Logic:**
    *   Request the decompiled pseudo-code for the specific functions identified in Step 1.

4.  **Transpile & Stub:**
    *   Convert decompiled code to C++.
    *   **Aggressive Stubbing:** If a function calls a complex dependency (e.g., `SoundSystem::Update`), **STUB IT** immediately. Do not attempt to implement the dependency in the same pass.

5.  **Verify:**
    *   Compile and run. If it works, repeat Step 1.

## 3. Coding Standards

### Stubs & TODOs
*   **Mandatory Tag:** ANY code that is incomplete, skipped, simplified, or stubbed **MUST** be marked with a `// TODO:` comment explaining what is missing.
    *   *Bad:* `return 0;`
    *   *Good:* `return 0; // TODO: Implement TRegistry logic`
*   **Stub Return Values:** Stubs should return values that allow the *caller* to proceed successfully (usually `1` for success, or a valid pointer).

### Debugging
*   **`_DEBUG` Macro:** All print statements, logging, or temporary verification code must be wrapped in `#ifdef _DEBUG`.
*   **No Logic Changes:** Debug code must not alter the control flow of the original game logic.

## 4. Output Format
To facilitate easy implementation:

*   **Context is King:** Always state *which* file is being modified.
*   **Two Modes:**
    1.  **Full File:** If a file has significant changes or is new, output the **entire** file content so it can be copied/pasted (Ctrl+A, Ctrl+V).
    2.  **Diff Blocks:** If changes are localized, output *only* the modified function or block, including enough context (surrounding lines) to easily locate the insertion point.
*   **Do not split code:** Do not output half a function in one block and the rest in another.
