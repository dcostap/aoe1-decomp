// VA: 0050D9A0 RGE_Timeline::update (341 B)
// PDB source: Timeline.cpp lines 155-221
// Attempt log:
// 1 (baseline): typed event scan/switch reconstruction; calls and frame matched,
//   but an artificial __int64 time scaffold, early return, and inverted time
//   predicates produced 396 B.
// 2 (behavior): natural common epilogue, unsigned world_time, float 0.001f,
//   positive first-scan and <= event-loop predicates -> 341 B / 33 diff.
// 3 (abi): canonical unsigned world_time explains the original zero-extended
//   qword fild and dword scale; frame and x87 setup became exact.
// 4 (control-flow): spelling entry->time > old_time reproduces the original
//   fld entry-time / fcomp old-time / test ah,41h sequence -> 11 diff.
// 5 (liveness): scoped world alias before player lookup emitted unchanged code.
// 6 (liveness): function-scope player/master/object/scan locals emitted unchanged
//   code; retained as a plausible PDB-era local surface.
// 7 (variant): three natural player-lookup surfaces, size/frame/call-set gated;
//   all remained the same 11-diff group. Remaining drift is jump-table relocation
//   plus case-1 lookup register coloring (original world=ECX/index=EAX).
// Main-agent audit restored canonical polymorphic timeline/world/player/master
// and object ownership; event processing remains an ordinary typed switch.

class RGE_Game_World;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void vf04(); virtual void vf08(); virtual void vf0c();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4c();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c();
    virtual void vf60(); virtual void vf64(); virtual void vf68();
    virtual void vf6c(); virtual void vf70(); virtual void vf74(); virtual void vf78();
    virtual void vf7c(); virtual void vf80(); virtual void vf84(); virtual void vf88();
    virtual void vf8c(); virtual void vf90(); virtual void vf94(); virtual void vf98();
    virtual void move(int, float, float, float);
    virtual void vfA0(); virtual void vfA4();
    virtual void attack(RGE_Static_Object*);
    char gap_04[0x44];
    unsigned char object_state; // +0x48
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object(); virtual void vf04(); virtual void vf08();
    virtual void vf0c(); virtual void vf10(); virtual void vf14();
    virtual RGE_Static_Object* create(RGE_Player*, float, float, int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time; // +0x04
    char gap_08[0x38];
    RGE_Player** players; // +0x40
};

struct RGE_Time_Entry {
    float time;                    // +0x00
    unsigned char command;         // +0x04
    unsigned char gap_05[1];       // +0x05
    short obj_type;                // +0x06
    unsigned char player;          // +0x08
    unsigned char gap_09[3];       // +0x09
    float x;                       // +0x0C
    float y;                       // +0x10
    float z;                       // +0x14
    short task;                    // +0x18
    unsigned char gap_1A[2];       // +0x1A
    RGE_Static_Object* this_obj;   // +0x1C
    short this_obj_id;             // +0x20
    unsigned char gap_22[2];       // +0x22
    RGE_Static_Object* target_obj; // +0x24
    short target_obj_id;           // +0x28
    unsigned char gap_2A[2];       // +0x2A
    RGE_Time_Entry* next;          // +0x2C
};

class RGE_Timeline {
public:
    virtual ~RGE_Timeline();
    RGE_Game_World* world;         // +0x04
    RGE_Time_Entry* time_list;     // +0x08
    short list_num;                // +0x0C
    short avail_id;                // +0x0E
    float old_time;                // +0x10

    void update();
};

void RGE_Timeline::update() {
    RGE_Time_Entry* event = 0;
    RGE_Player* player;
    RGE_Master_Static_Object* master;
    RGE_Static_Object* object;
    RGE_Time_Entry* scan;
    float time = this->world->world_time * 0.001f;
    RGE_Time_Entry* entry = this->time_list;

    if (entry != 0) {
        do {
            if (event == 0 && entry->time > this->old_time)
                event = entry;

            if (entry->this_obj != 0 && entry->this_obj->object_state >= 8)
                entry->this_obj = 0;
            if (entry->target_obj != 0 && entry->target_obj->object_state >= 8)
                entry->target_obj = 0;
            entry = entry->next;
        } while (entry != 0);

        for (; event != 0 && event->time <= time; event = event->next) {
            switch (event->command) {
            case 0:
                if (event->this_obj != 0 && event->target_obj != 0)
                    event->this_obj->attack(event->target_obj);
                break;

            case 1: {
                player = this->world->players[event->player];
                master = player->master_objects[event->obj_type];
                if (master != 0) {
                    object = master->create(player, event->x, event->y, 0);
                    for (scan = this->time_list; scan != 0; scan = scan->next) {
                        if (event->this_obj_id == scan->this_obj_id)
                            scan->this_obj = object;
                        if (event->this_obj_id == scan->target_obj_id)
                            scan->target_obj = object;
                    }
                }
                break;
            }

            case 2:
                if (event->this_obj != 0)
                    event->this_obj->move(0, event->x, event->y, event->z);
                break;

            case 4:
                if (event->this_obj != 0)
                    event->this_obj->vf68();
                break;
            }
        }
    }
    this->old_time = time;
}
