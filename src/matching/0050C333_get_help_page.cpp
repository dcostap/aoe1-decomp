// matched: /Od debug-style no-PDB TRIBE_Tech bounds-check getter

struct TechEntry {
    char gap_00[0x34];
    long help_page_id;
    char gap_38[0x04];
};

class TRIBE_Tech {
public:
    TechEntry* tech_tree;
    short tech_tree_num;
    char gap_06[2];

    long get_help_page(short param_1);
};

long TRIBE_Tech::get_help_page(short param_1) {
    if (param_1 < 0 || param_1 > this->tech_tree_num) {
        return -1;
    }

    return this->tech_tree[param_1].help_page_id;
}
