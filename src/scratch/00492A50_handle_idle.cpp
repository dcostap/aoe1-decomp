// VA: 00492A50 TRIBE_Credits_Screen::handle_idle
// Source: scr_cred.cpp lines 217-333
// Attempt log:
// 1: initial direct reconstruction from packet state machine.
// 2: fixed palette buffer to +0x890 and fade argument to use first palette dword; prologue and early state dispatch are close but rebuilt remains 608 bytes vs original 610.
// 3: remaining mismatch is localized early in state==1: rebuilt introduces EDI as palette pointer and has different zero-store/load scheduling; branch distances and later state blocks drift.
// 4: left in scratch; behavior is understood but size mismatch/broad scheduling drift are not accepted_drift-safe.

typedef unsigned long ulong;
struct PALETTEENTRY { unsigned char r,g,b,f; };

extern ulong __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(void* hpal, unsigned int start, unsigned int count, PALETTEENTRY* entries);
extern "C" void __cdecl RGE_fade_palette_start(void* draw, void* pal, float f, int a, void* b, int c, int d);
extern "C" int __cdecl RGE_fade_palette_step();

class TDrawArea { public: void GetPalette(PALETTEENTRY* p); };
class TDrawSystem { public: void Paint(void* r); };
class BasePanel { public: unsigned char gap[0x478]; unsigned char flag478; unsigned char flag479; };

class TRIBE_Credits_Screen {
public:
    void* vtbl;
    char gap_004[0x20 - 4];
    TDrawArea* draw_area;
    char gap_024[0x204 - 0x24];
    PALETTEENTRY* cur_pal;
    char gap_208[4];
    void* hpal;
    char gap_210[0x480 - 0x210];
    int campaign_no;
    ulong start_time;
    ulong wait_time;
    int state;
    char gap_490[0x890 - 0x490];
    PALETTEENTRY pal[256];
    char gap_C90[4];
    int use_special;

    int handle_idle();
    void set_dirty(int b);
    void calc_cur_line_col();
    int TPanel_handle_idle();
};

typedef void (*VirtBool)(TRIBE_Credits_Screen*, int);
typedef void (*VirtVoid)(TRIBE_Credits_Screen*);

int TRIBE_Credits_Screen::handle_idle()
{
    int state = this->state;
    if (state == 1) {
        if (this->start_time == 0) {
            goto set_time_f1;
        }
        if (debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0xF5) - this->start_time < 10000) {
            goto tail;
        }
        BasePanel* p = *(BasePanel**)this->draw_area;
        if (p->flag479 != 2 && p->flag478 != 1) {
            this->state = 4;
            goto tail;
        }
        this->state = 2;
        this->pal[0].r = 0;
        this->pal[0].g = 0;
        this->pal[0].b = 0;
        if (this->hpal == 0) this->draw_area->GetPalette(this->pal);
        else GetPaletteEntries(this->hpal, 0, 0x100, this->pal);
        RGE_fade_palette_start(this->draw_area, *(void**)&this->pal[0], 0.5f, 1, 0, 0xff, -1);
        goto tail;
    }
    if (state == 2) {
        if (!RGE_fade_palette_step()) goto tail;
        void* vt = *(void**)this;
        this->state = 4;
        this->wait_time = 0;
        (*(VirtBool*)((char*)vt + 0x20))(this, 1);
        (*(VirtVoid*)((char*)vt + 0x54))(this);
        (*(TDrawSystem**)this->draw_area)->Paint(0);
        goto tail;
    }
    if (state == 4) {
        if (this->wait_time == 0) {
            this->wait_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x11A);
            goto tail;
        }
        debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x11E);
        this->state = 5;
        ++this->campaign_no;
        if (this->campaign_no > 7) this->campaign_no = 1;
        this->cur_pal = (PALETTEENTRY*)*(int*)((char*)this + this->campaign_no * 4 + 0x890);
        void* vt = *(void**)this;
        (*(VirtBool*)((char*)vt + 0x20))(this, 1);
        (*(VirtVoid*)((char*)vt + 0x54))(this);
        (*(TDrawSystem**)this->draw_area)->Paint(0);
        BasePanel* p = *(BasePanel**)this->draw_area;
        if (p->flag479 != 2 && p->flag478 != 1) {
            this->state = 1;
            goto set_time_138;
        }
        RGE_fade_palette_start(this->draw_area, *(void**)&this->pal[0], 0.5f, 2, &this->pal[0], 0xff, -1);
        goto tail;
    }
    if (state == 5) {
        if (RGE_fade_palette_step()) {
            this->state = 1;
            goto set_time_142;
        }
    }
    goto tail;
set_time_f1:
    this->start_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0xF1);
    goto tail;
set_time_138:
    this->start_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x138);
    goto tail;
set_time_142:
    this->start_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x142);
tail:
    if (this->use_special) {
        this->calc_cur_line_col();
        return 1;
    }
    return this->TPanel_handle_idle();
}
