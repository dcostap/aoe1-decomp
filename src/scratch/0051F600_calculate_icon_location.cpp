// 0051F600 Time_Line_Panel::calculate_icon_location
// Attempt log:
// try 1: packet-grounded reconstruction from asm. Models shape availability/bounds validation, icon-mode switch, text-width computations, viewport clamping, and final output rect/valid flag.
// try 2: modeled initial valid flag, output visible reset at +0xa8, and temp x/y/right locals.
// try 3: modeled icon shape existence, shape_count nonzero, shape_count >= icon index, and shape_bounds width/height refresh into +0x4d8/+0x4da.
// try 4: modeled icon height vs event h and centered x bounds against panel left/width.
// try 5: modeled start_x = event x - icon_w/2 and start_y = event y*2 + event h/2 - icon_h/2.
// try 6: modeled mode switch on event byte +0x12 with default falling to final stores.
// try 7: modeled strlen-like text length into event +0x38 and text start at +0x3c.
// try 8: modeled modes 0/1/2 horizontal text placement using char_w at +0x488 and left/width clamp constants -3/-8 and +2.
// try 9: modeled vertical text placement using char_h at +0x48c and top/height clamps.
// try 10: modeled modes 3/4 and 5/6 text length truncation by viewport width, capped to 2 or 5, and bottom clamp with icon_h.
// Current validation: exact configured size 1036 but broad mismatch (87.5483% positional / 111.2934% edit). First mismatch is prologue/local topology: original uses 0x14 frame and loads event into EBX before saving EBP/ESI/EDI, rebuilt uses 0x10 frame and different saved-register/param order.
// GIVEUP blockers: exact Special_Event field layout, real source grouping for mode switch cases 0..8, local slot order for valid/start_x/start_y/right/height, and preserving original EBX event + EDI zero + EBP icon register allocation. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;
extern "C" unsigned int __cdecl strlen(const char*);

class TShape { public: int shape_count(); byte shape_bounds(long, short*, short*); };
struct Special_Event {
    char gap00[4]; int x; int y; int h; char gap10[2]; byte mode; char gap13[0x25]; int text_len; char text[0x6c]; int visible;
};
class Time_Line_Panel {
public:
    char gap00[0x488]; int char_w; int char_h; char gap490[0x44]; TShape* icon_shape; short icon_w; short icon_h; int left; int top; int width; int height;
    int calculate_icon_location(Special_Event* ev, short icon);
};

static int half(int v) { return (v - (v >> 31)) >> 1; }
static int text_len(Special_Event* ev) { int n = 0; char* p = ev->text; while (*p++) ++n; return n; }

int Time_Line_Panel::calculate_icon_location(Special_Event* ev, short icon)
{
    int ok = 1;
    int out_x = 0;
    int out_y = 0;
    int start_x = 0;
    int start_y = 0;
    int right = 0;
    ev->visible = 0;
    if (this->icon_shape == 0) ok = 0;
    if (this->icon_shape->shape_count() == 0) ok = 0;
    if (this->icon_shape->shape_count() < (int)icon) ok = 0;
    if (ok) {
        short w = 0, h = 0;
        this->icon_shape->shape_bounds(icon, &w, &h);
        if (w > 0) this->icon_w = w;
        if (h > 0) this->icon_h = h;
    }
    if (ok) {
        if ((int)this->icon_h > ev->h) ok = 0;
        int hw = half((int)this->icon_w);
        int x = ev->x;
        if (x + hw > this->left + this->width) ok = 0;
        if (x - hw < this->left) ok = 0;
        if (ok) {
            start_x = x - hw;
            start_y = ev->y * 2 + half(ev->h) - half((int)this->icon_h);
        }
    }

    switch (ev->mode) {
    case 0: {
        int len = text_len(ev); ev->text_len = len;
        int textw = this->char_w * len;
        if (ev->x + textw + 2 >= this->left + this->width) out_x = this->left + this->width - textw - 3;
        else out_x = ev->x + 2;
        int y = ev->y + ev->h - this->char_h - 2;
        if (y <= this->top) right = this->top + 2;
        else if (y >= this->top + this->height) right = this->top + this->height - this->char_h - 3;
        else right = y;
        out_y = right;
        break;
    }
    case 1: {
        int len = text_len(ev); ev->text_len = len;
        int textw = this->char_w * len;
        if (ev->x + textw + 2 >= this->left + this->width) out_x = this->left + this->width - textw - 8;
        else out_x = ev->x + 2;
        int y = ev->y + 2;
        if (y + this->char_h + 2 >= this->top + this->height) right = this->top + this->height - this->char_h - 2;
        else right = y;
        out_y = right;
        break;
    }
    case 2: {
        int len = text_len(ev); ev->text_len = len;
        int textw = this->char_w * len;
        int x;
        if (ev->x + textw + 2 >= this->left + this->width) x = this->left + this->width - textw - 3;
        else x = ev->x + 2;
        out_x = x;
        int y = ev->y + ev->h - this->char_h - 2;
        if (y <= this->top) right = this->top + 2;
        else if (y >= this->top + this->height) right = this->top + this->height - this->char_h - 3;
        else right = y;
        out_y = right;
        break;
    }
    case 3:
    case 4: {
        int maxx = this->left + this->width;
        int n = text_len(ev);
        int textw = n * this->char_w;
        if (ev->x + textw > maxx) ev->text_len = (maxx - ev->x) / this->char_w;
        else ev->text_len = n;
        if (ev->text_len > 2) ev->text_len = 2;
        int yend = start_y + this->top + this->icon_h + 1;
        if (yend > this->top + this->height) out_y = this->top + this->height - this->icon_h - 1;
        else out_y = start_y;
        out_x = start_x;
        right = out_y + this->icon_h + 1;
        break;
    }
    case 5:
    case 6: {
        int maxx = this->left + this->width;
        int n = text_len(ev);
        int textw = n * this->char_w;
        if (ev->x + textw > maxx) ev->text_len = (maxx - ev->x) / this->char_w;
        else ev->text_len = n;
        if (ev->text_len > 5) ev->text_len = 5;
        int yend = start_y + this->top + this->icon_h + 1;
        if (yend > this->top + this->height) out_y = this->top + this->height - this->icon_h - 1;
        else out_y = start_y;
        out_x = start_x;
        right = out_y + this->icon_h + 1;
        break;
    }
    default:
        break;
    }
    ev->x = out_x;
    ev->y = out_y;
    ev->h = right;
    ev->visible = ok ? 1 : 0;
    return ok;
}
