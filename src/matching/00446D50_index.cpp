class DString {
public:
    virtual ~DString();
    char gap_0[0x8];
    int field_C;
    int index();
};

int DString::index() { return this->field_C; }
