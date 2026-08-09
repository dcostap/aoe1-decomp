// VA: 0052D4F0 place_line_of_walls (257B)
// tvw_main.cpp, lines 382-418
//
// Attempt log:
// - Reconstructed the period-plausible wall scan: signed unit steps, typed
//   check_placement at vslot 0x20, and TRIBE_Player::make_new_object at vslot
//   0x94. The master id/elevation fields are at +0x10/+0x64.
// - Delayed current-coordinate locals until after the step guards. This
//   reproduces the entry register coloring, frame, calls, and loop/epilogue;
//   the best checkpoint is probe-009-layout (27 strict bytes remain).
// - A shared DAT_00577450 experiment caused a 20-byte frame/codegen drift and
//   was rolled back; the remaining unresolved bytes are the two step-predicate
//   idioms, parameter-home orientation, and the TU's pooled -0.5 constant.

class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char attribute);
    virtual void modify_delta(float amount, unsigned char attribute);
    virtual void modify_percent(float amount, unsigned char attribute);
    virtual void save(int file_handle);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player* player,
        float x,
        float y,
        int* placement,
        unsigned char check_terrain,
        unsigned char elevation,
        unsigned char check_objects,
        unsigned char check_units,
        unsigned char check_buildings,
        unsigned char check_fog);

    char gap_04[0x0C];
    short id;
    char gap_12[0x52];
    unsigned char elevation_flag;
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char status);
    virtual void do_resign(int reason);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int status);
    virtual int isEnemy(int player);
    virtual int isAlly(int player);
    virtual int isNeutral(int player);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player, int stance);
    virtual void loadAIInformation(char* a, char* b, char* c, int d, int e);
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e, float f, float g, float h);
    virtual void processAIOrder(int a, int b, int c, int d, int e, float f, float g, float h);
    virtual void kickAI(int reason);
    virtual int strategicNumber(int number);
    virtual void sendGameOrder(RGE_Static_Object* object, RGE_Static_Object* target, int a, int b, int c);
    virtual void sendAddWaypointCommand(int count, void* points, int flags);
    virtual void processAddWaypointCommand(int count, void* points, int flags);
    virtual void sendPlayCommand(int a, int b, int c);
    virtual void sendPlayCommand(int a, int* b, int c, int d, int e);
    virtual int sendAICommand(int a, int b, int c, int d, int e);
    virtual int objectCostByType(int type);
    virtual void trackUnitGather(int a, int b, int c);
    virtual RGE_Static_Object* make_scenario_obj(float x, float y, float z, int id);
    virtual void scenario_save(int file_handle);
    virtual void scenario_load(int file_handle, long* data, float version);
    virtual void scenario_postsave(int file_handle);
    virtual void scenario_postload(int file_handle, long* data, float version);
    virtual void load(int file_handle);
    virtual void add_attribute_num(short attribute, float amount, unsigned char flag);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file_handle);
    virtual void save2(int file_handle);
    virtual void save_info(int file_handle);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y, float z, int flags);
};

class TRIBE_Player : public RGE_Player {
public:
    virtual RGE_Static_Object* make_new_object(long id, float x, float y, float z, int flags);
};

class TRIBE_Main_View {
protected:
    void place_line_of_walls(
        TRIBE_Player* player,
        TRIBE_Master_Building_Object* master,
        int x1,
        int y1,
        int x2,
        int y2);
};

void TRIBE_Main_View::place_line_of_walls(
    TRIBE_Player* player,
    TRIBE_Master_Building_Object* master,
    int x1,
    int y1,
    int x2,
    int y2) {
    int x;
    int y_skip;
    int x_skip;

    if (x1 == x2) {
        y_skip = 0;
    } else {
        y_skip = (x2 <= x1) ? -1 : 1;
    }

    if (y1 == y2) {
        x_skip = 0;
    } else {
        x_skip = (y2 <= y1) ? -1 : 1;
    }

    x = y1;
    int y = x1;

    for (;;) {
        if (master->check_placement(
                player,
                (float)x + 0.5f,
                (float)y + 0.5f,
                0,
                1,
                master->elevation_flag,
                0,
                1,
                1,
                1) == 0) {
            player->make_new_object(
                (int)(short)master->id,
                (float)x + 0.5f,
                (float)y + 0.5f,
                0,
                1);
        }

        if ((x == x2) && (y == y2)) {
            break;
        }

        x += y_skip;
        y += x_skip;
    }
}
