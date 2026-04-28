// matched: /Od plus direct return avoids an extra result local; Tech_Entry stride is 0x3C

struct Tech_Entry {
    char* name;
    char gap_04[0x38];
};

struct Tech_Base {
    Tech_Entry* tech_tree;
};

class TRIBE_Player_Tech {
public:
    char gap_00[0x08];
    Tech_Base* base;

    char* get_name(short param_1);
};

char* TRIBE_Player_Tech::get_name(short param_1) {
    return this->base->tech_tree[param_1].name;
}
