// TRIBE_Mission_Screen::draw
// VA: 004B88E0
// PDB: scr_vc.cpp:236-260
// Attempt log:
// - baseline: reconstructed the draw path with typed TScreenPanel geometry and
//   natural Clear/Lock/Draw/Unlock calls; size/calls matched but the resolution
//   argument setup differed.
// - control-flow: kept the Draw operation in each resolution arm, allowing VC5
//   to tail-merge the common call while retaining the original branch-local
//   argument pushes; exact match.
// - layout: replaced the initial flat screen stub with the proven TPanel ->
//   TEasy_Panel -> TScreenPanel ownership and exact base/derived offsets; exact
//   output was preserved. Current source is the canonical candidate.
// FLAGS: default.rsp (/nologo /c /O2 /Oy)

#ifdef SCR_VC_CONTEXT_GROUP
#include "../../include/scr_vc_context.h"
#else
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void Clear(tagRECT* rect, int color);
    unsigned char* Lock(char* name, int wait);
    void Unlock(char* name);
};

class TPicture {
public:
    void Draw(TDrawArea* draw_area, long x, long y, int dst_x, int dst_y);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* draw_area, TPanel* parent,
                       long x, long y, long width, long height,
                       unsigned char flags);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(int mode, long x, long y, long width,
                                 long height, long a, long b, long c,
                                 long d, TPanel* p1, TPanel* p2,
                                 TPanel* p3, TPanel* p4);
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* first, TPanel* second, int mode);
    virtual void draw_setup(int value);
    virtual void draw_finish();
    virtual void draw();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    char gap_3C[0xB8];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x360];
    unsigned char background_color1;
    char gap_455[0x23];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual void draw();
};

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    char gap_478[0x20];
    TPicture* vc_back_bmp;

    virtual void draw();
};
#endif

void TRIBE_Mission_Screen::draw()
{
    TScreenPanel::draw();

    if (this->vc_back_bmp != 0) {
        this->draw_setup(0);

        if (this->need_redraw == 2)
            this->render_area->Clear(&this->clip_rect, this->background_color1);

        unsigned char* locked = this->render_area->Lock((char*)"scr_vc::draw", 1);
        if (locked != 0) {
            if (this->pnl_wid <= 0x280) {
                this->vc_back_bmp->Draw(this->render_area,
                                        this->pnl_x + 7,
                                        this->pnl_y + 0xA6, 0, 0);
            }
            else if (this->pnl_wid <= 0x320) {
                this->vc_back_bmp->Draw(this->render_area,
                                        this->pnl_x + 0x53,
                                        this->pnl_y + 0x118, 0, 0);
            }
            else {
                this->vc_back_bmp->Draw(this->render_area,
                                        this->pnl_x + 0xC5,
                                        this->pnl_y + 0x16B, 0, 0);
            }
            this->render_area->Unlock((char*)"scr_vc::draw");
        }

        this->draw_finish();
    }
}
