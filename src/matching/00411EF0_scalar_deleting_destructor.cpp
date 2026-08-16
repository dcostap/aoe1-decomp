class ResourceItem {
public:
    virtual void* scalar_deleting_destructor(unsigned int flags);
    ~ResourceItem();
};

extern "C" void operator_delete(void* ptr);

void* ResourceItem::scalar_deleting_destructor(unsigned int flags) {
    ResourceItem* self;

    self = this;
    this->~ResourceItem();
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
