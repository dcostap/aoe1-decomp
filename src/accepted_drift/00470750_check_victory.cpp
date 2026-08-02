// 00470750 RGE_Player::check_victory
// player.cpp lines 1497-1534
// Natural reconstruction: victory_conditions->victory_achieved() gate, then
// two allied-victory loops over world players (relations/ally-group), then
// optional set_game_status(1) + world->game_end_condition = 2.
//
// Attempt log:
// 1 baseline: world local in both loops -> VC5 kept world in EBP (extra saved
//   reg), prologue shifted (push ebp), diff 209. World must be direct
//   this->world member access: original reloads [esi+3Ch] at each loop bottom.
// 2 liveness: direct this->world in both loops -> diff 1 (0.4329%), shape
//   100%, calls 4/4, blocks 100%. Only remaining byte: +00A5 SIB byte of the
//   SECOND loop's `cmp byte [reg+reg],0` for this->relations[i]: original
//   emits [edi+edx] (base=counter edi, index=relations edx), rebuilt emits
//   [edx+edi]. First loop (with the i==id compare first) correctly emits
//   [edx+edi] in both.
// 3-4 variants: i[this->relations], *(i + this->relations) -> VC5 normalizes
//   subscript/add to pointer-first; codegen identical (dup).
// 5 variant lab (reltest x reltype, 12 forms): subscript, !x, explicit adds
//   (both orders), 0==x, paren, uchar*/char* member -> all emit [edx+edi].
// 6 variant lab (loop2 shapes, 36): for i++/++i, while, combined/nested/!call
//   bodies, early-return vs goto end -> all for-loop forms still [edx+edi];
//   while forms break frame (sub esp,8).
// 7 variant lab (shared i, per-iter relations local, 4): still [edx+edi].
// 8 liveness: world local in loop2 only -> forces EBP save again, diff 206.
// 9 variant lab (found uchar/bool/int, cast index forms, 9): uchar keeps
//   frame; bool/int break frame; SIB byte still [edx+edi].
// 10 variant: *(i + rel) with per-iteration local rel -> codegen duplicate.
// Left in scratch: remaining drift is the single SIB base/index swap byte
// (17 vs 3A) in the second loop's relations compare. Both encodings address
// the identical byte; calls, CFG, frame, registers, and all other bytes are
// exact. Behavior-equivalent register-encoding artifact, insensitive to all
// tried source axes; candidate for main-agent accepted-drift review.
// ACCEPTED_DRIFT: manually reviewed. The sole differing SIB byte swaps EDX
// and EDI as base/index with scale 1, so both instructions read exactly the
// same address. No predicate, call, control flow, stack, or memory effect
// differs; all other 230 bytes are identical.

class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Victory_Conditions;

class RGE_Player {
public:
    virtual void vf00(void);
    virtual void set_game_status(unsigned char param_1);

    char gap_04[0x10];
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    char gap_21[0x03];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x0C];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x3C - 0x38];
    RGE_Game_World* world;
    char gap_40[0x4A - 0x40];
    short id;
    char gap_4C[0x80 - 0x4C];
    unsigned char game_status;
    char gap_81[0x84 - 0x81];
    unsigned char* relations;
    char gap_88[0x104 - 0x88];
    unsigned char allied_victory;

    unsigned char check_ally_group(long& count);
    unsigned char check_victory_conditions(void);
    unsigned char check_victory(void);
};

class RGE_Game_World {
public:
    char gap_00[0x1E];
    unsigned char game_end_condition;
    char gap_1F[0x3C - 0x1F];
    short player_num;
    char gap_3E[0x40 - 0x3E];
    RGE_Player** players;
};

class RGE_Victory_Conditions {
public:
    unsigned char victory_achieved(void);
};

unsigned char RGE_Player::check_victory(void)
{
    long ally = -1;

    if (this->game_status != 2 && this->victory_conditions->victory_achieved()) {
        unsigned char found = 0;
        if (this->allied_victory) {
            for (int i = 1; i < this->world->player_num; i++) {
                if ((i == this->id || this->relations[i] == 0) &&
                    this->world->players[i]->check_ally_group(ally) == 0) {
                    found = 1;
                    break;
                }
            }
        }
        if (this->allied_victory) {
            if (found) return this->game_status;
            for (int i = 1; i < this->world->player_num; i++) {
                if (this->relations[i] == 0 &&
                    this->world->players[i]->check_victory_conditions() == 0) {
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            this->set_game_status(1);
            this->world->game_end_condition = 2;
        }
    }
    return this->game_status;
}
