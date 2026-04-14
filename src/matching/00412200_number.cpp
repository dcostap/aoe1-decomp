class ResourceItem {
public:
    virtual ~ResourceItem();
    char gap_0[0x68];
    int field_6C;
    int number();
};

int ResourceItem::number() { return this->field_6C; }
