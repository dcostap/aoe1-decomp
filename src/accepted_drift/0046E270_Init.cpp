// ACCEPTED_DRIFT: startup register/load ordering differs only for argument moves; the same fields are initialized before identical sign handling and return cleanup.
// tried direct field stores with height read from this->Height; mismatch stayed at the first mov pair
// tried decompiler-style iVar1 height temp and &info->bmiHeader; same first-byte mismatch, compiler still loads bits into eax first
// leaving in scratch: behavior is right, remaining gap is register/load ordering at function entry

#ifndef PICTURE_CONTEXT_H
struct BITMAPINFOHEADER {
    unsigned int biSize;
    int biWidth;
    int biHeight;
};

struct BITMAPINFO256 {
    BITMAPINFOHEADER bmiHeader;
};

struct TRANSINFO;

class TPicture {
public:
    void* Dib;
    void* BitmapInfo;
    unsigned char* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    int Width;
    int Height;
    short Orien;

    void Init(BITMAPINFO256* info, unsigned char* bits, TRANSINFO* trans);
};
#endif

void TPicture::Init(BITMAPINFO256* info, unsigned char* bits, TRANSINFO* trans) {
    int iVar1;

    this->Bits = bits;
    this->Dib = &info->bmiHeader;
    this->BitmapInfo = info;
    this->TransInfo = trans;
    this->OwnMemory = 0;
    this->Width = info->bmiHeader.biWidth;
    iVar1 = info->bmiHeader.biHeight;
    this->Height = iVar1;
    if (iVar1 < 0) {
        this->Orien = 1;
        this->Height = -iVar1;
        return;
    }
    this->Orien = -1;
}
