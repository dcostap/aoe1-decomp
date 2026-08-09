// VA: 0052D1F0 command_place_object (304B)
// tvw_main.cpp
// Attempt log:
//   baseline: canonical pick-info, game/player/view, and master-object
//     surfaces reconstructed from direct calls, vtable slots, and offsets;
//     call set/frame matched but the shared flag push was not yet recovered.
//   behavior: restored pick1's final flag as 1, matching its shared push with
//     the fallback base command and fixing the early branch topology.
//   abi: widened the master object id local from short to int so VC5 emits
//     the original sign-extending EBP load and dword comparisons; exact.
// Main-agent audit confirmed canonical game/player/view/master ownership and
// the binary-backed pick flag and object-id widths; emitted code remains exact.

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Tile;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);

    char gap_04[0x1B0];
    int game_mode;
    char gap_1B8[0x244];
    short master_obj_id;
};

extern int allow_user_commands;
extern RGE_Base_Game* rge_base_game;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player*, float, float, int*, unsigned char, unsigned char,
        unsigned char, unsigned char, unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);

    char gap_04[0x60];
    unsigned char elevation_flag;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;

    unsigned char command_make_building(short, float, float);
};

class RGE_View {
public:
    virtual ~RGE_View();
    char gap_04[0xF8];
    RGE_Game_World* world;
    RGE_Player* player;
};

class RGE_Main_View : public RGE_View {
public:
    virtual int command_place_object(long, long, int);

    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual int command_place_object(long, long, int);
};

int TRIBE_Main_View::command_place_object(long x, long y, int param_3) {
    int object_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Pick_Info pick_info;

    if (allow_user_commands != 0) {
        if (rge_base_game->game_mode != 7) {
            return RGE_Main_View::command_place_object(x, y, 1);
        }

        if (this->pick1(0x28, 0, x, y, &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            object_id = rge_base_game->master_obj_id;
            if (object_id != -1 &&
                (master_obj = this->player->master_objects[object_id]) != 0) {
                master_obj->alignment(&pick_info.x, &pick_info.y,
                                      this->world, 0);
                if (master_obj->check_placement(
                        this->player, pick_info.x, pick_info.y, 0,
                        1, master_obj->elevation_flag, 0, 1, 1, 1) == 0) {
                    if (param_3 != 0 || object_id == 0x6D) {
                        rge_base_game->set_game_mode(0, 0);
                    }
                    if (this->player->command_make_building(
                            object_id, pick_info.x, pick_info.y) != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
