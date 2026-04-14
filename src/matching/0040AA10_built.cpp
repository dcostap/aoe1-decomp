class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x74];
    int field_78;
    int built();
};

int ConstructionItem::built() { return this->field_78; }
