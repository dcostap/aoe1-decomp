// 0049B560 TRIBE_Screen_Game::draw
// Attempt log:
// initial direct reconstruction from asm: two branches on global mode, lock/draw/unlock around background/shape, save/restore clip rect.
// first build is same-size comparable (707/707) but broad mismatch: first mismatch at branch distance offset 0x10; rebuilt schedules vtable load/EBP and clip-rect local setup differently and then diverges through both large branches.
// behavior model includes global mode gate, vtable draw_background/draw_foreground, optional panel fill, 1024/768 vs 800/600 vs small background shape draws, clip rect restore, and alternate non-global path.
// tried natural virtual declarations and typed TDrawArea/TShape surfaces; calls and size are plausible but register/block topology remains broad (397 positional / 571 edit).
// left in scratch: not accepted_drift-safe due broad scheduling/register/control drift despite same size.

extern unsigned char byte_62C584;

class TDrawArea {
public:
    void* vtbl;
    char gap[0x20-4];
    void LockWindow(void* r);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void FillRect(long, long, long, long, unsigned char);
    void SetClipRect(void* r);
};
class TShape { public: unsigned char shape_draw(TDrawArea*, long, long, int, unsigned char, unsigned char*); };

class TRIBE_Screen_Game {
public:
    void* vtbl;
    char gap_04[0x14-4];
    int width;
    int height;
    char gap_1c[0x20-0x1c];
    TDrawArea* area;
    int rect[4];
    char gap_34[0x38-0x34];
    int mode;
    char gap_3c[0x478-0x3c];
    TShape* shape478;
    char gap_47c[0x4c0-0x47c];
    void* panel4c0;

    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void draw_background(int flag);
    virtual void draw_foreground();
    void draw();
};

void TRIBE_Screen_Game::draw()
{
    if (byte_62C584) {
        int old[4];
        int* r = this->rect;
        this->draw_background(0);
        old[0] = r[0]; old[1] = r[1]; old[2] = r[2]; old[3] = r[3];
        if (this->panel4c0) {
            if (this->area->Lock((char*)0x58653c, 1)) {
                int* pr = (int*)((char*)this->panel4c0 + 0x8c);
                this->area->FillRect(pr[0], pr[1], pr[2], pr[3], 0x74);
                this->area->Unlock((char*)0x58653c);
                if (this->rect[1] < pr[3]) this->rect[1] = pr[3];
                this->area->SetClipRect(r);
            }
        }
        if (this->shape478) {
            if (this->area->Lock((char*)0x58652c, 1)) {
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
                this->area->Unlock((char*)0x58652c);
            }
        }
        this->draw_foreground();
        r[0] = old[0]; r[1] = old[1]; r[2] = old[2]; r[3] = old[3];
        this->area->SetClipRect(r);
    } else {
        int flag;
        if (this->mode != 2 && this->shape478) flag = 0;
        else flag = 1;
        this->draw_background(flag);
        if (this->shape478) {
            if (this->area->Lock((char*)0x58651c, 1)) {
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
                this->area->Unlock((char*)0x58651c);
            }
        }
        this->draw_foreground();
    }
}
