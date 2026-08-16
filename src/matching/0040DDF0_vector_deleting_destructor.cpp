// VA: 0040DDF0 AIModuleID::`scalar deleting destructor'
// The generated wrapper calls the scalar destructor directly, then honors bit 0
// of the delete flags with the period global operator delete.
class AIModuleID {
public:
    virtual ~AIModuleID();
    void *vector_deleting_destructor(unsigned int flags);
};

void operator delete(void *object);

void *AIModuleID::vector_deleting_destructor(unsigned int flags) {
    this->AIModuleID::~AIModuleID();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
