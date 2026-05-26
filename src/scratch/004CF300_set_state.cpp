// VA: 004CF300 TRIBE_Action_Hunt::set_state
// PDB source: tact_hnt.cpp
// Attempt log:
// - broad switch reconstruction from packet: clear action list, store state, create follow/move/action helpers, update sprites, recurse on failure states.
// - used /GX because original has EH registration around operator new constructor calls; default optimized /O2 /GX compiles but .text is 1248 vs target 1312, too short for extraction.
// - tried /Od /Oy- /GX diagnostically: extracts at target size but 85.37% positional diff from offset 0 due EBP/debug frame, so not viable.
// - restored /O2 /Oy /GX. Give-up: remaining gap needs exact class/virtual surfaces and source-order/constructor EH topology for all state arms; no accepted_drift proposed.

extern void* operator new(unsigned int);
extern void play_sound(int, int, int, int, int, int);
extern int helper_path(int,int,int,int,int,int,int);
extern int check_obj(void*);

struct ActionList { void delete_list(); void add(void*); };
struct ObjType { char pad0[0xe8]; short a,b; char padec[0x124-0xec]; short c; char pad126[0x12a-0x126]; short d; char pad12c[0x138-0x12c]; int e; };
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void set_sprite(void*); char gap4[4]; int id; ObjType* type; void* world; char gap10[0x38-0x10]; int x,y,z; float f44; char state48; void set_type(short,int); void sound(int,int,int,int,int,int); };
struct Target { char pad0[0x38]; int x,y,z; float f44; char state48; };
struct Proto { char pad0[0x14]; short obj_type; char pad16[0x24-0x16]; int res; char pad28[0x38-0x28]; int x; char pad3c[0x44-0x3c]; int snd; };
struct HuntAction {
    void* vt; char gap4[4]; Obj* obj; unsigned char state; char gapd[3]; Target* target1; Target* target2; char gap18[8]; int x,y,z; int timer; Proto* proto; ActionList* list; char gap38[8]; int sound_id;
    void* wait_sprite(); void* run_sprite(); void* attack_sprite(); void set_state(unsigned char); void set_t1(int); void set_t2(int);
};
struct Follow { Follow(Obj*, int, int, int, int, void*); void init(int); };
struct Move { Move(Obj*, Target*, int, void*); void init(int); };
struct Hunt { Hunt(Obj*, Target*, int, int, int, int, short, short, void*); void init(int); };

void HuntAction::set_state(unsigned char s)
{
    list->delete_list(); state = s;
    switch (s) {
    case 1:
        obj->sound(obj->id, obj->id, 0x202, 0x265, sound_id, 0); obj->set_sprite(wait_sprite()); timer = 0xc1200000; return;
    case 2:
        obj->set_sprite(wait_sprite()); set_t1(0); set_t2(0); timer = 0; x = y = z = 0xbf800000; return;
    case 3: { timer = 0; Follow* a = new Follow(obj,x,y,z,proto->res,run_sprite()); if (!a) { set_state(13); return; } a->init(1); list->add(a); return; }
    case 4:
        timer = 0; if (!target1) { set_state(13); return; } x=target1->x; y=target1->y; z=target1->z; if ((unsigned char)target1->state48 <= 2) { set_state(12); return; }
        { Move* m = new Move(obj,target1,proto->res,run_sprite()); if (!m) { set_state(13); return; } list->add(m); m->init(1); return; }
    case 5: { timer = 0; Hunt* h = new Hunt(obj,target1,0,proto->x,proto->res,obj->type->e,obj->type->c,obj->type->d,attack_sprite()); if (!h) { set_state(13); return; } list->add(h); h->init(1); return; }
    case 6: timer = 0; obj->set_sprite(attack_sprite()); return;
    case 7:
        timer = 0; if (obj->type->a != proto->obj_type) obj->set_type(proto->obj_type, 0); obj->set_sprite((void*)proto->x); if (proto->snd) play_sound(1,0,0,0,0,0); return;
    case 8:
        if (!(obj->f44 < *(float*)0x575150)) {
            if (!target2) { if (obj->type->a != -1) set_t2(helper_path((int)obj->world, obj->type->a, obj->type->b, obj->x, obj->y, 1, 2)); else set_t2(0); }
            if (target2) { Move* m2 = new Move(obj,target2,proto->res,run_sprite()); if (!m2) { set_state(13); return; } list->add(m2); m2->init(1); return; }
            obj->sound(obj->id,obj->id,0x203,0x265,0,0); if (!check_obj(obj->world)) set_state(2); else set_state(1); return;
        }
        if (target1 && !(target1->f44 < *(float*)0x575150)) set_t1(0); set_state(3); return;
    case 15: timer=0; obj->set_sprite(wait_sprite()); return;
    default: return;
    }
}
