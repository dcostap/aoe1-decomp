// VA: 0046DE30 TPicture::TPicture(int file_handle, int param_2)
// Picture.cpp lines 25-76

// attempt 3: proper file-read / bitmap-allocation constructor
// ret 8, takes 2 params (file handle + transinfo flag)
// 366/366 exact size, 14 diff bytes
// Remaining: push order for calloc (1 vs dib_size first) + extra mov ecx,esi before malloc
// Both are VC5 optimizer scheduling artifacts
// Left in scratch.

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

void __cdecl rge_read(int file_handle, void* buf, int size);
void* __cdecl calloc(int count, int size);
void* __cdecl malloc(int size);
void __cdecl DibFree(void* dib);

extern "C" int __fastcall AlignedWidth(TPicture* pic);
void __cdecl DibCheckTrans(void* dib, TRANSINFO* ti, unsigned char* pt);

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
        int count = 1;
        int dib_size = AlignedWidth(this) * Height + 0x428;
        Dib = calloc(count, dib_size);
        dib_size = AlignedWidth(this) * Height + 0x428;
        rge_read(file_handle, Dib, dib_size);
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
            void* ecx_val = Dib;
            int bpp_test = *(int*)((char*)ecx_val + 0x10);
            if (bpp_test == 3) {
                unsigned char* pt = (unsigned char*)ecx_val + *(int*)ecx_val + 12;
                DibCheckTrans(ecx_val, ti, pt);
            } else {
                unsigned char* pt = (unsigned char*)ecx_val + *(int*)ecx_val + *(int*)((char*)ecx_val + 0x20) * 4;
                DibCheckTrans(ecx_val, ti, pt);
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
