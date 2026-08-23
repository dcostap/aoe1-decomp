// 00429A90 TCommunications_Handler::SendIResignMsg (Com_hand.cpp:2890-2924, 313B)
// Sends RSGN followed by 3 DONE messages with latency stats.
// Early return if Multiplayer flag at +0x10E4 is zero.
//
// Fields:
//   +0x10C8 = current_turn (int)
//   +0x10E4 = Multiplayer (int)
//   +0x14D4 = Speed (RGE_Communications_Speed*)
//   +0x1590 = CommandTurnIncrement (unsigned char)
//
// CommOut is __thiscall with 5 stack params (ret 14h cleans all).
// Log is __cdecl with 3 params (add esp, 0Ch after call).
// FLAGS: /nologo /c /O2 /Oy

extern "C" {
    extern void* L; // TDebuggingLog* at [62C4FCh]
    void __cdecl Log(void* log, const char* fmt, int val);
}

struct TCommunicationsHandler3 {
    char _pad_10C8[0x10C8];
    int current_turn;                           // +0x10C8
    char _pad_10CC[0x10E4 - 0x10CC];
    int Multiplayer;                            // +0x10E4
    char _pad_10E8[0x14D4 - 0x10E8];
    struct SpeedType3 {
        unsigned char GetHighLatencyCenti();
        unsigned char GetAvgFrameRate();
    }* Speed;                                   // +0x14D4
    char _pad_14D8[0x1590 - 0x14D8];
    unsigned char CommandTurnIncrement;          // +0x1590

    long CommOut(int type, int msg_type, void* data, long size, int flags);
    void SendIResignMsg();
};

void TCommunicationsHandler3::SendIResignMsg()
{
    if (Multiplayer == 0) return;

    int all_done;
    char done[12];

    // RSGN message
    all_done = current_turn + CommandTurnIncrement;
    Log(L, "  >TX RSGN (%d)", 4);
    CommOut(0, 0x51, &all_done, 4, 0);

    // Speed stats (set once, reused across 3 DONE messages)
    done[8] = Speed->GetHighLatencyCenti();
    done[9] = Speed->GetAvgFrameRate();

    // DONE 1: turn + inc + 1
    done[0] = 0x44;
    *(int*)&done[4] = current_turn + (unsigned char)CommandTurnIncrement + 1;
    Log(L, "  >TX DONE (%d)", 0x0C);
    CommOut(0, 0x44, done, 0x0C, 0);

    // DONE 2: turn + inc + 2
    *(int*)&done[4] = current_turn + (unsigned char)CommandTurnIncrement + 2;
    Log(L, "  >TX DONE (%d)", 0x0C);
    CommOut(0, 0x44, done, 0x0C, 0);

    // DONE 3: turn + inc + 3
    *(int*)&done[4] = current_turn + (unsigned char)CommandTurnIncrement + 3;
    Log(L, "  >TX DONE (%d)", 0x0C);
    CommOut(0, 0x44, done, 0x0C, 0);
}
