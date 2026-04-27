// VA: 004433F0
// TDrawSystem::HandleSize(void*, unsigned int, unsigned int, long)
// Source: Drawarea.cpp lines 1155-1172

// attempt 1: natural if-else chain with GetClientRect + two SetSize calls -> EXACT MATCH (109/109, 0.0000%)
// default flags; extern function pointer for IAT-resolved GetClientRect

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

// IAT-resolved GetClientRect via extern function pointer (per AGENTS.md)
extern "C" int (__stdcall * const GetClientRect)(void* hWnd, tagRECT* rect);

class TDrawArea {
public:
    // 004443D0
    void SetSize(long width, long height, int flags);
};

class TDrawSystem {
public:
    void* Inst;               // +0x00
    void* Wnd;                // +0x04
    void* Pal;                // +0x08
    TDrawArea* DrawArea;      // +0x0C
    TDrawArea* PrimaryArea;   // +0x10
    char gap_14[0x18];        // 0x14-0x2B
    int ScreenWidth;          // +0x2C
    int ScreenHeight;         // +0x30
    char gap_34[0x444];       // 0x34-0x477
    unsigned char DrawType;   // +0x478
    unsigned char ScreenMode; // +0x479

    void HandleSize(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
};

void TDrawSystem::HandleSize(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (this->DrawArea == 0) return;

    if (this->DrawType == 1 || this->ScreenMode == 1) {
        tagRECT rect;
        GetClientRect(this->Wnd, &rect);
        this->ScreenWidth = rect.right;
        this->ScreenHeight = rect.bottom;
    }

    if (this->PrimaryArea != 0) {
        this->PrimaryArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
    }

    this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
}
