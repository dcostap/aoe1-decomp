struct IDirectDrawSurface;
struct TDrawSystem {
    char gap_00[0x478];
    unsigned char DrawType;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;

    void ReleaseDc(char* unused);
};

struct IDirectDrawSurface {
    void** vftable;
};

typedef void (__stdcall *ReleaseDcFn)(IDirectDrawSurface*, void*);

void TDrawArea::ReleaseDc(char*) {
    IDirectDrawSurface* surface;

    if ((this->DrawSystem != 0) && (this->DrawSystem->DrawType == 1)) {
        return;
    }
    surface = this->DrawSurface;
    if ((surface != 0) && (this->DrawDc != 0)) {
        ((ReleaseDcFn)surface->vftable[0x68 / 4])(surface, this->DrawDc);
        this->DrawDc = 0;
    }
}
