// VA: 004CB710 TRIBE_Combat_Object::trade (EH-framed)
// PDB source: t_c_obj.cpp, lines 1111-1163
// FLAGS: /nologo /c /O2 /Oy /GX
// ACCEPTED_DRIFT: remaining ~22% positional diff is purely register allocation
//   (this in esi instead of edi, obj in edi instead of esi). All instruction
//   patterns, control flow, call sequences, and EH cookie tracking match.
//   No behavioral differences. Register choice is benign VC5 codegen variance.
//
// Attempt log:
// - Initial version: early returns -> 70% diff (inlined SEH epilogues)
// - goto-based shared exit -> 22% diff (register allocation only)
// - Tried removing self/dispatch locals, changing expression order, adding
//   VTableDispatch local, chaining get_action() calls. Register allocation
//   is baked into VC5's allocator decision and doesn't flip with source changes.
// - sizeof(RGE_Action) and sizeof(RGE_Action_Trade) corrected to 0x40 and 0x48
//   for proper `new` expression codegen.
// - get_action() calls must be chained (not saved to local) to match original's
//   repeated call pattern.

typedef unsigned char uchar;

class RGE_Game_World;
class RGE_Task;

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    void* master_obj;
    void* owner_player;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Game_World {
public:
    char gap_00[0x88];
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class RGE_Action_List {
public:
    uchar have_action();
    int get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(void* param_1);
    virtual int setup(int param_1, void* param_2);
    virtual void* create_action_list(void* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(uchar param_1);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual uchar attack_response(RGE_Static_Object* param_1);
    virtual uchar relation_response(long param_1, uchar param_2);
    virtual void copy_obj(void* param_1);
    virtual void copy_obj_sprites(void* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj();

    char gap_04[0x3C];
};

class RGE_Action_Trade : public RGE_Action {
public:
    char gap_40[8];

    RGE_Action_Trade(void* obj, RGE_Task* task, RGE_Static_Object* target);
};

struct VTableProxy {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6C();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7C();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8C();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9C();
    virtual void sA0();
    virtual void sA4();
    virtual void sA8();
    virtual void sAC();
    virtual void sB0();
    virtual void sB4();
    virtual void sB8();
    virtual void sBC();
    virtual void sC0();
    virtual void sC4();
    virtual void sC8();
    virtual void sCC();
    virtual void sD0();
    virtual void sD4();
    virtual void sD8();
    virtual void sDC();
    virtual void sE0();
    virtual void sE4();
    virtual void sE8();
    virtual void sEC();
    virtual void sF0();
    virtual void sF4();
    virtual void sF8();
    virtual void sFC();
    virtual void s100();
    virtual void s104();
    virtual void s108();
    virtual void s10C();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11C();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12C();
    virtual void s130();
    virtual void s134();
    virtual void s138();
    virtual void s13C();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14C();
    virtual void s150();
    virtual void s154();
    virtual void s158();
    virtual void s15C();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16C();
    virtual void s170();
    virtual void s174();
    virtual void s178();
    virtual void s17C();
    virtual void s180();
    virtual void s184();
    virtual void s188();
    virtual void s18C();
    virtual void s190();
    virtual void s194();
    virtual void s198();
    virtual void s19C();
    virtual void s1A0();
    virtual void s1A4();
    virtual void s1A8();
    virtual void s1AC();
    virtual void s1B0();
    virtual void s1B4();
    virtual void s1B8();
    virtual void s1BC();
    virtual void s1C0();
    virtual void s1C4();
    virtual void s1C8();
    virtual void s1CC();
    virtual void s1D0();
    virtual void s1D4();
    virtual void s1D8();
    virtual void s1DC();
    virtual void s1E0();
    virtual void s1E4();
    virtual void s1E8();
    virtual void s1EC();
    virtual void s1F0();
    virtual void s1F4();
    virtual void s1F8();
    virtual void s1FC();
    virtual void s200();
    virtual void s204();
    virtual void call208(void* arg);
    virtual void s20C();
    virtual RGE_Task* call210(RGE_Static_Object* obj, float x, float y, float z);
};

class CombatObject {
public:
    void* vtable_ptr;
    int id;
    void* master_obj;
    void* owner_player;
    char gap_10[0x184 - 0x10];
    RGE_Action_List* actions;

    int trade(int param_1, int param_2);
};

int CombatObject::trade(int param_1, int param_2)
{
    RGE_Static_Object* obj;
    RGE_Task* task;
    RGE_Action_Trade* new_action;

    obj = ((RGE_Game_World*)*(void**)((char*)this->owner_player + 0x3C))->object(param_1);
    if (obj == 0) {
        goto exit_return;
    }

    if (param_2 == 0) {
        if (this->actions->have_action() == 1) {
            if (((RGE_Action*)this->actions->get_action())->get_target_obj() == obj) {
                if (((RGE_Action*)this->actions->get_action())->type() == 0x6F) {
                    goto exit_return_one;
                }
            }
        }
    }

    if (this->actions->have_action() == 1) {
        if (((RGE_Action*)this->actions->get_action())->type() == 0x6F) {
            ((RGE_Action*)this->actions->get_action())->work(obj, obj->world_x, obj->world_y, obj->world_z);
            goto exit_return_one;
        }
    }

    task = ((VTableProxy*)this)->call210(obj, obj->world_x, obj->world_y, obj->world_z);
    if (task == 0) {
        goto exit_return;
    }

    new_action = new RGE_Action_Trade(this, task, obj);
    if (new_action == 0) {
        goto exit_return;
    }

    this->actions->delete_list();
    ((VTableProxy*)this)->call208(new_action);

exit_return_one:
    return 1;

exit_return:
    return 0;
}
