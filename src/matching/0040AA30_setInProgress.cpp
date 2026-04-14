class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x70];
    int field_74;
    void setInProgress(int v);
};

void ConstructionItem::setInProgress(int v) { this->field_74 = v; }
