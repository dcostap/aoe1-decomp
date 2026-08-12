// VA: 0048C0E0 RGE_Scenario::Get_player_AI
// Source: scenario.cpp lines 740-783
// Attempt log:
// 1: natural reconstruction with local arrays, language lookups, temp-file write, and fallback sprintfs; compiled 480 bytes, too small.
// 2: fixed TempText3-to-BuildList layout and inlined strcmp loops; size OK but frame 0x170 and locals at wrong offsets.
// 3: reordered string locals / initialized fd before first call; still locals at +38/+14/+7c and fd in ESI.
// 4: unused dummy local did not affect allocation.
// 5: use one raw local buffer with explicit offsets to force random/none/temp stack layout; got stable +4 skew from fd/local slot.
// 6: compensated explicit buffer macros by -4 and shrank raw buffer; restored 0x16c frame but caused worse pointer setup/register drift, rolled back.
// 7: tried narrow /O1 flag as possible local-layout/code-size probe; object shrank to 502 bytes and failed configured size, flag removed.
// 8: tried /O2 /Oy /Ob0 flag probe; same as default, flag removed.
// 9: default restored after flag probes; check_function compiles at configured 521 bytes but remains broad mismatch.
// 10: left in scratch: behavior/calls understood, but remaining mismatch is broad local stack layout and register allocation. Best family compiles at 521 bytes; one-buffer form can place local string regions close but introduces +4 frame skew from fd/register pressure, keeps fd in ESI instead of EBX, and differs in fallback copy/strcmp topology. Not accepted-drift-safe.
// 11: fresh typed baseline: restored the canonical 16-entry scenario arrays and used intrinsic strcmp/strcpy surfaces; testing layout and natural comparison codegen.
// 12: replaced the flat base-game ai_dir stub with the canonical prog_info->ai_dir ownership; checking the natural nested global access.
// 13: saved the selected AiRules entry before the .per sprintf; checking whether the original argument evaluation uses a natural member temporary.
// 14: used explicit TempText3 element addresses on returns; checking whether VC5 recomputes the result address after sprintf.
// 15: saved the program AI directory as a second formatting argument; checking local argument lifetime and register order.
// 16: restored the known RGE_Scenario virtual surface and adjusted the leading gap to keep TempText3 at +11E8.
// 17: restored direct natural member expressions and returns after unchanged alias probes; retained the canonical layout reconstruction.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" int __cdecl _open(const char*, int, int);
extern "C" int __cdecl _write(int, const void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" unsigned long (__stdcall* const GetTempPathA)(unsigned long, char*);

#pragma intrinsic(strcmp, strcpy)

class RGE_Prog_Info {
public:
    char gap_0000[0x102B];
    char ai_dir[0x100];
};

class RGE_Base_Game {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void get_string(int id, char* buf, int len);
    char gap_04[0x0C - 0x04];
    RGE_Prog_Info* prog_info;
};
extern RGE_Base_Game* rge_base_game;

class RGE_Scenario {
public:
    virtual int get_object_pointer(int);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int);
    char gap_0004[0x11E4];
    char TempText3[0xE0];
    char* BuildList[16];
    char* CityPlan[16];
    char* AiRules[16];
    unsigned char* BuildListFile[16];
    unsigned char* CityPlanFile[16];
    unsigned char* AiRulesFile[16];
    int BuildListFileSize[16];
    int CityPlanFileSize[16];
    int AiRulesFileSize[16];
    char* Get_player_AI(int player, int use_temp_file);
};

char* RGE_Scenario::Get_player_AI(int player, int use_temp_file)
{
    char random_str[0x32];
    char none_str[0x32];
    char temp_path[0x104];
    int fd;

    fd = -1;
    rge_base_game->get_string(0x277b, random_str, 0x32);
    rge_base_game->get_string(0x2775, none_str, 0x32);

    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (use_temp_file == 1 && this->AiRulesFileSize[player] > 0 && this->AiRulesFile[player] != 0) {
        sprintf(this->TempText3, "%stemp_AiRules%d.tmp", temp_path, player);
        fd = _open(this->TempText3, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->AiRulesFile[player], this->AiRulesFileSize[player]);
        _close(fd);
        return this->TempText3;
    }

    if (use_temp_file == 1) {
        if (strcmp(this->BuildList[player], none_str) != 0 &&
            strcmp(this->BuildList[player], random_str) != 0) {
            sprintf(this->TempText3, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[player]);
            return this->TempText3;
        }
    }

    sprintf(this->TempText3, "%s", this->AiRules[player]);
    return this->TempText3;
}
