#ifndef AOE1_PNL_MSG_CONTEXT_H
class TMessagePanel {
public:
    enum JustType {
        TopJust = 0,
        BottomJust = 1,
        LeftJust = 2,
        RightJust = 3,
        CenterJust = 4
    };
    char gap_0[0x320];
    int horz_just;
    int vert_just;
    int word_wrap;
    void set_justification(JustType a, JustType b, int c);
};
#endif

void TMessagePanel::set_justification(TMessagePanel::JustType a,
                                      TMessagePanel::JustType b, int c) {
    this->horz_just = a;
    this->vert_just = b;
    this->word_wrap = c;
}
