class TPanel {
public:
    long handle_user_command(unsigned int command, long param);
};

class TribeMPSetupScreen {
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
    virtual long handle_user_command(unsigned int command, long param);
};

class TribeGameSettingsScreen : public TPanel {
public:
    char gap_04[0x550];
    TribeMPSetupScreen* chat_scr;

    long handle_user_command(unsigned int command, long param);
};

long TribeGameSettingsScreen::handle_user_command(unsigned int command, long param) {
    if (this->chat_scr != 0) {
        long result = this->chat_scr->handle_user_command(command, param);
        if (result != 0) {
            return result;
        }
    }
    return ((TPanel*)this)->handle_user_command(command, param);
}
