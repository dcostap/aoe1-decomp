#ifndef BASEGAME_CANDIDATE_CONTEXT_H
#define BASEGAME_CANDIDATE_CONTEXT_H

struct _iobuf;
class RGE_Base_Game;
class TChat;
class TSound_Driver;
class TPanel;
struct IDirectDrawSurface;


struct RGE_Player_Info;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Player;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Sound;
class RGE_Command;
class XYZBYTEPoint;
class RGE_Timing_Info;
class RGE_Effects;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Doppleganger_Creator;
class RGE_Tile_List;
class RGE_Unified_Visible_Map;
class AIPlayBook;
class TChat;
class TTaunt;

class RGE_Timing_Info {
public:
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};
extern int do_draw_log;
extern int safe_draw_log;
extern char draw_log_name[260];
extern _iobuf* draw_log;
extern RGE_Base_Game* rge_base_game;
extern TChat* chat;
extern TSound_Driver* sound_driver;
extern unsigned int DAT_0062c578;
extern unsigned int DAT_0062c57c;
class RGE_Game_Info {
public:
    char gap_00[0x118];
    RGE_Game_Info(char* filename);
    ~RGE_Game_Info();
    void save(char* filename);
    int open_scenario();
    int get_current_campaign();
    int get_current_player();
    int get_current_scenario();
    unsigned char set_current_campaign(long value);
    unsigned char set_current_person(long value);
    unsigned char set_current_scenario(long value);
    void notify_of_scenario_complete();
    void find_campaigns();
    void campaign_open_scenario();
};
class RGE_Scenario;
class RGE_Scenario_Header {
public:
    int error_code;
    long version;
    unsigned long checksum;
    char* description;
    virtual ~RGE_Scenario_Header();
    virtual void write(int file);
    RGE_Scenario_Header(int value);
    RGE_Scenario_Header(RGE_Scenario* scenario);
};
class RGE_Scenario {
public:
    char pad_00[0x1990];
    RGE_Scenario(int value, int zero);
};
class RGE_Scenario_File_Info {
public:
    char gap_00[0x10C];
    RGE_Scenario_File_Info(char* filename);
    ~RGE_Scenario_File_Info();
    void reload_scenarios();
};
struct RGE_Prog_Info {
public:
    char prog_name[101];
    char prog_version[21];
    char prog_title[121];
    char world_db_file[261];
    char game_data_file[261];
    char vol_name[261];
    unsigned char gap_402[2];
    unsigned long vol_ser_num;
    int verify_cd;
    int max_players_per_cd;
    void* instance;
    void* prev_instance;
    char registry_key[256];
    char cmd_line[256];
    int show_wnd_flag;
    char icon_name[41];
    char menu_name[41];
    char pal_file[261];
    char cursor_file[261];
    int max_players;
    int check_expiration;
    short expire_month;
    short expire_day;
    short expire_year;
    unsigned char gap_886[2];
    unsigned long update_interval;
    int check_multi_copies;
    union {
        int skip_startup;
        int field_894;
    };
    int full_screen;
    int fixed_window_size;
    int use_dir_draw;
    int use_sys_mem;
    int use_music;
    int use_sound;
    int use_cd_audio;
    int use_ima;
    int use_midi;
    int use_wave_music;
    int fast_view;
    int auto_scroll;
    long mouse_scroll_edge;
    union {
        unsigned long mouse_scroll_interval;
        int scroll_speed;
    };
    float mouse_scroll_max_dist;
    unsigned long key_scroll_interval;
    float key_scroll_max_dist;
    float key_scroll_object_move;
    short interface_style;
    unsigned char gap_8DE[2];
    int main_wid;
    int main_hgt;
    unsigned char game_guid[0x10];
    unsigned char zone_guid[0x10];
    char data_dir[261];
    char graphics_dir[261];
    char save_dir[261];
    char scenario_dir[261];
    char campaign_dir[261];
    char sounds_dir[261];
    char resource_dir[261];
    char ai_dir[261];
    char avi_dir[261];
    unsigned char gap_1235[3];
};
class TDrawArea;
class TDrawSystem {
public:
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    void* PrimaryArea;
    void* DrawAreaList;
    void* DirDraw;
    IDirectDrawSurface* PrimarySurface;
    void* Clipper;
    void* DirDrawPal;
    unsigned long Flags;
    union {
        int ScreenWidth;
        int screen_size;
    };
    int ScreenHeight;
    int ColorBits;
    int ErrorCode;
    int ChangedMode;
    int IsBanked;
    int CanSrcBlt;
    int Restored;
    int ModeAvail640;
    int ModeAvail800;
    int ModeAvail1024;
    int ModeAvail1280;
    int ModeAvail320_200;
    int ModeAvail320_240;
    int ModeAvail320_200_16;
    int ModeAvail320_240_16;
    int ModeAvail640_16;
    int ModeAvail800_16;
    int ModeAvail1024_16;
    unsigned char palette[0x400];
    unsigned char DrawType;
    unsigned char ScreenMode;
    unsigned char gap_47A[2];
    TDrawSystem();
    ~TDrawSystem();
    void CheckAvailModes(int full_screen);
    int IsModeAvail(long width, long height, int bpp);
    int Init(void* instance, void* window, void* palette,
             unsigned char draw_type, unsigned char screen_mode,
             long width, long height, unsigned long flags);
    void Paint(void* rect);
    int CheckSurfaces();
    void ClearRestored();
    void ClearPrimarySurface();
    void ModifyPalette(int start, int count, void* entries);
    void HandleSize(void* p1, unsigned int p2, unsigned int p3, long p4);
    void HandlePaletteChanged(void* p1, unsigned int p2, unsigned int p3, long p4);
    int HandleQueryNewPalette(void* p1, unsigned int p2, unsigned int p3, long p4);
    int SetDisplaySize(long width, long height, int bits);
};
struct IDirectDrawSurface {
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface(void*);
    virtual long __stdcall AddOverlayDirtyRect(void*);
    virtual long __stdcall Blt(void*, void*, void*, unsigned long, void*);
    virtual long __stdcall BltBatch(void*, unsigned long, unsigned long);
    virtual long __stdcall BltFast(unsigned long, unsigned long, void*, void*, unsigned long);
    virtual long __stdcall DeleteAttachedSurface(unsigned long, void*);
    virtual long __stdcall EnumAttachedSurfaces(void*, void*);
    virtual long __stdcall EnumOverlayZOrders(unsigned long, void*, void*);
    virtual long __stdcall Flip(void*, unsigned long);
    virtual long __stdcall GetAttachedSurface(void*, void**);
    virtual long __stdcall GetBltStatus(unsigned long);
};
class TDrawArea {
public:
    unsigned char data_[0x100];
    long Width;
    long Height;
    TDrawArea(TDrawSystem*, long, long, int, int);
    TDrawArea(char* name, long id);
    ~TDrawArea();
    void Clear(void* rect, int color);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    void take_snapshot(char* name, int& number);
    int Init(TDrawSystem*, long, long, int, int);
};
class TShape {
public:
    TShape(char* name, long id);
    ~TShape();
};
class TSound_Driver {
public:
    char gap_0[0x69C];
    TSound_Driver(void* hwnd, char* sounds_dir);
    ~TSound_Driver();
    int driver_active();
    long get_volume();
    void set_volume(long volume, int flag);
    void handle_messages(void*, unsigned int, unsigned int, long);
    void play_list();
    void reset_play_list();
};
class TMusic_System {
public:
    char gap_000[0x104];
    unsigned char music_type;
    char gap_105[3];
    TSound_Driver* sound_system;
    void* instance;
    void* window;
    int device_open;
    char gap_118[0x130];
    int track_count;
    int volume;
    char gap_24C[0x1AC];
    TMusic_System(unsigned char type, void* instance, void* window,
                  TSound_Driver* sound, char* path);
    ~TMusic_System();
    int set_music_type(unsigned char type);
    void set_volume(long volume, int flag);
    int get_play_info(unsigned char*, int*, int*, int*, char*, int*, unsigned long*);
    int stop_track();
    int play_track(int, int, unsigned long);
    int play_tracks(int, int, int, int, unsigned long);
    int play_file(char*, unsigned long);
    int play_file(char*, unsigned long, int);
    void handle_messages(void*, unsigned int, unsigned int, long);
};
class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char gap_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    void* wave_info;
    void* sound_buffer;
    unsigned long data_size;
    TDigital(TSound_Driver*, char*, long);
    int load(char*, long);
    void stop();
    int is_playing();
    void play(int value);
    int play();
};
class TTaunt {
public:
    TTaunt(TSound_Driver* sound_driver);
    ~TTaunt();
};
class TChat {
public:
    void* HostWnd;
    int chatGroupPlayers[10];
    char* Chat[51];
    int CurrentMsgNo;
    TTaunt* taunt;
    TChat(void* host_wnd);
    ~TChat();
    void setInChatGroup(int player, int enabled);
    void StopSoundSystem();
    int RestartSoundSystem(TSound_Driver* driver);
};
class DriveInformation {
public:
    char gap_04[0x270];
    DriveInformation();
    virtual ~DriveInformation();
};
class TCommunications_Handler {
public:
    TCommunications_Handler(void*, unsigned char, TChat*, unsigned char*);
    ~TCommunications_Handler();
    int IsPaused();
    int get_paused();
    void TogglePauseGame();
    int GetPlayerHumanity(int player);
    void ReceiveGameMessages();
    int MultiplayerGameStart();
    void StopIfSyncFail(int);
    void ShowSyncChatMsgs(int);
    void SetStepMode(int);
    void SetSpeedControl(int);
    void DropPacketsIntentionally(int);
    void SetSpeedV1(int);
    void SetMyGameOptions(char*, int);
    void* GetMyGameOptions(unsigned long*);
    char* GetCommInfo(unsigned char param);
};
class TDebuggingLog {
public:
    ~TDebuggingLog();
    void LogFile(int value);
    void LogTimestamp(int value);
    void LogOutput(int value);
};
class TRegistry {
public:
    void* ghMachineKey;
    void* ghUserKey;
    void* ghMachineKeyRead;
    unsigned long gdwDisp;
    char Data[255];
    unsigned char gap_10F[1];
    TRegistry(char* key);
    int RegGetInt(int use_user, const char* name);
    int RegSetInt(int use_user, const char* name, int value);
    char* RegGetAscii(int use_user, const char* name);
    ~TRegistry();
};
class TMousePointer {
public:
    int custom_draw;
    TDrawArea* render_area;
    TDrawArea* save_area;
    TDrawArea* primary_area;
    int Num_Cursors;
    int Max_Cursors;
    TDrawArea* cursors[16];
    TShape* Cursor_Shape;
    int Mouse_Mode;
    int Max_CX;
    int Max_CY;
    int cWidth;
    int cHeight;
    int gWidth;
    int gHeight;
    long mouse_x;
    long mouse_y;
    long save_x;
    long save_y;
    int facet;
    int game_facet;
    int next_facet;
    int last_facet;
    int d_top;
    int d_left;
    int d_bottom;
    int d_right;
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;
    int save_area_valid;
    unsigned char save_rect[0x10];
    unsigned char mouse_rect[0x10];
    unsigned char cursor_rect[0x10];
    unsigned char new_save_rect[0x10];
    unsigned char restore_rect[0x10];
    unsigned char game_window[0x10];
    void* restoreSurface;
    void* renderSurface;
    void* PrimarySurface;
    int active;
    int drawn;
    int Shutdown;
    int Setup;
    int GameMode;
    int GameEnabled;
    int MouseOnScreen;
    unsigned long LastDrawTime;
    long LastddError;
    char cursor_file[260];
    int cursor_file_id;
    TMousePointer(int mode);
    ~TMousePointer();
    int setup(int custom_draw, TDrawArea* draw_area, char* base,
              int palette, int shape_number);
    void on();
    void off();
    void Poll();
    void draw();
    void draw(int flag);
    int in_game_mode();
    void Shutdown_Mouse();
    void erase();
    void Restore_Mouse(TDrawArea* area);
};
struct RGE_Font {
public:
    void* font;
    int font_wid;
    int font_hgt;
};
class RenderSystem {
public:
    void set_facet(long param);
};


class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long, unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, RGE_Player_Info*, unsigned char*);
    virtual void map_generate2(RGE_Game_World*, long, long, unsigned char, long);
    virtual void save(int);
    char gap_04[0x8DC4];
    RGE_Unified_Visible_Map* unified_vis_map;
    unsigned char gap_8DCC[4];
    RGE_Map(int, RGE_Sound**, int);
    RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**);
    void load_terrain_obj_types(char*);
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
    void clear_map_view_info();
    void new_map(long, long);
    void load_map(int);
    void clear_map(unsigned char, unsigned char);
    void scenario_load(int, unsigned char*);
    void save_map(int);
    void scenario_save(int);
};
class RGE_Object_List {
public:
    virtual void load(unsigned char, int, void*);
    union {
        int count;
        int number_of_objects;
        RGE_Object_Node* list;
    };
    void* nodes;
    RGE_Object_List();
    ~RGE_Object_List();
    void removeAllObjects();
    void update();
};
class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
    void del_list();
};
class RGE_Doppleganger_Creator {
public:
    void perform_doppleganger_checks();
};
class RGE_Player {
public:
    virtual ~RGE_Player();
    RGE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char);
    RGE_Player(int, RGE_Game_World*, unsigned char);
    virtual void set_game_status(unsigned char);
    void set_chat_flag(long player, int flag);
    long get_checksum();
    void get_checksums(long& c1, long& c2, long& c3);
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    unsigned char check_victory();
    unsigned char relation(long);
    void destroy_objects();
    void victory_if_game_on();
    void loss_if_game_on();
    void set_map_visible();
    void remake_visible_map();
    void load_info(int);
    void set_color_table(unsigned char);
    void set_relation(long, unsigned char);
    void set_allied_victory(unsigned char);
    char gap_04[0x24];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x0C];
    RGE_Doppleganger_Creator* doppleganger_creator;
    char gap_44[0x14];
    RGE_Tile_List tile_list;
    char gap_6C[0x14];
    unsigned char game_status;
    char gap_81[0x83];
    unsigned char allied_victory;
    char gap_105[0x11B];
};
class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
protected:
    virtual unsigned char data_load_terrain_tables(char*);
public:
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
protected:
    virtual void data_load_players_type(short, short, FILE*);
public:
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
protected:
    virtual unsigned char init_player_type(int, short, unsigned char);
public:
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
protected:
    virtual void master_player_init(int);
public:
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
protected:
    virtual unsigned char new_random_game(RGE_Player_Info&);
public:
    virtual void save(int);
protected:
    virtual void scenario_make_player(short, unsigned char, unsigned char, unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info&);
    virtual unsigned char load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
public:
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info&);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info&, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(int);
    virtual void base_save(char*);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);
    int initializePathingSystem();
    void update_sounds(unsigned long);
    void update_sprites(unsigned long);
    int is_player_turn(int);
    int get_accum_time_delta(int);
    void reset_object_count();
    void reset_communications(TCommunications_Handler*);
    void set_world_chat_flag(int flag);
    void reset_player_visible_maps();
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
    void set_game_speed(int);
    void update_mutual_allies();

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    union {
        float game_speed;
        int game_speed_bits;
    };
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    unsigned char gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    unsigned char gap_36[2];
    RGE_Sprite** sprites;
    union {
        short player_num;
        short num_players;
    };
    unsigned char gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    unsigned char gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    RGE_Command* commands;
    RGE_Scenario* scenario;
    union {
        short color_table_num;
        int header_info;
    };
    unsigned char gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;
    unsigned char gap_75[3];
    unsigned int random_seed;
    union {
        short curr_player;
        short current_player;
    };
    unsigned char gap_7E[2];
    TSound_Driver* sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    AIPlayBook* playbook;
    long campaign;
    long campaign_player;
    long campaign_scenario;
    int player_turn;
    unsigned long player_time_delta[9];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
};
class TPanelSystem {
public:
    void destroyPanel(char* name);
    void release_palette(void* palette);
    void* get_palette(char* name, long id);
    void DisableIME();
    void DisableInput();
    void EnableInput();
    void setCurrentPanel(char* name, int value);
    TPanel* currentPanel();
    void stop_sound_system();
    int restart_sound_system();
};
extern TPanelSystem panel_system;

class RGE_Sound {
public:
    void restart_sound(TSound_Driver* driver);
};

class TPanel {
public:
    enum RedrawMode {
        RedrawNone = 0,
        RedrawNormal = 1,
        RedrawImmediate = 2
    };

    virtual ~TPanel();
    char gap_04[0xF0];
    int error_code;
    virtual void destroy(int flag);
    virtual int activate_panel(void);
    virtual int handle_idle(void);
    virtual void set_redraw(int);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_paint();
    virtual int HandleSize(void*, unsigned int, unsigned int, long);
    virtual int HandleSize(int width, int height);
    virtual int get_palette(void*, unsigned long);
    virtual void* get_palette();
    virtual int wnd_proc(void*, unsigned int, unsigned int, long);
    // Candidate-only declarations for observed BaseGame callers. The direct
    // source uses the canonical TPanel declaration in include/panel.h.
    virtual long handle_size(long width, long height);
    virtual void handle_reactivate();
};
class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
};
class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
    TScreenPanel(char* name);
    long setup(TDrawArea*, char*, long, int);
};
struct VBase {
    virtual void scalar_deleting_destructor(int flag);
};
class RGE_Base_Game {
public:
    struct RGE_Game_Options {
        float versionValue;
        unsigned char scenarioGameValue;
        char scenarioNameValue[128];
        unsigned char singlePlayerGameValue;
        unsigned char multiplayerGameValue;
        unsigned char mapXSizeValue;
        unsigned char mapYSizeValue;
        unsigned char mapZSizeValue;
        unsigned char allowCheatCodesValue;
        unsigned char mpPathFindingValue;
        unsigned char cheatNotificationValue;
        unsigned char fullVisibilityValue;
        unsigned char fogOfWarValue;
        unsigned char coloredChatValue;
        unsigned char numberPlayersValue;
        unsigned char gameDeveloperModeValue;
        unsigned char playerCDAndVersionValue[9];
        unsigned char difficultyValue;
        unsigned char playerTeamValue[9];
    };

    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long __stdcall wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
protected:
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
protected:
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(tagMSG*);
    virtual int handle_idle();
    virtual int handle_mouse_move(void*, unsigned int, unsigned int, long);
    virtual int handle_key_down(void*, unsigned int, unsigned int, long);
    virtual int handle_user_command(void*, unsigned int, unsigned int, long);
    virtual int handle_command(void*, unsigned int, unsigned int, long);
    virtual int handle_music_done(void*, unsigned int, unsigned int, long);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_activate(void*, unsigned int, unsigned int, long);
    virtual int handle_init_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_exit_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_size(void*, unsigned int, unsigned int, long);
    virtual int handle_palette_changed(void*, unsigned int, unsigned int, long);
    virtual int handle_query_new_palette(void*, unsigned int, unsigned int, long);
    virtual int handle_close(void*, unsigned int, unsigned int, long);
    virtual int handle_destroy(void*, unsigned int, unsigned int, long);
    virtual int action_update();
    virtual int action_mouse_move(long, long, int, int, int, int);
    virtual int action_key_down(unsigned long, int, int, int, int);
    virtual int action_user_command(unsigned long, unsigned long);
    virtual int action_command(unsigned long, unsigned long);
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

protected:
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

public:
    RGE_Game_Info* player_game_info;
    RGE_Scenario_File_Info* scenario_info;
    RGE_Prog_Info* prog_info;
    union {
        void* prog_window;
        void* hwnd;
    };
    int prog_ready;
    int prog_active;
    void* prog_palette;
    void* prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    TDrawSystem* draw_system;
    TDrawArea* draw_area;
    unsigned char outline_type;
    unsigned char pad_51[3];
    int custom_mouse;
    short shape_num;
    unsigned char pad_5A[2];
    union {
        TShape** shapes;
        void** shape_arr_ptr;
    };
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    short sound_num;
    unsigned char pad_6A[2];
    union {
        TDigital** sounds;
        void** sound_arr_ptr;
    };
    unsigned char save_music_type;
    unsigned char pad_71[3];
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned long save_music_pos;
    union {
        TCommunications_Handler* comm_handler;
        TCommunications_Handler* comms_handler;
    };
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    TDebuggingLog* debugLog;
    int log_comm;
    TRegistry* registry;
    int prog_mode;
    union {
        int game_mode;
        int field_1B4;
    };
    union {
        int sub_game_mode;
        int field_1B8;
    };
    int paused;
    union {
        TMousePointer* mouse_pointer;
        RenderSystem* render_sys;
    };
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    void* mouse_cursor;
    int input_enabled;
    void* input_disabled_window;
    short font_num;
    unsigned char pad_1E2[2];
    union {
        RGE_Font* fonts;
        void* font_ptr;
    };
    char work_dir[261];
    char string_dll_name[261];
    unsigned char pad_3F2[2];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    union {
        char timing_text[256];
        char timing_string[256];
    };
    unsigned long frame_count;
    unsigned long world_update_count;
    unsigned long view_update_count;
    unsigned long last_frame_count;
    unsigned long last_world_update_count;
    unsigned long last_view_update_count;
    unsigned long fps;
    unsigned long world_update_fps;
    unsigned long view_update_fps;
    union {
        RGE_Timing_Info timings[30];
        char data_[0x3C0];
    };
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    unsigned long last_view_time;
    union {
        char game_options[0xA8];
        char options_data[0xA8];
        struct {
            float version_;
            unsigned char scenarioGame_;
            char scenarioName_[0x80];
            unsigned char singlePlayerGame_;
            unsigned char multiplayerGame_;
            unsigned char mapXSize_;
            unsigned char mapYSize_;
            unsigned char mapZSize_;
            unsigned char allowCheatCodes_;
            unsigned char mpPathFinding_;
            unsigned char cheatNotification_;
            unsigned char fullVisibility_;
            unsigned char fogOfWar_;
            unsigned char coloredChat_;
            unsigned char numberPlayers_;
            unsigned char gameDeveloperMode_;
            unsigned char cdAndVersion_[9];
            unsigned char difficulty_;
            unsigned char playerTeam_[9];
            unsigned char field_97F;
            unsigned char field_980;
            unsigned char field_981;
        };
    };
    union {
        int campaignGameValue;
        int campaignGame_;
    };
    union {
        int savedGameValue;
        int savedGame_;
    };
    int quick_build;
    int save_check_for_cd;
    union {
        int playerIDValue[9];
        int playerID_[9];
    };
    int display_selected_ids;
    union {
        long countdown_timer[9];
        long timers[9];
    };
    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover;
    union {
        float game_speed;
        float game_speed_;
    };
    union {
        int single_player_difficulty;
        int single_player_difficulty_;
    };
    union {
        unsigned char pathFindingValue;
        unsigned char pathFinding_;
    };
    unsigned char resigned[9];
    unsigned char pad_A1E[2];
    TDrawArea* map_save_area;

    RGE_Base_Game(RGE_Prog_Info* info, int do_setup);

    void setVersion(float v);
    void setScenarioGame(int v);
    void setCampaignGame(int v);
    void setSavedGame(int v);
    void setSinglePlayerGame(int v);
    void setMultiplayerGame(int v);
    void setMapSize(int x, int y, int z);
    void setAllowCheatCodes(int v);
    void setCheatNotification(int v);
    void setFullVisibility(int v);
    void setFogOfWar(int v);
    void setColoredChat(int v);
    void setGameDeveloperMode(int v);
    void setDifficulty(int v);
    void setPlayerCDAndVersion(int player, unsigned char v);
    void setPlayerHasCD(int player, int v);
    void setPlayerVersion(int player, unsigned char v);
    void setPlayerTeam(int player, int v);
    void setPathFinding(unsigned char v);
    void setMpPathFinding(unsigned char v);
    void setNumberPlayers(int v);
    void setScenarioName(char* name);
protected:
    int check_expiration();
    int check_multi_copies();
public:
    unsigned char check_prog_argument(char* argument);
    int check_for_cd(int value);
    RGE_Scenario* get_scenario_info(char* name, int from_player_info);
    RGE_Scenario_Header* get_scenario_header(char* name, int from_player_info);
    void write_scenario_header(int file);
    void get_campaign_info(long& campaign, long& player, long& scenario);
    unsigned char set_campaign_info(long campaign, long player, long scenario);
    void set_campaign_win();
    void reset_timings();
    void add_to_timing(int index, unsigned long value);
    void increment_world_update_count();
    void increment_view_update_count();
    void set_last_single_time(int index, unsigned long value);
    unsigned long get_last_time(int index);
    unsigned long get_last_single_time(int index);
    unsigned long get_accum_time(int index);
    unsigned long get_max_time(int index);
    unsigned long get_last_max_time(int index);
    unsigned long get_last_world_update_count();
    unsigned long get_last_view_update_count();
    unsigned long get_world_update_count();
    unsigned long get_view_update_count();
    void mouse_on();
    unsigned char pathFinding();
    unsigned char mpPathFinding();
    void mouse_off();

protected:
    void* make_font(void* dc, long id, int italic);
    void* make_font(void* dc, char* face, int point_size, int weight, int italic);
protected:
    int check_paint();
    void clear_window();
public:
    void close();
    int create_dialog(TPanel** out, TPanel* panel);
    void delete_dialog(TPanel** panel);
    int get_paused();
    RGE_Player* get_player();
    RGE_Font* get_font(int index);
    TShape* get_shape(int index);
    TDigital* get_sound(int index);
    void request_pause();
    void set_paused(int paused, int non_user_pause);
    void get_mouse_info(unsigned int flags, long lparam, tagPOINT& point,
                        int& lbtn, int& rbtn, int& mbtn, int& wheel);
    void get_mouse_info(unsigned int flags, unsigned long lparam, long* y, long* x,
                        int* lbtn, int* rbtn, int* ctrl);
    void get_mouse_pos(tagPOINT& point);
    void draw_window();
    void set_windows_mouse(int value);
    void set_mouse_cursor(void* cursor);
    void set_mouse_facet(long facet);
    int activate_dispatch();
    int deactivate_dispatch();
    int endMethod();
    int scenarioGame() const;
    float version() const;
    int randomGame() const;
    int campaignGame() const;
    int savedGame() const;
    char* scenarioName();
    int singlePlayerGame() const;
    int multiplayerGame() const;
    int mapXSize() const;
    int mapYSize() const;
    int mapZSize() const;
    int allowCheatCodes() const;
    int cheatNotification() const;
    int fullVisibility() const;
    int fogOfWar() const;
    int coloredChat() const;
    int gameDeveloperMode() const;
    int playerHasCD(int player);
    int playerID(int player);
    unsigned char playerVersion(int player);
    char* playerVersionString(int player);
    unsigned char playerCDAndVersion(int player);
    int difficulty();
    int numberPlayers() const;
    int playerTeam(int player);
    void find_campaigns();
    void set_map_visible(unsigned char value);
    void set_map_fog(unsigned char value);
    void turn_world_sound_off();
    int campaign_open_scenario();
    long GetChecksum(long value);
    unsigned char GetWorldChecksums(long& a, long& b, long& c);
    long GetWorldChecksum();
    void disable_input();
    void enable_input();
    void set_screen_size(long width, long height);
    unsigned char check_scenario_checksum(char* filename, long expected);
    long get_scenario_checksum(char* filename);
    unsigned long get_checksum(const char* filename);
    void dump_memory_usage(char* value);
    void setPlayerID(int player, int value);
    void reset_countdown_timer(long player);
    void set_countdown_timer(long player, long value);
    void get_countdown_timer(long player, long& output);
    int play_video(char* value);
    void close_video();
    void handle_video_notify();
    int play_sound(int value);
    float get_game_speed();
    void set_game_speed(float value);
    int get_single_player_difficulty();
    void set_single_player_difficulty(int value);
    void reload_scenarios_info();
    void set_render_all();
    void set_game_options(RGE_Game_Options* options);
    void get_game_options(RGE_Game_Options* options);
};

#endif
