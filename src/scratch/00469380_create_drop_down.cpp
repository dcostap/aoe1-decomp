// 00469380 TEasy_Panel::create_drop_down
// Attempt log:
// 1: natural reconstruction from packet with EH/new ctor and TDropDownPanel member calls.
// 2: modeled scaled coordinate math exactly from asm: param*width/ideal_width and param*height/ideal_height, plus width*18/ideal_width.
// 3: modeled negative font id fallback to 10 and rge_base_game->get_font calls at both observed sites.
// 4: modeled calloc(1,4), calloc(0x14,1), copy of literal at 0x580460, and cleanup free loop.
// 5: modeled operator_new(0x144) + placement constructor; VC5 needed a local placement-new declaration to compile.
// 6: tried /GX response file because original has EH registration; no improvement, object .text still too short for extraction, removed flag.
// 7: modeled TDropDownPanel setup argument list in observed push order from decompiler/asm.
// 8: modeled optional set_buttons, set_bevel_info, val/list text color, highlight color, and val_panel virtual bevel call.
// 9: current source compiles but produced .text section only 736B vs configured/original 811B; check_function cannot diff rebuilt bytes.
// 10: left in scratch as blocker-like scratch give-up: source is structurally close but needs real EH/context/call surface to reach original size; not accepted_drift.
// 11: replaced the placement-new/byte-copy scaffolding with the natural new/
// strcpy surfaces and a virtual TPanel/TDropDownPanel ownership model; testing
// whether the real destructible type supplies the original EH state.
// 12: restored the binary-proven one-element do/while cleanup instead of
// hand-written if cleanup; the original retains a countdown and cursor.
// 13: route first calloc failure through the existing cleanup label; the
// original has one shared cleanup/SEH epilogue rather than an early return.
// 14: kept the ignored initial font lookup as two natural branch arms; this
// tests the original jl/push-font/jmp-call topology instead of a rewritten id.
// 15: inverted that equivalent guard so the nonnegative source arm remains
// inline and the negative fallback is the late branch target.
// 16: /GX plus the typed virtual/destructible surface recovered the original
// EH prologue, frame, call set, and body; the final stdlib-context check was
// neutral. Best current output is exact size with 21 strict bytes remaining:
// early leak exits target the result epilogue differently, and the final free
// cleanup schedules stack restoration before the failure/result load.
// 17: direct allocation-failure returns duplicated the EH epilogue and grew
// the function by 33 bytes; restored the shared leak exits.
// 18: a natural initialized result local also duplicated the epilogue and
// grew the frame; carrying the second calloc value had the same blocker.
// 19: negated and ternary failure predicates emitted the unchanged 21-byte
// tail; restored the clean == 0 spelling.
// 20: localized direct return after final free, suggested by the original
// delayed stack cleanup; emitted code was unchanged and the clean form remains authoritative.
// 21: split the cleanup success return from the early zero finish; /GX duplicated
// the EH epilogue and grew 33 bytes, so restored the shared finish.
// 22: a pointer result carrier emitted the same 844-byte basin; restored.
// 23: a comma return deferred the failure load past free but changed loop and
// argument scheduling and left sete after EH restore; restored.
// 24: an unsigned-byte result changed the frame to 0xC and emitted 837 bytes;
// restored.
// 25: a register-qualified result duplicated the 844-byte basin; restored.
// 26: reusing the list home as the result changed the null branch and emitted
// 826 bytes; restored. Clean source remains the best reconstruction.
// 27: decompiler-style result carrier with explicit zero on first calloc
// failure changed the early branch and emitted 815 bytes / 556-byte diff.
// 28: split carrier/list declarations produced the same codegen duplicate.
// 29: comma-wrapped final free moved cleanup-loop scheduling and emitted 813
// bytes / 70-byte diff; restored.
// 30: a late char* result carrier moved the failure load before stack cleanup,
// but spilled the setcc and emitted 819 bytes / 32-byte diff.
// 31: register-qualified late char* and late int carriers were duplicates.
// 32: split success return from the early finish duplicated EH cleanup and
// emitted 844 bytes / 607-byte diff; restored.
// 33: function-scope uninitialized int carrier duplicated the 32-byte basin.
// 34: function-scope char* carrier assigned directly from second calloc was
// a codegen duplicate of the clean 21-byte basin; restored.
// 35: direct return only on the second calloc failure grew the function by
// 17 bytes and duplicated the EH return path; restored the clean goto form.
// FLAGS: config\flags\00469380_create_drop_down.rsp

#include <string.h>
#include <stdlib.h>

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xd8-0x04];
    int failure;
    char gap_dc[0x18];
};
class TDrawArea;
class TShape;
class TListPanel { public: void set_text_color(unsigned long, unsigned long); void set_highlight_text_color(unsigned long, unsigned long); };
class RGE_Font { public: void* font; int font_wid; int font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;

class TTextPanel {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual void vf36(); virtual void vf37(); virtual void vf38(); virtual void vf39();
    virtual void vf40(); virtual void vf41(); virtual void vf42(); virtual void vf43();
    virtual void vf44(); virtual void vf45(); virtual void vf46(); virtual void vf47();
    virtual void vf48(); virtual void vf49(); virtual void vf50(); virtual void vf51();
    virtual void vf52(); virtual void vf53(); virtual void vf54(); virtual void vf55();
    virtual void vf56(); virtual void vf57(); virtual void vf58();
    virtual void set_bevel_info(int, int, int, int, int, int, int);
};
class TButtonPanel;
class TDropDownPanel : public TPanel {
public:
    virtual ~TDropDownPanel();
    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    char gap_0100[0x144-0x100];
    TDropDownPanel();
    long setup(TDrawArea*, TPanel*, void*, int, int, int, char, int, int, int, int, int, int, int, int, int, int, char*, int, int, char**, int, int, char*, char*, char*, char*, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_bevel_info(int,int,int,int,int,int,int);
    void set_val_text_color(unsigned long,unsigned long);
};

class TEasy_Panel {
public:
    char gap_00[0x14]; int width; int height; char gap_1c[4]; TDrawArea* draw_area; char gap_24[0xb4]; int failure;
    char gap_dc[0x18]; int ideal_width; int ideal_height; char gap_fc[0x220]; int use_bevels;
    unsigned char bevel_color1, bevel_color2, bevel_color3, bevel_color4, bevel_color5, bevel_color6;
    char gap_326[2]; unsigned long text_color1; unsigned long text_color2; unsigned long focus_color1; unsigned long focus_color2;
    char gap_338[0x110]; TShape* button_pics;
    int create_drop_down(TPanel*, TDropDownPanel**, long,long,long,long,long,long,long);
};

int TEasy_Panel::create_drop_down(TPanel* parent, TDropDownPanel** out, long x, long y, long sx, long sy, long sw, long sh, long font_id)
{
    long ix = sx * this->width / this->ideal_width;
    long iy = sy * this->height / this->ideal_height;
    long iw = sw * this->width / this->ideal_width;
    long ih = sh * this->height / this->ideal_height;
    long bh = (this->width * 18) / this->ideal_width;
    long px = x * this->width / this->ideal_width;
    long py = y * this->height / this->ideal_height;
    if (font_id >= 0)
        rge_base_game->get_font(font_id);
    else
        rge_base_game->get_font(10);
    char** list = (char**)calloc(1,4);
    if (list == 0) { this->failure = 1; goto finish; }
    list[0] = (char*)calloc(0x14,1);
    if (list[0] == 0) goto finish;
    // string literal at 580460 is " "
    strcpy(list[0], (const char*)0x580460);
    if (this->failure == 0) {
        TDropDownPanel* p = new TDropDownPanel;
        *out = p;
        if (p != 0 && p->failure == 0) {
            RGE_Font* font = rge_base_game->get_font(font_id);
            if ((*out)->setup(this->draw_area,parent,font->font,font->font_wid,font->font_hgt,0,0,1,0xff,ix,iy,iw,ih,0,0,bh,ih,0,px,py,list,1,bh,0,0,0,0,bh,bh)) {
                if (this->button_pics) (*out)->set_buttons(this->button_pics,0xe,-1,8,10,0xc);
                if (this->use_bevels) (*out)->set_bevel_info(3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                (*out)->set_val_text_color(text_color1,text_color2);
                TListPanel* lp = (*out)->list_panel;
                lp->set_text_color(text_color1,text_color2);
                lp->set_highlight_text_color(focus_color1,focus_color2);
                (*out)->val_panel->set_bevel_info(3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                goto cleanup;
            }
        }
        this->failure = 1;
    }
cleanup:
    {
        char** p = list;
        int count = 1;
        do {
            if (*p) { free(*p); *p = 0; }
            ++p;
            --count;
        } while (count != 0);
        free(list);
    }
finish:
    return this->failure == 0;
}
