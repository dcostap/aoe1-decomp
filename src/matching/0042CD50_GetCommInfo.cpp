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
// follow-up session: inlined both global fill loops, restored RGE_Communications_Speed's direct method ABI, and corrected Speed/LastPlayerCommunication offsets; ordered calls became 23/23 exact.
// follow-up session: signed fill-loop bounds, explicit host/client strcpy arms, and TX/RX argument order reproduced the original copy/FPU topology; the 0x100-byte temporary restored the 0x118 frame.
// follow-up session: removed the DirectPlay global null guard after the oracle showed an unconditional vslot +0x44 call. Best rebuilt size/frame are exact (902B/0x118), with 100% ordered call parity and 436 positional-diff bytes remaining.
// current probe: the oracle passes the DirectPlay output to the speed-info sprintf while the speed method remains parameterless; test that typed call surface.
// exact: the `%s DPMsgs%d` argument order evaluates the parameterless speed
// method after dpid, matching the original push and cleanup topology. Main
// review replaced the manual dispatch struct with the period IDirectPlay2
// GetMessageCount surface; the typed COM call remains byte exact.

extern "C" int __cdecl sprintf(char*, const char*, ...);
#include <string.h>
extern unsigned long debug_timeGetTime(const char* file, int line);
typedef unsigned long ulong;

class IDirectPlay2 {
public:
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual ulong __stdcall AddRef() = 0;
    virtual ulong __stdcall Release() = 0;
    virtual long __stdcall AddPlayerToGroup(ulong, ulong) = 0;
    virtual long __stdcall Close() = 0;
    virtual long __stdcall CreateGroup(void*, void*, void*, ulong, ulong) = 0;
    virtual long __stdcall CreatePlayer(void*, void*, void*, void*, ulong, ulong) = 0;
    virtual long __stdcall DeletePlayerFromGroup(ulong, ulong) = 0;
    virtual long __stdcall DestroyGroup(ulong) = 0;
    virtual long __stdcall DestroyPlayer(ulong) = 0;
    virtual long __stdcall EnumGroupPlayers(ulong, void*, void*, void*, ulong) = 0;
    virtual long __stdcall EnumGroups(void*, void*, void*, ulong) = 0;
    virtual long __stdcall EnumPlayers(void*, void*, void*, ulong) = 0;
    virtual long __stdcall EnumSessions(void*, ulong, void*, void*, ulong) = 0;
    virtual long __stdcall GetCaps(void*, ulong) = 0;
    virtual long __stdcall GetGroupData(ulong, void*, ulong*, ulong) = 0;
    virtual long __stdcall GetGroupName(ulong, void*, ulong*) = 0;
    virtual long __stdcall GetMessageCount(ulong, ulong*) = 0;
};

extern IDirectPlay2* DAT_0062c5ec;
extern ulong DAT_0062cf04;
extern const char s_Com_hand_cpp[];

class RGE_Communications_Speed {
public:
    char gap_0000[0x238];
    unsigned long adjustment_count;
    char* GetLatencyInfo();
    unsigned long GetAdjustmentCount();
    char* GetMachineSpeedInfo();
    char* GetSelfPlayerOptimalSpeedStr();
    char* GetPlayerSpeedStatusStr(int player);
};

class TCommunications_Handler {
public:
    char gap_0000[0x1C];
    int MeHost;             // +1c
    char gap_0020[0x10C8-0x20];
    unsigned long current_turn; // +10c8
    char gap_10CC[0x10E0-0x10CC];
    unsigned int Me;        // +10e0
    int Multiplayer;        // +10e4
    char gap_10E8[8];
    float lastRXDataRate;   // +10f0
    float lastTXDataRate;   // +10f4
    char gap_10F8[0x1344-0x10F8];
    unsigned long LastPlayerCommunication[10]; // +1344
    char gap_136C[0x14D4-0x136C];
    RGE_Communications_Speed* Speed; // +14d4
    char gap_14D8[0x16D8-0x14D8];
    int Humanity[16];       // +16d8-ish

    char* GetCommInfo(unsigned char which);
    char* GetReadyPlayerStr();
    int IsPlayerHuman(unsigned int player);
};

char* TCommunications_Handler::GetCommInfo(unsigned char which) {
    char* p = (char*)0x62C6F0;
    char tmp[0x100];
    --which;

    if (this->Multiplayer == 0) {
        do {
            strcpy(p, (const char*)0x580464);
            p += 0x100;
        } while ((int)p < (int)0x62CDF0);
        sprintf((char*)0x62C6F0, (const char*)0x582920, this->current_turn);
        return (char*)0x62C6F0 + ((unsigned int)which << 8);
    }

    do {
        strcpy(p, (const char*)0x580460);
        p += 0x100;
    } while ((int)p < (int)0x62CDF0);
    strcpy(tmp, (const char*)0x592A40);
    if (this->MeHost != 0) {
        strcpy(tmp, (const char*)0x582918);
    } else {
        strcpy(tmp, (const char*)0x582910);
    }
    sprintf((char*)0x62C6F0, (const char*)0x5828E4, this->Me, this->current_turn, tmp, this->GetReadyPlayerStr(), (double)this->lastTXDataRate, (double)this->lastRXDataRate);
    sprintf((char*)0x62C7F0, (const char*)0x57F718, this->Speed->GetLatencyInfo());
    sprintf((char*)0x62C8F0, (const char*)0x5828CC, this->Speed->GetMachineSpeedInfo(), this->Speed->GetAdjustmentCount());

    ulong dpid = 0;
    DAT_0062c5ec->GetMessageCount(DAT_0062cf04, &dpid);
    sprintf((char*)0x62C9F0, (const char*)0x5828BC, this->Speed->GetSelfPlayerOptimalSpeedStr(), dpid);
    sprintf((char*)0x62CAF0, (const char*)0x57F718, this->Speed->GetPlayerSpeedStatusStr(0));

    unsigned long now = debug_timeGetTime(s_Com_hand_cpp, 0x1468);
    unsigned long t8, t7, t6, t5, t4, t3, t2, t1;
    if (this->IsPlayerHuman(8) && this->Me != 8) t8 = now - this->LastPlayerCommunication[8]; else t8 = 0;
    if (this->IsPlayerHuman(7) && this->Me != 7) t7 = now - this->LastPlayerCommunication[7]; else t7 = 0;
    if (this->IsPlayerHuman(6) && this->Me != 6) t6 = now - this->LastPlayerCommunication[6]; else t6 = 0;
    if (this->IsPlayerHuman(5) && this->Me != 5) t5 = now - this->LastPlayerCommunication[5]; else t5 = 0;
    if (this->IsPlayerHuman(4) && this->Me != 4) t4 = now - this->LastPlayerCommunication[4]; else t4 = 0;
    if (this->IsPlayerHuman(3) && this->Me != 3) t3 = now - this->LastPlayerCommunication[3]; else t3 = 0;
    if (this->IsPlayerHuman(2) && this->Me != 2) t2 = now - this->LastPlayerCommunication[2]; else t2 = 0;
    if (this->IsPlayerHuman(1) && this->Me != 1) t1 = now - this->LastPlayerCommunication[1]; else t1 = 0;
    sprintf((char*)0x62CBF0, (const char*)0x58286C, t1, t2, t3, t4, t5, t6, t7, t8);

    return (char*)0x62C6F0 + ((unsigned int)which << 8);
}
