// 00511E20 TRIBE_Player::TRIBE_Player(...)
// Source: tplayer.cpp lines 287-329
// FLAGS: config/flags/00511E20_TRIBE_Player.rsp
// Attempt log:
// - Replaced the earlier raw-offset scaffold with the period typed ownership
//   surface: the full RGE_Player base, TRIBE_World, three TRIBE_Object_List
//   members, and the exact allocated object sizes.
// - Baseline hypothesis: the constructor uses the real RGE_Player base
//   initializer, playerAI(0), typed member assignments, and ordinary new
//   expressions; /GX is retained for the observed constructor EH state.
// - Adding the binary-proven RGE_Game_World vptr moved map from +0x24 to
//   +0x28 and produced an exact 706-byte match. The remaining declarations are
//   typed local size/layout stubs for objects only allocated or called here.

void* __cdecl operator new(unsigned int);
extern "C" int __cdecl debug_rand(char*, int);

class RGE_Map;
class RGE_Master_Player;
class RGE_Player;
class TRIBE_Tech;
class TRIBE_Player_Tech;
class TRIBE_History_Info;
class TCommunications_Handler;
extern TCommunications_Handler* comm;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Game_World {
public:
    void* vtable_ptr;                     // +0x00
    char gap_04[0x24];
    RGE_Map* map;                         // +0x28
    char gap_2c[0x3c - 0x2c];
    short player_num;                     // +0x3c
    char gap_3e[0x104 - 0x3e];
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;                     // +0x104
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    int computerPlayerValue;              // +0x04
    int pathingAttemptCapValue;           // +0x08
    int pathingDelayCapValue;             // +0x0c
    int currentUpdatePathingAttemptsValue;// +0x10
    int checksum;                         // +0x14
    int position_checksum;                // +0x18
    int action_checksum;                  // +0x1c
    unsigned char checksum_created_this_update; // +0x20
    unsigned char gap_21[1];
    short master_object_num;              // +0x22
    void* master_objects;                 // +0x24
    class RGE_Object_List* objects;       // +0x28
    class RGE_Object_List* sleeping_objects; // +0x2c
    class RGE_Object_List* doppleganger_objects; // +0x30
    void* victory_conditions;             // +0x34
    void* visible;                        // +0x38
    RGE_Game_World* world;                // +0x3c
    void* doppleganger_creator;           // +0x40
    char* name;                           // +0x44
    unsigned char type;                   // +0x48
    unsigned char gap_49[1];
    short id;                             // +0x4a
    short attribute_num;                  // +0x4c
    unsigned char gap_4e[2];
    float* attributes;                    // +0x50
    unsigned char culture;                // +0x54
    unsigned char gap_55[3];
    unsigned char tile_list[0x14];        // +0x58
    unsigned char diam_tile_list[0x14];   // +0x6c
    unsigned char game_status;            // +0x80
    unsigned char resigned;               // +0x81
    unsigned char gap_82[2];
    unsigned char* relations;             // +0x84
    int unitDiplomacy[9];                 // +0x88
    int mutualAlly[9];                    // +0xac
    unsigned int mutualExploredMask;      // +0xd0
    unsigned int mutualVisibleMask;       // +0xd4
    unsigned int nonMutualVisibleMask;    // +0xd8
    unsigned int removeVisibleBits[9];    // +0xdc
    int allied_LOS_Enable;                // +0x100
    unsigned char allied_victory;         // +0x104
    unsigned char master_player_id;       // +0x105
    unsigned char gap_106[2];
    void* color_table;                    // +0x108
    int tribe_effect;                     // +0x10c
    void* VR_List;                        // +0x110
    unsigned char gap_114[0x220 - 0x114];

    RGE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char);
    void set_relation(int, char);
};

class Visible_Resource_Manager {
public:
    void* VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    Visible_Resource_Manager(RGE_Player*, int);
};

class RGE_Object_List {
public:
    virtual void vf00();
    unsigned char gap_04[8];
    RGE_Object_List();
};

class TRIBE_Object_List : public RGE_Object_List {
public:
    virtual void vf00();
};

class TCommunications_Handler {
public:
    int IsHost();
};

class TribeMainDecisionAIModule {
public:
    unsigned char storage[0x125c8];
    TribeMainDecisionAIModule(void*, int, char*, void*, char*, char*, char*);
};

class RGE_Visible_Map {
public:
    unsigned char storage[0x38];
    RGE_Visible_Map(RGE_Map*, RGE_Player*);
};

class TRIBE_History_Info {
public:
    void* history;
    void* events;
    int number_of_events;
    int number_of_entries;
    int max_number_of_entries;
    TRIBE_History_Info(int);
};

class TRIBE_Player_Tech {
public:
    void* tech_player_tree;
    short tech_player_tree_num;
    unsigned char gap_06[2];
    TRIBE_Tech* base_tech;
    RGE_Player* owner;
    TRIBE_Player_Tech(TRIBE_Tech*, RGE_Player*, unsigned char);
};

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree;          // +0x220
    int fog_update;                        // +0x224
    int update_count;                      // +0x228
    int update_history_count;              // +0x22c
    int updateCountNeedHelp;               // +0x230
    float update_time;                     // +0x234
    TribeMainDecisionAIModule* playerAI;   // +0x238
    unsigned char aiStatusInformationValue[0x600]; // +0x23c
    TRIBE_History_Info* history;           // +0x83c
    float ruin_held_time;                  // +0x840
    float artifact_held_time;              // +0x844

    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char,
                 unsigned char, unsigned char, char*, char*, char*);
    void new_victory();
};
#endif

TRIBE_Player::TRIBE_Player(TRIBE_World* world, RGE_Master_Player* master,
                           unsigned char player_id, char* name_arg,
                           unsigned char civ, unsigned char make_ai,
                           unsigned char make_lists, char* ai1, char* ai2,
                           char* ai3)
    : RGE_Player(world, master, player_id, name_arg, civ, 0), playerAI(0)
{
    this->VR_List = new Visible_Resource_Manager((RGE_Player*)this, 5);

    if (make_ai == 0) {
        this->type = 1;
    } else {
        this->type = 3;
        this->computerPlayerValue = 1;
        if (comm->IsHost() == 1) {
            this->playerAI = new TribeMainDecisionAIModule(
                (void*)0, this->id, this->name, this, ai1, ai2, ai3);
        }
    }

    if (make_lists != 0) {
        TRIBE_Object_List* list;

        list = new TRIBE_Object_List;
        this->objects = list;
        list = new TRIBE_Object_List;
        this->sleeping_objects = list;
        list = new TRIBE_Object_List;
        this->doppleganger_objects = list;
        this->new_victory();
        this->visible = new RGE_Visible_Map(world->map, (RGE_Player*)this);
    }

    int i = 1;
    if (this->world->player_num > 1) {
        do {
            if (i != this->id) {
                this->set_relation(i, 3);
            }
            ++i;
        } while (i < this->world->player_num);
    }

    this->update_count = 0;
    this->update_history_count = 0;
    this->updateCountNeedHelp = 0;
    this->fog_update = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tplayer.cpp", 0x140) * 3) / 0x7fff + 3;
    this->update_time = 0.0f;
    this->history = new TRIBE_History_Info(-1);
    this->tech_tree = new TRIBE_Player_Tech(world->tech, (RGE_Player*)this, 1);
    this->ruin_held_time = -1.0f;
    this->artifact_held_time = -1.0f;
}
