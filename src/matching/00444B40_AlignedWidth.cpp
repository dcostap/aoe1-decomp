class TDrawArea {
public:
    virtual ~TDrawArea();
    char gap_0[0x1C];
    int field_20;
    int AlignedWidth();
};

int TDrawArea::AlignedWidth() { return this->field_20; }
