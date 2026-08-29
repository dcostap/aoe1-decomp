
#include "../include/com_hand.h"
#include "../include/debuglog.h"
#include "../include/basegame.h"
#include "../include/pathsys.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/visible.h"
#include "../include/world.h"
#include "../include/com_sync.h"

#include <stdio.h>
#include <string.h>

extern TDebuggingLog* L;

// dwords at 0062D208: DoChecksum writes player slots 1 through 8, and
// LogChecksums reads the base slot plus those eight player slots. The
// checksumVisible result is a long. 0062D230 is one unsigned long result.
extern long DAT_0062D208[9];
extern unsigned long DAT_0062D230;

RGE_Communications_Synchronize::RGE_Communications_Synchronize(
    TCommunications_Handler* handler) {
    Comm = handler;
    CheckTime = 1000;
    CheckTurn = 10;

    L->Log("Check turn = %d", 10);

    StopOnSyncFail = 1;
    DoChecksums = 1;
    LastResult = 1;
    NewData = 0;
    Offset = 0;
    LastWorldRandom = 0;
    GameWorldChecksum = 0;
    SendChatMsgs = 0;
    DialogOnSyncFail = 0;

    int i;
    for (i = 0; i < 0x37; i++) {
        CHECKSUMARRAY& entry = this->Check[i];
        entry.WTime = 0;
        entry.WTurn = 0;
        entry.cs1 = 0;
        entry.cs2 = 0;
        entry.cs3 = 0;
        entry.cs4 = 0;
        entry.cs5 = 0;
        entry.Random = 0;
        entry.PlayerNo = 0;
    }
}

RGE_Communications_Synchronize::~RGE_Communications_Synchronize() {
    for (int i = 0; i < 0x37; i++) {
        CHECKSUMARRAY& entry = this->Check[i];
        entry.WTime = 0;
        entry.WTurn = 0;
        entry.cs1 = 0;
        entry.cs2 = 0;
        entry.cs3 = 0;
        entry.cs4 = 0;
        entry.cs5 = 0;
        entry.Random = 0;
        entry.PlayerNo = 0;
    }
}

int RGE_Communications_Synchronize::Add(
    unsigned int turn, unsigned long wRandom, unsigned long checksum1,
    unsigned long checksum2, long chatCrc, long dataCrc,
    long a7, long a8, long a9) {
    if (!this->DoChecksums) {
        return 0;
    }

    this->Offset++;
    if ((unsigned)this->Offset >= 0x36u) {
        this->Offset = 0;
    }

    this->Check[this->Offset].WTime = wRandom;
    this->Check[this->Offset].WTurn = checksum1;
    this->Check[this->Offset].cs1 = chatCrc;
    this->Check[this->Offset].cs2 = dataCrc;
    this->Check[this->Offset].cs3 = a7;
    this->Check[this->Offset].cs4 = a8;
    this->Check[this->Offset].cs5 = a9;
    this->Check[this->Offset].Random = checksum2;
    this->Check[this->Offset].PlayerNo = turn;

    this->NewData = 1;
    return this->ValidateChecksums(turn, wRandom, checksum1, checksum2,
                                   chatCrc, dataCrc, a7, a8, a9);
}

int RGE_Communications_Synchronize::ValidateChecksums(
    unsigned int turn, unsigned long wRandom, unsigned long checksum1,
    unsigned long checksum2, long chatCrc, long dataCrc, long a7,
    long a8, long a9) {
    int bad = 0;

    if (!this->NewData) {
        return this->LastResult;
    }

    this->NewData = 0;
    this->LastResult = 0;

    unsigned int i = 1;
    RGE_Communications_Check* check = &this->Check[1];
    for (; i <= 0x36; ++i, ++check) {
        if (check->WTurn == checksum1) {
            if (check->WTime != wRandom) {
                bad = 1;
            }
        }

        if (check->WTime == wRandom) {
            if (check->cs1 != chatCrc || check->cs2 != dataCrc ||
                check->cs3 != a7 || check->cs4 != a8 ||
                check->cs5 != a9 || check->Random != checksum2) {
                bad = 1;
            }
        }

        if (bad) {
            this->LogChecksums(turn, wRandom, checksum1, chatCrc, dataCrc,
                               a7, a8, a9, checksum2);
            this->Comm->NotifyWindowParam((COMMMESSAGES)0x17B0, checksum1);
            this->LastResult = 0;
            return 0;
        }
    }

    L->Log("P#%d In Sync @ Wtime=%d WTurn=%d Wrand=%d Wchksum=%d",
           turn, wRandom, checksum1, checksum2, chatCrc);
    this->LastResult = 1;
    return 1;
}

unsigned long RGE_Communications_Synchronize::DoChecksum(
    unsigned long turn) {
    unsigned long worldTime = 0;

    if (!this->DoChecksums) {
        return 0;
    }

    if (rge_base_game->world != 0) {
        worldTime = rge_base_game->world->world_time;
    }

    if (turn < (unsigned long)this->CheckTurn) {
        return 0;
    }

    L->Log("Sync check at turn #%d", this->CheckTurn);
    this->CheckTurn += 4;

    long cs4 = 0;
    long cs2 = 0;
    long cs3 = 0;
    char tmp[255];
    rge_base_game->GetWorldChecksums(cs4, cs2, cs3);

    if (this->SendChatMsgs) {
        sprintf(tmp, "Worldtime=%ld Random=%d Checksum=%d",
                worldTime, this->LastWorldRandom, this->GameWorldChecksum);
        this->Comm->SendChatMsgAll(tmp);
    }

    DAT_0062D230 = rge_base_game->world->players[0]->visible->checksumUnifiedVisible();

    int i = 1;
    RGE_Game_World* world = rge_base_game->world;
    if (i < world->player_num) {
        do {
            DAT_0062D208[i] = world->players[i]->visible->checksumVisible();
            ++i;
            world = rge_base_game->world;
        } while (i < world->player_num);
    }

    unsigned long unifiedChecksum = DAT_0062D230;
    long pathChecksum = pathSystem.checksum();

    this->Add(this->Comm->WhoAmI(), worldTime, turn,
              this->LastWorldRandom, unifiedChecksum,
              cs4, cs2, cs3, pathChecksum);

    this->Comm->SendChecksumMessage(worldTime, this->LastWorldRandom,
                                    unifiedChecksum, cs4, cs2,
                                    cs3, pathChecksum);

    L->Log("Checksum: T#%d wt=%d   rand=%d  csum=%d", turn, worldTime,
           this->LastWorldRandom, this->GameWorldChecksum);
    L->FlushLog();
    return 1;
}

void RGE_Communications_Synchronize::SetLastWorldRandom(unsigned long value) {
    this->LastWorldRandom = value;
}

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

    int count = 0x35;
    int index = 1;
    do {
        CHECKSUMARRAY& entry = this->Check[index];
        sprintf(TBuff,
                " %.2d: %.8d %.8d %.6d %.8d %.8d %.8d %.8d %.8d ",
                entry.PlayerNo, entry.WTime, entry.WTurn,
                entry.Random, entry.cs1, entry.cs2, entry.cs3,
                entry.cs4, entry.cs5);
        L->Log(TBuff);
        if (file != 0) {
            fputs(TBuff, file);
            fputs("\n", file);
        }

        if (entry.WTurn == commTurn && entry.WTime != worldTime) {
            sprintf(TBuff,
                    "=====>  WORLD TIME IS OUT OF SYNC  (%d should be %d at turn %d)",
                    worldTime, entry.WTime, commTurn);
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }
        }

        if (entry.WTime == worldTime) {
            if (entry.Random != random) {
                sprintf(TBuff,
                        "=====>  MISMATCHED RANDOM ( %d should be %d)",
                        random, entry.Random);
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs1 != unifiedVisible) {
                sprintf(TBuff,
                        "=====>  MISMATCHED Unified Visible Map");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs2 != checksumNew) {
                sprintf(TBuff,
                        "=====>  MISMATCHED CHECKSUM...New");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs3 != position) {
                sprintf(TBuff,
                        "=====>  MISMATCHED..Position");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs4 != action) {
                sprintf(TBuff,
                        "=====>  MISMATCHED...Action");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs5 != obstruction) {
                sprintf(TBuff,
                        "=====>  MISMATCHED...ObstructionMap Checksums");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
        }

        ++index;
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

void RGE_Communications_Synchronize::EnableSyncChecking(int value) {
    this->DoChecksums = value;
}

void RGE_Communications_Synchronize::SetStopOnFail(int value) {
    this->StopOnSyncFail = value;
}

void RGE_Communications_Synchronize::SetDialogOnFail(int value) {
    this->DialogOnSyncFail = value;
}

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int value) {
    this->SendChatMsgs = value;
}

// separate matching pass is complete.
int RGE_Communications_Synchronize::IsPlayerOutOfSync(
    unsigned int playerNo, unsigned long commTurn) {
    unsigned long myWorldTime = 0;
    int differentCount = 0;
    int sameCount = 0;
    long myUnifiedVisible = 0;
    long myChecksumNew = 0;
    long myPositionChecksum = 0;
    long myActionChecksum = 0;
    long myObstructionChecksum = 0;
    int foundMyValues = 0;
    unsigned long myRandom = 0;
    int humanPlayerCount = 0;

    unsigned int recordIndex = 1;
    for (; recordIndex <= 0x36; ++recordIndex) {
        CHECKSUMARRAY& entry = this->Check[recordIndex];
        if (entry.PlayerNo == playerNo && entry.WTurn == commTurn) {
            myChecksumNew = entry.cs2;
            myPositionChecksum = entry.cs3;
            myWorldTime = entry.WTime;
            myActionChecksum = entry.cs4;
            myObstructionChecksum = entry.cs5;
            myUnifiedVisible = entry.cs1;
            myRandom = entry.Random;
            foundMyValues = 1;
            break;
        }
    }

    if (!foundMyValues) {
        L->Log("OUTOFSYNC: DIDN'T FIND MY VALUES");
        return 0;
    }

    L->Log("OUTOFSYNC: my values: %d %d %d %d %d %d",
           myWorldTime, myUnifiedVisible, myChecksumNew,
           myPositionChecksum, myActionChecksum, myObstructionChecksum);

    recordIndex = 1;
    do {
        CHECKSUMARRAY& entry = this->Check[recordIndex];
        if (entry.PlayerNo != playerNo && commTurn == entry.WTurn) {
            if (myWorldTime == entry.WTime &&
                myUnifiedVisible == entry.cs1 &&
                myChecksumNew == entry.cs2 &&
                myPositionChecksum == entry.cs3 &&
                myActionChecksum == entry.cs4 &&
                myObstructionChecksum == entry.cs5 &&
                myRandom == entry.Random) {
                ++sameCount;
                L->Log("OUTOFSYNC: %d same: %d %d %d %d %d %d",
                       recordIndex, myWorldTime, myUnifiedVisible,
                       entry.WTurn, myPositionChecksum,
                       myActionChecksum, myObstructionChecksum);
            } else {
                ++differentCount;
                L->Log("OUTOFSYNC: %d diff: %d %d %d %d %d %d",
                       recordIndex, myWorldTime, myUnifiedVisible,
                       entry.WTurn, myPositionChecksum,
                       myActionChecksum, myObstructionChecksum);
            }
        }
        ++recordIndex;
    } while (recordIndex <= 0x36);

    int playerIndex = 1;
    do {
        if (this->Comm->GetPlayerHumanity(playerIndex) == 2) {
            ++humanPlayerCount;
        }
        ++playerIndex;
    } while (playerIndex <= 9);

    L->Log("OUTOFSYNC: numplayers=%d, diff=%d, same=%d",
           humanPlayerCount, differentCount, sameCount);

    if (sameCount + differentCount < humanPlayerCount - 1) {
        L->Log("OUTOFSYNC: return not out");
        return 0;
    }

    if (differentCount > sameCount) {
        L->Log("OUTOFSYNC: return out");
        return 1;
    }

    L->Log("OUTOFSYNC: return not out 2");
    return 0;
}
