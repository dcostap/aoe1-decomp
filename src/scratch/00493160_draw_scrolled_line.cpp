// VA: 00493160 TScrollTextPanel::draw_scrolled_line
// Attempt log:
// initial reconstruction from packet: get two texts, calc rect, optional colors, draw modes 0/1/2 for primary and secondary text.
// tried Win32 lstrlenA declaration for text lengths; emitted call-based shorter text (624B), unlike original inline repne scasb.
// replaced with manual pointer scan; rebuilt grew to 640B but still much shorter than original 692B.
// modeled SetTextColor/SetBkMode/DrawText as IAT-style stdcall surfaces from packet call sites.
// modeled get_text/get_text2/calc_line_pos and key panel fields at observed offsets 0xf8/0x10c/0x114/0x11c/0x160/0x17c/0x188/0x194.
// tried switch over draw_mode 0/1/2 with duplicated primary/secondary branches; source still collapses too much and check stops before diff.
// left in scratch: behavior is approximate, but source is 52 bytes short and not accepted_drift-safe.

extern "C" int __stdcall SetTextColor(void*, int);
extern "C" int __stdcall SetBkMode(void*, int);
extern "C" int (__stdcall* const DrawTextA)(void*, const char*, int, void*, unsigned int);

struct RECT { int left, top, right, bottom; };
class TScrollTextPanel {
public:
    char gap0[0x10]; int clip_bottom; char gap14[4]; int base_y; char gap1c[0xd4]; short line_count;
    char gapfa[0x10c-0xfa]; int line_height; char gap110[4]; int align; char gap118[4]; int draw_mode;
    char gap120[0x160-0x120]; int scroll_y; char gap164[0x17c-0x164]; int text_color; char gap180[8]; int offset_y;
    char gap18c[8]; int done;
    char* get_text(short); char* get_text2(short); void calc_line_pos(void*, int, short, RECT*, int);
    void draw_scrolled_line(void*, int, short, unsigned long, unsigned long);
};

void TScrollTextPanel::draw_scrolled_line(void* hdc, int x, short line, unsigned long c1, unsigned long c2)
{
    RECT r;
    int len1 = 0, len2 = 0;
    char* t1;
    char* t2;
    short l = line;
    int y;
    t1 = get_text(l);
    t2 = get_text2(l);
    if (!t1 && !t2) return;
    if (t1) { char* p = t1; while (*p) ++p; len1 = p - t1; }
    if (t2) { char* q = t2; while (*q) ++q; len2 = q - t2; }
    calc_line_pos(hdc, x, l, &r, 0);
    y = r.top;
    if (this->align != 0 && this->align != 6) y += 5;
    y += this->scroll_y;
    r.top = y;
    r.left = this->base_y - this->offset_y + r.left;
    if (len1 == (short)(this->line_count - 1) && this->line_height + r.left < this->clip_bottom) this->done = 1;
    if (this->text_color) SetTextColor(hdc, this->text_color);
    switch (this->draw_mode) {
    case 0:
        SetBkMode(hdc, c2);
        if (t1) DrawTextA(hdc, t1, (short)len1, &r, 0);
        break;
    case 1:
        SetBkMode(hdc, c2);
        if (t1) DrawTextA(hdc, t1, (short)len1, &r, 0);
        SetBkMode(hdc, c1);
        if (t1) DrawTextA(hdc, t1, (short)len1, &r, 0);
        break;
    case 2:
        SetBkMode(hdc, c1);
        if (t1) DrawTextA(hdc, t1, (short)len1, &r, 0);
        SetBkMode(hdc, c2);
        if (t1) DrawTextA(hdc, t1, (short)len1, &r, 0);
        break;
    }
    if (t2) {
        if (this->text_color) SetTextColor(hdc, *(int*)((char*)this + 0x88));
        switch (this->draw_mode) {
        case 0:
            SetBkMode(hdc, c2);
            DrawTextA(hdc, t2, (short)len2, &r, 0);
            break;
        case 1:
            SetBkMode(hdc, c2);
            DrawTextA(hdc, t2, (short)len2, &r, 0);
            SetBkMode(hdc, c1);
            DrawTextA(hdc, t2, (short)len2, &r, 0);
            break;
        case 2:
            SetBkMode(hdc, c1);
            DrawTextA(hdc, t2, (short)len2, &r, 0);
            SetBkMode(hdc, c2);
            DrawTextA(hdc, t2, (short)len2, &r, 0);
            break;
        }
    }
}
