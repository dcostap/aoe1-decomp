// vis_unit.cpp target: Visible_Resource_Manager::Visible_Resource_Manager(int, RGE_Player*)
// load constructor; reads list counts/sizes, allocates lists, then reads used resource records.
// first draft compiled 10 bytes short because VC5 kept the handle in ebp; keep ebp available for &count and only save handle for the second read phase.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void* __cdecl malloc(unsigned int size);
void rge_read(int handle, void* buffer, int size);

extern float save_game_version;
extern float DAT_005776c8;

class RGE_Player;

class Visible_Resource_Manager {
public:
    void** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    Visible_Resource_Manager(int handle, RGE_Player* owner);
};

Visible_Resource_Manager::Visible_Resource_Manager(int handle, RGE_Player* owner) {
    if (save_game_version >= DAT_005776c8) {
        rge_read(handle, &this->num_visible_resource_lists, 4);
    } else {
        this->num_visible_resource_lists = 5;
    }

    if (this->num_visible_resource_lists > 0) {
        this->VR_List = (void**)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListSize = (int*)calloc(this->num_visible_resource_lists, 4);
        this->VR_ListUsed = (int*)calloc(this->num_visible_resource_lists, 4);
        int i = 0;
        if (this->num_visible_resource_lists > 0) {
            do {
                rge_read(handle, this->VR_ListSize + i, 4);
                rge_read(handle, this->VR_ListUsed + i, 4);
                this->VR_List[i] = malloc(this->VR_ListSize[i] << 3);
                i++;
            } while (i < this->num_visible_resource_lists);
        }
        int savedHandle = handle;
        i = 0;
        if (this->num_visible_resource_lists > 0) {
            do {
                if (this->VR_ListUsed[i] > 0) {
                    rge_read(savedHandle, this->VR_List[i], this->VR_ListUsed[i] * 8);
                }
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
