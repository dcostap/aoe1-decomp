# `DString::numWords` (`00446E00`) address-generation near-match report

## Status

- **Function:** `DString::numWords(void)`
- **VA:** `00446E00`
- **Source file:** `dstring.cpp`
- **Resolved file:** `src/matching/00446E00_numWords.cpp`
- **Build context:** default `/O2`
- **Current state:** exact match
- **Winning minimal context:** `#include <stdlib.h>` and nothing more

## Resolution

A minimal donor-style `#include <stdlib.h>` was enough to flip both `isspace` byte loads
from the rebuilt `[ptr+index]` SIB family to the original `[index+ptr]` encoding.
The earlier source body was already in the right basin; the remaining difference was
translation-unit header context, not algorithm or `/GX`.

---

## Executive summary

This function is very close. The overall algorithm, cache-test family, loop structure, branch layout, and call placement are already in the right basin.

The remaining mismatch is at the two byte loads used to form the `isspace` argument.

### Original

```asm
00446E40  8b16              mov edx,[esi]
00446E42  0fbe0417          movsx eax,byte [edi+edx]
...
00446E61  8b0e              mov ecx,[esi]
00446E63  0fbe140f          movsx edx,byte [edi+ecx]
```

### Current rebuild

```asm
00446E40  8b16              mov edx,[esi]
00446E42  0fbe043a          movsx eax,byte [edx+edi]
...
00446E61  8b0e              mov ecx,[esi]
00446E63  0fbe1439          movsx edx,byte [ecx+edi]
```

These are semantically equivalent, but they are **not** the same bytes.

This is not just textual pretty-printing drift. The encodings differ in which register is tagged as the **base** and which as the **index** in the x86 SIB byte.

---

## Why this is different from the `/GX` / destructor-context cases

The earlier `DKeyString` / `asUppercase` / `asLowercase` cluster was a **front-end / TU-context / EH-object-lifetime** problem. There, the right body matched only when VC5 saw the right visible class surface plus `/GX`.

`numWords` is different.

Here, the function is already in the right codegen family except for the memory-operand addressing choice at two `movsx` loads. That points much more strongly to:

- backend register-role selection
- induction-variable classification
- pointer-vs-integer address lowering
- old VC5 allocator / address-generation heuristics

rather than:

- wrong algorithm
- wrong calling convention
- missing EH context
- missing include / header context

---

## Meaning of the mismatch

The remaining mismatch is:

- original: `movsx ..., byte [edi+edx]`
- current:  `movsx ..., byte [edx+edi]`

and similarly:

- original: `movsx ..., byte [edi+ecx]`
- current:  `movsx ..., byte [ecx+edi]`

On x86, those are different SIB encodings.

### Encodings

- `0f be 04 17` / `0f be 14 0f`
  - `EDI` is encoded as the **base**
  - `EDX` or `ECX` is encoded as the **index`
- `0f be 04 3a` / `0f be 14 39`
  - `EDX` or `ECX` is encoded as the **base**
  - `EDI` is encoded as the **index**

So the problem is not expression meaning anymore. The thing that still needs to change is:

> which live register VC5 decides is the memory operand's **base** and which is the **index**.

---

## Current working source

File: `src/scratch/00446E00_numWords.cpp`

```cpp
// tried the straightforward cached-word-count loop first; first mismatch was early at the initial cache test and branch shape
// kept the cached local and goto-shaped loop; remaining mismatch is now the byte-load addressing form at the two `isspace` calls
// tried `*(this->stringValue + index)`, `*(index + this->stringValue)`, per-use `char* text` temps, and a named `ch` temp for the `isspace` argument; all collapsed to the same `[base+index]` SIB form and no mismatch moved
extern "C" int __cdecl isspace(int c);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    int numWords(void);
};

int DString::numWords(void) {
    int cached;
    int index;
    int inWord;

    cached = this->numWordsValue;
    if (cached == -1) {
        cached = this->lengthValue;
        if (cached == 0) {
            return cached;
        }

        if (this->stringValue[0] == ' ') {
            this->numWordsValue = 0;
            inWord = 0;
        } else {
            this->numWordsValue = 1;
            inWord = 1;
        }

        index = 0;
        if (cached > 0) {
            do {
                if (!inWord) {
                    if (isspace((int)index[this->stringValue])) {
                        goto still_in_gap;
                    }
                    cached = this->numWordsValue;
                    inWord = 1;
                    cached = cached + 1;
                    this->numWordsValue = cached;
                    goto next_index;
                }

still_in_gap:
                if (isspace((int)index[this->stringValue])) {
                    inWord = 0;
                }

next_index:
                cached = this->lengthValue;
                index = index + 1;
            } while (index < cached);
        }

        cached = this->numWordsValue;
    }

    return cached;
}
```

---

## Original reference context

From `inventory/functions/0044/00446E00_numWords.txt`:

- **Size:** 133 bytes
- **Calling convention:** `__thiscall`
- **PDB lines:** `dstring.cpp:228-254`

### Original asm

```asm
00446E00  53                push ebx
00446E01  56                push esi
00446E02  8bf1              mov esi,ecx
00446E04  57                push edi
00446E05  8b4608            mov eax,[esi+8]
00446E08  83f8ff            cmp eax,0FFFFFFFFh
00446E0B  7574              jne short 00446E81h
00446E0D  8b4604            mov eax,[esi+4]
00446E10  85c0              test eax,eax
00446E12  7504              jne short 00446E18h
00446E14  5f                pop edi
00446E15  5e                pop esi
00446E16  5b                pop ebx
00446E17  c3                ret
00446E18  8b0e              mov ecx,[esi]
00446E1A  803920            cmp byte [ecx],20h
00446E1D  750b              jne short 00446E2Ah
00446E1F  c7460800000000    mov dword [esi+8],0
00446E26  33db              xor ebx,ebx
00446E28  eb0c              jmp short 00446E36h
00446E2A  c7460801000000    mov dword [esi+8],1
00446E31  bb01000000        mov ebx,1
00446E36  33ff              xor edi,edi
00446E38  85c0              test eax,eax
00446E3A  7e42              jle short 00446E7Eh
00446E3C  85db              test ebx,ebx
00446E3E  7521              jne short 00446E61h
00446E40  8b16              mov edx,[esi]
00446E42  0fbe0417          movsx eax,byte [edi+edx]
00446E46  50                push eax
00446E47  e8b4711000        call 0054E000h
00446E4C  83c404            add esp,4
00446E4F  85c0              test eax,eax
00446E51  750e              jne short 00446E61h
00446E53  8b4608            mov eax,[esi+8]
00446E56  bb01000000        mov ebx,1
00446E5B  40                inc eax
00446E5C  894608            mov [esi+8],eax
00446E5F  eb15              jmp short 00446E76h
00446E61  8b0e              mov ecx,[esi]
00446E63  0fbe140f          movsx edx,byte [edi+ecx]
00446E67  52                push edx
00446E68  e893711000        call 0054E000h
00446E6D  83c404            add esp,4
00446E70  85c0              test eax,eax
00446E72  7402              je short 00446E76h
00446E74  33db              xor ebx,ebx
00446E76  8b4604            mov eax,[esi+4]
00446E79  47                inc edi
00446E7A  3bf8              cmp edi,eax
00446E7C  7cbe              jl short 00446E3Ch
00446E7E  8b4608            mov eax,[esi+8]
00446E81  5f                pop edi
00446E82  5e                pop esi
00446E83  5b                pop ebx
00446E84  c3                ret
```

### Ghidra decompiler excerpt

```cpp
int __thiscall DString::numWords(DString *this)
{
    int iVar1;
    int iVar2;
    bool bVar3;
   
    iVar1 = this->numWordsValue;
    if (iVar1 == -1) {
        iVar1 = this->lengthValue;
        if (iVar1 == 0) {
            return iVar1;
        }
        bVar3 = *this->stringValue != ' ';
        if (bVar3) {
            this->numWordsValue = 1;
        }
        else {
            this->numWordsValue = 0;
        }
        iVar2 = 0;
        if (0 < iVar1) {
            do {
                if (bVar3) {
LAB_00446e61:
                    iVar1 = isspace((int)this->stringValue[iVar2]);
                    if (iVar1 != 0) {
                        bVar3 = false;
                    }
                }
                else {
                    iVar1 = isspace((int)this->stringValue[iVar2]);
                    if (iVar1 != 0) goto LAB_00446e61;
                    bVar3 = true;
                    this->numWordsValue = this->numWordsValue + 1;
                }
                iVar2 = iVar2 + 1;
            } while (iVar2 < this->lengthValue);
        }
        iVar1 = this->numWordsValue;
    }
    return iVar1;
}
```

---

## Probe history and results

## Phase 1: structural / control-flow probes

The first straightforward source draft mismatched earlier in the function, around:

- the initial cache test
- branch placement
- loop shape

That was improved by:

- introducing a named cached local
- keeping the cached return value alive longer
- using a goto-shaped loop that better resembled the original branch layout

That moved the first mismatch much deeper into the function. This was real progress.

## Phase 2: `isspace` argument-expression probes

Once the mismatch localized to the `isspace` loads, these source spellings were tested:

### Probe A
```cpp
isspace((int)index[this->stringValue])
```

### Probe B
```cpp
isspace((int)*(this->stringValue + index))
```

### Probe C
```cpp
isspace((int)*(index + this->stringValue))
```

### Probe D
```cpp
char* text = this->stringValue;
isspace((int)text[index])
```

### Probe E
```cpp
char* text = this->stringValue;
isspace((int)*(text + index))
```

### Probe F
```cpp
char* text = this->stringValue;
int ch = (int)text[index];
isspace(ch)
```

## Result of all six probes

All six collapsed to the **same rebuilt encoding family**:

```asm
00446E42  0fbe043a          movsx eax,byte [edx+edi]
...
00446E63  0fbe1439          movsx edx,byte [ecx+edi]
```

No probe moved the mismatch deeper.
No probe moved it earlier.
No probe changed the remaining issue at all.

This is strong negative evidence that ordinary final-expression sugar is exhausted.

---

## Interpretation

The practical conclusion is:

> the front-end is probably reducing all of those expression spellings to the same internal form, and the remaining difference is being chosen by the backend.

The likely drivers now are:

- register liveness
- induction-variable classification
- pointer-plus-int vs integer-plus-integer lowering
- old VC5 backend heuristics for base/index role assignment

This is why the issue is now best described as **backend address-generation selection**, not logic.

---

## Follow-up probe execution results

After the first version of this report, the next targeted probes were actually run on the current near-match source. The result was negative but useful: **all of them collapsed to the same wrong addressing family** and left the first mismatch at the same load pair.

## Probes executed

### 1. Integer-domain address reconstruction

```cpp
if (isspace((int)*(signed char *)((unsigned)this->stringValue + index))) {
```

and

```cpp
if (isspace((int)*(signed char *)((unsigned)index + (unsigned)this->stringValue))) {
```

### 2. `register` on the loop index

```cpp
register int index;
```

### 3. Reference-based character load

```cpp
signed char& ch = ((signed char*)this->stringValue)[index];
if (isspace((int)ch)) {
```

### 4. Unsigned induction variable

```cpp
unsigned index;
```

with the loop compare kept behaviorally equivalent via:

```cpp
} while ((int)index < cached);
```

## Result of all four targeted follow-up probes

All four still produced the same rebuilt load family:

```asm
00446E42  0fbe043a          movsx eax,byte [edx+edi]
...
00446E63  0fbe1439          movsx edx,byte [ecx+edi]
```

instead of the original:

```asm
00446E42  0fbe0417          movsx eax,byte [edi+edx]
...
00446E63  0fbe140f          movsx edx,byte [edi+ecx]
```

The first mismatch stayed at the same place. None of the probes moved it deeper or changed the register-role family.

## Updated conclusion

This strengthens the earlier diagnosis:

> the remaining difference is very likely below the level of ordinary source-expression steering.

At this point, practical next work should assume a **backend register-role / address-generation heuristic** problem unless a new deliberate context or allocator-facing lever is identified.

---

## What should *not* be retried next

At this point, it is probably wasted motion to keep trying more variants of:

- `text[index]`
- `*(text + index)`
- `index[text]`
- named scalar `ch`
- small control-flow rewrites unrelated to the load site

Those have already been shown to collapse to the same backend choice.

---

## Practical stop rule

If the following do **not** flip the addressing family:

1. integer-domain pointer reconstruction probes
2. `register int index`
3. maybe one reference-based character-load probe
4. maybe one `unsigned index` probe

then the remaining mismatch is probably below the level of practical steering from normal C++ source.

In that case, the function should stay in scratch as a documented near-match / lesson case rather than being churned blindly.

---

## Reusable lesson

A concise repo-level lesson from this case:

> When a function reaches a near-match where only a byte-load SIB form differs (for example `[edi+edx]` vs `[edx+edi]`), treat that as a **register-role / addressing-family** problem, not a high-level algorithm problem. If several natural expression spellings collapse to the same bytes, stop final-expression churn and switch to deliberate register-allocation / address-lowering investigation.

---

## Best next single probe

If this function is resumed, the best next single probe is:

```cpp
if (isspace((int)*(signed char *)((unsigned)this->stringValue + index))) {
```

and its swapped-order twin:

```cpp
if (isspace((int)*(signed char *)((unsigned)index + (unsigned)this->stringValue))) {
```

Those are the clearest remaining source-level probes that specifically target the base/index encoding choice instead of simply rephrasing the same pointer expression.
