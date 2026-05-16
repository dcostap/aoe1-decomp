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

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl _open(const char*, int, int);
extern "C" int __cdecl _write(int, const void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" unsigned long (__stdcall* const GetTempPathA)(unsigned long, char*);

class RGE_Base_Game {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void get_string(int id, char* buf, int len);
    char gap_04[0x0C - 0x04];
    char* ai_dir;
};
extern RGE_Base_Game* rge_base_game;

class RGE_Scenario {
public:
    char gap_0000[0x11E8];
    char TempText3[0xE0];
    char* BuildList[32];
    char* AiRules[32];
    char* AiRulesFile[32];
    int AiRulesFileSize[32];
    char* Get_player_AI(int player, int use_temp_file);
};

char* RGE_Scenario::Get_player_AI(int player, int use_temp_file)
{
    char buf[0x16C];
    int fd;

#define RANDOM_STR (buf)
#define NONE_STR (buf + 0x34)
#define TEMP_PATH (buf + 0x68)

    fd = -1;
    rge_base_game->get_string(0x277b, RANDOM_STR, 0x32);
    rge_base_game->get_string(0x2775, NONE_STR, 0x32);

    if (GetTempPathA(0x104, TEMP_PATH) == 0) {
        const char* dot = ".";
        char* dst = TEMP_PATH;
        while ((*dst++ = *dot++) != 0) {
        }
    }

    if (use_temp_file == 1 && this->AiRulesFileSize[player] > 0 && this->AiRulesFile[player] != 0) {
        sprintf(this->TempText3, "%stemp_AiRules%d.tmp", TEMP_PATH, player);
        fd = _open(this->TempText3, 0x8301, 0x180);
    }

    if (fd != -1) {
        _write(fd, this->AiRulesFile[player], this->AiRulesFileSize[player]);
        _close(fd);
        return this->TempText3;
    }

    if (use_temp_file == 1) {
        char* name = this->BuildList[player];
        char* p1 = name;
        char* p2 = NONE_STR;
        int cmp;
        while (*p1 == *p2) {
            if (*p1 == 0) break;
            if (p1[1] != p2[1]) break;
            if (p1[1] == 0) break;
            p1 += 2;
            p2 += 2;
        }
        cmp = (unsigned char)*p1 - (unsigned char)*p2;
        if (cmp != 0) {
            p1 = name;
            p2 = RANDOM_STR;
            while (*p1 == *p2) {
                if (*p1 == 0) break;
                if (p1[1] != p2[1]) break;
                if (p1[1] == 0) break;
                p1 += 2;
                p2 += 2;
            }
            cmp = (unsigned char)*p1 - (unsigned char)*p2;
            if (cmp != 0) {
                sprintf(this->TempText3, "%s%s.per", rge_base_game->ai_dir + 0x102b, this->AiRules[player]);
                return this->TempText3;
            }
        }
    }

    sprintf(this->TempText3, "%s", this->AiRules[player]);
    return this->TempText3;
}
