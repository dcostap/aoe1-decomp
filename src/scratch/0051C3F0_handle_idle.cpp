// VA: 0051C3F0 TRIBE_Panel_Object::handle_idle (1568B)
// tpnl_obj.cpp
// Attempt log:
// try 1: packet-grounded natural control flow with exact field offsets, virtual slots, and typed object surfaces.
// try 2: corrected active field and object layouts; call set now matches, but frame/CFG remain short.
// try 3: added real get_action and corrected child notify slot; all 25 call targets now align.
// try 4: explored local/frame padding and source guard forms; no exact movement beyond 62% shape.
// validated pause state: meaningful code is 1413/1568B, frame 0x84/0x8C, ordered calls
// are 96% with -1/+1 site gaps, and strict diff is 1330B (84.8214%). Structural work remains.

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

class TPanel {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void set_redraw(int value);
    virtual void vf09(); virtual void vf0A(); virtual void vf0B(); virtual void vf0C();
    virtual void vf0D(); virtual void vf0E(); virtual void vf0F(); virtual void vf10();
    virtual void vf11(); virtual void vf12(); virtual long handle_idle();
    char gap_04[0x3C];
    void* child; // +40
    char gap_44[0x28];
    int active; // +6C
    char gap_70[0x84];
};

class RGE_Object_Node { public: char gap_00[0x10]; };
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0x16];
    float los;
};
class RGE_Victory_Conditions { public: long get_victory_points(); };
class RGE_Action { };
class RGE_Action_List { public: RGE_Action* get_action(); };
class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x24 - 0x0C];
    RGE_Object_Node* objects;
    char gap_28[8];
    float hp;
    char gap_34[0x44 - 0x34];
    float attribute_amount;
    unsigned char object_state;
    char gap_49[3];
    short attribute_type;
    unsigned char selected_group;
    char gap_4F;
    unsigned char object_type;
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_50[4];
};

// The action object's vtable has the queried data methods at these slots.  Keep
// the slots explicit so VC5 emits the original indirect calls.
class RGE_Action_View {
public:
    virtual void v00();
    void* owner; // +04
    RGE_Master_Static_Object* master_obj; // +08
    char gap_0C[0x18];
    RGE_Object_Node* objects; // +24
    char gap_28[8];
    float hp; // +30
    char gap_34[3];
    unsigned char selected_group; // +37
    char gap_38[0x0C];
    float attribute_amount; // +44
    unsigned char object_state; // +48
    char gap_49[3];
    short attribute_type; // +4C
    char gap_4E[2];
    unsigned char object_type; // +50
    unsigned char have_action_value;
    unsigned char pad_52[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual void v7D();
    virtual void v7E();
    virtual void v7F();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8A();
    virtual void vf138(void*, void*); // +22C
    virtual void vf139(void*, void*); // +230
    virtual void vf13A(void*, void*); // +234
    virtual void vf13B(void*, void*); // +238
    virtual void v8F();
    virtual void v90();
    virtual void vf13C(void*, void*); // +244
    unsigned char have_action();
};

class RGE_Building_Object : public RGE_Action_View {
public:
    short get_construction_progress();
    void work_status(short*, short*, short*, char*, int);
    int production_queue_status(short*, short*);
};

class TRIBE_Player {
public:
    char gap_00[0x34];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0xF8];
    RGE_Static_Object* object_130;
};
class RGE_Game_World { public: char gap_00[0x40]; TRIBE_Player** players; };
class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
    int playerID(int id);
};
extern RGE_Base_Game* rge_base_game;

class ChildNotify {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void notify(void*, int, int, int);
};
class TRIBE_Panel_Object : public TPanel {
public:
    char gap_F4[0x110 - 0xF4];
    TRIBE_Player* player;
    RGE_Static_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    char gap_121[3];
    RGE_Master_Static_Object* save_obj_type;
    char gap_128[4];
    short save_attr_type;
    char gap_12E[2];
    float save_attr_amount;
    unsigned char save_selected_group;
    char gap_135[3];
    float save_hp;
    RGE_Object_Node* save_list;
    short save_number_of_objects;
    char gap_142[10];
    float save_los;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    char gap_156[2];
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    char save_facet; // +1CC
    char gap_1CD[3];
    float save_angle; // +1D0
    float save_build_pts; // +1D4
    int save_pop; // +1D8
    int save_max_pop; // +1DC
    unsigned char save_object_state; // +1E0
    char gap_1E1[3];
    TRIBE_Player* save_owner; // +1E4
    unsigned char save_have_action; // +1E8
    char gap_1E9[3];
    int save_score[9];
    int save_farm_amt;
    virtual long handle_idle();
    void set_object(RGE_Static_Object*);
    void save_object_info();
};

long TRIBE_Panel_Object::handle_idle()
{
    register TRIBE_Panel_Object* self = this;
    self->TPanel::handle_idle();
    if (self->active == 0) return 0;

    unsigned long now = debug_timeGetTime((char*)0x58B6D4, 0x37C);
    if (now - self->idle_time < self->idle_interval) return 0;
    now = debug_timeGetTime((char*)0x58B6D4, 0x37F);
    self->idle_time = now;

    if (self->mode == 2) {
        for (int i = 1; i < 9; ++i) {
            int p = rge_base_game->playerID(i);
            if (p != 0) {
                long score = rge_base_game->world->players[p]->victory_conditions->get_victory_points();
                if (self->save_score[p] != score) {
                    if (self->child == 0) self->set_redraw(1);
                    self->save_object_info();
                    return 0;
                }
            }
        }
        return 0;
    }

    TRIBE_Player* p = self->player;
    if ((p != 0 && p->object_130 != self->game_obj) || (p == 0 && self->game_obj != 0)) {
        self->set_object(p != 0 ? p->object_130 : 0);
        return 0;
    }

    RGE_Action_View* obj = (RGE_Action_View*)self->game_obj;
    int changed = 0;
    int do_buttons = 0;
    int frame_pad = 0;
    short cur_val = 0;
    short work_target = 0;
    short orig_val = 0;
    float cur_fval = 0;
    short temp = 0;
    short work_type = 0;
    short progress_value = 0;
    float orig_fval = 0;
    char name[100];
    RGE_Building_Object* bldg = (RGE_Building_Object*)obj;
    if (frame_pad != 0) goto finish;
    if (obj == 0) goto finish;

    if ((RGE_Static_Object*)obj->owner == (RGE_Static_Object*)self->save_owner) {
        if (obj->selected_group == self->save_selected_group) {
            RGE_Master_Static_Object* master = obj->master_obj;
            if (master == self->save_obj_type) {
                short n = *(short*)((char*)obj + 8);
                if (n == self->save_number_of_objects) {
                    if (obj->attribute_type != self->save_attr_type ||
                        obj->attribute_amount != self->save_attr_amount ||
                        obj->hp != self->save_hp ||
                        obj->objects != self->save_list ||
                        master->los != self->save_los || master->id == 0x2d) {
                        changed = 1; do_buttons = 1;
                    }
                } else {
                    changed = 1; do_buttons = 1;
                    if (n == 0 || self->save_number_of_objects == 0) do_buttons = 1;
                }
            } else { changed = 1; do_buttons = 1; }
        } else { changed = 1; do_buttons = 1; }
    } else { changed = 1; do_buttons = 1; }

    if (!changed) {
        unsigned char type = obj->object_type;
        if (type > 0x45 && type != 0x5A) {
            if (obj->have_action() != self->save_have_action) { changed = 1; do_buttons = 1; }
            if (!changed) {
                obj->vf138(&orig_val, (float*)((char*)&cur_fval + 2));
                if (orig_val != self->save_armor) { changed = 1; }
                if (!changed) {
                    obj->vf139(&orig_val, (float*)((char*)&cur_fval + 2));
                    if (orig_val != self->save_pierce_armor) { changed = 1; }
                }
                if (!changed) {
                    obj->vf13A(&orig_val, (float*)((char*)&cur_fval + 2));
                    if (orig_val != self->save_weapon) { changed = 1; }
                }
                if (!changed) {
                    obj->vf13B(&temp, (float*)((char*)&cur_fval + 2));
                    if (temp != self->save_weapon_range) { changed = 1; }
                }
                if (!changed) {
                    obj->vf13C(&temp, (float*)((char*)&cur_fval + 2));
                    if (temp != self->save_speed_of_attack) { changed = 1; }
                }
            }
        }
    }

    if (changed && do_buttons) goto finish;
    if (bldg->object_type != 'P') goto finish;
    if (bldg->object_state != self->save_object_state) { changed = 1; do_buttons = 1; }
    if (!changed || !do_buttons) {
        int progress = bldg->get_construction_progress();
        if ((float)progress != self->save_build_pts) {
            changed = 1;
            if ((float)progress > 99.0f) do_buttons = 1;
        }
    }
    if (!changed || !do_buttons) {
        bldg->work_status(&work_type, &work_target, &progress_value, name + 4, 100);
        short work_type2 = work_type;
        if (work_type2 != 0x67 && work_type2 != 0x66 && bldg->production_queue_status(&work_target, &temp) != 0) {
            work_type2 = 0x66;
            orig_fval = (float)temp;
        }
        if (work_type2 == self->save_work_type && work_target == self->save_work_target && progress_value == self->save_progress) {
            int i = 0;
            while (name[i + 4] == self->save_name[i] && name[i + 4] != 0) ++i;
            if (name[i + 4] == self->save_name[i]) goto name_same;
        }
        changed = 1;
        if (work_type2 == self->save_work_type && work_target == self->save_work_target) {
            int i = 0;
            while (name[i + 4] == self->save_name[i] && name[i + 4] != 0) ++i;
            if (name[i + 4] == self->save_name[i]) goto name_same;
        }
        do_buttons = 1;
    }
name_same:
finish:
    if ((!changed || !do_buttons) && self->game_obj->master_obj->id == 0x46) {
        float pop_a = *(float*)((char*)((RGE_Action_View*)self->game_obj)->owner + 0x2C);
        float pop_b = *(float*)((char*)((RGE_Action_View*)self->game_obj)->owner + 0x10);
        if ((int)pop_a != self->save_pop || (int)pop_b != self->save_max_pop) changed = 1;
    }
    if ((!changed || !do_buttons) && (TRIBE_Player*)((RGE_Action_View*)self->game_obj)->owner == self->player &&
        ((RGE_Action_View*)self->game_obj)->master_obj->id == 0x32) {
        RGE_Action* action = ((RGE_Action_List*)((RGE_Action_View*)self->game_obj)->objects)->get_action();
        if (action != 0 && (int)((RGE_Action_View*)self->game_obj)->attribute_amount != self->save_farm_amt) changed = 1;
    }
    if (changed) {
        if (self->child == 0) self->set_redraw(1);
        self->save_object_info();
        if (do_buttons) ((ChildNotify*)self->child)->notify(self, 1, 0, 0);
    }
    return 0;
}
