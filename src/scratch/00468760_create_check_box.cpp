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
// probe 14: keep the first coordinate as a named initialized local before scaling;
// VC5 emitted the clean-source code unchanged.
// probe 15: move sound initialization into its declaration, testing the oracle's
// early zero store before the coordinate loads; VC5 emitted the same code.
// probe 16: initialize one result and apply the error flag after the guarded
// success body, matching the oracle's single shared failure/return tail; this
// expanded the frame and moved the body, so it is rolled back.
// probe 17: use one uninitialized result with a single post-guard failure arm,
// matching the original's success jump over its shared failure block; VC5 emitted
// the clean code unchanged.
// probe 18: diagnostic only; force an x home with volatile storage to test whether
// the early parameter load is the sole remaining prologue cause; it worsened the
// frame-body alignment and was rolled back.
// probe 19: model the original protected virtual method surface, testing whether
// the class context changes VC5's early register schedule; it worsened block
// alignment and was rolled back.
// probe 20: declare the button object with the other long-lived locals, matching
// the original decompiler/PDB local ordering before its later allocation; this is
// a codegen duplicate and remains as a plausible source form.
// probe 22: explicit early-failure label with direct success/failure returns;
// VC5 emitted the clean code unchanged.
// probe 23: direct returns in the nested positive guards; VC5 emitted the clean
// code unchanged and retained two return paths.
// probe 24: declaration-initialize all scaled coordinates; this removed the EH
// frame and expanded the positional diff to 545, so it was rolled back.
// probe 26: named screen/base field locals; this added a slot and expanded the
// positional diff to 542, so it was rolled back.
// probe 28: inline scaled coordinates at setup; this moved allocation and body
// structure and expanded the positional diff to 525, so it was rolled back.
// probe 30: reuse incoming y/w/h parameter homes for scaled coordinates; this
// removed the frame and expanded the positional diff to 578, so it was rolled back.
// probe 32: add the virtual method surface with a compensating vptr gap; field
// offsets remain proven and VC5 emitted the clean code unchanged. Retained.
// probe 33: use the constructor result local in the validity guard; VC5 emitted
// the same bytes. Retained as the decompiler-supported ownership form.
// - Normalized the living source to direct success and failure returns. The
//   shared-result goto was a codegen diagnostic and is not retained.
// left in scratch: original is 604 bytes vs rebuilt 623; calls, frame, and most
// body blocks align, but the pre-save x-load/arithmetic schedule and the shared
// success/failure EH tail block remain structurally unresolved.

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
    char gap0[0x10];
    int screen_w; int screen_h; char gap1[4]; TDrawArea* draw_area;
    char gap2[0xd8-0x24]; int error_flag; char gap3[0xf4-0xdc]; int base_w; int base_h;
    char gap4[0x31c-0xfc]; int use_bevel; unsigned char bevel[6]; char gap5[2];
    int text0; int text1; int hi0; int hi1; int text2; int text3; char gap6[0x448-0x340]; void* picture;
    virtual int create_check_box(TPanel*, TButtonPanel**, long,long,long,long,long,long);
};

int TEasy_Panel::create_check_box(TPanel* panel, TButtonPanel** out, long x, long y, long w, long h, long sound, long id)
{
    TButtonPanel* b;
    TDigital* snd;
    long sx;
    long sy;
    long sw;
    long sh;

    snd = 0;
    sx = x * this->screen_w / this->base_w;
    sy = y * this->screen_h / this->base_h;
    sw = w * this->screen_w / this->base_w;
    sh = h * this->screen_h / this->base_h;
    b = new TButtonPanel;
    *out = b;
    if (b != 0 && b->init_error == 0) {
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
            return 1;
        }
    }
    this->error_flag = 1;
    return 0;
}
