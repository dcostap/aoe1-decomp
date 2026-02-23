#include "../include/RGE_Communications_Synchronize.h"

#include "../include/RGE_Comm_Error.h"
#include "../include/TCommunications_Handler.h"

#include <stdio.h>
#include <string.h>

RGE_Communications_Synchronize::RGE_Communications_Synchronize(TCommunications_Handler* comm) {
    // Source of truth: com_sync.cpp.decomp @ 0x00432FF0
    this->Comm = comm;
    this->CheckTime = 1000;
    this->CheckTurn = 10;
    this->StopOnSyncFail = 1;
    this->DoChecksums = 1;
    this->LastResult = 1;
    this->NewData = 0;
    this->Offset = 0;
    this->LastWorldRandom = 0;
    this->GameWorldChecksum = 0;
    this->SendChatMsgs = 0;
    this->DialogOnSyncFail = 0;

    for (int i = 0; i < 0x37; ++i) {
        memset(&this->Check[i], 0, sizeof(this->Check[i]));
    }
}

RGE_Communications_Synchronize::~RGE_Communications_Synchronize() {
    // Source of truth: com_sync.cpp.decomp @ 0x00433070
    for (int i = 0; i < 0x37; ++i) {
        memset(&this->Check[i], 0, sizeof(this->Check[i]));
    }
}

int RGE_Communications_Synchronize::Add(uint player_no, ulong world_time, ulong comm_turn, ulong random, long cs1, long cs2, long cs3,
                                       long cs4, long cs5) {
    // Source of truth: com_sync.cpp.decomp @ 0x004330A0
    if (this->DoChecksums == 0) {
        return 0;
    }

    uint next = this->Offset + 1;
    this->Offset = next;
    if (next > 0x35) {
        this->Offset = 0;
    }

    CHECKSUMARRAY& rec = this->Check[this->Offset];
    rec.WTime = world_time;
    rec.WTurn = comm_turn;
    rec.cs1 = cs1;
    rec.cs2 = cs2;
    rec.cs3 = cs3;
    rec.cs4 = cs4;
    rec.cs5 = cs5;
    rec.Random = (uint)random;
    rec.PlayerNo = player_no;

    this->NewData = 1;
    return this->ValidateChecksums(player_no, world_time, comm_turn, random, cs1, cs2, cs3, cs4, cs5);
}

int RGE_Communications_Synchronize::ValidateChecksums(uint player_no, ulong world_time, ulong comm_turn, ulong random, long cs1, long cs2,
                                                     long cs3, long cs4, long cs5) {
    // Source of truth: com_sync.cpp.decomp @ 0x00433180
    if (this->NewData == 0) {
        return this->LastResult;
    }

    this->NewData = 0;
    this->LastResult = 0;

    for (uint i = 1; i < 0x37; ++i) {
        const CHECKSUMARRAY& other = this->Check[i];
        bool mismatch = false;

        if (other.WTurn == comm_turn) {
            if (other.WTime != world_time) {
                mismatch = true;
            } else if (other.cs1 != cs1 || other.cs2 != cs2 || other.cs3 != cs3 || other.cs4 != cs4 || other.cs5 != cs5 ||
                       other.Random != (uint)random) {
                mismatch = true;
            }
        } else {
            if (other.WTime == world_time) {
                if (other.cs1 != cs1 || other.cs2 != cs2 || other.cs3 != cs3 || other.cs4 != cs4 || other.cs5 != cs5 ||
                    other.Random != (uint)random) {
                    mismatch = true;
                }
            }
        }

        if (mismatch) {
            this->LogChecksums(player_no, world_time, comm_turn, cs1, cs2, cs3, cs4, cs5, random);
            if (this->Comm != nullptr) {
                this->Comm->NotifyWindowParam(COMM_SYNC_ERROR, (long)comm_turn);
            }
            this->LastResult = 0;
            return 0;
        }
    }

    this->LastResult = 1;
    return 1;
}

ulong RGE_Communications_Synchronize::DoChecksum(ulong comm_turn) {
    // TODO: STUB - Full checksum computation depends on game-world checksum helpers not yet restored.
    // Source of truth: com_sync.cpp.decomp @ 0x00433290
    if (this->DoChecksums == 0) {
        return 0;
    }
    if (comm_turn < this->CheckTurn) {
        return 0;
    }
    this->CheckTurn += 4;
    return 1;
}

void RGE_Communications_Synchronize::SetLastWorldRandom(ulong v) {
    // Fully verified. Source of truth: com_sync.cpp.decomp @ 0x00433450
    this->LastWorldRandom = v;
}

void RGE_Communications_Synchronize::LogChecksums(uint player_no, ulong world_time, ulong comm_turn, long cs1, long cs2, long cs3, long cs4,
                                                 long cs5, ulong random) {
    // Source of truth: com_sync.cpp.decomp @ 0x00433460
    FILE* f = fopen("C:\\aoesync.txt", "wt");
    if (f == nullptr) {
        return;
    }

    fprintf(f, "Adding: P=%u WTime=%lu Turn=%lu cs1=%ld cs2=%ld cs3=%ld cs4=%ld cs5=%ld rand=%lu\n", player_no, world_time, comm_turn, cs1, cs2,
            cs3, cs4, cs5, random);
    fprintf(f, "Plr  Wrldtime  CommTurn  Random  cs1  cs2  cs3  cs4  cs5\n");

    for (uint i = 1; i < 0x37; ++i) {
        const CHECKSUMARRAY& rec = this->Check[i];
        fprintf(f, "%2u  %8lu  %8lu  %6u  %8ld  %8ld  %8ld  %8ld  %8ld\n", rec.PlayerNo, rec.WTime, rec.WTurn, rec.Random, rec.cs1, rec.cs2, rec.cs3,
                rec.cs4, rec.cs5);
    }

    fclose(f);
}

void RGE_Communications_Synchronize::EnableSyncChecking(int enable) {
    // Fully verified. Source of truth: com_sync.cpp.decomp @ 0x00433A90
    this->DoChecksums = enable;
}

void RGE_Communications_Synchronize::SetStopOnFail(int stop) {
    // Fully verified. Source of truth: com_sync.cpp.decomp @ 0x00433AA0
    this->StopOnSyncFail = stop;
}

void RGE_Communications_Synchronize::SetDialogOnFail(int dialog) {
    // Fully verified. Source of truth: com_sync.cpp.decomp @ 0x00433AB0
    this->DialogOnSyncFail = dialog;
}

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int enable) {
    // Fully verified. Source of truth: com_sync.cpp.decomp @ 0x00433AC0
    this->SendChatMsgs = enable;
}

int RGE_Communications_Synchronize::IsPlayerOutOfSync(uint player_no, ulong comm_turn) {
    // Source of truth: com_sync.cpp.decomp @ 0x00433AD0 (simplified but parity-aligned decision rule)
    const CHECKSUMARRAY* mine = nullptr;
    for (uint i = 1; i < 0x37; ++i) {
        const CHECKSUMARRAY& rec = this->Check[i];
        if (rec.PlayerNo == player_no && rec.WTurn == comm_turn) {
            mine = &rec;
            break;
        }
    }

    if (mine == nullptr) {
        return 0;
    }

    int same_count = 0;
    int diff_count = 0;
    for (uint i = 1; i < 0x37; ++i) {
        const CHECKSUMARRAY& rec = this->Check[i];
        if (rec.WTurn != comm_turn) {
            continue;
        }
        if (rec.PlayerNo == player_no) {
            continue;
        }

        const bool same = (rec.WTime == mine->WTime) && (rec.WTurn == mine->WTurn) && (rec.cs1 == mine->cs1) && (rec.cs2 == mine->cs2) &&
                          (rec.cs3 == mine->cs3) && (rec.cs4 == mine->cs4) && (rec.cs5 == mine->cs5) && (rec.Random == mine->Random);
        if (same) {
            same_count += 1;
        } else {
            diff_count += 1;
        }
    }

    int human_count = 0;
    if (this->Comm != nullptr) {
        for (uint p = 1; p < 10; ++p) {
            if (this->Comm->GetPlayerHumanity(p) == 2) {
                human_count += 1;
            }
        }
    }

    if (human_count - 1 <= same_count + diff_count) {
        return (diff_count > same_count) ? 1 : 0;
    }

    return 0;
}

