// VA: 0045A8A0 RGE_Missile_Object::setup (2-param variant, file-read)
// PDB source: misl_obj.cpp

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

extern float save_game_version;
extern float DAT_00570930;

int RGE_Missile_Object::setup(int fd, RGE_Game_World* game_world)
{
    RGE_Combat_Object::setup(fd, game_world);
    *(unsigned char*)((char*)this + 0x4E) = 0x3C;
    if (save_game_version > 7.09f) {
        rge_read(fd, &max_range, 4);
    } else {
        max_range = *(float*)(*(int*)((char*)this + 8) + 0x114);
    }
    return 1;
}
