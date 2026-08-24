#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void notify(int param);
    char gap_4[0x112];
    int field_118;

    void set_word_wrap(int value);
};
#endif

void TTextPanel::set_word_wrap(int value) {
    this->field_118 = value;
    this->notify(1);
}
