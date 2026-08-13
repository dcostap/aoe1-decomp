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
// - Final lead: the remaining 386-byte drift starts at the delayed EBP save;
//   calls, frame, size, and canonical field ownership are already aligned.

#include <stdlib.h>

extern "C" void __cdecl rge_read(int file, void* buffer, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Player;

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
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void scenario_load(int file, long* pos, float version);
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
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

void RGE_Player::scenario_load(int file, long* pos, float version)
{
    short name_length;
    unsigned char player_count;
    short count;
    int human_team;
    char* name_buffer;

    if (version <= 1.05) {
        int file_handle = file;
        rge_read(file, &name_length, 2);
        if (name_length > 0) {
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
        if (rge_base_game->prog_mode != 7) {
            for (int player = 1; player < 9; player++) {
                if (rge_base_game->playerID(player) == this->id &&
                    (comm->GetPlayerHumanity(player) == 2 ||
                     comm->GetPlayerHumanity(player) == 4)) {
                    if (rge_base_game->playerTeam(player - 1) > 1) {
                        human_team = 1;
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
        while (i < count) {
                rge_read(file_handle, &file, 1);
                if (human_team == 0) {
                    int player_id = pos[i];
                    if (player_id < this->world->player_num && player_id >= 0) {
                        this->relations[player_id] = (unsigned char)file;
                        if (player_id == 0) {
                            this->unitDiplomacy[0] = 0;
                        } else if (i == this->id) {
                            this->unitDiplomacy[player_id] = 1;
                        } else if ((unsigned char)file == 0) {
                            this->unitDiplomacy[player_id] = 2;
                        } else if ((unsigned char)file == 1) {
                            this->unitDiplomacy[player_id] = 3;
                        } else {
                            this->unitDiplomacy[player_id] = 4;
                        }
                    }
                }
                i++;
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
