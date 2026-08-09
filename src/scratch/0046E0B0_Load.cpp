// VA: 0046E0B0 TPicture::Load
// Picture.cpp lines 126-197
//
// Attempt log:
// - baseline typed reconstruction matched size/frame/calls but used the wrong
//   late DIB-null block shape (251 differing bytes).
// - inverted the positive DIB guard, inlined the bitmap base plus DIB offset,
//   and used the compression==3 arm first; this reached 5 differing bytes.
// - the remaining five bytes are only VC5 register/address encodings in the
//   two DibCheckTrans argument expressions; direct typed and constructor-donor
//   pointer spellings emitted the same 5-byte result.
// - a four-case focused variant lab (raw/header/base/shifted pointer forms)
//   preserved size/frame/call-set but collapsed to the same code group.
// - left in scratch: natural typed source, 5 differing bytes at the two
//   transparency scan address/register sequences.

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

struct tagBITMAPINFOHEADER {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
};

struct tagRGBQUAD {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct BITMAPINFO256 {
    tagBITMAPINFOHEADER bmiHeader;
    tagRGBQUAD bmiColors[256];
};

struct TRANSINFO;

extern unsigned char shape_file_first;
extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);
tagBITMAPINFOHEADER* __cdecl DibOpenFile(char* name);
int __cdecl RESFILE_Extract_to_File(unsigned long type, unsigned long id,
    char* name, FILE*& file);
void __cdecl DibMapToPalette(tagBITMAPINFOHEADER* dib, void* palette,
    int palette_id, int palette_flags);
void __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits);
void __cdecl DibFree(tagBITMAPINFOHEADER* dib);

class TPicture {
public:
    tagBITMAPINFOHEADER* Dib;
    BITMAPINFO256* BitmapInfo;
    unsigned char* Bits;
    TRANSINFO* TransInfo;
    int OwnMemory;
    long Width;
    long Height;
    short Orien;

    void Load(char* file_name, long resource_id, int palette_id,
        void* palette, int palette_flags);
};

void TPicture::Load(char* file_name, long resource_id, int palette_id,
    void* palette, int palette_flags) {
    BITMAPINFO256* bitmap;
    TRANSINFO* info;
    char temp_file_name[260];
    FILE* temp_file;

    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Picture.cpp", 0x7f);
    this->TransInfo = 0;
    this->OwnMemory = 1;

    if (shape_file_first != 0) {
        this->Dib = DibOpenFile(file_name);
    }

    if (this->Dib == 0 && resource_id != -1) {
        if (RESFILE_Extract_to_File(0x62696e61, resource_id,
            temp_file_name, temp_file) != 0) {
            fclose(temp_file);
            this->Dib = DibOpenFile(temp_file_name);
            _unlink(temp_file_name);
        }
    }

    if (shape_file_first == 0 && this->Dib == 0) {
        this->Dib = DibOpenFile(file_name);
    }

    bitmap = (BITMAPINFO256*)this->Dib;
    if (bitmap != 0) {
        this->BitmapInfo = bitmap;
        unsigned char* bits;
        if (bitmap->bmiHeader.biCompression == 3) {
            bits = (unsigned char*)bitmap +
                bitmap->bmiHeader.biSize + 0xc;
        } else {
            bits = (unsigned char*)bitmap +
                bitmap->bmiHeader.biSize + bitmap->bmiHeader.biClrUsed * 4;
        }
        this->Bits = bits;
        this->Width = bitmap->bmiHeader.biWidth;
        this->Height = bitmap->bmiHeader.biHeight;
        if (this->Height < 0) {
            this->Orien = 1;
            this->Height = -this->Height;
        } else {
            this->Orien = -1;
        }

        if (palette != 0) {
            DibMapToPalette((tagBITMAPINFOHEADER*)bitmap, palette,
                palette_id, palette_flags);
        }
        if (palette_id == 0) {
            return;
        }

        info = (TRANSINFO*)malloc(0x18);
        this->TransInfo = info;
        if (info != 0) {
            bitmap = (BITMAPINFO256*)this->Dib;
            if (bitmap->bmiHeader.biCompression == 3) {
                DibCheckTrans(bitmap, info,
                    (unsigned char*)bitmap + bitmap->bmiHeader.biSize + 0xc);
                return;
            } else {
                DibCheckTrans(bitmap, info,
                    (unsigned char*)bitmap + bitmap->bmiHeader.biSize +
                    bitmap->bmiHeader.biClrUsed * 4);
                return;
            }
        }

        DibFree(this->Dib);
        this->Dib = 0;
        this->BitmapInfo = 0;
    } else {
        this->Dib = 0;
        this->BitmapInfo = 0;
        this->Bits = 0;
        this->TransInfo = 0;
    }

    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
}
