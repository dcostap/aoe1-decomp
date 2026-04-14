class Path {
public:
    virtual ~Path();
    char gap_0[0x2C];
    int field_30;
    void initToStart();
};

void Path::initToStart() { this->field_30 = 0; }
