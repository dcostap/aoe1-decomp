// 00514010 TRIBE_Player::random_start
//
// Attempt log:
// - The original rough source used a non-inlined rndpos helper, raw vtable
//   calls, and the wrong +0x24/+0x14c ownership.  The binary identifies those
//   as RGE_Player::master_objects, RGE_Player::objects,
//   RGE_Master_Static_Object::check_placement/make_new_obj, and the normal
//   RGE_Player virtual surface.  This candidate restores those period-shaped
//   typed owners and keeps the random arithmetic in the function so each of
//   the eight debug_rand calls remains a real call site.
// - First clean reconstruction: the prior rough body was 709 rebuilt bytes
//   versus 1268 original, with eight missing debug_rand calls and several
//   wrong call relocations.  The typed/inlined reconstruction is the next
//   structural probe; register tuning is intentionally deferred.
// - Typed/inlined probe: 1348 bytes initially, frame 0x1c, 32/32 ordered calls
//   aligned except for one placement-call site; the source now carries all
//   eight random calls, exact master/object-list ownership, build, object
//   notification, player-ID, and chat calls.
// - Direct master lookup plus do/while, goto, split-declaration, and explicit
//   quotient-delta variants either emitted the same 1354-byte basin or added
//   a duplicate check_placement site; no variant was retained as a source
//   improvement.  The remaining structural gap is VC5 placement-call block
//   sharing and the early push/FPU schedule, not an unresolved field owner.
// - An absolute-address string/rdata relocation experiment reduced unresolved
//   relocations but worsened the function and was rolled back; the living
//   source retains named extern data and the period string expression.
// - Moving the tries < 5000 limit to the outer retry guard and keeping
//   check_placement as the natural break gate removed the duplicated virtual
//   call site: ordered calls are now 32/32 aligned, with a 1294-byte rebuild.
// - Direct integer delta expressions followed by combined float adjustments
//   restore the original four-call evaluation order and stack cleanup.
// - The inner bounds intentionally use map height for x and map width for y;
//   these are the executable's observed field accesses, including its swap.
// - The list fallback intentionally loads list->object without a null guard,
//   matching both original fallback blocks and their proven object lifetime.
// - The fallback map-location call uses the field order that reproduces the
//   original +0x3c then +0x38 conversion sequence; set_view_loc stays natural.
// - Removing the redundant outer player-count guard lets the player loop own
//   its bound and recovers the original single compare and exact 1268-byte body.

typedef unsigned char uchar;

class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual void* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*,
                                  uchar, uchar, uchar, uchar, uchar, uchar);
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar,
                                         RGE_Static_Object*);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map_tiles;
    long map_width;
    long map_height;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2c[0x10];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual unsigned char update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual float teleport(float, float, float);
    virtual void new_sprite(void*); virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*); virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char); virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char); virtual void transform(void*);
    virtual void copy_obj(void*); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die(); virtual void damage();
    virtual void calculateDamage(); virtual void rotate(long); virtual unsigned char can_attack();
    virtual void set_attribute(short, float); virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop(); virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound(); virtual void play_move_sound(); virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj(); virtual void* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(RGE_Static_Object*); virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);

    char gap_04[0x34];
    float world_x;
    float world_y;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    uchar build(float);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*,
                               float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand2(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                 uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);

    char gap_04[0x1e];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    void* doppleganger_creator;
    char* name;
    uchar type;
    uchar gap_49;
    short id;
    char gap_4c[0xc8];
    float view_x;
    float view_y;

    void set_map_loc(short, short);
    void set_view_loc(float, float);
};

class TRIBE_Player : public RGE_Player {
public:
    virtual void random_start();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int multiplayerGame();
    int randomGame();
    int playerID(int);
};

class TChat {
public:
    void setInChatGroup(int, int);
};
#endif

extern "C" int __cdecl debug_rand(char*, int);
extern float DAT_00576828;
extern float DAT_00576868;
extern float DAT_0057686c;

extern RGE_Base_Game* rge_base_game;
extern TChat* chat;

void TRIBE_Player::random_start()
{
    uchar found_ally = 0;

    if (this->objects->list == 0) {
        float w1;
        float h;
        w1 = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x631) *
                      (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf)
              - DAT_00576868;
        h = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x632) *
                     (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf)
             - DAT_00576868;
        int tries = 1;
        while (tries < 5000) {
            if (this->master_objects[0x6d]->check_placement(
                    this, h - DAT_00576868, w1 - DAT_00576868,
                    0, 0, 1, 1, 1, 1, 1) == 0)
                break;
            w1 = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x631) *
                          (this->world->map->map_height - 0x1e)) / 0x7fff + 0xf)
                         - DAT_00576868;
            h = (float)((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x632) *
                         (this->world->map->map_width - 0x1e)) / 0x7fff + 0xf)
                - DAT_00576868;
            ++tries;
        }

        if (tries < 5000) {
            TRIBE_Building_Object* town_center_object =
                (TRIBE_Building_Object*)this->master_objects[0x6d]->make_new_obj(
                    this, h, w1, 0);
            this->set_map_loc((short)h, (short)w1);
            this->set_view_loc(h, w1);
            town_center_object->build(10000.0f);

            int count = 3;
            int x_delta;
            int y_delta;
            float x;
            float y;
            do {
                uchar bad = 1;
                do {
                    x_delta = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x646) * 6) /
                              0x7fff - 3;
                    y_delta = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x647) * 6) /
                              0x7fff - 3;
                    x = (float)x_delta -
                        (float)debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x648) * DAT_0057686c + w1;
                    y = (float)y_delta -
                        (float)debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x649) * DAT_0057686c + h;

                    if (x >= DAT_00576828 && x < (float)this->world->map->map_height &&
                        y >= DAT_00576828 && y < (float)this->world->map->map_width &&
                        this->master_objects[0x53]->check_placement(
                            this, y, x, 0, 0, 1, 1, 1, 1, 1) == 0) {
                        this->master_objects[0x53]->make_new_obj(this, y, x, 0);
                        bad = 0;
                    }
                } while (bad);
                --count;
            } while (count != 0);
        }
    } else {
        RGE_Static_Object* town_center_object =
            this->objects->find_by_master_id(0x6d, 0.0f, 0.0f, 0, 0, 0);
        if (town_center_object == 0) {
            town_center_object = this->objects->list->object;
        }
        this->set_map_loc((short)town_center_object->world_x,
                          (short)town_center_object->world_y);
        this->set_view_loc(town_center_object->world_x,
                           town_center_object->world_y);
    }

    if (rge_base_game->multiplayerGame() || rge_base_game->randomGame()) {
        for (int i = 1; i < this->world->player_num; ++i) {
            if (this->isAlly(i) && i != this->id) {
                RGE_Static_Object* town_center_object =
                    this->objects->find_by_master_id(0x6d, 0.0f, 0.0f, 0, 0, 0);
                if (town_center_object == 0) {
                    town_center_object = this->objects->list->object;
                }
                if (town_center_object != 0) {
                    town_center_object->explore_terrain(this->world->players[i], 0, -1);
                    town_center_object->unexplore_terrain(this->world->players[i], 0, -1);
                }
                this->world->players[i]->make_new_object(
                    0x70, this->view_x, this->view_y, 0, 0);
                found_ally = 1;
            }
        }
    }

    if (this->world->curr_player == this->id && found_ally) {
        for (int i = 1; i < this->world->player_num; ++i) {
            if (i != this->id) {
                for (int j = 1; j < 9; ++j) {
                    if (rge_base_game->playerID(j) == i) {
                        chat->setInChatGroup(j, this->isAlly(i));
                    }
                }
            }
        }
    }
}
