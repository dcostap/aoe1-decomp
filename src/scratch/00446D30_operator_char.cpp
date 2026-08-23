class DString {
public:
    char* field_0;
    operator char*();
};

DString::operator char*() { return this->field_0; }
