// 0045B0A0 TMousePointer::Restore_Mouse
// Source: Mouseptr.cpp lines 163-185. 115 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 115-byte match confirmed via local check_function.py.
// First-pass match with correct member offsets from inventory type dumps.

class IDirectDrawSurface;
class TDrawArea;

class TDrawSystem {
public:
    char gap_00[0x10];
    TDrawArea* PrimaryArea;
    char gap_14[0x08];
    IDirectDrawSurface* PrimarySurface;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x38];
    IDirectDrawSurface* DrawSurface;
};

class TMousePointer {
public:
    int custom_draw;
    TDrawArea* render_area;
    TDrawArea* save_area;
    TDrawArea* primary_area;
    char gap_10[0x110];
    IDirectDrawSurface* renderSurface;
    IDirectDrawSurface* PrimarySurface;
    char gap_128[8];
    int Shutdown;
    int Setup;

    int Restore_Mouse(TDrawArea* param_1);
    int LoadCursors(char* a2, int a3, int a4);
};

int TMousePointer::Restore_Mouse(TDrawArea* param_1) {
    if (this->Shutdown == 0)
        return 0;

    if (this->custom_draw != 0) {
        if (this->Setup == 0)
            return 0;

        this->render_area = param_1;
        this->renderSurface = param_1->DrawSurface;
        this->PrimarySurface = param_1->DrawSystem->PrimarySurface;
        this->primary_area = param_1->DrawSystem->PrimaryArea;

        if (this->LoadCursors(0, -1, 1) == 0)
            return 0;

        this->Shutdown = 0;
    }

    return 1;
}
