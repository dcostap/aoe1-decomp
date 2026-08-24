// vis_unit.cpp target: Visible_Unit_Manager::Visible_Unit_Manager
// Natural constructor allocation loops from the packet. The category record is
// eight bytes: a list pointer and two 16-bit counters.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void* __cdecl malloc(unsigned int size);

#if !defined(VIS_UNIT_TU_CONTEXT)
struct VisibleUnitPtr {
    void* unit_list;
    short allocated;
    short used;
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

    Visible_Unit_Manager(int player_count, int category_count);
    void Build_Distance_Table();
};
#endif

Visible_Unit_Manager::Visible_Unit_Manager(int player_count, int category_count) {
    int i;
    this->Player_Count = player_count;
    this->Category_Count = category_count + 1;
    this->distanceTable = 0;
    this->PlayerDataPtrs = (VisibleUnitPtr**)calloc(player_count, 4);

    for (i = 0; i < this->Player_Count; i++) {
        this->PlayerDataPtrs[i] = (VisibleUnitPtr*)calloc(this->Category_Count, 8);
        VisibleUnitPtr* row = this->PlayerDataPtrs[i];
        for (int j = 0; j < this->Category_Count; j++) {
            row[j].allocated = 0x20;
            row[j].used = 0;
#if defined(VIS_UNIT_TU_CONTEXT)
            row[j].unit_list = (VisibleUnitRec*)calloc(0x20, 8);
#else
            row[j].unit_list = calloc(0x20, 8);
#endif
        }
    }

    for (i = 0; i < 5; i++) {
#if defined(VIS_UNIT_TU_CONTEXT)
        this->Return_Buffer[i] = (VisibleUnitRec*)malloc(0x800);
#else
        this->Return_Buffer[i] = malloc(0x800);
#endif
        VisibleUnitList[i] = this->Return_Buffer[i];
        VisibleUnitList_Size[i] = 0;
    }

    this->Build_Distance_Table();
    VisibleUnitManager = this;
}
