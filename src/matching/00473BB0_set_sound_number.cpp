class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x2B0];
    int field_2B4;
    void set_sound_number(int v);
};

void TButtonPanel::set_sound_number(int v) { this->field_2B4 = v; }
