// VA: 004DDD40 TribeInformationAIModule::objectToAttackByGroup2
// PDB source: taiinfmd.cpp
// Attempt log:
// - reconstructed broad behavior from packet: commander/group gates, object-memory scan, distance/strategic-number scoring.
// - default /O2 compiled but .text was 1056 vs target 1200, too short for byte extraction; source is still missing exact helper surfaces/block topology.
// - tried adding /GX: no change, still 1056 bytes, so this is not an EH-frame target.
// - tried /Od only as diagnostic: produced comparable 1200-byte extraction but 86.17% positional diff from offset 0 (EBP frame), proving original is optimized /O2 not /Od.
// - kept default flags; give-up notes only. No accepted_drift: broad unexplained behavior/source drift remains.

extern int debug_rand(char* file, int line);
extern int __ftol(float);

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
struct ObjectMemory;
class RGE_Static_Object {
public:
    void* vt; char gap04[4]; void* master; char gap0c[0x30-0x0c]; float x; float y; float z; char gap40[8]; unsigned char state;
    int is_live(); int can_attack(); unsigned char get_zone(); int object_id(); unsigned char same_zone(int x, int y);
};
class AttackDispatch { public: VPAD32(a0) VPAD16(a32) VPAD1(a48) virtual int can_attack_mem(ObjectMemory* mem); };
class MainDecisionAIModule { public: RGE_Static_Object* object(int id); char gap04[0x1146c-4]; int strategicNumber(int id); };
struct ObjectMemory { int id; char gap04[4]; unsigned char tilex; unsigned char tiley; char gap0a; unsigned char group; int data10; char flag14; char pad15[0x24-0x15]; };
class TribeInformationAIModule {
public:
    char gap0[0x100]; MainDecisionAIModule* md; char gap104[0x110-0x104]; int objectMemoryCount; ObjectMemory* objectMemory;
    ObjectMemory* wonderToAttack(int p);
    float attackFactor(int count, int* ids, RGE_Static_Object* obj);
    float attackFactor2(int count, int* ids, RGE_Static_Object* obj);
    ObjectMemory* objectToAttackByGroup2(int* ids, int group, int count);
};

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(int* ids, int group, int count)
{
    RGE_Static_Object* commander;
    unsigned char commanderZone;
    int commanderIsPriest;
    int i;
    int offset;
    ObjectMemory* best;
    float bestScore;
    float targetDistance;
    float zoneFactor;
    float inProgressFactor;
    float priestFactor;
    float rangeFactor;
    float randomFactor;
    float countFactor;

    if (this->wonderToAttack(-1) != 0) return 0;
    if (count == 0) return 0;

    commander = this->md->object(*ids);
    if (commander == 0) return 0;
    if (!commander->is_live()) return 0;
    commanderZone = commander->get_zone();
    commanderIsPriest = 0;
    if (*(short*)((char*)commander->master + 0x14) == 0x12) commanderIsPriest = 1;

    best = 0;
    bestScore = -1.0f;
    offset = 0;
    if (this->objectMemoryCount <= 0) return best;
    for (i = 0; i < this->objectMemoryCount; ++i, offset += 0x24) {
        ObjectMemory* mem = (ObjectMemory*)((char*)this->objectMemory + offset);
        if (mem->group != group) continue;
        RGE_Static_Object* obj = this->md->object(mem->id);
        if (obj == 0) continue;
        if (obj->state > 2) continue;
        if (obj->x == 0.0f) continue;
        int ox = (int)obj->y;
        int dx = (int)mem->tilex - ox; if (dx < 0) dx = -dx;
        int oy = (int)obj->z;
        int dy = (int)mem->tiley - oy; if (dy < 0) dy = -dy;
        if (dx > 5 || dy > 5) {
            if (this->md->object(0)->same_zone(ox, oy) != 0x0f) continue;
        }
        if (commanderIsPriest && commander->is_live()) {
            if (((AttackDispatch*)commander->is_live())->can_attack_mem(mem) == 0) continue;
        }

        zoneFactor = this->attackFactor(count, ids, obj);
        inProgressFactor = obj->x / zoneFactor;
        rangeFactor = this->attackFactor2(count, ids, obj);
        if (zoneFactor == 0.0f) continue;
        if (rangeFactor == 0.0f) continue;

        targetDistance = rangeFactor / inProgressFactor;
        dx = mem->tilex - (int)obj->y;
        dy = mem->tiley - (int)obj->z;
        float dist = (float)(dx * dx + dy * dy);
        targetDistance = dist;
        if (targetDistance < 1.0f) targetDistance = 1.0f;

        randomFactor = 0.0f;
        int sn = this->md->strategicNumber(0x53);
        if (sn > 0) randomFactor = (float)(debug_rand((char*)0x5878DC, 0x110b) % sn);
        zoneFactor = (float)this->md->strategicNumber(0x59) * mem->data10;
        priestFactor = 0.0f;
        if (commanderZone == obj->same_zone((int)obj->z, (int)obj->y)) priestFactor = (float)this->md->strategicNumber(0x7a);

        countFactor = 0.0f;
        if (this->md->strategicNumber(0xb9) > 0) {
            int c = 0;
            for (int j = 0; j < count; ++j) {
                RGE_Static_Object* o = this->md->object(ids[j]);
                if (o && o->is_live() && ((RGE_Static_Object*)o->is_live())->object_id() == *(int*)((char*)mem)) c++;
            }
            countFactor = (float)(this->md->strategicNumber(0xb9) * c);
        }
        float score = (float)this->md->strategicNumber(0xb8) * targetDistance;
        score = score + (float)this->md->strategicNumber(0x4d) / rangeFactor + zoneFactor + countFactor + priestFactor + inProgressFactor + randomFactor;
        if (best == 0 || score > bestScore) {
            bestScore = score;
            best = mem;
        }
    }
    return best;
}
