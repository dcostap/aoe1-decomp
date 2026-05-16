// 00535210 RGE_View::update
// Attempt log:
// 1: natural decompiler-shaped implementation with local RGE_View/RGE_Map/RGE_Tile layout: wrong field ordering caused +4 offsets and 0x18 frame; .text 576 < original 619.
// 2: fix view field offsets/order from asm: center_map at 0x122/0x124, start screen/map fields at 0x126..0x12c, last_view at 0x138/0x13c; offsets fixed but compiler still chooses 0x18 frame and EDI=player.
// 3: rewrite body closer to decompiler with named short temporaries instead of int-heavy expression staging: size improved 576 -> 592, offsets fixed, but frame still sub esp,18 and EDI holds player instead of original EBX; check cannot compare because .text < configured 619.
// 4: explicit default /O2 /Oy flags produced same 592-byte body; removed redundant flag file.
// 5: /O1 /Oy probe shrank body to 546 bytes, wrong direction; rolled back to default flags.
// 6: using exact field order is required: player 0x100, map 0x104, tile dims 0x10c/0x10e/0x110, max cols/rows 0x116/0x118, center_map 0x122/0x124, last_view 0x138/0x13c.
// 7: current blocker is source/FPU liveness basin: original uses only 0x0c locals, EBX=player then BX=center_scr_col, BP=center_scr_row, and keeps fractional deltas on FPU stack; rebuilt spills more and uses 0x18 locals.
// 8: broad mismatch is not accepted_drift-safe; although behavior surface is close, register/frame/FPU scheduling differs before the geometry calculations.
// 9: likely next probes: restructure first half to avoid preserving converted col/row as C locals, and model the two __ftol adjustment results as stack-reused int temporaries rather than named shorts.
// 10: left in scratch after honest attempts; no exact match.

struct RGE_Player { unsigned char pad_000[0x114]; float view_x; float view_y; };
struct RGE_Tile { short screen_xpos; short screen_ypos; unsigned char field_4; unsigned char flags; unsigned char pad[0x12]; };
struct RGE_Map { unsigned char pad_000[0x8d8c]; RGE_Tile** map_row_offset; };
class RGE_View {
public:
    unsigned char pad_000[0x14]; int screen_w; int screen_h;
    unsigned char pad_01c[0x8c-0x1c]; short base_col;
    unsigned char pad_08e[0x90-0x8e]; short base_row;
    unsigned char pad_092[0x100-0x92]; RGE_Player* player; RGE_Map* map;
    short scale_x; short scale_y; short tile_half_wid; short tile_half_hgt; short elev_hgt; short pad_112; short pad_114; short max_col_num; short max_row_num;
    short center_scr_col; short center_scr_row; short center_scr_col_offset; short center_scr_row_offset; short center_map_col; short center_map_row; short start_scr_col; short start_scr_row; short start_map_col; short start_map_row;
    int map_scr_x_offset; int map_scr_y_offset; float last_view_x; float last_view_y;
    void update();
};

void RGE_View::update()
{
    RGE_Player* p = this->player;
    if (p && (p->view_x != this->last_view_x || p->view_y != this->last_view_y)) {
        short sVar6 = (short)(int)p->view_x;
        this->center_map_col = sVar6;
        short sVar7 = (short)(int)p->view_y;
        this->center_map_row = sVar7;
        float f0 = p->view_x - (float)(int)sVar6;
        float f1 = p->view_y - (float)(int)sVar7;
        this->last_view_x = p->view_x;
        this->last_view_y = p->view_y;
        short sVar9 = (short)(this->base_col + this->screen_w / 2) - this->tile_half_wid;
        short sVar10 = (short)(this->base_row + this->screen_h / 2) - this->tile_half_hgt;
        f0 = f0 * 48.0f;
        f1 = f1 * 48.0f;
        short sVar11 = (short)-(int)f0;
        short sVar12 = (short)-(int)(f1 * (float)this->scale_x - f0 * (float)this->scale_y + (float)this->tile_half_hgt);
        sVar9 += sVar11;
        sVar10 += sVar12;
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        RGE_Tile* tile = this->map->map_row_offset[sVar7] + sVar6;
        this->map_scr_x_offset = (int)tile->screen_xpos - (int)sVar9;
        this->map_scr_y_offset = ((int)this->elev_hgt * ((unsigned int)tile->flags >> 5) + (int)tile->screen_ypos) - (int)sVar10;
        this->center_scr_col_offset = (short)((sVar6 + sVar7) * this->tile_half_wid + sVar11);
        short h = this->tile_half_hgt;
        this->center_scr_row_offset = (short)((sVar7 - sVar6) * h + sVar12);
        short sVar13 = this->max_col_num / 2 + 2;
        this->start_map_row = this->center_map_row;
        this->start_map_row -= sVar13;
        this->start_map_col = sVar6 - sVar13;
        this->start_scr_col = (short)(sVar9 - sVar13 * this->tile_half_wid * 2);
        short sVar14 = this->max_row_num / 2 + 1;
        this->start_map_col += sVar14;
        this->start_map_row -= sVar14;
        this->start_scr_row = (short)(sVar10 - sVar14 * h * 2);
    }
}
