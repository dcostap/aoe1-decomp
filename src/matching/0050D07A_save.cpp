#ifndef TECH_GROUP_CONTEXT
// Packet-grounded bodies under quality gate.

#pragma warning(disable: 4035 4805)
#include <stdlib.h>

struct Tech_Player_Tree {
    float research_done;
    short state;
};

struct TRIBE_Tech;
struct RGE_Player;

void __cdecl rge_read(int src, void* dst, int size);
void __cdecl rge_write(int dst, void* src, int size);
long __cdecl __ftol(double);

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    TRIBE_Player_Tech(int param_1, TRIBE_Tech* param_2, RGE_Player* param_3, unsigned char param_4);
    TRIBE_Player_Tech(TRIBE_Tech* param_1, RGE_Player* param_2, unsigned char param_3);
    ~TRIBE_Player_Tech();

    short get_tech_state(short param_1);
    unsigned char do_tech(short param_1);
    unsigned char research(short param_1, float param_2);
    void save(int param_1);
    short get_progress(short param_1);

    unsigned char check_for_new_tech();
};

#endif

void TRIBE_Player_Tech::save(int param_1)
{
    rge_write(param_1, &this->tech_player_tree_num, 2);
    for (short i = 0; i < this->tech_player_tree_num; i++) {
        rge_write(param_1, &this->tech_player_tree[i], 4);
        rge_write(param_1, &this->tech_player_tree[i].state, 2);
    }
}
