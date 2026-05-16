// VA: 0051FA90 Time_Line_Panel::draw_axis
// Attempt log:
// initial rough reconstruction from packet: draw locked axis rectangles, unlock, then draw optional labels/strings.
// tried IAT-style GetNearestPaletteIndex/SetBkColor/SetTextColor/DrawText surfaces.
// modeled draw-area palette at +0 and hdc at +0x38 after packet uses [draw+38h].
// modeled panel fields at +0x478/+0x47c/+0x480/+0x4dc/+0x4f4/+0x4f8, and helper calls xPosition/yPosition/textHeight/stringResource.
// rough FillRect argument order/coordinate expressions are approximate; first mismatch at offset 19 already shows wrong GetNearestPaletteIndex call surface (rebuilt pushes palette object, original loads vtable-ish [pal][+8]).
// manual string-length scans used to mirror original repne scasb for labels.
// current same-size 760B build has broad 76.3158% positional diff, not localized and not accepted_drift-safe.

extern "C" unsigned int (__stdcall* const GetNearestPaletteIndex)(void*, unsigned int);
extern "C" int (__stdcall* const SetBkColor)(void*, int);
extern "C" int (__stdcall* const SetTextColor)(void*, int);
extern "C" int (__stdcall* const DrawTextA)(void*, char*, int, int, int);

class TDrawArea { public:
    void* pal; char gap[0x34]; void* hdc;
    unsigned char* Lock(char*, int); void Unlock(char*); int IsLocked(char*); void FillRect(int,int,int,int); };
class Time_Line_Panel { public:
    char gap0[0x20]; TDrawArea* draw; char gap24[0x478-0x24]; int color; int char_w; int yoff; char gap484[0x4dc-0x484]; int center; char gap4e0[0x4f4-0x4e0]; int width; int xoff;
    int xPosition(int=0); int yPosition(int=0); int textHeight(); int stringResource(int,char*,int);
    void draw_axis();
};

void Time_Line_Panel::draw_axis()
{
    char temp[100];
    unsigned char white;
    white = (unsigned char)GetNearestPaletteIndex(this->draw->pal, 0xffffff);
    if (this->draw->Lock((char*)0x0058B788, 1)) {
        int y = this->yPosition(0);
        this->draw->FillRect(this->xPosition(y + this->yoff + this->char_w*2 + 13), this->yPosition(this->width + 24), this->xPosition(y + this->char_w*2 + this->xoff + 12), this->xPosition(0)+25);
        this->draw->FillRect(this->xPosition(y + this->char_w*2 + 14), this->xPosition(this->width + 24), this->yPosition(y + this->char_w*2 + 13), this->xPosition(0)+25);
        this->draw->FillRect(this->xPosition(y + this->yoff + this->char_w*2 + 13), this->yPosition(this->xPosition(y + this->char_w*2 + 13)+26), this->xPosition(this->yPosition(0)+this->char_w*2+13), this->xPosition(0)+25);
        this->draw->FillRect(this->xPosition(y + this->yoff + this->char_w*2 + 13), this->yPosition(this->width + 24), this->xPosition(y + this->char_w*2 + 13), this->yPosition(this->width + 23));
    }
    this->draw->Unlock((char*)0x0058B788);
    if (this->draw->IsLocked((char*)0x0058B788)) {
        SetBkColor(this->draw->hdc, 1);
        SetTextColor(this->draw->hdc, this->color);
        if (this->stringResource(0x2c57, temp, 100)) {
            int sx = this->xPosition() + 8;
            int sy = this->yPosition() + 5;
            SetTextColor(this->draw->hdc, 0xffffff);
            char* p=temp; while (*p) ++p;
            DrawTextA(this->draw->hdc, temp, p-temp, sx, sy);
        }
        if (this->stringResource(0x2c56, temp, 100)) {
            char* p=temp; while (*p) ++p;
            int sx = this->center + (this->width - (int)(p-temp)*this->char_w/2)/2;
            int sy = this->textHeight() + this->yPosition() - this->char_w - 5;
            SetTextColor(this->draw->hdc, 0xffffff);
            DrawTextA(this->draw->hdc, temp, p-temp, sx, sy);
        }
        SetTextColor(this->draw->hdc, white);
        this->draw->Unlock((char*)0x0058B788);
    }
}
