#ifndef COM_SYNC_CONTEXT_H
#define COM_SYNC_CONTEXT_H

#include "debuglog.h"

// Canonical declarations used by the com_sync.cpp owner sequence.
// The individual owners keep their narrow standalone declarations for the
// default per-function checks.  The unregistered TU wrapper selects this
// complete period source context instead.

// The PDB-qualified 00428280 call is
// TCommunications_Handler::NotifyWindowParam(enum COMMMESSAGES, long).
// Keep the enum type in this owner context so its direct target keeps the
// original decorated ABI.
enum COMMMESSAGES {
    COMMMESSAGE_SYNC_ERROR = 0x17B0
};

class TCommunications_Handler {
public:
    void NotifyWindowParam(COMMMESSAGES msg, long param);
    int WhoAmI();
    void SendChatMsgAll(const char* message);
    long SendChecksumMessage(unsigned long worldTime, unsigned int random,
                             long checksum, long checksum1, long checksum2,
                             long checksum3, long checksum4);
    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    int GetPlayerHumanity(unsigned int player);
    char* GetPlayerName(unsigned int player);
};

extern TDebuggingLog* L;
#define g_debuggingLog L

struct RGE_Communications_Check {
    int PlayerNo;
    unsigned long WTime;
    unsigned long WTurn;
    long cs1;
    long cs2;
    long cs3;
    long cs4;
    long cs5;
    unsigned long Random;
};

class RGE_Visible_Map {
public:
    unsigned long checksumUnifiedVisible();
    long checksumVisible();
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible;
};

class RGE_Game_World {
public:
    char gap_00[4];
    unsigned long world_time;
    char gap_08[0x34];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
    unsigned char GetWorldChecksums(long& checksum1, long& checksum2,
                                    long& checksum3);
    long GetChecksum(long player);
};

extern RGE_Base_Game* rge_base_game;

class PathingSystem {
public:
    long checksum();
};

extern PathingSystem pathSystem;
extern long DAT_0062D208[9];
extern unsigned long DAT_0062D230;

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* comm;
    unsigned long checkTime;
    unsigned long checkTurn;
    int stopOnSyncFail;
    int dialogOnSyncFail;
    int sendChatMsgs;
    int newData;
    int lastResult;
    unsigned int offset;
    int doChecksums;
    unsigned long lastWorldRandom;
    unsigned long gameWorldChecksum;
    RGE_Communications_Check check[0x37];

    RGE_Communications_Synchronize(TCommunications_Handler* comm);
    ~RGE_Communications_Synchronize();
    int Add(unsigned int turn, unsigned long wRandom,
            unsigned long checksum1, unsigned long checksum2,
            long chatCrc, long dataCrc, long a7, long a8, long a9);

protected:
    int ValidateChecksums(unsigned int turn, unsigned long wRandom,
                          unsigned long checksum1, unsigned long checksum2,
                          long chatCrc, long dataCrc, long a7, long a8,
                          long a9);

public:
    unsigned long DoChecksum(unsigned long turn);
    void SetLastWorldRandom(unsigned long value);
    void LogChecksums(unsigned int playerNo, unsigned long worldTime,
                      unsigned long commTurn, long unifiedVisible,
                      long checksumNew, long position, long action,
                      long obstruction, unsigned long random);
    void EnableSyncChecking(int value);
    void SetStopOnFail(int value);
    void SetDialogOnFail(int value);
    void SendChatMsgsAtChecksum(int value);
    int IsPlayerOutOfSync(unsigned int playerNo, unsigned long commTurn);
};

#define Comm comm
#define CheckTime checkTime
#define CheckTurn checkTurn
#define StopOnSyncFail stopOnSyncFail
#define DialogOnSyncFail dialogOnSyncFail
#define SendChatMsgs sendChatMsgs
#define NewData newData
#define LastResult lastResult
#define Offset offset
#define DoChecksums doChecksums
#define LastWorldRandom lastWorldRandom
#define GameWorldChecksum gameWorldChecksum
#define Check check

#endif
