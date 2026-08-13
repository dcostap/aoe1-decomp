// 005425B0 RGE_Game_World::setup_player_colors (World.cpp:1173-1220, 295B)
//
// Attempt log:
// - baseline: natural typed reconstruction with two indexed passes; structural
//   parity was not yet reached.
// - canonicalized the period class/type names and reference parameter, moved
//   color initialization before the first player call, and used explicit
//   do/while scans to mirror the observed bottom-tested loops.
// - hoisting one shared index before calloc restored the exact frame and all
//   structural/call parity; the remaining drift is one VC5 SIB base/index byte
//   at the used-color compare (original [ecx+eax], rebuild [eax+ecx]).
// - pointer/addition, boolean, signed-byte, operand-order, and array-overlay
//   variants were diagnostic duplicates; the natural typed subscript remains
//   the living source.
// - Main-agent audit replaced inline empty virtual bodies with canonical
//   declarations and restored world/player destructor ownership. This exposes
//   the same SIB-only blocker (two encoded bytes under canonical TU context).
// - Probe 13: first-pass pointer-addition spelling was a codegen duplicate.
// - Probes 16-19 and 23: full world/player-info/color-table layout/context
//   repairs were codegen duplicates; retain only proven layout facts.
// - Probe 20: a current-used-color pointer caused a 9-byte structural drift;
//   restored the natural direct table expression.
// - Probe 24: a typed 256-byte Colors_Used record fixed the store SIB byte and
//   reduced the diff to one compare byte, but the dynamic calloc source is more
//   naturally a byte pointer; kept the record as diagnostic evidence only.
// - Probes 25-26: member pointer-addition and typedef-array spellings did not
//   fix the compare SIB and the latter restored the second mismatch byte.
// - New worker probes: nested the nonnegative guard, combined signed-byte and
//   negation/pointer-addition forms, reversed local declaration order, tested a
//   named short color, unsigned-count calloc, and signed players_done. All
//   natural forms either duplicated the two-byte SIB drift or the named short
//   caused structural drift; restore the clean typed source.
// - An exact Victory.cpp donor confirms VC5 can emit base-first SIB for a
//   typed member byte array, but it does not establish that ownership here.
// - Follow-up: direct pointer-addition and reversed integer-plus-pointer
//   spellings for both used-color accesses were codegen duplicates. Restore
//   the natural typed subscript; the canonical RGE_Player surface remains.
// - Current session: the remaining two SIB bytes are localized at the first
//   used-color compare and store. No new natural source lead remains.
// - Indexed typed color access (`info.color[i - 1]`) preserved structure and
//   removed the compare SIB byte, leaving only the store SIB operand order.
// - Follow-up probes: signed-byte, named-color, record/member, volatile-cast,
//   pointer-alias, and reversed pointer-addition forms all emitted duplicates;
//   restore the canonical byte-table source and retain the one-byte SIB drift.
// - Current worker probes: first-pass and post-call byte-pointer aliases, a
//   split color-slot pointer, and historical short-cursor variants did not
//   improve the one-byte store SIB; the mixed cursor form became structural.
// - The pre-audit vtable context changed no bytes. Removing the player tail
//   and restoring historical one-line formatting also left the compare SIB.
//   Restored the canonical declarations and indexed source.
//
// FLAGS: /nologo /c /O2 /Oy

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

extern "C" void* calloc(int num, int size);
extern "C" void free(void* ptr);

class RGE_Player {
public:
    virtual ~RGE_Player();
    void set_color_table(unsigned char color);
    char gap_04[0x21C];
};

class RGE_Player_Info {
public:
    char gap_00[0x25C];
    short color[9];             // +0x25C
    char gap_26E[0x26];
    short player_num;           // +0x294
};

class RGE_Color_Table {
public:
    char gap_00[0x24];
    unsigned char type;         // +0x24
};

class RGE_Game_World {
public:
    // The target is the original virtual slot 42.  The declarations also
    // preserve the real vptr before the data fields.
    virtual ~RGE_Game_World();
    VPAD16(1) VPAD8(17)
    virtual unsigned char new_random_game(RGE_Player_Info& info);
    VPAD16(26)
    virtual void setup_player_colors(RGE_Player_Info& info);

    char gap_04[0x38];          // +0x04 through +0x3B
    short player_num;           // +0x3C
    char gap_3E[2];
    RGE_Player** players;       // +0x40
    char gap_44[0x1C];
    short color_table_num;      // +0x60
    char gap_62[2];
    RGE_Color_Table** color_tables; // +0x64
};

void RGE_Game_World::setup_player_colors(RGE_Player_Info& info) {
    int colorIdx = -1;

    this->players[0]->set_color_table(7);

    int maxPlayerNum = this->player_num + 1;
    int maxIter = info.player_num;
    if (maxIter > maxPlayerNum) {
        maxIter = maxPlayerNum;
    }

    int i = 1;
    unsigned char* colorsUsed = (unsigned char*)calloc(this->color_table_num, 1);
    unsigned char* playersDone = (unsigned char*)calloc(this->player_num, 1);

    if (this->player_num > 1) {
        do {
            if (i - 1 < maxIter && info.color[i - 1] >= 0 &&
                colorsUsed[info.color[i - 1]] == 0) {
                this->players[i]->set_color_table((unsigned char)info.color[i - 1]);
                colorsUsed[info.color[i - 1]] = 1;
                playersDone[i] = 1;
            }
            ++i;
        } while (i < this->player_num);
    }

    i = 1;
    if (this->player_num > 1) {
        do {
            if (playersDone[i] == 0) {
                do {
                    ++colorIdx;
                } while (colorsUsed[colorIdx] == 1 ||
                         this->color_tables[colorIdx]->type != 1);

                this->players[i]->set_color_table((unsigned char)colorIdx);
                colorsUsed[colorIdx] = 1;
            }
            ++i;
        } while (i < this->player_num);
    }

    free(colorsUsed);
    free(playersDone);
}
