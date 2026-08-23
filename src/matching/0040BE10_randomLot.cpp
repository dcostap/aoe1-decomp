#ifndef AICONMOD_CANONICAL_TU
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
#endif

ConstructionItem* ConstructionAIModule::randomLot(float px, float py) {
#ifdef AICONMOD_CANONICAL_TU
    ConstructionItem* cur = this->randomConstructionLots.next;
    while (cur != &this->randomConstructionLots && cur != 0) {
        if (cur->x() == px && cur->y() == py) {
            return cur;
        }
        cur = cur->next;
    }
    return 0;
#else
    ConstructionItem* cur = randomConstructionLots;
    while (cur != (ConstructionItem*)((char*)this + 0x178) && cur != 0) {
        if (cur->x() == px && cur->y() == py) {
            return cur;
        }
        cur = cur->next;
    }
    return 0;
#endif
}
