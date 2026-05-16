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

class TPanel;
class TDrawArea;
class TShape;
class TListPanel { public: void set_text_color(unsigned long, unsigned long); void set_highlight_text_color(unsigned long, unsigned long); };
class RGE_Font { public: void* font; int font_wid; int font_hgt; };
class RGE_Base_Game { public: RGE_Font* get_font(int id); };
extern RGE_Base_Game* rge_base_game;
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
void* operator_new(unsigned int);
inline void* operator new(unsigned int, void* p) { return p; }

class TDropDownPanel {
public:
    char gap_00[4]; int f4; int f8; char gap_0c[0xd8-0x0c]; int failure; char gap_dc[0x20]; TListPanel* list_panel;
    TDropDownPanel();
    long setup(TDrawArea*, TPanel*, void*, int, int, int, char, int, int, int, int, int, int, int, int, int, int, char*, int, int, char**, int, int, char*, char*, char*, char*, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_bevel_info(int,int,int,int,int,int,int);
    void set_val_text_color(unsigned long,unsigned long);
};
#define VTBL(o) (*(void***)(o))
#define VPANEL_BEVEL(o,a,b,c,d,e,f,g) ((void (__cdecl*)(void*,int,int,int,int,int,int,int))VTBL(o)[0x3b])((o),(a),(b),(c),(d),(e),(f),(g))

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
    int fid = font_id;
    if (fid < 0) fid = 10;
    rge_base_game->get_font(fid);
    char** list = (char**)calloc(1,4);
    if (list == 0) { this->failure = 1; return 0; }
    list[0] = (char*)calloc(0x14,1);
    if (list[0] == 0) goto done;
    // string literal at 580460 is " "
    { char* d=list[0]; const char* s=(const char*)0x580460; do { *d++=*s; } while(*s++); }
    if (this->failure == 0) {
        TDropDownPanel* p = (TDropDownPanel*)operator_new(0x144);
        if (p != 0) p = new(p) TDropDownPanel();
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
                VPANEL_BEVEL((*(void**)((char*)(*out)+0xf4)),3,bevel_color1,bevel_color2,bevel_color3,bevel_color4,bevel_color5,bevel_color6);
                goto done;
            }
        }
        this->failure = 1;
    }
done:
    if (list) { if (list[0]) { free(list[0]); list[0]=0; } free(list); }
    return this->failure == 0;
}
