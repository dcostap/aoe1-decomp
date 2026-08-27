// VA: 00433460 LogChecksums (1579B)
// com_sync.cpp lines 207-322
//
// Attempt log:
// - Replaced the placeholder with the period-plausible file/debug report,
//   checksum-record diagnostics, and per-player checksum report.
// - The typed record-base scan was structurally close but started at +54;
//   the executable proves a WTime anchor at +58 with a 9-dword stride, so the
//   named checksum fields are read through that interior cursor.
// - This anchor/stride reconstruction is exact; no custom flags or opaque
//   control-flow scaffolding are used.
//
// Exact-finish retrospective:
// - The reduced source passes the authoritative checker: MATCH, 1579/1579
//   bytes, the qualified member symbol, 0x20C frame, and 67 ordered calls.
// - Required source shape is the direct file-write sequence, the WTime
//   interior cursor with its 9-dword update, and the direct player publication
//   scan.  These preserve the shipped null-file fault order.
// - The declaration guard is required by the authentic grouped TU context;
//   it prevents duplicate declarations without adding a second VA owner.
// - No custom flags, aliases, cached reads, volatility, or assembly remain.

#include <stdio.h>
#include <string.h>

#ifndef COM_SYNC_TU_CONTEXT
class TDebuggingLog {
public:
    void Log(const char* format, ...);
};

extern TDebuggingLog* L;

class TCommunications_Handler {
public:
    int IsPlayerHuman(unsigned int player);
    int IsPlayerComputer(unsigned int player);
    char* GetPlayerName(unsigned int player);
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];

    long GetChecksum(long player);
};

extern RGE_Base_Game* rge_base_game;
extern long DAT_0062D208[9];

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

class RGE_Communications_Synchronize {
public:
    TCommunications_Handler* Comm;
    unsigned long CheckTime;
    unsigned long CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    unsigned int Offset;
    int DoChecksums;
    unsigned long LastWorldRandom;
    unsigned long GameWorldChecksum;
    RGE_Communications_Check Check[0x37];

    void LogChecksums(unsigned int playerNo, unsigned long worldTime,
                      unsigned long commTurn, long unifiedVisible,
                      long checksumNew, long position, long action,
                      long obstruction, unsigned long random);
};
#endif

void RGE_Communications_Synchronize::LogChecksums(
    unsigned int playerNo, unsigned long worldTime, unsigned long commTurn,
    long unifiedVisible, long checksumNew, long position, long action,
    long obstruction, unsigned long random) {
    char TBuff[513];
    FILE* file = fopen("C:\\aoesync.txt", "wt");

    sprintf(TBuff,
            "Adding:  P#%d  WTime=%d  Turn=%d Cs1=%d  Cs2=%d  Cs3=%d  Cs4=%d  Cs5=%d  Rand=%d",
            playerNo, worldTime, commTurn, unifiedVisible, checksumNew,
            position, action, obstruction, random);
    L->Log(TBuff);
    if (file != 0) {
        fputs(TBuff, file);
        fputs("\n", file);
    }

    sprintf(TBuff,
            "Plr: Wrldtime CommTurn Random WChecksum CksumNew Position Actions  Unif. Visible");
    L->Log(TBuff);
    if (file != 0) {
        fputs(TBuff, file);
        fputs("\n", file);
    }

    unsigned long* check = &this->Check[1].WTime;
    int count = 0x35;
    do {
        sprintf(TBuff,
                " %.2d: %.8d %.8d %.6d %.8d %.8d %.8d %.8d %.8d ",
                check[-1], check[0], check[1],
                check[7], check[2], check[3], check[4],
                check[5], check[6]);
        L->Log(TBuff);
        if (file != 0) {
            fputs(TBuff, file);
            fputs("\n", file);
        }

        if (check[1] == commTurn && check[0] != worldTime) {
            sprintf(TBuff,
                    "=====>  WORLD TIME IS OUT OF SYNC  (%d should be %d at turn %d)",
                    worldTime, check[0], commTurn);
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }
        }

        if (check[0] == worldTime) {
            if (check[7] != random) {
                sprintf(TBuff,
                        "=====>  MISMATCHED RANDOM ( %d should be %d)",
                        random, check[7]);
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (check[2] != unifiedVisible) {
                sprintf(TBuff,
                        "=====>  MISMATCHED Unified Visible Map");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (check[3] != checksumNew) {
                sprintf(TBuff,
                        "=====>  MISMATCHED CHECKSUM...New");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (check[4] != position) {
                sprintf(TBuff,
                        "=====>  MISMATCHED..Position");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (check[5] != action) {
                sprintf(TBuff,
                        "=====>  MISMATCHED...Action");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (check[6] != obstruction) {
                sprintf(TBuff,
                        "=====>  MISMATCHED...ObstructionMap Checksums");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
        }

        check += 9;
        --count;
    } while (count != 0);

    strcpy(TBuff, "Player Checksum information:");
    L->Log(TBuff);
    if (file != 0) {
        fputs(TBuff, file);
        fputs("\n", file);
    }

    unsigned int player = 0;
    long* visible = DAT_0062D208;
    do {
        if (this->Comm->IsPlayerHuman(player) ||
            this->Comm->IsPlayerComputer(player)) {
            strcpy(TBuff, " \n");
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }

            sprintf(TBuff, "PLAYER: %s",
                    this->Comm->GetPlayerName(player));
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }

            sprintf(TBuff, "P#%d CSum=%d ", player,
                    rge_base_game->GetChecksum(player));
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }

            sprintf(TBuff, "VISIBLE Checksum = %d", *visible);
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }
        }

        ++player;
        ++visible;
    } while (visible < DAT_0062D208 + 9);

    strcpy(TBuff, "...end of log");
    L->Log(TBuff);
    if (file != 0) {
        fputs(TBuff, file);
        fputs("\n", file);
    }

    fclose(file);
}
