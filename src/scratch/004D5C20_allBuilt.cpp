// TribeBuildAIModule::allBuilt
// VA: 004D5C20
// PDB: taibldmd.cpp:1680-1695

class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;

    int buildCategory();
    int built();
    int inProgress();
};

class TribeBuildAIModule {
public:
    char gap_00[0xF0];
    char sentinel[0x6C];
    BuildItem* first; // +0x15C

    int allBuilt(int param_1, int param_2);
};

int TribeBuildAIModule::allBuilt(int param_1, int param_2)
{
    BuildItem* item = this->first;
    BuildItem* sentinel = (BuildItem*)((char*)this + 0x0F0);

    if (item != sentinel) {
        int bx = param_2;
        int bp = param_1;
        while (item != 0) {
            int cat = item->buildCategory();
            if (cat == bp || item->buildCategory() == bx) {
                if (!item->built() && !item->inProgress()) {
                    return 0;
                }
            }
            item = item->next;
            if (item == sentinel) {
                return 1;
            }
        }
    }
    return 1;
}
