// VA: 00444270 TDrawArea::Lock (129 B)
// MATCHED: express the DirectDraw Lock flag as two duplicated call expressions under
// `if (waitFlag) ... else ...`. VC5 then avoids saving EDI/setne and emits the original
// `push 0; test [esp+0Ch]; mov eax,[ecx]; push 1/0; ... call [eax+64h]` common-tail shape.
// A single conditional-argument expression (`waitFlag ? 1 : 0` / `waitFlag != 0`) instead
// makes VC5 materialize the boolean in EDX and save EDI.

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;   // +0x00
    char gap_04[0x04];
    unsigned char* Bits;       // +0x08
    char gap_0C[0x2C];
    void* DrawDc;              // +0x38
    void* DrawSurface;         // +0x3C
    // +0x40: DDSURFACEDESC
    char gap_40[0x24];
    void* lpSurface;           // +0x64
    char gap_68[0x4C];
    void* LastBits;            // +0xB4

    void __fastcall SetInfo();
    void __fastcall SetAccessOffsets();
    unsigned char* Lock(char* name, int waitFlag);
};

typedef int (__stdcall* LockFunc)(void* surface, void* rect, void* desc, int flags, void* hdc);

unsigned char* TDrawArea::Lock(char* name, int waitFlag)
{
    if (this->DrawSystem != 0) {
        if (this->DrawSystem->DrawType == 1)
            return this->Bits;
    }

    if (this->DrawSurface == 0)
        return 0;

    if (this->Bits != 0)
        return this->Bits;

    if (this->DrawDc != 0)
        return 0;

    int hr;
    if (waitFlag) {
        hr = ((LockFunc)(*(void***)this->DrawSurface)[0x64 / 4])(this->DrawSurface, 0, (char*)this + 0x40, 1, 0);
    }
    else {
        hr = ((LockFunc)(*(void***)this->DrawSurface)[0x64 / 4])(this->DrawSurface, 0, (char*)this + 0x40, 0, 0);
    }

    if (hr != 0)
        return 0;

    this->Bits = (unsigned char*)this->lpSurface;
    this->SetInfo();

    if (this->Bits != this->LastBits)
        this->SetAccessOffsets();

    return this->Bits;
}
