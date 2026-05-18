// VA: 0046B680 PathingSystem::decrementObstruction(int, int)
// PDB source: pathsys.cpp lines 658-668 (82 bytes, 28 asm lines)
// Default flags
//
// CURRENT BEST APPROACH (Attempt 17+/adjusted-this family):
// Using (PathingSystem*)((char*)this + x * 255) to force x-first evaluation and
// add-to-this computation. Body and epilogue are byte-exact from mov bl onwards.
// Remaining diff is purely prologue register allocation (23 bytes, 28% positional).
//
// BLOCKER: VC5 register allocation basin. The adjusted-this approach forces x-first
// loading and the correct add-to-this computation pattern, but VC5 puts x in EDX
// (not EAX) and x*255 in EAX (not ESI), adds this+x*255 in EAX (not this+=x*255 in ECX),
// loads y after pushes (not before), and puts y>>2 in ECX (not EAX). These are all
// VC5 internal register allocation decisions that cannot be changed through source
// shape variations in any form tried across this and prior passes (30+ variants total).
//
// Attempt log:
// - Attempts 1-14+: various source shapes (row pointers, lane locals, 2D casts,
//   early returns, extern qualifiers, parameter mutation, volatile, char* arithmetic,
//   expression factoring). Best prior: raw adjusted-this gave y-first/EDI body-family.
// - Attempt 15: 2D array cast -> x loads second but EBX in prologue -> 75% diff
// - Attempt 16: 2D cast + int lane -> x loads first but EBX in body -> 74% diff
// - Attempt 17: (PathingSystem*)((char*)this + x*255) -> x loads first, 2-saved-regs,
//   body+epilogue exact -> 28% diff. BREAKTHROUGH pattern.
// - Attempt 18: ((char*&)this) += row -> rejected by VC5 (C2102)
// - Attempt 19: separate rowOffset local + adjusted-this -> same 28% family
// - Attempt 20: y>>2 and y&3 as locals before row -> back to 84% (y-first family)
// - Attempt 21: &obstructionValue[0] + x*255 -> 80-byte function, y-first
// - Attempt 22: volatile int x -> no change from 28% family
// - Attempt 23: single-expression no locals -> back to 78% (y-first/EDI family)
// - Attempt 24: full char* arithmetic single expr -> 78% (y-first/EDI family)
// - Attempt 25: char* base local -> same 28% family
// - Attempt 26: adjusted-this + int lane -> same 28% family with slight y-load variant
// - Attempt 27: x * 0xFF instead of x * 255 -> same 28% family
// - Attempt 28: this->obstructionValue + x*255 -> same 28% family
//
// Top-20 scratch retry pass:
// - Retry 1: baseline validated unchanged: exact size 82B, 23-byte prologue diff, body/epilogue exact.
// - Retry 2: introduced explicit xx/yy locals before rowThis; no codegen change from best 28% family.
// - Retry 3: assigned x = (x << 8) - x before adjusted-this; no codegen change from best 28% family.
// - Retry 4: changed x/y to unsigned temps and 255u multiply; kept same topology but changed y>>2 SAR to SHR, worse, rolled back.
// - Retry 5: /GX probe; no code/size change from best 28% family, removed flag.
// - Retry 6: /Od probe; produced EBP frame and broad 92.68% mismatch, removed flag.
// - Retry 7: reconsidered accepted_drift against current policy: all memory effects/calls/branches/body bytes are equivalent and only the address-setup prologue differs by register allocation/order.
// - Retry 8: compared original/rebuilt prologue manually; both compute row base this+x*255, lane y>>2, bit slot y&3, and then enter byte-exact mutation sequence.
// - Retry 9: no further source axis left from prior 30+ variants plus retry probes without inline asm; retained best adjusted-this source.
// - Retry 10: final validation remains exact size 82B, 23 positional diff bytes, body+epilogue exact from mov bl onward.
//
// ACCEPTED_DRIFT_PROPOSAL (retry mode): localized equivalent prologue register-allocation drift.
// The rebuilt and original differ only in setup registers/order for x, x*255, y>>2,
// y&3, and SIB base/index selection before the first byte load. From the first
// obstruction byte load through the mutation and epilogue, behavior is byte-equivalent
// except for commuted base/index encoding and relocation-masked array loads. No calls,
// memory writes, predicates, or stack cleanup differ. This is a reasonable low-risk
// accepted_drift candidate if Boss approves, despite the high percent caused by tiny size.
//
// Remaining prologue diff details (original vs rebuilt):
//   orig: mov eax,[esp+4]          rebuilt: mov edx,[esp+4]        ; x in EAX vs EDX
//   orig: mov edx,[esp+8]          (not present)                   ; y loaded before pushes
//   orig: push ebx                 rebuilt: push ebx
//   orig: push esi                 rebuilt: mov eax,edx            ; x copied to EAX
//   orig: mov esi,eax              rebuilt: push esi
//   orig: shl esi,8                rebuilt: shl eax,8              ; x*255 in ESI vs EAX
//   orig: sub esi,eax              rebuilt: sub eax,edx
//   orig: mov eax,edx              rebuilt: mov edx,[esp+10h]      ; y reload after pushes
//   orig: sar eax,2                rebuilt: add eax,ecx            ; this+row swapped operand
//   orig: add ecx,esi              rebuilt: mov ecx,edx            ; y>>2 in ECX vs EAX
//   orig: and edx,3                rebuilt: sar ecx,2
//   orig: mov bl,[eax+ecx+...]     rebuilt: and edx,3
//                                  rebuilt: mov bl,[ecx+eax+...]   ; SIB base/index swapped
// Then body and epilogue match byte-exact from here.
//
// ACCEPTED_DRIFT_APPROVED by Boss in top-20 retry mode: the remaining 23-byte
// diff is confined to equivalent prologue address setup/register allocation.
// Both versions compute the same row base, lane, bit slot, and array addresses;
// the byte mutation, predicate, memory write, epilogue, and stack cleanup match.

extern const unsigned char ObstructionValueShift[];
extern const unsigned char ObstructionValueMask[];

class PathingSystem {
public:
    char gap_00[0xCE624];
    unsigned char obstructionValue[];

    void decrementObstruction(int x, int y);
};

void PathingSystem::decrementObstruction(int x, int y) {
    PathingSystem* rowThis = (PathingSystem*)((char*)this + x * 255);
    unsigned char val = rowThis->obstructionValue[y >> 2];
    unsigned char field = (val >> ObstructionValueShift[y & 3]) & 3;
    if (field > 0) {
        rowThis->obstructionValue[y >> 2] = 
            (ObstructionValueMask[y & 3] & val) | ((field - 1) << ObstructionValueShift[y & 3]);
    }
}
