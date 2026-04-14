class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x74];
    int field_78;
    void setBuilt(int v);
};

void ConstructionItem::setBuilt(int v) { this->field_78 = v; }
