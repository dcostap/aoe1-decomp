// CheckAvailModes — canonical reconstruction from Drawarea.cpp lines 444-498
// VA: 004427A0
// Attempt log:
// baseline: natural TDrawSystem field/member and DirectDraw/GDI API surfaces;
//           mode flags are at +4C/+50/+54/+58 and DirDraw is at +18.
// probe 2: inclusive width thresholds (>= 800/1024/1280) restored the original
//           cmp/jl forms and produced an exact 190-byte match under default flags.

extern "C" __declspec(dllimport) void* __stdcall CreateICA(
    const char* driver, const char* device, const char* output, const char* data);
extern "C" __declspec(dllimport) int __stdcall GetDeviceCaps(void* dc, int index);
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* dc);
extern "C" long __stdcall DirectDrawCreate(void* guid, void* direct_draw, void* outer);

class IDirectDrawLike {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper();
    virtual long __stdcall CreatePalette();
    virtual long __stdcall CreateSurface();
    virtual long __stdcall DuplicateSurface();
    virtual long __stdcall EnumDisplayModes(
        unsigned long flags, void* desc, void* context, void* callback);
};

class TDrawSystem {
public:
    char gap_00[0x18];
    IDirectDrawLike* DirDraw;
    char gap_1C[0x30];
    int ModeAvail640;
    int ModeAvail800;
    int ModeAvail1024;
    int ModeAvail1280;

    static long __stdcall CheckAvailModesCallback(void* mode_desc, void* context);
    void CheckAvailModes(int param_1);
};

void TDrawSystem::CheckAvailModes(int param_1)
{
    if (param_1 == 0) {
        this->ModeAvail640 = 1;
        void* dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
            int width = GetDeviceCaps(dc, 8);
            GetDeviceCaps(dc, 10);
            DeleteDC(dc);
            if (width >= 800)
                this->ModeAvail800 = 1;
            if (width >= 1024)
                this->ModeAvail1024 = 1;
            if (width >= 1280)
                this->ModeAvail1280 = 1;
        }
    } else {
        IDirectDrawLike** direct_draw = &this->DirDraw;
        int was_present;
        if (this->DirDraw == 0) {
            if (DirectDrawCreate(0, direct_draw, 0) != 0)
                return;
            was_present = 0;
        } else {
            was_present = 1;
        }

        (*direct_draw)->EnumDisplayModes(0, 0, this, CheckAvailModesCallback);
        if (was_present == 0) {
            (*direct_draw)->Release();
            *direct_draw = 0;
        }
    }
}
