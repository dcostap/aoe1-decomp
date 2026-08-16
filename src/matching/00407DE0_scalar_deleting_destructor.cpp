class BaseItem {
public:
    virtual ~BaseItem();
    virtual void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *BaseItem::scalar_deleting_destructor(unsigned int param_1) {
    BaseItem *self;

    self = this;
    this->BaseItem::~BaseItem();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
