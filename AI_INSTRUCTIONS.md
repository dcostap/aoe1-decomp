# Decompilation Guidelines (AI Agent)

These rules exist to keep progress steady, builds stable, and the original information preserved. Re-read this document occasionally; it’s easy to drift.

---

## Non-negotiables

* `*.cpp.asm` is **immutable reference**. Never edit it.
* `.h` files define **layout truth**. Keep size/offset/`static_assert(sizeof(...))` checks intact.
* Prefer **small changes** that unblock the current goal. Don’t refactor for style.

If you get stuck on a key decision or something feels impossible/unclear, **stop and ask the user** for guidance rather than guessing wildly.

---

## Goal-first workflow

When given an objective, work in this order:

1. **Build blockers**: missing types, missing includes, missing globals, missing declarations/definitions.
2. **Objective-critical functions**: code paths needed for the objective.
3. **Stubs** for required-but-not-critical functions.

Don’t try to “finish the module” just because you opened it.

---

## Stubs (allowed and expected)

Use stubs to keep moving when full implementation isn’t needed yet.

Rules:

* Keep the exact signature.
* Minimal/no side effects.
* Return safe defaults.

Stub TODO can be simple:

```cpp
// TODO: implement (see <module>.cpp.asm)
```

---

## Includes (keep it simple)

### In headers (`.h`)

Include only what you must:

* You **must include** a type’s header if you inherit from it or store it **by value**.
* Use forward declarations for pointer/reference members (`X*`, `X&`) when possible.

### In source (`.cpp`)

* Include your own header first.
* Add other includes only as needed.

Avoid pulling platform headers into headers if you can.

---

## Globals (`globals.h` / `globals.cpp`)

Keep shared globals centralized:

* `globals.h`: `extern` declarations
* `globals.cpp`: one actual definition

Prefer pointer globals (less include pressure). If something is truly used only in one `.cpp`, keep it file-local (`static` or anonymous namespace).

---

## Coding style: keep it “old C++ / C-like”

Write straightforward, boring C++:

* Avoid modern/clever features (templates-heavy helpers, fancy RAII patterns, complex STL use).
* Prefer simple control flow, simple data, explicit local variables.
* It’s fine to look like C with classes.

The goal is correctness and readability for reverse engineering, not idiomatic modern C++.

---

## The hard part: ASM → C++ behavior matching

Your job is to make the C++ **behave like the original**. Perfect translation is hard and mistakes are expected; review passes will happen later. Still, aim for closest behavior.

### Practical translation rules

* Prefer matching **effects** (reads/writes/calls/branches) over matching instruction patterns.
* Keep calling order and side effects consistent (especially around globals, virtual calls, memory writes).
* Be careful with:

  * signed vs unsigned math
  * overflow/wrap behavior
  * pointer aliasing and byte/word access
  * structure packing/layout assumptions
  * string handling and buffer sizes
  * error paths / early exits

### Document assumptions and doubts in the `.cpp`

Whenever you are unsure or you make a guess, leave notes right in the code near the relevant logic. This is required because later review runs depend on it.

Use simple comments like:

```cpp
// ASSUMPTION: ...
// DOUBT: ...
// NOTE: assembly suggests ..., but unclear because ...
```

If you don’t know which is correct, prefer:

* a stub (if acceptable for the current goal), or
* the simplest implementation with a clear DOUBT comment.

---

## Implementation loop

For each function you touch:

1. Read its listing in `*.cpp.asm`.
2. Implement or stub in the real `.cpp`.
3. Add only the includes/globals needed.
4. Build.
5. Fix compile errors first, then linker errors.
6. Keep notes on assumptions and uncertainties.

---

## Quick reminders

* Never edit `*.cpp.asm`.
* Keep layout asserts.
* Use stubs freely, but mark them.
* Write simple C-like C++.
* Match behavior, and **document every guess**.
* If blocked or uncertain on a key point: **ask the user**.
