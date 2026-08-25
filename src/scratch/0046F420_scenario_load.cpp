// VA: 0046F420 RGE_Player::scenario_load (653B)
// PDB source: player.cpp, lines 758-851
//
// Attempt log:
// - Replaced the old allocation-only scaffold with the complete scenario
//   stream and the binary-supported RGE_Player field ownership.
// - Added the preserved file-handle local. This recovered all 20 calls, the
//   0xC frame, and exact body size; the original still saves it in EBP before
//   the first read while VC5 delays that save in this source basin.
// - Moved the diplomacy index to the pre-attribute declaration and reused it
//   in the count loop. This recovered the original loop size and late islands.
// - Kept the byte relation read on the incoming file parameter home. The
//   original reloads the position pointer and keeps the human-team flag in
//   EBX; this clean source reaches the same calls and memory effects but VC5
//   colors those values differently.
// - Final best remains a 653-byte, 20-call reconstruction with 386 differing
//   bytes. Remaining drift is prologue scheduling, register coloring, and the
//   relation-loop flag/pointer topology.
// - Tried the same-TU map serialization donor's function-scope file handle
//   with the first name-length read on the parameter. This saved EBP before
//   ESI, but lost exact prologue blocks and raised strict drift to 403 bytes;
//   restored the clean guarded handle form.
// - Tested direct parameter use, delayed handle assignment, function-scope
//   aliases, and the proven overlapping count home. These widened or left the
//   strict diff unchanged; restored the 653-byte guarded-handle source.
// - Reused the human-team variable for relation player IDs with a saved flag,
//   matching more block islands and 95.24% shape, but strict drift worsened to
//   467 bytes and the source was less plausible. Rolled it back.
// - Tested the first-read alias, function-scope guarded handle, short player
//   count overlay, comma-guard/do-while forms, split relation flags, and the
//   file-handle attribute read. They were unchanged, worsened, or broadened
//   register drift. Restored this clean source after each check.
// - Follow-up binary review proved a distinct one-byte relation local at the
//   incoming file home and a saved team flag at the -4 local. The natural
//   two-flag/do-while form preserves all calls, size, frame, faults, and the
//   late relation islands; its best strict result is 262 differing bytes.
// - For-header and explicit-label loop forms changed block layout without
//   closing the remaining register-color and loop-head gap. The guarded
//   do-while form is retained as the simplest supported source model.
// - Final lead: the remaining 262-byte drift starts at the delayed EBP save;
//   calls, frame, size, and canonical field ownership are already aligned.
// - Exact-finish probe: a natural pointer to the mapped player slot (`&pos[i]`)
//   restores the original LEA/address/value schedule and reduces strict drift
//   to 252 bytes. Keep this pointer because the executable proves its lifetime.
// - Direct file use, declaration reordering, register hints, loop-header forms,
//   and the full player/scenario context were tested. They did not improve the
//   pointer basin. A normal C++ rge_read declaration is codegen-neutral.
// - Exact finish remains blocked by the original EBP file / EBX team coloring,
//   the loop-head reload block, and the one-byte boundary difference.

#include <stdlib.h>
#ifdef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void rge_read(int file, void* buffer, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Player;

#ifndef PLAYER_GROUPED_TU
class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;

    int playerID(int player);
    int playerTeam(int player);
};

extern RGE_Base_Game* rge_base_game;

class TCommunications_Handler {
public:
    int GetPlayerHumanity(int player);
};

extern TCommunications_Handler* comm;
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Victory_Conditions {
public:
    ~RGE_Victory_Conditions();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
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
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void scenario_load(int file, long* pos, float version);
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
    virtual void load_victory(int file, long* pos, unsigned char flag);

    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x04];
    RGE_Game_World* world;
    char gap_40[0x04];
    char* name;
    char gap_48[0x02];
    short id;
    short attribute_num;
    char gap_4E[0x02];
    float* attributes;
    char gap_54[0x30];
    unsigned char* relations;
    int unitDiplomacy[9];
    char gap_AC[0x54];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    char gap_105[0x0F];
    float view_x;
    float view_y;
    short map_x;
    short map_y;
};
#endif

void RGE_Player::scenario_load(int file, long* pos, float version)
{
    short name_length;
    unsigned char player_count;
    short count;
    int human_team;
    int saved_human_team;

    if (version <= 1.05) {
        int file_handle = file;
        rge_read(file, &name_length, 2);
        if (name_length > 0) {
            char* name_buffer;
            name_buffer = (char*)calloc((int)name_length, 1);
            rge_read(file_handle, name_buffer, (int)name_length);
            if (this->name == 0) {
                this->name = name_buffer;
            } else {
                free(name_buffer);
            }
        }

        rge_read(file_handle, &this->view_x, 4);
        rge_read(file_handle, &this->view_y, 4);
        rge_read(file_handle, &this->map_x, 2);
        rge_read(file_handle, &this->map_y, 2);

        human_team = 0;
        saved_human_team = 0;
        if (rge_base_game->prog_mode != 7) {
            for (int player = 1; player < 9; player++) {
                if (rge_base_game->playerID(player) == this->id &&
                    (comm->GetPlayerHumanity(player) == 2 ||
                     comm->GetPlayerHumanity(player) == 4)) {
                    if (rge_base_game->playerTeam(player - 1) > 1) {
                        human_team = 1;
                        saved_human_team = 1;
                    }
                    break;
                }
            }
        }

        if (version > 1.0) {
            rge_read(file_handle, &player_count, 1);
            if (human_team == 0) {
                this->allied_victory = player_count;
            }
        }

        short i = 0;
        this->allied_LOS_Enable = 0;
        if (this->attribute_num > 0) {
            rge_read(file, this->attributes, 0x74);
        }

        rge_read(file_handle, &count, 2);
        if (count > 0) {
            do {
                unsigned char relation_value;
                rge_read(file_handle, &relation_value, 1);
                if (human_team == 0) {
                    long* player_id = &pos[i];
                    if (*player_id < this->world->player_num && *player_id >= 0) {
                        this->relations[*player_id] = relation_value;
                        if (*player_id == 0) {
                            this->unitDiplomacy[0] = 0;
                        } else if (i == this->id) {
                            this->unitDiplomacy[*player_id] = 1;
                        } else if (relation_value == 0) {
                            this->unitDiplomacy[*player_id] = 2;
                        } else if (relation_value == 1) {
                            this->unitDiplomacy[*player_id] = 3;
                        } else {
                            this->unitDiplomacy[*player_id] = 4;
                        }
                    }
                }
                ++i;
                human_team = saved_human_team;
            } while (i < count);
        }

        if (version > 1.08) {
            rge_read(file_handle, this->unitDiplomacy, 0x24);
        }

        if (this->victory_conditions != 0) {
            delete this->victory_conditions;
        }

        this->load_victory(file_handle, pos, 0);
    }
}
