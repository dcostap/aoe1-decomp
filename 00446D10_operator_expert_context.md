# Expert-context prompt: `00446D10` `DString::operator[]`

You are reviewing a stubborn near-match in an Age of Empires 1 decompilation project that targets **exact VC5-era assembly parity**.

Please do **not** suggest inline asm or hacks. The goal is a **source-level hypothesis** for why this function still mismatches, plus a short prioritized probe plan.

## What I want from you

Please read the full context below and then provide:

1. your top hypotheses for why the current source keeps compiling to the wrong register/codegen shape,
2. which hypotheses are strongest vs weakest,
3. a short list of the **next 3-8 concrete source/TU experiments** worth trying,
4. for each proposed experiment, what assembly change you predict it might cause,
5. whether you think this is most likely:
   - a still-wrong source shape,
   - missing translation-unit context,
   - declaration/signature context,
   - local type/layout context,
   - or genuine historical toolchain/context drift.

If you think the function is probably behaviorally correct but codegen-stuck, say so explicitly.

---

## Repo / build context

- Project goal: **exact generated assembly parity** against the original EXE.
- Original EXE is the behavioral oracle.
- Working compiler is pinned historical VC5:
  - `C:\Program Files (x86)\DevStudio\VC\Bin\CL.EXE`
  - expected compiler version: `11.00.7022`
- Normal flags:

```text
/nologo /c /O2
```

- Build/check loop used here:

```text
python tools\check_function.py --va 00446D10
```

- Inline asm is forbidden.
- Per-function custom flags are allowed only as a last resort; one `/O1` probe was tried and rolled back after failure.

---

## Function under investigation

- VA: `00446D10`
- Name: `operator[]`
- Mangled symbol from packet: `??ADString@@QAEAADH@Z`
- Calling convention: `__thiscall`
- PDB source file: `dstring.cpp`
- PDB line span: `197-202`
- Packet says source-level signature is:

```cpp
char& DString::operator[](int)
```

---

## Original packet / original asm

From `inventory\functions\0044\00446D10_operator.txt`:

```text
00446D10-00446D2E
  00446D10  8b442404          mov eax,[esp+4]
  00446D14  56                push esi
  00446D15  85c0              test eax,eax
  00446D17  7c10              jl short 00446D29h
  00446D19  8b7104            mov esi,[ecx+4]
  00446D1C  8d5001            lea edx,[eax+1]
  00446D1F  3bf2              cmp esi,edx
  00446D21  7c06              jl short 00446D29h
  00446D23  0301              add eax,[ecx]
  00446D25  5e                pop esi
  00446D26  c20400            ret 4
  00446D29  8b01              mov eax,[ecx]
  00446D2B  5e                pop esi
  00446D2C  c20400            ret 4
```

Ghidra decompiler excerpt for the same packet:

```cpp
/* public: char & __thiscall DString::operator[](int) */

char * __thiscall DString::operator[](DString *this,int param_1)
{
  if ((-1 < param_1) && (param_1 + 1 <= this->lengthValue)) {
    return this->stringValue + param_1;
  }
  return this->stringValue;
}
```

Important machine-shape facts from the original:

- the stack arg is loaded into `eax` immediately,
- `test eax,eax`,
- `lea edx,[eax+1]`,
- compare uses `cmp esi,edx`,
- success path is the compact `add eax,[ecx]`,
- failure path returns `[ecx]`.

---

## Current scratch source file

Current file path:

```text
src\scratch\00446D10_operator.cpp
```

Current source after the latest dummy-TU probe:

```cpp
// tried char* return with if(index<0||length<index+1) and return base+index; still loaded arg into edx
// tried the exact `-1 < index && index + 1 <= length` spelling; still loaded arg into edx
// tried the inverted fail-return form; still loaded arg into edx
// tried a named base temp; still loaded arg into edx
// tried a named index temp; still loaded arg into edx
// tried split fail checks instead of one combined condition; no register change
// tried `register int index`; still loaded arg into edx
// tried char& return with `*this->stringValue` fallback; signature turned out wrong for this packet
// tried `return *(index + this->stringValue);`; still loaded arg into edx
// tried `return index[this->stringValue];`; still loaded arg into edx
// tried `return *(&this->stringValue[0]);` and `return *(&index[this->stringValue]);`; still loaded arg into edx
// tried a `char* result;` temp with if/else assignment; still loaded arg into edx
// tried a custom /O1 rsp; build shape broke on size mismatch, rolled back
// tried flipping the success return to `index + this->stringValue`; VC5 still loaded arg into edx
// tried the full char& rewrite in both declaration and definition; VC5 still loaded arg into edx
// Probe A tried: `*(index + this->stringValue)`; still loaded arg into edx
// Probe B tried: `*(this->stringValue + index)`; still loaded arg into edx
// tried a named length temp; VC5 still loaded the arg into edx and moved the length load earlier
// tried a named reference for the success return; VC5 still loaded arg into edx
// tried split fail checks again in the correct char& form; VC5 still loaded arg into edx
// tried explicit address-of on the indexed lvalue; still loaded arg into edx
// tried the array-ref spelling `index[this->stringValue]`; still loaded arg into edx
// tried a named reference to that array-ref result; still loaded arg into edx
// tried a named reference from explicit pointer-add; VC5 still loaded arg into edx
// tried a named bound temp `bound = index + 1`; VC5 still loaded arg into edx and split the fail path
// tried a delayed base temp after the checks; VC5 still loaded arg into edx
// tried a plain named result with `this->stringValue[index]`; VC5 still loaded arg into edx
// tried delayed base + named result; VC5 still loaded arg into edx
// tried a dummy TU with neighboring DString accessors in the same source file; still loaded arg into edx
class DString {
public:
    char* stringValue;
    int lengthValue;
    int gap_08;
    int indexValue;

    char& operator[](int index);
    operator char*() const;
    int length() const;
    int index() const;
};

char& DString::operator[](int index) {
    if (index < 0 || this->lengthValue < index + 1) {
        return *this->stringValue;
    }
    return this->stringValue[index];
}

DString::operator char*() const {
    return this->stringValue;
}

int DString::length() const {
    return this->lengthValue;
}

int DString::index() const {
    return this->indexValue;
}
```

Notes:

- The extra accessors were added only to test whether a more realistic local translation unit would change codegen.
- They did **not** help.
- This file is left in `scratch` because the latest probe was finished and the function remains non-exact.

---

## Latest rebuilt asm from the dummy-TU probe

```text
00446D10  8b542404          mov edx,[esp+4]
00446D14  56                push esi
00446D15  85d2              test edx,edx
00446D17  7c12              jl short 00446D2Bh
00446D19  8b7104            mov esi,[ecx+4]
00446D1C  8d4201            lea eax,[edx+1]
00446D1F  3bf0              cmp esi,eax
00446D21  7c08              jl short 00446D2Bh
00446D23  8b01              mov eax,[ecx]
00446D25  03c2              add eax,edx
00446D27  5e                pop esi
00446D28  c20400            ret 4
00446D2B  8b01              mov eax,[ecx]
00446D2D  5e                pop esi
00446D2E  c2                (bad)
```

The byte count still comes out correct (`31` bytes), but the first mismatch is still immediate.

Diff summary from the latest check:

```text
Function: operator[] (00446D10)
Original bytes: 31
Rebuilt bytes: 31
Relocations masked: 0
Result: MISMATCH
First mismatch offset: 1
Original window: 8b4424045685c07c10
Rebuilt  window: 8b5424045685d27c12
```

The persistent wrong shape is basically:

- arg loaded into `edx`, not `eax`,
- `test edx,edx`,
- `lea eax,[edx+1]`,
- `cmp esi,eax`,
- success path becomes `mov eax,[ecx] ; add eax,edx`

instead of the target shape:

- arg in `eax`,
- `test eax,eax`,
- `lea edx,[eax+1]`,
- `cmp esi,edx`,
- success path `add eax,[ecx]`

---

## Nearby `dstring.cpp` neighborhood that was inspected

These adjacent functions appear to be in the same original TU cluster:

### `00446D30` `DString::operator char*() const`

```text
00446D30  mov eax,[ecx]
00446D32  ret
```

### `00446D40` `DString::length() const`

```text
00446D40  mov eax,[ecx+4]
00446D43  ret
```

### `00446D50` `DString::index() const`

```text
00446D50  mov eax,[ecx+0Ch]
00446D53  ret
```

This suggests a nearby layout neighborhood like:

```cpp
+0x00 stringValue
+0x04 lengthValue
+0x0C indexValue
```

This inspection did **not** reveal an obvious helper that `operator[]` should have been calling. The original `operator[]` directly uses raw field loads, not calls to these accessors.

---

## Callsite context that may matter

From `DString::append` in `inventory\functions\0044\004471F0_append.txt`:

```cpp
pcVar4 = operator[](&param_1,iVar5 - iVar1);
pcVar2[iVar5] = *pcVar4;
```

So the callsite treats the result like an address in a register, which is consistent with the machine-level ABI behavior of a `char&` return.

---

## What has already been tried

These are the meaningful probes already attempted.

### Return-type / semantic-shape probes

- `char*` return form instead of `char&`
- full `char&` rewrite in both declaration and definition
- fallback expressed as `*this->stringValue`
- success return expressed as:
  - `this->stringValue[index]`
  - `*(index + this->stringValue)`
  - `*(this->stringValue + index)`
  - `index[this->stringValue]`
  - explicit address-of variants on indexed lvalues

### Condition-shape probes

- combined fail check:

```cpp
if (index < 0 || this->lengthValue < index + 1)
```

- exact decompiler-style success condition:

```cpp
if (-1 < index && index + 1 <= length)
```

- inverted fail-return form
- split fail checks instead of one combined condition
- split fail checks again after the correct `char&` rewrite
- named bound temp:

```cpp
int bound = index + 1;
```

### Temporary / expression-shape probes

- named base temp
- delayed base temp after the checks
- named index temp
- named length temp
- named `char* result` temp
- named `char& result` temp
- delayed base + named result

### Other probes

- `register int index`
- dummy TU with neighboring DString accessors in the same source file
- one custom `/O1` rsp experiment, which failed and was rolled back

The `/O1` attempt failed with:

```text
Configured function size 31 exceeds .text section size 27 for C:\Projects\my_decomps\aoe1_attempt3\build\obj\00446D10_operator.obj
```

---

## What seems to be ruled out so far

The following have not fixed the core issue:

1. basic source spelling changes in the return expression,
2. basic source spelling changes in the compare/bounds check,
3. introducing or removing named temporaries,
4. switching between obvious `char*` and `char&` source forms,
5. a tiny local dummy-TU cluster of nearby DString accessors.

So far, the mismatch looks **stable** and **front-loaded**: the compiler strongly prefers loading the stack arg into `edx` and keeping `eax` available for the address result.

---

## Current best internal guess before asking you

The current local belief is:

- behavior is probably already correct,
- the mismatch is probably register-allocation / codegen-shape drift,
- but it is still possible there is a subtle missing source/declaration/TU detail.

What is not known is **which subtle detail is still most plausible**.

---

## Specific questions for you

Please answer these as directly as you can:

1. Why might VC5 prefer the stable wrong shape here (`edx` for arg, `eax` reserved for result) even across many source spellings?
2. What source shape would most plausibly force the original shape (`eax` carries the arg from load through `add eax,[ecx]`)?
3. Is there a strong chance the original was actually compiled in a fuller `dstring.cpp` TU context that affects register allocation in a way this one-function build cannot reproduce?
4. Are there declaration-context details worth probing, such as constness, exact class body shape, or a fuller neighboring method set?
5. Do you think the original source was more likely closer to:
   - decompiler-style pointer return semantics,
   - true `char&` source with optimizer collapse,
   - or some less obvious source shape entirely?
6. If you had to spend only 3 more probes on this function, what would they be?

---

## Preferred answer style

Please respond with sections like:

- `Most likely explanation`
- `Why the current wrong shape is stable`
- `Top hypotheses ranked`
- `Concrete next probes`
- `What probably is not worth trying again`
- `Whether to keep digging or leave it in scratch`

Be opinionated. If you think this is likely a genuine codegen-stuck scratch hold, say so.
