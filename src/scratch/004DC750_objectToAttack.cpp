// 004DC750 TribeInformationAIModule::objectToAttack (taiinfmd.cpp:3458-3765, 1977 bytes)
// Clean canonical reconstruction from packet asm + PDB line bands.
//
// Attempt log:
// - baseline: clean reconstruction. Every offset/condition verified against original asm:
//   * loop predicate reloads each CANDIDATE's master_obj->object_group/master_id (per-iteration
//     `mov eax,[esi+8]` in both guards), never the attacked unit's group.
//   * oLimits is the struct-return value of findObjectMemoryLimits(player, objnum, &randomRating,
//     &id); the hidden return slot lands at &oLimits (no post-call copy in original).
//   * timeToKill = 100 (integer 0x64 store, "1.4013e-43" in Ghidra is just float rendering of 100);
//     hpRating/distanceRating/bestAttackValue/unitIsPriest defaults are 100.
//   * final rating override is `rating = 1` when ((bestObject > boatWeapon && boatWeapon != -1.0f)
//     || bestObject == -1.0f) -- branch topology verified against original.
//   * slot 49 (0xC4) on unitAI() dispatch is mostDangerousEnemy per derived UnitAIModule vtable;
//     local declaration uses int arg (caller passes record->id); exact donor 00415A10 declares
//     float* outThreat -- local stub only, slot/arity identical.
// - probe 2: split into TWO distance blocks (candidate coords for the visibility check, unit coords
//   for the distance); guards as positive `if (a == 0 && ... && x > 0) continue;` (matches original
//   test/jg); numberNonSiegeTargets as store-0/conditional-1. Frame 0x88, 44/44 calls aligned.
// - probe 3: raw-offset record accesses (donor 004E4680 idiom) so the original's per-iteration
//   importantObjectMemory reload and inline base derivation are reproduced instead of a spilled
//   record pointer + hoisted member load.
//
// orch-w1 session probes (for-loop era, best 1423 diff / 78.42% shape / size 1977 exact):
// - KEY: converted the loop from do-while (body-bottom dCRating++; i += 0x24) to a for-loop with
//   increments in the header. In VC5 a do-while `continue` jumps to the condition and SKIPS
//   body-bottom increment statements (rebuilt infinite-looped on skip paths); the original's
//   continue paths all jump to the bottom increment+test block (004DCECB), which is for-loop
//   continue semantics. This fixed the loop rotation: size 1983->1977 exact, exact-blocks
//   29.48%->39.24%, shape 76.22%->78.42%, and removed the split test-block/extra jmp.
// - rangeRating rewritten as if/else with the zero store in both arms; VC5 hoists the 0 store
//   between the last cmp and the jne, matching original `cmp ax,0Bh; mov [esp+24h],ebp; jne`.
// - loop init forms (for-init i=0 vs separate int i=0, i declared before/after unitZone) and
//   loop-form variants were swept via variant_lab; all dedupe to the same emitted code.
// - REMAINING (next lead): the whole function's register roles are swapped vs original:
//   original keeps unit in EBX and the zero/loop-offset in EBP (xor ebp,ebp at 004DC763 is the
//   dedicated zero that later becomes the record byte-offset); rebuilt puts unit in EBP and the
//   offset/zero in EBX. Local slot layout also shifts (i at [esp+14h] orig vs [esp+18h] reb,
//   dCRating [esp+54h] vs [esp+4Ch], unitZone [esp+1Bh] vs [esp+17h]). This is a register-
//   allocation/liveness basin issue, not a structural or call-set one: calls 44/44 aligned,
//   frame 0x88/0x88, CFG signals matched, first strict mismatch at +0014 (xor ebp vs xor ebx).

#include <math.h>

extern "C" long __ftol();
extern int debug_rand(char* file, int line);

typedef unsigned char uchar;

struct ObjectMemory {
    int id;                  // +0x00
    short type;              // +0x04
    short group;             // +0x06
    uchar x;                 // +0x08
    uchar y;                 // +0x09
    uchar z;                 // +0x0A
    uchar owner;             // +0x0B
    short hitPoints;         // +0x0C
    char pad0E[2];           // +0x0E
    int attackAttempts;      // +0x10
    uchar kills;             // +0x14
    char pad15[3];           // +0x15
    float damageCapability;  // +0x18
    float rateOfFire;        // +0x1C
    float range;             // +0x20
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short master_id;         // +0x10
    short gap_12;
    short object_group;      // +0x14
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_a)
#define VPAD4(n) VPAD2(n) VPAD2(n##_b)
#define VPAD8(n) VPAD4(n) VPAD4(n##_c)
#define VPAD16(n) VPAD8(n) VPAD8(n##_d)
#define VPAD32(n) VPAD16(n) VPAD16(n##_e)

class RGE_Static_Object;
class UnitAIModule;
class RGE_Visible_Map;

class RGE_Static_Object {
public:
    VPAD32(a0) VPAD32(a32)                    // vtable slots 0..63
    virtual float vf100();                    // slot 64 = +0x100 (attack rate)
    virtual float vf104(RGE_Static_Object* obj); // slot 65 = +0x104 (damage vs obj)

    int obj_id;                               // +0x04
    RGE_Master_Static_Object* master_obj;     // +0x08
    char gap_0C[0x30 - 0x0C];
    float hp;                                 // +0x30
    char gap_34[4];
    float world_x;                            // +0x38
    float world_y;                            // +0x3C
    char gap_40[8];
    uchar object_state;                       // +0x48

    uchar currentZone();
    uchar lookupZone(int x, int y);
    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    VPAD32(a0) VPAD16(a32) VPAD1(a48)         // vtable slots 0..48
    virtual int mostDangerousEnemy(int id);   // slot 49 = +0xC4
};

struct RGE_Visible_Map {
    uchar get_visible(int x, int y);
};

class VisibleMapHolder {
public:
    char gap_00[0x38];
    RGE_Visible_Map* map;                     // +0x38
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int index);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    VisibleMapHolder* member_F0;              // +0xF0
    char gap_F4[0x1146C - 0xF4];
    TribeTacticalAIModule tacticalAI;         // +0x1146C
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;                 // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;             // +0x110
    ObjectMemory* importantObjectMemory;      // +0x114

    ObjectMemory* wonderToAttack(int param);
    int isBoat(RGE_Static_Object* obj);
    float damagePerSecond(int objnum, int x, int y);
    ObjectMemory findObjectMemoryLimits(int player, int objnum, int* c1, int* c2);
    ObjectMemory* objectToAttack(int player, int siegeWeapons, int boats, int objnum, int* out);
};

ObjectMemory* TribeInformationAIModule::objectToAttack(int player, int siegeWeapons, int boats, int objnum, int* out)
{
    ObjectMemory* mem = this->wonderToAttack(-1);
    if (mem != 0) {
        *out = 1;
        return mem;
    }

    RGE_Static_Object* unit = this->md->object(objnum);
    if (unit == 0 || unit->unitAI() == 0) {
        return 0;
    }

    uchar unitZone = unit->currentZone();
    int rangeRating;
    if (unit->master_obj->master_id == 0x23 ||
        unit->master_obj->master_id == 0x24 ||
        unit->master_obj->master_id == 0x0B) {
        rangeRating = 1;
    } else {
        rangeRating = 0;
    }
    int unitIsBoat = this->isBoat(unit);
    int numberNonSiegeTargets = 0;
    if (unit->master_obj->object_group == 0x12) numberNonSiegeTargets = 1;

    int randomRating;
    int id;
    ObjectMemory oLimits = findObjectMemoryLimits(player, objnum, &randomRating, &id);

    ObjectMemory* best = 0;
    int specialRating3 = -1;
    int dCRating;
    int i;
    for (dCRating = 0, i = 0; dCRating < this->maxImportantObjectMemory; dCRating++, i += 0x24) {
            if (*(uchar*)((char*)this->importantObjectMemory + i + 0x0B) == player) {
                RGE_Static_Object* candidate =
                    this->md->object(*(int*)((char*)this->importantObjectMemory + i));
                if (candidate != 0 && candidate->object_state <= 2) {
                    float damage = this->damagePerSecond(objnum,
                                                         (int)candidate->world_x,
                                                         (int)candidate->world_y);
                    float fVar3 = candidate->vf104(unit) / unit->vf100();
                    float boatWeapon;
                    float bestObject;
                    if (damage > 0.0f) {
                        boatWeapon = unit->hp / damage;
                    } else {
                        boatWeapon = -1.0f;
                    }
                    if (fVar3 > 0.0f) {
                        bestObject =
                            (float)*(short*)((char*)this->importantObjectMemory + i + 0x0C) / fVar3;
                    } else {
                        bestObject = -1.0f;
                    }
                    if (rangeRating == 0 && siegeWeapons != 0 &&
                        (candidate->master_obj->object_group == 3 ||
                         candidate->master_obj->object_group == 0x1B) &&
                        randomRating > 0) {
                        continue;
                    }
                    if (unitIsBoat == 0 && boats != 0 &&
                        (candidate->master_obj->master_id == 0x2D ||
                         candidate->master_obj->object_group == 2 ||
                         candidate->master_obj->object_group == 0x15 ||
                         candidate->master_obj->object_group == 0x16 ||
                         candidate->master_obj->object_group == 0x14) &&
                        id > 0) {
                        continue;
                    }
                    if (numberNonSiegeTargets != 0) {
                        if (unit->unitAI()->mostDangerousEnemy(
                                *(int*)((char*)this->importantObjectMemory + i)) == 0) continue;
                    }
                    int ix = (int)candidate->world_x;
                    int iy = (int)candidate->world_y;
                    int dx1 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x08) - ix;
                    if (dx1 < 0) dx1 = -dx1;
                    int dy1 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x09) - iy;
                    if (dy1 < 0) dy1 = -dy1;
                    if (dx1 > 5 || dy1 > 5) {
                        if (this->md->member_F0->map->get_visible(ix, iy) != 0x0F) {
                            continue;
                        }
                    }
                    int dx2 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x08)
                              - (int)unit->world_x;
                    int dy2 = (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x09)
                              - (int)unit->world_y;
                    int distance = (int)(sqrt(dx2 * dx2 + dy2 * dy2));
                    int unitIsPriest;
                    if (oLimits.id != 0) {
                        unitIsPriest = 100 - distance * 100 / oLimits.id;
                    } else {
                        unitIsPriest = 100;
                    }
                    int distanceRating;
                    if (oLimits.hitPoints != 0) {
                        distanceRating =
                            (int)*(short*)((char*)this->importantObjectMemory + i + 0x0C) * 100
                            / oLimits.hitPoints;
                    } else {
                        distanceRating = 100;
                    }
                    int bestAttackValue;
                    if (oLimits.kills != 0) {
                        bestAttackValue =
                            (int)*(uchar*)((char*)this->importantObjectMemory + i + 0x14) * 100
                            / (int)oLimits.kills;
                    } else {
                        bestAttackValue = 100;
                    }
                    int hpRating;
                    if (oLimits.damageCapability != 0.0f) {
                        hpRating =
                            (int)(*(float*)((char*)this->importantObjectMemory + i + 0x18)
                                  * 100.0f / oLimits.damageCapability);
                    } else {
                        hpRating = 100;
                    }
                    int timeToKill;
                    int siegeWeapon;
                    if (*(float*)((char*)this->importantObjectMemory + i + 0x18) > 0.0f) {
                        if (oLimits.range != 0.0f) {
                            timeToKill =
                                (int)(*(float*)((char*)this->importantObjectMemory + i + 0x20)
                                      * 100.0f / oLimits.range);
                        } else {
                            timeToKill = 100;
                        }
                        if (oLimits.rateOfFire != 0.0f) {
                            siegeWeapon =
                                100 - (int)(*(float*)((char*)this->importantObjectMemory + i + 0x1C)
                                           * 100.0f / oLimits.rateOfFire);
                        } else {
                            siegeWeapon = 100;
                        }
                    } else {
                        timeToKill = 0;
                        siegeWeapon = 0;
                    }
                    int numberNonBoatTargets =
                        debug_rand((char*)"C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0xE36) % 100;
                    int typeMatchA = 0;
                    if (*(short*)((char*)this->importantObjectMemory + i + 0x04)
                            == this->md->tacticalAI.strategicNumber(0x6A)) typeMatchA = 1;
                    int typeMatchB = 0;
                    if (*(short*)((char*)this->importantObjectMemory + i + 0x04)
                            == this->md->tacticalAI.strategicNumber(0x6B)) typeMatchB = 1;
                    int typeMatchC = 0;
                    if (*(short*)((char*)this->importantObjectMemory + i + 0x04)
                            == this->md->tacticalAI.strategicNumber(0x6C)) typeMatchC = 1;
                    int specialRating2 = 0;
                    if (unit->lookupZone((int)candidate->world_x,
                                         (int)candidate->world_y) == unitZone) {
                        specialRating2 = 1;
                    }
                    int rangeSign;
                    int boatSign;
                    if (candidate->master_obj->object_group == 3 ||
                        candidate->master_obj->object_group == 0x1B) {
                        rangeSign = rangeRating ? 1 : -1;
                    } else {
                        rangeSign = rangeRating ? -1 : 1;
                    }
                    if (candidate->master_obj->master_id == 0x2D ||
                        candidate->master_obj->object_group == 2 ||
                        candidate->master_obj->object_group == 0x15 ||
                        candidate->master_obj->object_group == 0x16 ||
                        candidate->master_obj->object_group == 0x14) {
                        boatSign = unitIsBoat ? 1 : -1;
                    } else {
                        boatSign = unitIsBoat ? -1 : 1;
                    }
                    int rating =
                        this->md->tacticalAI.strategicNumber(0x59)
                            * *(int*)((char*)this->importantObjectMemory + i + 0x10)
                        + this->md->tacticalAI.strategicNumber(0x90) * boatSign
                        + this->md->tacticalAI.strategicNumber(0x7B) * rangeSign
                        + this->md->tacticalAI.strategicNumber(0x7A) * specialRating2
                        + this->md->tacticalAI.strategicNumber(0x50) * bestAttackValue
                        + this->md->tacticalAI.strategicNumber(0x53) * numberNonBoatTargets
                        + this->md->tacticalAI.strategicNumber(0x4D) * unitIsPriest
                        + this->md->tacticalAI.strategicNumber(0x6F) * typeMatchC
                        + this->md->tacticalAI.strategicNumber(0x5A) * timeToKill
                        + this->md->tacticalAI.strategicNumber(0x4E) * distanceRating
                        + this->md->tacticalAI.strategicNumber(0x4F) * hpRating
                        + this->md->tacticalAI.strategicNumber(0x52) * siegeWeapon
                        + this->md->tacticalAI.strategicNumber(0x6E) * typeMatchB
                        + this->md->tacticalAI.strategicNumber(0x6D) * typeMatchA;
                    if ((bestObject > boatWeapon && boatWeapon != -1.0f) ||
                        bestObject == -1.0f) {
                        rating = 1;
                    }
                    if (best == 0 || rating > specialRating3) {
                        best = (ObjectMemory*)((char*)this->importantObjectMemory + i);
                        specialRating3 = rating;
                        *out = 1;
                    }
                }
            }
    }
    return best;
}
