class TechnologyItem {
public:
    virtual ~TechnologyItem();
    char gap_0[0xC];
    char field_10[1];
    char* name();
};

char* TechnologyItem::name() { return this->field_10; }
