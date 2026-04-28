// matched candidate: /Od debug-style no-PDB TRIBE_Tech destructor

extern "C" void __cdecl free(void* p);

struct Tech_Entry {
    char* name;
    char gap_04[0x38];
};

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;

    ~TRIBE_Tech();
};

TRIBE_Tech::~TRIBE_Tech()
{
    int i;

    if (this->tech_tree) {
        for (i = 0; i < this->tech_tree_num; i++) {
            if (this->tech_tree[i].name) {
                free(this->tech_tree[i].name);
            }
        }
        free(this->tech_tree);
        this->tech_tree = 0;
    }
}
