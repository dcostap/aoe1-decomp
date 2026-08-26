// VA: 0048BCC0 RGE_Scenario::Get_BuildList
// scenario.cpp lines 640-683
// Attempt log:
// 1: natural source from packet/decompiler with exact stack-array sizes/order.
// 2: added explicit strcmp prototype after compile failure.
// 3: object dump showed close stack size but 480 B; prologue hoisted rge_base_game before stack allocation, fd in esi not ebx, and manual '.' copy emitted byte loop not original rep movs.
// 4: changed rge_base_game to extern symbol and fallback copy to strcpy; reached exact 507 B with first mismatch only fd=-1 placement between first/second get_string calls plus small tail offsets.
// 5: initialized fd in declaration; fixed early code through offset 0x115. Remaining diff is late return-block shortening from reusing cached TempText1 pointer in esi.
// 6: tried raw `(char*)this + 0x1028` for late sprintf/return destinations; no codegen change.
// 7: tried volatile TempText1 member plus casts; no codegen change in remaining diff.
// 8: tried /GX; unchanged.
// 9: tried /O2 without /Oy; unchanged.
// 10: current best is behavior-equivalent 507 B. Equal through offset 0x115; remaining diff is branch displacements and `mov eax,esi` return-value reuse vs original `lea eax/edx,[ebp+1028h]` in late return blocks. Candidate for accepted_drift review; no changed calls, predicates, stack cleanup, or memory effects identified.

typedef unsigned int UINT;
typedef unsigned long DWORD;

class RGE_Base_Game;

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl _open(const char*, int, ...);
extern "C" int __cdecl _write(int, const void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" DWORD (__stdcall* const GetTempPathA)(DWORD, char*);

extern RGE_Base_Game* rge_base_game;

#ifndef SCENARIO_TU
class RGE_Prog_Info {
public:
    char gap_000[0x102B];
    char ai_dir[0x100];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* param_1, unsigned int param_2,
                          unsigned int param_3, long param_4);
    virtual void set_prog_mode(int param_1);
    virtual void set_game_mode(int param_1, int param_2);
    virtual void set_player(short param_1);
    virtual int get_error_code();
    virtual char* get_string(int param_1, long param_2, char* param_3,
                             int param_4);
    virtual char* get_string(long param_1, char* param_2, int param_3);
    char gap_04[8];
    RGE_Prog_Info* prog_info;
};

class RGE_Scenario {
public:
    char gap_0000[0x1028];
    volatile char TempText1[0x2a0];
    char* BuildList[0x30];
    char* BuildListFile[0x30];
    int BuildListFileSize[0x30];

    char* Get_BuildList(int player, int use_file);
};
#endif

char* RGE_Scenario::Get_BuildList(int player, int use_file)
{
    char random_str[50];
    char pad1[2];
    char none_str[50];
    char pad2[2];
    char temp_path[260];
    int fd = -1;

    rge_base_game->get_string(0x277b, random_str, 50);
    rge_base_game->get_string(0x2775, none_str, 50);
    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, (char*)0x00585800);
    }

    if (use_file == 1 && this->BuildListFileSize[player] > 0 && this->BuildListFile[player] != 0) {
        sprintf((char*)this->TempText1, (char*)0x00585FE8, temp_path, player);
        fd = _open((char*)this->TempText1, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->BuildListFile[player], this->BuildListFileSize[player]);
        _close(fd);
        return (char*)this->TempText1;
    }

    if (use_file == 1) {
        char* name = this->BuildList[player];
        if (strcmp(name, none_str) != 0) {
            if (strcmp(name, random_str) != 0) {
                sprintf((char*)this + 0x1028, (char*)0x00585FE0, rge_base_game->prog_info->ai_dir, name);
                return (char*)this + 0x1028;
            }
        }
    }

    sprintf((char*)this + 0x1028, (char*)0x0057F324, this->BuildList[player]);
    return (char*)this + 0x1028;
}
