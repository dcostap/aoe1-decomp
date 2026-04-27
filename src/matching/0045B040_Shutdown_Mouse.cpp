// attempt 1: straightforward guard/cleanup translation with the reset helper and the listed zero stores
// result: the first pass needed the real field aliases at +4/+0x0c/+0x11c/+0x120/+0x124/+0x128
// attempt 2: kept the guard order natural and matched the return-arm layout exactly

class TMousePointer {
public:
    int custom_draw;
    int render_area;
    int save_area;
    int primary_area;
    char gap_10[0x11C - 0x10];
    int restoreSurface;
    int renderSurface;
    int PrimarySurface;
    int active;
    char gap_12C[0x130 - 0x12C];
    int Shutdown;
    int Setup;

    void reset();
    int Shutdown_Mouse();
};

int TMousePointer::Shutdown_Mouse() {
    if (this->Shutdown != 0) {
        return 0;
    }
    if (this->custom_draw == 0) {
        return 1;
    }
    if (this->Setup == 0) {
        return 0;
    }
    this->reset();
    this->render_area = 0;
    this->restoreSurface = 0;
    this->renderSurface = 0;
    this->PrimarySurface = 0;
    this->primary_area = 0;
    this->active = 0;
    this->Shutdown = 1;
    return 1;
}
