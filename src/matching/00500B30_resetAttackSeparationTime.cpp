#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00500B30 TribeTacticalAIModule::resetAttackSeparationTime()
// PDB source: taitacmd.cpp lines 11567-11583 (99 bytes, 32 asm lines)
// Default flags
// Exact match.
// Attempts:
// - Natural local `int sep = sn[0x66]` with split arithmetic was behaviorally correct, but VC5 kept sep in EDI
//   from the initial load (`mov edi,[esi+32C]; test edi,edi`) instead of original `mov eax,...; test eax,eax;`
//   then delayed `mov edi,eax` until immediately before the debug_rand call.
// - Splitting remainder/half/base locals did not change the early EDI allocation and also reordered the base/half
//   arithmetic around `ecx` differently.
// - Testing the member directly then assigning sep inside the true arm still collapsed to the same EDI-local family.
// - Volatile sn improved the later half/base arithmetic but still forced early EDI and shifted the branch target.
// - /Ob0 and /Og did not affect this register-allocation family; no custom flags are needed.
// - Winning shape: do not name `sep`; use direct member rereads in the expression. VC5 still saves the tested EAX
//   into EDI just before the call, but avoids making the variable a long-lived EDI local from the first load.

extern int __cdecl debug_rand(char* file, int line);

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    char gap_000[0x194];
    int sn[0x67];                    // +0x194, sn[0x2E] at +0x24C, sn[0x66] at +0x32C
    char gap_330[0x0D24 - 0x330];
    int randomizedAttackSeparationTime; // +0xD24

    void resetAttackSeparationTime();
};

#endif
void TribeTacticalAIModule::resetAttackSeparationTime() {
    if (this->sn[0x66] > 0) {
        this->randomizedAttackSeparationTime =
            debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taitacmd.cpp", 0x2D35) % this->sn[0x66] +
            (this->sn[0x2E] - this->sn[0x66] / 2);
    } else {
        this->randomizedAttackSeparationTime = this->sn[0x2E];
    }

    if (this->randomizedAttackSeparationTime < 0) {
        this->randomizedAttackSeparationTime = 0;
    }
}
#else
void TribeTacticalAIModule::resetAttackSeparationTime() {}
#endif
