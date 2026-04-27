// vis_unit.cpp target: Visible_Unit_Manager::Visible_Unit_Manager
// natural constructor allocation loops from packet.
// first compile was behaviorally right but used indexed inner stores; switch to a running short* cursor to mirror original esi-based category initialization.
// current cursor form is very close but retained calloc result; reload PlayerDataPtrs[i] for original's extra load sequence.
// declare the cursor before the positive Category_Count gate so VC5 computes it before the test like the original.
// row local plus cursor inside gate should match original row reload, Category_Count reload, test, then lea cursor.
// tried comma-expression arg side effects; they did not produce original push8/store/push20/store scheduling.
// probing volatile short cursor for store scheduling.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void* __cdecl malloc(unsigned int size);

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

Visible_Unit_Manager::Visible_Unit_Manager(int player_count, int category_count) {
    int i;
    this->Player_Count = player_count;
    this->Category_Count = category_count + 1;
    this->distanceTable = 0;
    this->PlayerDataPtrs = (VisibleUnitPtr**)calloc(player_count, 4);

    for (i = 0; i < this->Player_Count; i++) {
        this->PlayerDataPtrs[i] = (VisibleUnitPtr*)calloc(this->Category_Count, 8);
        int j = 0;
        VisibleUnitPtr* row = this->PlayerDataPtrs[i];
        if (this->Category_Count > 0) {
            volatile short* cursor = &row[0].used;
            do {
                cursor[-1] = 0x20;
                *cursor = 0;
                ((VisibleUnitPtr*)((short*)cursor - 3))->unit_list = calloc(0x20, 8);
                j++;
                cursor += 4;
            } while (j < this->Category_Count);
        }
    }

    for (i = 0; i < 5; i++) {
        this->Return_Buffer[i] = malloc(0x800);
        VisibleUnitList[i] = this->Return_Buffer[i];
        VisibleUnitList_Size[i] = 0;
    }

    this->Build_Distance_Table();
    VisibleUnitManager = this;
}
