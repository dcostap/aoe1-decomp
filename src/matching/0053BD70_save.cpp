// vis_unit.cpp target: Visible_Resource_Manager::save
// writes list count, per-list sizes/used counts, then used resource records.

void rge_write(int handle, void* buffer, int size);

#if !defined(VIS_UNIT_TU_CONTEXT)
class Visible_Resource_Manager {
public:
    void** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    void* owner;
    int num_visible_resource_lists;

    void save(int handle);
};
#endif

void Visible_Resource_Manager::save(int handle) {
    rge_write(handle, &this->num_visible_resource_lists, 4);
    int i = 0;
    if (this->num_visible_resource_lists > 0) {
        do {
            rge_write(handle, this->VR_ListSize + i, 4);
            rge_write(handle, this->VR_ListUsed + i, 4);
            i++;
        } while (i < this->num_visible_resource_lists);
    }
    i = 0;
    if (this->num_visible_resource_lists > 0) {
        do {
            if (this->VR_ListUsed[i] > 0) {
                rge_write(handle, this->VR_List[i], this->VR_ListUsed[i] << 3);
            }
            i++;
        } while (i < this->num_visible_resource_lists);
    }
}
