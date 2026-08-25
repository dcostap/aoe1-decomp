#ifndef AOE1_TWORLD_PHASE2_CONTEXT_H
#define AOE1_TWORLD_PHASE2_CONTEXT_H

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Game_World;
class TRIBE_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Object_List_Node;
class RGE_Object_Info_Holder;
class RGE_Object_Type_Info;
class RGE_Map;
class RGE_Tile;
class RGE_Sound;
class RGE_Sprite;
class RGE_Effects;
class RGE_Master_Player;
class RGE_Scenario;
class RGE_Player;
class TRIBE_Player;
class TRIBE_Gaia;
class TRIBE_History_Info;
class TRIBE_Tech;
class TRIBE_Command;
class T_Scenario;
class TSound_Driver;
class TCommunications_Handler;
class TPanel;
class TDrawArea;
struct RGE_Player_Info;

class TCommunications_Handler {
public:
    char gap_00[0x174C];
    int WasKicked[9];
    void SendZoneMessage(char*, int);
};

class RGE_Base_Game {
public:
    class RGE_Game_Options {
    public:
        unsigned char data[0xA8];
    };
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
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_info(int);
    virtual void notification(int, int, int, int, int);

    int scenarioGame();
    int randomGame();
    int campaignGame();
    int multiplayerGame();
    int allowCheatCodes();
    int fullVisibility();
    int difficulty();
    uchar pathFinding();
    uchar mpPathFinding();
    uchar check_prog_argument(const char*);
    void reset_countdown_timer(int);
    void set_map_visible(int);
    void set_map_fog(int);
    int victoryType();
    int mapSize();
    int mapType();
    int victoryAmount();
    int randomizePositions();
    int fullTechTree();
    int resourceLevel();
    int startingAge();
    uchar deathMatch();
    uchar popLimit();
    int allowTrading();
    int longCombat();
    int playerTeam(int);
};

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int);
    char gap_04[0x100C];
    char* scenario_name; // +0x1010

    void Set_scenario_name(const char*);
    char* Get_scenario_name();
    void add_description(char*);
    void Set_victory_all_flag(int);
    void Set_Multi_Conquest(int);
    void Set_Multi_Ruins(int);
    void Set_Multi_Artifacts(int);
    void Set_Multi_Discoveries(int);
    void Set_Multi_Exploration(int);
    void Set_Multi_Gold(int);
    void Save_victory_conditions_into_players(int);
    int GetMPVictory();
    int GetVictoryTime();
    int GetVictoryScore();
    int Get_Multi_Ruins();
    int Get_Multi_Artifacts();
    int Get_Multi_Discoveries();
    int GetScenarioOption(int);
};

class T_Scenario : public RGE_Scenario {
public:
    T_Scenario(int, RGE_Game_World*);
    T_Scenario(RGE_Game_World*);
};

class RGE_Game_World {
public:
    RGE_Game_World();
    virtual uchar data_load_world(FILE*);
protected:
    virtual uchar data_load_terrain_tables(char*);
public:
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
protected:
    virtual void data_load_players_type(short, short, FILE*);
public:
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
protected:
    virtual uchar init_player_type(int, short, uchar);
public:
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
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
    virtual uchar new_random_game(RGE_Player_Info&);
public:
    virtual void save(int);
protected:
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
    virtual uchar load_scenario(RGE_Player_Info&);
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
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual uchar data_load(char*, char*);
    virtual uchar init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar load_game(char*);
    virtual uchar new_game(RGE_Player_Info&, int);
    virtual uchar new_scenario(RGE_Player_Info&, int);
    virtual uchar save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual uchar save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(uchar);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);
};

class AIPlayBook {
public:
    int loadPlays(char*);
};
class TribeAIPlayBook : public AIPlayBook {
public:
    char gap[0x50];
    TribeAIPlayBook();
};

class TRIBE_Tech {
public:
    virtual ~TRIBE_Tech();
    char gap_04[8];
    TRIBE_Tech(char*);
    TRIBE_Tech(int, TRIBE_World*);
    void save(int);
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int, void*, void*);
    char gap_04[0x28];
    RGE_Master_Player(int);
    RGE_Master_Player(FILE*);
};
class TRIBE_Master_Player : public RGE_Master_Player {
public:
    TRIBE_Master_Player(int);
    TRIBE_Master_Player(FILE*);
};

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save();
    char gap_04[8];
    RGE_Effects(int);
    virtual void do_effect(short, RGE_Player*);
};
class TRIBE_Effects : public RGE_Effects {
public:
    TRIBE_Effects(int);
};

class TRIBE_Map {
public:
    virtual ~TRIBE_Map();
    char gap_04[0xB5F4];
    TRIBE_Map(char*, char*, char*, char*, short, short, short, RGE_Sound**);
    TRIBE_Map(int, void*, int);
    void load_terrain_obj_types(char*);
};

class TRIBE_Command {
public:
    char gap_00[0x14];
    TRIBE_Command(TRIBE_World*, TCommunications_Handler*);
    TCommunications_Handler* com_hand;
    void command_cheat(short, short);
    void command_make(RGE_Static_Object*, short);
};

class RGE_Victory_Conditions {
public:
    int get_victory_points();
    int get_victory_points_group(uchar);
    void add_victory_points(int, int, int);
    void add_points_attribute_amount(int, int, int, int, int);
    void add_points_attribute_first(int, int, int, int, int);
    void add_points_highest_attribute(int, int, int, int, int);
    void add_points_high_attribute_once(int, int, int, int, int);
    void add_points_high_attribute_amount(int, int, int, int, int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status();
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void aiStatus();
    virtual int isEnemy(int);
    virtual int isAlly(int);
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects; // +24
    RGE_Object_List* objects; // +28
    char gap_2C[8];
    union {
        RGE_Victory_Conditions* victory; // +34
        RGE_Victory_Conditions* victory_conditions;
    };
    char gap_38[0x0C];
    char* name; // +44
    char gap_48[2];
    short player_id; // +4A
    char gap_4C[4];
    union {
        float* attributes; // +50
        float* resources; // +50
        float* fields_50; // +50
    };
    uchar civ; // +54
    char gap_55[0x2B];
    uchar game_status; // +80
    char gap_81[0x83];
    uchar allied_victory; // +104
    short civilization; // compatibility member

    int computerPlayer();
    uchar relation(long);
    uchar check_victory();
    void win_game_now();
    void loss_if_game_on();
    void victory_if_game_on();
    void rev_tech(int);
    void new_attribute_num(int, float);
    void add_population_entry();
};
class TRIBE_Player : public RGE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void isNeutral();
    virtual void isAllNeutral();
    virtual void setDiplomaticStance();
    virtual void loadAIInformation();
    virtual void sendUnitAIOrder();
    virtual void processAIOrder();
    virtual void kickAI();
    virtual void strategicNumber();
    virtual void sendGameOrder();
    virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand();
    virtual void sendPlayCommand();
    virtual void sendPlayCommand2();
    virtual void sendAICommand();
    virtual void objectCostByType();
    virtual void trackUnitGather();
    virtual void make_scenario_obj();
    virtual void scenario_save();
    virtual void scenario_load();
    virtual void scenario_postsave();
    virtual void scenario_postload();
    virtual void load(int);
    char gap_108[0x734];
    TRIBE_History_Info* history; // +83C
    float ruin_held_time; // +840
    float artifact_held_time; // +844
    TRIBE_Player(int, TRIBE_World*, uchar);
    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, uchar, char*, char, int, int, int, int, int);
    void get_achievement(uchar, char*);
};
class TRIBE_Gaia : public TRIBE_Player {
public:
    char gap_848[0x10];
    TRIBE_Gaia(int, TRIBE_World*, uchar);
    TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, int, char*, int);
};

class RGE_Object_Type_Info {
public:
    char gap_00[0x10];
    short id;
};
class RGE_Object_Info_Holder {
public:
    char gap_00[8];
    RGE_Object_Type_Info* type;
};
class RGE_Object_List_Node {
public:
    RGE_Object_Info_Holder* object;
    RGE_Object_List_Node* next;
};
class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    uchar centered;
    char gap_0D[3];
};
class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    union {
        RGE_Object_Node* list;
        RGE_Object_List_Node* head;
    };
    short number_of_objects;
    char gap_0A[2];
    RGE_Static_Object* find_by_master_id(short);
    RGE_Static_Object* find_by_master_id(long, float, float, uchar, uchar, RGE_Static_Object*);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id; // +10
    char gap_12[2];
    short object_group; // +14
    char gap_16[0x1A];
    float radius_x; // +30
    float radius_y; // +34
    float radius_z; // +38
    char gap_3C[0x0F];
    uchar can_be_built_on; // +4B
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
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
    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +8
    char gap_0C[0x2C];
    float world_x; // +38
    float world_y; // +3C
    char gap_40[8];
    uchar object_state;
};

class TPanel {
public:
    enum RedrawMode { redraw_none = 0, redraw_local = 1, redraw_all = 2 };
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning();
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects; // +0C
};
class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    char gap_18[0x8D74];
    RGE_Tile** map_row_offset;
};

class RGE_Random_Map_Module {
public:
    ~RGE_Random_Map_Module();
};
class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    char gap_04[0x191C];
    virtual void generate();
    RGE_RMM_Object_Generator(RGE_Map*, void*, RGE_Game_World*, void*, int);
    void add_quick_obj(short, int, int);
};

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    char gap_25B;
    short color[9];
    char gap_26E[2];
    long player_id_hash[9];
    short player_num;
    char gap_296[2];
    char* scenario;
    void* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    uchar campaign;
    char gap_2A9[3];
};
struct TRIBE_Zone_High_Score_Info {
    long score;
    uchar civ;
    char player_name[0x10];
    uchar num_allies;
};

class TRIBE_Game : public RGE_Base_Game {
public:
    struct TRIBE_Game_Options {
        int mapSizeValue;
        int mapTypeValue;
        int animalsValue;
        int predatorsValue;
        int victoryTypeValue;
        int victoryAmountValue;
        uchar civilizationValue[9];
        int scenarioPlayerValue[9];
        uchar playerColorValue[9];
        uchar computerNameValue[9];
        uchar allowTradingValue;
        uchar longCombatValue;
        uchar randomizePositionsValue;
        uchar fullTechTreeValue;
        int resourceLevelValue;
        int startingAgeValue;
        uchar startingUnitsValue;
        uchar deathMatchValue;
        uchar popLimitValue;
    };
    int mapSize();
    int mapType();
    int victoryType();
    int victoryAmount();
    int randomizePositions();
    int fullTechTree();
    int resourceLevel();
    int startingAge();
    uchar deathMatch();
    uchar popLimit();
    int allowTrading();
    int longCombat();
    int civilization(int);
    int playerColor(int);
    void get_tribe_options(TRIBE_Game_Options*);
    char random_prefix[0xA54];
    int random_civ[9];
};

class TRIBE_World : public RGE_Game_World {
public:
    unsigned long world_time; // +04
    char gap_08[0x15];
    uchar game_state; // +1D
    uchar game_end_condition; // +1E
    char gap_1F[9];
    RGE_Map* map; // +28
    char gap_2C[4];
    void* field_30;
    char gap_34[4];
    void* field_38;
    union {
        short player_num; // +3C
        short player_count;
    };
    char gap_3E[2];
    RGE_Player** players; // +40
    char gap_44[4];
    RGE_Master_Player** master_players; // +48
    RGE_Effects* effects; // +4C
    char gap_50[8];
    union {
        TRIBE_Command* commands; // +58
        TRIBE_Command* field_58;
    };
    RGE_Scenario* scenario; // +5C
    char gap_60[0x1C];
    union {
        short curr_player; // +7C
        short field_7C;
    };
    char gap_7E[6];
    float delta_time; // +84
    char gap_88[0x18];
    AIPlayBook* playBook; // +A0
    char gap_A4[0x60];
    TRIBE_Tech* tech; // +104
    int victory_type; // +108
    int artifact_count; // +10C
    int ruin_count; // +110
    uchar countdown_victory; // +114
    char gap_115[3];
    float countdown_clock; // +118
    uchar score_displayed; // +11C
    uchar controllingComputerPlayer; // +11D
    char gap_11E[2];
    int sent_zone_score; // +120
protected:
    virtual void logStatus(FILE*, int);
public:
    TRIBE_World();
    virtual ~TRIBE_World();
    virtual uchar data_load_world(FILE*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual void load_player(int, uchar, short);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual uchar init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar new_game(RGE_Player_Info&, int);
    virtual uchar new_scenario(RGE_Player_Info&, int);
    virtual void base_save(int);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);
    void check_destructables(short, short, float, float, uchar);
    long get_achievement(uchar, char**);
    void send_cheat(short);
    void cheat(short, short);
    void fill_in_score(TRIBE_Zone_High_Score_Info&, long);
    void send_zone_score_info();

};

extern TRIBE_Game* rge_base_game;
extern TRIBE_Game* tribe_game;
extern void __cdecl rge_write(int, const void*, int);
extern int __cdecl debug_rand(const char*, int);
extern float DAT_00577578;
extern float DAT_00577580;
extern unsigned char die_die_die;

#endif
