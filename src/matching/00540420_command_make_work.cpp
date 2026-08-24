// VA: 00540420 command_make_work (412B)
// PDB-qualified owner: RGE_Main_View::command_make_work (vw_main.cpp:1852-1909)
// Original body boundary: 00540420-005405BB; next symbol 005405C0.
//
// Baseline reconstruction: the command path first asks the player for the
// selected units, tries the best object target, and then falls back to the
// map-point command.  The three cleanup/update tails are kept separate to
// follow the distinct source line bands in the executable.
//
// Attempt log:
// - baseline: canonical player/object/pick-info ownership and explicit target
//   and fallback tails produced 419B with the correct 0x20 frame, registers,
//   CFG, and call set; fallback-success had one extra overlay reset.
// - control-flow: removed that reset from the successful fallback arm while
//   retaining it on pick failure; exact 412B under default.rsp.

extern "C" void __cdecl free(void*);

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class TShape;
class RGE_Static_Object;
class RGE_Player;
class RGE_Tile;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    char gap_08[0x30];
    float world_x;
    float world_y;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);

    char gap_04[0x58];
    TShape** shapes;
};

extern int allow_user_commands;
extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    virtual void vt_pad_00();
    virtual void vt_pad_01();
    virtual void vt_pad_02();
    virtual void vt_pad_03();
    virtual void vt_pad_04();
    virtual void vt_pad_05();
    virtual void vt_pad_06();
    virtual void vt_pad_07();
    virtual void vt_pad_08();
    virtual void vt_pad_09();
    virtual void vt_pad_10();
    virtual void vt_pad_11();
    virtual void vt_pad_12();
    virtual void vt_pad_13();
    virtual void vt_pad_14();
    virtual void vt_pad_15();
    virtual void vt_pad_16();
    virtual void vt_pad_17();
    virtual void vt_pad_18();
    virtual void vt_pad_19();
    virtual void vt_pad_20();
    virtual void vt_pad_21();
    virtual void vt_pad_22();
    virtual void vt_pad_23();
    virtual void vt_pad_24();
    virtual void vt_pad_25();
    virtual void vt_pad_26();
    virtual void vt_pad_27();
    virtual void vt_pad_28();
    virtual void vt_pad_29();
    virtual void vt_pad_30();
    virtual void vt_pad_31();
    virtual void vt_pad_32();
    virtual void vt_pad_33();
    virtual void vt_pad_34();
    virtual void vt_pad_35();
    virtual void vt_pad_36();
    virtual void vt_pad_37();
    virtual void vt_pad_38();
    virtual void vt_pad_39();
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);

    unsigned char get_selected_objects_to_command(
        RGE_Static_Object*** list_out, short* list_num_out,
        short min_select_level, short object_group,
        short object_id, short unit_level);
};

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void vt_04();
    virtual void vt_08();
    virtual void vt_0C();
    virtual void vt_10();
    virtual void vt_14();
    virtual void vt_18();
    virtual void vt_1C();
    virtual void set_redraw(int);

    char gap_04[0xFC];
    RGE_Player* player;

    void display_object_selection(int, int, int, int);
    void reset_overlay_sprites();
    void add_overlay_sprite(TShape*, int, int, int, int, int,
                            unsigned char*, int, unsigned long);
};

class RGE_Main_View : public RGE_View {
public:
    char gap_104[0x2C];
    int map_scr_x_offset;
    int map_scr_y_offset;

    RGE_Static_Object* pick_best_target(long, long, int*, int);
    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
    void reset_display_object_selection(int);

    virtual int command_make_work(long, long);
};
#endif

int RGE_Main_View::command_make_work(long param_1, long param_2)
{
    RGE_Static_Object** list;
    short list_num;
    int attacking;
    RGE_Pick_Info pick_info;
    RGE_Static_Object* target;
    int result;

    if (allow_user_commands != 0) {
        if (this->player->get_selected_objects_to_command(
                &list, &list_num, -1, -1, -1, -1)) {
            free(list);

            target = this->pick_best_target(param_1, param_2,
                                            &attacking, -1);
            if (target != 0) {
                result = this->player->command_make_work(
                    target, target->world_x, target->world_y);
                if (result != 0) {
                    this->display_object_selection(target->id, 0x5DC, 2, 2);
                }
                this->reset_overlay_sprites();
                this->set_redraw(1);
                rge_base_game->set_game_mode(0, 0);
                return result;
            }

            if (this->pick1(0x28, 0, param_1, param_2,
                            &pick_info, 0, 1) == 0x33) {
                this->fixup_pick_info(&pick_info);
                result = this->player->command_make_work(
                    0, pick_info.x, pick_info.y);
                if (result != 0) {
                    this->reset_display_object_selection(2);
                    this->add_overlay_sprite(
                        rge_base_game->shapes[2], 0,
                        this->map_scr_x_offset + param_1,
                        this->map_scr_y_offset + param_2,
                        0, 0x0F, 0, 2, 0x5A);
                }
                this->set_redraw(1);
                rge_base_game->set_game_mode(0, 0);
                return result;
            }

            this->reset_overlay_sprites();
            this->set_redraw(1);
            rge_base_game->set_game_mode(0, 0);
        }
    }
    return 0;
}
