// compact list double-click handler first
// expected basin: call goto_item on the click target, then if the parent panel exists and the current line is in range, fire the slot 0xB4 action

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
    virtual void vf58(void*, int, int, int);
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
    virtual void vfB4(void*, int, int, int);

    char pad_00[0x3C];
    TPanel* parent_panel;

    long goto_item(long item_id, long list_index);
};

class TListPanel : public TPanel {
public:
    char pad_44[0xB4];
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;

    long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
};

long TListPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    this->goto_item(param_1, param_2);
    if (this->parent_panel != 0 && this->cur_line > -1 && this->cur_line < this->num_lines) {
        this->parent_panel->vfB4(this, 3, this->cur_line, 0);
    }
    return 1;
}
