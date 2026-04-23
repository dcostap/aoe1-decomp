class PausePanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void set_state(int value);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int value);

    char gap_04[0x68];
    int field_6C;
};

class MainView {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int value);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    MainView* main_view;
    char gap_4BC[0xC8];
    PausePanel* pause_text;

    void handle_resume(void);
};

void TRIBE_Screen_Game::handle_resume(void) {
    if (this->pause_text->field_6C != 0) {
        this->pause_text->set_state(0);
        this->pause_text->redraw(1);
        this->main_view->redraw(1);
    }
}
