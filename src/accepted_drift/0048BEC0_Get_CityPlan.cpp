// VA: 0048BEC0 RGE_Scenario::Get_CityPlan
// Attempt log:
// initial source adapted from accepted_drift Get_BuildList sibling with CityPlan offsets/formats.
// check: exact 521-byte size, equal through offset 0x115; remaining diff is late return-block shortening/reuse of TempText2 pointer in ESI vs original recomputing LEA for return.
// tried local dest/dest2 variables for late sprintf return blocks; no codegen change.
// tried non-volatile TempText2 member; no codegen change, restored volatile to mirror sibling.
// tried raw `(char*)this + 0x1108` destinations/returns (current) rather than member return; same best family.
// used extern rge_base_game symbol and strcpy fallback per Get_BuildList lesson; this gives original prologue, rep movs fallback copy, calls, and stack size.
// kept strcmp source spelling because VC5 inlines the same two-byte-at-a-time strcmp loops as original.
// ACCEPTED_DRIFT proposal: behavior-equivalent same-size build; first 277 bytes exact. Remaining localized late tail drift consists of branch displacements and ESI-cached TempText2 return pointer versus original LEA eax/ecx/edx recomputation in late sprintf return blocks; no call/predicate/stack-cleanup/memory-effect difference identified.

typedef unsigned long DWORD;
class RGE_Base_Game;

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl _open(const char*, int, int);
extern "C" int __cdecl _write(int, const void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" DWORD (__stdcall* const GetTempPathA)(DWORD, char*);
extern RGE_Base_Game* rge_base_game;

class RGE_Base_Game {
public:
#define GPAD(n) virtual void g##n();
    GPAD(0) GPAD(1) GPAD(2) GPAD(3) GPAD(4) GPAD(5) GPAD(6) GPAD(7)
#undef GPAD
    virtual void get_string(int id, char* out, int len);
    char gap_04[8];
    char* prog_info;
};

class RGE_Scenario {
public:
    char gap_0000[0x1108];
    volatile char TempText2[0x1c0];
    char* CityPlanName[0x10];       // +12c8
    char* CityPlan[0x30];           // +1308
    char* CityPlanFile[0x30];       // +13c8
    int CityPlanFileSize[0x30];     // +1488

    char* Get_CityPlan(int player, int use_file);
};

char* RGE_Scenario::Get_CityPlan(int player, int use_file)
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

    if (use_file == 1 && this->CityPlanFileSize[player] > 0 && this->CityPlanFile[player] != 0) {
        sprintf((char*)this->TempText2, (char*)0x0058600C, temp_path, player);
        fd = _open((char*)this->TempText2, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->CityPlanFile[player], this->CityPlanFileSize[player]);
        _close(fd);
        return (char*)this->TempText2;
    }

    if (use_file == 1) {
        char* name = this->CityPlanName[player];
        if (strcmp(name, none_str) != 0) {
            if (strcmp(name, random_str) != 0) {
                sprintf((char*)this + 0x1108, (char*)0x00586000, rge_base_game->prog_info + 0x102b, this->CityPlan[player]);
                return (char*)this + 0x1108;
            }
        }
    }

    sprintf((char*)this + 0x1108, (char*)0x0057F324, this->CityPlan[player]);
    return (char*)this + 0x1108;
}
