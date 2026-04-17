class TButtonPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int param_1);

    char gap_04[0x138];
    int buttonTypeValue;
    char gap_140[0xB8];
    int is_down;

    void release_mouse(void);
    void reset(void);
};

void TButtonPanel::reset(void) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        vf20(1);
    }
}
