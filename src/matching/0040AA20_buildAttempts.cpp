class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x78];
    int field_7C;
    int buildAttempts();
};

int ConstructionItem::buildAttempts() { return this->field_7C; }
