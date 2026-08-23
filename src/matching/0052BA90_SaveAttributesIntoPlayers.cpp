// 0052BA90 T_Scenario::SaveAttributesIntoPlayers (tscenaro.cpp:778-791, 293B)
// Baseline reconstruction: scenario player-start attributes, per-player
// relations, and allied-victory flags copied into the world's player objects.
//
// Attempt log:
// - The canonical tscenaro context provides the reviewed scenario, world, and
//   player ownership. PDB lines 778-791 and exact siblings prove this context.
// - The pinned baseline carried an explicit AlliedVictory pointer. It had one
//   nine-byte setup-order difference. All later bytes matched.
// - The exact source reads AlliedVictory[player - 1] at the call site. VC5
//   derives the shipped carried pointer from this indexed expression.
// - This form initializes the relation offset before it publishes the pointer
//   home. It preserves every later instruction.
// - Walkback restored only the unused pointer declaration. The result stayed
//   exact. Walkback also restored its dead initialization. It stayed exact.
// - Restoring the pointer increment caused 56 differences across the body.
//   Direct indexing and removal of that increment are the required group.
// - The declaration and initialization were incidental. The reduced source
//   removes both. It keeps no dead compiler-steering code.
// - Headers, translation-unit order, and default flags did not change.
// BINARY NOTE: direct array indexing emits the original carried pointer,
// relation induction, stack home, frame, calls, cleanup, and fault order.

#include "../../include/tscenaro_context.h"

#if 0
struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

struct Friendliness {
    int Attitude[16];
};

class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    void new_attribute_num(short attrType, float value);
    void set_relation(long playerIdx, unsigned char relation);
    void set_allied_victory(unsigned char flag);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short playerCount;
    char gap_3E[2];
    RGE_Player** players;
};

class T_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~T_Scenario();
    char gap_04[4];
    RGE_Game_World* world;
    char gap_0C[0x479C];
    Friendliness Opponent[16];
    int AlliedVictory[16];

    int Get_player_Food(int idx);
    int Get_player_Stone(int idx);
    int Get_player_Gold(int idx);
    int Get_player_Wood(int idx);

    void SaveAttributesIntoPlayers();
};
#endif

void T_Scenario::SaveAttributesIntoPlayers() {
    int player = 1;
    int other;
    if (player < this->world->player_num) {
        do {
            this->world->players[player]->new_attribute_num(
                0, (float)this->Get_player_Food(player - 1));
            this->world->players[player]->new_attribute_num(
                2, (float)this->Get_player_Stone(player - 1));
            this->world->players[player]->new_attribute_num(
                3, (float)this->Get_player_Gold(player - 1));
            this->world->players[player]->new_attribute_num(
                1, (float)this->Get_player_Wood(player - 1));

            other = 1;
            if (other < this->world->player_num) {
                do {
                    if (other != player) {
                        this->world->players[player]->set_relation(
                            other,
                            (unsigned char)this->Opponent[player - 1].Attitude[other - 1]);
                    }
                    ++other;
                } while (other < this->world->player_num);
            }

            this->world->players[player]->set_allied_victory(
                (unsigned char)this->AlliedVictory[player - 1]);
            ++player;
        } while (player < this->world->player_num);
    }
}
