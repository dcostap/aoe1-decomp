class TDrawArea {
public:
    virtual ~TDrawArea();
    char gap_0[0xC4];
    int field_C8;
    void SetShadowTable(int v);
};

void TDrawArea::SetShadowTable(int v) { this->field_C8 = v; }
