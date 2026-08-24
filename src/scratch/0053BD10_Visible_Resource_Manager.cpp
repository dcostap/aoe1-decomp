// vis_unit.cpp target: Visible_Resource_Manager::~Visible_Resource_Manager

#include <stdlib.h>

#if !defined(VIS_UNIT_TU_CONTEXT)
struct VisibleResourceRecord;

class Visible_Resource_Manager {
public:
    VisibleResourceRecord** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    void* owner;
    int num_visible_resource_lists;

    ~Visible_Resource_Manager();
};
#endif

Visible_Resource_Manager::~Visible_Resource_Manager() {
    int i;
    for (i = 0; i < this->num_visible_resource_lists; i++) {
        VisibleResourceRecord* list = this->VR_List[i];
        if (list) free(list);
    }
    if (this->VR_List) free(this->VR_List);
    if (this->VR_ListSize) free(this->VR_ListSize);
    if (this->VR_ListUsed) free(this->VR_ListUsed);
}
