// VA: 00476BB0 TEditPanel::handle_reactivate (45 B, EXACT MATCH)
// PDB source: pnl_edit.cpp lines 1060-1067
// Key insight: local void* hFocus = GetFocus() forces VC5 to save this in esi
// and reuse it for edit_wnd after the call. Comparison order matters:
// if (hFocus != this->field_F4) generates cmp eax, esi (3B C6).

__declspec(dllimport) void* __stdcall GetFocus();
__declspec(dllimport) void* __stdcall SetFocus(void* hwnd);

class TEditPanel {
public:
    char gap_00[0x78];
    int field_78;
    char gap_7C[0x78];
    void* field_F4;
    void handle_reactivate();
};

void TEditPanel::handle_reactivate() {
    if (this->field_F4 && this->field_78) {
        void* hFocus = GetFocus();
        if (hFocus != this->field_F4)
            SetFocus(this->field_F4);
    }
}
