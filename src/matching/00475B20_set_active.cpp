extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow);

class TPanel {
public:
    virtual void set_active(int active);
};

class TEditPanel : public TPanel {
public:
    char gap_04[0x68];
    int field_6C;
    char gap_70[0x84];
    void* edit_wnd;
    char gap_F8[0x0C];
    int hidden;

    void set_active(int active);
};

void TEditPanel::set_active(int active) {
    TPanel::set_active(active);
    if ((this->edit_wnd != 0) && (this->field_6C == 0)) {
        ShowWindow(this->edit_wnd, 0);
        this->hidden = 1;
    }
}
