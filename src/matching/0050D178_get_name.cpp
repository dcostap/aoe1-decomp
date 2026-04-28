// tried /Od (like matched TRIBE_Player_Tech neighbors)
// tried multiple locals (tree ptr, char* p, no locals)
// BLOCKER: rebuilt uses 'sub esp,8' for locals, original uses 'push ecx'
//           this stored at [ebp-8] vs [ebp-4], shifts all offsets
//           size correct (31) but prolog stack allocation differs

struct Tech_Entry {
    char* name;
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
    char* p;
    p = this->base->tech_tree[param_1].name;
    return p;
}
