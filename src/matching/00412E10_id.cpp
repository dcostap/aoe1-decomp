class TechnologyItem {
public:
    virtual ~TechnologyItem();
    char gap_0[0x8];
    int field_C;
    int id();
};

int TechnologyItem::id() { return this->field_C; }
