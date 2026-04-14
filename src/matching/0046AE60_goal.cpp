class Path {
public:
    virtual ~Path();
    char gap_0[0x10];
    char field_14[1];
    char* goal();
};

char* Path::goal() { return this->field_14; }
