// baseline reconstruction: natural constructor/member layout with CRT memset fill
// probe 2: keep dimensions as named members so VC5 can reuse the original field loads
// probe 3: preserve the source operand order at the total-size store and fill
// probe 4: use direct mask-member assignments so VC5 rereads the stored mask
// Fresh pass: exact visible-map family/layout review; natural source retained.
// Diagnostic leads (rolled back): narrow mask reread reached 2B/100% shape;
// total-expression, temporary/register, local-dimension, and statement-order
// variants did not move the initial height/width multiply register choice.
// Focused 20-way total-expression lab likewise found one 2-byte codegen basin.
// Final unresolved lead: initial imul operand coloring (target eax=height,
// rebuilt eax=width); no shared layout conflict is indicated.
// Main-agent exact follow-up: replacing the raw RGE_Player/RGE_Map vptr fields
// with their canonical virtual destructor surfaces changed TU type context and
// recovered the original height-first multiply allocation. Retaining the
// narrow, binary-observed reload of PlayerVisibleMaskValue then recovered the
// exact mask tail. Exact: 212/212 bytes, both calls, and full CFG/block parity.

#include <stdlib.h>
#include <string.h>

class RGE_Game_World;
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
    char gap_40[0xA];
    short id;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
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
    this->PlayerExploredMaskValue =
        *(volatile unsigned long*)&this->PlayerVisibleMaskValue << 0x10;
    this->PlayerExploredMaskInvertValue = ~this->PlayerExploredMaskValue;
}
