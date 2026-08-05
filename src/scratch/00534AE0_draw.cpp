// VA: 00534AE0 RGE_View::draw (view.cpp:1324-1904, 1835 bytes, __thiscall virtual)
// Attempt log:
//   - Canonical ownership (from asm/PDB/donors 00533760, 0053A9C0, 004777C0):
//     RGE_View : TPanel (vptr@+0); render_area@+0x20; screen_w@+0x14, screen_h@+0x18;
//     world@+0xFC; start_scr_col/row@0x126/0x128, start_map_col/row@0x12A/0x12C;
//     map_scr_x/y_offset@0x130/0x134; render_terrain_mode(byte)@0x142;
//     TSpan_List_Manager* clip masks @0x178/0x17C/0x180;
//     Limited_Render_Rect@0x2A0, Use_Rect2@0x2A4, Render_Rect1@0x2A8, Render_Rect2@0x2B8;
//     Float_X/Y_Delta@0x2D0/0x2D4, Queued_Blits@0x2D8; save_area1@0x324; prior_objs@0x334.
//     TPanel virtuals: vf28(int)@slot0x28, vf2c()@slot0x2C.
//     TDrawArea: Width@0x18, Height@0x1C, ClipRect@0x28, DisplayOffsets@0xBC.
//   - Globals: view_debug_redraw_all@0x87D7A4, view_debug_ObstructionMap@0x87D7A8,
//     view_debug_palette@0x87D7B0, frame_count@0x87D7B8, tiles_drawn@0x87D7BC,
//     MouseSystem@0x62E660, rge_base_game@0x62C574.
//   - Diagnostic baseline: 26/26 calls aligned and saved regs ebx/ebp/esi/edi,
//     with frame 0x54 and -41 bytes / 81.6% strict diff, but that version also
//     contained the false member write and duplicated clipping block described
//     below; it is codegen evidence only, not the clean-source baseline.
//   - Probe: deltas are binary-observed `short` on both operands; leaving them as
//     `long` int (int-int) vs faithful short widened inside matched decompiler shape.
//   - Codegen blocker (kept canonical source): the cleanest single-copy clipping
//     using local sw/sh (faithful to decompiler iVar13 local, and the binary NEVER
//     writes back this->screen_w/screen_h) drops the rebuilt to 1763B / frame 0x50 /
//     95.1%. An opaque variant that added a spurious `this->screen_w -= ...` member
//     write plus a duplicate clipping block got to 1794B / frame 0x54 / 81.6% but
//     is NOT faithful source, so it is not retained. The gap driver is VC5 liveness
//     around the rect-clipping locals (one 4-byte frame slot + -31 bytes).
//   Next lead: this is a large 1835B / 26-call virtual; exact byte-parity likely
//     needs a focused variant lab on the clipping-block liveness basin or the full
//     view.cpp TU context (several helper callees here are themselves scratch:
//     CreateBlitQueue/ProcessQueuedBlit/update/draw_view). Frame is provably 0x54
//     with these locals; find what occupies the 4th rect/short slot.
//   - Orchestrator audit: retained as a full natural scratch reconstruction, not
//     as an exhausted or logic-review-ready candidate. Only one meaningful probe
//     was completed. The first structural lead is to materialize the initial
//     view_debug_redraw_all read before tiles_drawn=0, matching the executable's
//     load-before-frame/store schedule, then recover the missing 0x54 local slot.
// FLAGS: none (default /O2 /Oy). Inline asm forbidden.

struct tagRECT { long left; long top; long right; long bottom; };

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

extern int view_debug_redraw_all;
extern int view_debug_ObstructionMap;
extern int view_debug_palette;
extern int frame_count;
extern int tiles_drawn;

class TSpan_List_Manager {
public:
    void ResetAll();
};

class DClipInfo_List {
public:
    void Scroll(int x, int y);
};

class TMousePointer {
public:
    void Poll();
};
extern TMousePointer* MouseSystem;

class RGE_Base_Game {
public:
    char gap_000[0x1B4];
    int game_mode;   // +0x1B4
};
extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    struct Draw_System {
        char gap[0x478];
        unsigned char field478;   // +0x478
    };
    Draw_System* DrawSystem;    // +0x0
    char gap_04[0x18 - 0x4];
    int Width;                  // +0x18
    int Height;                 // +0x1C
    tagRECT ClipRect;           // +0x28
    char gap_30[0xBC - 0x30];
    int* DisplayOffsets;        // +0xBC
    char gap_C0[0xE8 - 0xC0];
    int UsingVidMem;            // +0xE8

    void Clear(tagRECT* r, int color);
    unsigned char* Lock(const char* name, int flag);
    void Unlock(const char* name);
    void OverlayMemCopy(tagRECT* dst, tagRECT* src, int x, int y, int a5, int a6);
    void SetFloatOffsets(int x, int y);
    void PtrClear(tagRECT* r, int fill);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual long vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int);
    virtual long handle_idle();
    virtual void vf28(int);
    virtual void vf2c();
    virtual void vf30();
};

class RGE_View : public TPanel {
public:
    char pad_004[0x14 - 0x4];
    int screen_w;                  // +0x14
    int screen_h;                  // +0x18
    char pad_01C[0x20 - 0x1C];
    TDrawArea* render_area;        // +0x20
    tagRECT clear_rect;            // +0x24
    char pad_34[0x8C - 0x34];
    int field_8C;                  // +0x8C
    int field_90;                  // +0x90
    char pad_94[0xEF - 0x94];
    unsigned char clear_color;     // +0xEF
    char pad_F0[0xFC - 0xF0];
    void* world;                   // +0xFC
    char pad_100[0x126 - 0x100];
    short start_scr_col;           // +0x126
    short start_scr_row;           // +0x128
    short start_map_col;           // +0x12A
    short start_map_row;           // +0x12C
    char pad_12E[0x130 - 0x12E];
    int map_scr_x_offset;          // +0x130
    int map_scr_y_offset;          // +0x134
    char pad_138[0x142 - 0x138];
    unsigned char render_terrain_mode; // +0x142
    char pad_143[0x178 - 0x143];
    TSpan_List_Manager* Terrain_Clip_Mask;      // +0x178
    TSpan_List_Manager* Terrain_Fog_Clip_Mask;  // +0x17C
    TSpan_List_Manager* Master_Clip_Mask;       // +0x180
    char pad_184[0x2A0 - 0x184];
    int Limited_Render_Rect;       // +0x2A0
    int Use_Rect2;                 // +0x2A4
    tagRECT Render_Rect1;          // +0x2A8
    tagRECT Render_Rect2;          // +0x2B8
    char pad_2C8[0x2D0 - 0x2C8];
    int Float_X_Delta;             // +0x2D0
    int Float_Y_Delta;             // +0x2D4
    int Queued_Blits;              // +0x2D8
    char pad_2DC[0x324 - 0x2DC];
    TDrawArea* save_area1;         // +0x324
    char pad_328[0x334 - 0x328];
    DClipInfo_List* prior_objs;    // +0x334

    void update();
    void CreateBlitQueue(tagRECT& src, tagRECT& dst, int xd, int yd);
    void ProcessQueuedBlit(int force);
    void draw_paint_brush();
    void draw_view(unsigned char p1, TDrawArea* p2);
    void draw();
};

void RGE_View::draw()
{
    tagRECT old_rect;
    tagRECT new_rect;
    tagRECT clip_rect1;
    tagRECT clip_rect2;
    short old_start_scr_col;
    short old_start_scr_row;
    short old_start_map_col;
    short old_start_map_row;
    int old_map_scr_x_offset;
    int old_map_scr_y_offset;
    int sw;
    int sh;

    tiles_drawn = 0;
    if (view_debug_redraw_all != 0) {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if (view_debug_ObstructionMap != 0 || view_debug_palette != 0) {
        this->render_terrain_mode = 0;
    }

    if (this->world == 0) {
        this->vf28(0);
        this->render_area->Clear(&this->clear_rect, this->clear_color);
        this->vf2c();
        return;
    }

    old_start_scr_col = this->start_scr_col;
    old_start_map_row = this->start_map_row;
    old_start_scr_row = this->start_scr_row;
    old_start_map_col = this->start_map_col;
    this->Terrain_Clip_Mask->ResetAll();
    this->Terrain_Fog_Clip_Mask->ResetAll();
    this->Master_Clip_Mask->ResetAll();
    old_map_scr_x_offset = this->map_scr_x_offset;
    old_map_scr_y_offset = this->map_scr_y_offset;
    this->Use_Rect2 = 0;
    this->Limited_Render_Rect = 0;
    this->update();
    this->vf28(0);

    if (this->render_terrain_mode == 1) {
        if ((this->start_map_col == old_start_map_col && this->start_map_row == old_start_map_row) &&
            (this->start_scr_col == old_start_scr_col && this->start_scr_row == old_start_scr_row)) {
            goto label_done;
        }

        long dx = (short)this->map_scr_x_offset - old_map_scr_x_offset;
        long dy = (short)this->map_scr_y_offset - old_map_scr_y_offset;
        if (dx == 0 && dy == 0) goto label_done;

        new_rect.left = (int)dx;
        new_rect.top = (int)dy;
        old_rect.left = 0;
        old_rect.top = 0;
        old_rect.right = this->screen_w - 1;
        old_rect.bottom = this->screen_h - 1;
        new_rect.right = old_rect.right + new_rect.left;
        new_rect.bottom = old_rect.bottom + new_rect.top;

        if (new_rect.bottom < 0 || new_rect.right < 0 || old_rect.bottom < new_rect.top || old_rect.right < new_rect.left) {
            this->render_terrain_mode = 0;
            goto label_done;
        }

        if ((dx & 7) != 0) {
            long t = new_rect.left;
            if (dx < 1) t = new_rect.left + 7;
            long a = (t & ~7) - new_rect.left;
            dx += a;
            this->map_scr_x_offset += a;
        }
        if ((dy & 7) != 0) {
            long t = new_rect.top;
            if (dy < 1) t = new_rect.top + 7;
            long a = (t & ~7) - new_rect.top;
            dy += a;
            this->map_scr_y_offset += a;
        }

        int xd = (int)dx;
        int yd = (int)dy;

        sw = this->screen_w - 1;
        sh = this->screen_h - 1;
        if (dx < 0) {
            old_rect.left = 0;
            old_rect.right = (int)dx + sw;
            new_rect.left = -(int)dx;
        } else {
            old_rect.left = (int)dx;
            old_rect.right = sw;
            new_rect.left = 0;
            sw = sw - old_rect.left;
        }
        new_rect.right = sw;

        if (dy < 0) {
            old_rect.top = 0;
            old_rect.bottom = (int)dy + sh;
            new_rect.top = -(int)dy;
        } else {
            old_rect.top = (int)dy;
            old_rect.bottom = sh;
            new_rect.top = 0;
            sh = sh - old_rect.top;
        }
        new_rect.bottom = sh;

        if (this->render_area->DrawSystem->field478 == 1 || this->render_area->UsingVidMem == 0) {
            this->render_area->OverlayMemCopy(&old_rect, &new_rect, xd, yd, this->field_8C, this->field_90);
            this->Queued_Blits = 0;
        } else {
            this->CreateBlitQueue(old_rect, new_rect, xd, yd);
            if (MouseSystem != 0) MouseSystem->Poll();
            if (this->Queued_Blits != 0) this->ProcessQueuedBlit(0);
        }

        this->prior_objs->Scroll(xd, yd);

        int fxd = this->Float_X_Delta + xd;
        this->Float_X_Delta = fxd;
        if (fxd >= this->save_area1->Width) {
            if (this->save_area1->Lock("view::draw", 1) != 0) {
                memcpy((void*)this->save_area1->DisplayOffsets[0],
                       (const void*)(this->save_area1->DisplayOffsets[this->save_area1->Height - 1] + this->save_area1->Width),
                       this->Float_X_Delta - xd);
                this->Float_X_Delta -= this->save_area1->Width;
                this->Float_Y_Delta += 1;
                if (this->Float_Y_Delta >= this->save_area1->Height) this->Float_Y_Delta = 0;
                this->save_area1->Unlock("view::draw");
            }
        } else {
            if (this->save_area1->Lock("view::draw2", 1) != 0) {
                this->Float_X_Delta += this->save_area1->Width;
                this->Float_Y_Delta -= 1;
                if (this->Float_Y_Delta < 0) this->Float_Y_Delta = this->save_area1->Height - 1;
                memcpy((void*)this->save_area1->DisplayOffsets[0],
                       (const void*)(this->save_area1->DisplayOffsets[this->save_area1->Height - 1] + this->save_area1->Width),
                       this->Float_X_Delta);
                this->save_area1->Unlock("view::draw3");
            }
        }

        this->Float_Y_Delta += yd;
        if (this->Float_Y_Delta < 0) this->Float_Y_Delta += this->save_area1->Height;
        if (this->Float_Y_Delta >= this->save_area1->Height) this->Float_Y_Delta -= this->save_area1->Height;

        this->save_area1->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);

        if ((new_rect.left == 0) && (new_rect.right == sw)) {
            clip_rect1.left = -1;
            if ((new_rect.top == 0) && (new_rect.bottom == sh)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = 0;
                clip_rect2.right = sw;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.bottom = sh;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        } else if (new_rect.left == 0) {
            clip_rect1.right = sw;
            clip_rect1.left = new_rect.right + 1;
            clip_rect1.bottom = sh;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = 0;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = new_rect.right;
                    clip_rect2.bottom = clip_rect1.bottom;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.right = new_rect.right;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        } else {
            clip_rect1.right = new_rect.left - 1;
            clip_rect1.bottom = sh;
            clip_rect1.left = 0;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = new_rect.left;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = sw;
                    clip_rect2.bottom = clip_rect1.bottom;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.right = sw;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        }

        if (clip_rect1.left != -1) {
            this->save_area1->PtrClear(&clip_rect1, 0);
            this->Limited_Render_Rect = 1;
            this->Render_Rect1 = clip_rect1;
        }
        if (clip_rect2.left != -1) {
            this->save_area1->PtrClear(&clip_rect2, 0);
            if (clip_rect1.left == -1) {
                this->Limited_Render_Rect = 1;
                this->Render_Rect1 = clip_rect2;
            } else {
                this->Use_Rect2 = 1;
                this->Render_Rect2 = clip_rect2;
            }
        }
    }

label_done:
    if (MouseSystem != 0) MouseSystem->Poll();
    if (this->Queued_Blits != 0) this->ProcessQueuedBlit(0);

    int gm = rge_base_game->game_mode;
    if ((gm >= 9 && gm <= 10) || gm == 0x13) {
        this->draw_paint_brush();
    }

    if (this->render_terrain_mode == 0) {
        this->Float_X_Delta = 0;
        this->Float_Y_Delta = 0;
        this->save_area1->SetFloatOffsets(0, 0);
        this->save_area1->PtrClear(&this->save_area1->ClipRect, 0);
    }

    this->draw_view(10, this->save_area1);
    this->render_terrain_mode = 1;
    this->vf2c();
    frame_count++;
}
