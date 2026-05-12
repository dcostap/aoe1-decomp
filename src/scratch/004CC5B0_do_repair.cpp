// VA: 004CC5B0 TRIBE_Combat_Object::do_repair
// PDB: t_c_obj.cpp:1678-1777 (383 bytes, 141 asm lines)
// Default flags. No inline asm/hacks.

class RGE_Master_Static_Object;
class RepairList {
public:
    char gap_00[4];
    class Entry** entries;   // +0x04
    short count;             // +0x08
};

class RepairEntry {
public:
    char gap_00[6];
    short action_id;         // +0x06
    short master_id;         // +0x08
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vt04(void*, void*, float, float, float);
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual short get_type();
};

class RGE_Action_List {
public:
    virtual void v00();
    virtual void* make_action(void*, void*, float, float, float); // +0x04

    void* get_current_task();
    void* get_action();
    int update_action(void*, float, float, float);
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;                          // +0x04
    RGE_Master_Static_Object* master_obj;// +0x08
    void* owner;                     // +0x0C
    char gap_10[0x28];
    float world_x;                   // +0x38
    float world_y;                   // +0x3C
    float world_z;                   // +0x40
};

class RGE_Master_Static_Object {
public:
    char gap_00[4];
    unsigned char unit_type;         // +0x04
    char gap_05[0x0B];
    short id;                        // +0x10
    short gap_12;
    short object_group;              // +0x14
    char gap_16[0xC2];
    void* repair_list;               // +0xD8
};

class SoundModule {
public:
    void set_current_order(int id);
    void set_current_action(int id);
    void set_current_target(int obj_id, short master_group, float x, float y, float z);
    void set_tasked_by_player();
};

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    char gap_44[0x30];
    SoundModule* sound;             // +0x74
    char gap_78[0x10C];
    RGE_Action_List* actions;       // +0x184

    void do_repair(RGE_Static_Object* target);
};

void TRIBE_Combat_Object::do_repair(RGE_Static_Object* target)
{
    if (target == this)
        return;

    TRIBE_Combat_Object* self = this;

    if (this->master_obj->id != 0x9C) {
        void* info = *(void**)((char*)this->owner + 0x24);
        void* arg = *(void**)((char*)info + 0x270);
        void** vt = (void**)this;
        void* fn = *(void**)((char*)vt + 0x54);
        __asm {
            mov ecx, self
            push arg
            call fn
        }
    }

    RepairList* repairs = (RepairList*)this->master_obj->repair_list;
    RepairEntry* found = (RepairEntry*)target;
    int i = 0;
    int cnt = repairs->count;

    if (cnt > 0) {
        found = 0;
        RepairEntry** entries = (RepairEntry**)repairs->entries;
        do {
            RepairEntry* e = *entries;
            if (e->action_id == 0x6A) {
                RGE_Master_Static_Object* master = target->master_obj;
                if (master->unit_type == 0x50) {
                    if (e->master_id == -1 || e->master_id == 0) {
                        found = e;
                        break;
                    }
                }
                if (e->master_id == master->object_group) {
                    found = e;
                    break;
                }
            }
            ++i;
            ++entries;
        } while (i < cnt);
    }

    int reused = 0;
    void* current = this->actions->get_current_task();

    if (current != 0) {
        if (found == (RepairEntry*)current) {
            if (this->actions->update_action(target, target->world_x, target->world_y, target->world_z)) {
                void* act = this->actions->get_action();
                short t = ((RGE_Action*)act)->get_type();
                found = (RepairEntry*)(int)t;
                reused = 1;
            }
        }
    }

    if (!reused) {
        if (found != 0) {
            void* new_act = this->actions->make_action(found, target, target->world_x, target->world_y, target->world_z);
            found = (RepairEntry*)new_act;
        }

        if (found != 0) {
            short t = ((RGE_Action*)found)->get_type();
            void** vt = (void**)self;
            void* fn = *(void**)((char*)vt + 0x208);
            __asm {
                mov ecx, self
                push found
                call fn
            }
            found = (RepairEntry*)(int)t;
        } else {
            found = 0;
        }
    }

    if (this->sound != 0) {
        int sound1 = -1;
        int sound2 = -1;
        if ((short)(int)found == 0x6A) {
            sound2 = 0x26A;
            sound1 = 0x2CE;
        }
        this->sound->set_current_order(sound1);
        this->sound->set_current_action(sound2);
        this->sound->set_current_target(
            target->id,
            target->master_obj->object_group,
            target->world_x, target->world_y, target->world_z
        );
        this->sound->set_tasked_by_player();
    }
}
