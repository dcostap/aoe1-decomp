class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_04[0x68];
    ConstructionItem* next;
    ConstructionItem* prev;
};

class ConstructionAIModule {
public:
    char gap_00[0xF0];
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;

    void removeOldLots(void);
};

void ConstructionAIModule::removeOldLots(void) {
    ConstructionItem* item = this->constructionLots.next;
    ConstructionItem* end = &this->constructionLots;

    while (item != end && item != 0) {
        ConstructionItem* next = item->next;
        delete item;
        item = next;
    }

    this->constructionLots.next = end;
    this->constructionLots.prev = end;
    this->numberConstructionLotsValue = 0;
}
