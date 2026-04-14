class ConstructionItem {
public:
    virtual ~ConstructionItem();
    char gap_0[0x78];
    int field_7C;
    void incrementBuildAttempts();
};

void ConstructionItem::incrementBuildAttempts() { this->field_7C++; }
