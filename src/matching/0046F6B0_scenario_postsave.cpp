// VA: 0046F6B0 RGE_Player::scenario_postsave(int)
// PDB source: player.cpp lines 855-874
//
// Canonical ownership (per inventory/types/dumps/RGE_Player.txt, RGE_Game_World.txt):
//   +0x34 RGE_Victory_Conditions* victory_conditions (vslot 3 = save(int), call [vt+0xC])
//   +0x3C RGE_Game_World* world;  world->player_num is short at world+0x3C
//   +0x44 char* name
//   +0x84 unsigned char* relations
//   +0x88 int unitDiplomacy[9] (0x24 bytes)
//   +0x104 unsigned char allied_victory
//   +0x114 float view_x, +0x118 float view_y, +0x11C short map_x, +0x11E short map_y
// Serialization idiom: write short strlen(name)+1 (includes NUL), then the name bytes.

#ifdef PLAYER_GROUPED_TU
#include "../../include/player_context.h"
#endif

#ifndef PLAYER_GROUPED_TU
extern "C" int __cdecl strlen(const char*);
#endif

void rge_write(int file, void* data, int size);

#ifndef PLAYER_GROUPED_TU
class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;   // +0x3C
};

class RGE_Victory_Conditions {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void save(int file);    // vtable slot 3 (+0xC)
};

class RGE_Player {
public:
    char gap_00[0x34];
    RGE_Victory_Conditions* victory_conditions;   // +0x34
    char gap_38[0x4];                             // +0x38 visible
    RGE_Game_World* world;                        // +0x3C
    char gap_40[0x4];                             // +0x40 doppleganger_creator
    char* name;                                   // +0x44
    char gap_48[0x3C];
    unsigned char* relations;                     // +0x84
    int unitDiplomacy[9];                         // +0x88
    char gap_AC[0x58];
    unsigned char allied_victory;                 // +0x104
    char gap_105[0x0F];
    float view_x;                                 // +0x114
    float view_y;                                 // +0x118
    short map_x;                                  // +0x11C
    short map_y;                                  // +0x11E

    void scenario_postsave(int file);
};
#endif

void RGE_Player::scenario_postsave(int file)
{
    short count = strlen(this->name) + 1;

    rge_write(file, &count, 2);
    rge_write(file, this->name, count);
    rge_write(file, &this->view_x, 4);
    rge_write(file, &this->view_y, 4);
    rge_write(file, &this->map_x, 2);
    rge_write(file, &this->map_y, 2);
    rge_write(file, &this->allied_victory, 1);
    rge_write(file, &this->world->player_num, 2);
    rge_write(file, this->relations, this->world->player_num);
    rge_write(file, this->unitDiplomacy, 0x24);
    this->victory_conditions->save(file);
}
