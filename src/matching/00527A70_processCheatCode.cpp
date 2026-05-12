// VA: 00527A70 TRIBE_Game::processCheatCode (3071 B)
// PDB source: tribegam.cpp
// Reconstructed high-level dispatcher. Current pass replaces placeholder with full
// behavior from packet/Ghidra; remaining work is exact code-shape tuning.

extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" int __cdecl sscanf(const char*, const char*, ...);
extern "C" unsigned char* __cdecl __mbsupr(unsigned char*);

extern void __cdecl encrypt_codes(char* src, char* dst, int max_len);

class RGE_Static_Object {
public:
    char gap_00[0x36];
    char selected;
};

#define VPAD1(n) virtual void vpad##n() = 0;
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Player {
public:
    VPAD16(0) VPAD16(16) VPAD4(32) VPAD2(36) VPAD1(38) VPAD1(39) VPAD1(40) VPAD1(41) VPAD1(42) VPAD1(43) VPAD1(44)
    virtual void set_attribute(short attr, float value) = 0; // vt[45] +0xb4
    void unselect_object();
};

class AIPlayBook {
public:
    int playNumber(char* name);
};

class TRIBE_Command {
public:
    void command_quick_build(short value);
};

class TRIBE_World {
public:
    char gap_00[0x3c];
    short player_count;
    char gap_3e[2];
    void** players;       // +0x40
    char gap_44[0x14];
    TRIBE_Command* command; // +0x58
    char gap_5c[0x44];
    AIPlayBook* playbook; // +0xa0

    RGE_Static_Object* object(int id);
    void send_cheat(short code);
};

class TRIBE_Game {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void vf10(int, int) = 0;
    virtual void vf14(int) = 0;

    char gap_04[0x1b0];
    int game_state;       // +0x1b4
    int game_substate;    // +0x1b8
    char gap_1bc[0x238];
    TRIBE_World* world;   // +0x3f4
    char gap_3f8[0x5b0];
    int quick_build;      // +0x9a8

    int allowCheatCodes();
    int singlePlayerGame();
    RGE_Player* get_player();
    int processCheatCode(int player_id, char* cheat);
};

class TRIBE_Player_Command {
public:
    virtual void v0() = 0;
    VPAD16(1)
    VPAD2(17) VPAD1(19)
    virtual void run_play(int target, int commander, int playNumber) = 0; // +0x50
    virtual void do_unknown(int player, int a, int b, int c, int d) = 0; // +0x54
};

#define ECMP(addr) strcmp(encstr, (const char*)(addr))
#define SEND(c) do { this->world->send_cheat((short)(c)); return 1; } while (0)

int TRIBE_Game::processCheatCode(int player_id, char* cheat) {
    int target;
    int commander;
    char encstr[512];
    char str[256];
    char tempStr1[256];
    char playName[256];

    if (cheat == 0 || player_id < 0 || player_id >= this->world->player_count) {
        return 0;
    }

    strcpy(str, cheat);
    __mbsupr((unsigned char*)str);
    encrypt_codes(str, encstr, 0x200);

    if (this->allowCheatCodes() == 0) {
        return 0;
    }

    if (ECMP(0x58C26C) == 0 && this->singlePlayerGame() != 0) SEND(0x66);
    else if (strstr(str, (const char*)0x58C260) != 0) SEND(0x0e);
    else if (strstr(str, (const char*)0x58C250) != 0) SEND(0x0f);
    else if (strstr(str, (const char*)0x58C244) != 0) SEND(0x10);
    else if (strstr(str, (const char*)0x58C238) != 0) SEND(0x11);
    else if (strstr(str, (const char*)0x58C228) != 0) SEND(0x12);
    else if (strstr(str, (const char*)0x58C21C) != 0) SEND(0x13);
    else if (ECMP(0x58C208) == 0) SEND(0);
    else if (ECMP(0x58C1F0) == 0) SEND(1);
    else if (ECMP(0x58C1D4) == 0) SEND(2);
    else if (ECMP(0x58C1C0) == 0) SEND(3);
    else if (ECMP(0x58C1A0) == 0) SEND(4);
    else if (ECMP(0x58C17C) == 0) SEND(7);
    else if (ECMP(0x58C168) == 0) SEND(8);
    else if (ECMP(0x58C154) == 0) SEND(10);
    else if (ECMP(0x58C13C) == 0) SEND(11);
    else if (ECMP(0x58C12C) == 0) SEND(12);
    else if (ECMP(0x58C120) == 0) SEND(13);
    else {
        if (this->singlePlayerGame() != 0) {
            if (ECMP(0x58C10C) == 0) SEND(100);
            else if (ECMP(0x58C100) == 0) SEND(0xc9);
            else if (ECMP(0x58C0F4) == 0) SEND(0xca);
            else if (ECMP(0x58C0E8) == 0) SEND(0xcb);
            else if (ECMP(0x58C0DC) == 0) SEND(0xcc);
            else if (ECMP(0x58C0D0) == 0) SEND(0xcd);
            else if (ECMP(0x58C0C4) == 0) SEND(0xce);
            else if (ECMP(0x58C0B8) == 0) SEND(0xcf);
            else if (ECMP(0x58C0AC) == 0) SEND(0xd0);
        }
        if (ECMP(0x58C098) == 0) SEND(0x65);
    else if (ECMP(0x58C088) == 0) SEND(0x67);
    else if (ECMP(0x58C07C) == 0) {
        this->get_player()->unselect_object();
        if (this->game_state == 6 && this->game_substate == 1) this->vf10(0, 0);
        this->vf14(0);
        return 1;
    }
    else if (ECMP(0x58C05C) == 0) { this->get_player()->set_attribute(0, 1000.0f); return 1; }
    else if (ECMP(0x58C04C) == 0) { this->get_player()->set_attribute(3, 1000.0f); return 1; }
    else if (ECMP(0x58C038) == 0) { this->get_player()->set_attribute(1, 1000.0f); return 1; }
    else if (ECMP(0x58C028) == 0) { this->get_player()->set_attribute(2, 1000.0f); return 1; }
    else if (ECMP(0x58C014) == 0) { this->world->command->command_quick_build((short)(this->quick_build == 0)); return 1; }
    else if (ECMP(0x58C000) == 0) SEND(0xdc);
    else if (ECMP(0x58BFEC) == 0) SEND(0xe6);
    else if (ECMP(0x58BFE0) == 0) SEND(0xe7);
    else {
        sscanf(str, (const char*)0x57F718, tempStr1);
        if (strcmp(tempStr1, (const char*)0x58BFD4) == 0) {
            sscanf(cheat, (const char*)0x57F6E8, &commander);
            RGE_Static_Object* obj = this->world->object(commander);
            if (obj != 0) {
                obj->selected = 1;
                *(RGE_Static_Object**)((char*)this->world->players[player_id] + 0x130) = obj;
            }
        }
        if (strcmp(tempStr1, (const char*)0x58BFCC) == 0) {
            sscanf(cheat, (const char*)0x58BFBC, &target, playName, &commander);
            int play = this->world->playbook->playNumber(playName);
            if (play != -1) {
                ((TRIBE_Player_Command*)this->world->players[player_id])->run_play(target, commander, play);
                return 1;
            }
        }
        else {
            if (ECMP(0x58BFB0) != 0) {
                return 0;
            }
            ((TRIBE_Player_Command*)this->world->players[player_id])->do_unknown(player_id, 0, 0, 0, 0);
        }
        return 1;
    }
    }
}

