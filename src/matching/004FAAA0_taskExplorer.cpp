// 004FAAA0 TribeTacticalAIModule::taskExplorer (taitacmd.cpp:8897-8913)
// Attempt log:
// 1: Natural implementation with static add_unique helper emitted helper out-of-line; function only 336B.
// 2: Inline both array-add sequences and use the canonical player surface: size matches, but search loops use pointer-walk/test max; 81.60% positional, 30.47% edit.
// 3: While with max locals improves edit to 21.68 but adds duplicate count tests and function too long.
// 4: Copy loop do/while spelling produced no source change/no codegen change.
// 5: For-loop search spelling no codegen change.
// 6: int task player parameter + cast improved tail (edit 20.04%).
// 7: while(1) copy loops improved edit to 14.31 and copy loops match; function still +3/duplicate search tests.
// 8: Goto-shaped search loops worsened to 23.72 edit; rolled back to for-loop search.
// 9: Removed the decompiler-only positive-count guards from all bounded scans;
//    exact same-TU donors then recovered the target size and first scan blocks.
// 10: Reconstructed both lists as ManagedIntArray members at +104 and +d58;
//     output stayed unchanged and the layout is now canonical.
// 11: Fresh typed baseline retained the known 224-byte second-scan drift.
// 12: Explicitly assigned civilian.numberValue before both scans; no code change.
// 13: Guarded do-while repeated scan reduced the byte diff but changed block shape;
//     restored the natural indexed for-loop.
// 14: Separate firstCount and secondCount locals did not change emitted code.
// 15: A canonical civilians ManagedIntArray alias on the repeated scan produced MATCH.
// 16: Scoped that reference to the civilian scan and growth block; MATCH remained.
// Final: exact default-flags output, with canonical list ownership and typed dispatch.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char); virtual void do_resign(int);
    virtual void changeToHumanPlayer(); virtual void changeToComputerPlayer();
    virtual char* aiStatus(int); virtual int isEnemy(int); virtual int isAlly(int);
    virtual int isNeutral(int); virtual int isAllNeutral(); virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void sendUnitAIOrder(int player, int unit, int action, int a, int b,
                                 float x, float y, float f1, float f2,
                                 int c, int d, int e);
    char pad04[0x46];
    short id;
};
class TribeMainDecisionAIModule { public: char pad[0xf0]; RGE_Player* player; };

class TribeTacticalAIModule {
public:
    char pad000[0xf0];
    TribeMainDecisionAIModule* md; // +f0
    char pad0f4[0x104 - 0x0f4];
    ManagedIntArray civilians;  // +104
    char pad114[0xd58 - 0x114];
    ManagedIntArray unitsTaskedThisUpdate; // +d58

    int taskExplorer(int unit, float x, float y, int flag);
    int removeGatherer(int unit);
};

#endif
int TribeTacticalAIModule::taskExplorer(int unit, float x, float y, int flag)
{
    int i = 0;
    int count = this->unitsTaskedThisUpdate.numberValue;
    for (; i < count; i++) {
        if (i >= this->unitsTaskedThisUpdate.maximumSizeValue) break;
        if (this->unitsTaskedThisUpdate.value[i] == unit) goto tasked_done;
    }
    if (count > this->unitsTaskedThisUpdate.maximumSizeValue - 1) {
        int newMax = count + 1;
        int* nv = (int*)operator_new(newMax * 4);
        if (nv != 0) {
            i = 0;
            if (this->unitsTaskedThisUpdate.maximumSizeValue > 0) {
                while (1) {
                    if (i >= newMax) break;
                    nv[i] = this->unitsTaskedThisUpdate.value[i];
                    i++;
                    if (i >= this->unitsTaskedThisUpdate.maximumSizeValue) break;
                }
            }
            operator_delete(this->unitsTaskedThisUpdate.value);
            this->unitsTaskedThisUpdate.value = nv;
            this->unitsTaskedThisUpdate.maximumSizeValue = newMax;
        }
    }
    this->unitsTaskedThisUpdate.value[this->unitsTaskedThisUpdate.numberValue] = unit;
    this->unitsTaskedThisUpdate.numberValue++;

tasked_done:
    if (flag == 1) {
        i = 0;
        for (; i < this->civilians.numberValue; i++) {
            if (i >= this->civilians.maximumSizeValue) break;
            if (this->civilians.value[i] == unit) goto haveExplorer;
        }
        {
            ManagedIntArray& civiliansArray = this->civilians;
            i = 0;
            count = civiliansArray.numberValue;
            for (; i < count; i++) {
            if (i >= civiliansArray.maximumSizeValue) break;
                if (civiliansArray.value[i] == unit) goto haveExplorer;
            }
            if (count > civiliansArray.maximumSizeValue - 1) {
                int newMax = count + 1;
                int* nv = (int*)operator_new(newMax * 4);
                if (nv != 0) {
                    i = 0;
                    if (civiliansArray.maximumSizeValue > 0) {
                        while (1) {
                            if (i >= newMax) break;
                            nv[i] = civiliansArray.value[i];
                            i++;
                            if (i >= civiliansArray.maximumSizeValue) break;
                        }
                    }
                    operator_delete(civiliansArray.value);
                    civiliansArray.value = nv;
                    civiliansArray.maximumSizeValue = newMax;
                }
            }
            civiliansArray.value[civiliansArray.numberValue] = unit;
            civiliansArray.numberValue++;
        }
haveExplorer:
        this->removeGatherer(unit);
    }
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, unit, 0x2c1, -1, -1,
                            x, y, -1.0f, 1.0f, 1, 0, 1);
    return 1;
}
