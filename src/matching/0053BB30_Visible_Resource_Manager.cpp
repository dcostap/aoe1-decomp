// vis_unit.cpp target: Visible_Resource_Manager::Visible_Resource_Manager(RGE_Player*, int)
// straightforward allocation constructor for visible resource lists.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void* __cdecl malloc(unsigned int size);

class RGE_Player;

class Visible_Resource_Manager {
public:
    void** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    Visible_Resource_Manager(RGE_Player* owner, int count);
};

Visible_Resource_Manager::Visible_Resource_Manager(RGE_Player* owner, int count) {
    this->num_visible_resource_lists = count;
    if (count > 0) {
        this->VR_List = (void**)calloc(count, 4);
        this->VR_ListSize = (int*)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListUsed = (int*)calloc(this->num_visible_resource_lists, 4);
        int i = 0;
        if (this->num_visible_resource_lists > 0) {
            do {
                this->VR_List[i] = malloc(0x100);
                this->VR_ListSize[i] = 0x20;
                this->VR_ListUsed[i] = 0;
                i++;
            } while (i < this->num_visible_resource_lists);
        }
    } else {
        this->VR_List = 0;
        this->VR_ListSize = 0;
        this->VR_ListUsed = 0;
    }
    this->owner = owner;
}
