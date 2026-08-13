// VA: 0046F7A0 RGE_Player::scenario_postload(int, long*, float)
// PDB source: player.cpp, lines 879-1016
//
// Canonical ownership follows the matching player.cpp neighbors: name +44,
// world +3c, id +4a, attribute_num/attributes +4c/+50, relations +84,
// unitDiplomacy +88, allied_LOS_Enable/allied_victory +100/+104, and the
// victory-conditions pointer +34.  The serialized short values are kept as
// adjacent ordinary locals, matching the proven stack window.
//
// Attempt log:
// - Baseline rebuilt the complete typed serialization, diplomacy remap, old
//   version gates, victory-condition cleanup, and +0xf0 load_victory surface;
//   it was 727 bytes with one tail-merged virtual call.
// - Preserving the file handle in a local and using separate load_victory arms
//   restored the original 703-byte size and both virtual call sites.
// - Adjacent short locals improved the stack/count basin substantially; a
//   packed local-record experiment was rolled back because it enlarged the
//   frame and lost the call set.
// - A natural temp_byte local for the relation byte coalesced to the dead file
//   parameter home and is the current best: 703 bytes, 259 differing bytes,
//   exact ordered call set, and 3.56% bounded edit diff.  Remaining drift is
//   a localized prologue/local-slot and block-shape mismatch; left in scratch
//   after the ten-hypothesis budget.
// - Continuation: explicit data/non-data player_id arms reproduced the original
//   relation block and reduced drift to 19 bytes.
// - Continuation: a positive final version gate reproduced the original
//   load_victory block and reduced drift to 16 bytes.
// - Tested and rolled back an int high-half overlay for the two serialized
//   counts.  It matched stack addresses but changed full-width load scheduling
//   and moved 625 bytes.  Tested and rolled back LOS-reset source reordering;
//   it moved the attribute block and broke the best basin.
// - Current residual: 16 bytes in stack displacements and the
//   fcomp/LOS-reset scheduling.  Calls, size, frame, and late blocks align.
// - Continuation probes: short declaration reordering was codegen-neutral;
//   reversing the final version gate improved block shape but not bytes. Restored
//   this pinned clean source for a documented pause.

#include <stdlib.h>

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);

void rge_read(int file, void* buffer, int size);

extern double DAT_00570ea0;
extern double DAT_00570ea8;
extern double DAT_00570eb0;
extern double DAT_00570eb8;

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Victory_Conditions {
public:
    ~RGE_Victory_Conditions();
};

class RGE_Base_Game {
public:
    char gap_000[0x1B0];
    int prog_mode;

    int playerID(int player);
    int playerTeam(int player);
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(int player);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int stance);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int, int, int);
    virtual void* make_scenario_obj(float, float, float, short,
                                    unsigned char, float);
    virtual void scenario_save(int file);
    virtual void scenario_load(int file, long* data, float version);
    virtual void scenario_postsave(int file);
    virtual void scenario_postload(int file, long* data, float version);
    virtual void load(int file);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file);
    virtual void save2(int file);
    virtual void save_info(int file);
    virtual void random_start();
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
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
    virtual void* addObject(void*, int, int);
    virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int file, long* data, unsigned char flag);
    virtual void new_victory();

    char gap_004[0x30];
    RGE_Victory_Conditions* victory_conditions; // +34
    char gap_038[4];
    RGE_Game_World* world;                      // +3c
    char gap_040[4];
    char* name;                                 // +44
    unsigned char type;                         // +48
    unsigned char gap_049[1];
    short id;                                    // +4a
    short attribute_num;                         // +4c
    unsigned char gap_04e[2];
    float* attributes;                           // +50
    char gap_054[0x30];
    unsigned char* relations;                   // +84
    int unitDiplomacy[9];                        // +88
    char gap_0AC[0x54];
    int allied_LOS_Enable;                       // +100
    unsigned char allied_victory;                // +104
    char gap_105[0x0F];

    float view_x;                                // +114
    float view_y;                                // +118
    short map_x;                                 // +11c
    short map_y;                                 // +11e

};

void RGE_Player::scenario_postload(int file, long* data, float version)
{
    int file_handle = file;
    short has_team;
    short count;
    short player_count;
    int has_human_team;
    unsigned char temp_byte;

    rge_read(file_handle, &has_team, 2);
    if (has_team > 0) {
        char* name = (char*)calloc((int)has_team, 1);
        rge_read(file_handle, name, (int)has_team);
        if (this->name == 0) {
            this->name = name;
        }
        else {
            free(name);
        }
    }

    rge_read(file_handle, &this->view_x, 4);
    rge_read(file_handle, &this->view_y, 4);
    rge_read(file_handle, &this->map_x, 2);
    rge_read(file_handle, &this->map_y, 2);

    has_human_team = 0;
    if (rge_base_game->prog_mode != 7) {
        for (int player = 1; player < 9; ++player) {
            if (rge_base_game->playerID(player) == this->id &&
                (comm->GetPlayerHumanity(player) == 2 ||
                 comm->GetPlayerHumanity(player) == 4)) {
                if (rge_base_game->playerTeam(player - 1) > 1) {
                    has_human_team = 1;
                }
                break;
            }
        }
    }

    if (version > DAT_00570ea0) {
        rge_read(file_handle, ((char*)&player_count) + 1, 1);
        if (has_human_team == 0) {
            this->allied_victory = ((unsigned char*)&player_count)[1];
        }
    }

    this->allied_LOS_Enable = 0;
    if (version <= DAT_00570eb0 && this->attribute_num > 0) {
        rge_read(file_handle, this->attributes, 0x74);
    }

    rge_read(file_handle, &count, 2);
    short i = 0;
    if (count > 0) {
        do {
            rge_read(file_handle, &temp_byte, 1);
            if (has_human_team == 0) {
                short player_id;
                if (data != 0) {
                    player_id = (short)data[i];
                }
                else {
                    player_id = i;
                }
                if (player_id < this->world->player_num && player_id >= 0) {
                    this->relations[player_id] = temp_byte;
                    if (player_id == 0) {
                        this->unitDiplomacy[0] = 0;
                    }
                    else if (player_id == this->id) {
                        this->unitDiplomacy[player_id] = 1;
                    }
                    else if (temp_byte == 0) {
                        this->unitDiplomacy[player_id] = 2;
                    }
                    else if (temp_byte == 1) {
                        this->unitDiplomacy[player_id] = 3;
                    }
                    else {
                        this->unitDiplomacy[player_id] = 4;
                    }
                }
            }
            ++i;
        } while (i < count);
    }

    if (version >= DAT_00570ea8) {
        rge_read(file_handle, this->unitDiplomacy, 0x24);
    }

    RGE_Victory_Conditions* victory = this->victory_conditions;
    if (victory != 0) {
        delete victory;
    }

    if (version >= DAT_00570eb8) {
        this->load_victory(file_handle, data, 1);
    }
    else {
        this->load_victory(file_handle, data, 0);
    }
}
