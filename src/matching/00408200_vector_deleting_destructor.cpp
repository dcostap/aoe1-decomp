class BaseItem {
public:
    virtual ~BaseItem();
};

class BuildItem : public BaseItem {
public:
    virtual ~BuildItem();
    virtual void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *BuildItem::vector_deleting_destructor(unsigned int param_1) {
    BuildItem *self;

    self = this;
    this->BuildItem::~BuildItem();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
