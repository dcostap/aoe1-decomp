// matched: /Od debug-style no-PDB getter; Tech_Entry stride is 0x3C

struct Tech_Entry {
    char gap_00[0x26];
    unsigned char button_location;
    char gap_27[0x15];
};

struct Tech_Base {
    Tech_Entry* tech_tree;
};

class TRIBE_Player_Tech {
public:
    char gap_00[0x08];
    Tech_Base* base;

    unsigned char get_button_location(short param_1);
};

unsigned char TRIBE_Player_Tech::get_button_location(short param_1) {
    return this->base->tech_tree[param_1].button_location;
}
