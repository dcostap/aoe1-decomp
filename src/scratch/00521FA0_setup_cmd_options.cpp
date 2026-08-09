// VA: 00521FA0 TRIBE_Game::setup_cmd_options (598 B)
// PDB source: tribegam.cpp (lines 691-797)
// Attempt log:
// baseline: replaced the placeholder parser with the period command-line
// buffers, CharUpperA/encryption pass, four option parsers, and the natural
// base setup_cmd_options return path.
// control-flow/layout probes: preincremented cursor setup, nested/for scan
// forms, scalar declaration order, and removal of decompiler-only +4 command
// cursors were tested.  The best clean reconstruction is size/frame/call
// exact with 60 bytes of localized loop/stack drift; temp_str[3] remains the
// only early stack-home mismatch and the parser loops retain the oracle's
// separate space/NUL tests.
// behavior probes (rolled back): temp_str+4 parsing and alternate >25 clamp
// topology moved farther from the 60-byte best; the ordinary <25 / >200 clamp
// is restored.

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

int TRIBE_Game::setup_cmd_options()
{
    char c;
    int i;
    char* p;
    char cmd_line[256];
    char temp_str[256];
    char encstr[512];

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFF);
    temp_str[3] = 0;
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
        while (c != ' ') {
            if (c == 0) {
                break;
            }
            temp_str[i] = c;
            c = p[1];
            ++i;
            ++p;
        }
        temp_str[i] = 0;
        i = (int)atol(temp_str);
        if (i < 25) {
            i = 25;
        } else if (i > 200) {
            i = 200;
        }
        this->setPopLimit((unsigned char)i);
    }

    p = strstr(cmd_line, "QUICK1");
    if (p != 0) {
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
        while (c != ' ') {
            if (c == 0) {
                break;
            }
            this->startup_scenario[i] = c;
            c = p[1];
            ++i;
            ++p;
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
        while (c != ' ') {
            if (c == 0) {
                break;
            }
            temp_str[i] = c;
            c = p[1];
            ++i;
            ++p;
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
        while (c != ' ') {
            if (c == 0) {
                break;
            }
            this->startup_game[i] = c;
            c = p[1];
            ++i;
            ++p;
        }
        this->startup_game[i] = 0;
        if (strchr(this->startup_game, '.') == 0) {
            strcat(this->startup_game, ".gmx");
        }
    }

    return this->RGE_Base_Game::setup_cmd_options();
}
