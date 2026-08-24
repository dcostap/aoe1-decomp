#ifndef PICTURE_CONTEXT_H
class TPicture {
public:
    char gap_0[0x14];
    int width;
    int AlignedWidth();
};
#endif

int TPicture::AlignedWidth() {
#ifdef PICTURE_CONTEXT_H
    return (this->Width + 3) & ~3;
#else
    return (this->width + 3) & ~3;
#endif
}
