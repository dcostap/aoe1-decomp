// VA: 00443490 TDrawSystem::HandleQueryNewPalette (134 B)
// PDB source: Drawarea.cpp
// Handles WM_QUERYNEWPALETTE message

struct tagPALETTEENTRY {
    unsigned char peRed, peGreen, peBlue, peFlags;
};

__declspec(dllimport) void* __stdcall GetDC(void* hwnd);
__declspec(dllimport) void* __stdcall SelectPalette(void* hdc, void* hpal, int bForceBackground);
__declspec(dllimport) int __stdcall RealizePalette(void* hdc);
__declspec(dllimport) int __stdcall ReleaseDC(void* hwnd, void* hdc);
__declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, void* rect, int bErase);

class TDrawSystem {
public:
    char gap_00[0x04];
    void* Wnd;                      // +0x04
    void* Pal;                      // +0x08
    char gap_0C[0x46C];
    unsigned char DrawType;         // +0x478
    unsigned char ScreenMode;       // +0x479
    // palette data at +0x78

    void ModifyPalette(int start, int count, tagPALETTEENTRY* entries);
    int HandleQueryNewPalette(void* param1, unsigned int param2, unsigned int param3, long param4);
};

int TDrawSystem::HandleQueryNewPalette(void* param1, unsigned int param2, unsigned int param3, long param4)
{
    if (this->Pal != 0 && (this->DrawType == 1 || this->ScreenMode == 1)) {
        void* hdc = GetDC(this->Wnd);
        if (this->Pal != 0)
            SelectPalette(hdc, this->Pal, 0);
        unsigned char result = (unsigned char)RealizePalette(hdc);
        ReleaseDC(this->Wnd, hdc);
        if (result != 0) {
            InvalidateRect(this->Wnd, 0, 0);
            return 1;
        }
    }
    this->ModifyPalette(0, 256, (tagPALETTEENTRY*)((char*)this + 0x78));
    return 0;
}
