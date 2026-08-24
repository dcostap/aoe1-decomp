// 00487940 TRIBE_RMM_Database_Controller::add_land_module
// Attempt log:
// 1: natural reconstruction from packet asm with raw fixed offsets, direct base call, debug_rand gates.

#ifndef RMM_TDBC_SHARED_CONTEXT
typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" void __cdecl DebugLog_Log(void* log, char* fmt, int value);
extern "C" double rmm_land_scale;
#define g_debug_log (*(void**)0x62C4FC)

class RGE_RMM_Database_Controller {
public:
    virtual unsigned char generate();
    virtual void add_land_module(uchar x);
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    char gap_04[0x10];
    int map_h;              // +14
    int map_w;              // +18
    char gap_1c[0x18];
    int map_type;           // +34
    char gap_38[0x1420];
    int land_count;         // +1458
    unsigned char byte_145c;// +145c
    char gap_145d[3];
    int v1460;
    int v1464;
    int v1468;
    int v146c;
    char gap_1470[0x4f58 - 0x1470];
    int* map_infos;         // +4f58

    void add_land_module(uchar param_1);
    void add_shallows_module();
};
#endif

#ifdef RMM_TDBC_SHARED_CONTEXT
#define land_count land_info.land_num
#define byte_145c land_info.base_terrain
#define v1460 land_info.wall_1_avoidance_line
#define v1464 land_info.wall_2_avoidance_line
#define v1468 land_info.wall_3_avoidance_line
#define v146c land_info.wall_4_avoidance_line
#define map_h map_height
#define map_w map_width
#endif

#define g_debug_log (*(void**)0x62C4FC)

#define FIELD_INT(off) (*(int*)((char*)this + (off)))
#define FIELD_BYTE(off) (*(unsigned char*)((char*)this + (off)))

#define SET_ALL_INT(off_, val_) \
    { int i_ = 0; int n_ = this->land_count; \
      if (n_ > 0) { int* p_ = (int*)((char*)this + (off_)); \
        do { *p_ = (val_); ++i_; p_ = (int*)((char*)p_ + 0x34); } while (i_ < this->land_count); } }
#define SET_ALL_BYTE(off_, stride_, val_, start_) \
    { int i_ = (start_); int n_ = this->land_count; \
      if (i_ < n_) { unsigned char* p_ = (unsigned char*)((char*)this + (off_)); \
        do { *p_ = (unsigned char)(val_); i_ += 2; p_ += (stride_); } while (i_ < this->land_count); } }

void TRIBE_RMM_Database_Controller::add_land_module(uchar param_1)
{
    int old = this->map_info.maps[this->map_type].land_info.map_edge_buffer[2];
    long* slot = &this->map_info.maps[this->map_type].land_info.map_edge_buffer[2];
    if ((this->map_type == 5 || this->map_type == 8) && this->map_h < 100) {
        int v = (this->map_h >= 80 ? 0 : -1);
        v &= -5;
        v += 25;
        *slot = v;
    }

    this->RGE_RMM_Database_Controller::add_land_module(param_1);
    this->map_info.maps[this->map_type].land_info.map_edge_buffer[2] = old;

    int minus1 = -1;
    if (this->map_type < 5) {
        if (debug_rand((char*)0x585E04, 0xB9) < 0x3FFF) {
            this->land_info.wall_1_avoidance_line = minus1;
            SET_ALL_INT(0x5C, minus1);
        }
        if (debug_rand((char*)0x585E04, 0xC0) < 0x3FFF) {
            this->land_info.wall_2_avoidance_line = minus1;
            SET_ALL_INT(0x60, minus1);
        }
        if (debug_rand((char*)0x585E04, 0xC7) < 0x3FFF) {
            this->land_info.wall_3_avoidance_line = this->map_height;
            SET_ALL_INT(0x64, this->map_h);
        }
        if (debug_rand((char*)0x585E04, 0xCE) < 0x3FFF) {
            this->land_info.wall_4_avoidance_line = this->map_width;
            SET_ALL_INT(0x68, this->map_w);
        }
    }

    if (this->map_type == 8) {
        if (debug_rand((char*)0x585E04, 0xD8) < 0x3FFF) {
            this->land_info.wall_3_avoidance_line = this->map_height;
            this->land_info.wall_1_avoidance_line = minus1;
            int i = 0;
            if (this->land_count > 0) {
                int* p = (int*)((char*)this + 0x64);
                do {
                    p[-2] = minus1;
                    *p = this->map_height;
                    ++i;
                    p = (int*)((char*)p + 0x34);
                } while (i < this->land_count);
            }
        } else {
            this->land_info.wall_4_avoidance_line = this->map_width;
            this->land_info.wall_2_avoidance_line = minus1;
            int i = 0;
            if (this->land_count > 0) {
                int* p = (int*)((char*)this + 0x68);
                do {
                    p[-2] = minus1;
                    *p = this->map_width;
                    ++i;
                    p = (int*)((char*)p + 0x34);
                } while (i < this->land_count);
            }
        }
    }

    if ((this->map_type >= 2 && this->map_type <= 6) || this->map_type == 8) {
        if (debug_rand((char*)0x585E04, 0xF1) < 0x3FFF) {
            if (debug_rand((char*)0x585E04, 0xF7) < 0x3FFF) {
                int i = 0;
                if (this->land_count > 0) {
                    unsigned char* p = (unsigned char*)((char*)this + 0x54);
                    do { *p = 0; i += 2; p += 0x68; } while (i < this->land_count);
                }
            } else {
                int i = 0;
                if (this->land_count > 0) {
                    unsigned char* p = (unsigned char*)((char*)this + 0x54);
                    do { *p = (unsigned char)i; i += 2; p += 0x68; } while (i < this->land_info.land_num);
                }
            }
            if (debug_rand((char*)0x585E04, 0xFF) < 0x3FFF) {
                int i = 1;
                if (this->land_count > i) {
                    unsigned char* p = (unsigned char*)((char*)this + 0x88);
                    do { *p = 1; i += 2; p += 0x68; } while (i < this->land_count);
                }
                this->add_shallows_module();
            } else {
                int i = 1;
                if (this->land_count > i) {
                    unsigned char* p = (unsigned char*)((char*)this + 0x88);
                    do { *p = (unsigned char)i; i += 2; p += 0x68; } while (i < this->land_count);
                }
                this->add_shallows_module();
            }
        } else {
            if (this->map_type == 4) {
                int i = 0;
                if (this->land_count > 0) {
                    unsigned char* p = (unsigned char*)((char*)this + 0x54);
                    do { *p = 0; ++i; p += 0x34; } while (i < this->land_count);
                }
                this->byte_145c = 0;
            } else if (this->map_type >= 5) {
                int i = 0;
                if (this->land_count > 0) {
                    unsigned char* p = (unsigned char*)((char*)this + 0x54);
                    do { *p = 0; ++i; p += 0x34; } while (i < this->land_count);
                }
            }
        }
    }

    if (this->map_type == 5 || this->map_type == 8) {
        int edge = 20;
        if (this->map_h < 100) {
            edge = (this->map_h >= 80 ? 0 : -1);
            edge &= -5;
            edge += 15;
            if (this->v1460 > 0) this->v1460 = edge;
            if (this->v1464 > 0) this->v1464 = edge;
            if (this->v1468 < this->map_h) this->v1468 = this->map_h - edge;
            if (this->v146c < this->map_w) this->v146c = this->map_w - edge;
            int i = 0;
            if (this->land_count > 0) {
                int* p = (int*)((char*)this + 0x60);
                do {
                    if (p[-1] > 0) p[-1] = edge;
                    if (p[0] > 0) p[0] = edge;
                    if (p[1] < this->map_h) p[1] = this->map_h - edge;
                    if (p[2] < this->map_w) p[2] = this->map_w - edge;
                    ++i;
                    p = (int*)((char*)p + 0x34);
                } while (i < this->land_count);
            }
        }
        int area = (this->map_h - edge * 2) * (this->map_w - edge * 2);
        int each = (long)((double)area * rmm_land_scale);
        int j = 0;
        if (this->land_count > 0) {
            int* p = (int*)((char*)this + 0x3C);
            do {
                *p = each / this->land_count;
                ++j;
                p = (int*)((char*)p + 0x34);
            } while (j < this->land_count);
        }
    }

    int r = debug_rand((char*)0x585E04, 0x137);
    DebugLog_Log(g_debug_log, (char*)0x585E28, r);
}
