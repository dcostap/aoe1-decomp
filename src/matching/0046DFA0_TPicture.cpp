class TPicture {
public:
    void* Dib;
    void* BitmapInfo;
    unsigned char* Bits;
    void* TransInfo;
    int OwnMemory;
    int Width;
    int Height;
    short Orien;

    TPicture();
};

TPicture::TPicture() {
    Dib = 0;
    BitmapInfo = 0;
    Bits = 0;
    TransInfo = 0;
    OwnMemory = 0;
    Width = 0;
    Height = 0;
    Orien = 1;
}
