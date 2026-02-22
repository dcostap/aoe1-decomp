#include "../include/TShape.h"
#include "../include/Res_file.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/RGE_Color_Table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

extern unsigned char shape_file_first;
extern int RESFILE_Decommit_Mapped_Memory(unsigned char* param_1, int param_2);

extern "C" unsigned int g_ASMShadowing_Amount;

static unsigned long shape_palette_checksum(const tagPALETTEENTRY* entries, int count) {
    if (!entries || count <= 0) return 0;
    unsigned long hash = 2166136261UL;
    for (int i = 0; i < count; ++i) {
        hash ^= (unsigned long)entries[i].peRed; hash *= 16777619UL;
        hash ^= (unsigned long)entries[i].peGreen; hash *= 16777619UL;
        hash ^= (unsigned long)entries[i].peBlue; hash *= 16777619UL;
        hash ^= (unsigned long)entries[i].peFlags; hash *= 16777619UL;
    }
    return hash;
}

static const unsigned char* shape_shadowing_xlate_table(TDrawArea* draw_area, unsigned int amount) {
    if (!draw_area || !draw_area->DrawSystem) return (const unsigned char*)0;
    if (amount == 0) return (const unsigned char*)0;

    static unsigned char table[256];
    static unsigned long last_pal_hash = 0;
    static unsigned int last_amount = 0xFFFFFFFFu;
    static TDrawSystem* last_sys = (TDrawSystem*)0;
    // NOTE: Not thread-safe; rendering in this codebase is expected to be single-threaded.

    const tagPALETTEENTRY* pal = draw_area->DrawSystem->palette;
    const unsigned long pal_hash = shape_palette_checksum(pal, 256);
    if (last_sys == draw_area->DrawSystem && last_pal_hash == pal_hash && last_amount == amount) {
        return table;
    }

    last_sys = draw_area->DrawSystem;
    last_pal_hash = pal_hash;
    last_amount = amount;

    const unsigned int keep = 256u - (amount & 0xFFu);
    for (int i = 0; i < 256; ++i) {
        const int r = (int)pal[i].peRed;
        const int g = (int)pal[i].peGreen;
        const int b = (int)pal[i].peBlue;

        const int tr = (r * (int)keep) >> 8;
        const int tg = (g * (int)keep) >> 8;
        const int tb = (b * (int)keep) >> 8;

        int best_idx = 0;
        int best_dist = 0x7FFFFFFF;
        for (int j = 0; j < 256; ++j) {
            const int dr = tr - (int)pal[j].peRed;
            const int dg = tg - (int)pal[j].peGreen;
            const int db = tb - (int)pal[j].peBlue;
            const int dist = dr * dr + dg * dg + db * db;
            if (dist < best_dist) {
                best_dist = dist;
                best_idx = j;
            }
        }
        table[i] = (unsigned char)best_idx;
    }

    return table;
}

static unsigned char shape_apply_shadowing_to_index(TDrawArea* draw_area, unsigned char idx, unsigned int amount) {
    const unsigned char* tbl = shape_shadowing_xlate_table(draw_area, amount);
    return tbl ? tbl[idx] : idx;
}

static unsigned long shape_apply_shadowing_to_pixel(TDrawArea* draw_area, unsigned long px, unsigned int amount) {
    if (!draw_area || amount == 0) return px;

    const unsigned int keep = 256u - (amount & 0xFFu);

    unsigned long rmask = 0x00FF0000;
    unsigned long gmask = 0x0000FF00;
    unsigned long bmask = 0x000000FF;
    if (draw_area->SurfaceDesc.dwSize == sizeof(DDSURFACEDESC)) {
        rmask = draw_area->SurfaceDesc.ddpfPixelFormat.dwRBitMask;
        gmask = draw_area->SurfaceDesc.ddpfPixelFormat.dwGBitMask;
        bmask = draw_area->SurfaceDesc.ddpfPixelFormat.dwBBitMask;
    }

    int rshift = 0, gshift = 0, bshift = 0;
    while (rmask && ((rmask >> rshift) & 1) == 0) rshift++;
    while (gmask && ((gmask >> gshift) & 1) == 0) gshift++;
    while (bmask && ((bmask >> bshift) & 1) == 0) bshift++;

    unsigned long rmax = rmask ? (rmask >> rshift) : 0xFF;
    unsigned long gmax = gmask ? (gmask >> gshift) : 0xFF;
    unsigned long bmax = bmask ? (bmask >> bshift) : 0xFF;

    unsigned long r = (rmask ? ((px & rmask) >> rshift) : ((px >> 16) & 0xFF));
    unsigned long g = (gmask ? ((px & gmask) >> gshift) : ((px >> 8) & 0xFF));
    unsigned long b = (bmask ? ((px & bmask) >> bshift) : (px & 0xFF));

    r = (r * (unsigned long)keep) >> 8;
    g = (g * (unsigned long)keep) >> 8;
    b = (b * (unsigned long)keep) >> 8;

    if (r > rmax) r = rmax;
    if (g > gmax) g = gmax;
    if (b > bmax) b = bmax;

    unsigned long out = px;
    if (rmask) out = (out & ~rmask) | ((r << rshift) & rmask);
    else out = (out & 0xFF00FFFF) | ((r & 0xFF) << 16);
    if (gmask) out = (out & ~gmask) | ((g << gshift) & gmask);
    else out = (out & 0xFFFF00FF) | ((g & 0xFF) << 8);
    if (bmask) out = (out & ~bmask) | ((b << bshift) & bmask);
    else out = (out & 0xFFFFFF00) | (b & 0xFF);

    return out;
}

static int shape_file_load(const char* path, unsigned char** out_data, int* out_size) {
    if (!path || !out_data || !out_size) return 0;
    *out_data = 0;
    *out_size = 0;

    int h = _open(path, _O_BINARY | _O_RDONLY);
    if (h == -1) return 0;

    _lseek(h, 0, SEEK_END);
    int sz = (int)_tell(h);
    if (sz <= 0) {
        _close(h);
        return 0;
    }

    unsigned char* p = (unsigned char*)malloc(sz);
    if (!p) {
        _close(h);
        return 0;
    }

    _lseek(h, 0, SEEK_SET);
    int rd = _read(h, p, sz);
    _close(h);
    if (rd != sz) {
        free(p);
        return 0;
    }

    *out_data = p;
    *out_size = sz;
    return 1;
}

static int shape_has_version_110(const void* p) {
    if (!p) return 0;
    return memcmp(p, "1.10", 4) == 0;
}

static int shape_bytes_per_pixel(TDrawArea* draw_area) {
    if (!draw_area) return 1;
    if (draw_area->SurfaceDesc.dwSize == sizeof(DDSURFACEDESC)) {
        int bpp = (int)draw_area->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount;
        if (bpp > 0) {
            int bytes = bpp / 8;
            if (bytes < 1) bytes = 1;
            if (bytes > 4) bytes = 4;
            return bytes;
        }
    }
    if (draw_area->Width > 0 && draw_area->Pitch > 0) {
        int bytes = draw_area->Pitch / draw_area->Width;
        if (bytes < 1) bytes = 1;
        if (bytes > 4) bytes = 4;
        return bytes;
    }
    return 1;
}

static unsigned long shape_scale_to_mask(unsigned int c, unsigned long mask) {
    if (mask == 0) return 0;
    unsigned long m = mask;
    int shift = 0;
    while ((m & 1) == 0) {
        m >>= 1;
        shift++;
    }
    int bits = 0;
    while ((m & 1) != 0) {
        m >>= 1;
        bits++;
    }
    if (bits <= 0) return 0;
    unsigned int maxv = (1u << bits) - 1u;
    unsigned int v = (c * maxv + 127u) / 255u;
    return ((unsigned long)v << shift) & mask;
}

static unsigned long shape_index_to_pixel(TDrawArea* draw_area, unsigned char idx, int bytes_per_pixel) {
    if (bytes_per_pixel <= 1) return (unsigned long)idx;

    unsigned int r = idx;
    unsigned int g = idx;
    unsigned int b = idx;
    if (draw_area && draw_area->DrawSystem) {
        tagPALETTEENTRY pe = draw_area->DrawSystem->palette[idx];
        r = (unsigned int)pe.peRed;
        g = (unsigned int)pe.peGreen;
        b = (unsigned int)pe.peBlue;
    }

    if (draw_area && draw_area->SurfaceDesc.dwSize == sizeof(DDSURFACEDESC)) {
        const DDSURFACEDESC* d = &draw_area->SurfaceDesc;
        unsigned long pr = shape_scale_to_mask(r, d->ddpfPixelFormat.dwRBitMask);
        unsigned long pg = shape_scale_to_mask(g, d->ddpfPixelFormat.dwGBitMask);
        unsigned long pb = shape_scale_to_mask(b, d->ddpfPixelFormat.dwBBitMask);
        return pr | pg | pb;
    }

    return ((unsigned long)r << 16) | ((unsigned long)g << 8) | (unsigned long)b;
}

static void shape_store_pixel(unsigned char* dst, int bytes_per_pixel, unsigned long px) {
    if (bytes_per_pixel <= 1) {
        dst[0] = (unsigned char)(px & 0xFF);
        return;
    }
    if (bytes_per_pixel == 2) {
        dst[0] = (unsigned char)(px & 0xFF);
        dst[1] = (unsigned char)((px >> 8) & 0xFF);
        return;
    }
    if (bytes_per_pixel == 3) {
        dst[0] = (unsigned char)(px & 0xFF);
        dst[1] = (unsigned char)((px >> 8) & 0xFF);
        dst[2] = (unsigned char)((px >> 16) & 0xFF);
        return;
    }
    dst[0] = (unsigned char)(px & 0xFF);
    dst[1] = (unsigned char)((px >> 8) & 0xFF);
    dst[2] = (unsigned char)((px >> 16) & 0xFF);
    dst[3] = (unsigned char)((px >> 24) & 0xFF);
}

static unsigned long shape_read_pixel(const unsigned char* src, int bytes_per_pixel) {
    if (bytes_per_pixel <= 1) return src[0];
    if (bytes_per_pixel == 2) return (unsigned long)src[0] | ((unsigned long)src[1] << 8);
    if (bytes_per_pixel == 3) return (unsigned long)src[0] | ((unsigned long)src[1] << 8) | ((unsigned long)src[2] << 16);
    return (unsigned long)src[0] | ((unsigned long)src[1] << 8) | ((unsigned long)src[2] << 16) | ((unsigned long)src[3] << 24);
}

static void shape_shadow_pixel(TDrawArea* draw_area, unsigned char* dst, int bytes_per_pixel, unsigned char* table) {
    if (!dst) return;
    if (bytes_per_pixel == 1) {
        if (!table) return;
        dst[0] = table[dst[0]];
        return;
    }

    if (!draw_area) return;

    // Runtime true-color fallback: apply shadow darkening using the same mask-aware approach as DrawShadowBox.
    int percent = 50;
    if (draw_area->shadow_color_table) {
        percent = (int)draw_area->shadow_color_table->id;
    }
    if (percent < 0) percent = 0;
    if (percent > 100) percent = 100;
    int keep = 100 - percent;

    unsigned long rmask = 0x00FF0000;
    unsigned long gmask = 0x0000FF00;
    unsigned long bmask = 0x000000FF;
    if (draw_area->SurfaceDesc.dwSize == sizeof(DDSURFACEDESC)) {
        rmask = draw_area->SurfaceDesc.ddpfPixelFormat.dwRBitMask;
        gmask = draw_area->SurfaceDesc.ddpfPixelFormat.dwGBitMask;
        bmask = draw_area->SurfaceDesc.ddpfPixelFormat.dwBBitMask;
    }

    int rshift = 0;
    int gshift = 0;
    int bshift = 0;
    while (rmask && ((rmask >> rshift) & 1) == 0) rshift++;
    while (gmask && ((gmask >> gshift) & 1) == 0) gshift++;
    while (bmask && ((bmask >> bshift) & 1) == 0) bshift++;

    unsigned long rmax = rmask ? (rmask >> rshift) : 0xFF;
    unsigned long gmax = gmask ? (gmask >> gshift) : 0xFF;
    unsigned long bmax = bmask ? (bmask >> bshift) : 0xFF;

    unsigned long px = shape_read_pixel(dst, bytes_per_pixel);
    unsigned long r = (rmask ? ((px & rmask) >> rshift) : ((px >> 16) & 0xFF));
    unsigned long g = (gmask ? ((px & gmask) >> gshift) : ((px >> 8) & 0xFF));
    unsigned long b = (bmask ? ((px & bmask) >> bshift) : (px & 0xFF));

    r = (r * (unsigned long)keep) / 100;
    g = (g * (unsigned long)keep) / 100;
    b = (b * (unsigned long)keep) / 100;

    if (r > rmax) r = rmax;
    if (g > gmax) g = gmax;
    if (b > bmax) b = bmax;

    unsigned long out = px;
    if (rmask) out = (out & ~rmask) | ((r << rshift) & rmask);
    else out = (out & 0xFF00FFFF) | ((r & 0xFF) << 16);
    if (gmask) out = (out & ~gmask) | ((g << gshift) & gmask);
    else out = (out & 0xFFFF00FF) | ((g & 0xFF) << 8);
    if (bmask) out = (out & ~bmask) | ((b << bshift) & bmask);
    else out = (out & 0xFFFFFF00) | (b & 0xFF);

    shape_store_pixel(dst, bytes_per_pixel, out);
}

static unsigned char* shape_slp_shadow_table(TDrawArea* draw_area, unsigned char* xlate) {
    // Parity note (ASMDraw_Sprite): opcode 0x0B uses the global table installed by _ASMSet_Xlate_Table
    // (DAT_0088c01c). In our software SLP renderer, `xlate` is the TShape::shape_draw() param_7 pointer
    // (same value that would be passed to _ASMSet_Xlate_Table), so we use it when present.
    // The ASM global persists across draws, so mirror that: if a table was previously provided, keep using it.
    static unsigned char* last_xlate = (unsigned char*)0;
    if (xlate) { last_xlate = xlate; return xlate; }
    if (last_xlate) return last_xlate;

    // UI can also install a runtime shadow table via draw_area->shadow_color_table.
    if (draw_area && draw_area->shadow_color_table) return draw_area->shadow_color_table->table;

    struct ShadowColTable {
        unsigned char table[256];
        int ok;
        ShadowColTable() : ok(0) {
            FILE* f = fopen("data\\shadow.col", "r");
            if (!f) f = fopen("dist\\data\\shadow.col", "r");
            if (!f) return;
            for (int i = 0; i < 256; ++i) {
                int v = 0;
                if (fscanf(f, " %d", &v) != 1) { fclose(f); return; }
                if (v < 0) v = 0;
                if (v > 255) v = 255;
                table[i] = (unsigned char)v;
            }
            fclose(f);
            ok = 1;
        }
    };

    static ShadowColTable shadow_col;
    return shadow_col.ok ? shadow_col.table : (unsigned char*)0;
}

static void shape_free_loaded_data(unsigned char* ptr, int load_type, int load_size) {
    if (!ptr) return;
    if (load_type == 1) {
        free(ptr);
        return;
    }
    if (load_type == 0) {
        RESFILE_Decommit_Mapped_Memory(ptr, load_size);
    }
}

TShape::TShape(char* filename, int file_id) {
    this->shape = 0;
    this->shape_header = 0;
    this->head = 0;
    this->offsets = 0;
    this->FShape = 0;
    this->shape_info = 0;
    this->load_type = -1;
    this->load_size = 0;

    if ((shape_file_first != 0 || file_id < 0) && filename && filename[0] != '\0') {
        char next_file[260];
        next_file[0] = '\0';
        strncpy(next_file, filename, sizeof(next_file) - 1);
        next_file[sizeof(next_file) - 1] = '\0';

        int len = (int)strlen(next_file);
        if (len < 4 || _stricmp(next_file + len - 4, ".slp") != 0) {
            strncat(next_file, ".SLP", sizeof(next_file) - strlen(next_file) - 1);
        }

        unsigned char* data = 0;
        int size = 0;
        if (shape_file_load(next_file, &data, &size)) {
            this->FShape = (SLhape_File_Header*)data;
            this->shape_info = (Shape_Info*)(data + 0x20);
            this->load_type = 1;
            this->load_size = size;
            return;
        }

        strncpy(next_file, filename, sizeof(next_file) - 1);
        next_file[sizeof(next_file) - 1] = '\0';
        len = (int)strlen(next_file);
        if (len >= 4 && _stricmp(next_file + len - 4, ".slp") == 0) {
            next_file[len - 4] = '\0';
        }
        len = (int)strlen(next_file);
        if (len < 4 || _stricmp(next_file + len - 4, ".shp") != 0) {
            strncat(next_file, ".SHP", sizeof(next_file) - strlen(next_file) - 1);
        }

        data = 0;
        size = 0;
        if (shape_file_load(next_file, &data, &size)) {
            this->shape = data;
            this->head = (Shape_File_Header*)this->shape;
            this->offsets = (Shape_Offsets*)(this->shape + 8);
            this->load_type = 1;
            this->load_size = size;
            return;
        }
    }

    if (file_id >= 0 && !this->FShape && !this->shape) {
        int size = 0;
        int out_type = 0;
        this->shape = RESFILE_load(0x73687020, file_id, &size, &out_type); // 'shp '
        if (this->shape) {
            if (shape_has_version_110(this->shape)) {
                this->head = (Shape_File_Header*)this->shape;
                this->offsets = (Shape_Offsets*)(this->shape + 8);
                this->load_type = out_type;
                this->load_size = size;
                return;
            }

            shape_free_loaded_data(this->shape, out_type, size);
            this->shape = 0;
        }

        unsigned char* slp_data = RESFILE_load(0x736c7020, file_id, &size, &out_type); // 'slp '
        if (slp_data) {
            this->FShape = (SLhape_File_Header*)slp_data;
            this->shape_info = (Shape_Info*)(slp_data + 0x20);
            this->shape = 0;
            this->load_type = out_type;
            this->load_size = size;
            return;
        }
    }
}

TShape::~TShape() {
    if (this->FShape) {
        shape_free_loaded_data((unsigned char*)this->FShape, this->load_type, this->load_size);
    }
    if (this->shape) {
        shape_free_loaded_data(this->shape, this->load_type, this->load_size);
    }

    this->shape = 0;
    this->shape_header = 0;
    this->head = 0;
    this->offsets = 0;
    this->FShape = 0;
    this->shape_info = 0;
}

unsigned char TShape::Check_shape(long shape_idx, char* msg) {
    (void)msg;

    if (!this->shape && !this->FShape) return 1;

    if (this->shape) {
        if (!this->head) return 1;
        if (!shape_has_version_110(this->head)) return 1;
        if (shape_idx >= 0 && shape_idx >= this->head->shape_num) return 1;
    }

    if (this->FShape) {
        if (shape_idx >= 0 && shape_idx >= this->FShape->Num_Shapes) return 1;
    }

    return 0;
}

int TShape::is_loaded() {
    return (this->shape || this->FShape) ? 1 : 0;
}

long TShape::shape_count() {
    if (this->Check_shape(-1, (char*)"RGL_shape_count")) return 0;
    if (this->FShape) return this->FShape->Num_Shapes;
    if (this->head) return this->head->shape_num;
    return 0;
}

unsigned char TShape::shape_minmax(long* x_min, long* y_min, long* x_max, long* y_max, int shape_idx) {
    if (x_min) *x_min = 0;
    if (y_min) *y_min = 0;
    if (x_max) *x_max = 0;
    if (y_max) *y_max = 0;

    if (shape_idx < 0) return 0;
    if (this->Check_shape(shape_idx, (char*)"RGL_shape_minxy")) return 0;

    if (this->FShape && this->shape_info) {
        Shape_Info* info = &this->shape_info[shape_idx];
        long xmin = -info->Hotspot_X;
        long ymin = -info->Hotspot_Y;
        long xmax = (info->Width - info->Hotspot_X) - 1;
        long ymax = (info->Height - info->Hotspot_Y) - 1;
        if (x_min) *x_min = xmin;
        if (y_min) *y_min = ymin;
        if (x_max) *x_max = xmax;
        if (y_max) *y_max = ymax;
        return 1;
    }

    if (!this->shape || !this->offsets) return 0;
    this->shape_header = (Shape_Header*)(this->shape + this->offsets[shape_idx].shape);
    if (!this->shape_header) return 0;

    if (x_min) *x_min = this->shape_header->xmin;
    if (y_min) *y_min = this->shape_header->ymin;
    if (x_max) *x_max = this->shape_header->xmax;
    if (y_max) *y_max = this->shape_header->ymax;
    return 1;
}

unsigned char TShape::shape_check(long x, long y, long shape_idx) {
    if (shape_idx < 0) return 0;
    if (this->Check_shape(shape_idx, (char*)"RGL_shape_draw")) return 0;

    if (this->shape && this->offsets) {
        Shape_Header* hdr = (Shape_Header*)(this->shape + this->offsets[shape_idx].shape);
        if (!hdr) return 0;
        this->shape_header = hdr;

        if (y < hdr->ymin || y > hdr->ymax || x < hdr->xmin || x > hdr->xmax) return 0;
        unsigned char* src = (unsigned char*)(hdr + 1);
        unsigned char* end = this->shape + this->load_size;
        long row = y - hdr->ymin;

        for (long r = 0; r < row; ++r) {
            while (src < end) {
                unsigned char cmd = *src++;
                unsigned int run = (unsigned int)(cmd >> 1);
                if (cmd & 1) {
                    if (run == 0) {
                        if (src >= end) return 0;
                        src++;
                    } else {
                        if (src + run > end) return 0;
                        src += run;
                    }
                } else {
                    if (run == 0) break;
                    if (src >= end) return 0;
                    src++;
                }
            }
        }

        long cur_x = hdr->xmin;
        while (src < end) {
            unsigned char cmd = *src++;
            unsigned int run = (unsigned int)(cmd >> 1);
            if (cmd & 1) {
                if (run == 0) {
                    if (src >= end) return 0;
                    cur_x += *src++;
                } else {
                    if (src + run > end) return 0;
                    if (x < cur_x + (long)run) return 1;
                    cur_x += run;
                    src += run;
                }
            } else {
                if (run == 0) return 0;
                if (src >= end) return 0;
                if (x < cur_x + (long)run) return 1;
                cur_x += run;
                src++;
            }
        }
        return 0;
    }

    if (!this->FShape || !this->shape_info) return 0;
    Shape_Info* info = &this->shape_info[shape_idx];
    long lx = info->Hotspot_X + x;
    long ly = info->Hotspot_Y + y;
    if (lx < 0 || ly < 0 || lx >= info->Width || ly >= info->Height) return 0;

    unsigned char* base = (unsigned char*)this->FShape;
    unsigned char* end = base + this->load_size;
    unsigned long outline_off = info->Shape_Outline_Offset + (unsigned long)(ly * 4);
    unsigned long data_off_tbl = info->Shape_Data_Offsets + (unsigned long)(ly * 4);
    if (outline_off + 4 > (unsigned long)this->load_size) return 0;
    if (data_off_tbl + 4 > (unsigned long)this->load_size) return 0;

    short left = *(short*)(base + outline_off);
    short right = *(short*)(base + outline_off + 2);
    if (left < 0) return 0;

    long row_max_x = (info->Width - right) - 1;
    if (lx < left || lx > row_max_x) return 0;

    unsigned long row_off = *(unsigned long*)(base + data_off_tbl);
    if (row_off >= (unsigned long)this->load_size) return 0;
    unsigned char* src = base + row_off;
    long cur_x = left;

    while (src < end && cur_x <= lx) {
        unsigned char cmd = *src++;
        unsigned char op = (unsigned char)(cmd & 0x0F);
        unsigned int run = 0;

        if (op == 0x0F) return 0;
        if (op == 0x02 || op == 0x03) {
            if (src >= end) return 0;
            run = (unsigned int)(((cmd & 0xF0) << 4) | *src++);
            if (op == 0x02) {
                if (lx < cur_x + (long)run) return 1;
                if (src + run > end) return 0;
                src += run;
            }
            cur_x += run;
            continue;
        }
        if (op == 0x07 || op == 0x0A || op == 0x06 || op == 0x0B) {
            run = (unsigned int)(cmd >> 4);
            if (run == 0) {
                if (src >= end) return 0;
                run = *src++;
            }
            if (lx < cur_x + (long)run) return 1;
            cur_x += run;
            if (op == 0x07) {
                if (src >= end) return 0;
                src++;
            } else if (op == 0x0A) {
                if (src >= end) return 0;
                src++;
            } else if (op == 0x06) {
                if (src + run > end) return 0;
                src += run;
            } else if (op == 0x0B) {
                // Shadow draw (0x0B) consumes no pixel payload bytes.
            }
            continue;
        }
        if (op == 0x0E) {
            unsigned char ext = (unsigned char)(cmd >> 4);
            if (ext == 0x04 || ext == 0x06) {
                run = 1;
            } else if (ext == 0x05 || ext == 0x07) {
                if (src >= end) return 0;
                run = (unsigned int)(*src++);
                if (run == 0) run = 1;
            } else {
                run = 0;
            }

            if (run) {
                if (lx < cur_x + (long)run) return 1;
                cur_x += run;
            }
            continue;
        }
        if ((op & 0x03) == 0x00 || (op & 0x03) == 0x01) {
            run = (unsigned int)(cmd >> 2);
            if ((op & 0x03) == 0x01 && run == 0) {
                if (src >= end) return 0;
                run = (unsigned int)(*src++);
            }
            if ((op & 0x03) == 0x00) {
                if (lx < cur_x + (long)run) return 1;
                if (src + run > end) return 0;
                src += run;
            }
            cur_x += run;
            continue;
        }
        return 0;
    }
    return 0;
}

static unsigned char shape_draw_shp_internal(TShape* self, TDrawArea* draw_area, long x, long y, long shape_idx, long mode, unsigned char* table) {
    if (!self || !draw_area || !self->shape || !self->offsets) return 0;
    const unsigned int shadow_amount = g_ASMShadowing_Amount & 0xFFu;

    Shape_Header* hdr = (Shape_Header*)(self->shape + self->offsets[shape_idx].shape);
    if (!hdr) return 0;
    self->shape_header = hdr;

    long sx1 = x + hdr->xmin;
    long sy1 = y + hdr->ymin;
    long sx2 = x + hdr->xmax;
    long sy2 = y + hdr->ymax;

    long clip_l = draw_area->ClipRect.left;
    long clip_t = draw_area->ClipRect.top;
    long clip_r = draw_area->ClipRect.right;
    long clip_b = draw_area->ClipRect.bottom;
    if (clip_l < 0) clip_l = 0;
    if (clip_t < 0) clip_t = 0;
    if (draw_area->Width > 0 && clip_r >= draw_area->Width) clip_r = draw_area->Width - 1;
    if (draw_area->Height > 0 && clip_b >= draw_area->Height) clip_b = draw_area->Height - 1;

    long draw_l = (sx1 > clip_l) ? sx1 : clip_l;
    long draw_t = (sy1 > clip_t) ? sy1 : clip_t;
    long draw_r = (sx2 < clip_r) ? sx2 : clip_r;
    long draw_b = (sy2 < clip_b) ? sy2 : clip_b;
    if (draw_l > draw_r || draw_t > draw_b) return 0;

    int locked_here = 0;
    if (!draw_area->Bits) {
        if (!draw_area->Lock((char*)"shape_draw", 0)) return 0;
        locked_here = 1;
    }

    unsigned char* bits = draw_area->Bits;
    if (!bits) {
        if (locked_here) draw_area->Unlock((char*)"shape_draw");
        return 0;
    }

    int bpp = shape_bytes_per_pixel(draw_area);
    if (mode != 0 && mode != 1 && mode != 2) {
        if (locked_here) draw_area->Unlock((char*)"shape_draw");
        return 0;
    }
    if (mode != 0 && !table) mode = 0;

    unsigned char* src = (unsigned char*)(hdr + 1);
    unsigned char* end = self->shape + self->load_size;
    long rows = (hdr->ymax - hdr->ymin) + 1;
    if (rows < 0) rows = 0;

    for (long row = 0; row < rows && src < end; ++row) {
        long dst_y = sy1 + row;
        long cur_x = sx1;
        int draw_row = (dst_y >= draw_t && dst_y <= draw_b) ? 1 : 0;
        unsigned char* dst_row = 0;
        if (draw_row) {
            int off = (draw_area->Orien == 1) ? (int)(dst_y * draw_area->Pitch) : (int)(((draw_area->Height - dst_y) - 1) * draw_area->Pitch);
            dst_row = bits + off;
        }

        for (;;) {
            if (src >= end) break;
            unsigned char cmd = *src++;
            unsigned int run = (unsigned int)(cmd >> 1);

            if (cmd & 1) {
                if (run == 0) {
                    if (src >= end) break;
                    cur_x += *src++;
                    continue;
                }

                if (src + run > end) {
                    src = end;
                    break;
                }

                for (unsigned int i = 0; i < run; ++i) {
                    unsigned char spx = *src++;
                    if (draw_row && cur_x >= draw_l && cur_x <= draw_r) {
                        unsigned char* dst_px = dst_row + cur_x * bpp;
                        if (mode == 2) {
                            shape_shadow_pixel(draw_area, dst_px, bpp, table);
                        } else {
                            unsigned char out_idx = spx;
                            if (mode == 1 && table) out_idx = table[spx];
                            if (bpp == 1 && shadow_amount) out_idx = shape_apply_shadowing_to_index(draw_area, out_idx, shadow_amount);
                            unsigned long px = shape_index_to_pixel(draw_area, out_idx, bpp);
                            if (bpp > 1 && shadow_amount) px = shape_apply_shadowing_to_pixel(draw_area, px, shadow_amount);
                            shape_store_pixel(dst_px, bpp, px);
                        }
                    }
                    cur_x++;
                }
                continue;
            }

            if (run == 0) break;
            if (src >= end) break;

            unsigned char fill = *src++;
            for (unsigned int i = 0; i < run; ++i) {
                if (draw_row && cur_x >= draw_l && cur_x <= draw_r) {
                    unsigned char* dst_px = dst_row + cur_x * bpp;
                    if (mode == 2) {
                        shape_shadow_pixel(draw_area, dst_px, bpp, table);
                    } else {
                        unsigned char out_idx = fill;
                        if (mode == 1 && table) out_idx = table[fill];
                        if (bpp == 1 && shadow_amount) out_idx = shape_apply_shadowing_to_index(draw_area, out_idx, shadow_amount);
                        unsigned long px = shape_index_to_pixel(draw_area, out_idx, bpp);
                        if (bpp > 1 && shadow_amount) px = shape_apply_shadowing_to_pixel(draw_area, px, shadow_amount);
                        shape_store_pixel(dst_px, bpp, px);
                    }
                }
                cur_x++;
            }
        }
    }

    if (locked_here) draw_area->Unlock((char*)"shape_draw");
    return 1;
}

static unsigned char shape_draw_slp_internal(TShape* self, TDrawArea* draw_area, long x, long y, long shape_idx, unsigned char* xlate) {
    if (!self || !draw_area || !self->FShape || !self->shape_info) return 0;
    const unsigned int shadow_amount = g_ASMShadowing_Amount & 0xFFu;
    Shape_Info* info = &self->shape_info[shape_idx];

    long width = info->Width;
    long height = info->Height;
    long draw_x = x - info->Hotspot_X;
    long draw_y = y - info->Hotspot_Y;

    int locked_here = 0;
    unsigned char* dest_bits = draw_area->Bits;
    if (!dest_bits) {
        dest_bits = draw_area->Lock((char*)"shape_draw", 0);
        locked_here = 1;
    }
    if (!dest_bits) return 0;

    int dest_pitch = draw_area->Pitch;
    int bytes_per_pixel = shape_bytes_per_pixel(draw_area);
    unsigned char* slp_base = (unsigned char*)self->FShape;
    unsigned char* shape_end = slp_base + self->load_size;

    long clip_l = draw_area->ClipRect.left;
    long clip_t = draw_area->ClipRect.top;
    long clip_r = draw_area->ClipRect.right;
    long clip_b = draw_area->ClipRect.bottom;
    if (clip_l < 0) clip_l = 0;
    if (clip_t < 0) clip_t = 0;
    if (draw_area->Width > 0 && clip_r >= draw_area->Width) clip_r = draw_area->Width - 1;
    if (draw_area->Height > 0 && clip_b >= draw_area->Height) clip_b = draw_area->Height - 1;

    unsigned long need_data = info->Shape_Data_Offsets + (unsigned long)(height * 4);
    unsigned long need_outline = info->Shape_Outline_Offset + (unsigned long)(height * 4);
    if (need_data > (unsigned long)self->load_size || need_outline > (unsigned long)self->load_size) {
        if (locked_here) draw_area->Unlock((char*)"shape_draw");
        return 0;
    }

    unsigned long* row_offsets = (unsigned long*)(slp_base + info->Shape_Data_Offsets);
    unsigned short* outline = (unsigned short*)(slp_base + info->Shape_Outline_Offset);
    unsigned char* active_xlate = xlate;

    for (long row = 0; row < height; row++) {
        long dst_y = draw_y + row;
        if (dst_y < clip_t || dst_y > clip_b) continue;

        unsigned short left = outline[row * 2 + 0];
        unsigned short right = outline[row * 2 + 1];
        if (left & 0x8000) continue;
        left = (unsigned short)(left & 0x7FFF);
        right = (unsigned short)(right & 0x7FFF);

        unsigned long row_off = row_offsets[row];
        if (row_off >= (unsigned long)self->load_size) continue;
        unsigned char* src = slp_base + row_off;

        long dst_x = draw_x + (long)left;
        long max_x = draw_x + width - 1 - (long)right;
        int off = (draw_area->Orien == 1) ? (int)(dst_y * dest_pitch) : (int)(((draw_area->Height - dst_y) - 1) * dest_pitch);
        unsigned char* dst_row = dest_bits + off;

        for (;;) {
            if (src >= shape_end) break;
            unsigned char cmd = *src++;
            unsigned char op = (unsigned char)(cmd & 0x0F);

            if (op == 0x0F) break;
            if (dst_x > max_x) break;

            if (op == 0x0E) {
                unsigned char ext = (unsigned char)(cmd >> 4);

                // 0x2E / 0x3E: normal/alternate transform selection.
                if (ext == 0x02) { active_xlate = (unsigned char*)0; continue; }
                if (ext == 0x03) { active_xlate = xlate; continue; }

                // 0x4E/0x5E/0x6E/0x7E: outline opcodes. These draw palette indices and advance X.
                unsigned int len = 0;
                unsigned char outline_idx = 0;
                if (ext == 0x04) { len = 1; outline_idx = 16; }
                else if (ext == 0x06) { len = 1; outline_idx = 243; }
                else if (ext == 0x05) { if (src >= shape_end) break; len = (unsigned int)(*src++); if (len == 0) len = 1; outline_idx = 16; }
                else if (ext == 0x07) { if (src >= shape_end) break; len = (unsigned int)(*src++); if (len == 0) len = 1; outline_idx = 243; }
                else { continue; }

                for (unsigned int i = 0; i < len; ++i) {
                    if (dst_x >= clip_l && dst_x <= clip_r && dst_x <= max_x) {
                        unsigned char out_idx = outline_idx;
                        if (bytes_per_pixel == 1 && shadow_amount) out_idx = shape_apply_shadowing_to_index(draw_area, out_idx, shadow_amount);
                        unsigned long out_px = shape_index_to_pixel(draw_area, out_idx, bytes_per_pixel);
                        if (bytes_per_pixel > 1 && shadow_amount) out_px = shape_apply_shadowing_to_pixel(draw_area, out_px, shadow_amount);
                        shape_store_pixel(dst_row + dst_x * bytes_per_pixel, bytes_per_pixel, out_px);
                    }
                    dst_x++;
                }
                continue;
            }

            if (op == 0x02 || op == 0x03) {
                if (src >= shape_end) break;
                unsigned int len = (unsigned int)(((cmd & 0xF0) << 4) | (*src++));
                if (op == 0x03) {
                    dst_x += (long)len;
                    continue;
                }

                if (src + len > shape_end) break;
                for (unsigned int i = 0; i < len; ++i) {
                    unsigned char px = *src++;
                    if (dst_x >= clip_l && dst_x <= clip_r && dst_x <= max_x) {
                        unsigned char out_idx = active_xlate ? active_xlate[px] : px;
                        if (bytes_per_pixel == 1 && shadow_amount) out_idx = shape_apply_shadowing_to_index(draw_area, out_idx, shadow_amount);
                        unsigned long out_px = shape_index_to_pixel(draw_area, out_idx, bytes_per_pixel);
                        if (bytes_per_pixel > 1 && shadow_amount) out_px = shape_apply_shadowing_to_pixel(draw_area, out_px, shadow_amount);
                        shape_store_pixel(dst_row + dst_x * bytes_per_pixel, bytes_per_pixel, out_px);
                    }
                    dst_x++;
                }
                continue;
            }

            if (op == 0x07 || op == 0x0A || op == 0x06 || op == 0x0B) {
                unsigned int len = (unsigned int)(cmd >> 4);
                if (len == 0) {
                    if (src >= shape_end) break;
                    len = (unsigned int)(*src++);
                }

                unsigned char a = 0;
                if (op == 0x07) {
                    if (src >= shape_end) break;
                    a = *src++;
                } else if (op == 0x0A) {
                    if (src >= shape_end) break;
                    a = *src++;
                } else if (op == 0x06) {
                    if (src + len > shape_end) break;
                }

                unsigned char* shadow_table = (unsigned char*)0;
                if (op == 0x0B) shadow_table = shape_slp_shadow_table(draw_area, xlate);

                for (unsigned int i = 0; i < len; ++i) {
                    unsigned char px = 0;
                    if (op == 0x06) {
                        px = *src++;
                    } else if (op == 0x07 || op == 0x0A) {
                        px = a;
                    }

                    if (dst_x >= clip_l && dst_x <= clip_r && dst_x <= max_x) {
                        if (op == 0x0B) {
                            shape_shadow_pixel(draw_area, dst_row + dst_x * bytes_per_pixel, bytes_per_pixel, shadow_table);
                        } else {
                            unsigned char out_idx = active_xlate ? active_xlate[px] : px;
                            if (bytes_per_pixel == 1 && shadow_amount) out_idx = shape_apply_shadowing_to_index(draw_area, out_idx, shadow_amount);
                            unsigned long out_px = shape_index_to_pixel(draw_area, out_idx, bytes_per_pixel);
                            if (bytes_per_pixel > 1 && shadow_amount) out_px = shape_apply_shadowing_to_pixel(draw_area, out_px, shadow_amount);
                            shape_store_pixel(dst_row + dst_x * bytes_per_pixel, bytes_per_pixel, out_px);
                        }
                    }
                    dst_x++;
                }
                continue;
            }

            if ((op & 0x03) == 0x00 || (op & 0x03) == 0x01) {
                unsigned int len = (unsigned int)(cmd >> 2);
                if ((op & 0x03) == 0x01) {
                    if (len == 0) {
                        if (src >= shape_end) break;
                        len = (unsigned int)(*src++);
                    }
                    dst_x += (long)len;
                    continue;
                }

                if (src + len > shape_end) break;
                for (unsigned int i = 0; i < len; ++i) {
                    unsigned char px = *src++;
                    if (dst_x >= clip_l && dst_x <= clip_r && dst_x <= max_x) {
                        unsigned char out_idx = active_xlate ? active_xlate[px] : px;
                        if (bytes_per_pixel == 1 && shadow_amount) out_idx = shape_apply_shadowing_to_index(draw_area, out_idx, shadow_amount);
                        unsigned long out_px = shape_index_to_pixel(draw_area, out_idx, bytes_per_pixel);
                        if (bytes_per_pixel > 1 && shadow_amount) out_px = shape_apply_shadowing_to_pixel(draw_area, out_px, shadow_amount);
                        shape_store_pixel(dst_row + dst_x * bytes_per_pixel, bytes_per_pixel, out_px);
                    }
                    dst_x++;
                }
                continue;
            }

            break;
        }
    }

    if (locked_here) draw_area->Unlock((char*)"shape_draw");
    return 1;
}

unsigned char TShape::shape_draw(TDrawArea* draw_area, long x, long y, long shape_idx, long param_5, unsigned char param_6, unsigned char* param_7) {
    (void)param_6;

    if (this->Check_shape(shape_idx, (char*)"RGL_shape_draw")) return 0;

    if (this->FShape && this->shape_info) {
        // NOTE: SLP path in original calls ASM sprite drawer and can use xlate table.
        // Our current reimplementation keeps the existing software decode path.
        return shape_draw_slp_internal(this, draw_area, x, y, shape_idx, param_7);
    }

    if (this->shape && this->offsets) {
        return shape_draw_shp_internal(this, draw_area, x, y, shape_idx, param_5, param_7);
    }

    return 0;
}
