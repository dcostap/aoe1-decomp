// VA: 004696B0 TEasy_Panel::create_list
// Source: Panel_ez.cpp lines 1540-1610
// Attempt log:
// 1: initial reconstruction from packet/decompiler with /GX candidate EH for TListPanel construction cleanup.
// 2: switched placement-new to real `new TListPanel`; EH prologue appears but only one local slot and this in esi.
// 3: added explicit temp local and self register; worsened scheduling and did not produce sub esp,8/ebx=this, rolled back.
// 4: changed calloc call argument order to source `calloc(4,1)`; negligible edit improvement but original pushes 4 then 1, keep.
// 5: changed second calloc source to `calloc(1,0x14)`; no improvement, rolled back.
// 6: replaced manual empty-string copy with strcpy; positional worse and removes original rep movs, rolled back.
// 7: declared explicit operator new surface and used `new TListPanel`; EH appears but function remains 32 bytes short.
// 8: first allocation `calloc(4,1)` kept because it slightly improves edit diff and still allocates 4 bytes.
// 9: remaining first mismatch is EH handler address relocation area/prologue: rebuilt has EH but uses one local (`push ecx`) and this in esi; original has `sub esp,8`, this in ebx, and stores intermediate scaled values in stack slots.
// 10: left in scratch: behavior/calls mostly understood, but local/register allocation and cleanup/return layout remain broad; not accepted_drift-safe.

typedef unsigned long ulong;
typedef unsigned int uint;

extern "C" void* __cdecl calloc(uint count, uint size);
extern "C" void __cdecl free(void* p);
extern "C" void* __cdecl operator_new(uint size);

class RGE_Font { public: int font; int font_wid; int font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TPanel {};
class TDrawArea {};

class TTextPanel {
public:
    virtual void v0();
    char gap_04[0xD8 - 4];
    int error;
    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, int font, int font_wid, int font_hgt, char* text, int a, unsigned char b, int c, int d, int e, char** lines, int f);
    void set_text_color(ulong a, ulong b);
    void set_highlight_text_color(ulong a, ulong b);
};

class TListPanel : public TTextPanel {
public:
    TListPanel();
    void scroll_cur_line(unsigned char a, int b, unsigned char c);
};

class TEasy_Panel {
public:
    void* vtbl;
    char gap_004[0x14 - 0x04];
    int ideal_width;
    int ideal_height;
    TDrawArea* draw_area;
    char gap_024[0xD8 - 0x24];
    int error;
    char gap_0DC[0xF4 - 0xDC];
    int screen_width;
    int screen_height;
    char gap_0FC[0x31C - 0x0FC];
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[2];
    ulong text_color1;
    ulong text_color2;
    ulong focus_color1;
    ulong focus_color2;

    int create_list(TPanel* parent, TListPanel** out, long x, long y, long w, long h, long font_id);
};

typedef void (*BevelFn)(TListPanel*, int, int, int, int, int, int, int);

int TEasy_Panel::create_list(TPanel* parent, TListPanel** out, long x, long y, long w, long h, long font_id)
{
    long ideal_x;
    long ideal_y;
    char** list_items;

    ideal_x = (x * this->ideal_width) / this->screen_width;
    ideal_y = (y * this->ideal_height) / this->screen_height;
    w = (w * this->ideal_width) / this->screen_width;
    h = (h * this->ideal_height) / this->screen_height;

    int use_font = font_id;
    if (use_font < 0) {
        use_font = 10;
    }
    rge_base_game->get_font(use_font);

    list_items = (char**)calloc(4, 1);
    if (list_items == 0) {
        this->error = 1;
        return 0;
    }
    list_items[0] = (char*)calloc(0x14, 1);
    if (list_items[0] == 0) {
        goto cleanup_fail;
    }
    {
        char* dst = list_items[0];
        const char* src = "";
        while ((*dst++ = *src++) != 0) {}
    }

    if (this->error == 0) {
        TListPanel* list = new TListPanel;
        *out = list;
        if (list != 0 && list->error == 0) {
            RGE_Font* font = rge_base_game->get_font(font_id);
            if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, w, h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 1, 0xFF, 0, list_items, 1) != 0) {
                (*out)->scroll_cur_line(1, 0, 1);
                goto cleanup_success;
            }
        }
        this->error = 1;
    }

cleanup_success:
    {
        int n = 1;
        char** p = list_items;
        do {
            if (*p != 0) {
                free(*p);
                *p = 0;
            }
            ++p;
            --n;
        } while (n != 0);
    }
    free(list_items);
    if (this->use_bevels != 0) {
        TListPanel* list = *out;
        (*(BevelFn*)((char*)*(int*)list + 0xEC))(list, 3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
    }
    (*out)->set_text_color(this->text_color1, this->text_color2);
    (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    return 1;

cleanup_fail:
    return 0;
}
