// 00403110 RGE_Action_Gather::set_state
// ACT_GATH.cpp
// Attempt log:
// try 1: broad reconstruction from packet: delete child action list, set state byte, switch over gather states, spawn move/action children, update target sprites/commands.
// try 2: used /GX because original has explicit EH registration and new-child unwind state stores.
// try 3: modeled initial list->delete_list(), state byte store at +0x0C, and switch on states 1..15.
// try 4: modeled state 1 idle/reset: get_wait_sprite, clear target/overlay, set x/y/z to -1.0f.
// try 5: modeled state 2 immediate sprite command with opcodes 0x202/0x261, timer=-10.0f, then wait-sprite path.
// try 6: modeled state 3 new ActionMove(0x44) with state tracking, get_speed/resourceDef speed, active flag, and list add/fail-to-state-13 path.
// try 7: modeled state 4 target-position copy then new ActionWork with list add/active and failure state 13.
// try 8: modeled state 6 resourceDef sprite/frame update and resource owner callback; exact direct 004BC310 call is represented through a helper declaration.
// try 9: modeled state 7 gather/dropoff logic: amount comparison, overlay path_or_sprite creation, dropSite child action, and fallback sprite command/state 13.
// try 10: fixed compile-surface issues by removing explicit operator new/delete declarations and expanding Sprite/Object stubs for id/frame/query fields.
// try 11: /GX compile gives exact size 1087B but broad mismatch (77.64% positional), first mismatch at prologue because rebuilt saves EBX and uses +0x30 list offset while original saves only ESI/EDI and uses +0x34; default no-/GX is size-short 960B, so /GX flag retained.
// left in scratch: EH/new-child broad structure is present and size matches under /GX, but class layout (list at +0x34 vs local stub), state switch/source ordering, virtual call surfaces, and child action constructors are still wrong. No accepted_drift: broad prologue/register/control-flow mismatch.

class ActionList { public: void delete_list(); void add(void*); };
class Sprite { public: void* vtbl; int id; void* player; char gap0c[0x38-0x0c]; float x; float y; float z; float amount; void* type; char gap48[0x4c-0x48]; short frame; void set_sprite(void*); void set_overlay(void*); void set_state(int); void move_to(float,float,int,int,int,int,int,int); int query(); };
class Object { public: void* vtbl; int id; void* player; char gap0c[0x38-0x0c]; float x; float y; float z; float amount; void* type; char gap48[0x4c-0x48]; short frame; int query(); };
class ActionMove { public: ActionMove(Sprite*,float,float,float,int,int); void set_active(int); };
class ActionWork { public: ActionWork(Sprite*,Object*,int); void set_active(int); };

extern int path_or_sprite(int,int,int,int,int,int,int,int);
extern void call_BC310(void*, int);

class RGE_Action_Gather {
public:
    void* vtbl; char gap04[4]; Sprite* sprite; unsigned char state; char gap0d[3]; Object* target; Object* dropSite; Object* resource;
    float x; float y; float z; float timer; Object* resourceDef; ActionList* list; char gap38[8]; int carryType;
    void set_state(unsigned char s);
    void set_target(Sprite*); void set_overlay(Sprite*); void change_state(int);
    Sprite* get_wait_sprite(); int get_range(); int get_speed();
};

void RGE_Action_Gather::set_state(unsigned char s) {
    list->delete_list();
    state = s;
    switch (s) {
    case 1:
        timer = 0.0f;
        sprite->set_sprite(get_wait_sprite());
        set_target(0); set_overlay(0);
        x = y = z = -1.0f;
        return;
    case 2:
        sprite->move_to(sprite->id, sprite->id, 0x202, 0x261, carryType, 0, 0, 0);
        timer = -10.0f;
        sprite->set_sprite(get_wait_sprite());
        return;
    case 3: {
        timer = 0.0f;
        ActionMove* a = new ActionMove(sprite, x, y, z, resourceDef ? *(int*)((char*)resourceDef+0x24) : 0, get_speed());
        if (!a) { change_state(13); return; }
        a->set_active(1);
        list->add(a);
        return;
    }
    case 4:
        timer = 0.0f;
        if (!target) { change_state(13); return; }
        x = target->x; y = target->y; z = target->z;
        {
            ActionWork* a = new ActionWork(sprite, target, resourceDef ? *(int*)((char*)resourceDef+0x24) : 0);
            if (!a) { change_state(13); return; }
            list->add(a); a->set_active(1); return;
        }
    case 5:
        timer = 0.0f;
        sprite->set_sprite(get_range() ? get_wait_sprite() : 0);
        return;
    case 6:
        timer = 0.0f;
        if (resourceDef && sprite->frame != *(short*)((char*)resourceDef+0x14)) sprite->move_to(sprite->id, sprite->id, 0, 0, *(short*)((char*)resourceDef+0x14), 0,0,0);
        sprite->set_sprite((void*)resourceDef);
        if (resourceDef && *(void**)((char*)resourceDef+0x44)) { call_BC310(*(void**)((char*)resourceDef+0x44),1); return; }
        return;
    case 7:
        if (sprite->amount >= 0.0f) {
            if (!dropSite) {
                Object* t = sprite ? (Object*)sprite : 0;
                if (t && *(short*)((char*)t->type+0xe8) != -1) set_overlay((Sprite*)path_or_sprite(*(short*)((char*)t->type+0xe8),*(short*)((char*)t->type+0xea),(int)t->x,(int)t->y,1,2,t->query(),(int)t));
                else set_overlay(0);
                if (dropSite) {
                    ActionWork* a = new ActionWork(sprite, dropSite, resourceDef ? *(int*)((char*)resourceDef+0x24) : 0);
                    if (!a) { change_state(13); return; }
                    list->add(a); a->set_active(1); return;
                }
                sprite->move_to(sprite->id, sprite->id, 0x203, 0x261, 0, 0, 0, 0);
                change_state(13); return;
            }
        } else {
            if (target && target->amount < 0.0f) {
                if (!sprite->query()) set_target(0);
            }
            change_state(3); return;
        }
        break;
    case 13:
        timer = 0.0f;
        sprite->set_sprite(get_wait_sprite());
        return;
    default:
        break;
    }
}
