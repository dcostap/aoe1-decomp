class DString {
public:
    virtual ~DString();
    int field_4;
    int length();
};

int DString::length() { return this->field_4; }
