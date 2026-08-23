// vis_unit.cpp target: Visible_Unit_Manager::~Visible_Unit_Manager
// initial natural destructor from packet: free nested unit lists, return buffers, distance table, and clear globals.

void operator_delete(void* ptr);

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

Visible_Unit_Manager::~Visible_Unit_Manager() {
    int i;
    if (this->PlayerDataPtrs != 0) {
        for (i = 0; i < this->Player_Count; i++) {
            VisibleUnitPtr* playerData = this->PlayerDataPtrs[i];
            if (playerData != 0) {
                int j;
                for (j = 0; j < this->Category_Count; j++) {
                    if (playerData[j].unit_list != 0) {
                        operator_delete(playerData[j].unit_list);
                    }
                }
                operator_delete(playerData);
            }
        }
        operator_delete(this->PlayerDataPtrs);
    }

    for (i = 0; i < 5; i++) {
        if (this->Return_Buffer[i] != 0) {
            operator_delete(this->Return_Buffer[i]);
        }
        VisibleUnitList[i] = 0;
        VisibleUnitList_Size[i] = 0;
    }

    if (this->distanceTable != 0) {
        operator_delete(this->distanceTable);
    }
    VisibleUnitManager = 0;
}
