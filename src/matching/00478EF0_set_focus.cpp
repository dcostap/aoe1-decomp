// TListPanel::set_focus — matching pattern from mouse_left_dbl_click_action

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
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
    virtual void vf58(void*, int, int, int);
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
    virtual void vfB4(void* caller, int action, int index, int zero);

    char pad_00[0x3C];
    TPanel* parent_panel;

    void set_focus(int focus);
};

class TListPanel : public TPanel {
public:
    char pad_44[0x34];
    void* field_78;
    char pad_7C[0x7C];
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;

    void set_focus(int focus);
};

void TListPanel::set_focus(int focus) {
    TPanel::set_focus(focus);
    if (this->field_78 != 0 && this->parent_panel != 0 &&
        this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->vfB4(this, 1, this->cur_line, 0);
    }
}
