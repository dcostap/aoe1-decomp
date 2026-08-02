// baseline reconstruction: natural constructor/member layout with CRT memset fill
// probe 2: keep dimensions as named members so VC5 can reuse the original field loads
// probe 3: preserve the source operand order at the total-size store and fill
// probe 4: use direct mask-member assignments so VC5 rereads the stored mask
// variant lab: an explicit volatile reread reduced the byte diff but did not
// resolve the initial multiply register drift; restored natural member reads.
// Final canonical validation: 212-byte size and call/CFG parity; remaining
// codegen drift is the multiply register plus mask-tail scheduling.

#include <stdlib.h>
#include <string.h>

class RGE_Game_World;
class RGE_Player {
public:
    void* vtable_ptr;
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
    char gap_40[0xA];
    short id;
};

class RGE_Map {
public:
    void* vtable_ptr;
    void* map;
    long map_width;
    long map_height;
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

    RGE_Visible_Map(RGE_Map* map, RGE_Player* player);
};

RGE_Visible_Map::RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2) {
    int row;

    this->world = param_2->world;
    this->player = param_2;
    this->map = param_1;
    this->widthValue = param_1->map_width;
    this->heightValue = param_1->map_height;
    this->numberTilesExploredValue = 0;
    this->numberTotalTilesValue = this->widthValue * this->heightValue;
    if ((this->widthValue <= 0) || (this->heightValue <= 0)) {
        this->visible_map = 0;
        this->map_offsets = 0;
    } else {
        this->visible_map = (unsigned char*)calloc(this->numberTotalTilesValue, 1);
        this->map_offsets = (unsigned char**)calloc(this->heightValue, 4);
        row = 0;
        if (0 < this->heightValue) {
            do {
                this->map_offsets[row] = this->visible_map + row * this->widthValue;
                row = row + 1;
            } while (row < this->heightValue);
        }
        memset(this->visible_map, 0xff, this->heightValue * this->widthValue);
    }
    unsigned long mask = 1 << (unsigned char)param_2->id;
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = mask;
    this->PlayerVisibleMaskInvertValue = ~this->PlayerVisibleMaskValue;
    this->PlayerExploredMaskValue = this->PlayerVisibleMaskValue << 0x10;
    this->PlayerExploredMaskInvertValue = ~this->PlayerExploredMaskValue;
}
