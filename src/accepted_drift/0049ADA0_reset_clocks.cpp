// VA: 0049ADA0 reset_clocks (594B)
// scr_game.cpp:4192-4265
//
// Attempt log (sa-b5a80f3f-r1-match0049ADA0):
// - initial placeholder was unrelated to the executable; the first clean
//   reconstruction below follows the typed TRIBE_World/player ownership,
//   byte-offset player cursor, and clock-selection loops proved by the asm.
// - swapping the clock/player local declaration order, using post-increment
//   clock receivers, and splitting the allied guard aligned frame/size/CFG;
//   the clean source then differed only in the two inner-loop branch pairs
//   and the outer induction tail.
// - top-tested while/for forms, reversed bound operands, and explicit
//   infinite-loop break/continue spellings either broadened the drift or
//   emitted the same branch basin; the ordinary do/while remains the
//   period-plausible source.
// - reversing the ordinary outer updates to `++player_id; player_offset += 4`
//   recovered the target's pointer-store/world-count scheduling, leaving a
//   six-byte codegen gap: both inner scans use `jge exit; jmp body` instead of
//   the oracle's `jl body; jmp exit`.
// - zero-based/preincrement inner counters were rolled back (broad drift).
// - sharing countdown/relation locals across the outer iteration was a codegen duplicate; scoped locals remain the clearer period-plausible source.
// - moving each inner increment into the do/while condition was a codegen duplicate; the paired branch gap remains.
// - resumed after the host crash, restored the clean pinned source, and
//   reproduced the 594-byte/frame-0x10 validation. No new natural source lead
//   remains; the unresolved bytes are the two inner-loop branch pairs.
// - this session re-tested for-header, while, explicit continue/break, post-
//   increment, inverted-predicate, labeled-backedge, and <=-bound spellings;
//   all either broadened the function or canonicalized to the same six-byte
//   gap. The clean do/while source remains the best reconstruction.
// - this session reconfirmed the clean baseline, then tested scoped and
//   predeclared-counter for headers; both changed register ownership and
//   broadened the diff. A four-case loop-shape lab found no new invariant-
//   eligible codegen group.
// - a four-case predicate-shape lab (direct, negated-or, nested, and
//   positive-else) collapsed to the same six-byte branch gap. The final
//   predeclared-counter for probe was a duplicate of the scoped-for basin;
//   the clean do/while remains authoritative.
// - this revisit restored the canonical TScreenPanel/TRIBE_Screen_Game
//   ownership and the proven polymorphic RGE_Player/TRIBE_Player timing
//   fields. Codegen stayed unchanged at 594 bytes with the same six-byte
//   inner-loop branch gap.
// - natural while scans were retested for both relation loops. They added
//   eight bytes and broadened the diff, so the typed do/while reset remains
//   authoritative.
// ACCEPTED DRIFT: Each three-byte hunk inverts one loop condition and exchanges
// its taken and unconditional jump targets. `JL body; JMP exit` and
// `JGE exit; JMP body` partition the same signed comparison with identical
// destinations. No instruction, call, or memory access lies between the two
// jumps. Both relation loops therefore have equal behavior and fault order.

class TRIBE_Panel_Time {
public:
    void set_clock_type(int clock_type, int player_id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x80];
    unsigned char* relations;
    char gap_88[0x7C];
    unsigned char allied_victory;
    char gap_105[0x11B];

    unsigned char relation(long player_id);
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_220[0x620];
    float ruin_held_time;
    float artifact_held_time;
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x24];
    void* map;
    char gap_2C[0x10];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0xC0];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[4];
    int victory_type;
};

class RGE_Base_Game {
public:
    void get_countdown_timer(int player_id, int* countdown_timer);
};

extern RGE_Base_Game* rge_base_game;

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    char gap_04[0x474];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0xA0];
    TRIBE_Panel_Time* countdown_clock[10];
    char gap_540[0x74];
    TRIBE_World* world;

    void reset_clocks();
};

void TRIBE_Screen_Game::reset_clocks() {
    if (this->world->victory_type == 2) {
        this->countdown_clock[0]->set_clock_type(3, 0);
        return;
    }

    if (this->world->victory_type != 0) {
        return;
    }

    int player_id = 1;
    int clock_count = 0;

    if (player_id < this->world->player_num) {
        TRIBE_Panel_Time** clock = this->countdown_clock;
        int player_offset = 4;

        do {
            int countdown_timer;
            rge_base_game->get_countdown_timer(player_id, &countdown_timer);
            if (countdown_timer > 0) {
                ++clock_count;
                (*clock++)->set_clock_type(4, player_id);
                if (clock_count > 9) {
                    break;
                }
            }

            if (((TRIBE_Player*)(*(RGE_Player**)((char*)this->world->players + player_offset)))->artifact_held_time != -1.0f) {
                int countdown = 0;
                if ((*(RGE_Player**)((char*)this->world->players + player_offset))->allied_victory != 0) {
                    int other_player = 1;
                    if (player_offset > 4) {
                        do {
                            if ((*(RGE_Player**)((char*)this->world->players + player_offset))->relation(other_player) == 0 &&
                                (*(RGE_Player**)((char*)this->world->players + other_player * 4))->relation(player_id) == 0 &&
                                (*(RGE_Player**)((char*)this->world->players + other_player * 4))->allied_victory != 0) {
                                countdown = 1;
                                break;
                            }
                            ++other_player;
                        } while (other_player < player_id);
                    }
                }

                if (countdown == 0) {
                    ++clock_count;
                    (*clock++)->set_clock_type(5, player_id);
                    if (clock_count > 9) {
                        break;
                    }
                }
            }

            if (((TRIBE_Player*)(*(RGE_Player**)((char*)this->world->players + player_offset)))->ruin_held_time != -1.0f) {
                int countdown = 0;
                if ((*(RGE_Player**)((char*)this->world->players + player_offset))->allied_victory != 0) {
                    int other_player = 1;
                    if (player_offset > 4) {
                        do {
                            if ((*(RGE_Player**)((char*)this->world->players + player_offset))->relation(other_player) == 0 &&
                                (*(RGE_Player**)((char*)this->world->players + other_player * 4))->relation(player_id) == 0 &&
                                (*(RGE_Player**)((char*)this->world->players + other_player * 4))->allied_victory != 0) {
                                countdown = 1;
                                break;
                            }
                            ++other_player;
                        } while (other_player < player_id);
                    }
                }

                if (countdown == 0) {
                    ++clock_count;
                    (*clock++)->set_clock_type(6, player_id);
                    if (clock_count > 9) {
                        break;
                    }
                }
            }

            ++player_id;
            player_offset += 4;
        } while (player_id < this->world->player_num);
    }

    if (clock_count < 10) {
        TRIBE_Panel_Time** clock = &this->countdown_clock[clock_count];
        int remaining = 10 - clock_count;
        do {
            (*clock++)->set_clock_type(0, 0);
            --remaining;
        } while (remaining != 0);
    }
}
