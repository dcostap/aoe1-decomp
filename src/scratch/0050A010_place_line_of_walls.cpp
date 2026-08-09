// VA: 0050A010, TRIBE_Command::place_line_of_walls (tcommand.cpp:456-503)
//
// Attempt log:
// baseline: clean typed reconstruction using the period class/virtual surface;
//   retained named master fields, parameter-home coordinate swap, and the
//   signed unit-step expressions from the original line routine (291B, exact
//   frame/instruction/call shape, 29 strict bytes).
// reversed endpoint equality operands: 28 strict bytes; retained because the
//   resynchronized endpoint compare was closer without changing behavior.
// modeled pay failure as the binary-proven immediate routine return: 27 bytes;
//   retained, matching the original far failure branch.
// named endpoint-copy/local declaration variants forced an extra ESI save and
//   293B output (261 strict bytes); rolled back. The canonical RGE_Command base
//   surface was restored from same-TU donors and had no codegen movement.
// final unresolved drift is the first endpoint register/home coloring and its
//   resulting FPU stack-slot schedule; call set, CFG, frame, and size are exact.
// Main-agent audit removed the inline empty destructor body and retained the
// canonical command/master virtual declarations; output remains at 27 bytes.

typedef unsigned char uchar;

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Task_List;
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Sound;

class RGE_Player {
public:
    virtual ~RGE_Player();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, uchar attribute);
    virtual void modify_delta(float value, uchar attribute);
    virtual void modify_percent(float value, uchar attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player* player, float x, float y,
                                  int* placement, uchar check_terrain,
                                  uchar elevation, uchar check_objects,
                                  uchar check_units, uchar check_buildings,
                                  uchar check_fog);
    virtual uchar alignment(float* x, float* y, RGE_Game_World* world,
                            uchar value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, uchar flags);

    uchar gap_04[0x0C];
    short id;
    uchar gap_12[0x52];
    uchar elevation_flag;
    uchar gap_65[0x53];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    uchar gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    uchar gap_D8[0x24];
    virtual RGE_Task_List* create_task_list();
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    uchar gap_FC[0x4C];
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    uchar gap_148[0x1C];
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    uchar gap_164[0x18];
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z,
                                             int flags);
};

class TRIBE_Player : public RGE_Player {
public:
    uchar pay_obj_cost(short object_id, float amount, int flag);
};

class RGE_Command {
public:
    virtual void vfunc0() = 0;
    virtual ~RGE_Command();
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;

    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    unsigned int last_order_time;
    void* com_hand;
};

class TRIBE_Command : public RGE_Command {
public:
    void place_line_of_walls(
        TRIBE_Player* player,
        TRIBE_Master_Building_Object* master,
        int object_id,
        int start_x,
        int start_y,
        int end_x,
        int end_y,
        RGE_Static_Object** result);
};

void TRIBE_Command::place_line_of_walls(
    TRIBE_Player* player,
    TRIBE_Master_Building_Object* master,
    int object_id,
    int start_x,
    int start_y,
    int end_x,
    int end_y,
    RGE_Static_Object** result)
{
    int y_skip;
    int x_skip;

    if (end_x == start_x) {
        y_skip = 0;
    } else {
        y_skip = (((int)(end_x <= start_x) - 1) & 2) - 1;
    }

    if (end_y == start_y) {
        x_skip = 0;
    } else {
        x_skip = (((int)(end_y <= start_y) - 1) & 2) - 1;
    }

    int temp = start_x;
    start_x = start_y;
    start_y = temp;

    for (;;) {
        if (master->check_placement(
                player,
                (float)start_y + 0.5f,
                (float)start_x + 0.5f,
                0, 1, master->elevation_flag, 0, 1, 1, 1) == 0) {
            if (player->pay_obj_cost(master->id, 1.0f, 0) == 0) {
                return;
            }

            RGE_Static_Object* object = master->make_new_obj(
                player,
                (float)start_y + 0.5f,
                (float)start_x + 0.5f,
                0,
                object_id);
            if (object != 0 && *result == 0) {
                *result = object;
            }
        }

        if (start_y == end_x && start_x == end_y) {
            break;
        }

        start_y += y_skip;
        start_x += x_skip;
    }
}
