class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x70];
    int field_74;
    int inProgress();
};

int ConstructionItem::inProgress() { return this->field_74; }
