// VA: 00433290 DoChecksum (448B)
// com_sync.cpp lines 129-195
//
// Attempt log:
// - Replaced the placeholder with the period-plausible checksum collection,
//   chat/reporting, player-visible-map scan, and communication sequence.
// - Baseline had the third GetWorldChecksums output overlaid on tmp[0]; its
//   natural two-output/local-buffer form was 15 bytes off from a 0x10C frame.
// - Kept a named cs3 output local to recover the 0x10C frame and the original
//   zero-store order; this is the codegen-best source, with only tmp-home
//   displacements at the chat formatting sites still differing (2 bytes).
// - Reordered locals, widened/aggregated the buffer, and union/reference
//   overlays were diagnostic only; they either duplicated an earlier basin or
//   restored the 0x108 frame. No custom flags or opaque aliases were kept.
// - Tested a natural { checksum; text[255]; } aggregate to make the marker
//   lifetime explicit; it worsened the first mismatch to +007A and diff 8.
//   Restored the named long plus buffer, which remains the clean 2-byte best.
// - Reordered the natural buffer and named checksum declarations to test the
//   binary-proven tmp[0]/tmp[4] stack adjacency; emitted code was unchanged.
//   Restored the clean declaration order; the two-byte tmp-home drift remains.
// - The original chat destination is the report-buffer base, not tmp + 4;
//   removing that offset closes both stack-home bytes and gives an exact match.
//   A function-scope buffer is the natural exact source form; a block-scoped
//   buffer emitted the same exact code and was not retained.

#include <stdio.h>

#ifndef COM_SYNC_TU_CONTEXT
class TDebuggingLog {
public:
    void Log(const char* format, ...);
    void FlushLog();
};

extern TDebuggingLog* L;

class TCommunications_Handler {
public:
    int WhoAmI();
    void SendChatMsgAll(const char* message);
    long SendChecksumMessage(unsigned long worldTime, unsigned int random,
                             long checksum, long checksum1, long checksum2,
                             long checksum3, long checksum4);
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
};

extern RGE_Base_Game* rge_base_game;

class PathingSystem {
public:
    long checksum();
};

extern PathingSystem pathSystem;
extern unsigned long DAT_0062D208[];
extern unsigned long DAT_0062D230;

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

    int Add(unsigned int turn, unsigned long worldTime,
            unsigned long checksum1, unsigned long checksum2,
            long chatCrc, long dataCrc, long a7, long a8, long a9);

    unsigned long DoChecksum(unsigned long turn);
};
#endif

unsigned long RGE_Communications_Synchronize::DoChecksum(unsigned long turn) {
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
