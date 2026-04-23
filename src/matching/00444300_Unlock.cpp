class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

struct IDirectDrawSurface {
    void** vftable;
};

typedef void (__stdcall *UnlockFn)(IDirectDrawSurface*, void*);

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x04];
    void* Bits;
    char gap_0C[0x30];
    IDirectDrawSurface* DrawSurface;

    void Unlock(char* param);
};

void TDrawArea::Unlock(char* param) {
    if ((this->DrawSystem == 0) || (this->DrawSystem->DrawType != 1)) {
        IDirectDrawSurface* surface = this->DrawSurface;
        if (surface != 0) {
            void* bits = this->Bits;
            if (bits != 0) {
                ((UnlockFn)surface->vftable[0x80 / 4])(surface, bits);
                this->Bits = 0;
            }
        }
    }
}
