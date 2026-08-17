// VA: 00534AE0 RGE_View::draw (view.cpp:1324-1904, 1835 bytes, __thiscall virtual)
// Attempt log:
//   - Canonical ownership (from asm/PDB/donors 00533760, 0053A9C0, 004777C0):
//     RGE_View : TPanel (vptr@+0); render_area@+0x20; screen_w@+0x14, screen_h@+0x18;
//     world@+0xFC; start_scr_col/row@0x126/0x128, start_map_col/row@0x12A/0x12C;
//     map_scr_x/y_offset@0x130/0x134; render_terrain_mode(byte)@0x142;
//     TSpan_List_Manager* clip masks @0x178/0x17C/0x180;
//     Limited_Render_Rect@0x2A0, Use_Rect2@0x2A4, Render_Rect1@0x2A8, Render_Rect2@0x2B8;
//     Float_X/Y_Delta@0x2D0/0x2D4, Queued_Blits@0x2D8; save_area1@0x324; prior_objs@0x334.
//     TPanel virtuals: draw_setup(int)@slot0x28, draw_finish()@slot0x2C.
//     TDrawArea: Width@0x18, Height@0x1C, ClipRect@0x28, DisplayOffsets@0xBC.
//   - Globals: view_debug_redraw_all@0x87D7A4, view_debug_ObstructionMap@0x87D7A8,
//     view_debug_palette@0x87D7B0, frame_count@0x87D7B8, tiles_drawn@0x87D7BC,
//     MouseSystem@0x62E660, rge_base_game@0x62C574.
//   - Prior diagnostic variant with a false screen_w/screen_h write and duplicate
//     clipping was rejected: it is not executable-supported source. The retained
//     reconstruction has one natural clipping pass and never writes those members.
//   - Materializing `redraw_all = view_debug_redraw_all` before tiles_drawn recovered
//     the original global-load-before-frame/store schedule (1764B; frame remained
//     0x50). Keeping raw screen_width/screen_height locals from the initial rectangle
//     setup through the two directional clips restored the proven 0x54 frame and
//     reached 1792B / 67.7% shape / 1498 strict diff while retaining 26/26 calls.
//   - Narrow `short` dx/dy locals were tested and rolled back: they changed the frame
//     to 0x50 and reduced structural shape despite a smaller size gap. Reordering
//     snapshot/map-offset declarations was mostly codegen-neutral.
//   - Late final clipping reads were changed back to direct `this->screen_w` /
//     `this->screen_h` expressions, matching the binary's member rereads without
//     member writes. This retained 26/26 calls and frame 0x54, improved shape to
//     77.3% and resync similarity to 64.5% (1782B; 1501 strict diff); keep this
//     source-plausible candidate rather than the opaque metric-only variant.
//   - A named rge_base_game intermediate recovered the A1 global-load encoding but
//     did not improve whole-function structure, so it was rolled back. No volatility,
//     inline asm, fake stores, or opaque register-steering scaffolding is retained.
//   - Bounded pause: remaining structural drift is broad around VC5 register/local
//     liveness and clipping block layout; next lead is a focused natural-source
//     variant lab or full view.cpp TU context, not more false member writes.
//   - Session sa-3ce3c739-r1 (2026-08-06, 10+ probes): improved 1501 -> 1441 strict
//     (78.0% shape, -49B, frame 0x54, 26/26 calls; codegen-best diagnostic now 1441).
//     Retained changes (all natural, PDB/binary-supported):
//       * rounding tests spelled `dx <= 0` / `dy <= 0` instead of `dx < 1` ->
//         matches orig `test reg,reg; jg` form (was `cmp reg,1; jge`);
//       * clip_rect2 sub-if arms swapped to `if (clip_rect1.left != -1) {Use_Rect2/
//         Render_Rect2} else {Limited_Render_Rect/Render_Rect1}` -- PDB line map
//         (1765 test / 1768 else inline / 1773 if-arm out-of-line) proves this order;
//       * old_map_scr_x_offset declared BEFORE y -> VC5 spills map_scr_y_offset to
//         [esp+1Ch] like the original (was spilling x; 1484 -> 1444);
//       * snapshot declaration map_col-first -> original load order (1444 -> 1441).
//     Rejected/negative evidence:
//       * `short dx/dy` again collapses frame to 0x50 (map offsets both land in
//         callee-saved regs; the dedicated zero moves to ecx) -- binary proves 16-bit
//         dx/dy ops but the 0x54 frame needs the zero in edi with map_y spilled;
//         no source spelling found to reproduce that exact allocation.
//       * dy-before-dx computation order worsens (1643); rect declaration order and
//         snapshot declaration order are codegen-neutral; fuller TPanel/RGE_View
//         vtable/field surface (64 slots, virtual dtor, DispSel_List) is
//         codegen-duplicate -- the register basin is robust to TU class surface.
//     Current basin: zero register = esi (orig edi); start_map_col = bx (orig si);
//     map_y = [esp+1Ch] (orig same) but map_x = edi (orig ebx); dx/dy 32-bit in
//     ebx/eax (orig 16-bit dx/si); old_rect@[esp+54h]/clip_rect1@[esp+44h] slots
//     swapped vs orig; Render_Rect1 copy stays inline (orig out-of-line at 005351D1)
//     -> PtrClear2->Poll region +46B vs orig. These are one coherent allocator basin;
//     the remaining blocker is flipping zero-register choice, not more local shapes.
//   - BINARY NOTE: The original tests Float_X_Delta < 0 before the draw2 lock.
//     It skips that lock when the displacement is nonnegative but below Width.
//   - Session sa-7c437db9-r1: 21 meaningful probes reached the same allocator
//     basin. The best metric-only source is 1441 strict bytes but omits that
//     binary-proven guard. The retained source has 1471 strict bytes, 1792B,
//     frame 0x54, 26/26 calls, and 78.76% shape similarity.
//   - Tested and rejected: absolute global overlays, direct redraw tests, zero
//     locals, cold-copy gotos, snapshot permutations, narrow dx/dy types,
//     displacement aliases, lock flags, branch order, and sign spellings.
//   - Next lead: recover the original zero-register and rectangle-home colors
//     through full period view.cpp context. Do not add register-steering forms.
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
    virtual void set_overlapped_redraw();
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
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
    tagRECT clip_rect2;
    tagRECT new_rect;
    tagRECT old_rect;
    tagRECT clip_rect1;
    int redraw_all = view_debug_redraw_all;

    tiles_drawn = 0;
    if (redraw_all != 0) {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if (view_debug_ObstructionMap != 0 || view_debug_palette != 0) {
        this->render_terrain_mode = 0;
    }

    if (this->world == 0) {
        this->draw_setup(0);
        this->render_area->Clear(&this->clear_rect, this->clear_color);
        this->draw_finish();
        return;
    }

    short old_start_map_col = this->start_map_col;
    short old_start_map_row = this->start_map_row;
    short old_start_scr_col = this->start_scr_col;
    short old_start_scr_row = this->start_scr_row;
    this->Terrain_Clip_Mask->ResetAll();
    this->Terrain_Fog_Clip_Mask->ResetAll();
    this->Master_Clip_Mask->ResetAll();
    int old_map_scr_x_offset = this->map_scr_x_offset;
    int old_map_scr_y_offset = this->map_scr_y_offset;
    this->Use_Rect2 = 0;
    this->Limited_Render_Rect = 0;
    this->update();
    this->draw_setup(0);

    if (this->render_terrain_mode == 1) {
        if ((this->start_map_col == old_start_map_col && this->start_map_row == old_start_map_row) &&
            (this->start_scr_col == old_start_scr_col && this->start_scr_row == old_start_scr_row)) {
            goto label_done;
        }

        long dx = (short)this->map_scr_x_offset - old_map_scr_x_offset;
        long dy = (short)this->map_scr_y_offset - old_map_scr_y_offset;
        if (dx == 0 && dy == 0) goto label_done;

        int screen_width = this->screen_w;
        int screen_height = this->screen_h;

        new_rect.left = (int)dx;
        new_rect.top = (int)dy;
        old_rect.left = 0;
        old_rect.top = 0;
        old_rect.right = screen_width - 1;
        old_rect.bottom = screen_height - 1;
        new_rect.right = old_rect.right + new_rect.left;
        new_rect.bottom = old_rect.bottom + new_rect.top;

        if (new_rect.bottom < 0 || new_rect.right < 0 || old_rect.bottom < new_rect.top || old_rect.right < new_rect.left) {
            this->render_terrain_mode = 0;
            goto label_done;
        }

        if ((dx & 7) != 0) {
            long t = dx;
            if (dx <= 0) t = dx + 7;
            long a = (t & ~7) - dx;
            dx += a;
            this->map_scr_x_offset += a;
        }
        if ((dy & 7) != 0) {
            long t = dy;
            if (dy <= 0) t = dy + 7;
            long a = (t & ~7) - dy;
            dy += a;
            this->map_scr_y_offset += a;
        }

        if (dx < 0) {
            old_rect.left = 0;
            old_rect.right = (int)dx + screen_width - 1;
            new_rect.left = -(int)dx;
        } else {
            old_rect.left = (int)dx;
            old_rect.right = screen_width - 1;
            new_rect.left = 0;
            screen_width = screen_width - old_rect.left;
        }
        new_rect.right = screen_width - 1;

        if (dy < 0) {
            old_rect.top = 0;
            old_rect.bottom = (int)dy + screen_height - 1;
            new_rect.top = -(int)dy;
        } else {
            old_rect.top = (int)dy;
            old_rect.bottom = screen_height - 1;
            new_rect.top = 0;
            screen_height = screen_height - old_rect.top;
        }
        new_rect.bottom = screen_height - 1;

        int xd = (int)dx;
        int yd = (int)dy;

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
            if (fxd < 0 && this->save_area1->Lock("view::draw2", 1) != 0) {
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

        if ((new_rect.left == 0) && (new_rect.right == this->screen_w - 1)) {
            clip_rect1.left = -1;
            if ((new_rect.top == 0) && (new_rect.bottom == this->screen_h - 1)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = 0;
                clip_rect2.right = this->screen_w - 1;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.bottom = this->screen_h - 1;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.bottom = new_rect.top - 1;
                }
            }
        } else if (new_rect.left == 0) {
            clip_rect1.right = this->screen_w - 1;
            clip_rect1.left = new_rect.right + 1;
            clip_rect1.bottom = this->screen_h - 1;
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
            clip_rect1.bottom = this->screen_h - 1;
            clip_rect1.left = 0;
            clip_rect1.top = 0;
            if ((new_rect.top == 0) && (new_rect.bottom == clip_rect1.bottom)) {
                clip_rect2.left = -1;
            } else {
                clip_rect2.left = new_rect.left;
                if (new_rect.top == 0) {
                    clip_rect2.top = new_rect.bottom + 1;
                    clip_rect2.right = this->screen_w - 1;
                    clip_rect2.bottom = clip_rect1.bottom;
                } else {
                    clip_rect2.top = 0;
                    clip_rect2.right = this->screen_w - 1;
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
            if (clip_rect1.left != -1) {
                this->Use_Rect2 = 1;
                this->Render_Rect2 = clip_rect2;
            } else {
                this->Limited_Render_Rect = 1;
                this->Render_Rect1 = clip_rect2;
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
    this->draw_finish();
    frame_count++;
}
