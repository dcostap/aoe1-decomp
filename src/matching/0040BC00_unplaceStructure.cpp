// The original packet preserves the ConstructionItem operator== decorated
// identity. The reviewed symbol override validates this natural list search.

class ConstructionItem;

int __cdecl operator==(const ConstructionItem& a, const ConstructionItem& b);

class BaseItem {
public:
    char gap_00[0x0C];
    int uniqueIDValue;

    int uniqueID();
    void setUniqueID(int v);
};

class ConstructionItem : public BaseItem {
public:
    char gap_10[0x5C];
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    void setInProgress(int v);
    void setBuilt(int v);
    void decrementBuildAttempts();
};

class ConstructionAIModule {
public:
    char gap_00[0xF4];
    ConstructionItem constructionLots;

    int unplaceStructure(ConstructionItem* item, int decrement);
};

int ConstructionAIModule::unplaceStructure(ConstructionItem* item, int decrement) {
    ConstructionItem* current;
    ConstructionItem* end;
    ConstructionItem* target = item;
    int oldID;

    current = this->constructionLots.next;
    end = &this->constructionLots;
    while (current != end) {
        if (current == 0) {
            break;
        }
        if (operator==(*current, *target)) {
            current->setInProgress(0);
            current->setBuilt(0);
            oldID = current->uniqueID();
            current->setUniqueID(-1);
            if (decrement == 1) {
                current->decrementBuildAttempts();
            }
            return oldID;
        }
        current = current->next;
    }
    return -1;
}
