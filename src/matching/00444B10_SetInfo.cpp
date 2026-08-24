#ifndef DRAWAREA_CANONICAL_TU
struct BitmapInfoHeader {
    int unused0;
    int biWidth;
};

struct BitmapInfo {
    BitmapInfoHeader bmiHeader;
};

class TDrawArea {
public:
    char gap_00[0x0C];
    BitmapInfo* BitmapInfo;
    char gap_10[0x10];
    int Pitch;
    char gap_24[0x2C];
    int field_50;
    char gap_54[0x54];
    int caps;
    char gap_AC[0x3C];
    int UsingVidMem;

    void SetInfo(void);
};
#endif

void TDrawArea::SetInfo(void) {
    this->Pitch = this->SurfaceDesc.lPitch;
    this->BitmapInfo->bmiHeader.biWidth = this->SurfaceDesc.lPitch;
    if ((this->SurfaceDesc.ddsCaps.dwCaps & 0x800) != 0) {
        this->UsingVidMem = 0;
        return;
    }
    this->UsingVidMem = 1;
}
