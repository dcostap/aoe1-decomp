// RGE_Game_World::init_player
// VA: 00541800
// World.cpp:735-751
// 113 bytes, 18 diff bytes (15.93%)
// Loop bottom quirk: original uses `cmp si,[ebx]; jl` (16-bit compare),
// rebuilt uses `movsx edx,[ebx]; cmp esi,edx; jl` (32-bit compare + sign-ext).
// Same behavior, different loop comparison encoding.
// 5+ source forms tried. 6 relocations masked.

#include "../../include/game_globals.h"

void rge_read(int fileHandle, void* dest, int size);
void* calloc(int count, int size);

class RGE_Game_World {
public:
    // vtable pointer at +0x00 (implicit, 4 bytes)
    char gap_04[0x40];       // +0x04 to +0x43 (64 bytes)
    short playerCount;       // +0x44
    char gap_46[2];          // +0x46 to +0x47
    void** masterPlayers;    // +0x48

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void create_master_player(int fileHandle, int index, unsigned char playerType);

    unsigned char init_player(int fileHandle);
};

unsigned char RGE_Game_World::init_player(int fileHandle) {
    rge_read(fileHandle, &this->playerCount, 2);

    if (this->playerCount > 0) {
        this->masterPlayers = (void**)calloc(this->playerCount, 4);
        for (int i = 0; i < this->playerCount; i++) {
            unsigned char tempByte;
            rge_read(fileHandle, &tempByte, 1);
            this->create_master_player(fileHandle, i, tempByte);
        }
    }
    return 1;
}
