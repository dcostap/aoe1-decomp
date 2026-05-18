// VA: 0042CD50 TCommunications_Handler::GetCommInfo
// Com_hand.cpp
// Attempt log:
// try 1: broad reconstruction from packet: initialize global comm-info text buffers, single-player branch, multiplayer info sprintfs, latency deltas by player.
// try 2: modeled return convention as global line buffer `0x62C6F0 + ((which-1)&0xff)*0x100`.
// try 3: modeled single-player path: fill 7/8 0x100-byte slots with literal `>` string and sprintf first line with current turn.
// try 4: modeled multiplayer path: fill slots with blank string, copy empty temp string, choose Host/Client string from field +0x1C, main sprintf with comm type/turn/ready string/TX/RX floats.
// try 5: modeled fields used by packet: turn +0x10C8, commType +0x10E0, singlePlayer +0x10E4, tx/rx +0x10F0/+0x10F4, player time stamps +0x1348..+0x1364, lobby +0x14D4.
// try 6: modeled LobbyInfo methods for the multiple lobby sprintf lines, and GetReadyPlayerStr/IsPlayerHuman calls from matched/scratch neighbors.
// try 7: initially approximated DirectPlay vtable +0x44 call by assigning global dco id; rebuilt .text was 896B vs original 902B.
// try 8: added explicit DirectPlay-like vtable +0x44 call into local dpid; rebuilt reached original size 902B but broad mismatch.
// try 9: adjusted temp buffer from 0x100 to 0xFC to recover original 0x118 frame size; first mismatch moved from frame size to prologue/source-order (`mov edx,62C6F0` before saves in original vs param load first in rebuilt).
// try 10: reviewed diff: current size matches 902B, but positional diff remains 85.03%, edit diff 58.20%; major drift is fill-line copy loop lowered through helper/strcpy calls and different prologue/local scheduling. Original inlines strlen/rep movsd/movsb into the fill loop and hand-copies strings before sprintfs.
// left in scratch: behavior/call surface is broad and size-matched, but exact string-copy source shape/prologue scheduling and lobby/DirectPlay call surfaces are unresolved. No accepted_drift: broad prologue/copy-loop/control drift.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcpy(char*, const char*);
extern unsigned long debug_timeGetTime(const char* file, int line);
struct DPVtbl { char gap[0x44]; int (__stdcall *get_id)(void*, unsigned int, unsigned int*); };
struct DPObj { DPVtbl* vt; };
extern DPObj* DAT_0062c5ec;
extern unsigned int DAT_0062cf04;
extern const char s_Com_hand_cpp[];

class LobbyInfo {
public:
    int get1();
    int get2();
    int get3(int);
    int get4();
    int get5();
};

class TCommunications_Handler {
public:
    char gap_0000[0x1C];
    int hostFlag;           // +1c
    char gap_0020[0x10C8-0x20];
    int turn;               // +10c8
    char gap_10CC[0x10E0-0x10CC];
    int commType;           // +10e0
    int singlePlayer;       // +10e4
    char gap_10E8[8];
    float txRate;           // +10f0
    float rxRate;           // +10f4
    char gap_10F8[0x1348-0x10F8];
    unsigned long stamp1;   // +1348
    unsigned long stamp2;
    unsigned long stamp3;
    unsigned long stamp4;
    unsigned long stamp5;
    unsigned long stamp6;
    unsigned long stamp7;
    unsigned long stamp8;
    char gap_1368[0x14D4-0x1368];
    LobbyInfo* lobby;       // +14d4
    char gap_14D8[0x16D8-0x14D8];
    int humanity[16];       // +16d8-ish

    char* GetCommInfo(unsigned char which);
    char* GetReadyPlayerStr();
    int IsPlayerHuman(unsigned int player);
};

static void fill_lines(const char* s) {
    char* p = (char*)0x62C6F0;
    do {
        strcpy(p, s);
        p += 0x100;
    } while (p < (char*)0x62CDF0);
}

char* TCommunications_Handler::GetCommInfo(unsigned char which) {
    unsigned char idx = (unsigned char)(which - 1);
    char tmp[0xFC];

    if (this->singlePlayer == 0) {
        fill_lines((const char*)0x580464);
        sprintf((char*)0x62C6F0, (const char*)0x582920, this->turn);
        return (char*)0x62C6F0 + ((unsigned int)idx << 8);
    }

    fill_lines((const char*)0x580460);
    strcpy(tmp, (const char*)0x592A40);
    strcpy(tmp, this->hostFlag == 0 ? (const char*)0x582910 : (const char*)0x582918);
    sprintf((char*)0x62C6F0, (const char*)0x5828E4, this->commType, this->turn, tmp, this->GetReadyPlayerStr(), (double)this->txRate, (double)this->rxRate);
    sprintf((char*)0x62C7F0, (const char*)0x57F718, this->lobby->get1());
    sprintf((char*)0x62C8F0, (const char*)0x5828CC, this->lobby->get2(), this->lobby->get3(0));

    unsigned int dpid = 0;
    if (DAT_0062c5ec != 0) {
        DAT_0062c5ec->vt->get_id(DAT_0062c5ec, DAT_0062cf04, &dpid);
    }
    sprintf((char*)0x62C9F0, (const char*)0x5828BC, this->lobby->get3(dpid));
    sprintf((char*)0x62CAF0, (const char*)0x57F718, this->lobby->get4());

    unsigned long now = debug_timeGetTime(s_Com_hand_cpp, 0x1468);
    unsigned long t8, t7, t6, t5, t4, t3, t2, t1;
    if (this->IsPlayerHuman(8) && this->commType != 8) t8 = now - this->stamp8; else t8 = 0;
    if (this->IsPlayerHuman(7) && this->commType != 7) t7 = now - this->stamp7; else t7 = 0;
    if (this->IsPlayerHuman(6) && this->commType != 6) t6 = now - this->stamp6; else t6 = 0;
    if (this->IsPlayerHuman(5) && this->commType != 5) t5 = now - this->stamp5; else t5 = 0;
    if (this->IsPlayerHuman(4) && this->commType != 4) t4 = now - this->stamp4; else t4 = 0;
    if (this->IsPlayerHuman(3) && this->commType != 3) t3 = now - this->stamp3; else t3 = 0;
    if (this->IsPlayerHuman(2) && this->commType != 2) t2 = now - this->stamp2; else t2 = 0;
    if (this->IsPlayerHuman(1) && this->commType != 1) t1 = now - this->stamp1; else t1 = 0;
    sprintf((char*)0x62CBF0, (const char*)0x58286C, t1, t2, t3, t4, t5, t6, t7, t8);

    return (char*)0x62C6F0 + ((unsigned int)idx << 8);
}
