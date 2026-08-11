// VA: 00517F30 TRIBE_Player::setupAssyrian | tplayer.cpp:4089-4142
// Attempt log:
// - canonical direct int* setup-array source matches the log/deathmatch/difficulty
//   control flow and all call sites; default build remains 96 positional bytes off
//   and three bytes short, first mismatch at the non-deathmatch constant group.
// - moving/reordering independent setup groups was tested; the best diagnostic
//   order (0x28, 100, 0x14, then 0x0a/0x50) reached exact size and 12 bytes off,
//   but left the canonical source restored because its ordering is not established.
// - direct parameter/member spelling was retained; no stable shared type/global
//   fact was found. Paused with the natural source and the remaining lead is the
//   source-level ordering around the 0x14 versus 0x64 stores.
// - this session reconfirmed the baseline, then tested direct group reordering;
//   it worsened the positional diff despite improving resynchronization.
// - an ordinary local int* alias plus the b_d_c_a group order reached exact size
//   and 12 positional bytes off; the only remaining hunk was [0x4c] versus
//   [0xa0]/[0xa4] store order around the param_2 test. Shared tplayer ABI
//   declarations and a second pointer alias emitted the same bytes.
// - a focused 24-way permutation of the four individual stores found no exact
//   variant. The diagnostic alias/order source was restored; remaining evidence
//   is a localized VC5 scheduling/register basin, not an unknown call or layout.

struct AIModule {
    void __cdecl logCommonHistory(char* msg);
};
struct TRIBE_Game {
    unsigned char deathMatch();
    int difficulty();
};
extern TRIBE_Game* rge_base_game;

struct TRIBE_Player {
    virtual ~TRIBE_Player();
    char gap_04[0x234];
    AIModule* playerAI;
    void setupAssyrian(int* param_1, int param_2, int param_3, int param_4);
};

void TRIBE_Player::setupAssyrian(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Assyrians.");
    if (rge_base_game->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x3c] = 100;
            return;
        }
        if (param_2 == 2 || param_2 == 6) {
            param_1[0x16] = 60;
            param_1[0x3c] = 40;
            return;
        }
        if (param_2 == 5 || param_2 == 8) {
            param_1[0x16] = 80;
            param_1[0x3c] = 20;
            return;
        }
        param_1[0x16] = 100;
        return;
    }

    if (rge_base_game->difficulty() < 1) {
        param_1[0x22] = 100;
        return;
    }

    param_1[3] = 10;
    param_1[7] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[0x14] = 10;
    param_1[0x48] = 0x50;
    param_1[0x49] = 0x50;
    param_1[0x4a] = 0x50;
    param_1[0x10] = 0x28;
    param_1[0xb] = 0x28;
    param_1[6] = 0x14;
    param_1[0x13] = 0x14;
    param_1[0x28] = 100;
    param_1[0x29] = 100;
    if (param_2 == 0 || param_2 == 1) {
        param_1[0x4b] = 100;
        param_1[0x4c] = 100;
    } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
        param_1[0x4b] = 50;
        param_1[0x4c] = 50;
    }
}
