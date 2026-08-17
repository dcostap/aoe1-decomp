// 004374C0 RGE_Diamond_Map::clear_image (diam_map.cpp:519-569)
// Attempt log (sa-d55a5d35-clear_image, bounded 10-probe pass):
// - Baseline guessed TDA/DMap offsets, inlined memset, and missed the direct memset call.
// - Reconstructed the binary-backed TPanel/TDrawArea/RGE_Diamond_Map layouts and external memset;
//   size/calls became exact and the canonical typed source reached 216 differing bytes (310B).
// - A typed RGE_Map_Image_Line scan loaded before row bounds improved setup/block alignment;
//   the remaining 24-byte size gap is a natural VC5 short-branch basin, not accepted drift.
// - Short clipping intermediates were tested as a binary arithmetic hypothesis; they changed the
//   frame and cleanup and were rolled back. Best retained source is the typed-record/int-span form.
// - Paused: orientation register coloring and the compact-vs-near loop branch remain unresolved.
// - Follow-up pass: an interior line_len cursor and declaration-order changes were duplicate or
//   worse. Compound short clipping arithmetic reproduced the oracle's word-load body but added a
//   stack slot/frame and broad drift; a scoped widened pitch step reached 346 bytes with better
//   resynchronization but still had the wrong cursor allocation and was rolled back.
// - Follow-up pause: clean typed-record/int-span source remains authoritative; ordered calls,
//   frame, and behavior are aligned, while orientation register coloring and 24-byte loop drift
//   remain unresolved after 10 additional meaningful hypotheses.
// - Top-up pass: block-scoped post-lock locals and a scoped line cursor were tested; the former
//   was duplicate and the latter worsened loop topology. Short x/end arithmetic reproduced a
//   prior stack-slot basin and was rolled back. FillRect-style pointer-before-pitch ordering
//   worsened the orientation block. Boundary-local probes were duplicate; a temporary bottom
//   boundary test was rolled back because the binary's late load is clip-right, not clip-bottom.
// - Top-up pause: the clean typed-record/int-span reconstruction is restored. The remaining
//   evidence-backed gap is the original orientation register coloring and 24-byte loop shape.
// - Current pass: moving the natural scan step and line cursor into the positive-row block
//   worsened setup and loop topology; a named orientation local was codegen-identical.
// - Current pause: restored the prior clean source. No new lead remains before the structural
//   orientation and loop-shape gap is understood.
// - Follow-up pass (sa-4ab9d209): baseline remained 216 differing bytes (310 vs 334),
//   frame 0x10, three ordered calls, and 81.74% shape similarity. An interior line_len
//   cursor, an explicit short-pointer cursor, promoted pitch, short coordinate fields with
//   padding, short clipping intermediates, raw cursor plus short clipping, function-scope
//   line declaration, and char pointer types were tested. The cursor and char-pointer forms
//   were duplicate or worse; narrow-field and narrow-clipping forms added a 0x14 frame.
// - Follow-up pause: restored the pinned typed-record/int-span source. The remaining gap is
//   evidence-backed orientation register coloring plus the original narrow loop topology and
//   near back-edge. No exact result was found without opaque compiler steering.
// - Revisit pass (sa-85d5417c): natural declaration and owner-alias changes were duplicate or
//   worse. Short span locals reproduced word clipping but added a frame and broad drift. Direct
//   Lock guards, row declaration order, and orientation assignment order gave no improvement.
// - Revisit pause: restored the typed image-line ownership and natural do-loop source. Three
//   calls, the 0x10 frame, and behavior remain aligned; the 216-byte structural gap remains.
// - Revisit pass (sa-61f31cf1-r1): a natural short line_len cursor with narrow clipping
//   spans reproduced the word-width inner blocks, but changed the orientation register
//   basin, added control-flow drift, and reached 272 differing bytes (346-byte body).
//   A scoped cursor alias added a 0x14 frame and 283 differing bytes. Both were restored.
// - Revisit pause: the pinned typed-record/int-span source remains the clean natural
//   reconstruction. No policy-valid exact result was found.

extern "C" void* __cdecl memset(void* dst, int value, unsigned int count);
#pragma function(memset)

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void* draw_system;
    void* wnd;
    unsigned char* Bits;
    void* bitmap_info;
    void* bitmap;
    void* old_bitmap;
    int width;
    int Height;
    int Pitch;
    int Orien;

    unsigned char* Lock(char* name, int flag);
    void Unlock(char* name);
};

class TPanel {
public:
    virtual ~TPanel();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0xB8];
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

struct RGE_Map_Image_Line {
    short tile_row;
    short start_x;
    short line_len;
};

class RGE_Diamond_Map : public TPanel {
public:
    void clear_image();

    void* world;
    void* player;
    void* map;
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    tagRECT view_rect;
    void* last_player;
    RGE_Map_Image_Line* map_image_lines;
    void* map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;
    short map_tile_draw_hgt;
    short map_tile_draw_wid;
    short view_col;
    short view_row;
    void* main_view;
    int scrolling;
    unsigned char fog_color;
    unsigned char pad_159[3];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;
};

void RGE_Diamond_Map::clear_image()
{
    unsigned char* p;
    TDrawArea* save_area;
    short start_y;
    short pi;
    p = this->save_area->Lock("diam_map::clear_image", 1);
    if (p == 0)
        return;

    save_area = this->save_area;
    start_y = this->map_image_start_y;

    if (save_area->Orien == 1) {
        pi = (short)save_area->Pitch;
        p = save_area->Bits + (int)start_y * save_area->Pitch;
    } else {
        p = save_area->Bits + ((save_area->Height - (int)start_y) - 1) * save_area->Pitch;
        pi = -(short)save_area->Pitch;
    }

    RGE_Map_Image_Line* line = this->map_image_lines;
    short cur_y = (short)this->pnl_y + start_y;
    short end_y = this->map_image_hgt + cur_y;

    if (cur_y < end_y) {
        int yv = (int)cur_y;
        int rm = (int)end_y - yv;

        do {
            if (yv >= this->clip_rect.top && yv <= this->clip_rect.bottom) {
                short sx = line->start_x;
                int s2 = (int)this->pnl_x + (int)sx;
                int ex = s2 + (int)line->line_len - 1;

                if (s2 < this->clip_rect.left) {
                    int adj = this->clip_rect.left - s2;
                    sx = (short)((int)sx + adj);
                    s2 = this->clip_rect.left;
                }
                if (ex > this->clip_rect.right) ex = this->clip_rect.right;

                if (s2 >= this->clip_rect.left && ex <= this->clip_rect.right)
                    memset(p + (int)sx, this->color, ex - s2 + 1);
            }
            line++;
            p += (int)pi;
            yv++;
            rm--;
        } while (rm);
    }

    this->save_area->Unlock("diam_map::clear_image");
}
