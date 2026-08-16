// VA: 0040DF30 AIModuleMessage::`scalar deleting destructor'
// The generated wrapper calls the scalar destructor directly, then honors bit 0
// of the delete flags with the period global operator delete.
class AIModuleMessage {
public:
    virtual ~AIModuleMessage();
    void *scalar_deleting_destructor(unsigned int flags);
};

void operator delete(void *object);

void *AIModuleMessage::scalar_deleting_destructor(unsigned int flags) {
    this->AIModuleMessage::~AIModuleMessage();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
