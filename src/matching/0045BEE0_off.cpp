// attempt 6: direct non-virtual DrawSystem::Paint call via draw_area->draw_system
extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);
class TDrawSystem { public: void Paint(void* rect); };
class TDrawArea { public: TDrawSystem* draw_system; };
class TMousePointer {
public:
    void* custom_draw;
    TDrawArea* draw_area;
    char gap_08[0xB8-0x08];
    void* save_area_valid;
    char gap_BC[0xFC-0xBC];
    int restore_rect[4];
    char gap_10C[0x128-0x10C];
    int active;
    int drawn;
    int Shutdown;
    void erase();
    void reset();
    void off();
};
void TMousePointer::off() {
    if (this->Shutdown == 0) {
        if (this->custom_draw != 0 && this->drawn != 0 && this->save_area_valid != 0) {
            this->erase();
            this->draw_area->draw_system->Paint(&this->restore_rect);
        }
        SetCursor(0);
        this->active = 0;
        this->reset();
    }
}
