// Authentic com_sync.cpp owner sequence.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\com_sync.cpp
// The owner order follows the original source lines and address order.

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
extern long DAT_0062D208[9];
extern unsigned long DAT_0062D230;

// com_sync.cpp:23-27
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

    unsigned long* base = &this->Check[0].WTurn;
    int i;
    for (i = 0; i < 0x37; i++) {
        base[-1] = 0;
        base[0] = 0;
        base[1] = 0;
        base[2] = 0;
        base[3] = 0;
        base[4] = 0;
        base[5] = 0;
        base[6] = 0;
        base[-2] = 0;
        base += 9;
    }
}

// com_sync.cpp:30-32
RGE_Communications_Synchronize::~RGE_Communications_Synchronize() {
    unsigned long* p = &this->Check[0].WTurn;
    int i = 0x37;

    do {
        p[-1] = 0;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[-2] = 0;
        p += 9;
        i = i - 1;
    } while (i != 0);
}

// com_sync.cpp:44-62
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

// com_sync.cpp:74-125
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

// com_sync.cpp:129-195
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

// com_sync.cpp:200-202
void RGE_Communications_Synchronize::SetLastWorldRandom(unsigned long value) {
    this->LastWorldRandom = value;
}

// com_sync.cpp:207-322
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

// com_sync.cpp:325-327
void RGE_Communications_Synchronize::EnableSyncChecking(int value) {
    this->DoChecksums = value;
}

// com_sync.cpp:330-332
void RGE_Communications_Synchronize::SetStopOnFail(int value) {
    this->StopOnSyncFail = value;
}

// com_sync.cpp:335-337
void RGE_Communications_Synchronize::SetDialogOnFail(int value) {
    this->DialogOnSyncFail = value;
}

// com_sync.cpp:340-342
void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int value) {
    this->SendChatMsgs = value;
}

// com_sync.cpp:345-435
// This owner remains scratch. Keep its source body in the module until its
// separate matching pass is complete.
int RGE_Communications_Synchronize::IsPlayerOutOfSync(
    unsigned int playerNo, unsigned long commTurn) {
    unsigned long uVar5;
    unsigned long* puVar8 = &this->Check[1].WTurn;
    int NumPlayers;
    int NumDiff;
    long lVar6;
    long mycs5;
    long mycs2;
    long mycs3;
    int NumSame;
    int myRandom;
    unsigned int local_8;
    int foundMine;

    uVar5 = 0;
    NumPlayers = 0;
    NumDiff = 0;
    lVar6 = 0;
    mycs5 = 0;
    mycs2 = 0;
    mycs3 = 0;
    NumSame = 0;
    myRandom = 0;
    local_8 = 0;
    foundMine = 0;

    unsigned long* puVar2 = puVar8;
    unsigned int firstIndex = 1;
    for (; firstIndex <= 0x36; ++firstIndex, puVar2 += 9) {
        if (this->Check[firstIndex].PlayerNo == playerNo &&
            this->Check[firstIndex].WTurn == commTurn) {
            mycs5 = this->Check[firstIndex].cs2;
            mycs2 = this->Check[firstIndex].cs3;
            uVar5 = this->Check[firstIndex].WTime;
            mycs3 = this->Check[firstIndex].cs4;
            NumSame = this->Check[firstIndex].cs5;
            lVar6 = this->Check[firstIndex].cs1;
            local_8 = this->Check[firstIndex].Random;
            myRandom = 1;
            break;
        }
    }

    if (!myRandom) {
        L->Log("OUTOFSYNC: DIDN'T FIND MY VALUES");
        return 0;
    }

    L->Log("OUTOFSYNC: my values: %d %d %d %d %d %d",
           uVar5, lVar6, mycs5, mycs2, mycs3, NumSame);

    unsigned int i = 1;
    do {
        if (puVar8[-2] != playerNo && commTurn == puVar8[0]) {
            if (uVar5 == puVar8[-1] &&
                lVar6 == puVar8[1] &&
                mycs5 == puVar8[2] &&
                mycs2 == puVar8[3] &&
                mycs3 == puVar8[4] &&
                NumSame == puVar8[5] &&
                local_8 == puVar8[6]) {
                ++NumDiff;
                L->Log("OUTOFSYNC: %d same: %d %d %d %d %d %d",
                       i, uVar5, lVar6, puVar8[0],
                       mycs2, mycs3, NumSame);
            } else {
                ++NumPlayers;
                L->Log("OUTOFSYNC: %d diff: %d %d %d %d %d %d",
                       i, uVar5, lVar6, puVar8[0],
                       mycs2, mycs3, NumSame);
            }
        }
        ++i;
        puVar8 += 9;
    } while (i <= 0x36);

    int player = 1;
    do {
        if (this->Comm->GetPlayerHumanity(player) == 2) {
            ++foundMine;
        }
        ++player;
    } while (player <= 9);

    L->Log("OUTOFSYNC: numplayers=%d, diff=%d, same=%d",
           foundMine, NumPlayers, NumDiff);

    if (NumDiff + NumPlayers < foundMine - 1) {
        L->Log("OUTOFSYNC: return not out");
        return 0;
    }

    if (NumPlayers > NumDiff) {
        L->Log("OUTOFSYNC: return out");
        return 1;
    }

    L->Log("OUTOFSYNC: return not out 2");
    return 0;
}
