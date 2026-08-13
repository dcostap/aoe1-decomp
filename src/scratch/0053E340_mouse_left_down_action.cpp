// VA 0053E340 RGE_Main_View::mouse_left_down_action
// vw_main.cpp:461-630
//
// Behavior-first reconstruction from the original switch and same-TU donors.
// The render area, pick record, world/player ownership, and virtual command
// surfaces use the period layout.  The source does not use decompiler offsets.
//
// Attempt log:
// - Prior scratch source had direct helper calls and incorrect player/object
//   fields.  It was not a canonical behavior baseline.
// - Current baseline: restored RGE_View/TPanel render-area ownership, the
//   master-object placement path, selected-object checks, and start-scroll
//   command dispatch from the original ordered call list.
// - Structural probe: kept the local-player and scenario-player placement
//   arms separate.  This restored both alignment and command-place call sites,
//   exact size, and call-target parity.  Broader block order still differs.
// - Nested the paused and allowed-mode guards to restore the shared false
//   return path used by the original.
// - Ordered switch arms by the PDB line bands: selection, placement, scroll,
//   drag, then the default capture path.  This restored all ordered calls.
// - Binary stack offsets identify player+0x130 as the selected object and
//   pick_info.object as the picked static object.  The decompiler tile label
//   was not canonical ownership.
// - Direct object reloads improve the case-15 and case-18 block shape.  The
//   exact donor reference ABI for get_frame produced no useful movement.
// - Widened master_obj_id's local to int; this restored the original size and
//   reduced the strict diff from 755 to 585 bytes.
// - Removed the fallback command-player alias.  Repeated named world/player
//   access restored the original reload topology and reduced the diff to 27.
// - A typed four-short frame aggregate, with max_y before max_x, reduced the
//   remaining local-output drift to 17 bytes.  The candidate stays in scratch.

extern "C" void __cdecl color_log(unsigned char, unsigned char, int);
extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void*, void*);
extern "C" __declspec(dllimport) int __stdcall ScreenToClient(void*, void*);

struct tagPOINT {
    long x;
    long y;
};

struct RGE_Frame_Bounds {
    short min_x;
    short min_y;
    short max_y;
    short max_x;
};

class TDrawSystem {
public:
    char gap_00[0x479];
    unsigned char screen_mode;
};

class TDrawArea {
public:
    TDrawSystem* draw_system;
    void* wnd;
};

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Tile;
class RGE_Sprite;
class RGE_Active_Sprite_List;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Active_Sprite_List {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Sprite {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x2C];
    unsigned char object_state;

    int get_frame(short&, short&, short&, short&);
};

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
    virtual unsigned char alignment(
        float*, float*, RGE_Game_World*, unsigned char);

    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x3C];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
#define PLAYER_VIRTUAL(n) virtual void player_v##n();
    PLAYER_VIRTUAL(01) PLAYER_VIRTUAL(02) PLAYER_VIRTUAL(03)
    PLAYER_VIRTUAL(04) PLAYER_VIRTUAL(05) PLAYER_VIRTUAL(06)
    PLAYER_VIRTUAL(07) PLAYER_VIRTUAL(08) PLAYER_VIRTUAL(09)
    PLAYER_VIRTUAL(10) PLAYER_VIRTUAL(11) PLAYER_VIRTUAL(12)
    PLAYER_VIRTUAL(13) PLAYER_VIRTUAL(14) PLAYER_VIRTUAL(15)
    PLAYER_VIRTUAL(16) PLAYER_VIRTUAL(17) PLAYER_VIRTUAL(18)
    PLAYER_VIRTUAL(19) PLAYER_VIRTUAL(20) PLAYER_VIRTUAL(21)
    PLAYER_VIRTUAL(22) PLAYER_VIRTUAL(23) PLAYER_VIRTUAL(24)
    PLAYER_VIRTUAL(25) PLAYER_VIRTUAL(26) PLAYER_VIRTUAL(27)
    PLAYER_VIRTUAL(28) PLAYER_VIRTUAL(29) PLAYER_VIRTUAL(30)
    PLAYER_VIRTUAL(31) PLAYER_VIRTUAL(32) PLAYER_VIRTUAL(33)
    PLAYER_VIRTUAL(34) PLAYER_VIRTUAL(35) PLAYER_VIRTUAL(36)
    PLAYER_VIRTUAL(37) PLAYER_VIRTUAL(38) PLAYER_VIRTUAL(39)
    PLAYER_VIRTUAL(40) PLAYER_VIRTUAL(41) PLAYER_VIRTUAL(42)
    PLAYER_VIRTUAL(43)
#undef PLAYER_VIRTUAL
    virtual unsigned char command_place_object(
        short, float, float, float);

    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x22];
    short id;
    char gap_4C[0xE4];
    RGE_Static_Object* selected_obj;

    void unselect_object();
    int select_one_object(RGE_Static_Object*, int);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);

    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x240];
    short master_obj_id;

    int get_paused();
    RGE_Player* get_player();
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void panel_v1();
    virtual void panel_v2();
    virtual void panel_v3();
    virtual void panel_v4();
    virtual void panel_v5();
    virtual void panel_v6();
    virtual void panel_v7();
    virtual void set_redraw(int);

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xD0];

    void capture_mouse();
};

class RGE_View : public TPanel {
public:
#define VIEW_VIRTUAL(n) virtual void view_v##n();
    VIEW_VIRTUAL(09) VIEW_VIRTUAL(10) VIEW_VIRTUAL(11)
    VIEW_VIRTUAL(12) VIEW_VIRTUAL(13) VIEW_VIRTUAL(14)
    VIEW_VIRTUAL(15) VIEW_VIRTUAL(16) VIEW_VIRTUAL(17)
    VIEW_VIRTUAL(18) VIEW_VIRTUAL(19) VIEW_VIRTUAL(20)
    VIEW_VIRTUAL(21) VIEW_VIRTUAL(22) VIEW_VIRTUAL(23)
    VIEW_VIRTUAL(24) VIEW_VIRTUAL(25) VIEW_VIRTUAL(26)
    VIEW_VIRTUAL(27) VIEW_VIRTUAL(28) VIEW_VIRTUAL(29)
    VIEW_VIRTUAL(30) VIEW_VIRTUAL(31) VIEW_VIRTUAL(32)
    VIEW_VIRTUAL(33) VIEW_VIRTUAL(34) VIEW_VIRTUAL(35)
    VIEW_VIRTUAL(36) VIEW_VIRTUAL(37) VIEW_VIRTUAL(38)
    VIEW_VIRTUAL(39) VIEW_VIRTUAL(40) VIEW_VIRTUAL(41)
    VIEW_VIRTUAL(42) VIEW_VIRTUAL(43) VIEW_VIRTUAL(44)
    VIEW_VIRTUAL(45) VIEW_VIRTUAL(46) VIEW_VIRTUAL(47)
    VIEW_VIRTUAL(48) VIEW_VIRTUAL(49) VIEW_VIRTUAL(50)
    VIEW_VIRTUAL(51) VIEW_VIRTUAL(52) VIEW_VIRTUAL(53)
    VIEW_VIRTUAL(54) VIEW_VIRTUAL(55) VIEW_VIRTUAL(56)
    VIEW_VIRTUAL(57)
#undef VIEW_VIRTUAL
    virtual int start_scroll_view(unsigned char, long, long, int, int);

    TDrawArea* cur_render_area;
    int calc_draw_count;
    RGE_Game_World* world;
    RGE_Player* player;
    char gap_104[0x70];
    RGE_Static_Object* movable_object;
    char gap_178[0x1E8];
};

extern RGE_Base_Game* rge_base_game;

class RGE_Main_View : public RGE_View {
public:
    char gap_360[0x1C];
    RGE_Player* save_player;

    long mouse_left_down_action(long, long, int, int);
    unsigned char pick1(unsigned char, unsigned char, long, long,
                        RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
};

long RGE_Main_View::mouse_left_down_action(long param_1, long param_2,
                                           int param_3, int param_4)
{
    RGE_Frame_Bounds frame;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            mode = rge_base_game->game_mode;
            color_log(0x4C, 0xBA, 1);

            switch (mode) {
            case 18:
                if (this->pick1(0x29, 0, param_1, param_2,
                                &pick_info, this->player->selected_obj, 1) == 0x34) {
                    this->player->unselect_object();
                    this->player->select_one_object(
                        (RGE_Static_Object*)pick_info.object, 1);
                    this->set_redraw(1);
                    if (((RGE_Static_Object*)pick_info.object)->sprite != 0) {
                        ((RGE_Static_Object*)pick_info.object)->get_frame(
                            frame.min_x, frame.min_y,
                            frame.max_x, frame.max_y);
                        point.x = frame.max_x - frame.min_x;
                        point.y = frame.max_y - frame.min_y;
                        if (this->render_area->draw_system->screen_mode == 1) {
                            ClientToScreen(this->render_area->wnd, &point);
                        }
                        if (this->render_area->draw_system->screen_mode == 1) {
                            ScreenToClient(this->render_area->wnd, &point);
                        }
                        this->start_scroll_view(
                            4, point.x, point.y, param_3, param_4);
                    }
                }
                break;

            case 1:
                if (this->pick1(0x28, 0, param_1, param_2,
                                &pick_info, 0, 1) == 0x33) {
                    this->fixup_pick_info(&pick_info);
                    int object_id = rge_base_game->master_obj_id;
                    if (object_id != -1 &&
                        this->player->master_objects[object_id] != 0) {
                        RGE_Master_Static_Object* master =
                            this->player->master_objects[object_id];
                        master->alignment(&pick_info.x, &pick_info.y,
                                          this->world, 0);
                        this->player->command_place_object(
                            object_id, pick_info.x, pick_info.y, 0.0f);
                    } else if (object_id != -1 && this->world->players[0]
                               ->master_objects[object_id] != 0) {
                        RGE_Master_Static_Object* master =
                            this->world->players[0]->master_objects[object_id];
                        master->alignment(&pick_info.x, &pick_info.y,
                                          this->world, 0);
                        this->world->players[0]->command_place_object(
                            object_id, pick_info.x, pick_info.y, 0.0f);
                    }
                }
                break;

            case 9:
            case 10:
            case 19:
                if (this->player->selected_obj != 0) {
                    this->player->unselect_object();
                    this->set_redraw(1);
                }
                if (mode == 19) {
                    rge_base_game->set_game_mode(19, 0);
                }
                this->start_scroll_view(9, param_1, param_2, param_3, param_4);
                break;

            case 2:
            case 3:
            case 17:
                if (this->player->selected_obj != 0) {
                    this->player->unselect_object();
                    this->set_redraw(1);
                }
                // Fall through.  These modes use the same scroll command as 21.
            case 21:
                this->start_scroll_view(3, param_1, param_2, param_3, param_4);
                break;

            case 15:
                if (this->pick1(0x29, 0, param_1, param_2,
                                &pick_info, this->player->selected_obj, 1) == 0x34) {
                    if (((RGE_Static_Object*)pick_info.object)
                            ->master_obj->object_group != 0x22) {
                        unsigned char draw_level;
                        if (((RGE_Static_Object*)pick_info.object)->sprite_list != 0) {
                            draw_level = ((RGE_Static_Object*)pick_info.object)
                                ->sprite_list->get_lowest_draw_level();
                        } else if (((RGE_Static_Object*)pick_info.object)->sprite != 0) {
                            draw_level = ((RGE_Static_Object*)pick_info.object)
                                ->sprite->get_lowest_draw_level();
                        } else {
                            draw_level = 0x14;
                        }

                        this->save_player = rge_base_game->get_player();
                        rge_base_game->set_player(
                            ((RGE_Static_Object*)pick_info.object)->owner->id);
                        rge_base_game->master_obj_id =
                            ((RGE_Static_Object*)pick_info.object)->master_obj->id;
                        this->movable_object =
                            (RGE_Static_Object*)pick_info.object;
                        ((RGE_Static_Object*)pick_info.object)->object_state = 7;
                        if (draw_level == 0) {
                            this->set_redraw(2);
                        }
                        rge_base_game->set_game_mode(8, 1);
                        if (this->movable_object->sprite != 0) {
                            this->movable_object->get_frame(
                                frame.min_x, frame.min_y,
                                frame.max_x, frame.max_y);
                            point.x = frame.max_x - frame.min_x;
                            point.y = frame.max_y - frame.min_y;
                            if (this->render_area->draw_system->screen_mode == 1) {
                                ClientToScreen(this->render_area->wnd, &point);
                            }
                        }
                        this->start_scroll_view(
                            9, param_1, param_2, param_3, param_4);
                    }
                }
                break;

            default:
                this->capture_mouse();
                break;
            }

            color_log(0x4C, 0x5F, 1);
            return 1;
        }
    }
    return 0;
}
