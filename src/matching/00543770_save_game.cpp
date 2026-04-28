// 00543770 RGE_Game_World::save_game
// PDB: World.cpp:2072-2104, 212 bytes
// __thiscall, returns unsigned char, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1: 31.6% - first diff at +90, jne instead of je for fd==-1 check
//   VC5 inverts block order: puts fail path as fall-through
// probe 2: if(fd!=-1){body}return0 -> MATCH (0.0000%)
//   Key: `if (fd != -1)` makes VC5 put the common continue path as
//   fall-through, matching the original's `je short fail_path` pattern.
//   With `if (fd == -1) return 0;`, VC5 puts the fail path as fall-through
//   (inverted block order) with `jne` to the continue path.

#include <stdlib.h>

extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern "C" int __cdecl rge_open(const char* path, int mode, int access);
extern "C" void __cdecl rge_close(int handle);
extern "C" int __cdecl _unlink(const char* path);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);

extern float save_game_version;
extern int rge_write_error;

class RGE_Prog_Info;
class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;      // +0x0C
};

class RGE_Prog_Info {
public:
    char gap_00[0xB12];
    char save_dir[261];            // +0xB12
};

extern RGE_Base_Game* rge_base_game;

class RGE_Game_World {
public:
    // Vtable slots 0-25: base class virtual methods (26 slots = 0x68)
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25();
    virtual void save(int handle);                    // slot 26 = 0x68
    virtual unsigned char save_game(char* name);      // slot 27 = 0x6C
};

unsigned char RGE_Game_World::save_game(char* name) {
    char tempname[300];

    save_game_version = 7.23f;
    sprintf(tempname, "%s%s", rge_base_game->prog_info->save_dir, name);
    int fd = rge_open(tempname, 0x8309, 0x180);
    if (fd != -1) {
        rge_write_error = 0;
        rge_write(fd, "VER 8.6", 8);
        rge_write(fd, &save_game_version, 4);

        this->save(fd);

        rge_close(fd);

        if (rge_write_error != 0) {
            _unlink(tempname);
            return 0;
        }
        return 1;
    }
    return 0;
}
