// VA: 0052B080 T_Scenario::InitializePlayerValues
// PDB: tscenaro.cpp lines 260-277 (123 bytes, 40 asm lines)
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log (22 focused attempts, 0 variant labs):
//
// The function initializes per-player game values in a 16-iteration loop:
// - Zeros a 4-int block (players[n-1].tail + players[n].field0..field2)
// - Sets players[n].field0=200, field1=200, field2=150
// - Sets per-player PlType-relative fields: [0x1f]=0, [-1]=0, [0xf]=counter,
//   [-0x11]=4, [0xCB6]=0, [0xE0C]=0
// - Post-loop: *PlType = 1
//
// Best result (attempts 15, 19, 21): 73-80% positional diff, exact size 123 bytes.
// All attempts share a stable core of VC5 codegen differences:
//
// Issue 1 — Register ordering (push edi interleaved):
//   Original pushes all 5 registers upfront (51 53 55 56 57).
//   Rebuilt pushes esi, then does lea eax,[ecx+18CCh], then push edi.
//   Root cause: original uses edi=persistent zero + edx=counter + esi=block.
//   Rebuilt uses esi=persistent zero + edi=counter + edx=block (swap of
//   edi↔esi and edx↔edi). Cannot be forced from C source — VC5's internal
//   register allocator heuristic assigns the first xor to esi and second
//   to edi regardless of declaration order, type choice (int/long), or
//   init style (=0 vs separate decl+init).
//
// Issue 2 — Constant hoisting:
//   Original: `mov dword [ecx-14h],0C8h` (immediate 200, 7 bytes).
//   Rebuilt: `mov ebx,0C8h` (5B) + `mov [ecx-14h],ebx` (3B) per 200 store
//   (8+3=11B for two), plus `mov ebp,96h` (5B) + `mov [ecx-0Ch],ebp`
//   for 150. VC5's loop-invariant code motion always hoists repeated
//   constants into registers when used 2+ times. Using separate expressions
//   (decimal/hex, typed casts) does not prevent hoisting.
//
// Issue 3 — Block zero stores eliminated:
//   Original has `mov [ebp],ebx; mov [ebp+4],ebx; mov [ebp+8],ebx;
//   mov [ebp+0Ch],ebx` (4 zero stores via loop-local ebx, 2B each).
//   Rebuilt eliminates these because VC5 proves the stores are overwritten
//   by subsequent 200/150 stores (q[-5]=200 aliases block[1]=zero, etc.).
//   Using separate pre/post-increment pointer variables (block vs q) does
//   not prevent alias analysis — VC5 tracks the arithmetic chain
//   q = block+6, q[-5] = block[1].
//
// Issue 4 — Missing block-pointer copy:
//   Original has `mov ebp,esi` (copy esi to ebp for zero stores).
//   Rebuilt never creates this copy because no source variable represents
//   the "block for zeros" separately from "block for redundant zero".
//   No C++ source pattern forces VC5 to allocate a second register for the
//   same address.
//
// Issue 5 — Store reordering:
//   Original: block[0]=0 (1st), block[1..3]=0, p[0x1f]=0, block[0]=0 (redundant)
//   Rebuilt: block[1..3]=0, p[0x1f]=0, block[0]=0
//   VC5 removes the first dead block[0]=0 (overwritten by redundant block[0]=0)
//   and reorders the remaining stores.
//
// Not suitable for accepted_drift — the structural differences (register
// allocation, instruction encoding, store count, scheduling) are too broad
// and systematic, not localized equivalent drift.
//
// Left in scratch: 123-byte implementation that is behaviorally correct
// but differs in register allocation and instruction scheduling. The
// VC5 codegen barriers appear to be intrinsic to the compiler's register
// allocator and loop-invariant optimization heuristics.
// Retry 2026-05-19 Boss pass: 10 additional variants (volatile block/all stores, char* byte-offset addressing, for 1..16 loop, memset block clear, volatile constants, explicit zero local, short counter, !=16 loop condition). Best new try was char* offset form at 73.1707% positional but still broad register/scheduling mismatch; restored prior behaviorally-correct scratch.
// Retry 2026-05-20 Boss pass: revalidated current scratch baseline (123B, 87.8049% positional/edit, first mismatch 4). Tried /O1, /O2 without /Oy, /Og, /Oa, /Ox, /Gs, /Ob0; tried volatile block zero stores, explicit zero local, constants inside loop, char* byte-offset source, for 1..16, register locals, goto loop, and while-top loop. /Oa moved only slightly (86.18% positional), volatile/goto/for worsened, and the rest were identical to baseline or noncompetitive. No exact or accepted-drift-quality result; broad register allocation, constant hoisting, dead-store elimination, and loop scheduling remain.
// Retry 2026-05-21 Boss pass: revalidated baseline. Tried volatile int pointers, volatile store casts, char-base volatile stores, indexed for 1..16, count-down loop, zero-first local, volatile zero local, register zero/i locals, saved-first, this alias, zero+char-base, inside-loop constant locals, q-before-p order, and zero+i-after-pointers. Best current kept source is zero-first (123B, 81.3008% positional, first mismatch 12), which improves register/push scheduling slightly but still hits broad constant-hoist/dead-store/register-allocation drift. Still not accepted_drift.
// Retry 2026-05-24 assigned pass: 11 more probes. Literal-zero/no-zero-local and explicit goto/preinc loop stayed identical to current best. Volatile block stores worsened to 91.0569% and first mismatch 4. Declaring pointer locals before zero/counter worsened to 87.8049% first mismatch 4. Fully direct indexed this+offset form worsened badly (95.122%, first mismatch 1). Flag probes /Og-, /Oi-, /Ot, /Od /Oy either stayed current best or produced wrong broad families; /Os and /O1 did not produce a useful compile/result under this setup. Still no accepted_drift: broad loop register allocation, dead-store elimination, constant hoisting, and scheduling differ throughout the body.
// Retry 2026-05-26 Boss pass: revalidated old zero-first source (123B, 81.3008% positional, first mismatch 12). Tried 15 variants: all-volatile stores, volatile zero-only, raw this-offset volatile zeros, for/preinc, declaration-order split locals, pointer/counter order, unsigned long counter, memset block clear, separated constant expressions, while(1)/break, volatile saved pointer, explicit count temp, moving increment around memset, p-before-q increment, and per-store 200 locals. Best new source uses natural `memset(block,0,16)` for the four zero stores; it keeps correct prologue registers through the zero block and improves to 78 positional bytes / 63.4146% and edit diff 30 / 24.3902%, but still has non-local drift: saved-pointer stack store is scheduled after `add ecx`, increment/add order differs, VC5 hoists the repeated 200 into ESI, and tail offsets shift. GIVEUP; not accepted_drift because remaining differences are broad scheduling/constant-hoist topology, not localized benign drift.

// Retry 2026-08-02 LunaM52B080 (10 meaningful probes, no variant lab):
// ran the required dossier, donor ranking, and ABI queries, then modeled the
// proven Player_Start_Info layout (Food at +0x1998) and _padding_ at +0x18CC.
// The closest source uses typed member addresses plus memset(block,0,16),
// declaration order `p; saved=p; q`, and yields 123 bytes / 23 positional
// differences (18.6992%), 85.37% shape, 108 equal bytes, first mismatch +0x20.
// This improves the old best substantially and exactly matches the prologue,
// stack home, zero stores, tail, and all memory offsets after the induction
// setup. Reordering saved before q fixes the +0x0F scheduling mismatch.
// Prefix/postfix counter and p/q update variants are codegen duplicates; typed
// block aliases regress q-base scheduling. Volatile destination casts are also
// a duplicate and do not prevent the VC5 constant hoist. Remaining drift is
// the induction order (`add eax,4` / `add ecx,10h` / `inc edx` versus original
// `inc edx` / `add ecx,10h` / `add eax,4`) and repeated-200 hoisting (`mov esi`
// versus two immediate stores). No exact or accepted-drift promotion.

#include <string.h>

struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

class T_Scenario {
public:
    char gap_00[0x18CC];
    int _padding_[0x31];
    Player_Start_Info player_info[16];
    char gap_1A90[0x3218];

    void InitializePlayerValues();
};

void T_Scenario::InitializePlayerValues()
{
    int zero = 0;
    int i = 0;
    int* p = this->_padding_;
    int* saved = p;
    int* q = &this->player_info[0].Food;

    do {
        int* block = q - 2;
        p++;
        ++i;
        q += 4;

        memset(block, 0, 16);

        p[0x1f] = zero;
        block[0] = zero;

        q[-5] = 200;
        q[-4] = 200;
        q[-3] = 150;

        p[-1] = zero;
        p[0x0f] = i;
        p[-0x11] = 4;
        p[0xCB6] = zero;
        p[0xE0C] = zero;
    } while (i < 16);

    *saved = 1;
}
