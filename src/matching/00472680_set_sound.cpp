class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x144];
    int field_148;
    void set_sound(int v);
};

void TButtonPanel::set_sound(int v) { this->field_148 = v; }
