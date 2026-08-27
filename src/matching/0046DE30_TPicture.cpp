// VA: 0046DE30 TPicture::TPicture(int file_handle, int param_2)
// Picture.cpp lines 25-76

#include "../../include/picture_context.h"

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
        void* dib = calloc(this->AlignedWidth() * Height + 0x428, 1);
        Dib = dib;
        rge_read(file_handle, Dib,
            this->AlignedWidth() * Height + 0x428);
        BitmapInfo = Dib;
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
            if (((BITMAPINFO256*)Dib)->bmiHeader.biCompression == 3) {
                unsigned char* pt = (unsigned char*)Dib
                    + ((BITMAPINFO256*)Dib)->bmiHeader.biSize + 12;
                DibCheckTrans((BITMAPINFO256*)Dib, ti, pt);
            } else {
                unsigned char* pt = (unsigned char*)Dib
                    + ((BITMAPINFO256*)Dib)->bmiHeader.biSize
                    + ((BITMAPINFO256*)Dib)->bmiHeader.biClrUsed * 4;
                DibCheckTrans((BITMAPINFO256*)Dib, ti, pt);
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
