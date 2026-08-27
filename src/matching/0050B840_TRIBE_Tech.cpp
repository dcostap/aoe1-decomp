#ifndef TECH_GROUP_CONTEXT
// /Od debug-style no-PDB TRIBE_Tech file constructor
// Attempt: variant lab/block-scope probe found the original local topology: outer i at
// [ebp-4], one scoped j reused across both inner loops at [ebp-0C], name_len at [ebp-8].

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
void __cdecl rge_read(int src, void* dst, int size);

struct Tech_Entry {
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short civilization;
    short full_tech_mode;
    unsigned char button_location;
    char gap_27;
    short button_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

struct TRIBE_World;

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;
    char gap_06[2];
    TRIBE_World* world;

    TRIBE_Tech(int param_1, TRIBE_World* param_2);
};

#endif

TRIBE_Tech::TRIBE_Tech(int param_1, TRIBE_World* param_2)
{
    short i;

    this->world = param_2;
    rge_read(param_1, &this->tech_tree_num, 2);
    if (this->tech_tree_num > 0) {
        this->tech_tree = (Tech_Entry*)calloc(0x3c, this->tech_tree_num);
        for (i = 0; i < this->tech_tree_num; i++) {
            { short j; for (j = 0; j < 4; j++) {
                rge_read(param_1, &this->tech_tree[i].pre_reqs[j], 2);
            }
            for (j = 0; j < 3; j++) {
                rge_read(param_1, &this->tech_tree[i].attribute[j], 2);
                rge_read(param_1, &this->tech_tree[i].attribute_cost[j], 2);
                rge_read(param_1, &this->tech_tree[i].attribute_used[j], 1);
            } }
            rge_read(param_1, &this->tech_tree[i].pre_reqs_required, 2);
            rge_read(param_1, &this->tech_tree[i].button_id, 2);
            rge_read(param_1, &this->tech_tree[i].string_id, 2);
            rge_read(param_1, &this->tech_tree[i].string_id2, 2);
            rge_read(param_1, &this->tech_tree[i].research, 2);
            rge_read(param_1, &this->tech_tree[i].effect, 2);
            rge_read(param_1, &this->tech_tree[i].civilization, 2);
            rge_read(param_1, &this->tech_tree[i].full_tech_mode, 2);
            rge_read(param_1, &this->tech_tree[i].button_location, 1);
            rge_read(param_1, &this->tech_tree[i].help_string_id, 4);
            rge_read(param_1, &this->tech_tree[i].help_page_id, 4);
            rge_read(param_1, &this->tech_tree[i].hotkey_id, 4);
            short name_len;
            rge_read(param_1, &name_len, 2);
            if (name_len > 0) {
                this->tech_tree[i].name = (char*)calloc(1, name_len);
                rge_read(param_1, this->tech_tree[i].name, name_len);
            } else {
                this->tech_tree[i].name = 0;
            }
        }
    } else {
        this->tech_tree = 0;
    }
}
