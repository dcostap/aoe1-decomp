class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[0x68];
    BuildItem* next;
    BuildItem* prev;
    char gap_74[0x3C];
};

class BuildAIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList;
    int buildListLengthValue;

    void removeOldList(void);
};

void BuildAIModule::removeOldList(void) {
    BuildItem* current = this->buildList.next;
    BuildItem* end = &this->buildList;

    while (current != end && current != 0) {
        BuildItem* next = current->next;
        delete current;
        current = next;
    }

    this->buildList.next = end;
    this->buildList.prev = end;
    this->buildListLengthValue = 0;
}
