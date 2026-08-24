// VA: 0046E020 TPicture::Save
// Picture.cpp lines 112-123
//
// Attempt log:
// - Initial scratch modeled this as fwrite/palette/data-size fields; behavior and layout were wrong.
// - Tried natural named fields for OwnMemory/Width/Height/Orien/BitmapInfo/Bits; behavior was right but register/address
//   scheduling drifted (best: positional diff 42, edit diff 13).
// - SpruceGlow MATCH: keep the real TPicture member offsets visible via raw offset accesses. This makes VC5 preserve
//   Width in EBX and Height in EBP as address temporaries, matching the original rge_write/check/AlignedWidth sequence.
// Result: MATCH locally with `python tools/check_function.py --va 0046E020`.

extern "C" void rge_write(int fd, void* buf, int len);

#ifndef PICTURE_CONTEXT_H
class TPicture {
public:
    char gap_00[0x20];

    long AlignedWidth();
    void Save(int fd);
};
#endif

void TPicture::Save(int fd) {
    rge_write(fd, (char*)this + 0x10, 4);     // OwnMemory
    rge_write(fd, (char*)this + 0x14, 4);     // Width
    rge_write(fd, (char*)this + 0x18, 4);     // Height
    rge_write(fd, (char*)this + 0x1C, 2);     // Orien

    if (*(int*)((char*)this + 0x14) > 0 && *(int*)((char*)this + 0x18) > 0) {
        rge_write(fd, *(void**)((char*)this + 0x04), 0x428); // BitmapInfo
        rge_write(fd, *(void**)((char*)this + 0x08), this->AlignedWidth() * *(int*)((char*)this + 0x18)); // Bits
    }
}
