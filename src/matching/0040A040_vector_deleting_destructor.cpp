class BaseObject {
public:
    virtual ~BaseObject();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *BaseObject::vector_deleting_destructor(unsigned int param_1) {
    this->BaseObject::~BaseObject();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
