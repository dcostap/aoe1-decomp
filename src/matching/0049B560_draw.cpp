// 0049B560 TRIBE_Screen_Game::draw
// Attempt log:
// initial direct reconstruction from asm: two branches on global mode, lock/draw/unlock around background/shape, save/restore clip rect.
// first build is same-size comparable (707/707) but broad mismatch: first mismatch at branch distance offset 0x10; rebuilt schedules vtable load/EBP and clip-rect local setup differently and then diverges through both large branches.
// behavior model includes global mode gate, vtable draw_background/draw_foreground, optional panel fill, 1024/768 vs 800/600 vs small background shape draws, clip rect restore, and alternate non-global path.
// tried natural virtual declarations and typed TDrawArea/TShape surfaces; calls and size are plausible but register/block topology remains broad (397 positional / 571 edit).
// left in scratch: not accepted_drift-safe due broad scheduling/register/control drift despite same size.
// bounded pass sa872fd63f: removed the duplicate explicit vptr and restored the
// inherited +28/+2c draw_setup/draw_finish slots; this fixed all 21 ordered
// calls, exact size/frame/CFG, and improved the first pass to 414 positional
// differing bytes.
// tried moving the clip copy before draw_setup with scalar locals; VC5 emitted
// a 708-byte function and broad drift, so restored it.
// typed the screen clip as tagRECT and modeled TPanel->TEasy_Panel->TScreenPanel
// ownership plus TPanel::render_rect at +8c; the natural aggregate save/restore
// gives a 707-byte, 96.67%-shape candidate with 90 edit-diff cost, but the
// FillRect argument loads remain a localized register/order mismatch.
// tried panel aliases, split pointer declaration, and four scalar argument
// locals; scalar locals moved the first prologue hunk and were rolled back.
// follow-up direct member expressions for FillRect loaded the render fields in
// the wrong order and grew the function by 14 bytes; rolled back.
// prior validated scratch reconstruction retained the typed inherited layout
// and aggregate clip save/restore; its remaining drift was localized to panel
// FillRect scheduling (558 strict bytes / 90 edit bytes, 707 vs 707).
// probe orch-49B560-a #1: copy panel->render_rect as a typed aggregate before
// FillRect, testing whether VC5 preserves the oracle's left-to-bottom load
// order while retaining bottom for the later clip comparison.
// exact: the typed aggregate copy reproduces all 707 bytes, calls, frame, and
// block topology without compiler-steering code.
// Named the three draw lock tags. The raw absolute string addresses were
// diagnostic data plumbing and are not part of the source model.

extern unsigned char byte_62C584;

static char s_scr_game_draw[] = "scr_game::draw";
static char s_scr_game_draw2[] = "scr_game::draw2";
static char s_scr_game_draw3[] = "scr_game::draw3";

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void* vtbl;
    char gap[0x20-4];
    void LockWindow(void* r);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void FillRect(long, long, long, long, unsigned char);
    void SetClipRect(tagRECT* r);
};
class TShape { public: unsigned char shape_draw(TDrawArea*, long, long, int, unsigned char, unsigned char*); };

class TPanel {
public:
    virtual ~TPanel();
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void draw_setup(int flag);
    virtual void draw_finish();
    virtual void draw();

    char gap_04[0x14-4];
    long width;
    long height;
    char gap_1c[0x20-0x1c];
    TDrawArea* area;
    tagRECT rect;
    char gap_34[0x38-0x34];
    int mode;
    char gap_3c[0x8c-0x3c];
    tagRECT render_rect;
    char gap_9c[0xf4-0x9c];
};

class TEasy_Panel : public TPanel {
public:
    char gap_f4[0x478-0xf4];
};

class TScreenPanel : public TEasy_Panel {
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* shape478;
    char gap_47c[0x4c0-0x47c];
    TPanel* panel4c0;

    void draw();
};

void TRIBE_Screen_Game::draw()
{
    if (byte_62C584) {
        tagRECT* r = &this->rect;
        tagRECT old = *r;
        this->draw_setup(0);
        if (this->panel4c0) {
            if (this->area->Lock(s_scr_game_draw, 1)) {
                TPanel* panel = this->panel4c0;
                tagRECT panel_rect = panel->render_rect;
                this->area->FillRect(panel_rect.left, panel_rect.top,
                                     panel_rect.right, panel_rect.bottom, 0x74);
                this->area->Unlock(s_scr_game_draw);
                if (this->rect.top < panel_rect.bottom)
                    this->rect.top = panel_rect.bottom;
                this->area->SetClipRect(r);
            }
        }
        if (this->shape478) {
            if (this->area->Lock(s_scr_game_draw2, 1)) {
                if (this->width >= 0x400 && this->height >= 0x300) {
                    this->shape478->shape_draw(this->area, 0, 0, 0, 0, 0);
                    this->shape478->shape_draw(this->area, 0, 0x282, 1, 0, 0);
                } else if (this->width >= 0x320 && this->height >= 0x258) {
                    this->shape478->shape_draw(this->area, 0, 0, 0, 0, 0);
                    this->shape478->shape_draw(this->area, 0, 0x1da, 1, 0, 0);
                } else {
                    this->shape478->shape_draw(this->area, 0, 0, 0, 0, 0);
                    this->shape478->shape_draw(this->area, 0, 0x162, 1, 0, 0);
                }
                this->area->Unlock(s_scr_game_draw2);
            }
        }
        this->draw_finish();
        *r = old;
        this->area->SetClipRect(r);
    } else {
        int flag;
        if (this->mode != 2 && this->shape478) flag = 0;
        else flag = 1;
        this->draw_setup(flag);
        if (this->shape478) {
            if (this->area->Lock(s_scr_game_draw3, 1)) {
                if (this->width >= 0x400 && this->height >= 0x300) {
                    this->shape478->shape_draw(this->area, 0, 0, 0, 0, 0);
                    this->shape478->shape_draw(this->area, 0, 0x282, 1, 0, 0);
                } else if (this->width >= 0x320 && this->height >= 0x258) {
                    this->shape478->shape_draw(this->area, 0, 0, 0, 0, 0);
                    this->shape478->shape_draw(this->area, 0, 0x1da, 1, 0, 0);
                } else {
                    this->shape478->shape_draw(this->area, 0, 0, 0, 0, 0);
                    this->shape478->shape_draw(this->area, 0, 0x162, 1, 0, 0);
                }
                this->area->Unlock(s_scr_game_draw3);
            }
        }
        this->draw_finish();
    }
}
