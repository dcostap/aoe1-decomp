#ifndef PICTURE_CONTEXT_H
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

    TPicture(char* param_1, long param_2, int param_3, void* param_4, int param_5);
    void Load(char* param_1, long param_2, int param_3, void* param_4, int param_5);
};
#endif

TPicture::TPicture(char* param_1, long param_2, int param_3, void* param_4, int param_5) {
    this->Dib = 0;
    this->BitmapInfo = 0;
    this->Bits = 0;
    this->TransInfo = 0;
    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
    this->Load(param_1, param_2, param_3, param_4, param_5);
}
