// VA: 00524D70 TRIBE_Game::notification
// PDB: tribegam.cpp:2143-2580
//
// Baseline reconstruction from the executable and the period class/type
// surfaces.  The world/player/panel ownership is named here so the virtual
// calls retain their real ABI and the two message buffers retain their
// observed stack homes.
//
// Attempt log:
// - Baseline matched the 0x200 frame and 3760-byte boundary, but preserved
//   too many independent get_string2/additional tail call sites.
// - Shared goto tails were tried for the two get_string2/show_message groups;
//   the compiler still coalesces their virtual call, so the source is kept as
//   the clearest bounded reconstruction rather than a codegen-only rewrite.
// - Binary argument tracing showed 0x6C/0x6D/0x6E use
//   add_notification_loc(value2, value), with one shared wonder tail; this
//   removed the spurious saved-register basin and raised shape similarity.
// - The disconnected-player path reloads playerID for the name lookup, as in
//   the original's third playerID call.  Final unresolved drift is structural:
//   the jump-table/table-base encoding and several compiler tail merges leave
//   3298 differing bytes (85.29% shape; 89/92 calls; frame and size exact).
// - The call map shows one shared get_string2/show_message block for 0x7D/0x68
//   and a separate block for 0x6B/1/2/3.  Unsharing only the first pair was
//   natural and improved the diff to 2796, but over-emitted one call of each.
//   Separating the second group as well over-emitted five vslot calls; both
//   probes were rolled back to the clean shared-tail reconstruction.
// - Splitting the group-A and group-B selector values into separate typed
//   locals did not change emitted code; restored the shared selector source.
// - Isolating only the 0x7D body was a binary-guided call-tail probe; VC5
//   emitted three vslot+0x28 calls and four show_message calls, so it was
//   rolled back.  The clean source still has the documented five count gaps.

#include <stdio.h>

class TPanel;
class TDrawArea;
class TDrawSystem;
class TShape;
class TSound_Driver;
class TMusic_System;
class TDigital;
class TRegistry;
class TMousePointer;
class TDebuggingLog;
class RGE_Game_Info;
class RGE_Scenario_File_Info;
class RGE_Prog_Info;
class RGE_Font;
class RGE_Scenario;
class RGE_Scenario_Header;
class RGE_Static_Object;
class RGE_Object_Node;
class RGE_Master_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Effects;
class RGE_Command;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Scenario_Info;
class RGE_Player_Info;
class TCommunications_Handler;
class RGE_Game_World;
class TRIBE_World;
class TRIBE_Screen_Game;
class TRIBE_Tech;
class XYZBYTEPoint;

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* name);
    virtual unsigned char data_load_players(char* name);
    virtual unsigned char data_load_objects(char* name);
    virtual unsigned char data_load_sounds(char* name);
    virtual unsigned char data_load_color_tables(char* name);
    virtual unsigned char data_load_sprites(char* name);
    virtual void data_load_players_type(short type, short player, FILE* file);
    virtual void data_load_effects(char* name);
    virtual void data_load_map(char* a, char* b, char* c, char* d,
                               short e, short f, short g, RGE_Sound** sounds,
                               char* h);
    virtual void data_load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char active);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char active, short type);
    virtual void color_table_init(int value);
    virtual void terrain_tables_init(int value);
    virtual void init_sounds(int value, TSound_Driver* driver);
    virtual void init_sprites(int value);
    virtual void map_init(int value, TSound_Driver* driver);
    virtual void effects_init(int value);
    virtual void master_player_init(int value);
    virtual void command_init(int value, TCommunications_Handler* handler);
    virtual void world_init(int value, TSound_Driver* driver,
                            TCommunications_Handler* handler);
    virtual void setup_gaia();
    virtual void setup_players(void* info);
    virtual unsigned char new_random_game(void* info);
    virtual void save(int handle);
    virtual void scenario_make_player(short player, unsigned char a,
                                      unsigned char b, unsigned char c,
                                      char* name);
    virtual void scenario_make_map(int value);
    virtual unsigned char load_scenario(void* info);
    virtual unsigned char load_scenario(char* name, void* info);
    virtual void load_scenario1(int value, void* info);
    virtual void load_scenario2(int value, void* info);
    virtual void load_scenario3(int value, void* info);
    virtual void load_scenario4(int value, void* info);
    virtual void load_scenario5(int value, void* info);
    virtual void load_scenario6(int value, void* info);
    virtual void load_scenario7(int value, void* info);
    virtual void load_scenario8(int value, void* info);
    virtual void logStatus(FILE* file, int value);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(void* info);
    virtual unsigned char data_load(char* a, char* b);
    virtual unsigned char init(char* name, TSound_Driver* driver,
                               TCommunications_Handler* handler);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int handle);
    virtual unsigned char load_game(char* name);
    virtual unsigned char new_game(void* info, int value);
    virtual unsigned char new_scenario(void* info, int value);
    virtual unsigned char save_game(char* name);
    virtual void base_save(char* name);
    virtual void base_save(int handle);
    virtual unsigned char save_scenario(char* name);
    virtual RGE_Scenario* get_scenario_info(char* name);
    virtual void pause(unsigned char value);
    virtual void scenario_init(RGE_Game_World* world);
    virtual void scenario_init(int value, RGE_Game_World* world);
    virtual int addObject(RGE_Static_Object* object);
    virtual int removeObject(int id);

    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    class RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
    char gap_7E[0x86];
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    unsigned char countdown_victory;
    char gap_115[3];
    float countdown_clock;
    unsigned char score_displayed;
    unsigned char controllingComputerPlayer;
    char gap_11E[2];
    int sent_zone_score;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int submode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int id, long value, char* buffer, int length);
    virtual char* get_string(long id, char* buffer, int length);
    virtual char* get_string(long id);
    virtual char* get_string2(int id, long value1, long value2,
                              char* buffer, int length);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);
    virtual RGE_Scenario_Header* new_scenario_header(int value);
    virtual RGE_Scenario* new_scenario_info(int value);
    virtual void notification(int type, long a, long b, long c, long d);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int player, char* cheat);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(void* message);
    virtual int handle_idle();
    virtual int handle_mouse_move(void* window, unsigned int message,
                                  unsigned int wparam, long lparam);
    virtual int handle_key_down(void* window, unsigned int message,
                                unsigned int wparam, long lparam);
    virtual int handle_user_command(void* window, unsigned int message,
                                    unsigned int wparam, long lparam);
    virtual int handle_command(void* window, unsigned int message,
                               unsigned int wparam, long lparam);
    virtual int handle_music_done(void* window, unsigned int message,
                                  unsigned int wparam, long lparam);
    virtual int handle_paint(void* window, unsigned int message,
                             unsigned int wparam, long lparam);
    virtual int handle_activate(void* window, unsigned int message,
                                unsigned int wparam, long lparam);
    virtual int handle_init_menu(void* window, unsigned int message,
                                 unsigned int wparam, long lparam);
    virtual int handle_exit_menu(void* window, unsigned int message,
                                 unsigned int wparam, long lparam);
    virtual int handle_size(void* window, unsigned int message,
                            unsigned int wparam, long lparam);
    virtual int handle_palette_changed(void* window, unsigned int message,
                                       unsigned int wparam, long lparam);
    virtual int handle_query_new_palette(void* window, unsigned int message,
                                         unsigned int wparam, long lparam);
    virtual int handle_close(void* window, unsigned int message,
                             unsigned int wparam, long lparam);
    virtual int handle_destroy(void* window, unsigned int message,
                               unsigned int wparam, long lparam);
    virtual int action_update();
    virtual int action_mouse_move(long x, long y, int a, int b, int c, int d);
    virtual int action_key_down(unsigned long key, int a, int b, int c, int d);
    virtual int action_user_command(unsigned long a, unsigned long b);
    virtual int action_command(unsigned long a, unsigned long b);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

    char gap_04[0x3F0];
    TRIBE_World* world;
    char gap_3F8[0xA24 - 0x3F8];

    int play_sound(int sound_id);
    int playerID(int player);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char status);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int player);
    virtual int isAlly(int player);
    virtual int isNeutral(int player);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player, int stance);
    virtual void loadAIInformation(char* a, char* b, char* c, int d, int e);
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e,
                                 float f, float g, float h, float i,
                                 int j, int k, int l);
    virtual void processAIOrder(int a, int b, int c, int d, int e,
                                float f, float g, float h, float i,
                                int j, int k, int l);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object* a, RGE_Static_Object* b,
                               float c, float d);
    virtual void sendAddWaypointCommand(int a, XYZBYTEPoint* b, int c);
    virtual void processAddWaypointCommand(int a, XYZBYTEPoint* b, int c);
    virtual void sendPlayCommand(int a, int* b, int c, int d, int e);
    virtual void sendPlayCommand(int a, int b, int c);
    virtual int sendAICommand(int a, int b, int c, int d, int e);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int a, int b, int c);
    virtual RGE_Static_Object* make_scenario_obj(float a, float b, float c,
                                                  short d, unsigned char e,
                                                  float f);
    virtual void scenario_save(int value);
    virtual void scenario_load(int value, long* position, float version);
    virtual void scenario_postsave(int value);
    virtual void scenario_postload(int value, long* position, float version);
    virtual void load(int value);
    virtual void add_attribute_num(short id, float amount, unsigned char flag);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int value);
    virtual void save2(int value);
    virtual void save_info(int value);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y,
                                                float z, int value);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int value, int* a, int* b);
    virtual unsigned char command_make_move(RGE_Static_Object* object,
                                            float x, float y);
    virtual unsigned char command_make_work(RGE_Static_Object* object,
                                            float x, float y);
    virtual unsigned char command_make_do(RGE_Static_Object* object,
                                          float x, float y);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short id, float x, float y,
                                                float z);
    virtual unsigned char command_add_attribute(int id, float value);
    virtual unsigned char command_give_attribute(int id, int player,
                                                 float value);
    virtual unsigned char command_formation(int value);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int value, int* ids, int count,
                                               float radius);
    virtual unsigned char command_add_to_group(int group, int object,
                                               float value);
    virtual unsigned char command_remove_from_group(int group, int object);
    virtual unsigned char command_destroy_group(int group);
    virtual unsigned char command_resign(int player, int value);
    virtual unsigned char command_add_waypoint(float x, float y, float z);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* object, int a, int b);
    virtual void removeObject(RGE_Static_Object* object, int a, int b,
                              RGE_Object_Node* node);
    virtual void logMessage(char* message);
    virtual void notify(int player, int to_player, int event,
                        long a, long b, long c);
    virtual void logStatus(FILE* file, int value);
    virtual void load_victory(int value, long* data, unsigned char flag);
    virtual void new_victory();

    unsigned char relation(long player);

    char gap_04[0x40];
    char* name;
    char gap_48[2];
    short id;
    char gap_4C[0xB8];
    unsigned char allied_victory;
    char gap_105[0x11B];
};

class TRIBE_Screen_Game {
public:
    void setup_buttons();
    void show_message(int type, char* text, unsigned char color1,
                      unsigned char color2);
    void display_system_message(char* text);
    void reset_clocks();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x200];
    TRIBE_Screen_Game* game_screen;
    long notification_loc_x[5];
    long notification_loc_y[5];
    long current_notification_loc;
    long current_notification_recalled;
    char gap_C58[0x104];
    char gap_D5C[0x104];
    unsigned long auto_exit_time;
    char gap_E64[0x104];
    char gap_F68[0x100];
    int save_humanity[9];
    unsigned char quick_start_game;
    char gap_1191[3];
    int random_start_value;
    unsigned char computerNameUsed[18][10];
    void* handleIdleLock;
    int inHandleIdle;

    virtual void notification(int type, long a, long b, long c, long d);

    void add_notification_loc(long x, long y);
};

#define player_dropped ((int*)0x86BCA8)

void TRIBE_Game::notification(int type, long player, long value,
                              long value2, long value3)
{
    char msg[256];
    char temp_str[256];
    long string_arg;

    switch (type) {
    case 0x7E:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(0x10);
            this->add_notification_loc(value2, value3);
            return;
        }
        break;

    case 0x7C:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->game_screen->setup_buttons();
            return;
        }
        break;

    case 0x7D:
        if (player == this->world->curr_player && this->game_screen != 0) {
            string_arg = 1;
            goto show_string_group_a;
        }
        break;

    case 0x64:
        if (player == this->world->curr_player && this->game_screen != 0) {
            int sound;
            if (value == 0x65 || value == 0x66 || value == 0x67) {
                sound = 5;
            }
            else {
                sound = 0x0F;
            }
            this->play_sound(sound);
            this->game_screen->setup_buttons();
            this->add_notification_loc(value2, value3);
            return;
        }
        break;

    case 0x66:
    case 0x69:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->game_screen->setup_buttons();
            this->add_notification_loc(value2, value3);
            return;
        }
        break;

    case 0x68:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            string_arg = 1000;
            goto show_string_group_a;
        }
        break;

show_string_group_a:
        this->get_string2(0x67, string_arg, value, msg, 256);
        this->game_screen->show_message(1, msg, 0x55, 0);
        return;

    case 0x6B:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            string_arg = 0x6A;
            goto show_string_group_b;
        }
        break;

    case 1:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            string_arg = 0x66;
            goto show_string_group_b;
        }
        break;

    case 2:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            string_arg = 0x69;
            goto show_string_group_b;
        }
        break;

    case 3:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            string_arg = 0x67;
            goto show_string_group_b;
        }
        break;

show_string_group_b:
        ((RGE_Base_Game*)this)->get_string2(0x67, string_arg, 0, msg, 256);
        this->game_screen->show_message(1, msg, 0x55, 0);
        return;

    case 4:
        if (this->playerID((int)player) != this->world->curr_player &&
            this->game_screen != 0 && player_dropped[player] == 0) {
            player_dropped[player] = 1;
            this->play_sound(7);
            if (this->playerID((int)player) > 0) {
                this->get_string(0xBC4, temp_str, 256);
                sprintf(msg, temp_str,
                        this->world->players[this->playerID((int)player)]->name);
                this->game_screen->display_system_message(msg);
                return;
            }
        }
        break;

    case 5:
        if (player != this->world->curr_player && this->game_screen != 0 &&
            player > 0) {
            this->play_sound(6);
            if (value == 0) {
                this->get_string(0xBC5, temp_str, 256);
            }
            else {
                this->get_string(0xBC4, temp_str, 256);
            }
            sprintf(msg, temp_str, this->world->players[player]->name);
            this->game_screen->display_system_message(msg);
            return;
        }
        break;

    case 6:
        if (player != this->world->curr_player && this->game_screen != 0) {
            this->play_sound(6);
            if (player > 0) {
                this->get_string(0xBC6, temp_str, 256);
                sprintf(msg, temp_str,
                        this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
                return;
            }
        }
        break;

    case 7:
        if (value == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(4);
            if (value2 == 0) {
                this->get_string(0xBC8, temp_str, 256);
            }
            else if (value2 == 1) {
                this->get_string(0xBC7, temp_str, 256);
            }
            else if (value2 == 3) {
                this->get_string(0xBC1, temp_str, 256);
            }
            else {
                this->get_string(0xBC9, temp_str, 256);
            }
            sprintf(msg, temp_str,
                    this->world->players[player]->name, value3);
            this->game_screen->display_system_message(msg);
            return;
        }
        break;

    case 8:
        if (this->game_screen != 0) {
            this->game_screen->reset_clocks();
        }
        if (value != this->world->curr_player) {
            return;
        }
        if (this->game_screen == 0) {
            return;
        }
        if (value2 == 0) {
            this->get_string(0xBD2, temp_str, 256);
        }
        else {
            if (value2 != 1) {
                if (value2 == 3) {
                    this->get_string(0xBD3, temp_str, 256);
                }
            }
            else {
                this->get_string(0xBD1, temp_str, 256);
            }
        }
        sprintf(msg, temp_str, this->world->players[player]->name);
        this->game_screen->display_system_message(msg);
        return;

    case 0x6C:
        if (this->game_screen != 0) {
            this->play_sound(8);
            if (player == this->world->curr_player) {
                this->get_string(0xBF2, msg, 256);
                this->game_screen->display_system_message(msg);
            }
            else {
                this->get_string(0xBCB, temp_str, 256);
                sprintf(msg, temp_str,
                        this->world->players[player]->name);
                this->game_screen->display_system_message(msg);
            }
            this->add_notification_loc(value2, value);
            return;
        }
        break;

    case 0x6D: {
        RGE_Player* p1;
        RGE_Player* p2;

        if (this->game_screen == 0) {
            return;
        }
        this->play_sound(9);
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (p1 == p2) {
            if (this->world->victory_type == 0) {
                this->get_string(0xBCC, msg, 256);
            }
            else {
                this->get_string(0xBEE, msg, 256);
            }
        }
        else {
            if ((p1->allied_victory == 0 ||
                 p1->relation((long)p2->id) != 0) ||
                (p2->allied_victory == 0 ||
                 p2->relation((long)p1->id) != 0)) {
                if (this->world->victory_type == 0) {
                    this->get_string(0xBCE, temp_str, 256);
                    goto wonder_format;
                }
                this->get_string(0xBEF, temp_str, 256);
                goto wonder_format;
            }
            if (this->world->victory_type == 0) {
                this->get_string(0xBCD, temp_str, 256);
                goto wonder_format;
            }
            this->get_string(0xBEF, temp_str, 256);
            goto wonder_format;

wonder_format:
            sprintf(msg, temp_str, p1->name);
        }
        goto wonder_tail;
    }

    case 0x6E: {
        RGE_Player* p1;
        RGE_Player* p2;

        if (this->game_screen == 0) {
            return;
        }
        if (this->world->victory_type != 0) {
            return;
        }
        this->play_sound(10);
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (p1 == p2) {
            this->get_string(0xBCF, msg, 256);
        }
        else {
            if ((p1->allied_victory == 0 ||
                 p1->relation((long)p2->id) != 0) ||
                (p2->allied_victory == 0 ||
                 p2->relation((long)p1->id) != 0)) {
                this->get_string(0xBD0, temp_str, 256);
                goto destroyed_format;
            }
            this->get_string(0xBD0, temp_str, 256);

destroyed_format:
            sprintf(msg, temp_str, p1->name);
        }
        goto wonder_tail;

wonder_tail:
        this->add_notification_loc(value2, value);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;
    }

    case 0x72: {
        RGE_Player* p1;
        RGE_Player* p2;
        int i;

        if (this->game_screen == 0) {
            return;
        }
        this->play_sound(0x0B);
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (this->world->victory_type == 0) {
            if (p1 == p2) {
                this->get_string(0xBD4, msg, 256);
            }
            else {
                if ((p1->allied_victory == 0 ||
                     p1->relation((long)p2->id) != 0) ||
                    (p2->allied_victory == 0 ||
                     p2->relation((long)p1->id) != 0)) {
                    this->get_string(0xBD5, msg, 256);
                }
                else {
                    this->get_string(0xBD4, msg, 256);
                }
            }
        }
        else {
            this->get_string(0xBF0, msg, 256);
        }
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        i = 1;
        if (i < this->world->player_num) {
            do {
                this->world->players[i]->notify((long)p1->id, i, 0x72,
                                                0, 0, 0);
                ++i;
            } while (i < this->world->player_num);
        }
        return;
    }

    case 0x74: {
        RGE_Player* p1;
        RGE_Player* p2;
        int i;

        if (this->game_screen == 0) {
            return;
        }
        this->play_sound(0x0B);
        p1 = this->world->players[player];
        p2 = this->world->players[this->world->curr_player];
        if (this->world->victory_type == 0) {
            if (p1 == p2) {
                this->get_string(0xBD9, msg, 256);
            }
            else {
                if ((p1->allied_victory == 0 ||
                     p1->relation((long)p2->id) != 0) ||
                    (p2->allied_victory == 0 ||
                     p2->relation((long)p1->id) != 0)) {
                    this->get_string(0xBDA, msg, 256);
                }
                else {
                    this->get_string(0xBD9, msg, 256);
                }
            }
        }
        else {
            this->get_string(0xBF1, msg, 256);
        }
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        i = 1;
        if (i < this->world->player_num) {
            do {
                this->world->players[i]->notify((long)p1->id, i, 0x74,
                                                0, 0, 0);
                ++i;
            } while (i < this->world->player_num);
        }
        return;
    }

    case 0x75:
        if (this->game_screen == 0) {
            return;
        }
        if (this->world->victory_type != 0) {
            return;
        }
        this->play_sound(0x0C);
        this->get_string(0xBDB, msg, 256);
        this->game_screen->display_system_message(msg);
        this->game_screen->reset_clocks();
        return;

    case 0x76:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE7, msg, 256);
            this->game_screen->show_message(1, msg, 0x55, 0);
            return;
        }
        break;

    case 0x77:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE8, msg, 256);
            this->game_screen->show_message(1, msg, 0x55, 0);
            return;
        }
        break;

    case 0x78:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBE9, msg, 256);
            this->game_screen->show_message(1, msg, 0x55, 0);
            return;
        }
        break;

    case 0x79:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBEA, msg, 256);
            this->game_screen->show_message(1, msg, 0x55, 0);
            return;
        }
        break;

    case 0x7A:
        if (player == this->world->curr_player && this->game_screen != 0) {
            this->play_sound(3);
            this->get_string(0xBEB, msg, 256);
            this->game_screen->show_message(1, msg, 0x55, 0);
            return;
        }
        break;

    case 0x7B:
        if (this->game_screen != 0 && player != this->world->curr_player &&
            value == this->world->curr_player) {
            this->play_sound(0x0D);
        }
        break;

    }
}
