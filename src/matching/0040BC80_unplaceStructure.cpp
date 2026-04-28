// ConstructionAIModule::unplaceStructure
// VA: 0040BC80
// aiconmod.cpp:513-529
// Attempt log:
// modeled BaseItem size 0x6C and ConstructionAIModule::constructionLots at +0xF4.
// while (item != sentinel) with explicit null return gives original loop back-edge and MATCH.

class BaseItem {
public:
    virtual ~BaseItem();
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;

    int uniqueID(void) const;
    void setUniqueID(int value);
    float x(void) const;
    float y(void) const;
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    void setInProgress(int value);
    void setBuilt(int value);
    void decrementBuildAttempts(void);
};

class ConstructionAIModule {
public:
    virtual int unplaceStructure(float x, float y, int decrement);
    char gap_04[0xEC];
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
};

int ConstructionAIModule::unplaceStructure(float x, float y, int decrement) {
    int id;
    ConstructionItem* item;

    item = this->constructionLots.next;
    while (item != &this->constructionLots) {
        if (item == 0) {
            return -1;
        }
        if (item->x() == x && item->y() == y) {
            item->setInProgress(0);
            item->setBuilt(0);
            id = item->uniqueID();
            item->setUniqueID(-1);
            if (decrement == 1) {
                item->decrementBuildAttempts();
            }
            return id;
        }
        item = item->next;
    }
    return -1;
}
