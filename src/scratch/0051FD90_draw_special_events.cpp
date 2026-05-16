// 0051FD90 Time_Line_Panel::draw_special_events
// Attempt log:
// initial natural switch/list reconstruction using TDrawArea surfaces and special event node offsets from packet.
// modeled early draw_events gate, palette calls, Lock/Unlock, first icon-pass switch, IsLocked gate, text color restore, and second event text drawing loop.
// first compile produced same configured size 674 but broad mismatch from entry: rebuilt starts with sub esp,10h and EBX=this, while original uses push ecx scratch slot and ESI=this; positional diff 533 / edit diff 564.
// fixed EventNode local scoping and function pointer surfaces enough to compile, but control/register basin remains far from original.
// remaining differences include wrong prologue/local allocation, switch layout, string-length/text positioning math, and incomplete event-case behavior for several types; not accepted_drift-safe.

extern "C" int strlen(const char*);
extern "C" void* GetNearestPaletteIndex;
extern "C" void* SetTextColor;
extern "C" void* SetBkColor;
extern "C" void* TextOutA;

typedef int (__stdcall *PFN2)(void*, int);
typedef int (__stdcall *PFN5)(void*, int, int, char*, int);

class TDrawArea {
public:
    void* vtbl;
    char gap_04[0x38-4];
    void* hdc;
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    int IsLocked(char*);
};

class EventNode {
public:
    int x; int y;
    char gap08[0x12-0x08];
    unsigned char type;
    char gap13[0x28-0x13];
    int draw_x;
    int draw_y;
    char gap30[0x38-0x30];
    int color;
    char text1[0x38];
    char text2[0x34];
    int flag_a8;
    EventNode* next;
};

class Time_Line_Panel {
public:
    char gap_000[0x20];
    TDrawArea* draw_area;
    char gap_024[0x47c-0x024];
    int char_w;
    int old_color;
    int color484;
    char gap_488[0x518-0x488];
    EventNode* events;
    unsigned char draw_events;

    void draw_icon(EventNode*, int, int);
    int text_width(char*, int);
    int font_height();
    void draw_special_events();
};

void Time_Line_Panel::draw_special_events()
{
    if (!this->draw_events) return;
    PFN2 pNearest = (PFN2)GetNearestPaletteIndex;
    pNearest(*(void***)this->draw_area[0].vtbl + 2, 0xffffff);
    pNearest(*(void***)this->draw_area[0].vtbl + 2, 0);

    if (this->draw_area->Lock((char*)0x58b79c, 1)) {
        EventNode* e = this->events;
        while (e) {
            switch (e->type) {
            case 0: this->draw_icon(e, -1, 0); break;
            case 1: this->draw_icon(e, -1, 1); break;
            case 2: this->draw_icon(e, -1, 2); break;
            case 3: this->draw_icon(e, -1, 3); break;
            case 4: this->draw_icon(e, 0, 4); break;
            case 5: this->draw_icon(e, 1, 5); break;
            case 6: this->draw_icon(e, 2, 6); break;
            case 7: this->draw_icon(e, 3, 7); break;
            case 8: this->draw_icon(e, 4, 8); break;
            }
            e = e->next;
        }
    }
    this->draw_area->Unlock((char*)0x58b79c);

    EventNode* e;
    if (!this->draw_area->IsLocked((char*)0x58b79c)) return;
    PFN2 setBk = (PFN2)SetBkColor;
    PFN2 setText = (PFN2)SetTextColor;
    PFN5 textOut = (PFN5)TextOutA;
    setBk(this->draw_area->hdc, 1);
    int old = setText(this->draw_area->hdc, this->color484);
    e = this->events;
    if (!e) goto done;
    do {
        switch (e->type) {
        case 0:
            setBk(this->draw_area->hdc, 0);
            textOut(this->draw_area->hdc, e->draw_x, e->draw_y, e->text1, e->color);
            break;
        case 1:
        case 2:
        case 3: {
            int base = e->x ? -2 : 2;
            setBk(this->draw_area->hdc, 0xffffff);
            int len = strlen(e->text1);
            int tw = this->text_width(e->text1, len);
            int x = e->y + base - (tw >> 1);
            textOut(this->draw_area->hdc, x, e->draw_y, e->text1, len);
            len = strlen(e->text2);
            int y = e->y + base - ((len >> 1) * this->char_w);
            int yy = e->draw_y + this->font_height() - 7 - (this->char_w << 1);
            textOut(this->draw_area->hdc, y, yy, e->text2, len);
            break;
        }
        case 4:
            if (e->flag_a8) { setBk(this->draw_area->hdc, 0); textOut(this->draw_area->hdc, e->draw_x, e->draw_y, e->text1, e->color); }
            break;
        case 5:
            if (e->flag_a8) { setBk(this->draw_area->hdc, 0); textOut(this->draw_area->hdc, e->draw_x, e->draw_y, e->text1, e->color); }
            break;
        }
        e = e->next;
    } while (e);
done:
    setText(this->draw_area->hdc, old);
    this->draw_area->Unlock((char*)0x58b79c);
}
