// 004C9DA0 TRIBE_Building_Object::update_production_queue
// Attempt log:
// 1: natural implementation from packet/decompiler; /GX required for original EH frame around new+ctor. First compile lacked EH and was 560B because helper functions were outlined and fields were 2 bytes early.
// 2: fix production_queue_count/enabled offsets and inline need counter/send logic: offsets fixed but text still short/no EH frame.
// 3: use ordinary new expression instead of manual operator new + placement new to trigger VC5 EH cleanup around constructor: EH prologue now present, size 608B. Still missing EDI save and action-list list offset/float compare shape differ.
// 4: fix RGE_Action_List list offset to +8 and spell resource check as negated less-than: list/float compare now match original family; body 608B, still 44B short.
// 5: ordinary new now gives correct EH prologue/state stores around constructor; retained /GX flag file.
// 6: remaining blocker: compiler does not save/use EDI like original send paths, and it tail-merges need-counter increments/returns differently, making text shorter.
// 7: resource send paths are behaviorally modeled but original duplicates vtable-load/send/count update blocks with EDI; rebuilt uses EAX/EDX and shared jumps.
// 8: early queue-clear loop and action creation call set look structurally close after field fixes, but broad layout/register drift remains.
// 9: no accepted_drift proposal: check_function cannot compare because rebuilt .text 608 < configured 652, and drift is not localized.
// 10: typed the full Static/Moving/Action/Combat ownership, player attributes,
//     action-list object/list fields, and the RGE_Action/TRIBE_Action_Make_Obj
//     destructor/0x50 layout. This restored EDI/EH/call ABI context.
// 11: branch-local named counter pointers with explicit old/new values preserved
//     the original duplicated global update blocks instead of VC5 tail-merging
//     them into one shared store.
// 12: a positive resource-available guard placed the attr-4 fallback after the
//     action-creation arm, recovering the original far branch/block topology.
// 13: exact after restoring the proven TRIBE_Action_Make_Obj size (0x50); the
//     living source uses no explicit vptr, novtable, inline asm, or raw object
//     offset plumbing. /GX remains required for the constructor EH context.
// Main-agent audit restored canonical player/base-game destructor ownership and
// retained the natural typed queue/resource flow; exact bytes were revalidated.

void* __cdecl operator new(unsigned int);

class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;                     // +0x3C
    char gap_40[0x0A];
    short id;                                  // +0x4A
    short gap_4C;
    float* attributes;                         // +0x50
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void send(int, int, int, int, int); // +0x40
    char gap_44[0xA30];
    int need_counts[256];                        // +0xA34
};

extern RGE_Base_Game* rge_base_game;
extern float DAT_005749F4;

class RGE_Master_Static_Object;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x44];
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_180[0x14];
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[0x3A];
};

struct RGE_Action_Node {
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual char status();                         // +0x0C
    RGE_Action_Object* object;                      // +0x04
    RGE_Action_Node* list;                          // +0x08
    void add_action(RGE_Action* action);
    void remove_action();
};

struct Production_Queue_Record {
    short master_id;
    short unit_count;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char gap_194[0x30];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    char gap_1C4[4];
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    Production_Queue_Record* production_queue;     // +0x1C8
    short production_queue_size;                    // +0x1CC
    short production_queue_count;                   // +0x1CE
    unsigned char production_queue_enabled;         // +0x1D0
    char gap_1D1[3];
    RGE_Action_List* production_queue_actions;      // +0x1D4
    unsigned char production_queue_change_flag;     // +0x1D8
    unsigned char production_queue_auto_paused;     // +0x1D9
    short production_queue_need_attr;               // +0x1DA

    int work_status(short*, short*, short*, char*, int);
    void remove_from_production_queue(short, short);
    void advance_production_queue();
    void update_production_queue();
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    virtual ~TRIBE_Action_Make_Obj();
    unsigned short field_40;
    int work_done;
    int unique_id;
    unsigned char pre_paid;
    unsigned char gap_4D[3];
    TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, unsigned char);
};

void TRIBE_Building_Object::update_production_queue()
{
    short work_target;
    short local_14;
    short local_12;

    if (!this->production_queue_enabled || this->production_queue_count == 0) {
        if (this->production_queue_need_attr == 4) {
            RGE_Player* p = this->owner;
            this->production_queue_need_attr = -1;
            int id = (int)p->id;
            int* count_ptr = &rge_base_game->need_counts[id];
            int old_count = *count_ptr;
            int new_count = old_count - 1;
            *count_ptr = new_count;
        }
        return;
    }

    if (this->work_status(&work_target, &local_12, &local_14, 0, 0) && (work_target == 0x66 || work_target == 0x67)) {
        while (this->production_queue_count > 0) {
            this->remove_from_production_queue(this->production_queue->master_id, -1);
        }
        return;
    }

    RGE_Action_List* actions = this->production_queue_actions;
    if (actions->list == 0) {
        RGE_Player* p = this->owner;
        float* attributes = p->attributes;
        if (!(attributes[0x2C / 4] < attributes[0x80 / 4])) {
            if (this->production_queue_need_attr == 0x20) return;
            this->production_queue_need_attr = 0x20;
            rge_base_game->send(0x7d, (int)p->id, 0x20, 0, 0);
            int id = (int)this->owner->id;
            int* count_ptr = &rge_base_game->need_counts[id];
            int old_count = *count_ptr;
            int new_count = old_count + 1;
            *count_ptr = new_count;
            return;
        }
        if (attributes[0x10 / 4] > DAT_005749F4) {
            if (this->production_queue_need_attr == 4) {
                int id = (int)p->id;
                int* count_ptr = &rge_base_game->need_counts[id];
                int old_count = *count_ptr;
                int new_count = old_count - 1;
                *count_ptr = new_count;
            }
            this->production_queue_need_attr = -1;
            TRIBE_Action_Make_Obj* act = new TRIBE_Action_Make_Obj(
                this, this->production_queue->master_id, -1, 1);
            if (act) {
                this->production_queue_actions->add_action(act);
            }
        } else {
            if (this->production_queue_need_attr == 4) return;
            this->production_queue_need_attr = 4;
            rge_base_game->send(0x7d, (int)p->id, 4, 0, 0);
            int id = (int)this->owner->id;
            int* count_ptr = &rge_base_game->need_counts[id];
            int old_count = *count_ptr;
            int new_count = old_count + 1;
            *count_ptr = new_count;
            return;
        }
    }

    char st = this->production_queue_actions->status();
    if (st == 3 || st == 2 || st == 1) {
        this->production_queue_actions->remove_action();
        this->advance_production_queue();
    }
}
