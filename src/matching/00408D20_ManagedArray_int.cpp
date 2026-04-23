void __cdecl operator delete(void* ptr);

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedArray_int();
};

ManagedArray_int::~ManagedArray_int() {
    if (this->value != 0) {
        operator delete(this->value);
        this->value = 0;
    }
    this->numberValue = 0;
    this->desiredNumberValue = 0;
    this->maximumSizeValue = 0;
}
