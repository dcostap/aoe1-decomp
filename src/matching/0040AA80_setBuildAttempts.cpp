class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x78];
    int field_7C;
    void setBuildAttempts(int v);
};

void ConstructionItem::setBuildAttempts(int v) { this->field_7C = v; }
