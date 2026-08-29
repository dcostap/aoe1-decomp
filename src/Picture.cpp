
#include "../include/Picture.h"
#include "../include/Shape.h"
#include "../include/Res_file.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>

extern void __cdecl rge_read(int file_handle, void* buffer, int size);
extern unsigned long __cdecl debug_timeGetTime(const char* file, int line);
extern void __cdecl rge_write(int fd, void* buffer, int size);
tagBITMAPINFOHEADER* __cdecl DibOpenFile(char* name);
void __cdecl DibMapToPalette(tagBITMAPINFOHEADER* dib, void* palette,
    int palette_id, int palette_flags);
void __cdecl DibFree(tagBITMAPINFOHEADER* dib);
int __cdecl DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info,
    unsigned char* bits);
extern void __cdecl TransDibBlt(void* dst_info, void* dst_bits, void* clip,
    long x, long y, int width, int height, void* src_info, void* src_bits,
    void* trans_info, int sx, int sy, int sw, int sh, int flag, int dst_x,
    int dst_y, int zero);
extern void __cdecl DibBlt(void* dst_info, void* dst_bits, void* clip,
    long x, long y, int width, int height, void* src_info, void* src_bits,
    int sx, int sy, int sw, int sh, int flag, int dst_x, int dst_y);
extern long __cdecl TileDibBlt(BITMAPINFO256* bitmap_info,
    unsigned char* bits, void* clip_rect, long param_2, long param_3,
    long param_4, long param_5, long param_6, long param_7,
    BITMAPINFO256* picture_info, unsigned char* picture_bits,
    void* trans_info, long param_8, long param_9, long param_10,
    long param_11, int has_trans, int zero_1, int zero_2);

TPicture::TPicture(char* file_name, long resource_id, int palette_id,
    void* palette, int palette_flags) {
    this->Dib = 0;
    this->BitmapInfo = 0;
    this->Bits = 0;
    this->TransInfo = 0;
    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
    this->Load(file_name, resource_id, palette_id, palette, palette_flags);
}

TPicture::TPicture(int file_handle, int param_2) {
    this->Dib = 0;
    this->BitmapInfo = 0;
    this->Bits = 0;
    this->TransInfo = 0;
    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;

    rge_read(file_handle, &this->OwnMemory, 4);
    rge_read(file_handle, &this->Width, 4);
    rge_read(file_handle, &this->Height, 4);
    rge_read(file_handle, &this->Orien, 2);

    if (this->OwnMemory != 0) {
        this->OwnMemory = 2;
    }

    if (this->Width > 0 && this->Height > 0) {
        void* dib = calloc(this->AlignedWidth() * this->Height + 0x428, 1);
        this->Dib = (tagBITMAPINFOHEADER*)dib;
        rge_read(file_handle, this->Dib,
            this->AlignedWidth() * this->Height + 0x428);
        this->BitmapInfo = (BITMAPINFO256*)this->Dib;
        this->Bits = (unsigned char*)this->Dib + 0x428;
    } else {
        this->Dib = 0;
        this->BitmapInfo = 0;
        this->Bits = 0;
    }

    this->TransInfo = 0;

    if (param_2 != 0 && this->Dib != 0) {
        TRANSINFO* trans_info = (TRANSINFO*)malloc(0x18);
        this->TransInfo = trans_info;
        if (trans_info != 0) {
            if (this->BitmapInfo->bmiHeader.biCompression == 3) {
                unsigned char* transparency_bits =
                    (unsigned char*)this->Dib +
                    this->BitmapInfo->bmiHeader.biSize + 12;
                DibCheckTrans(this->BitmapInfo, trans_info, transparency_bits);
            } else {
                unsigned char* transparency_bits =
                    (unsigned char*)this->Dib +
                    this->BitmapInfo->bmiHeader.biSize +
                    this->BitmapInfo->bmiHeader.biClrUsed * 4;
                DibCheckTrans(this->BitmapInfo, trans_info, transparency_bits);
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

void TPicture::Save(int fd) {
    rge_write(fd, &this->OwnMemory, 4);
    rge_write(fd, &this->Width, 4);
    rge_write(fd, &this->Height, 4);
    rge_write(fd, &this->Orien, 2);

    if (this->Width > 0 && this->Height > 0) {
        rge_write(fd, this->BitmapInfo, 0x428);
        rge_write(fd, this->Bits,
            this->AlignedWidth() * this->Height);
    }
}

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
            bits = (unsigned char*)bitmap + bitmap->bmiHeader.biSize + 0xc;
        } else {
            bits = (unsigned char*)bitmap + bitmap->bmiHeader.biSize +
                bitmap->bmiHeader.biClrUsed * 4;
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
            unsigned char* transparency_bits;
            if (bitmap->bmiHeader.biCompression == 3) {
                transparency_bits = (unsigned char*)bitmap +
                    bitmap->bmiHeader.biSize + 0xc;
            } else {
                transparency_bits = (unsigned char*)bitmap +
                    bitmap->bmiHeader.biSize +
                    bitmap->bmiHeader.biClrUsed * 4;
            }
            DibCheckTrans(bitmap, info, transparency_bits);
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

void TPicture::Init(BITMAPINFO256* info, unsigned char* bits,
    TRANSINFO* trans) {
    int height;

    this->Bits = bits;
    this->Dib = &info->bmiHeader;
    this->BitmapInfo = info;
    this->TransInfo = trans;
    this->OwnMemory = 0;
    this->Width = info->bmiHeader.biWidth;
    height = info->bmiHeader.biHeight;
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

void TPicture::Draw(TDrawArea* draw_area, long x, long y, int dst_x,
    int dst_y) {
    if (this->TransInfo != 0) {
        TransDibBlt(draw_area->BitmapInfo, draw_area->Bits,
            &draw_area->ClipRect, x, y, this->Width, this->Height,
            this->BitmapInfo, this->Bits, this->TransInfo, 0, 0,
            this->Width, this->Height, 1, dst_x, dst_y, 0);
    } else {
        DibBlt(draw_area->BitmapInfo, draw_area->Bits, &draw_area->ClipRect,
            x, y, this->Width, this->Height, this->BitmapInfo, this->Bits,
            0, 0, this->Width, this->Height, 1, dst_x, dst_y);
    }
}

long TPicture::Tile(TDrawArea* draw_area, long param_2, long param_3,
    long param_4, long param_5, long param_6, long param_7, long param_8,
    long param_9, long param_10, long param_11) {
    return TileDibBlt(draw_area->BitmapInfo, draw_area->Bits,
        &draw_area->ClipRect, param_2, param_3, param_4, param_5, param_6,
        param_7, this->BitmapInfo, this->Bits, this->TransInfo, param_8,
        param_9, param_10, param_11, (this->TransInfo != 0), 0, 0);
}

unsigned char TPicture::GetPixel(long x, long y, int param_3, int param_4) {
    char orientation = (char)this->Orien;
    if (param_4 != 0) {
        orientation = (orientation != 1) ? 1 : -1;
    }

    if (x <= 0 || x >= this->Width || y < 0 || y >= this->Height) {
        return 0;
    }

    if (param_3 != 0) {
        if (orientation == 1) {
            return this->Bits[this->AlignedWidth() * y - x + this->Width - 1];
        }
        return this->Bits[this->AlignedWidth() * (this->Height - y - 1) - x +
                          this->Width - 1];
    }

    if (orientation == 1) {
        return this->Bits[this->AlignedWidth() * y + x];
    }
    return this->Bits[this->AlignedWidth() * (this->Height - y - 1) + x];
}
