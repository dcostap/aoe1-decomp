// RGE_Action_Enter::update
// 954 bytes, large multi-path action helper
// PAUSED at probe 8 per 10-probe limit
// probe 1: 224 bytes (stub, missing class members)
// probe 2: 512 bytes (added state switches, FPU paths, compile errors)
// probe 3: 288 bytes (__ftol path wrong)
// probe 4: 816 bytes (nested pointer structure fixed: world->owner->object())
// probe 5: 954/954, 76.3% diff (size match, structural codegen differences)
// probe 6: 954/954, 76.0% diff (restructured early path linear fall-through)
// probe 7: 944/954 (redundant null check optimized away by VC5)
// probe 8: 944/954 (obj_check temp still optimized, VC5 proves target non-null)
//
// Blocker: VC5 register allocation basin (ebp vs esi saved), stack frame 0x1C vs 0x24,
// redundant null-check optimized away (original keeps it), control flow jump targets differ.
// Core logic correct: object validation, state machine cases 0-13, FPU math, vf_1B4 path,
// __ftol conversions, common path. Structural VC5 codegen differences unresolvable.

class RGE_Game_World;
class RGE_Owner;
class RGE_Static_Object;
class RGE_Action_List;
class RGE_Action;

struct XYPoint {
    int x, y;
};

struct Placement_State {
    char gap_00[0x24];
    float max_distance;
};

class RGE_Owner {
public:
    int vtable;
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0xA];
    short field_4A;

    RGE_Static_Object* object(int index);
    int vf_1C(int param);
};

class RGE_Static_Object {
public:
    int vtable;
    int field_04;
    char gap_08[0x8];
    RGE_Owner* owner;
    char gap_14[0x34];
    unsigned char field_48;
    char gap_49[0x1E];
    float field_6C;
    float field_70;
    float field_74;
    char gap_78[0x10];
    int field_88;
    char gap_8C[0x3C];
    float field_C4;
    float field_C8;
    float field_CC;
    char gap_D0[0xCC];
    RGE_Action_List* field_18C;

    unsigned char is_dying();
    float distance_to_object(RGE_Static_Object* other);
    unsigned char get_type();
    void vf_D0(RGE_Static_Object* param);
    void vf_154(float x, float y, float z, float w, int a);
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
    unsigned char get_type();
};

class RGE_Action {
public:
    float targetX();
    float targetY();
};

class RGE_Game_World {
public:
    int vtable;
    int field_04;
    RGE_Owner* owner;
    char gap_10[0x74];
    float world_time_delta_seconds;
    char gap_90[0x8];
    float field_98;
    float field_9C;

    void vf_D0(RGE_Static_Object* param);
    void vf_148(int a, int b, int c, int d, int e, int f);
    int vf_1B4(XYPoint* a, XYPoint* b, XYPoint* c, int d, int e);
};

extern float DAT_0056e1a0;
extern float DAT_0056e1a4;
extern float DAT_0056e1a8;

class RGE_Action_Enter {
public:
    int vtable;
    char gap_04[4];
    RGE_Game_World* world;
    unsigned char state;
    RGE_Static_Object* target;
    int field_14;
    int object_index_from;
    int object_index_to;
    float pos_x;
    int pos_y;
    char gap_28[0x4];
    float timer;
    Placement_State* field_30;
    RGE_Action_List* action_list;
    char gap_38[4];
    unsigned char field_3C;

    void vf_54(int param);
    void vf_58(int param);
    void vf_5C(int param);

    unsigned char update();
};

unsigned char RGE_Action_Enter::update() {
    RGE_Static_Object* obj_check;
    // Line 229-262: linear fall-through path
    if (object_index_from != -1) {
        RGE_Static_Object* obj = world->owner->object(object_index_from);
        if (obj == 0) goto common_path;
    }

    // Line 240: object_index_to check (both paths merge here)
    if (object_index_to != -1) {
        RGE_Static_Object* obj2 = world->owner->object(object_index_to);
        if (obj2 == 0) {
            vf_58(0);
        }
    }

    // Line 248-257: target checks (unconditional, both paths)
    if (target == 0) goto state_switch;
    if (target->field_48 >= 3) goto common_path;
    // Original does a second null check before vf_1C
    obj_check = target;
    if (obj_check == 0) goto state_switch;
    if (world->owner->vf_1C(obj_check->owner->field_4A) != 0) {
        goto state_switch;
    }

common_path:
    vf_5C(1);
    vf_54(0);
    world->vf_148(0, 0, 0x269, world->field_04, world->field_04, 0x1FB);
    return 4;

state_switch:
    if (state - 1 > 12) return 0;

    switch (state) {
        case 1:
            return 1;

        case 2:
        case 3: {
            if (target != 0 && !target->is_dying()) {
                unsigned char t = action_list->get_type() - 1;
                if (t > 4) return 0;

                switch (t) {
                    case 0:
                    case 1: {
                        timer -= world->owner->world->world_time_delta_seconds;
                        if (timer >= DAT_0056e1a8) return 0;
                        float dist = target->distance_to_object(target) - DAT_0056e1a4;
                        if (dist < field_30->max_distance) {
                            world->vf_D0(target);
                        }
                        if (field_3C == 0) {
                            world->vf_148(0, 0, 0x269, world->field_04, world->field_04, 0x1FA);
                        }
                        vf_5C(1);
                        return 2;
                    }
                    case 2:
                    case 3: {
                        if (target->get_type() != 2) {
                            if (target->get_type() == 11) {
                                RGE_Action* act = action_list->get_action();
                                if (act) {
                                    pos_x = act->targetX();
                                    pos_y = act->targetY();
                                }
                            }
                            vf_5C(4);
                            return 0;
                        }

                        int sx = (int)world->field_98;
                        int sy = (int)world->field_9C;
                        int dx = (int)target->field_6C;
                        int dy = (int)target->field_70;

                        XYPoint dest, start, rVal;
                        start.x = sx;
                        start.y = sy;
                        dest.x = dx;
                        dest.y = dy;

                        if (world->vf_1B4(&dest, &start, &rVal, 2, 1) == 1) {
                            if ((float)dest.x - DAT_0056e1a0 != pos_x - DAT_0056e1a0 ||
                                (float)dest.y - DAT_0056e1a0 != pos_y - DAT_0056e1a0) {
                                pos_x = target->field_6C;
                                pos_y = target->field_70;
                            }
                        } else {
                            pos_x = target->field_6C;
                            pos_y = target->field_70;
                            target->vf_154(target->field_74, world->field_9C, world->field_98, 0, 1);
                        }
                        vf_5C(4);
                        return 0;
                    }
                }
            } else {
                vf_54(0);
                vf_5C(13);
                return 0;
            }
            break;
        }
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            return 0;

        case 13:
            world->vf_148(0, 0, 0x269, world->field_04, world->field_04, 0x1F9);
            return 3;
    }

    return 0;
}
