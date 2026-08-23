class GlobalUiHost {
public:
    void helper(int flag);
};
extern GlobalUiHost* g_ui;
class SetFocusHost {
public:
    void parent_set_focus(int v);
    void set_focus(int v);
    char gap_00[0x78];
    int field_78;
};
void SetFocusHost::set_focus(int v) {
    this->parent_set_focus(v);
    if (this->field_78) {
        g_ui->helper(0);
    } else {
        g_ui->helper(1);
    }
}
