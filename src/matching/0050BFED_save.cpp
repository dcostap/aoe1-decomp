// /Od debug-style no-PDB TRIBE_Tech::save

extern "C" int __cdecl strlen(const char* s);
void __cdecl rge_write(int dst, const void* src, int size);

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

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;

    void save(int param_1);
};

void TRIBE_Tech::save(int param_1)
{
    short i;

    rge_write(param_1, &this->tech_tree_num, 2);
    for (i = 0; i < this->tech_tree_num; i++) {
        short name_len;
        if (this->tech_tree[i].name != 0) {
            name_len = (short)(strlen(this->tech_tree[i].name) + 1);
        } else {
            name_len = 0;
        }
        {
            short j;
            for (j = 0; j < 4; j++) {
                rge_write(param_1, &this->tech_tree[i].pre_reqs[j], 2);
            }
            for (j = 0; j < 3; j++) {
                rge_write(param_1, &this->tech_tree[i].attribute[j], 2);
                rge_write(param_1, &this->tech_tree[i].attribute_cost[j], 2);
                rge_write(param_1, &this->tech_tree[i].attribute_used[j], 1);
            }
        }
        rge_write(param_1, &this->tech_tree[i].pre_reqs_required, 2);
        rge_write(param_1, &this->tech_tree[i].button_id, 2);
        rge_write(param_1, &this->tech_tree[i].string_id, 2);
        rge_write(param_1, &this->tech_tree[i].string_id2, 2);
        rge_write(param_1, &this->tech_tree[i].research, 2);
        rge_write(param_1, &this->tech_tree[i].effect, 2);
        rge_write(param_1, &this->tech_tree[i].civilization, 2);
        rge_write(param_1, &this->tech_tree[i].full_tech_mode, 2);
        rge_write(param_1, &this->tech_tree[i].button_location, 1);
        rge_write(param_1, &this->tech_tree[i].help_string_id, 4);
        rge_write(param_1, &this->tech_tree[i].help_page_id, 4);
        rge_write(param_1, &this->tech_tree[i].hotkey_id, 4);
        rge_write(param_1, &name_len, 2);
        if (name_len > 0) {
            rge_write(param_1, this->tech_tree[i].name, name_len);
        }
    }
}
