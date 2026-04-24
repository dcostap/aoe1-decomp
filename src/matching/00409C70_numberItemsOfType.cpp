class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;

    int typeID();
    int buildCategory();
};

class BuildAIModule {
public:
    char gap_00[0x15C];
    BuildItem* buildList;

    int numberItemsOfType(int typeID, int buildCategory);
};

int BuildAIModule::numberItemsOfType(int typeID, int buildCategory) {
    BuildItem* cur = buildList;
    int count = 0;
    void* sentinel = (void*)((char*)this + 0xF0);
    while (cur != (BuildItem*)sentinel && cur != 0) {
        if (cur->typeID() == typeID && cur->buildCategory() == buildCategory) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}
