// 005145E0 TRIBE_Player::researchCost
// PDB source: tplayer.cpp

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class ResourceItem {
public:
    void incrementValue(int type, int amount);
};

class TRIBE_Player_Tech {
public:
    void tech_cost(short tech_id, short* inv_2, short* inv_amt_2, short* inv_3, short* inv_amt_3, short* inv_1, short* inv_amt_1);
};

class TRIBE_Player {
public:
    char gap_00[0x220];
    TRIBE_Player_Tech* tech_tree;

    void researchCost(int tech_id, int unused, ResourceItem* resources, int unused2);
};
#endif

void TRIBE_Player::researchCost(int tech_id, int unused, ResourceItem* resources, int unused2) {
    short inv_amt_2;
    short inv_2;
    short inv_amt_3;
    short inv_3;
    short inv_1;
    short inv_amt_1;

    this->tech_tree->tech_cost((short)tech_id, &inv_2, (short*)&tech_id, &inv_3, &inv_amt_3, &inv_1, &inv_amt_1);
    resources->incrementValue(inv_2, (short)tech_id);
    resources->incrementValue(inv_3, inv_amt_3);
    resources->incrementValue(inv_1, inv_amt_1);
}
