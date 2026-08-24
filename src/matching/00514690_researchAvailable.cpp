#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
struct TechPlayerEntry {
    char gap_00[4];
    short state;
    short gap_06;
};

struct TechTree {
    TechPlayerEntry* tech_player_tree;
};

class TRIBE_Player {
public:
    char gap_00[0x220];
    TechTree* tech_tree;

    int researchAvailable(int index);
};
#endif

int TRIBE_Player::researchAvailable(int index) {
    return this->tech_tree->tech_player_tree[index].state == 1;
}
