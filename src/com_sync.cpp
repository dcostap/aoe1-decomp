
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
    TCommunications_Handler* c) {
    Comm = c;
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
    unsigned int player, unsigned long worldtime, unsigned long worldturn,
    unsigned long worldrandom, long cs1, long cs2, long cs3, long cs4,
    long cs5) {
    if (!this->DoChecksums) {
        return 0;
    }

    this->Offset++;
    if ((unsigned)this->Offset >= 0x36u) {
        this->Offset = 0;
    }

    this->Check[this->Offset].WTime = worldtime;
    this->Check[this->Offset].WTurn = worldturn;
    this->Check[this->Offset].cs1 = cs1;
    this->Check[this->Offset].cs2 = cs2;
    this->Check[this->Offset].cs3 = cs3;
    this->Check[this->Offset].cs4 = cs4;
    this->Check[this->Offset].cs5 = cs5;
    this->Check[this->Offset].Random = worldrandom;
    this->Check[this->Offset].PlayerNo = player;

    this->NewData = 1;
    return this->ValidateChecksums(player, worldtime, worldturn, worldrandom,
                                   cs1, cs2, cs3, cs4, cs5);
}

int RGE_Communications_Synchronize::ValidateChecksums(
    unsigned int player, unsigned long worldtime, unsigned long worldturn,
    unsigned long worldrandom, long cs1, long cs2, long cs3, long cs4,
    long cs5) {
    int bad = 0;

    if (!this->NewData) {
        return this->LastResult;
    }

    this->NewData = 0;
    this->LastResult = 0;

    unsigned int i = 1;
    RGE_Communications_Check* check = &this->Check[1];
    for (; i <= 0x36; ++i, ++check) {
        if (check->WTurn == worldturn) {
            if (check->WTime != worldtime) {
                bad = 1;
            }
        }

        if (check->WTime == worldtime) {
            if (check->cs1 != cs1 || check->cs2 != cs2 ||
                check->cs3 != cs3 || check->cs4 != cs4 ||
                check->cs5 != cs5 || check->Random != worldrandom) {
                bad = 1;
            }
        }

        if (bad) {
            this->LogChecksums(player, worldtime, worldturn, cs1, cs2, cs3,
                               cs4, cs5, worldrandom);
            this->Comm->NotifyWindowParam((COMMMESSAGES)0x17B0, worldturn);
            this->LastResult = 0;
            return 0;
        }
    }

    L->Log("P#%d In Sync @ Wtime=%d WTurn=%d Wrand=%d Wchksum=%d",
           player, worldtime, worldturn, worldrandom, cs1);
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

void RGE_Communications_Synchronize::SetLastWorldRandom(unsigned long lwr) {
    this->LastWorldRandom = lwr;
}

void RGE_Communications_Synchronize::LogChecksums(
    unsigned int player, unsigned long worldtime, unsigned long worldturn,
    long cs1, long cs2, long cs3, long cs4, long cs5,
    unsigned long random) {
    char TBuff[513];
    FILE* file = fopen("C:\\aoesync.txt", "wt");

    sprintf(TBuff,
            "Adding:  P#%d  WTime=%d  Turn=%d Cs1=%d  Cs2=%d  Cs3=%d  Cs4=%d  Cs5=%d  Rand=%d",
            player, worldtime, worldturn, cs1, cs2, cs3, cs4, cs5, random);
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

        if (entry.WTurn == worldturn && entry.WTime != worldtime) {
            sprintf(TBuff,
                    "=====>  WORLD TIME IS OUT OF SYNC  (%d should be %d at turn %d)",
                    worldtime, entry.WTime, worldturn);
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }
        }

        if (entry.WTime == worldtime) {
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
            if (entry.cs1 != cs1) {
                sprintf(TBuff,
                        "=====>  MISMATCHED Unified Visible Map");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs2 != cs2) {
                sprintf(TBuff,
                        "=====>  MISMATCHED CHECKSUM...New");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs3 != cs3) {
                sprintf(TBuff,
                        "=====>  MISMATCHED..Position");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs4 != cs4) {
                sprintf(TBuff,
                        "=====>  MISMATCHED...Action");
                L->Log(TBuff);
                if (file != 0) {
                    fputs(TBuff, file);
                    fputs("\n", file);
                }
            }
            if (entry.cs5 != cs5) {
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

    unsigned int player_index = 0;
    long* visible = DAT_0062D208;
    do {
        if (this->Comm->IsPlayerHuman(player_index) ||
            this->Comm->IsPlayerComputer(player_index)) {
            strcpy(TBuff, " \n");
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }

            sprintf(TBuff, "PLAYER: %s",
                    this->Comm->GetPlayerName(player_index));
            L->Log(TBuff);
            if (file != 0) {
                fputs(TBuff, file);
                fputs("\n", file);
            }

            sprintf(TBuff, "P#%d CSum=%d ", player_index,
                    rge_base_game->GetChecksum(player_index));
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

        ++player_index;
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

void RGE_Communications_Synchronize::EnableSyncChecking(int Status) {
    this->DoChecksums = Status;
}

void RGE_Communications_Synchronize::SetStopOnFail(int Status) {
    this->StopOnSyncFail = Status;
}

void RGE_Communications_Synchronize::SetDialogOnFail(int Status) {
    this->DialogOnSyncFail = Status;
}

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int Status) {
    this->SendChatMsgs = Status;
}

int RGE_Communications_Synchronize::IsPlayerOutOfSync(
    unsigned int pnum, unsigned long worldturn) {
    int NumDiff = 0;
    int NumSame = 0;
    int foundMine = 0;

    unsigned long myWorldTime = 0;
    long mycs1 = 0;
    long mycs2 = 0;
    long mycs3 = 0;
    long mycs4 = 0;
    long mycs5 = 0;
    unsigned int myRandom = 0;
    int NumPlayers = 0;

    unsigned int i;
    for (i = 1; i <= 0x36; i++) {
        CHECKSUMARRAY& entry = this->Check[i];
        if (entry.PlayerNo == pnum && entry.WTurn == worldturn) {
            foundMine = 1;
            myWorldTime = entry.WTime;
            mycs1 = entry.cs1;
            mycs2 = entry.cs2;
            mycs3 = entry.cs3;
            mycs4 = entry.cs4;
            mycs5 = entry.cs5;
            myRandom = entry.Random;
            break;
        }
    }

    if (!foundMine) {
        L->Log("OUTOFSYNC: DIDN'T FIND MY VALUES");
        return 0;
    }

    L->Log("OUTOFSYNC: my values: %d %d %d %d %d %d",
           myWorldTime, mycs1, mycs2, mycs3, mycs4, mycs5);

    for (i = 1; i <= 0x36; i++) {
        CHECKSUMARRAY& entry = this->Check[i];
        if (entry.PlayerNo != pnum && entry.WTurn == worldturn) {
            if (entry.WTime == myWorldTime && entry.cs1 == mycs1 &&
                entry.cs2 == mycs2 && entry.cs3 == mycs3 &&
                entry.cs4 == mycs4 && entry.cs5 == mycs5 &&
                entry.Random == myRandom) {
                NumSame++;
                L->Log("OUTOFSYNC: %d same: %d %d %d %d %d %d",
                       i, myWorldTime, mycs1, mycs2, mycs3, mycs4,
                       mycs5);
            }
            else {
                NumDiff++;
                L->Log("OUTOFSYNC: %d diff: %d %d %d %d %d %d",
                       i, myWorldTime, mycs1, mycs2, mycs3, mycs4,
                       mycs5);
            }
        }
    }

    for (i = 1; i <= 9; i++) {
        if (this->Comm->GetPlayerHumanity(i) == ME_HUMAN) {
            NumPlayers++;
        }
    }

    L->Log("OUTOFSYNC: numplayers=%d, diff=%d, same=%d",
           NumPlayers, NumDiff, NumSame);

    if (NumDiff + NumSame < NumPlayers - 1) {
        L->Log("OUTOFSYNC: return not out");
        return 0;
    }

    if (NumDiff > NumSame) {
        L->Log("OUTOFSYNC: return out");
        return 1;
    }

    L->Log("OUTOFSYNC: return not out 2");
    return 0;
}
