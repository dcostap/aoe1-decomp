// 004282C0 TCommunications_Handler::EvaluatePlayerMessage
// Com_hand.cpp
// Attempt log:
// try 1: broad switch reconstruction from packet: message opcode dispatch to lobby/session/chat/control handlers.
// try 2: modeled early multiplayer guard at +0x10E4 returning 0, preserving original prologue register set (EBX/ESI/EDI) in broad form.
// try 3: modeled parameter surface as nine stack args, with opcode in arg4 and data pointer in arg6, matching packet stack references.
// try 4: implemented turn-speed message path: SetPlayerTurnSpeed from data[8]/data[9], regression warning when message turn < current_turn, lastTurn[player] update with latencyBase subtraction.
// try 5: implemented simple receive helper path at 004286F0, stats 9-argument path at lobby/stats +0x14D8, and generic six-arg receive path at 00426470.
// try 6: implemented speed update with two shorts and p5, and chat text path with logging, local-player/mode check, and chat sink display using player-name 0x80 stride.
// try 7: implemented pause/resume/control paths calling 0042C860/0042C840/0042C880-style helpers and zeroed stats reset call.
// try 8: implemented player-id lookup path: log incoming id, scan dpid range minPlayer..maxPlayer at +0x1564, add missing player flag, update local/remote UI.
// try 9: implemented default unknown opcode log with opcode twice, matching observed varargs shape.
// try 10: current source compiles to exact 972B, but broad mismatch remains: first 34 bytes match, then switch range differs because natural case labels are compact 0x44..0x4F while original normalizes opcode-0x2B and uses a sparse 0x2C range jump table.
// try 11: reviewed diff: major remaining drift is opcode mapping/jump table plus many handler argument/order details; behavior is only approximate in some helper surfaces.
// left in scratch: size-matched broad reconstruction, but exact sparse switch mapping and handler call surfaces are unresolved. No accepted_drift: broad switch/control-flow/call-surface drift.

extern void log_printf(void*, const char*, ...);
extern void* DAT_0062c4fc;

class Speed { public: void SetPlayerTurnSpeed(int, unsigned char, unsigned char); void set_32840(unsigned short,unsigned short,unsigned int); };
class Stats { public: void call330A0(int,int,int,int,int,int,int,int,int); void call33460(int,int,int,int,int,int,int,int,int); };
class ChatSink { public: int show(char*, char*, int); };

class TCommunications_Handler {
public:
    char gap00[0x18]; ChatSink* chat; int some1c;
    char gap20[0x10C8-0x20]; unsigned int current_turn;
    char gap10CC[0x10E0-0x10CC]; unsigned int localPlayer; int multiplayer;
    char gap10E8[0x12C8-0x10E8]; char* playerNames;
    char gap12CC[0x13BC-0x12CC]; int playerFlags[16];
    char gap13FC[0x14D4-0x13FC]; Speed* speed; Stats* stats;
    char gap14DC[0x1558-0x14DC]; int mode;
    char gap155C[0x1590-0x155C]; unsigned char latencyBase;
    char gap1591[0x1710-0x1591]; unsigned short minPlayer, maxPlayer;
    char gap1714[0x1720-0x1714]; unsigned int lastTurn[16];

    int EvaluatePlayerMessage(unsigned long a1,unsigned long player,unsigned long a3,unsigned char opcode,unsigned char p5,char* data,unsigned int p7,unsigned int p8,unsigned int p9);
    void recv1(int player, int value);
    void recv2(unsigned int a, unsigned long b, unsigned long c, unsigned long d, unsigned long e, int z);
    void recv3(int player);
    void recv4(int player);
    void recv5(int on);
    void add_player(int index, int id);
    void update_ui(int id);
};

int TCommunications_Handler::EvaluatePlayerMessage(unsigned long a1,unsigned long player,unsigned long a3,unsigned char opcode,unsigned char p5,char* data,unsigned int p7,unsigned int p8,unsigned int p9) {
    if (!multiplayer) return 0;
    switch (opcode) {
    case 0x44: {
        speed->SetPlayerTurnSpeed((int)player, (unsigned char)data[9], (unsigned char)data[8]);
        if ((mode < 5 || current_turn < 6) && *(unsigned int*)(data+4) < current_turn) {
            log_printf(DAT_0062c4fc,(const char*)0x5816D0, current_turn, *(unsigned int*)(data+4));
            return 0;
        }
        unsigned int v = *(unsigned int*)(data+4) - latencyBase;
        if (v <= lastTurn[player]) v = lastTurn[player];
        lastTurn[player] = v;
        return 1;
    }
    case 0x45:
        recv1((int)player, *(int*)data); return 1;
    case 0x46: {
        int* p=(int*)data;
        stats->call330A0((int)player,p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]); return 1;
    }
    case 0x47:
        recv2(a1,a3,p7,p8,p9,0); return 1;
    case 0x48:
        speed->set_32840(*(unsigned short*)data, *(unsigned short*)(data+2), p5); return 1;
    case 0x49: {
        char* text=data+0x11;
        log_printf(DAT_0062c4fc,(const char*)0x58167C, a1,p8,p9,text,*(int*)(data+0x0c),p7,data[0x10]);
        if (((char*)localPlayer)[(unsigned int)data + 1] == 'Y' || mode == 3) chat->show(playerNames + ((unsigned char)data[0]<<7), text, 0);
        return 1;
    }
    case 0x4a:
        log_printf(DAT_0062c4fc,(const char*)0x581664); recv4((int)p5); stats->call33460(0,0,0,0,0,0,0,0,0); return 1;
    case 0x4b:
        log_printf(DAT_0062c4fc,(const char*)0x581654); recv3((int)p5); return 1;
    case 0x4c:
        if (some1c) { recv5(0); log_printf(DAT_0062c4fc,(const char*)0x581638); recv3((int)p5); return 1; } break;
    case 0x4d:
        if (some1c) { recv5(1); recv4((int)player); return 1; } break;
    case 0x4e: {
        log_printf(DAT_0062c4fc,(const char*)0x58160C, player, *(int*)data);
        int id = *(int*)(data+4); int found=0;
        if (id) for (int i=minPlayer;i<=maxPlayer;i++) if (((int*)((char*)this+0x1564))[i]==id) { found=i; break; }
        if (found>0) { if (!playerFlags[found]) add_player(found,id); if (found==localPlayer) update_ui(0x17AA); else if (!playerFlags[found]) update_ui(0x17B3); return 1; }
        break;
    }
    case 0x4f:
        if (!some1c) { log_printf(DAT_0062c4fc,(const char*)0x5815D8); return 1; } break;
    default:
        log_printf(DAT_0062c4fc,(const char*)0x5815BC, opcode, opcode); break;
    }
    return 1;
}
