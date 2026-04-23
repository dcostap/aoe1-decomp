class BaseItem {
public:
    virtual void vf00(void);
    BaseItem(const BaseItem& other);
};

class ConstructionItem : public BaseItem {
public:
    char gap_04[0x68];
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    ConstructionItem(const ConstructionItem& other);
};

ConstructionItem::ConstructionItem(const ConstructionItem& other)
    : BaseItem(other) {
    this->next = 0;
    this->prev = 0;
    this->inProgressValue = other.inProgressValue;
    this->builtValue = other.builtValue;
    this->buildAttemptsValue = other.buildAttemptsValue;
}
