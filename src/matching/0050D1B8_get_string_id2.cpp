// matched: /Od debug-style no-PDB getter; Tech_Entry stride is 0x3C

struct Tech_Entry {
    char gap_00[0x2C];
    short string_id2;
    char gap_2E[0x0E];
};

struct Tech_Base {
    Tech_Entry* tech_tree;
};

class TRIBE_Player_Tech {
public:
    char gap_00[0x08];
    Tech_Base* base;

    short get_string_id2(short param_1);
};

short TRIBE_Player_Tech::get_string_id2(short param_1) {
    return this->base->tech_tree[param_1].string_id2;
}
