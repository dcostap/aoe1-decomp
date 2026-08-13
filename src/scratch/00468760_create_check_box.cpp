// VA: 00468760 TEasy_Panel::create_check_box
// Attempt log:
// natural reconstruction from packet; /GX required by original EH/new prologue.
// tried matching allocated TButtonPanel size; added tail pad so operator new uses 0x2b8.
// hypothesis 2: use the typed TDigital local, initialized before scaling, the real
// 10-argument setup ABI, *out for all post-construction calls, and one result/goto
// cleanup.  These are the donor-shaped ownership/control-flow forms suggested by
// the exact create_button family; checking whether they restore the EH frame and
// original call-site topology.
// probes: typed sound/frame + ABI correction improved 549->545; uninitialized
// scale locals restored the 0x8 frame and 114-byte positional diff.  Positive
// guard/if-else, operand-order, result-init, and declaration-initialized-x probes
// were codegen duplicates or worse.  Best clean source keeps named scaled locals,
// typed ownership, and the natural nested success/failure arms.
// probe 12: changed the typed success path to goto a shared failure tail, matching
// the oracle's success jump over one failure block; VC5 emitted identical code.
// left in scratch: original is 604 bytes vs rebuilt 623; calls, frame, and most
// body blocks align, but the early x-load/arithmetic scheduling and duplicated
// success/failure EH epilogues remain broad enough to block promotion.

class TPanel;
class TDrawArea;
class TDigital;
struct FontInfo { int a,b,c; };
class RGE_Base_Game { public: TDigital* get_sound(int); FontInfo* get_font(int); };
extern RGE_Base_Game* rge_base_game;
class TPanel {};
class TButtonPanel { public:
    char gap[0xd8]; int init_error; char tail[0x2b8-0xdc];
    TButtonPanel();
    long setup(TDrawArea*, TPanel*, long,long,long,long, int, TDigital*, int, long);
    void set_sound_number(long);
    void set_state_info(short);
    void setDrawType(int);
    void set_picture(short, void*, int);
    void set_text_info(char*, int,int,int,int,int);
    void set_text(short, char*);
    void set_bevel_info(int,int,int,int,int,int,int);
    void set_text_color(int,int,int);
    void set_highlight_text_color(int,int,int);
};
class TEasy_Panel { public:
    char gap0[0x14]; int screen_w; int screen_h; char gap1[4]; TDrawArea* draw_area;
    char gap2[0xd8-0x24]; int error_flag; char gap3[0xf4-0xdc]; int base_w; int base_h;
    char gap4[0x31c-0xfc]; int use_bevel; unsigned char bevel[6]; char gap5[2];
    int text0; int text1; int hi0; int hi1; int text2; int text3; char gap6[0x448-0x340]; void* picture;
    int create_check_box(TPanel*, TButtonPanel**, long,long,long,long,long,long);
};

int TEasy_Panel::create_check_box(TPanel* panel, TButtonPanel** out, long x, long y, long w, long h, long sound, long id)
{
    TDigital* snd;
    long sx;
    long sy;
    long sw;
    long sh;
    int result;

    snd = 0;
    sx = x * this->screen_w / this->base_w;
    sy = y * this->screen_h / this->base_h;
    sw = w * this->screen_w / this->base_w;
    sh = h * this->screen_h / this->base_h;
    TButtonPanel* b = new TButtonPanel;
    *out = b;
    if (*out != 0 && (*out)->init_error == 0) {
        if (sound >= 0) snd = rge_base_game->get_sound(sound);
        if ((*out)->setup(this->draw_area, panel, sx, sy, sw, sh, 6, snd, 1, id)) {
            (*out)->set_sound_number(sound);
            (*out)->set_state_info(2);
            if (this->picture) {
                (*out)->setDrawType(6);
                (*out)->set_picture(0, this->picture, 0);
                (*out)->set_picture(1, this->picture, 2);
            } else {
                FontInfo* f = rge_base_game->get_font(0);
                (*out)->set_text_info((char*)0x00580460, f->a, f->b, f->c, -1, -1);
                (*out)->set_text(1, (char*)0x00583B74);
                (*out)->setDrawType(3);
            }
            if (this->use_bevel) {
                (*out)->set_bevel_info(4, this->bevel[0], this->bevel[1], this->bevel[2], this->bevel[3], this->bevel[4], this->bevel[5]);
            }
            (*out)->set_text_color(0, this->text0, this->text1);
            (*out)->set_highlight_text_color(0, this->hi0, this->hi1);
            (*out)->set_text_color(1, this->text2, this->text3);
            (*out)->set_highlight_text_color(1, this->hi0, this->hi1);
            result = 1;
        } else {
            this->error_flag = 1;
            result = 0;
        }
    } else {
        this->error_flag = 1;
        result = 0;
    }
    return result;
}
