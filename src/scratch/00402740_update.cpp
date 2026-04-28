// RGE_Action_Enter::update (00402740)
// Flat class layout (no virtual methods, no inheritance)
// Structural fixes correct. Remaining: vtable calls vs direct calls.
//
// probe 1 (flat): 954 bytes, 76.6% diff - clean structural model
// probe 2 (virtual on this): 954 bytes, 80.2% diff - virtual bodies emit as thunks, shifting everything
// probe 3 (pure virtual all classes): 954 bytes, 87.8% diff - RTTI/vtable data clutters section
//
// Lesson: vtable dispatch requires full-class TU context.
// Single-function scratch can't match virtual call patterns because:
//   1. Inline virtual method bodies emit as separate COMDATs before the function
//   2. Pure virtual still generates RTTI/vtable data that shifts alignment
//   3. VC5 needs complete class hierarchy to compute correct vtable offsets
// Fixing this requires broader class definition work (game_types.h / donor TU)

class RGE_Game_World;
class RGE_Owner;
class RGE_Static_Object;
class RGE_Action_List;
class RGE_Action;

struct XYPoint { int x, y; };

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

class RGE_Game_World {
public:
    int vtable;
    int field_04;
    char gap_08[0x8];
    char gap_10[0x74];
    float world_time_delta_seconds;
    char gap_88[0x10];
    float field_98;
    float field_9C;

    RGE_Static_Object* object(int index);
};

class RGE_Static_Object {
public:
    int vtable;
    int field_04;
    char gap_08[0x4];         // owner at 0x0C
    RGE_Owner* owner;
    char gap_10[0x28];        // 0x10-0x37
    float pos_x;              // 0x38
    float pos_y;              // 0x3C
    float pos_z;              // 0x40
    char gap_44[4];
    unsigned char field_48;
    char gap_49[0x23];
    float field_6C;
    float field_70;
    float field_74;
    char gap_78[0x10];
    int field_88;
    char gap_8C[0x3C];
    float field_C4;
    float field_C8;
    float field_CC;
    char gap_D0[0xBC];
    RGE_Action_List* field_18C;

    unsigned char is_dying();
    float distance_to_object(RGE_Static_Object* other);
    unsigned char actionState();
    void enter_obj(RGE_Static_Object* param);
    int firstTileAlongLine(XYPoint* a, XYPoint* b, XYPoint* c, int d, int e, int f);
    int moveTo(int x, int y, float z, float w, int a);
    void notify(int a, int b, int c, long d, long e, long f);
};

class RGE_Action_List {
public:
    int vtable;
    RGE_Action* get_action();
    unsigned char update();
};

class RGE_Action {
public:
    int vtable;
    char gap_04[4];

    float targetX();
    float targetY();
};

class RGE_Action_Enter {
public:
    int vtable;                    // offset 0x00
    char gap_04[4];                // offset 0x04
    RGE_Static_Object* obj;        // offset 0x08
    unsigned char state;           // offset 0x0C
    RGE_Static_Object* target;     // offset 0x10
    int field_14;
    int object_index_from;         // offset 0x18
    int object_index_to;           // offset 0x1C
    float pos_x;                   // offset 0x20
    int pos_y;                     // offset 0x24
    char gap_28[0x4];
    float timer;                   // offset 0x2C
    Placement_State* field_30;     // offset 0x30
    RGE_Action_List* action_list;  // offset 0x34
    char gap_38[4];
    unsigned char field_3C;        // offset 0x3C

    void set_target_obj(RGE_Static_Object* param);
    void set_target_obj2(RGE_Static_Object* param);
    void set_state(unsigned char param);

    unsigned char update();
};

// Stubs
RGE_Static_Object* RGE_Owner::object(int index) { return 0; }
int RGE_Owner::vf_1C(int param) { return 0; }
RGE_Static_Object* RGE_Game_World::object(int index) { return 0; }
unsigned char RGE_Static_Object::is_dying() { return 0; }
float RGE_Static_Object::distance_to_object(RGE_Static_Object* other) { return 0.0f; }
unsigned char RGE_Static_Object::actionState() { return 0; }
void RGE_Static_Object::enter_obj(RGE_Static_Object* param) {}
int RGE_Static_Object::firstTileAlongLine(XYPoint* a, XYPoint* b, XYPoint* c, int d, int e, int f) { return 0; }
int RGE_Static_Object::moveTo(int x, int y, float z, float w, int a) { return 0; }
void RGE_Static_Object::notify(int a, int b, int c, long d, long e, long f) {}
RGE_Action* RGE_Action_List::get_action() { return 0; }
unsigned char RGE_Action_List::update() { return 0; }
float RGE_Action::targetX() { return 0.0f; }
float RGE_Action::targetY() { return 0.0f; }
void RGE_Action_Enter::set_target_obj(RGE_Static_Object* param) {}
void RGE_Action_Enter::set_target_obj2(RGE_Static_Object* param) {}
void RGE_Action_Enter::set_state(unsigned char param) {}

extern float DAT_0056e1a0;
extern float DAT_0056e1a4;
extern float DAT_0056e1a8;

unsigned char RGE_Action_Enter::update() {
    RGE_Static_Object* check_obj;
    XYPoint rVal;
    XYPoint start;
    XYPoint dest;

    if (object_index_from != -1) {
        RGE_Static_Object* o = obj->owner->world->object(object_index_from);
        if (o == 0) goto common_path;
    }

    if (object_index_to != -1) {
        RGE_Static_Object* o = obj->owner->world->object(object_index_to);
        if (o == 0) {
            set_target_obj2(0);
        }
    }

    if (target == 0) goto state_switch;
    if (target->field_48 >= 3) goto common_path;
    check_obj = target;
    if (check_obj == 0) goto state_switch;
    if (obj->owner->vf_1C((int)(short)check_obj->owner->field_4A) != 0) goto state_switch;

common_path:
    set_state(1);
    set_target_obj(0);
    obj->notify(obj->field_04, obj->field_04, 0x1FB, 0x269, 0, 0);
    return 4;

state_switch:
    if (state - 1 > 12) return 0;

    switch (state) {
        case 1:
            return 1;

        case 2:
        case 3: {
            timer -= obj->owner->world->world_time_delta_seconds;
            if (timer > DAT_0056e1a8) return 0;

            float dist = obj->distance_to_object(target) - DAT_0056e1a4;
            if (dist < field_30->max_distance) {
                obj->enter_obj(target);
                goto field_3c_check;
            }

            if (target->actionState() == 2) {
                int sx = (int)obj->pos_x;
                int sy = (int)obj->pos_y;
                int dx = (int)target->pos_x;
                int dy = (int)target->pos_y;

                start.x = sx;
                start.y = sy;
                dest.x = dx;
                dest.y = dy;

                if (obj->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
                    if ((float)dest.x - DAT_0056e1a0 != pos_x - DAT_0056e1a0 ||
                        (float)dest.y - DAT_0056e1a0 != pos_y - DAT_0056e1a0) {
                        pos_x = target->pos_x;
                        pos_y = target->pos_y;
                    }
                } else {
                    pos_x = target->pos_x;
                    pos_y = target->pos_y;
                    target->moveTo((int)obj->pos_x, (int)obj->pos_y, obj->pos_z, 0.5f, 1);
                }
                set_state(4);
                return 0;
            } else if (target->actionState() == 11) {
                set_state(4);
                return 0;
            }

            set_state(4);
            return 0;
        }

field_3c_check:
            if (field_3C == 0) {
                obj->notify(obj->field_04, obj->field_04, 0x1FA, 0x269, 0, 0);
            }
            set_state(1);
            return 2;

        case 4:
            if (target != 0 && !target->is_dying()) {
                unsigned char t = action_list->update() & 0xFF;
                if (t > 5) return 0;

                switch (t) {
                    case 1:
                    case 2: {
                        float d = obj->distance_to_object(target) - DAT_0056e1a4;
                        if (d < field_30->max_distance) {
                            obj->enter_obj(target);
                            goto field_3c_check;
                        }
                        set_state(2);
                        return 0;
                    }

                    case 3:
                        set_state(2);
                        return 0;

                    default:
                        set_target_obj(0);
                        set_state(13);
                        return 0;
                }
            } else {
                set_target_obj(0);
                set_state(13);
                return 0;
            }
            break;

        case 5:  case 6:  case 7:  case 8:
        case 9:  case 10: case 11: case 12:
            return 0;

        case 13:
            obj->notify(obj->field_04, obj->field_04, 0x1F9, 0x269, 0, 0);
            return 3;
    }

    return 0;
}
