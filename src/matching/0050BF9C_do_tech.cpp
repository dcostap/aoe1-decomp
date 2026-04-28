// matched candidate: /Od debug-style no-PDB TRIBE_Tech effect dispatcher

struct RGE_Player;

struct RGE_Effects {
    virtual void vf00();
    virtual void vf04();
    virtual void do_effect(short effect, RGE_Player* player);
};

struct TRIBE_World {
    char gap_00[0x4C];
    RGE_Effects* effects;
};

struct Tech_Entry {
    char gap_00[0x20];
    short effect;
    char gap_22[0x1A];
};

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;
    TRIBE_World* world;

    unsigned char do_tech(short param_1, RGE_Player* param_2);
};

unsigned char TRIBE_Tech::do_tech(short param_1, RGE_Player* param_2)
{
    if (this->tech_tree[param_1].effect >= 0) {
        this->world->effects->do_effect(this->tech_tree[param_1].effect, param_2);
    }
    return 1;
}
