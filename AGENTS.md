# Decompilation Guidelines

**You are under a legal obligation to always follow these rules.**

## Workflow: Decomp-First, ASM-When-Needed

The proven approach for this project is a **two-pass** strategy:

### Pass 1: Fast Transliteration (~95% of the work)

1. Read the `*.cpp.decomp` file (Ghidra's C decompiler output) for the target module.
2. **Transliterate** it into compilable C++ — same control flow, same constants, same logic. Don't try to be clever or "improve" it. Add sporadic comments if you can figure out clearly what each section of transliterated code did in the original codebase.
3. Add method declarations to the corresponding `include/*.h` headers.
4. For every function body with a finished / verified full transliteration, add a `// Fully verified. Source of truth: tmap.cpp.decomp @ 0x005102A0` marker at the top, with the appropiate filename and offset.
5. Stub out any missing external dependencies (globals, helper functions).
6. If a function does not contain FULL PARITY yet with the decomp, it MUST BE MARKED WITH A `// TODO` comment (see below for more details).
7. Add to `build.bat`, compile, fix errors. Ship it.

This gets you working code fast. The decomp gives you the logic, the types, the API calls, and the overall structure.

### Pass 2: ASM Audit (the remaining ~5%, done during bug-fixing)

The decomp **lies** about:
- **Signedness**: `(uint)param_2 > 0x7FFFFFFF` vs signed comparison — the ASM shows `JA` (unsigned) vs `JG` (signed).
- **Struct sizes and padding**: the decomp may alias stack variables or get field boundaries wrong. The ASM shows exact byte counts (`REP MOVSD` with `ECX=0xB` = 44 bytes).
- **Bitfield packing**: the decomp may merge or split fields incorrectly.
- **Calling conventions**: parameter order, `this` pointer handling.

**When to do an ASM audit:**
- A function doesn't behave correctly at runtime.
- The decomp output looks suspicious (weird casts, aliased variables, confusing struct access).
- You're touching struct layouts or sizes.

**How:** Open the `*.cpp.asm`, find the function by offset, and compare instruction-by-instruction against your C++. Focus on comparisons, memory copies, struct offsets, and branch conditions.

### Crash Triage Protocol

1. Reproduce the crash and inspect `dist/decomp_debug.log`.
2. Add narrow `CUSTOM_DEBUG_LOG` checkpoints around the suspected call chain.
3. Isolate the exact failing function/call boundary before changing behavior.
4. Apply the smallest parity fix, rebuild, re-run, confirm no regression.

### Stubs

Only add your custom stubs when strictly needed.
CRITICAL: ALL STUBS MUST INCLUDE A `// TODO: STUB`, and optionally a brief explanation of why the stub was needed
Some legimitimate reasons for stubs:
- The function is called by the decomp but not critical for the current implementation.
- The function is complex and you want to defer it until you have more context.

No other reasons, really. Try to keep custom stubs to a minimum.

ALWAYS REMEMBER: Any non-parity code path (e.g., best-effort logic, debug bypass, disabled branch, fallback) IS FORBIDDEN UNLESS IT'S CLEARLY marked WITH A `// TODO`

## Sources of Truth

- `*.cpp.asm` and `*.cpp.decomp`, exported from Ghidra by reading the original .EXE and its PDB. These are **immutable references**. Never edit them.
- `include/*.h` headers are pre-exported from Ghidra, and define **memory layout** (members) and **vtable layout** (virtuals).
- `all_types_ground_truth.h` is a read-only dump of the all the type information exported from Ghidra.
- You may edit `*.h` files, as the pre-exported code here may be imperfect or incorrect, but always keep all size/offset/`static_assert(sizeof(...))` checks intact.

## EVERYTHING SHOULD BE THERE
If you can't seem to find the source of truth for a given function, piece of logic, type, etc, YOU MUST ASK AND REPORT TO THE USER. DON'T GO OFF ON USELESS TANGENTS. EVERY SINGLE LINE OF CODE SHOULD BE PRESENT!!! IF THAT'S NOT THE CASE, IT'S A FATAL MISTAKE BY THE USER, AND YOU MUST REPORT BACK!

## Includes (keep it simple)

### In headers (`.h`)

* You **must include** a type's header if you inherit from it or store it **by value**.
* Use forward declarations for pointer/reference members (`X*`, `X&`) when possible.

### In source (`.cpp`)

* Include your own header first.
* Add other includes only as needed.

Avoid pulling platform headers into headers if you can.

## Header Modification Rules

The dumped headers (`include/*.h`) often lack method declarations and constructors.

### IMMUTABLE (Do Not Touch)
* **Member Variables:** Never add, remove, or reorder. This breaks `sizeof` and offsets.
* **Virtual Functions:** Never reorder or remove. This breaks the vtable.
* **Inheritance:** Do not change the base class unless confirmed by the dump.

### MUTABLE (Add as needed)
* **Constructors / Destructors:** Add declarations as you implement them.
* **Non-Virtual Methods:** Add declarations for functions found in the decomp/ASM.
* **Static Methods:** Safe to add.
* **Inner Structs/Enums:** Define them if a member variable needs the type to compile.

**Rule of Thumb:** If it changes the **bytes in memory** (variables, vtable), don't touch it. If it's just **code linkage** (functions, constructors), add it.

## Constructor/Base Init Safety Rule

For derived transliterations, ensure base state is initialized correctly (especially required pointers/flags) before derived logic runs. If a base constructor path is not implemented yet, add a clearly marked temporary-safe equivalent and keep parity intent explicit.

## Globals (`globals.h` / `globals.cpp`)

* `globals.h`: `extern` declarations
* `globals.cpp`: one actual definition

Prefer pointer globals (less include pressure). File-local stuff stays `static` or in an anonymous namespace.

## Coding Style

Write straightforward, boring C++. It's fine to look like C with classes.

* No modern/clever features (heavy templates, fancy RAII, complex STL).
* Simple control flow, simple data, explicit local variables.
* Match the decomp's style — the goal is behavioral parity, not idiomatic code.

## Parity Completion Checklist (Per Function)

- Match decomp control flow/constants first, then verify suspicious parts in ASM.
- Confirm call signatures/virtual dispatch assumptions are correct.
- Validate expected side effects in the active runtime path (not just return values).
- Keep comments/TODOs precise where parity is intentionally deferred.

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

## Temporary Debug Instrumentation Lifecycle

Temporary debug logs/checkpoints are allowed during investigation, but keep them narrow and remove (or gate) them once the issue is validated. Retain only durable checkpoints that continue to add diagnostic value.

## Compiling & Output

Use the existing `.bat` script files in the root directory to build / compile the game.
Check `*.log` files for output logs of the last execution of the game.
Ask the user to run the game and provide feedback, ONLY IF IT'S ESSENTIAL FOR PROGRESS.

# Build & Assets

* **EXE Output**: `dist\empiresx.exe`
* **Game Assets**: All original game assets (DRS, DLLs, etc.) are included in `dist/`, as they appear in the release game. We only need to worry about generating the right EXE.
