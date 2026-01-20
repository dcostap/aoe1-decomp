#pragma once
#include "common.h"

struct COMMPLAYEROPTIONS {
    uchar NeedsToBeSent;
    ulong LastSentTime;
    COMMSTATES ProgramState;
    ulong CurrentTurn;
    uchar TurnSpeedMsec;
    ulong dcoID[10];
    ulong AcknowledgeAfterMsec;
    uchar CommandTurnIncrement;
    int PlayerReady[10];
    ulong User1[10];
    ulong User2[10];
    ulong User3[10];
    ulong User4[10];
    ulong User5[10];
    ulong User6[10];
    ulong User7[10];
    PLAYERHUMANITY Humanity[10];
    uchar InvalidPlayer[10];
    ulong Initialized;
    ulong RandomSeed;
    ushort HighPlayerNumber;
    ushort LowPlayerNumber;
    uint HostPlayerNumber;
    int GameHasStarted;
    ulong DataSizeToFollow;
};
static_assert(sizeof(COMMPLAYEROPTIONS) == 0x1D0, "Size mismatch");
