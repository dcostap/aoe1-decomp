// VA: 00519AF0 TRIBE_Gaia::TRIBE_Gaia
// tplayer.cpp:5263-5270
// FLAGS: /GX

class TRIBE_World;

extern void __cdecl rge_read(int file, void* buf, int size);

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TRIBE_Player {
public:
    char gap_004[0x844];
    TRIBE_Player(int file, TRIBE_World* world, unsigned char player_id);
    virtual ~TRIBE_Player();
};

class TRIBE_Gaia : public TRIBE_Player {
public:
    int update_time;   // +0x848
    int update_nature; // +0x84C
    int last_count;    // +0x850
    int animal_max;    // +0x854

    TRIBE_Gaia(int file, TRIBE_World* world, unsigned char player_id);
    virtual ~TRIBE_Gaia();
};
#endif

TRIBE_Gaia::TRIBE_Gaia(int file, TRIBE_World* world, unsigned char player_id)
    : TRIBE_Player(file, world, player_id)
{
    *(unsigned char*)((char*)this + 0x48) = 2;
    rge_read(file, &update_time, 4);
    rge_read(file, &update_nature, 4);
    rge_read(file, &animal_max, 4);
    rge_read(file, &last_count, 4);
}
