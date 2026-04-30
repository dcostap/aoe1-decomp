// TEditPanel::handle_reactivate - set focus to a HWND if conditions met

extern "C" void* __stdcall GetFocus();
extern "C" void* __stdcall SetFocus(void* hwnd);

struct TEditPanel {
    char gap_00[0x78];
    int field_78;        // 0x78
    char gap_7C[0x78];
    void* field_F4;      // 0xF4
};

void __thiscall handle_reactivate(TEditPanel* this) {
    void* hwnd = this->field_F4;
    if (hwnd == 0)
        goto done;
    if (this->field_78 == 0)
        goto done;
    if (GetFocus() == hwnd)
        goto done;
    SetFocus(hwnd);
done:
    return;
}
