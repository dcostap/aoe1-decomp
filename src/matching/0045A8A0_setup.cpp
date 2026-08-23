// VA: 0045A8A0 RGE_Missile_Object::setup (2-param variant, file-read)
// PDB source: misl_obj.cpp

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Combat_Object_setup_2 {
    char base[0x1C4];
    int setup(int fd, void* game_world);
};

extern float save_game_version;
extern float DAT_00570930;

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
struct RGE_Missile_Object {
    char base[0x1C4];
    float max_range;                // +0x1C4
    // fields inherited from RGE_Combat_Object include a game_world pointer at +0x8
    
    int setup(int fd, void* game_world);
};
#endif

int RGE_Missile_Object::setup(int fd, void* game_world)
{
    ((RGE_Combat_Object_setup_2*)this)->setup(fd, game_world);
    *(unsigned char*)((char*)this + 0x4E) = 0x3C;
    if (save_game_version > 7.09f) {
        rge_read(fd, &max_range, 4);
    } else {
        max_range = *(float*)(*(int*)((char*)this + 8) + 0x114);
    }
    return 1;
}
