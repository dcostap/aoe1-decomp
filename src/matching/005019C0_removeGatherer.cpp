#ifndef TAITACMD_SHARED_CONTEXT
// VA: 005019C0 removeGatherer (192B)
// taitacmd.cpp
// Attempt log:
// - Baseline was the old incomplete stub; it did not model the gatherer table.
// - Reconstructed the binary-proven UnitData table at +0x51C and the natural
//   remove/compact operation from the matched addGatherer donor.
// - The first natural scan used do/while; VC5 peeled its first record and
//   emitted an extra load/branch family. A bounded while scan restored the
//   original unpeeled pointer walk and matched exactly.

extern "C" void __cdecl logCommonHistory(void* module, const char* text);

#ifndef TAITACMD_SHARED_CONTEXT
struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

class TribeTacticalAIModule {
public:
    char gap_000[0x51C];
    UnitData gatherers[50];
    int numberGatherersValue;

    int removeGatherer(int id);
};

#endif
int TribeTacticalAIModule::removeGatherer(int id)
{
    UnitData* pU;
    int* piVar2;
    int i;

    if (id == -1) {
        logCommonHistory(this, (const char*)0x00588AC8);
        return 0;
    }
    i = 0;
    pU = this->gatherers;
    while (i < 0x32) {
        if (pU->id == id) {
            piVar2 = &this->gatherers[i].data1;
            this->gatherers[i].id = -1;
            *piVar2 = -1;
            this->gatherers[i].data2 = -1;
            this->gatherers[i].data3 = -1;
            this->gatherers[i].target = -1;
            this->numberGatherersValue = this->numberGatherersValue + -1;
            for (; i < 0x31 && piVar2[5] != -1; piVar2 = piVar2 + 6) {
                ((UnitData*)(piVar2 - 1))->id = piVar2[5];
                *piVar2 = piVar2[6];
                piVar2[1] = piVar2[7];
                piVar2[2] = piVar2[8];
                piVar2[3] = piVar2[9];
                piVar2[5] = -1;
                piVar2[6] = -1;
                piVar2[7] = -1;
                piVar2[8] = -1;
                piVar2[9] = -1;
                i = i + 1;
            }
            return 1;
        }
        i = i + 1;
        pU = pU + 1;
    }
    return 0;
}
#else
int TribeTacticalAIModule::removeGatherer(int id) {
    return 0;
}
#endif
