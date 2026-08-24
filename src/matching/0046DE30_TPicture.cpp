// VA: 0046DE30 TPicture::TPicture(int file_handle, int param_2)
// Picture.cpp lines 25-76

// attempt 7: fix calloc arg order — original is calloc(dib_size, 1) not calloc(1, dib_size)
// Module note: the standalone owner remains exact. In the authentic Picture.cpp
// wrapper, the complete TPicture method surface changes four bytes in the late
// non-compression transparency arm. Do not force this with register steering.

#ifndef PICTURE_CONTEXT_H
class TRANSINFO;
class TPicture {
public:
    void* Dib;              // +0x00
    void* BitmapInfo;       // +0x04
    unsigned char* Bits;    // +0x08
    TRANSINFO* TransInfo;   // +0x0C
    int OwnMemory;          // +0x10
    int Width;              // +0x14
    int Height;             // +0x18
    short Orien;            // +0x1C

    TPicture(int file_handle, int param_2);
    ~TPicture();
};
#endif

#ifndef PICTURE_CONTEXT_H
void __cdecl rge_read(int file_handle, void* buf, int size);
void* __cdecl calloc(int count, int size);
void* __cdecl malloc(int size);
void __cdecl DibFree(void* dib);
#endif

#ifndef PICTURE_CONTEXT_H
extern "C" int __fastcall AlignedWidth(TPicture* pic);
#endif
#ifndef PICTURE_CONTEXT_H
void __cdecl DibCheckTrans(void* dib, TRANSINFO* ti, unsigned char* pt);
#endif

TPicture::TPicture(int file_handle, int param_2) {
    Dib = 0;
    BitmapInfo = 0;
    Bits = 0;
    TransInfo = 0;
    OwnMemory = 0;
    Width = 0;
    Height = 0;
    Orien = 1;
    
    rge_read(file_handle, &OwnMemory, 4);
    rge_read(file_handle, &Width, 4);
    rge_read(file_handle, &Height, 4);
    rge_read(file_handle, &Orien, 2);
    
    if (OwnMemory != 0) {
        OwnMemory = 2;
    }
    
    if (Width > 0 && Height > 0) {
        void* dib = calloc(
#ifdef PICTURE_CONTEXT_H
            this->AlignedWidth()
#else
            AlignedWidth(this)
#endif
            * Height + 0x428, 1);
#ifdef PICTURE_CONTEXT_H
        Dib = (tagBITMAPINFOHEADER*)dib;
#else
        Dib = dib;
#endif
        rge_read(file_handle, Dib,
#ifdef PICTURE_CONTEXT_H
            this->AlignedWidth()
#else
            AlignedWidth(this)
#endif
            * Height + 0x428);
#ifdef PICTURE_CONTEXT_H
        BitmapInfo = (BITMAPINFO256*)Dib;
#else
        BitmapInfo = Dib;
#endif
        Bits = (unsigned char*)Dib + 0x428;
    } else {
        Dib = 0;
        BitmapInfo = 0;
        Bits = 0;
    }
    
    TransInfo = 0;
    
    if (param_2 != 0 && Dib != 0) {
        TRANSINFO* ti = (TRANSINFO*)malloc(0x18);
        TransInfo = ti;
        if (ti != 0) {
            void* ecx_val = Dib;
            int bpp_test = *(int*)((char*)ecx_val + 0x10);
            if (bpp_test == 3) {
                unsigned char* pt = (unsigned char*)ecx_val + *(int*)ecx_val + 12;
#ifdef PICTURE_CONTEXT_H
                DibCheckTrans((BITMAPINFO256*)ecx_val, ti, pt);
#else
                DibCheckTrans(ecx_val, ti, pt);
#endif
            } else {
                unsigned char* pt = (unsigned char*)ecx_val + *(int*)ecx_val + *(int*)((char*)ecx_val + 0x20) * 4;
#ifdef PICTURE_CONTEXT_H
                DibCheckTrans((BITMAPINFO256*)ecx_val, ti, pt);
#else
                DibCheckTrans(ecx_val, ti, pt);
#endif
            }
        } else {
            DibFree(Dib);
            Dib = 0;
            BitmapInfo = 0;
            OwnMemory = 0;
            Width = 0;
            Height = 0;
            Orien = 1;
        }
    }
}
