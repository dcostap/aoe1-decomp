#include "../include/TPicture.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/TRANSINFO.h"
#include "../include/Res_file.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>

static void picture_reset(TPicture* pic) {
    pic->Dib = 0;
    pic->BitmapInfo = 0;
    pic->Bits = 0;
    pic->TransInfo = 0;
    pic->OwnMemory = 0;
    pic->Width = 0;
    pic->Height = 0;
    pic->Orien = 1;
}

static long picture_aligned_width(long width) {
    return (width + 3L) & ~3L;
}

long TPicture::AlignedWidth() {
    // Fully verified. Source of truth: picture.cpp.decomp (usage from diam_map.cpp.decomp @ 0x00436A10).
    return picture_aligned_width(this->Width);
}

static int picture_alloc_8bit(TPicture* pic, long width, long height) {
    if (!pic || width < 1 || height < 1) return 0;

    long stride = picture_aligned_width(width);
    long total_size = 0x428 + (stride * height);
    tagBITMAPINFOHEADER* dib = (tagBITMAPINFOHEADER*)calloc(1, (size_t)total_size);
    if (!dib) return 0;

    BITMAPINFO256* bmi = (BITMAPINFO256*)dib;
    bmi->bmiHeader.biSize = sizeof(tagBITMAPINFOHEADER);
    bmi->bmiHeader.biWidth = width;
    bmi->bmiHeader.biHeight = -height; // store top-down for simple drawing path
    bmi->bmiHeader.biPlanes = 1;
    bmi->bmiHeader.biBitCount = 8;
    bmi->bmiHeader.biCompression = BI_RGB;
    bmi->bmiHeader.biSizeImage = stride * height;
    bmi->bmiHeader.biClrUsed = 256;
    bmi->bmiHeader.biClrImportant = 256;

    for (int i = 0; i < 256; ++i) {
        bmi->bmiColors[i].rgbBlue = (unsigned char)i;
        bmi->bmiColors[i].rgbGreen = (unsigned char)i;
        bmi->bmiColors[i].rgbRed = (unsigned char)i;
        bmi->bmiColors[i].rgbReserved = 0;
    }

    pic->Dib = dib;
    pic->BitmapInfo = bmi;
    pic->Bits = ((unsigned char*)dib) + 0x428;
    pic->OwnMemory = 1;
    pic->Width = width;
    pic->Height = height;
    pic->Orien = 1;
    return 1;
}

static int picture_load_bmp_file(TPicture* pic, const char* filename) {
    if (!pic || !filename || filename[0] == '\0') return 0;

    int fd = _open(filename, _O_BINARY | _O_RDONLY);
    if (fd == -1) return 0;

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    memset(&bfh, 0, sizeof(bfh));
    memset(&bih, 0, sizeof(bih));

    if (_read(fd, &bfh, sizeof(bfh)) != sizeof(bfh) || bfh.bfType != 0x4D42) {
        _close(fd);
        return 0;
    }
    if (_read(fd, &bih, sizeof(bih)) != sizeof(bih)) {
        _close(fd);
        return 0;
    }

    if (bih.biWidth < 1 || bih.biHeight == 0 || bih.biPlanes != 1 || bih.biBitCount != 8 || bih.biCompression != BI_RGB) {
        _close(fd);
        return 0;
    }

    long width = bih.biWidth;
    long height = (bih.biHeight < 0) ? -bih.biHeight : bih.biHeight;
    int src_top_down = (bih.biHeight < 0) ? 1 : 0;

    int palette_count = (int)bih.biClrUsed;
    if (palette_count <= 0) palette_count = 256;
    if (palette_count > 256) palette_count = 256;

    if (!picture_alloc_8bit(pic, width, height)) {
        _close(fd);
        return 0;
    }

    long palette_offset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    if (_lseek(fd, palette_offset, SEEK_SET) == -1) {
        free(pic->Dib);
        picture_reset(pic);
        _close(fd);
        return 0;
    }
    if (_read(fd, pic->BitmapInfo->bmiColors, palette_count * (int)sizeof(RGBQUAD)) != palette_count * (int)sizeof(RGBQUAD)) {
        free(pic->Dib);
        picture_reset(pic);
        _close(fd);
        return 0;
    }

    long src_stride = (((width * 8L) + 31L) / 32L) * 4L;
    long dst_stride = picture_aligned_width(width);
    unsigned char* row = (unsigned char*)malloc((size_t)src_stride);
    if (!row) {
        free(pic->Dib);
        picture_reset(pic);
        _close(fd);
        return 0;
    }

    for (long y = 0; y < height; ++y) {
        long src_row = src_top_down ? y : (height - 1 - y);
        long row_offset = (long)bfh.bfOffBits + (src_row * src_stride);
        if (_lseek(fd, row_offset, SEEK_SET) == -1 || _read(fd, row, (unsigned int)src_stride) != (int)src_stride) {
            free(row);
            free(pic->Dib);
            picture_reset(pic);
            _close(fd);
            return 0;
        }
        memcpy(pic->Bits + (y * dst_stride), row, (size_t)width);
    }

    free(row);
    _close(fd);
    return 1;
}

static int picture_load_bmp_from_resource(TPicture* pic, long file_id) {
    if (!pic || file_id == -1) return 0;

    char temp_file_name[MAX_PATH];
    FILE* temp_file = 0;
    if (!RESFILE_Extract_to_File(0x62696e61, (unsigned long)file_id, temp_file_name, &temp_file)) {
        return 0;
    }

    if (temp_file) fclose(temp_file);
    int loaded = picture_load_bmp_file(pic, temp_file_name);
    _unlink(temp_file_name);
    return loaded;
}

TPicture::TPicture(char* filename, long file_id, int use_trans, void* memory, int own_memory) {
    (void)use_trans;
    (void)memory;
    (void)own_memory;

    picture_reset(this);
    if (picture_load_bmp_file(this, filename)) return;
    picture_load_bmp_from_resource(this, file_id);
}

TPicture::TPicture(int handle, int use_trans) {
    // Fully verified. Source of truth: picture.cpp.decomp @ 0x0046DE30
    (void)use_trans; // TransInfo is not currently reconstructed; not required for scenario load/save parity.

    picture_reset(this);

    rge_read(handle, &this->OwnMemory, 4);
    rge_read(handle, &this->Width, 4);
    rge_read(handle, &this->Height, 4);
    rge_read(handle, &this->Orien, 2);

    if (this->OwnMemory != 0) {
        this->OwnMemory = 2;
    }

    if (this->Width < 1 || this->Height < 1) {
        this->Dib = 0;
        this->BitmapInfo = 0;
        this->Bits = 0;
        return;
    }

    long aligned = picture_aligned_width(this->Width);
    long total_size = 0x428 + (aligned * this->Height);
    this->Dib = (tagBITMAPINFOHEADER*)calloc(1, (size_t)total_size);
    if (this->Dib == 0) {
        picture_reset(this);
        return;
    }

    rge_read(handle, this->Dib, (int)total_size);
    this->BitmapInfo = (BITMAPINFO256*)this->Dib;
    this->Bits = ((unsigned char*)this->Dib) + 0x428;
    this->TransInfo = 0;
}

TPicture::TPicture() {
    picture_reset(this);
}

TPicture::~TPicture() {
    if (this->TransInfo) {
        if (this->TransInfo->AnyTrans && this->TransInfo->LineInfo) {
            free(this->TransInfo->LineInfo);
        }
        free(this->TransInfo);
        this->TransInfo = 0;
    }

    if (this->OwnMemory != 0 && this->Dib != nullptr) {
        // Decomp distinguishes OwnMemory==2 vs other values; in this codebase DIB memory is heap-backed.
        if (this->OwnMemory == 2) {
            free(this->Dib);
        } else {
            free(this->Dib);
        }
    }

    picture_reset(this);
}

void TPicture::Save(int p1) {
    // Source of truth: picture.cpp.decomp @ 0x0046E020
    rge_write(p1, &this->OwnMemory, 4);
    rge_write(p1, &this->Width, 4);
    rge_write(p1, &this->Height, 4);
    rge_write(p1, &this->Orien, 2);

    if (this->Width > 0 && this->Height > 0 && this->BitmapInfo != nullptr && this->Bits != nullptr) {
        rge_write(p1, this->BitmapInfo, 0x428);
        long aligned = picture_aligned_width(this->Width);
        rge_write(p1, this->Bits, (int)(aligned * this->Height));
    }
}

void TPicture::Draw(TDrawArea* area, long x, long y, int p4, int p5) {
    (void)p4;
    (void)p5;

    if (!area || !area->Bits || !this->Bits || this->Width < 1 || this->Height < 1) return;

    int bytes_per_pixel = 1;
    if (area->Width > 0 && area->Pitch > 0) {
        bytes_per_pixel = area->Pitch / area->Width;
        if (bytes_per_pixel < 1) bytes_per_pixel = 1;
        if (bytes_per_pixel > 4) bytes_per_pixel = 4;
    }

    long clip_left = area->ClipRect.left;
    long clip_top = area->ClipRect.top;
    long clip_right = area->ClipRect.right;
    long clip_bottom = area->ClipRect.bottom;
    if (clip_right < clip_left || clip_bottom < clip_top) {
        clip_left = 0;
        clip_top = 0;
        clip_right = area->Width - 1;
        clip_bottom = area->Height - 1;
    }

    long src_stride = picture_aligned_width(this->Width);
    for (long sy = 0; sy < this->Height; ++sy) {
        long dy = y + sy;
        if (dy < 0 || dy >= area->Height || dy < clip_top || dy > clip_bottom) continue;

        long sx0 = 0;
        long dx0 = x;
        if (dx0 < clip_left) {
            sx0 += (clip_left - dx0);
            dx0 = clip_left;
        }
        if (dx0 < 0) {
            sx0 += -dx0;
            dx0 = 0;
        }

        long draw_w = this->Width - sx0;
        long clip_w = (clip_right - dx0) + 1;
        long area_w = area->Width - dx0;
        if (draw_w > clip_w) draw_w = clip_w;
        if (draw_w > area_w) draw_w = area_w;
        if (draw_w < 1) continue;

        unsigned char* src = this->Bits + (sy * src_stride) + sx0;
        unsigned char* dst = area->Bits + (dy * area->Pitch) + (dx0 * bytes_per_pixel);

        if (bytes_per_pixel == 1) {
            memcpy(dst, src, (size_t)draw_w);
            continue;
        }

        // Non-original fallback for >8bpp render targets. TODO: port exact palette conversion logic.
        for (long i = 0; i < draw_w; ++i) {
            unsigned char idx = src[i];
            unsigned char b = idx;
            unsigned char g = idx;
            unsigned char r = idx;
            if (area->DrawSystem) {
                tagPALETTEENTRY pe = area->DrawSystem->palette[idx];
                r = pe.peRed;
                g = pe.peGreen;
                b = pe.peBlue;
            }
            unsigned char* px = dst + (i * bytes_per_pixel);
            px[0] = b;
            if (bytes_per_pixel > 1) px[1] = g;
            if (bytes_per_pixel > 2) px[2] = r;
            if (bytes_per_pixel > 3) px[3] = 0;
        }
    }
}
