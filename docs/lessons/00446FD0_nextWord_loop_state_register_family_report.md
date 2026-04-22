# `DString::nextWord` (`00446FD0`) loop-state / register-family lesson

## Status

- **Function:** `DString::nextWord(int updateIndex)`
- **VA:** `00446FD0`
- **Source file:** `dstring.cpp`
- **Resolved file:** `src/matching/00446FD0_nextWord.cpp`
- **Build context:** `/O2 /GX`
- **Current state:** exact match

## Resolution

The winning source shape was the simple **one running scan index plus one saved start index** form:

```cpp
DString DString::nextWord(int updateIndex) {
    int i;
    int start;

    i = this->indexValue;
    while ((isspace((int)this->stringValue[i]) != 0) && (i < this->lengthValue)) {
        i = i + 1;
    }
    start = i;
    while ((isspace((int)this->stringValue[i]) == 0) && (i < this->lengthValue)) {
        i = i + 1;
    }
    if (updateIndex != 0) {
        this->indexValue = i;
    }
    DString rStr = this->subString(start, i - start);
    return rStr;
}
```

That exact state topology mattered more than the decompiler-like three-local form.

## What was misleading

A decompiler-shaped reconstruction used three integer locals such as:

- one local for the first loop's index,
- one local for the second loop's index,
- one or two extra locals for `isspace` results.

That shape looked "explicit" and safe, but it was the wrong instinct for VC5.
Those extra locals were not just cosmetic names; they changed value lifetimes
and register pressure enough to kick the function into the wrong codegen family.

The practical mistake was starting from the decompiler's temporary structure
instead of first asking:

> **how would the original developers likely have written this by hand?**

For this function, the likely handwritten answer was the winning answer:

- one running scan index,
- one saved start index,
- no named `isspace` result temp,
- and a normal local-return-object tail.

The earlier three-local version was behaviorally right and size-correct, but VC5 kept landing in the wrong saved-register family:

- original wanted `this` in `EDI`
- original wanted the running scan index in `ESI`
- original saved the word start once into `EBP`
- the three-local rebuild instead tended to keep `this` in `ESI` and spill/reuse `EBP`/`EDI` differently

So this was **not** mainly a `/GX` problem, and it was **not** fixed by broader donor-style TU context alone.

## Why the winning shape worked

The original asm has the same conceptual structure as the winning source:

1. load the current scan index from `this->indexValue`
2. advance that same index through leading whitespace
3. save the current index once as the word start
4. keep advancing the same running index through the word
5. optionally write the final index back to `this->indexValue`
6. call `subString(start, i - start)` and return the local result object

That means the key source fact was not just “two loops exist”. The key fact was:

> **there is one long-lived running iterator, and the boundary between the loops is represented by a single saved copy of that iterator.**

VC5 appears to map that shape naturally into the original register family.

## Reusable rule

Default probe order for this class of function:

1. try the simplest natural human-written source family first,
2. keep only the state a real programmer would naturally preserve,
3. add decompiler-style temporaries only if the asm clearly forces them.

For old VC5 code, if the original asm for a two-phase scan function visibly does this:

- advances one register through a first loop,
- copies that register once at the phase boundary,
- then keeps advancing the original register through a second loop,

then prefer source with:

- **one running index local**, and
- **one saved boundary/start local**,

instead of decompiler-style source with separate per-loop indices and named `isspace`/predicate temporaries.

In short:

> **Match the original loop-state topology, not just the control-flow meaning.**

## Practical heuristic for future agents

When a small scan/helper function is size-correct and behaviorally correct but trapped in the wrong register-allocation basin:

1. identify the original long-lived iterator register,
2. identify whether the original saves that iterator once at a phase boundary,
3. rewrite the source to use exactly that model,
4. remove extra predicate/result temporaries before trying stranger context tricks,
5. prefer the natural handwritten source family before escalating into clever or decompiler-ish reshaping.

For this function, that simple reduction from a three-local decompiler shape to a two-local iterator-plus-start shape was the exact-match unlock.
