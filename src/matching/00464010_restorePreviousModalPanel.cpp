class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void set_focus_state(int focus);

    TPanel* previousModalPanel(void);
};

class TPanelSystem {
public:
    char gap_00[0x08];
    TPanel* modalPanelValue;

    void setMouseOwner(TPanel* owner);
    void setKeyboardOwner(TPanel* owner);
    int restorePreviousModalPanel(void);
};

int TPanelSystem::restorePreviousModalPanel(void) {
    TPanel* panel;

    if (modalPanelValue == 0) {
        return 0;
    }
    panel = modalPanelValue->previousModalPanel();
    if (panel == 0) {
        return 0;
    }
    panel->set_focus_state(1);
    setMouseOwner(panel);
    setKeyboardOwner(panel);
    modalPanelValue = panel;
    return 1;
}
