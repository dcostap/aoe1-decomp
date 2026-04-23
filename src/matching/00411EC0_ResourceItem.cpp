class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* prev;
    int field_0C[8];
    int sortedValue[8];
    int field_4C[8];
    int field_6C;

    ResourceItem();
};

ResourceItem::ResourceItem() {
    this->next = 0;
    this->prev = 0;
    this->field_6C = 0;
    for (int i = 0; i < 8; i++) {
        this->field_0C[i] = -1;
        this->sortedValue[i] = -1;
        this->field_4C[i] = -1;
    }
}
