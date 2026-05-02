// VA: 004972A0 TRIBE_Screen_Game::handle_pause (70B)
// PDB source: scr_game.cpp lines 2090-2107

class TTextPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14(int);
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int);
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4(int);

    char gap_E8[0x6C - 4];
    int pause_flag;
};

class TRIBE_Main_View {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    TRIBE_Main_View* main_view;
    char gap_4BC[0x584 - 0x4BC];
    TTextPanel* pause_text;

    void handle_pause(void);
};

void TRIBE_Screen_Game::handle_pause(void) {
    this->pause_text->vfE4(0x2329);
    if (this->pause_text->pause_flag == 0) {
        this->pause_text->vf14(1);
        this->pause_text->vf20(1);
    }
    this->main_view->vf20(1);
}
