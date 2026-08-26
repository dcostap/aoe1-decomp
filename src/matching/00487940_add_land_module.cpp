// 00487940 TRIBE_RMM_Database_Controller::add_land_module
// Attempt log:
// 1: natural reconstruction from packet asm with raw fixed offsets, direct base call, debug_rand gates.
// Recovery notes:
// - PDB source module: rmm_tdbc.cpp, lines 165-312; owner is the derived controller.
// - Exact anchors: base add_land_module at +0x44, 14 ordered calls, and ret 4.
// - The map entry field at entry +0x18 is land_placement_edge, not map_edge_buffer[2].
// - The binary uses map_width at +0x14 and map_height at +0x18.
// - First exact transition: canonical rmm_tdbc context, member logger ABI, and these
//   proven field bindings. Reversions of the logger, map field, and dimensions failed.
// - Typed land-line loops matched exact code, except the final natural clamp form
//   reversed two independent loads. The retained exact form preserves proven line offsets.

#ifndef RMM_TDBC_SHARED_CONTEXT
#include "../../include/rmm_tdbc_context.h"
#endif

#define land_count land_info.land_num
#define byte_145c land_info.base_terrain
#define v1460 land_info.wall_1_avoidance_line
#define v1464 land_info.wall_2_avoidance_line
#define v1468 land_info.wall_3_avoidance_line
#define v146c land_info.wall_4_avoidance_line
#define map_h map_width
#define map_w map_height

void TRIBE_RMM_Database_Controller::add_land_module(uchar param_1)
{
    int old = this->map_info.maps[this->map_type].land_info.land_placement_edge;
    long* slot = &this->map_info.maps[this->map_type].land_info.land_placement_edge;
    if ((this->map_type == 5 || this->map_type == 8) && this->map_h < 100) {
        int v = (this->map_h >= 80 ? 0 : -1);
        v &= -5;
        v += 25;
        *slot = v;
    }

    this->RGE_RMM_Database_Controller::add_land_module(param_1);
    this->map_info.maps[this->map_type].land_info.land_placement_edge = old;

    int minus1 = -1;
    if (this->map_type < 5) {
        if (debug_rand((char*)0x585E04, 0xB9) < 0x3FFF) {
            this->land_info.wall_1_avoidance_line = minus1;
            int i = 0;
            if (this->land_count > 0) {
                RGE_Land_Info_Line* p = this->land_info.land;
                do {
                    p->wall_1_avoidance_line = minus1;
                    ++i;
                    ++p;
                } while (i < this->land_count);
            }
        }
        if (debug_rand((char*)0x585E04, 0xC0) < 0x3FFF) {
            this->land_info.wall_2_avoidance_line = minus1;
            int i = 0;
            if (this->land_count > 0) {
                RGE_Land_Info_Line* p = this->land_info.land;
                do {
                    p->wall_2_avoidance_line = minus1;
                    ++i;
                    ++p;
                } while (i < this->land_count);
            }
        }
        if (debug_rand((char*)0x585E04, 0xC7) < 0x3FFF) {
            this->land_info.wall_3_avoidance_line = this->map_h;
            int i = 0;
            if (this->land_count > 0) {
                RGE_Land_Info_Line* p = this->land_info.land;
                do {
                    p->wall_3_avoidance_line = this->map_h;
                    ++i;
                    ++p;
                } while (i < this->land_count);
            }
        }
        if (debug_rand((char*)0x585E04, 0xCE) < 0x3FFF) {
            this->land_info.wall_4_avoidance_line = this->map_w;
            int i = 0;
            if (this->land_count > 0) {
                RGE_Land_Info_Line* p = this->land_info.land;
                do {
                    p->wall_4_avoidance_line = this->map_w;
                    ++i;
                    ++p;
                } while (i < this->land_count);
            }
        }
    }

    if (this->map_type == 8) {
        if (debug_rand((char*)0x585E04, 0xD8) < 0x3FFF) {
            this->land_info.wall_3_avoidance_line = this->map_h;
            this->land_info.wall_1_avoidance_line = minus1;
            int i = 0;
            if (this->land_count > 0) {
                RGE_Land_Info_Line* p = this->land_info.land;
                do {
                    p->wall_1_avoidance_line = minus1;
                    p->wall_3_avoidance_line = this->map_h;
                    ++i;
                    ++p;
                } while (i < this->land_count);
            }
        } else {
            this->land_info.wall_4_avoidance_line = this->map_w;
            this->land_info.wall_2_avoidance_line = minus1;
            int i = 0;
            if (this->land_count > 0) {
                RGE_Land_Info_Line* p = this->land_info.land;
                do {
                    p->wall_2_avoidance_line = minus1;
                    p->wall_4_avoidance_line = this->map_w;
                    ++i;
                    ++p;
                } while (i < this->land_count);
            }
        }
    }

    if ((this->map_type >= 2 && this->map_type <= 6) || this->map_type == 8) {
        if (debug_rand((char*)0x585E04, 0xF1) < 0x3FFF) {
            if (debug_rand((char*)0x585E04, 0xF7) < 0x3FFF) {
                int i = 0;
                if (this->land_count > 0) {
                    RGE_Land_Info_Line* p = this->land_info.land;
                    do { p->zone = 0; i += 2; p += 2; } while (i < this->land_count);
                }
            } else {
                int i = 0;
                if (this->land_count > 0) {
                    RGE_Land_Info_Line* p = this->land_info.land;
                    do { p->zone = (unsigned char)i; i += 2; p += 2; } while (i < this->land_info.land_num);
                }
            }
            if (debug_rand((char*)0x585E04, 0xFF) < 0x3FFF) {
                int i = 1;
                if (this->land_count > i) {
                    RGE_Land_Info_Line* p = this->land_info.land + 1;
                    do { p->zone = 1; i += 2; p += 2; } while (i < this->land_count);
                }
                this->add_shallows_module();
            } else {
                int i = 1;
                if (this->land_count > i) {
                    RGE_Land_Info_Line* p = this->land_info.land + 1;
                    do { p->zone = (unsigned char)i; i += 2; p += 2; } while (i < this->land_count);
                }
                this->add_shallows_module();
            }
        } else {
            if (this->map_type == 4) {
                int i = 0;
                if (this->land_count > 0) {
                    RGE_Land_Info_Line* p = this->land_info.land;
                    do { p->zone = 0; ++i; ++p; } while (i < this->land_count);
                }
                this->byte_145c = 0;
            } else if (this->map_type >= 5) {
                int i = 0;
                if (this->land_count > 0) {
                    RGE_Land_Info_Line* p = this->land_info.land;
                    do { p->zone = 0; ++i; ++p; } while (i < this->land_count);
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
                long* p = (long*)((char*)this + 0x60);
                do {
                    if (p[-1] > 0) p[-1] = edge;
                    if (p[0] > 0) p[0] = edge;
                    if (p[1] < this->map_h) p[1] = this->map_h - edge;
                    if (p[2] < this->map_w) p[2] = this->map_w - edge;
                    ++i;
                    p = (long*)((char*)p + 0x34);
                } while (i < this->land_count);
            }
        }
        int area = (this->map_h - edge * 2) * (this->map_w - edge * 2);
        int each = (long)((double)area * rmm_land_scale);
        int j = 0;
        if (this->land_count > 0) {
            RGE_Land_Info_Line* p = this->land_info.land;
            do {
                p->land_size = each / this->land_count;
                ++j;
                ++p;
            } while (j < this->land_count);
        }
    }

    int r = debug_rand((char*)0x585E04, 0x137);
    L->Log((char*)0x585E28, r);
}
