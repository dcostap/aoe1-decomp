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

    void setBuilt(int v);
};

class ConstructionAIModule {
public:
    char gap_00[0xF4];
    ConstructionItem constructionLots;

    void setBuilt(ConstructionItem* item, int built);
};

void ConstructionAIModule::setBuilt(ConstructionItem* item, int built) {
    ConstructionItem* current;
    ConstructionItem* end;
    ConstructionItem* target = item;

    current = this->constructionLots.next;
    end = &this->constructionLots;
    while (current != end) {
        if (current == 0) {
            break;
        }
        if (operator==(*current, *target)) {
            current->setBuilt(built);
            return;
        }
        current = current->next;
    }
}
