class ResourceAIModule {
public:
    virtual void* vector_deleting_destructor(unsigned int flags);
    ~ResourceAIModule();
};

extern "C" void operator_delete(void* ptr);

void* ResourceAIModule::vector_deleting_destructor(unsigned int flags) {
    ResourceAIModule* self;

    self = this;
    this->~ResourceAIModule();
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
