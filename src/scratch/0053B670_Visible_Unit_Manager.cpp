// vis_unit.cpp target: Visible_Unit_Manager::~Visible_Unit_Manager
// Natural destructor from the packet: free nested unit lists, return buffers,
// the distance table, and the manager globals.

#include <stdlib.h>

#if !defined(VIS_UNIT_TU_CONTEXT)
struct VisibleUnitPtr {
    void* unit_list;
    int count;
};

extern void* VisibleUnitList[5];
extern int VisibleUnitList_Size[5];
extern void* VisibleUnitManager;

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    void* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    void* distanceTable;

    ~Visible_Unit_Manager();
};
#endif

Visible_Unit_Manager::~Visible_Unit_Manager() {
    int i;
    if (this->PlayerDataPtrs != 0) {
        for (i = 0; i < this->Player_Count; i++) {
            VisibleUnitPtr* playerData = this->PlayerDataPtrs[i];
            if (playerData != 0) {
                int j;
                for (j = 0; j < this->Category_Count; j++) {
                    if (playerData[j].unit_list != 0) {
                        free(playerData[j].unit_list);
                    }
                }
                free(playerData);
            }
        }
        free(this->PlayerDataPtrs);
    }

    for (i = 0; i < 5; i++) {
        if (this->Return_Buffer[i] != 0) {
            free(this->Return_Buffer[i]);
        }
        VisibleUnitList[i] = 0;
        VisibleUnitList_Size[i] = 0;
    }

    if (this->distanceTable != 0) {
        free(this->distanceTable);
    }
    VisibleUnitManager = 0;
}
