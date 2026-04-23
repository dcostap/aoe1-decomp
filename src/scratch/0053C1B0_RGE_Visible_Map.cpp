// tried the direct constructor shape first; the mismatch moved into the prolog and the 0xff fill loop shape
// switching to the decompiler-temp form next so the old dims and local temp order match the asm more closely
// if it stays non-exact, the gap is likely just init ordering / loop shape

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

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
    int iVar1;
    int iVar4;
    unsigned char* puVar2;
    unsigned char** ppuVar3;
    unsigned int uVar5;
    unsigned int uVar6;

    this->world = param_2->world;
    this->player = param_2;
    this->map = param_1;
    iVar4 = param_1->map_width;
    this->widthValue = iVar4;
    iVar1 = param_1->map_height;
    this->heightValue = iVar1;
    this->numberTilesExploredValue = 0;
    this->numberTotalTilesValue = iVar1 * iVar4;
    if ((iVar4 < 1) || (iVar1 < 1)) {
        this->visible_map = 0;
        this->map_offsets = 0;
    } else {
        puVar2 = (unsigned char*)calloc(iVar1 * iVar4, 1);
        this->visible_map = puVar2;
        ppuVar3 = (unsigned char**)calloc(this->heightValue, 4);
        this->map_offsets = ppuVar3;
        iVar4 = 0;
        if (0 < this->heightValue) {
            do {
                this->map_offsets[iVar4] = this->visible_map + iVar4 * this->widthValue;
                iVar4 = iVar4 + 1;
            } while (iVar4 < this->heightValue);
        }
        uVar5 = this->heightValue * this->widthValue;
        puVar2 = this->visible_map;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            puVar2[0] = 0xff;
            puVar2[1] = 0xff;
            puVar2[2] = 0xff;
            puVar2[3] = 0xff;
            puVar2 = puVar2 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar2 = 0xff;
            puVar2 = puVar2 + 1;
        }
    }
    uVar6 = 1 << ((unsigned char)param_2->id & 0x1f);
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = uVar6;
    this->PlayerVisibleMaskInvertValue = ~uVar6;
    uVar6 = this->PlayerVisibleMaskValue << 0x10;
    this->PlayerExploredMaskValue = uVar6;
    this->PlayerExploredMaskInvertValue = ~uVar6;
}
