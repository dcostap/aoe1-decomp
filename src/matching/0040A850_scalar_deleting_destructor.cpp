class ConstructionItem {
public:
    virtual ~ConstructionItem();
    virtual void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *ConstructionItem::scalar_deleting_destructor(unsigned int param_1) {
    this->ConstructionItem::~ConstructionItem();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
