class ConstructionItem {
public:
    char gap_00[0x6C];
    ConstructionItem* next;

    float x();
    float y();
};

class ConstructionAIModule {
public:
    char gap_00[0x1E4];
    ConstructionItem* randomConstructionLots;

    ConstructionItem* randomLot(float px, float py);
};

ConstructionItem* ConstructionAIModule::randomLot(float px, float py) {
    ConstructionItem* cur = randomConstructionLots;
    while (cur != (ConstructionItem*)((char*)this + 0x178) && cur != 0) {
        if (cur->x() == px && cur->y() == py) {
            return cur;
        }
        cur = cur->next;
    }
    return 0;
}
