// VA: 00468760 TEasy_Panel::create_check_box
// Attempt log:
// natural reconstruction from packet; /GX required by original EH/new prologue.
// tried matching allocated TButtonPanel size; added tail pad so operator new uses 0x2b8.
// tried initializing sound local to encourage the original two-local EH frame; rebuilt still uses push ecx/one-slot style instead of sub esp,8.
// current mismatch is broad from prologue offset 21: original `sub esp,8` frame, rebuilt `push ecx` and different local/constructor-result basin.
// left in scratch: behavior mostly modeled, but not accepted_drift-safe due broad frame/register/layout mismatch.

struct FontInfo { int a,b,c; };
class RGE_Base_Game { public: void* get_sound(int); FontInfo* get_font(int); };
extern RGE_Base_Game* rge_base_game;
class TPanel{};
class TButtonPanel { public:
    char gap[0xd8]; int init_error; char tail[0x2b8-0xdc];
    TButtonPanel();
    long setup(void*, long,long,long,long,long, void*, int, TPanel*, int, long);
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
    char gap0[0x14]; int screen_w; int screen_h; char gap1[4]; void* draw_area;
    char gap2[0xd8-0x24]; int error_flag; char gap3[0xf4-0xdc]; int base_w; int base_h;
    char gap4[0x31c-0xfc]; int use_bevel; unsigned char bevel[6]; char gap5[2];
    int text0; int text1; int hi0; int hi1; int text2; int text3; char gap6[0x448-0x340]; void* picture;
    int create_check_box(TPanel*, TButtonPanel**, long,long,long,long,long,long);
};

int TEasy_Panel::create_check_box(TPanel* panel, TButtonPanel** out, long x, long y, long w, long h, long sound, long id)
{
    void* snd = 0;
    long sx = x * this->screen_w / this->base_w;
    long sy = y * this->screen_h / this->base_h;
    long sw = w * this->screen_w / this->base_w;
    long sh = h * this->screen_h / this->base_h;
    TButtonPanel* b = new TButtonPanel;
    *out = b;
    if (b == 0 || b->init_error != 0) goto fail;
    if (sound >= 0) snd = rge_base_game->get_sound(sound); else snd = 0;
    if (!b->setup(this->draw_area, sx, sy, sw, sh, 6, snd, 1, panel, 1, id)) goto fail;
    b->set_sound_number(sound);
    b->set_state_info(2);
    if (this->picture) {
        b->setDrawType(6);
        b->set_picture(0, this->picture, 0);
        b->set_picture(1, this->picture, 2);
    } else {
        FontInfo* f = rge_base_game->get_font(0);
        b->set_text_info((char*)0x00580460, f->a, f->b, f->c, -1, -1);
        b->set_text(1, (char*)0x00583B74);
        b->setDrawType(3);
    }
    if (this->use_bevel) {
        b->set_bevel_info(4, this->bevel[0], this->bevel[1], this->bevel[2], this->bevel[3], this->bevel[4], this->bevel[5]);
    }
    b->set_text_color(0, this->text0, this->text1);
    b->set_highlight_text_color(0, this->hi0, this->hi1);
    b->set_text_color(1, this->text2, this->text3);
    b->set_highlight_text_color(1, this->hi0, this->hi1);
    return 1;
fail:
    this->error_flag = 1;
    return 0;
}
