// 004F87B0 TribeTacticalCommand::unit
// Attempt log:
// try 1: packet-grounded reconstruction. Models three unit-id arrays at +0xf4/+114/+134, grows arrays as needed, resolves object IDs through world->object, filters by current selected unit predicates, and returns matched ID or -1.
// try 2: fixed operator new/get_current_unit declarations to compile; helper-factored source compiles too short (704B vs 1071B) because grow/filter code is out-of-line/factored by source.
// try 3: modeled first list at +0xf4/+0x100/+0xf8, with capacity grow using new size (i+1)*4, copy old entries, free old array, update cap.
// try 4: modeled second list at +0x114/+0x120/+0x118 with same grow/copy/free/update pattern.
// try 5: modeled third list at +0x134/+0x140/+0x138 with same grow/copy/free/update pattern.
// try 6: modeled world lookup through this+0xf0 -> +0x1256c -> +0x3c -> object(id) call.
// try 7: modeled match rejection when object lookup returns non-null, then current-unit lookup through 004C7420.
// try 8: modeled optional player/class/type filters using -1 wildcard and virtual/helper calls 00413960/00413980/00413990 on current unit.
// try 9: modeled first list type wildcard success path returning original id directly.
// try 10: modeled second/third list success paths returning array entry after possible grow, and final -1 return.
// GIVEUP blockers: exact in-function expansion of grow-array blocks, true current-unit helper/class surfaces and calling convention, exact list field layout/capacity semantics, and preserving original EBX/EBP/EDI loop-register topology. No inline asm used; no accepted_drift proposal.

extern "C" void __cdecl free(void*);

class RGE_Static_Object;
class WorldObj { public: RGE_Static_Object* object(int); };
class GameObj { public: char gap[0x1256c]; WorldObj* world; };
class CurrentUnit { public: int player(); int class_id(); int type_id(); };
extern CurrentUnit* get_current_unit_004C7420(void*);

class TribeTacticalCommand {
public:
    char gap00[0xf0]; GameObj* game;
    int* units1; int cap1; int count1;
    char gap100[0x14]; int* units2; int cap2; int count2;
    char gap124[0x10]; int* units3; int cap3; int count3;
    int unit(int player, int cls, int type);
};

static void grow_to(int*& arr, int& cap, int index)
{
    if (index > cap - 1) {
        int newCap = index + 1;
        int* p = (int*)operator new(newCap * 4);
        if (p) {
            int i = 0;
            while (i < cap && i < newCap) { p[i] = arr[i]; ++i; }
            free(arr);
            arr = p;
            cap = newCap;
        }
    }
}

static int matches_filters(RGE_Static_Object* o, int player, int cls, int type)
{
    if (o) return 0;
    CurrentUnit* u = get_current_unit_004C7420(0);
    if (u) return 0;
    if (player != -1) { u = get_current_unit_004C7420(0); if (u->player() != player) return 0; }
    if (cls != -1) { u = get_current_unit_004C7420(0); if (u->class_id() != cls) return 0; }
    if (type != -1) { u = get_current_unit_004C7420(0); if (u->type_id() == type) return 1; return 0; }
    return 1;
}

int TribeTacticalCommand::unit(int player, int cls, int type)
{
    int i = 0;
    for (i = 0; i < this->count1; ++i) {
        grow_to(this->units1, this->cap1, i);
        int id = this->units1[i];
        RGE_Static_Object* obj = this->game->world->object(id);
        if (matches_filters(obj, player, cls, type)) return id;
    }
    for (i = 0; i < this->count2; ++i) {
        grow_to(this->units2, this->cap2, i);
        int id = this->units2[i];
        RGE_Static_Object* obj = this->game->world->object(id);
        if (matches_filters(obj, player, cls, type)) {
            grow_to(this->units2, this->cap2, i);
            return this->units2[i];
        }
    }
    for (i = 0; i < this->count3; ++i) {
        grow_to(this->units3, this->cap3, i);
        int id = this->units3[i];
        RGE_Static_Object* obj = this->game->world->object(id);
        if (matches_filters(obj, player, cls, type)) {
            grow_to(this->units3, this->cap3, i);
            return this->units3[i];
        }
    }
    return -1;
}
