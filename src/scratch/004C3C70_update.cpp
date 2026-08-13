// VA: 004C3C70 RGE_Static_Object::update()
// Attempt log:
// 1: natural packet/decompiler implementation with raw __thiscall casts failed VC5 (__thiscall keyword reserved).
// 2: switched to real virtual declarations/padding and typed layout so VC5 emits thiscall vtable calls naturally; compiles but prologue/register pressure badly off.
// 3: made return byte volatile to try to recover original stack return slot; recovered sub esp but extra early pushes remain.
// 4: corrected virtual slot padding from class-interface reference: update vt[9], check_damage_sprites vt[10], new_sprite vt[14], set_object_state vt[23], spawn_death_obj vt[46], owner dopple vt[55/56]; fixed owner/self vtable call offsets but not prologue/register pressure.
// 5: used real `new int[bytes/4]`/`delete[]` instead of raw operator declarations to avoid linkage conflict; call shape compiles but allocation-family scheduling is still not original.
// 6: kept local Raw overlay because full virtual class fields would shift +08/+0c object/master/owner offsets; direct virtual methods plus Raw overlay is behaviorally right but raises liveness.
// 7: checked class-interface reference for `new_sprite`/`set_object_state`/`spawn_death_obj` rather than guessed vtable layout; remaining mismatch no longer due to those offsets.
// 8: tried natural switch with fallthrough case 2->0; switch family still emits too much early callee-save pressure because later virtual calls are visible to optimizer.
// 9: tried volatile return byte to preserve original stack byte at [esp+7]/[esp+13]/[esp+1f]; this helped frame creation but not delayed EBX/EBP/EDI saves.
// 10: left in scratch: first mismatch is extra early push ebx/push ebp/push edi after `sub esp,8`; original delays those until after goto_sleep fast path. Remaining broad drift is register/liveness and block placement, not accepted-drift-safe.
// r1 baseline: canonical owner/master/group fields and the natural group/state update reconstruction built at 836 bytes; first mismatch was the prologue.
// r1 ABI: removed one speculative virtual slot so the final state helper calls observed vslot +B8, not +BC.
// r1 layout: used direct operator_new(byte_count)/operator_delete and corrected owner world +3C/id +4A from exact stat_obj donors; rebuilt size fell to 828 bytes.
// r1 control-flow: inverted inside_obj guard so the null-state switch stays inline and the non-null set_state path is the shared out-of-line tail; calls became fully ordered.
// r1 diagnostics: named ManagedArray syntax, volatile return/group reads, and
// an i+1-only capacity expression changed the VC5 basin without exact structure.
// The final source removes all fake volatility.
// r1 pause: best retained source is typed owner/allocation plus raw group overlay; remaining drift is broad delayed-save/register allocation and group-loop topology, not accepted-drift-safe.
// shardD5_4C3C70 control-flow: made non-sleep state arms assign ret and break to one final return, matching the original shared epilogue and stack-byte home; diff improved to 668/812 bytes with exact frame/saved-esi, but the first structural gap is the group-loop duplicate guard at +005C and the rebuilt body is 55 bytes too large.
// Main-agent policy audit removed fake volatile return storage and named the
// string/float globals. The natural source is now exactly 757 bytes with all
// 17 calls, but VC5 omits the original 0x8 frame. It remains in scratch.

typedef unsigned char uchar;
typedef unsigned long uint;

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" void __cdecl debug_srand(char* file, int line, int seed);
extern int debug_random_on;
extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);
extern char STR_STAT_OBJ[];
extern const float F_ZERO;
extern const float F_ONE;

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_a)
#define VPAD4(n) VPAD2(n) VPAD2(n##_b)
#define VPAD8(n) VPAD4(n) VPAD4(n##_c)
#define VPAD16(n) VPAD8(n) VPAD8(n##_d)
#define VPAD32(n) VPAD16(n) VPAD16(n##_e)

class RGE_Static_Object;
class RGE_Game_World { public: char gap[0x7C]; short curr_player; char gap2[6]; float attr_rate; RGE_Static_Object* object(int id); };
class RGE_Sound { public: void play(int); };

class RGE_Owner {
public:
    VPAD32(o0) VPAD16(o32) VPAD4(o48) VPAD2(o52) VPAD1(o54)
    virtual void* dopple_on(RGE_Static_Object* o, int one, int flag);
    virtual void dopple_off(RGE_Static_Object* o, int zero, int flag, RGE_Static_Object* node);
    char gap0[0x38]; RGE_Game_World* world; char gap44[0x0A]; short id;
};

class RGE_Master_Static_Object { public: char gap0[0x1C]; int death_sprite; int undead_sprite; uchar undead_flag; char gap25[0x1B]; RGE_Sound* death_sound; char gap44[0x3C]; float decay; char gap84[0x20]; uchar recyclable; };

class RGE_Static_Object {
public:
    VPAD8(s0) VPAD1(s8)
    virtual uchar update();
    virtual void vf28();
    VPAD1(s11) VPAD1(s12) VPAD1(s13)
    virtual void set_sprite(int sprite);
    VPAD8(s15)
    virtual void set_state(int state);
    VPAD16(s24) VPAD4(s40) VPAD2(s44)
    virtual void vf_b8();

    RGE_Master_Static_Object* master_obj; // +04? actually after vptr, need +08 target impossible with virtual class if fields begin +4
    RGE_Master_Static_Object* master_obj2;
    RGE_Owner* owner;
};

struct Raw {
    void** vtbl; char gap04[4]; RGE_Master_Static_Object* master_obj; RGE_Owner* owner; char gap10[0x10];
    RGE_Static_Object* inside_obj; char gap24[0x0c]; float hp; char gap34[0x10]; float attribute_amount_held;
    uchar object_state; char gap49; uchar dopple_flag; uchar goto_sleep_flag; short attribute_type_held; RGE_Static_Object* player_object_node;
    char gap54[0x10]; int* group_values; int group_number; char gap6c[4]; int group_max;
};

uchar RGE_Static_Object::update()
{
    Raw* self = (Raw*)this;
    uchar ret = 0;
    if (self->goto_sleep_flag != 0) {
        RGE_Owner* own = self->owner;
        self->goto_sleep_flag = 0;
        own->dopple_off(this, 0, self->dopple_flag, self->player_object_node);
        self->player_object_node = (RGE_Static_Object*)self->owner->dopple_on(this, 1, self->dopple_flag);
        return 0;
    }
    if (self->group_number > 0) {
        int i = 0;
        if (self->group_number > 0) {
            uint bytes = 4;
            do {
                if (i > self->group_max - 1) {
                    int newmax = i + 1;
                    int* nv = (int*)operator_new(bytes);
                    if (nv != 0) {
                        int j = 0;
                        if (self->group_max > 0) {
                            do { if (j >= newmax) break; j++; nv[j-1] = self->group_values[j-1]; } while (j < self->group_max);
                        }
                        operator_delete(self->group_values);
                        self->group_values = nv; self->group_max = newmax;
                    }
                }
                int id = self->group_values[i];
                RGE_Static_Object* obj = self->owner->world->object(id);
                if (obj == 0 || ((Raw*)obj)->object_state > 2) {
                    int n = self->group_max; int k = 0;
                    if (n > 0) { int* p = self->group_values; while (*p != id) { k++; p++; if (k >= n) break; } }
                    if (k < n) {
                        if (k < n - 1) { do { int* p = self->group_values; k++; p[k-1] = p[k]; } while (k < self->group_max - 1); }
                        int gn = self->group_number - 1; self->group_number = gn; if (gn < 0) self->group_number = 0;
                    }
                    i--; bytes -= 4;
                }
                i++; bytes += 4;
            } while (i < self->group_number);
        }
    }
    if (self->inside_obj == 0) {
        switch (self->object_state) {
    case 2: this->vf28();
    case 0:
        if (self->hp < F_ONE) {
            this->set_state(3); this->set_sprite(self->master_obj->death_sprite);
            int r = debug_rand(STR_STAT_OBJ, 0x704); int old = debug_random_on; debug_random_on = 0;
            if (self->master_obj->death_sound != 0 && self->owner->id == self->owner->world->curr_player) self->master_obj->death_sound->play(1);
            debug_random_on = old; debug_srand(STR_STAT_OBJ, 0x70e, r);
        } break;
    case 3: case 5:
        if (self->attribute_type_held != -1 && self->attribute_amount_held > F_ZERO) {
            if (self->master_obj->decay > F_ZERO) { self->attribute_amount_held = self->attribute_amount_held - self->owner->world->attr_rate * self->master_obj->decay; if (self->attribute_amount_held < F_ZERO) { self->attribute_amount_held = F_ZERO; } break; }
        }
        if (self->master_obj->undead_flag != 0) { this->set_state(6); this->set_sprite(self->master_obj->undead_sprite); break; }
        this->set_state(7); this->vf_b8(); break;
    case 7: this->set_state(8); break;
    case 8: ret = (self->master_obj->recyclable != 0) + 1; break;
        }
    } else {
        uchar st = ((Raw*)self->inside_obj)->object_state;
        if (st > 2) this->set_state(st);
    }
    return ret;
}
