// VA: 0049CCB0 command_select_building (307B)
// scr_game.cpp:5478-5512
// Natural reconstruction from the executable and same-TU command_view_tribe:
// choose the command object id, preserve the currently selected matching object
// as the find_obj continuation, then select the result and update both views.
// The repeated get_player() expressions are intentional: the original reloads
// the global player for each member call rather than carrying one local.
// Attempt log (sa-66340ab1-command_select_building):
// - baseline typed reconstruction reached exact size, frame, calls, and CFG but
//   left 24 bytes: the common local continuation emitted xor eax,eax and delayed
//   the selected-object push until after the receiver global load.
// - duplicated the natural find_obj call in the null and matching continuation
//   arms. VC5 tail-merged the call while preserving push-before-get_player order;
//   this reached an exact 307-byte match with all 17 call sites aligned.
// - Main-agent audit restored canonical polymorphic object/player/game/view
//   ownership; exact bytes were revalidated after promotion.

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x04];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x12C];
    RGE_Static_Object* selected_obj;

    void unselect_object();
    int select_object(RGE_Static_Object* obj);
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
};

class TRIBE_Player : public RGE_Player {
public:
    RGE_Static_Object* find_obj(short master_id, RGE_Static_Object* after);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int get_paused();
    TRIBE_Player* get_player();
};

class RGE_ViewLike {
public:
    virtual ~RGE_ViewLike();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int value);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    RGE_ViewLike* main_view;

    void command_select_building(int value);
};

void TRIBE_Screen_Game::command_select_building(int value) {
    int object_id;

    if (rge_base_game->get_paused() == 0) {
        switch (value) {
        case 0:
            object_id = 0x6D;
            break;
        case 1:
            object_id = 0x0C;
            break;
        case 2:
            object_id = 0x2D;
            break;
        case 3:
            object_id = 0x57;
            break;
        case 4:
            object_id = 0x31;
            break;
        case 5:
            object_id = 0x65;
            break;
        case 6:
            object_id = 0x68;
            break;
        case 7:
            object_id = 0;
            break;
        default:
            return;
        }

        RGE_Static_Object* selected = rge_base_game->get_player()->selected_obj;
        RGE_Static_Object* obj;
        if (selected == 0 ||
            rge_base_game->get_player()->selected_obj->master_obj->id != object_id) {
            obj = rge_base_game->get_player()->find_obj((short)object_id, 0);
        } else {
            obj = rge_base_game->get_player()->find_obj(
                (short)object_id, rge_base_game->get_player()->selected_obj);
        }
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc(
                (short)(int)obj->world_x, (short)(int)obj->world_y);
            this->main_view->vf20(1);
        }
    }
}
