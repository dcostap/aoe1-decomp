#ifndef AOE1_TWORLD_PREFIX_CONTEXT_H
#define AOE1_TWORLD_PREFIX_CONTEXT_H

// Canonical tworld.cpp reconstruction context.
// Layout facts come from inventory/types/all_types_reference.h.
typedef unsigned char uchar;
#ifndef _FILE_DEFINED
struct _iobuf;
typedef struct _iobuf FILE;
#endif

class AIPlayBook;
class RGE_Map;
class RGE_Sound;
class RGE_Player;
struct RGE_Player_Info;
class RGE_Master_Player;
class RGE_Master_Static_Object;
class RGE_Effects;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Object_Type_Info;
class RGE_Object_Info_Holder;
class RGE_Object_List_Node;
class RGE_Object_List_Head;
class RGE_Scenario;
class RGE_Static_Object;
class RGE_Victory_Conditions;
class RGE_Command;
class RGE_Sprite;
class RGE_Tile;
class TSound_Driver;
class TCommunications_Handler;
class TDrawArea;
class T_Scenario;
class TRIBE_Tech;
class TRIBE_Player;

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    char gap_25B;
    short color[9];
    uchar gap_26E[2];
    long player_id_hash[9];
    short player_num;
    uchar gap_296[2];
    char* scenario;
    void* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    uchar campaign;
    uchar gap_2A9[3];
};

class RGE_Game_World {
public:
    virtual uchar data_load_world(FILE*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual uchar new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
protected:
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

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    uchar temp_pause;
    uchar game_state;
    uchar game_end_condition;
    uchar gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    uchar gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    uchar gap_36[2];
    RGE_Sprite** sprites;
    short player_num;
    uchar gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    uchar gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    RGE_Command* commands;
    T_Scenario* scenario;
    short color_table_num;
    uchar gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    uchar scenario_object_flag;
    uchar gap_75[3];
    unsigned int random_seed;
    short curr_player;
    uchar gap_7E[2];
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

class TRIBE_World : public RGE_Game_World {
public:
    virtual uchar data_load_world(FILE*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
    virtual void color_table_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    void check_destructables(short, short, float, float, uchar);
    virtual void setup_players(RGE_Player_Info&);
    virtual uchar new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
protected:
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
    virtual ~TRIBE_World();
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

    TRIBE_Tech* tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    uchar countdown_victory;
    uchar gap_115[3];
    float countdown_clock;
    uchar score_displayed;
    uchar controllingComputerPlayer;
    uchar gap_11E[2];
    int sent_zone_score;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    uchar gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    uchar gap_2C[0x08];
    RGE_Victory_Conditions* victory;
    uchar gap_38[0x18];
    float* resources;
    uchar gap_54[0xB8];
    short civilization;
    uchar gap_10E[0x112];
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    union {
        RGE_Object_Node* list;
        RGE_Object_List_Node* head;
    };
    short number_of_objects;
    uchar gap_0A[2];
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type : 5;
    uchar border_type : 4;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Map {
public:
    void* vtable_ptr;
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    uchar gap_18[0x8D74];
    RGE_Tile** map_row_offset;
};

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    uchar gap_04[0x0C];
    short id;
    uchar gap_12[0x1E];
    float radius_x;
    float radius_y;
    float radius_z;
    uchar gap_3C[0x0F];
    uchar can_be_built_on;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    uchar centered;
    uchar gap_0D[3];
};

class RGE_Object_Type_Info {
public:
    uchar gap_00[0x10];
    short id;
};

class RGE_Object_Info_Holder {
public:
    uchar gap_00[0x08];
    RGE_Object_Type_Info* type;
};

class RGE_Object_List_Node {
public:
    RGE_Object_Info_Holder* object;
    RGE_Object_List_Node* next;
};

class RGE_Object_List_Head {
public:
    uchar gap_00[0x04];
    RGE_Object_List_Node* head;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    uchar gap_10[0x28];
    float world_x;
    float world_y;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void load(int);
    uchar gap_220[0x628];
    TRIBE_Player(int, TRIBE_World*, uchar);
    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, uchar, char*, uchar,
                 uchar, uchar, char*, char*, char*);
    void rev_tech(short);
    void new_attribute_num(short, float);
    void add_population_entry();
};

class TRIBE_Gaia : public TRIBE_Player {
public:
    char gap_848[0x10];
    TRIBE_Gaia(int, TRIBE_World*, uchar);
    TRIBE_Gaia(RGE_Game_World*, RGE_Master_Player*, uchar, char*, uchar);
};

// The 0xC-byte tech object is shared by world_init and base_save.
class TRIBE_Tech {
public:
    char gap_00[0x0C];
    TRIBE_Tech(int, TRIBE_World*);
    void save(int);
};

void* operator new(unsigned int);
extern "C" void rge_write(int, void*, int);

#endif
