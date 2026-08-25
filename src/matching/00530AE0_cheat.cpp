// VA: 00530AE0 TRIBE_World::cheat (1534 B)
// PDB source: tworld.cpp:1395-1606
// Baseline reconstruction: dispatch the multiplayer cheat command, object-list
// actions, player diplomacy checks, and the map visibility actions through the
// period class surfaces proved by the original call sites.
// Attempt log:
// - Baseline had the correct 1534-byte body but omitted two effects calls and
//   factored three repeated kill loops through a helper.
// - Inlined the three object-list loops and restored effects 0xd8 and 0xd9;
//   the result is an exact 1534-byte match with all 44 calls aligned.

#ifndef TWORLD_PHASE2_CONTEXT
class RGE_Base_Game;
class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Effects;
class TRIBE_Command;
class TDrawArea;
class TPanel;
struct tagRECT;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(long);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();

    int allowCheatCodes();
    void set_map_visible(int value);
    void set_map_fog(int value);
};

extern RGE_Base_Game* rge_base_game;
extern unsigned char die_die_die;

class TPanel {
public:
    enum RedrawMode { redraw_none = 0, redraw_local = 1, redraw_all = 2 };

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning();
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode value);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x10];
    short object_group; // +0x14
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x8
    char gap_0C[0x3C];
    unsigned char object_state; // +0x48

    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual void teleport();
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list; // +0x4

    RGE_Static_Object* find_by_master_id(long master_id, float x, float y,
        unsigned char flag1, unsigned char flag2, RGE_Static_Object* object);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status();
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void aiStatus();
    virtual int isEnemy(int player);
    virtual int isAlly(int player);

    char gap_04[0x24];
    RGE_Object_List* objects; // +0x28

    void win_game_now();
    void loss_if_game_on();
};

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save();
    virtual void do_effect(short effect, RGE_Player* player);
};

class TRIBE_Command {
public:
    void command_make(RGE_Static_Object* object, short command);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x1A];
    unsigned char game_end_condition; // +0x1E
    char gap_1F[0x1D];
    short player_num; // +0x3C
    char gap_3E[2];
    RGE_Player** players; // +0x40
    char gap_44[8];
    RGE_Effects* effects; // +0x4C
    char gap_50[8];
    TRIBE_Command* commands; // +0x58
};

class TRIBE_World : public RGE_Game_World {
public:
    void cheat(short player, short cheat_code);
};
#endif

void TRIBE_World::cheat(short player, short cheat_code)
{
    if (rge_base_game->allowCheatCodes() != 0) {
        switch (cheat_code) {
        case 0:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    this->commands->command_make(object, 0x112);
            }
            break;
        case 1:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    this->commands->command_make(object, 0xf8);
            }
            break;
        case 2:
            if (player > 0)
                this->effects->do_effect(0x7f, this->players[player]);
            break;
        case 3:
            if (player > 0)
                this->effects->do_effect(0x80, this->players[player]);
            break;
        case 4:
            if (player > 0)
                this->effects->do_effect(0x81, this->players[player]);
            break;
        case 5:
            this->effects->do_effect(0x82, this->players[0]);
            break;
        case 6:
            if (player > 0)
                this->effects->do_effect(0x83, this->players[player]);
            break;
        case 7:
            if (player > 0)
                this->effects->do_effect(0x84, this->players[player]);
            break;
        case 8:
            if (player > 0)
                this->effects->do_effect(0x85, this->players[player]);
            break;
        case 9:
            if (player > 0)
                this->effects->do_effect(0x86, this->players[player]);
            break;
        case 10:
            if (player > 0)
                this->effects->do_effect(0x87, this->players[player]);
            break;
        case 11:
            if (player > 0)
                this->effects->do_effect(0x88, this->players[player]);
            break;
        case 12:
            if (player > 0)
                this->effects->do_effect(0x89, this->players[player]);
            break;
        case 13:
            if (player > 0)
                this->effects->do_effect(0x8a, this->players[player]);
            break;
        case 14:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    this->commands->command_make(object, 0x182);
            }
            break;
        case 15:
            if (player > 0)
                this->effects->do_effect(0xd7, this->players[player]);
            break;
        case 16:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    this->commands->command_make(object, 0x18d);
            }
            break;
        case 17:
            if (player > 0)
                this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
            break;
        case 18:
            this->effects->do_effect(0xd8, this->players[0]);
            break;
        case 19:
            this->effects->do_effect(0xd9, this->players[0]);
            break;
        case 100: {
            int i = 1;
            die_die_die = 1;
            if (this->player_num > 1) {
                do {
                    if (i != player || this->players[player]->isAlly(i) == 0 ||
                        this->players[i]->isAlly(player) == 0)
                    {
                        RGE_Object_Node* node = this->players[i]->objects->list;
                        while (node != 0) {
                            RGE_Static_Object* object = node->node;
                            if (object->object_state < 3 &&
                                object->master_obj->object_group != 1)
                                object->die_die_die();
                            node = node->next;
                        }
                    }
                    ++i;
                } while (i < this->player_num);
            }
            break;
        }
        case 101:
            {
                RGE_Object_Node* node = this->players[player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < 3 &&
                        object->master_obj->object_group != 1)
                        object->die_die_die();
                    node = node->next;
                }
            }
            break;
        case 102:
            this->players[player]->win_game_now();
            this->game_end_condition = 0x68;
            break;
        case 103:
            this->players[player]->loss_if_game_on();
            break;
        case 200:
        case 201:
        case 202:
        case 203:
        case 204:
        case 205:
        case 206:
        case 207:
        case 208:
        case 209: {
            int other_player = cheat_code - 200;
            if ((other_player != player ||
                 this->players[player]->isAlly(other_player) == 0 ||
                 this->players[other_player]->isAlly(player) == 0) &&
                this->players[other_player]->objects->list != 0) {
                RGE_Object_Node* node = this->players[other_player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < 3 &&
                        object->master_obj->object_group != 1)
                        object->die_die_die();
                    node = node->next;
                }
            }
            break;
        }
        case 220: {
            RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                0x6d, -1.0f, -1.0f, 1, 2, 0);
            if (object != 0)
                this->commands->command_make(object, 0x174);
            break;
        }
        case 230:
            rge_base_game->set_map_visible(1);
            rge_base_game->get_view_panel()->set_redraw(TPanel::redraw_all);
            rge_base_game->get_map_panel()->set_redraw(TPanel::redraw_all);
            break;
        case 231:
            rge_base_game->set_map_fog(0);
            rge_base_game->get_view_panel()->set_redraw(TPanel::redraw_all);
            break;
        }
    }
}
