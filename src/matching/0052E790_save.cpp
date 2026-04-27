// VA: 0052E790 TRIBE_World::save (145 B)
// PDB source: tworld.cpp

#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

struct RGE_Game_World_save {
    char base[0x108];
    void save(int fd);
};

struct TRIBE_World {
    char pad[0x108];
    int victory_type;         // +0x108
    int artifact_count;       // +0x10C
    int ruin_count;           // +0x110
    char countdown_victory;   // +0x114
    float countdown_clock;    // +0x118
    char score_displayed;     // +0x11C
    char controllingCompPlayer; // +0x11D
    
    void save(int fd);
};

void TRIBE_World::save(int fd)
{
    ((RGE_Game_World_save*)this)->save(fd);
    rge_write(fd, &victory_type, 4);
    rge_write(fd, &artifact_count, 4);
    rge_write(fd, &ruin_count, 4);
    rge_write(fd, &countdown_victory, 1);
    rge_write(fd, &countdown_clock, 4);
    rge_write(fd, &score_displayed, 1);
    rge_write(fd, &controllingCompPlayer, 1);
}
