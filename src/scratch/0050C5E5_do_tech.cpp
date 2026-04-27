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

// Helper wrappers for thiscall externs
struct TRIBE_Tech_Helper {
    unsigned char do_tech(short param_1, RGE_Player* param_2);
};
struct TRIBE_History_Info_Helper {
    void add_history_event(unsigned char param_1);
};

unsigned char TRIBE_Player_Tech::do_tech(short param_1)
{
    if (this->tech_player_tree[param_1].state >= 3 || this->tech_player_tree[param_1].state < 0) {
        return 0;
    }
    this->tech_player_tree[param_1].state = 3;
    ((TRIBE_Tech_Helper*)this->base_tech)->do_tech(param_1, this->owner);
    check_for_new_tech();
    if (param_1 == 0x65) {
        ((TRIBE_History_Info_Helper*)(*(void**)((char*)this->owner + 0x83c)))->add_history_event(0);
    } else if (param_1 == 0x66) {
        ((TRIBE_History_Info_Helper*)(*(void**)((char*)this->owner + 0x83c)))->add_history_event(1);
    } else if (param_1 == 0x67) {
        ((TRIBE_History_Info_Helper*)(*(void**)((char*)this->owner + 0x83c)))->add_history_event(2);
    }
    return 1;
}
