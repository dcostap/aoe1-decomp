extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void* instance, const char* name);
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);

class TMousePointer {
public:
    int custom_draw;
    char gap_04[0x124];
    int active;
    char gap_12C[0x04];
    int Shutdown;

    void on(void);
};

void TMousePointer::on(void) {
    if (this->Shutdown == 0) {
        if (this->custom_draw == 0) {
            SetCursor(LoadCursorA(0, (const char*)0x7F00));
        }
        this->active = 1;
    }
}
