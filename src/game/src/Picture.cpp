#include "../include/TPicture.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/TRANSINFO.h"
#include "../include/Res_file.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>

static void picture_zero(TPicture* this_) {
    this_->Dib = (tagBITMAPINFOHEADER*)0x0;
    this_->BitmapInfo = (BITMAPINFO256*)0x0;
    this_->Bits = (uchar*)0x0;
    this_->TransInfo = (TRANSINFO*)0x0;
    this_->OwnMemory = 0;
    this_->Width = 0;
    this_->Height = 0;
    this_->Orien = 1;
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046DDE0
TPicture::TPicture(char* param_1, long param_2, int param_3, void* param_4, int param_5) {
    picture_zero(this);
    this->Load(param_1, param_2, param_3, param_4, param_5);
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046DE30
TPicture::TPicture(int handle, int use_trans) {
    picture_zero(this);

    rge_read(handle, &this->OwnMemory, 4);
    rge_read(handle, &this->Width, 4);
    rge_read(handle, &this->Height, 4);
    rge_read(handle, &this->Orien, 2);

    if (this->OwnMemory != 0) {
        this->OwnMemory = 2;
    }

    if ((this->Width < 1) || (this->Height < 1)) {
        this->Dib = (tagBITMAPINFOHEADER*)0x0;
        this->BitmapInfo = (BITMAPINFO256*)0x0;
        this->Bits = (uchar*)0x0;
    } else {
        long aligned = this->AlignedWidth();
        this->Dib = (tagBITMAPINFOHEADER*)calloc(aligned * this->Height + 0x428, 1);
        rge_read(handle, this->Dib, (int)(aligned * this->Height + 0x428));
        this->BitmapInfo = (BITMAPINFO256*)this->Dib;
        this->Bits = (uchar*)(this->BitmapInfo + 1);
    }

    this->TransInfo = (TRANSINFO*)0x0;
    if ((use_trans != 0) && (this->Dib != (tagBITMAPINFOHEADER*)0x0)) {
        this->TransInfo = (TRANSINFO*)malloc(0x18);
        if (this->TransInfo != (TRANSINFO*)0x0) {
            BITMAPINFO256* bmi = (BITMAPINFO256*)this->Dib;
            if ((bmi->bmiHeader).biCompression == 3) {
                DibCheckTrans(bmi, this->TransInfo, (uchar*)((char*)(bmi->bmiColors - 7) + (bmi->bmiHeader).biSize));
                return;
            }
            DibCheckTrans(bmi, this->TransInfo, (uchar*)(&bmi->bmiColors[(bmi->bmiHeader).biClrUsed - 10].rgbBlue) + (bmi->bmiHeader).biSize);
            return;
        }

        DibFree(this->Dib);
        this->Dib = (tagBITMAPINFOHEADER*)0x0;
        this->BitmapInfo = (BITMAPINFO256*)0x0;
        this->OwnMemory = 0;
        this->Width = 0;
        this->Height = 0;
        this->Orien = 1;
    }
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046DFA0
TPicture::TPicture() {
    picture_zero(this);
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046DFC0
TPicture::~TPicture() {
    if (this->OwnMemory != 0) {
        TRANSINFO* trans = this->TransInfo;
        if (trans != (TRANSINFO*)0x0) {
            if ((trans->LineInfo != (LINEINFO*)0x0) && (trans->AnyTrans != 0)) {
                free(trans->LineInfo);
            }
            free(this->TransInfo);
        }

        if (this->Dib != (tagBITMAPINFOHEADER*)0x0) {
            if (this->OwnMemory == 2) {
                free(this->Dib);
                return;
            }
            DibFree(this->Dib);
        }
    }
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E020
void TPicture::Save(int param_1) {
    rge_write(param_1, &this->OwnMemory, 4);
    rge_write(param_1, &this->Width, 4);
    rge_write(param_1, &this->Height, 4);
    rge_write(param_1, &this->Orien, 2);

    if ((0 < this->Width) && (0 < this->Height)) {
        rge_write(param_1, this->BitmapInfo, 0x428);
        long aligned = this->AlignedWidth();
        rge_write(param_1, this->Bits, (int)(aligned * this->Height));
    }
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E0B0
void TPicture::Load(char* param_1, long param_2, int param_3, void* param_4, int param_5) {
    char temp_file_name[260];
    FILE* temp_file = (FILE*)0x0;

    (void)debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Picture.cpp", 0x7f);
    this->TransInfo = (TRANSINFO*)0x0;
    this->OwnMemory = 1;

    if (shape_file_first != '\0') {
        this->Dib = DibOpenFile(param_1);
    }

    if ((this->Dib == (tagBITMAPINFOHEADER*)0x0) && (param_2 != -1) &&
        (RESFILE_Extract_to_File(0x62696e61, (unsigned long)param_2, temp_file_name + 4, &temp_file) != 0)) {
        fclose(temp_file);
        this->Dib = DibOpenFile(temp_file_name + 4);
        _unlink(temp_file_name + 4);
    }

    if ((shape_file_first == '\0') && (this->Dib == (tagBITMAPINFOHEADER*)0x0)) {
        this->Dib = DibOpenFile(param_1);
    }

    BITMAPINFO256* bmi = (BITMAPINFO256*)this->Dib;
    if (bmi == (BITMAPINFO256*)0x0) {
        this->Dib = (tagBITMAPINFOHEADER*)0x0;
        this->BitmapInfo = (BITMAPINFO256*)0x0;
        this->Bits = (uchar*)0x0;
        this->TransInfo = (TRANSINFO*)0x0;
    } else {
        this->BitmapInfo = bmi;

        int bit_offset = 0;
        if ((bmi->bmiHeader).biCompression == 3) {
            bit_offset = (bmi->bmiHeader).biSize + 0xc;
        } else {
            bit_offset = (bmi->bmiHeader).biSize + (bmi->bmiHeader).biClrUsed * 4;
        }

        this->Bits = (uchar*)((char*)bmi + bit_offset);
        this->Width = (bmi->bmiHeader).biWidth;

        int bmp_h = (bmi->bmiHeader).biHeight;
        this->Height = bmp_h;
        if (bmp_h < 0) {
            this->Orien = 1;
            this->Height = -bmp_h;
        } else {
            this->Orien = -1;
        }

        if (param_4 != (void*)0x0) {
            DibMapToPalette((tagBITMAPINFOHEADER*)bmi, param_4, param_3, param_5);
        }

        if (param_3 == 0) {
            return;
        }

        this->TransInfo = (TRANSINFO*)malloc(0x18);
        if (this->TransInfo != (TRANSINFO*)0x0) {
            bmi = (BITMAPINFO256*)this->Dib;
            if ((bmi->bmiHeader).biCompression != 3) {
                DibCheckTrans(bmi, this->TransInfo,
                              (uchar*)(&bmi->bmiColors[(bmi->bmiHeader).biClrUsed - 10].rgbBlue) + (bmi->bmiHeader).biSize);
                return;
            }
            DibCheckTrans(bmi, this->TransInfo, (uchar*)((char*)(bmi->bmiColors - 7) + (bmi->bmiHeader).biSize));
            return;
        }

        DibFree(this->Dib);
        this->Dib = (tagBITMAPINFOHEADER*)0x0;
        this->BitmapInfo = (BITMAPINFO256*)0x0;
    }

    this->OwnMemory = 0;
    this->Width = 0;
    this->Height = 0;
    this->Orien = 1;
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E270
void TPicture::Init(BITMAPINFO256* param_1, uchar* param_2, TRANSINFO* param_3) {
    this->Bits = param_2;
    this->Dib = &param_1->bmiHeader;
    this->BitmapInfo = param_1;
    this->TransInfo = param_3;
    this->OwnMemory = 0;
    this->Width = (param_1->bmiHeader).biWidth;

    int bmp_h = (param_1->bmiHeader).biHeight;
    this->Height = bmp_h;
    if (bmp_h < 0) {
        this->Orien = 1;
        this->Height = -bmp_h;
        return;
    }
    this->Orien = -1;
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E2C0
long TPicture::AlignedWidth() {
    return (this->Width + 3U) & 0xfffffffc;
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E2D0
void TPicture::Draw(TDrawArea* param_1, long param_2, long param_3, int param_4, int param_5) {
    if (this->TransInfo != (TRANSINFO*)0x0) {
        TransDibBlt(param_1->BitmapInfo, param_1->Bits, &param_1->ClipRect, param_2, param_3, this->Width, this->Height, this->BitmapInfo, this->Bits,
                    this->TransInfo, 0, 0, this->Width, this->Height, 1, param_4, param_5, 0);
        return;
    }

    DibBlt(param_1->BitmapInfo, param_1->Bits, &param_1->ClipRect, param_2, param_3, this->Width, this->Height, this->BitmapInfo, this->Bits, 0, 0,
           this->Width, this->Height, 1, param_4, param_5);
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E370
long TPicture::Tile(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9,
                    long param_10, long param_11) {
    return TileDibBlt(param_1->BitmapInfo, param_1->Bits, &param_1->ClipRect, param_2, param_3, param_4, param_5, param_6, param_7, this->BitmapInfo,
                      this->Bits, this->TransInfo, param_8, param_9, param_10, param_11, (uint)(this->TransInfo != (TRANSINFO*)0x0), 0, 0);
}

// Fully verified. Source of truth: picture.cpp.decomp @ 0x0046E3E0
uchar TPicture::GetPixel(long param_1, long param_2, int param_3, int param_4) {
    char orient = (char)this->Orien;
    if (param_4 != 0) {
        orient = (char)((-(orient != '\x01') & 2U) - 1);
    }

    if ((((param_1 < 1) || (this->Width <= param_1)) || (param_2 < 0)) || (this->Height <= param_2)) {
        return '\0';
    }

    if (param_3 == 0) {
        if (orient == '\x01') {
            long aligned = this->AlignedWidth();
            return this->Bits[param_1 + aligned * param_2];
        }
        long aligned = this->AlignedWidth();
        return this->Bits[param_1 + aligned * ((this->Height - param_2) - 1)];
    }

    if (orient == '\x01') {
        long aligned = this->AlignedWidth();
        return this->Bits[this->Width + (aligned * param_2 - param_1) - 1];
    }

    long aligned = this->AlignedWidth();
    return this->Bits[this->Width + (aligned * ((this->Height - param_2) - 1) - param_1) - 1];
}
