// 0052BA90 T_Scenario::SaveAttributesIntoPlayers (tscenaro.cpp:778-791, 293B)
// Baseline reconstruction: scenario player-start attributes, per-player
// relations, and allied-victory flags copied into the world's player objects.
//
// Attempt log:
// - prior source used raw relation cursor arithmetic and a redundant nested
//   count guard; it emitted a 315-byte structural mismatch.
// - current probe restores named Friendliness/AlliedVictory arrays and the
//   natural short-count do/while topology.
// - baseline reached 294 bytes with 101 instructions, 0x8 frame, all 10
//   calls aligned, and 93 strict differing bytes (24-byte edit diff).
// - zero-based relation columns (`Attitude[other - 1]`) reproduce the
//   original 0x11E9 running row offset; using the one-based column was a
//   semantic/layout mistake even though its emitted code was nearly equal.
// - ten bounded source/layout/context probes did not change the remaining
//   codegen basin: VC5 emits `mov [esp+10h],ecx` before `mov ebp,11E9h`,
//   uses a one-byte-longer `lea [ebp+edi]` SIB, and leaves a one-byte tail
//   overflow/branch-span difference. The polymorphic-base and flattened
//   relation diagnostics were rolled back.
// - left in scratch after budget: natural typed source is behaviorally
//   aligned; remaining drift is localized VC5 scheduling/address encoding.
// - Main-agent audit restored polymorphic player/world/scenario ownership;
//   emitted code remains in the documented 93-byte scheduling basin.

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

void T_Scenario::SaveAttributesIntoPlayers() {
    int player = 1;
    int other;
    int* alliedVictory;
    if (player < this->world->playerCount) {
        alliedVictory = this->AlliedVictory;
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
            if (other < this->world->playerCount) {
                do {
                    if (other != player) {
                        this->world->players[player]->set_relation(
                            other,
                            (unsigned char)this->Opponent[player - 1].Attitude[other - 1]);
                    }
                    ++other;
                } while (other < this->world->playerCount);
            }

            this->world->players[player]->set_allied_victory(
                (unsigned char)*alliedVictory);
            ++player;
            ++alliedVictory;
        } while (player < this->world->playerCount);
    }
}
