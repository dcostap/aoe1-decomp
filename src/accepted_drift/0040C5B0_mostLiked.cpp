// 0040C5B0 DiplomacyAIModule::mostLiked
// Source: aidipmod.cpp lines 338-362
// Size: 169 bytes
//
// Attempt log:
// Probe 1: 144/169B — structural probe, pointer chain + virtual dispatch basin
// Probe 2: switched to flat raw-offset class and binary-observed delta/index loop.
// Probe 3: named player/world locals fixed initial and bottom reload topology.
// Probe 4: named object temp restored separate object load and reduced to 2-byte drift.
// Probes 5-8: reordered/renamed base/delta/like expressions and tried indexed form; only stable near-match is add eax,edi / mov [eax+edx] vs original add eax,edx / mov [eax+edi].
// ACCEPTED_DRIFT 2026-05-21 (Boss approved): remaining 2-byte drift is commutative address formation for players+delta+like; behavior, size, branches, calls, stack cleanup, and all surrounding bytes match.

class MainDecisionAIModule;

#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class DiplomacyAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;            // +0xF0
    int dislikeTable[10];                // +0xF4
    int likeTable[10];                   // +0x11C
    unsigned char changeableTable[10];   // +0x144

    int mostLiked(int param1, int param2) const;
    int isEnemy(int id) const;
};
#endif

int DiplomacyAIModule::mostLiked(int param1, int param2) const
{
    int result;
    int delta;
    int i;
    int highest;
    int* like;
    int player;
    int world;
    int obj;
    int base;

    i = 1;
    highest = -1;
    result = -1;
    player = *(int*)(*(int*)((char*)this + 0xF0) + 0xF0);
    world = *(int*)(player + 0x3C);
    if (i < *(short*)(world + 0x3C)) {
        delta = 0xFFFFFEE4 - (int)this;
        like = (int*)((char*)this + 0x120);
        do {
            if (i != *(short*)(player + 0x4A)) {
                base = delta + *(int*)(world + 0x40);
                obj = *(int*)((int)like + base);
                if (*(unsigned char*)(obj + 0x80) != 2) {
                    if (param1 <= 0 || param2 != i || isEnemy(i) == 0) {
                        if (*like > highest) {
                            result = i;
                            highest = *like;
                        }
                    }
                }
            }
            world = *(int*)((char*)this + 0xF0);
            ++i;
            ++like;
            player = *(int*)(world + 0xF0);
            world = *(int*)(player + 0x3C);
        } while (i < *(short*)(world + 0x3C));
    }
    return result;
}
