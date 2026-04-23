extern "C" void* __stdcall GetFocus(void);
extern "C" void* __stdcall SetFocus(void* wnd);

class TEditPanel {
public:
    char gap_00[0x78];
    int field_78;
    char gap_7C[0x74];
    void* edit_wnd;

    virtual void handle_reactivate(void);
};

void TEditPanel::handle_reactivate(void) {
    void* edit_wnd;

    edit_wnd = this->edit_wnd;
    if (edit_wnd != 0 && this->field_78 != 0) {
        if (GetFocus() != edit_wnd) {
            SetFocus(edit_wnd);
        }
    }
}
