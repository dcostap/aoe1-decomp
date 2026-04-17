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

    char gap_04[0x7C];
    int active;
    char gap_84[0x22C];
    int disabled;

    void set_disabled(int disabled);
};

void TButtonPanel::set_disabled(int is_disabled) {
    disabled = is_disabled;
    vf20(1);
    if (disabled != 0) {
        active = 0;
        return;
    }
    active = 1;
}
