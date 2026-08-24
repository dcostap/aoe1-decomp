// baseline reconstruction: natural load constructor with named map/player ownership
// probe 2: use an int local for the 2-byte player-id read and <=0 guards;
// this matches the binary's 4-byte home and test/jle topology.
// probe 3: member rereads for derived masks were codegen-neutral.
// probe 4: inlining the bit expression was also codegen-neutral.
// probe 5: assign the visible inverse before the explored masks; this preserves
// the natural field-update order and recovers the exact mask tail.
// Exact: 294/294 bytes with default VC5 /O2 /Oy.
// Main-agent audit confirmed this constructor shares the canonical nonvirtual
// visible-map layout and polymorphic world/player ownership of its exact donor.

#include <stdlib.h>

extern float save_game_version;
extern "C" void __cdecl rge_read(int file, void* buffer, int count);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Map;
class RGE_Player;

#ifndef AOE1_VISIBLE_TU_CONTEXT_H
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2c[0x14];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21[1];
    short master_object_num;
    char gap_24[0x18];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    RGE_Visible_Map(int file, RGE_Game_World* world);
};
#endif

RGE_Visible_Map::RGE_Visible_Map(int file, RGE_Game_World* world) {
    int player_id;

    this->world = world;
    this->map = world->map;
    this->numberTilesExploredValue = 0;

    rge_read(file, &this->widthValue, 4);
    rge_read(file, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_read(file, &this->numberTilesExploredValue, 4);
    }
    rge_read(file, &player_id, 2);

    this->numberTotalTilesValue = this->heightValue * this->widthValue;
    this->player = world->players[(short)player_id];

    if ((this->widthValue <= 0) || (this->heightValue <= 0)) {
        this->visible_map = 0;
        this->map_offsets = 0;
    } else {
        this->visible_map = (unsigned char*)calloc(this->numberTotalTilesValue, 1);
        this->map_offsets = (unsigned char**)calloc(this->heightValue, 4);

        int row = 0;
        if (0 < this->heightValue) {
            do {
                this->map_offsets[row] =
                    this->visible_map + row * this->widthValue;
                row = row + 1;
            } while (row < this->heightValue);
        }
        rge_read(file, this->visible_map,
                 this->widthValue * this->heightValue);
    }

    this->input_csum = 0;
    this->PlayerVisibleMaskValue = 1 << (unsigned char)player_id;
    this->PlayerVisibleMaskInvertValue = ~this->PlayerVisibleMaskValue;
    this->PlayerExploredMaskValue = this->PlayerVisibleMaskValue << 0x10;
    this->PlayerExploredMaskInvertValue = ~this->PlayerExploredMaskValue;
}
