# Decompilation Guidelines

**You are under a legal obligation to always follow these rules:**
1. Define exact scope and target behavior deltas.
2. Identify immutable source-of-truth artifacts (`*.asm`, `*.decomp`, ground-truth headers) for every touched function/type.
3. Do a line-by-line parity audit from call entry to rendering/input side effects.
4. Prioritize fixes by impact: core dispatch/state/layout before cosmetic details.
5. Apply one small, source-backed change at a time; document assumptions/TODOs where parity is uncertain.
6. Rebuild and validate after each change; stop regressions before continuing.
7. Repeat audit-fix-validate cycles until observed behavior and source behavior match.

- `*.cpp.asm` and `*.cpp.decomp` are **immutable references**. Never edit them.
- You may edit `*.h` files, but keep all size/offset/`static_assert(sizeof(...))` checks intact.
- For a function or code you want to edit / refactor / fix / create, search for the source of truth of the function: find the corresponding `*.cpp.asm` and `*.cpp.decomp` files. Read both sources of truth carefully.
- For a type or struct you want to edit / refactor / fix / create, search for the source of truth of the type: find the corresponding `include/*.h` and `all_types_ground_truth.h` files. Read both sources of truth carefully.
- Create **Stubs** for functions that are required, but not yet critical for the goal at hand.
- Document your assumptions, doubts, and TODOs in the code you write. Be very explicit about what you are unsure of, or what pieces of code you are skipping for now. Use comments liberally to explain your thinking and assumptions.

Note: even tho this is Windows, `grep` is installed and in the PATH.

# Includes (keep it simple)

## In headers (`.h`)

Include only what you must:

* You **must include** a type’s header if you inherit from it or store it **by value**.
* Use forward declarations for pointer/reference members (`X*`, `X&`) when possible.

## In source (`.cpp`)

* Include your own header first.
* Add other includes only as needed.

Avoid pulling platform headers into headers if you can.

# Header Modification Rules (Reimplementation)

The dumped headers (`include/*.h`) define the **memory layout** (members) and **vtable layout** (virtuals), but they often lack standard methods and constructors.

### 🛑 IMMUTABLE (Do Not Touch)
*   **Member Variables:** Never add, remove, or reorder member variables. This breaks `sizeof` and offsets.
*   **Virtual Functions:** Never reorder or remove existing `virtual` functions. This breaks the vtable.
*   **Inheritance:** Do not change the base class unless confirmed by the dump.

### ✅ MUTABLE (Add as needed)
*   **Constructors:** You **must** add declarations for constructors (e.g., `RGE_Base_Game(args...);`) to the class.
*   **Non-Virtual Methods:** You **must** add declarations for regular functions found in the ASM calls (e.g., `void setVersion(float v);`).
*   **Static Methods:** Safe to add.
*   **Inner Structs/Enums:** If a member variable uses an undefined inner type (e.g., `RGE_Game_Options`), define it so the member variable compiles.

**Rule of Thumb:** If it changes the **bytes in memory** (variables, vtable), don't touch it. If it’s just **code linkage** (functions, constructors), add it to the header.

# Globals (`globals.h` / `globals.cpp`)

Keep shared globals centralized:

* `globals.h`: `extern` declarations
* `globals.cpp`: one actual definition

Prefer pointer globals (less include pressure). If something is truly used only in one `.cpp`, keep it file-local (`static` or anonymous namespace).

# Coding style: keep it “old C++ / C-like”

Write straightforward, boring C++:

* Avoid modern/clever features (templates-heavy helpers, fancy RAII patterns, complex STL use).
* Prefer simple control flow, simple data, explicit local variables.
* It’s fine to look like C with classes.

The goal is correctness and readability for reverse engineering, not idiomatic modern C++.

# The hard part: ASM → C++ behavior matching

Your job is to make the C++ **behave like the original**. Perfect translation is hard and mistakes are expected; review passes will happen later. Still, aim for closest behavior. Regularly review both the original `.cpp.asm` and `.cpp.decomp` to remember what the original code is actually doing.

# Custom Debug Infrastructure

We have a custom debug system for **runtime debugging** (NOT in the original game):

## Header: `include/custom_debug.h`

Toggle: `#define CUSTOM_DEBUG_ENABLED 1` (set to 0 to disable all debug code)

## Key Macros

```cpp
CUSTOM_DEBUG_INIT()           // Call once at startup 
CUSTOM_DEBUG_SHUTDOWN()       // Call at exit
CUSTOM_DEBUG_CHECKPOINT(name) // Mark execution phase
CUSTOM_DEBUG_LOG(msg)         // Log a message
CUSTOM_DEBUG_LOG_FMT(fmt,...) // Log with printf-style format
CUSTOM_DEBUG_ERROR(code,desc) // Log error with code
CUSTOM_DEBUG_WIN_ERROR(ctx)   // Capture Windows GetLastError()
CUSTOM_DEBUG_FUNC_ENTER()     // Log function entry (uses __FUNCTION__)
```

## Block Markers

Wrap custom debug code with these to clearly mark it as non-original:
```cpp
CUSTOM_DEBUG_BEGIN
    // debug code here
CUSTOM_DEBUG_END
```

## Compiling & Output

Use the `.bat` script files in the root directory to build / compile the game.
Check `*.log` files for output logs.
Ask the user to run the game and provide feedback, ONLY IF ESSENTIAL FOR PROGRESS.

# Build & Assets

* **EXE Output**: `dist\empiresx.exe`
* **Game Assets**: All original game assets (DRS, DLLs, etc.) are included in `dist/`, as they appear in the release game. We only need to worry about generating the right EXE.
