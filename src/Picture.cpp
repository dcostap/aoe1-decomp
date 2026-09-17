
#include "../include/Picture.h"
#include "../include/Shape.h"
#include "../include/Res_file.h"
#include "../include/Dib.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>

extern void __cdecl rge_read(int handle, void* data, int size);
extern unsigned long __cdecl debug_timeGetTime(char* source_name, int source_line);
extern void __cdecl rge_write(int handle, void* data, int size);

TPicture::TPicture(char* FileName, long res_id, int UseTrans,
    void* MapToPal, int ZeroIsTrans) {
    this->Dib = 0;
    this->BitmapInfo = 0;
    this->Bits = 0;
    this->TransInfo = 0;
    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
    this->Load(FileName, res_id, UseTrans, MapToPal, ZeroIsTrans);
}

TPicture::TPicture(int infile, int UseTrans) {
    this->Dib = 0;
    this->BitmapInfo = 0;
    this->Bits = 0;
    this->TransInfo = 0;
    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;

    rge_read(infile, &this->OwnMemory, 4);
    rge_read(infile, &this->Width, 4);
    rge_read(infile, &this->Height, 4);
    rge_read(infile, &this->Orien, 2);

    if (this->OwnMemory != 0) {
        this->OwnMemory = 2;
    }

    if (this->Width > 0 && this->Height > 0) {
        void* dib = calloc(this->AlignedWidth() * this->Height + 1064, 1);
        this->Dib = (tagBITMAPINFOHEADER*)dib;
        rge_read(infile, this->Dib, this->AlignedWidth() * this->Height + 1064);
        this->BitmapInfo = (BITMAPINFO256*)this->Dib;
        this->Bits = (unsigned char*)this->Dib + 0x428;
    } else {
        this->Dib = 0;
        this->BitmapInfo = 0;
        this->Bits = 0;
    }

    this->TransInfo = 0;

    if (UseTrans != 0 && this->Dib != 0) {
        TRANSINFO* trans_info = (TRANSINFO*)malloc(24);
        this->TransInfo = trans_info;
        if (trans_info != 0) {
            if (((BITMAPINFO256*)this->Dib)->bmiHeader.biCompression == 3) {
                unsigned char* transparency_bits =
                    (unsigned char*)this->Dib +
                    ((BITMAPINFO256*)this->Dib)->bmiHeader.biSize + 12;
                DibCheckTrans((BITMAPINFO256*)this->Dib, trans_info, transparency_bits);
            } else {
                unsigned char* transparency_bits =
                    (unsigned char*)this->Dib +
                    ((BITMAPINFO256*)this->Dib)->bmiHeader.biSize +
                    ((BITMAPINFO256*)this->Dib)->bmiHeader.biClrUsed * 4;
                DibCheckTrans((BITMAPINFO256*)this->Dib, trans_info, transparency_bits);
            }
        } else {
            DibFree(this->Dib);
            this->Dib = 0;
            this->BitmapInfo = 0;
            this->OwnMemory = 0;
            this->Width = 0;
            this->Height = 0;
            this->Orien = 1;
        }
    }
}

TPicture::TPicture() {
    this->Dib = 0;
    this->BitmapInfo = 0;
    this->Bits = 0;
    this->TransInfo = 0;
    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
}

TPicture::~TPicture() {
    if (this->OwnMemory == 0) {
        return;
    }

    if (this->TransInfo != 0) {
        if (this->TransInfo->LineInfo != 0 && this->TransInfo->AnyTrans != 0) {
            free(this->TransInfo->LineInfo);
        }
        free(this->TransInfo);
    }

    if (this->Dib != 0) {
        if (this->OwnMemory == 2) {
            free(this->Dib);
            return;
        }
        DibFree(this->Dib);
    }
}

void TPicture::Save(int outfile) {
    rge_write(outfile, &this->OwnMemory, 4);
    rge_write(outfile, &this->Width, 4);
    rge_write(outfile, &this->Height, 4);
    rge_write(outfile, &this->Orien, 2);

    if (this->Width > 0 && this->Height > 0) {
        rge_write(outfile, this->BitmapInfo, 1064);
        rge_write(outfile, this->Bits, this->AlignedWidth() * this->Height);
    }
}

void TPicture::Load(char* FileName, long res_id, int UseTrans,
    void* MapToPal, int ZeroIsTrans) {
    BITMAPINFO256* bitmap;
    TRANSINFO* info;
    char temp_file_name[260];
    FILE* temp_file;
    int height;

    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Picture.cpp", 127);
    this->TransInfo = 0;
    this->OwnMemory = 1;

    if (shape_file_first != 0) {
        this->Dib = DibOpenFile(FileName);
    }

    if (this->Dib == 0 && res_id != -1) {
        if (RESFILE_Extract_to_File(RES_TYPE_BINARY, res_id, temp_file_name, temp_file) != 0) {
            fclose(temp_file);
            this->Dib = DibOpenFile(temp_file_name);
            _unlink(temp_file_name);
        }
    }

    if (shape_file_first == 0 && this->Dib == 0) {
        this->Dib = DibOpenFile(FileName);
    }

    bitmap = (BITMAPINFO256*)this->Dib;
    if (bitmap != 0) {
        this->BitmapInfo = bitmap;
        unsigned char* bits;
        if (((BITMAPINFO256*)this->Dib)->bmiHeader.biCompression == 3) {
            bits = (unsigned char*)this->Dib +
                ((BITMAPINFO256*)this->Dib)->bmiHeader.biSize + 0xc;
        } else {
            bits = (unsigned char*)this->Dib +
                ((BITMAPINFO256*)this->Dib)->bmiHeader.biSize +
                ((BITMAPINFO256*)this->Dib)->bmiHeader.biClrUsed * 4;
        }
        this->Bits = bits;
        this->Width = bitmap->bmiHeader.biWidth;
        height = bitmap->bmiHeader.biHeight;
        this->Height = height;
        if (height < 0) {
            this->Orien = 1;
            this->Height = -height;
        } else {
            this->Orien = -1;
        }

        if (MapToPal != 0) {
            DibMapToPalette((tagBITMAPINFOHEADER*)bitmap, MapToPal, UseTrans, ZeroIsTrans);
        }
        if (UseTrans == 0) {
            return;
        }

        info = (TRANSINFO*)malloc(24);
        this->TransInfo = info;
        if (info != 0) {
            bitmap = (BITMAPINFO256*)this->Dib;
            unsigned char* transparency_bits;
            if (((BITMAPINFO256*)this->Dib)->bmiHeader.biCompression == 3) {
                transparency_bits = (unsigned char*)this->Dib +
                    ((BITMAPINFO256*)this->Dib)->bmiHeader.biSize + 0xc;
            } else {
                transparency_bits = (unsigned char*)this->Dib +
                    ((BITMAPINFO256*)this->Dib)->bmiHeader.biSize +
                    ((BITMAPINFO256*)this->Dib)->bmiHeader.biClrUsed * 4;
            }
            DibCheckTrans((BITMAPINFO256*)this->Dib, info, transparency_bits);
            return;
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

void TPicture::Init(BITMAPINFO256* FromInfo, unsigned char* FromBits,
    TRANSINFO* FromTrans) {
    int height;

    this->Dib = &FromInfo->bmiHeader;
    this->BitmapInfo = FromInfo;
    this->Bits = FromBits;
    this->TransInfo = FromTrans;
    this->OwnMemory = 0;
    this->Width = FromInfo->bmiHeader.biWidth;
    height = FromInfo->bmiHeader.biHeight;
    this->Height = height;
    if (height < 0) {
        this->Orien = 1;
        this->Height = -height;
        return;
    }
    this->Orien = -1;
}

long TPicture::AlignedWidth() {
    return (this->Width + 3) & ~3;
}

void TPicture::Draw(TDrawArea* DrawArea, long DestX, long DestY, int Mirror,
    int Flip) {
    if (this->TransInfo != 0) {
        TransDibBlt(DrawArea->BitmapInfo, DrawArea->Bits, &DrawArea->ClipRect, DestX, DestY, this->Width, this->Height,
                    this->BitmapInfo, this->Bits, this->TransInfo, 0, 0, this->Width, this->Height, 1, Mirror, Flip, 0);
    } else {
        DibBlt(DrawArea->BitmapInfo, DrawArea->Bits, &DrawArea->ClipRect,
               DestX, DestY, this->Width, this->Height, this->BitmapInfo,
               this->Bits, 0, 0, this->Width, this->Height, 1, Mirror, Flip);
    }
}

long TPicture::Tile(TDrawArea* DrawArea, long DestX, long DestY,
    long DestWid, long DestHgt, long BlockWid, long BlockHgt, long SrcX,
    long SrcY, long SrcWid, long SrcHgt) {
    return TileDibBlt(DrawArea->BitmapInfo, DrawArea->Bits, &DrawArea->ClipRect, DestX, DestY, DestWid, DestHgt, BlockWid,
                      BlockHgt, this->BitmapInfo, this->Bits, this->TransInfo, SrcX, SrcY, SrcWid, SrcHgt, (this->TransInfo != 0), 0, 0);
}

unsigned char TPicture::GetPixel(long x, long y, int Mirror, int Flip) {
    char orientation = (char)this->Orien;
    if (Flip != 0) {
        orientation = (orientation != 1) ? 1 : -1;
    }

    if (x <= 0 || x >= this->Width || y < 0 || y >= this->Height) {
        return 0;
    }

    if (Mirror != 0) {
        if (orientation == 1) {
            unsigned char* row = this->Bits + this->AlignedWidth() * y;
            return *(row - x + this->Width - 1);
        }
        unsigned char* row = this->Bits +
                             this->AlignedWidth() * (this->Height - y - 1);
        return *(row - x + this->Width - 1);
    }

    if (orientation == 1) {
        unsigned char* row = this->Bits + this->AlignedWidth() * y;
        return row[x];
    }
    unsigned char* row = this->Bits +
                         this->AlignedWidth() * (this->Height - y - 1);
    return row[x];
}
