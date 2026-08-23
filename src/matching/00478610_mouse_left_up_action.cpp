// TListPanel::mouse_left_up_action — release mouse, clear scroll, then conditionally dispatch callback with action=2

#ifndef AOE1_PNL_LST_CONTEXT_H
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
    virtual long action(TPanel* caller, long action, unsigned long index,
                        unsigned long zero);

    void release_mouse();

    char pad_00[0x3C];
    TPanel* parent_panel;
};

class TListPanel : public TPanel {
public:
    char pad_44[0xB4];
    short num_lines;
    char gap_FA[6];
    short cur_line;
    char pad_102[0x92];
    int mouse_scroll_up;
    int mouse_scroll_down;

    long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
};
#endif

long TListPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    release_mouse();
    this->mouse_scroll_up = 0;
    this->mouse_scroll_down = 0;
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->action(this, 2, this->cur_line, 0);
    }
    return 1;
}
