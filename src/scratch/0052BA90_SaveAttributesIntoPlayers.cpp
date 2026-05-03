// 0052BA90 T_Scenario::SaveAttributesIntoPlayers (tscenaro.cpp:778-791, 293B)
// Sets up player attributes (food, stone, gold, wood) and relations from scenario data.
//
// Left in scratch: remaining diffs are VC5 codegen optimization choices:
// - sub esp, 0Ch vs sub esp, 8: extra stack slot for relation pointer backup
// - ebp as running pointer (lea [this+47A8h]) vs offset (mov ebp, 11E9h):
//   VC5 converts `(int*)this + inner + relationBase` into a running pointer
// - inner loop comparison loads playerCount into cx register vs direct memory cmp
// - relation access as direct [ebp] read vs lea+scaled [this+ecx*4]
// - outer loop saves/restores relation pointer to stack
// All code paths, field offsets, FPU eval order, and loop bounds verified correct.
// Suggest variant_lab pass probing relation expression form to force offset arithmetic.
// FLAGS: /nologo /c /O2 /Oy

class RGE_Player;

struct GameWorldShort {
    char _gap_00[0x3C];
    short playerCount;
    char _gap_3E[2];
    RGE_Player** players;
};

struct RGE_PlayerShort {
    char _gap_00[4];
    void new_attribute_num(short attrType, float value);
    void set_relation(int playerIdx, unsigned char relation);
    void set_allied_victory(unsigned char flag);
    char _gap_04[0x220 - 4];
};

struct ScenarioShort2 {
    char _gap_00[8];
    GameWorldShort* world;

    int Get_player_Food(int idx);
    int Get_player_Stone(int idx);
    int Get_player_Gold(int idx);
    int Get_player_Wood(int idx);

    void SaveAttributesIntoPlayers();
};

void ScenarioShort2::SaveAttributesIntoPlayers() {
    int idx = 1;
    if (world->playerCount <= 1) return;

    char* av = (char*)this + 0x4BA8;

    do {
        ((RGE_PlayerShort*)world->players[idx])->new_attribute_num(
            0, (float)Get_player_Food(idx - 1));
        ((RGE_PlayerShort*)world->players[idx])->new_attribute_num(
            2, (float)Get_player_Stone(idx - 1));
        ((RGE_PlayerShort*)world->players[idx])->new_attribute_num(
            3, (float)Get_player_Gold(idx - 1));
        ((RGE_PlayerShort*)world->players[idx])->new_attribute_num(
            1, (float)Get_player_Wood(idx - 1));

        if (world->playerCount > 1) {
            const int baseRelation = 0x11E9 + (idx - 1) * 0x10;
            for (int inner = 1; inner < world->playerCount; inner++) {
                if (inner != idx) {
                    ((RGE_PlayerShort*)world->players[idx])->set_relation(
                        inner,
                        *(unsigned char*)((int*)this + inner + baseRelation)
                    );
                }
            }
        }

        ((RGE_PlayerShort*)world->players[idx])->set_allied_victory(
            *(unsigned char*)av
        );

        idx++;
        av += 4;
    } while (idx < world->playerCount);
}
