// 004F0D70 TribeTacticalAIModule::addObject
// Attempt log:
// try 1: reconstructed object-type dispatch and per-list duplicate/insert helper behavior from asm.
// try 2: modeled object master pointer at +8, object id at +4, master type at +0x14 and master id at +0x10.
// try 3: modeled TACTICAL lists at +0xf4, +0x114, +0x134, +0x144, +0x154, +0x164, +0x174, +0x184 based on asm offsets.
// try 4: used local add_unique_scan helper for the duplicated scan/grow/write sequence; compiles but too small (608B vs 798B) because helper abstraction changes code shape.
// try 5: matched exclusion compare order for types 0,18,6,19,1a,c,23,17,24,1c,12,d,27.
// try 6: matched group compare order 2,14,16,15 and secondary list inserts for each exact subtype.
// try 7: modeled checkObjectInList/addImportantObject helper calls for 14/16/15 lists; calls are semantically correct but source factoring still too compact.
// try 8: modeled type 2 list as duplicate scan insert at +0x164.
// try 9: modeled special master id 0x9f plus player/world/difficulty chain (+0xf0,+0xf0,+0x3c) before +0x184 addImportantObject.
// try 10: /GX probe had no effect on compact code size; removed.
// left in scratch: behavior and offsets are reconstructed, but duplicated source shape must be manually inlined/unfactored to reach original size/layout; not accepted_drift-safe.

typedef unsigned char uchar;
struct Master { char pad0[0x10]; short id; char pad12[2]; short type; };
struct Obj { char pad0[4]; int id; Master* master; };
class World { public: char pad0[0x3c]; int difficultyLevel(); };
struct PlayerWrap { char pad0[0xf0]; World* world; };
struct IntArray { int* value; int count; int max; void setSize(int); int checkObjectInList(int, int*); void addImportantObject(int); };
class TribeTacticalAIModule { public:
 char pad0[0xf0]; PlayerWrap* player;
 IntArray objects4; char pad100[0x114-0x100]; IntArray misc;
 char pad124[0x134-0x124]; IntArray groupA; IntArray list16; IntArray list15; IntArray list2; IntArray list14; IntArray special;
 void addObject(Obj*);
};

static void add_unique_scan(IntArray* a, int id) {
    int i = 0;
    int n = a->count;
    if (n > 0) {
        do {
            if (i >= a->max) break;
            if (a->value[i] == id) return;
            i++;
        } while (i < n);
    }
    if (n > a->max - 1) a->setSize(n + 1);
    a->value[a->count] = id;
    a->count++;
}

void TribeTacticalAIModule::addObject(Obj* obj)
{
    Master* m = obj->master;
    short t = m->type;
    int id;
    if (t == 4) {
        add_unique_scan(&this->objects4, obj->id);
        return;
    }
    if (t == 0 || t == 0x18 || t == 6 || t == 0x19 || t == 0x1a || t == 0x0c || t == 0x23 || t == 0x17 || t == 0x24 || t == 0x1c || t == 0x12 || t == 0x0d || t == 0x27) {
        add_unique_scan(&this->misc, obj->id);
        return;
    }
    if (t == 2 || t == 0x14 || t == 0x16 || t == 0x15) {
        add_unique_scan(&this->groupA, obj->id);
        if (obj->master->type == 2) add_unique_scan(&this->list2, obj->id);
        if (obj->master->type == 0x14) { id = obj->id; if (this->list14.checkObjectInList(1, &id) != 1) this->list14.addImportantObject(id); }
        if (obj->master->type == 0x16) { id = obj->id; if (this->list16.checkObjectInList(1, &id) != 1) this->list16.addImportantObject(id); }
        if (obj->master->type == 0x15) { id = obj->id; if (this->list15.checkObjectInList(1, &id) != 1) this->list15.addImportantObject(id); }
        return;
    }
    if (m->id == 0x9f) {
        if (this->player->world->difficultyLevel() < 4) {
            this->special.addImportantObject(obj->id);
        }
    }
}
