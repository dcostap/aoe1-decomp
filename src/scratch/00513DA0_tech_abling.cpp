class Tech_Tree_tab {
public:
    void enable_tech(int tech_id);
    void disable_tech(int tech_id);
};

class TRIBE_Player_tab {
public:
    void tech_abling(int tech_id, unsigned char enable);
    char gap_00[0x220];
    Tech_Tree_tab* tech_tree;
};

void TRIBE_Player_tab::tech_abling(int tech_id, unsigned char enable) {
    if (enable) {
        this->tech_tree->enable_tech(tech_id);
    } else {
        this->tech_tree->disable_tech(tech_id);
    }
}
