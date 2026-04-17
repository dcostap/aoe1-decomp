class TButtonPanel {
public:
    char gap_00[0x198];
    char* text1[9];
    char* text2[9];
    char gap_1E0[0x16];
    short cur_state;

    int get_text(short state, char** text1, char** text2);
};

int TButtonPanel::get_text(short state, char** out_text1, char** out_text2) {
    if (state == -1) {
        state = cur_state;
    }
    *out_text1 = text1[state];
    *out_text2 = text2[state];
    return *out_text1 != 0;
}
