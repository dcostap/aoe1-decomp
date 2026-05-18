// VA 005071F0 TribeSoldierUnitAIModule::processNotify
// taiuaimd.cpp:2380-2536
// Attempt log:
// 1: Natural reconstruction from packet/decompiler using nearby taiuaimd processNotify/list-growth patterns.
// 2: Modeled NotifyEvent type split for 0x20F evasive-move and 0x200 chase/retreat paths, with base processNotify fallback.
// 3: Added computerPlayer/world->object/type gates, group 0x23/0x24 checks, command/target checks, and issueOrder/moveTo virtual-call surfaces.
// 4: Added debug_rand jitter and FPU-ish random coordinate adjustment logic for both X/Y evasive targets.
// 5: Added rangeLeft/distance_to_object check, target vector accumulation, dynamic id-list growth/copy/delete pattern, and normalized retreat move.
// 6: Default /O2 /Oy compiles but is size-short: configured 1098 exceeds rebuilt .text 992. Broad source is behaviorally approximate but not enough codegen/detail.
// 7: Probed /Od: exact size 1098 but broad wrong basin from offset 0 (86.7942% positional); removed flag.
// 8: Probed /O2 /Oy /Ob0: still size-short 992; removed flag.
// 9: Probed /O2 /Oy /Og-: exact size 1098 but broad wrong basin from offset 0 (86.0656% positional); removed flag.
// 10: Probed /O2 /Oy /Op: closer size 1040 but still size-short; removed flag.
// 11: Probed /O1 /Oy: size-short 861; removed flag.
// GIVEUP: left in scratch. Main blockers are inaccurate true owner/object/player type surface and large FPU/list-growth source topology; default optimized build is size-short, exact-size diagnostics are broad from offset 0. No accepted_drift.

extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);
extern int __cdecl debug_rand(char*, int);
extern int taskedThisUpdate;
extern float FLOAT_5758BC; // 1.0
extern float FLOAT_5758C0;
extern float FLOAT_5758DC;
extern float FLOAT_5758E0;
extern float FLOAT_5758E4;
extern double __cdecl sqrt(double);

struct NotifyEvent { int caller; int unk4; int type; int p2; };
struct UnitType { char gap0[0x10]; short object_group; short gap12; short object_class; };
struct RGE_Static_Object {
    void* vtbl;
    int player_id;
    UnitType* type;
    char gap0C[0x38-0x0C];
    float x;
    float y;
    int z;
    float distance_to_object(RGE_Static_Object* other);
};
struct RGE_Game_World { RGE_Static_Object* object(int id); };
struct RGE_Player { int computerPlayer(); char gap[0x3C-4]; RGE_Game_World* world; };
struct UnitAIModuleBase { int processNotify(NotifyEvent*, unsigned long); };

class TribeSoldierUnitAIModule {
public:
    void* vtbl;                 // +00
    RGE_Static_Object* object;  // +04
    char gap08[0x28-0x08];
    int field_28;
    int orderType;              // +2c
    int command;                // +30
    int targetId;               // +34
    char gap38[4];
    float orderX;               // +3c
    int field_40;               // +40
    int field_44;               // +44
    int field_48;               // +48
    char gap4C[0x60-0x4C];
    int* idList;                // +60
    int idCount;                // +64
    char gap68[4];
    int idMax;                  // +6c

    int processNotify(NotifyEvent*, unsigned long);
    int baseProcessNotify(NotifyEvent*, unsigned long);
    int issueOrder(int player_id,int cmd,int target,int minus1,float x,int f40,int f44,float f48,int z0,int z1,int orderType);
    int moveTo(float x,float y,int z,int a,int b);
    float rangeLeft();
};

static void grow_list_005071F0(TribeSoldierUnitAIModule* self, int index)
{
    if (index > self->idMax - 1) {
        int newMax = index + 1;
        int* p = (int*)operator new(newMax * 4);
        if (p) {
            int i = 0;
            if (self->idMax > 0) {
                do {
                    if (i >= newMax) break;
                    p[i] = self->idList[i];
                    ++i;
                } while (i < self->idMax);
            }
            operator delete(self->idList);
            self->idList = p;
            self->idMax = newMax;
        }
    }
}

int TribeSoldierUnitAIModule::processNotify(NotifyEvent* ev, unsigned long flags)
{
    float evasiveMoveDistance;
    float evasiveX;

    if (ev->type == 0x20F) {
        RGE_Player* player = object->type ? *(RGE_Player**)((char*)object + 0x0C) : 0;
        if (!((RGE_Player*)((char*)object + 0x0C))->computerPlayer()) goto base;
        RGE_Static_Object* attacker = (*(RGE_Player**)((char*)object + 0x0C))->world->object(ev->caller);
        if (!attacker) goto base;
        short group = attacker->type->object_group;
        if (group != 0x23 && group != 0x24) goto base;
        if (command == -1) goto base;
        if (field_28 != -1) {
            issueOrder(object->player_id, field_28, targetId, -1, orderX, field_40, field_44, *(float*)&field_48, 0, 0, orderType);
        }
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x97c);
        evasiveMoveDistance = object->x - FLOAT_5758DC + (float)(r % 8);
        if (evasiveMoveDistance == object->x) {
            if (evasiveMoveDistance >= FLOAT_5758E0) evasiveMoveDistance -= FLOAT_5758E4;
            else evasiveMoveDistance -= FLOAT_5758C0;
        }
        r = debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x983);
        evasiveX = object->y - FLOAT_5758DC + (float)(r % 8);
        if (evasiveX == object->y) {
            if (evasiveX >= FLOAT_5758E0) evasiveX -= FLOAT_5758E4;
            else evasiveX -= FLOAT_5758C0;
        }
        if (moveTo(evasiveMoveDistance, evasiveX, object->z, 1, 1) != 1) goto base;
        taskedThisUpdate = 1;
        return 3;
    }

    if (ev->type == 0x200) {
        RGE_Player* player = *(RGE_Player**)((char*)object + 0x0C);
        if (!player->computerPlayer()) goto base;
        if (rangeLeft() < FLOAT_5758BC) goto base;
        if (object->type->object_class == 0x1A) goto base;
        if (command != 600) return 2;
        RGE_Static_Object* target = player->world->object(targetId);
        if (!target) goto base;
        float distLeft = rangeLeft() - object->distance_to_object(target);
        evasiveMoveDistance = distLeft;
        if (distLeft < FLOAT_5758BC) goto base;
        float dx = target->x - object->x;
        float dy = target->y - object->y;
        issueOrder(object->player_id, 700, targetId, -1, orderX, field_40, field_44, *(float*)&field_48, 0, 1, orderType);
        int i = 0;
        if (idCount > 0) {
            do {
                grow_list_005071F0(this, i);
                if (idList[i] != targetId) {
                    grow_list_005071F0(this, i);
                    RGE_Static_Object* o = player->world->object(idList[i]);
                    if (o) {
                        dx += o->x - object->x;
                        dy += o->y - object->y;
                    }
                }
                ++i;
            } while (i < idCount);
        }
        float mag = (float)sqrt(dx * dx + dy * dy);
        if (moveTo(object->x - dx / mag * distLeft, object->y - dy / mag * distLeft, object->z, 0, 1) == 1) return 3;
        return 2;
    }
base:
    return ((UnitAIModuleBase*)this)->processNotify(ev, flags);
}
