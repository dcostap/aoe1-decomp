class ResourceItem {
public:
    virtual void scalar_deleting_destructor(unsigned int param_1);
};

class TechnologyItem {
public:
    virtual ~TechnologyItem();
    char gap_04[0x4C];
    ResourceItem* resourceCostValue;
};

TechnologyItem::~TechnologyItem() {
    if (this->resourceCostValue != 0) {
        this->resourceCostValue->scalar_deleting_destructor(1);
    }
}
