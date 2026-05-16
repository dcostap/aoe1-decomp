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
// 10: left in scratch after honest attempts.

#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

void* __cdecl operator new(unsigned int);
inline void* operator new(unsigned int, void* p) { return p; }

struct RGE_Player { char pad[0x4a]; short id; char pad4c[4]; struct Stats* stats; };
struct Stats { char pad0[0x10]; float attr; char pad14[0x2c-0x14]; float have; char pad30[0x80-0x30]; float need; };
class RGE_Base_Game { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void send(int,int,int,int,int); char pad[0xa30]; int need_counts[256]; };
class RGE_Action { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual char status(); };
struct RGE_Action_Node { RGE_Action* action; RGE_Action_Node* next; };
class RGE_Action_List { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual char status(); char pad4[4]; RGE_Action_Node* list; void add_action(RGE_Action*); void remove_action(); };
struct ProdItem { short master_id; };
class TRIBE_Building_Object;
class TRIBE_Action_Make_Obj : public RGE_Action { public: TRIBE_Action_Make_Obj(TRIBE_Building_Object*, short, int, int); };

class TRIBE_Building_Object {
public:
    char pad0[0x0c]; RGE_Player* player; char pad10[0x1c8-0x10]; ProdItem* production_queue; char pad1cc[2]; short production_queue_count; unsigned char production_queue_enabled; char pad1d1[3]; RGE_Action_List* production_queue_actions; char pad1d8[2]; short production_queue_need_attr;
    int work_status(short*, short*, short*, char*, int);
    void remove_from_production_queue(short, int);
    void advance_production_queue();
    void update_production_queue();
};

void TRIBE_Building_Object::update_production_queue()
{
    short work_type;
    short progress;
    short work_target;
    short local_14;
    short local_12;

    if (!this->production_queue_enabled || this->production_queue_count == 0) {
        if (this->production_queue_need_attr == 4) {
            RGE_Player* p = this->player;
            this->production_queue_need_attr = -1;
            int id = (int)p->id;
            RGE_Base_Game* g = rge_base_game;
            g->need_counts[id]--;
        }
        return;
    }

    if (this->work_status(&work_target, &local_12, &local_14, (char*)0, 0) && (work_target == 0x66 || work_target == 0x67)) {
        while (this->production_queue_count > 0) {
            this->remove_from_production_queue(this->production_queue->master_id, -1);
        }
        return;
    }

    RGE_Action_List* actions = this->production_queue_actions;
    if (actions->list == 0) {
        RGE_Player* p = this->player;
        Stats* s = p->stats;
        if (!(s->have < s->need)) {
            if (this->production_queue_need_attr == 0x20) return;
            this->production_queue_need_attr = 0x20;
            rge_base_game->send(0x7d, (int)p->id, 0x20, 0, 0);
            {
                int id = (int)this->player->id;
                RGE_Base_Game* g = rge_base_game;
                g->need_counts[id]++;
            }
            return;
        }
        if (s->attr <= 0.0f) {
            if (this->production_queue_need_attr == 4) return;
            this->production_queue_need_attr = 4;
            rge_base_game->send(0x7d, (int)p->id, 4, 0, 0);
            {
                int id = (int)this->player->id;
                RGE_Base_Game* g = rge_base_game;
                g->need_counts[id]++;
            }
            return;
        }
        if (this->production_queue_need_attr == 4) {
            int id = (int)p->id;
            RGE_Base_Game* g = rge_base_game;
            g->need_counts[id]--;
        }
        this->production_queue_need_attr = -1;
        TRIBE_Action_Make_Obj* act = new TRIBE_Action_Make_Obj(this, this->production_queue->master_id, -1, 1);
        if (act) {
            this->production_queue_actions->add_action(act);
        }
    }

    char st = this->production_queue_actions->status();
    if (st == 3 || st == 2 || st == 1) {
        this->production_queue_actions->remove_action();
        this->advance_production_queue();
    }
}
