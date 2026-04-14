class TechnologyItem {
public:
    virtual ~TechnologyItem();
    char gap_0[0x4C];
    int field_50;
    int resourceCost();
};

int TechnologyItem::resourceCost() { return this->field_50; }
