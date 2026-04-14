class TListPanel {
public:
    virtual ~TListPanel();
    char gap_0[0x184];
    int field_188;
    void set_auto_track(int v);
};

void TListPanel::set_auto_track(int v) { this->field_188 = v; }
