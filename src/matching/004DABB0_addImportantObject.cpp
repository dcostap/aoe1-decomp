// 004DABB0 TribeInformationAIModule::addImportantObject
// taiinfmd.cpp
// Attempt log:
// try 1: broad reconstruction from packet: validation, allied recursion, add to important/object subtype lists, final notification.
// try 2: modeled object validation exactly from packet: null object, negative id, object type via obj->type+0x14, validType(type) helper.
// try 3: modeled owner/game/player chain at this+0x100, game+0xF0, player+0x3C/+0x4A/+0x40 observed in alliance recursion path.
// try 4: modeled no-recurse allied propagation path: player isAlly(dispatch table+0x18), player count > 3, strategy.check(0xC2)==1, loop players 1..count-1.
// try 5: modeled recursive call into other AI module at other->ai+0xCEC with recurse=1 when visibility/active checks pass.
// try 6: modeled markObject(obj) at 004DE600 and stored marked result for final notify condition.
// try 7: modeled first important-id list at +0x118/+0x11C/+0x124: duplicate scan, grow with malloc/free, append id.
// try 8: modeled classifyA/B/C dispatch helpers at 004DAFF0/004DB070/004DB0B0 and secondary lists at +0x128/+0x12C/+0x134 and +0x138/+0x13C/+0x144.
// try 9: factored duplicate list append into local helper for initial behavior; compiled but rebuilt .text only 768B vs original 962B, showing helper factoring is wrong for exactness.
// try 10: reviewed original: three append-list blocks are fully inlined, nearly duplicated, with subtly different register choices/copy loops; current helper collapses ~200B and prevents full diff.
// try 11: also current owner/player/local type surfaces are broad approximations, so even after inlining the append blocks exact register/layout is likely nontrivial.
// Prior worker left this in scratch: behavior was broadly reconstructed but
// the exact inlined append-block/source topology was unresolved.

// Session probes: restore the period ManagedArray/operator-new surface and the
// actual md -> player -> world/player-array ownership from the packet.  The
// previous candidate used a helper and a synthetic owner/game layer, which
// collapsed the three inlined growth blocks and added an extra +0x100 hop.
// Mirroring the same-TU addObject donor's indexed for scans, count >
// maximumSizeValue - 1 growth test, and combined-bound copy loops recovered
// the original 962-byte CFG and all three allocation/copy blocks.
// Swapping the natural world and owner-ID local declarations recovered the
// final four-byte ECX/EDX coloring hunk. Current default-flags build matches
// all 962 bytes; no custom flags or inline assembly are used.
extern void* operator new(unsigned int);
extern void operator delete(void*);

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap04[0x10];
    short objectGroup;
};

class RGE_Game_World;
class TribeMainDecisionAIModule;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    int isActive(int);
    int computerPlayer();
    char gap04[0x38];
    RGE_Game_World* world;
    char gap40[0x0a];
    short id;
    char gap4c[0x1ec];
    TribeMainDecisionAIModule* playerAI;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

class RGE_Game_World {
public:
    char gap00[0x3c];
    short player_num;
    char gap3e[2];
    RGE_Player** players;
};

class AIStrategy {
public:
    int strategicNumber(int);
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap000[0x100];
    TribeMainDecisionAIModule* md;
    char gap104[0x118-0x104];
    ManagedArray_int importantObjects;
    ManagedArray_int importantUnits;
    ManagedArray_int importantMiscs;
    char gap148[0x10090 - 0x148];

    int addImportantObject(RGE_Static_Object* obj, int recurse);
    int importantObject(int type);
    int importantUnit(int type);
    int importantResource(int type);
    int importantMisc(int type);
    int checkDefend(RGE_Static_Object* obj);
    int addResourceObject(RGE_Static_Object* obj);
    void* addObjectMemory(RGE_Static_Object* obj);
};
#endif

class TribeMainDecisionAIModule {
public:
    char gap00[0xf0];
    RGE_Player* player;
    char gapf4[0xbf8];
    TribeInformationAIModule informationAI;
    char gap10d7c[0x6f0];
    AIStrategy tacticalAI;
};

#endif

#endif
int TribeInformationAIModule::addImportantObject(RGE_Static_Object* obj, int recurse) {
    int oType;
    int marked;
    int id;
    int i;

    if (obj != 0 && obj->id >= 0) {
        oType = obj->master_obj->objectGroup;
        if (importantObject(oType) != 0) {
            RGE_Game_World* world = this->md->player->world;
            int ownerID = obj->owner->id;
            if (recurse == 0 && ownerID > 0 && this->md->player->isAlly(ownerID) != 0 && world->player_num > 3 && this->md->tacticalAI.strategicNumber(0xC2) == 1) {
                for (i = 1; i < world->player_num; ++i) {
                    if (i != this->md->player->id) {
                        RGE_Player* other = world->players[i];
                        if (other->computerPlayer() != 0 && this->md->player->isActive(i) != 0 && other->isActive(this->md->player->id) != 0) {
                            ((TribeMainDecisionAIModule*)other->playerAI)->informationAI.addImportantObject(obj, 1);
                        }
                    }
                }
            }

            marked = checkDefend(obj);
            id = obj->id;
            i = 0;
            for (i = 0; i < this->importantObjects.numberValue; ++i) {
                if (i >= this->importantObjects.maximumSizeValue) break;
                if (this->importantObjects.value[i] == id) goto important_unit;
            }
            if (this->importantObjects.numberValue > this->importantObjects.maximumSizeValue - 1) {
                int newMaximum = this->importantObjects.numberValue + 1;
                int* newValue = (int*)operator new(newMaximum * 4);
                if (newValue != 0) {
                    int j = 0;
                    while (j < this->importantObjects.maximumSizeValue && j < newMaximum) {
                        newValue[j] = this->importantObjects.value[j];
                        ++j;
                    }
                    operator delete(this->importantObjects.value);
                    this->importantObjects.value = newValue;
                    this->importantObjects.maximumSizeValue = newMaximum;
                }
            }
            this->importantObjects.value[this->importantObjects.numberValue] = id;
            this->importantObjects.numberValue = this->importantObjects.numberValue + 1;

important_unit:
            if (importantUnit(oType) == 1) {
                id = obj->id;
                i = 0;
                for (i = 0; i < this->importantUnits.numberValue; ++i) {
                    if (i >= this->importantUnits.maximumSizeValue) break;
                    if (this->importantUnits.value[i] == id) goto end;
                }
                if (this->importantUnits.numberValue > this->importantUnits.maximumSizeValue - 1) {
                    int newMaximum = this->importantUnits.numberValue + 1;
                    int* newValue = (int*)operator new(newMaximum * 4);
                    if (newValue != 0) {
                        int j = 0;
                        while (j < this->importantUnits.maximumSizeValue && j < newMaximum) {
                            newValue[j] = this->importantUnits.value[j];
                            ++j;
                        }
                        operator delete(this->importantUnits.value);
                        this->importantUnits.value = newValue;
                        this->importantUnits.maximumSizeValue = newMaximum;
                    }
                }
                this->importantUnits.value[this->importantUnits.numberValue] = id;
                this->importantUnits.numberValue = this->importantUnits.numberValue + 1;
            } else {
                if (importantResource(oType) == 1) {
                    addResourceObject(obj);
                } else if (importantMisc(oType) == 1) {
                    id = obj->id;
                    i = 0;
                    for (i = 0; i < this->importantMiscs.numberValue; ++i) {
                        if (i >= this->importantMiscs.maximumSizeValue) break;
                        if (this->importantMiscs.value[i] == id) goto end;
                    }
                    if (this->importantMiscs.numberValue > this->importantMiscs.maximumSizeValue - 1) {
                        int newMaximum = this->importantMiscs.numberValue + 1;
                        int* newValue = (int*)operator new(newMaximum * 4);
                        if (newValue != 0) {
                            int j = 0;
                            while (j < this->importantMiscs.maximumSizeValue && j < newMaximum) {
                                newValue[j] = this->importantMiscs.value[j];
                                ++j;
                            }
                            operator delete(this->importantMiscs.value);
                            this->importantMiscs.value = newValue;
                            this->importantMiscs.maximumSizeValue = newMaximum;
                        }
                    }
                    this->importantMiscs.value[this->importantMiscs.numberValue] = id;
                    this->importantMiscs.numberValue = this->importantMiscs.numberValue + 1;
                }
            }

end:
            if (importantUnit(oType) == 1 || marked == 1) {
                addObjectMemory(obj);
            }
            return 1;
        }
    }
    return 0;
}
