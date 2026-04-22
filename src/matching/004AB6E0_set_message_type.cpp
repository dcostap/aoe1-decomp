class TInputPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void set_value(int value);
};

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
    virtual void vf20(int mode);
};

class TRIBE_Screen_Sed {
public:
    char gap_00[0x4D4];
    TPanel* bottom_panel;
    char gap_4D8[0x29C];
    TInputPanel* message_input;

    void set_message_type(int type, int value);
};

void TRIBE_Screen_Sed::set_message_type(int type, int value) {
    message_input->set_value(value);
    bottom_panel->vf20(1);
}
