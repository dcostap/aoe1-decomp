class TButtonPanel {
public:
    virtual void* scalar_deleting_destructor(unsigned int flags);
    ~TButtonPanel();
};

extern "C" void operator_delete(void* ptr);

void* TButtonPanel::scalar_deleting_destructor(unsigned int flags) {
    TButtonPanel* self;

    self = this;
    this->~TButtonPanel();
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
