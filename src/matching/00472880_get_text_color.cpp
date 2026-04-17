class TButtonPanel {
public:
    char gap_00[0x1F6];
    short cur_state;
    char gap_1F8[0x10];
    unsigned long text_color1[9];
    unsigned long text_color2[9];

    void get_text_color(short state, unsigned long* color1, unsigned long* color2);
};

void TButtonPanel::get_text_color(short state, unsigned long* color1, unsigned long* color2) {
    if (state == -1) {
        state = cur_state;
    }
    *color1 = text_color1[state];
    *color2 = text_color2[state];
}
