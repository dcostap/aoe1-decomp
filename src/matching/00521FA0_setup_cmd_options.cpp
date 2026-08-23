// VA: 00521FA0 TRIBE_Game::setup_cmd_options (598 B)
// PDB source: tribegam.cpp (lines 691-797)
// Exact recovery:
// - The four value scans use one combined space/NUL guard.
// - q is the successor pointer. The source reads through q before p advances.
// - The population clamp uses <= 25. This preserves the oracle's jg branch.
// - QUICK1 uses the strstr result as its predicate. This preserves test eax,eax.
//
// BINARY NOTE: The oracle loads [p+1], then increments p in each scan body.
// A direct p[1] source lets VC5 rotate that increment before the NUL test.
// The q successor local prevents that rotation and restores all four bodies.
//
// Exact-finish walkback:
// - Restoring the QUICK1 pointer temporary changed two bytes.
// - Restoring < 25 changed one branch byte.
// - Removing q changed 56 bytes across the four scans.
// - Branch-local q declarations were byte-identical, but one shared q is simpler.
//
// Fresh validation: 598/598 bytes, 202/202 instructions, 14/14 ordered calls,
// exact blocks, frame 0x400, and the PDB-qualified TRIBE_Game owner all match.
// Context: tribegam_context.h is the grouped TU surface. The fallback class
// declarations stay disabled. Anchors 00520FC0, 00521120, 005213A0, and
// 00522200 remain exact after this source change.

#include <string.h>

extern "C" {
    __declspec(dllimport) char* __stdcall CharUpperA(char* string);
    char* __cdecl strncpy(char* destination, const char* source,
                          unsigned int count);
    long __cdecl atol(const char* string);
    char* __cdecl strstr(const char* string, const char* substring);
    char* __cdecl strchr(const char* string, int character);
}

void encrypt_codes(char* source, char* destination, int limit);

extern int disable_terrain_sounds;
extern int quick_start_game_mode;

#include "../../include/tribegam_context.h"

#if 0
class RGE_Prog_Info {
public:
    char gap_00[0x518];
    char cmd_line[256]; // +0x518
};

class RGE_Game_Info;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    RGE_Game_Info* player_game_info; // +0x04
    void* scenario_info;              // +0x08
    RGE_Prog_Info* prog_info;         // +0x0C
    char gap_10[0xA24 - 0x10];

    int setup_cmd_options();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    virtual int setup_cmd_options();

    char gap_A24[0x234];
    char startup_scenario[260]; // +0xC58
    char startup_game[260];     // +0xD5C
    unsigned long auto_exit_time; // +0xE60

    void setPopLimit(unsigned char limit);
};
#endif

int TRIBE_Game::setup_cmd_options()
{
    char c;
    int i;
    char* p;
    char* q;
    char cmd_line[256];
    char temp_str[256];
    char encstr[512];

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFF);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);
    encrypt_codes(cmd_line, encstr, 0x200);

    if (strstr(cmd_line, "NOTERRAINSOUND") != 0) {
        disable_terrain_sounds = 1;
    }

    p = strstr(encstr, "+!#L%c#L ^=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            temp_str[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        temp_str[i] = 0;
        i = (int)atol(temp_str);
        if (i <= 25) {
            i = 25;
        } else if (i > 200) {
            i = 200;
        }
        this->setPopLimit((unsigned char)i);
    }

    if (strstr(cmd_line, "QUICK1") != 0) {
        quick_start_game_mode = 1;
    }

    p = strstr(cmd_line, "SCN=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            this->startup_scenario[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        this->startup_scenario[i] = 0;
    }

    p = strstr(cmd_line, "EXIT=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            temp_str[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        temp_str[i] = 0;
        this->auto_exit_time = (unsigned long)atol(temp_str);
    }

    p = strstr(cmd_line, "GAM=");
    if (p != 0) {
        c = *p;
        while (c != '=') {
            c = *++p;
        }
        c = *++p;
        i = 0;
        while (c != ' ' && c != 0) {
            this->startup_game[i] = c;
            q = p + 1;
            c = *q;
            ++i;
            p = q;
        }
        this->startup_game[i] = 0;
        if (strchr(this->startup_game, '.') == 0) {
            strcat(this->startup_game, ".gmx");
        }
    }

    return this->RGE_Base_Game::setup_cmd_options();
}
