class BaseItem {
public:
    virtual void vf00(void);

    BaseItem();
};

class ConstructionItem : public BaseItem {
public:
    char gap_04[0x68];
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    ConstructionItem();
};

ConstructionItem::ConstructionItem() {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = 0;
    this->builtValue = 0;
    this->buildAttemptsValue = 0;
}
