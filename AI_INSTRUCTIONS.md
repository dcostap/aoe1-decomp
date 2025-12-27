# AoE1 Decompilation Project: AI Agent Protocol

## 1. Project Overview
This project is a C++ reconstruction of the original *Age of Empires (1997)* source code. We use a Ghidra `.c` dump (`empiresx.exe.c`) derived from a beta build with PDB symbols. The goal is a simplified, functional replica that maintains strict memory compatibility with the original x86 32-bit architecture.

## 2. Technical Constraints (MANDATORY)
*   **Architecture:** Windows x86 (32-bit). Pointers are **4 bytes**.
*   **Memory Alignment:** Strict 1-byte packing for all game structures.
    *   Header files must use `#pragma pack(push, 1)` and `#pragma pack(pop)`.
*   **Memory Layout Parity:** Even if binary matching is not the goal, **Layout Matching** is mandatory.
    *   The engine uses raw memory serialization for multiplayer (sending/receiving structs as byte blobs).
    *   The engine uses hardcoded byte offsets in assembly (e.g., `*(char*)(this + 0x18)`) which the decompiler might not always resolve to named members.
    *   **How to follow:** Always include manual padding (e.g., `uchar _pad_18[2];`) to ensure every named member sits at the exact hex offset identified in the Ghidra dump. Use `static_assert(sizeof(T) == 0xSize, "...")` to verify.
*   **VTable Integrity:** Virtual function order is the only way the engine identifies methods. Do **not** reorder virtual functions.
*   **Inheritance:** 
    *   `RGE_...` classes: The base engine (Realtime Game Engine).
    *   `TRIBE_...` classes: The Age of Empires specific logic.
*   **Standard Types:** Use `uchar`, `ushort`, `ulong` (defined in `src/types.h`).
*   **Verification:** Use `build/verify.exe` to confirm layout parity. It is the source of truth for offsets. If `verify.exe` reports a mismatch, the C++ header must be adjusted regardless of what the Ghidra dump suggests.

## 3. Directory Structure
*   `src/rge/`: Engine-level headers/logic (Graphics, Sound, Base Classes).
*   `src/tribe/`: Game-level headers/logic (AoE Units, Civs, Game Class).
*   `src/types.h`: Common typedefs and Enums.
*   `src/main.cpp`: WinMain entry point.

## 4. Decompilation Workflow
When tasked with implementing a class or function:

1.  **Search the `.c` Dump:** Locate the class by name (e.g., `THelpDialog`).
2.  **Determine Inheritance:** Identify what the class calls in its constructor (e.g., if `TRIBE_Game` calls `RGE_Base_Game`, it inherits from it).
3.  **Map the VTable:** Look for `_vftable_` assignments or virtual calls (e.g., `(**(code **)var->_padding_)(1)`).
4.  **Identify Members:** Look at constructor assignments (`this->field_0x... = 0`) to determine member offsets.
5.  **Reconstruct C++:** 
    *   Convert `__thiscall` functions with `param_1` as `this` back into standard C++ member functions.
    *   Convert `scalar deleting destructors` into standard C++ destructors.
6.  **Annotate Addresses:** Every function **must** include a comment with its origin hex address (find this in Ghidra or via `LAB_...` labels in the dump).

## 5. Coding Standards

### Debug Logging & Divergence
*   **Marker for Divergence:** Use `#ifdef _DEBUG` to wrap any code that is **not** faithful to the original source (e.g., debug logging, console attachment, GDI test renders, or convenience hacks). This makes it clear where the reconstruction diverges from the original logic.
*   Redirect `stdout` and `stderr` to `build/debug.log` in `main.cpp`.
*   Use `printf` for logging. Avoid `MessageBox` for initialization success; use the console/log file instead.
*   Keep log frequency reasonable (e.g., log every 1000th iteration for high-frequency loops).

### Function Headers
```cpp
// Address: 0x004549e0
TRIBE_Game::TRIBE_Game(RGE_Prog_Info* info, int setup) : RGE_Base_Game(info, setup) {
    // Logic...
}
```

### Struct/Class Layout
Always include offsets to ensure memory alignment.
```cpp
#pragma pack(push, 1)
class TRIBE_Game : public RGE_Base_Game {
public:
    /* 0x0a24 */ struct MouseClickInfo *MouseRightClickTable;
    /* 0x0a28 */ int MouseRightClickTableSize;
    // ...
};
#pragma pack(pop)
```

### Stubs
If a function calls a method not yet implemented, create a stub:
```cpp
void TRIBE_Game::update() {
    this->update_input(); // STUB: implementation at 0x004XXXXX
}
```

## 6. Translation "Rosetta Stone"
| Ghidra Decompilation Pattern | C++ Translation |
| :--- | :--- |
| `this->_padding_ = (int)&_vftable_;` | (Automatic/Ignore) |
| `(**(code **)var->_padding_)(1);` | `delete var;` (Virtual Destructor) |
| `pcVar1 = TPanel::get_string((TPanel *)this, id);` | `char* s = this->get_string(id);` |
| `operator_new(size);` | `new ClassName();` |
| `operator_delete(ptr);` | `delete ptr;` |

## 7. Instructions for Current Task
*   Maintain the split between `.h` (definition) and `.cpp` (implementation).
*   Use `static_assert(sizeof(ClassName) == 0xXXXX, "Size mismatch");` at the bottom of header files to verify structure sizes against the `operator_new` calls found in the dump.
*   If you find global variables (starting with `DAT_`), suggest placing them in a `Globals.h/cpp` file or as static members.
*   **Build Artifacts:** All `.obj`, `.exe`, `.pdb`, and `.log` files must reside in the `build/` directory. The project root must remain clean (source and data only).
*   **Resource Loading:** When implementing file loading (DRS, DLLs, .dat), always include a fallback to the `data2/` directory to support modern installation layouts.

***

**AI Agent:** Acknowledge this guide. When providing code, specify which file it belongs to and ensure it adheres to the memory offsets provided in the symbols.