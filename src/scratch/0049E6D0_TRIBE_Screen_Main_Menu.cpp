// VA: 0049E6D0 TRIBE_Screen_Main_Menu ctor (1281B)
// Scr_main.cpp lines 85-193
// EH-framed constructor
// Attempt log:
// - Baseline reconstruction restores the period TPanel/TEasy/TScreenPanel
//   ownership, 0xF4/0x478 base boundaries, five-button setup loop, text
//   layout branches, picture panel, and final tab/child wiring.
// - Restored the four-argument virtual fixed-position calls from the original;
//   call count/order is now 44/44 and all three height/width/y-position call
//   families are present.
// - Matched the EH frame (0x230), setup guard, pointer-clearing loop, reused
//   panel-height local, member-owned picture lifetime, and pointer-copy tab
//   list.  The remaining drift is compiler register/address scheduling: the
//   rebuilt button-base/zeroing basin does not retain the original EBX/EAX
//   coloring and the constructor remains 10 bytes short.
// - Left in scratch after the bounded VC5 pass; no inline asm or codegen-only
//   volatile/offset scaffolding was retained.
// FLAGS: /GX (EH)

#include <string.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
typedef tagRECT RECT;

class TDrawArea;
class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* area, TPanel* parent, long x, long y,
                       long w, long h, unsigned char mode);
    virtual void set_rect(RECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(int mode, long p2, long p3, long p4,
                                 long p5, long p6, long p7, long p8,
                                 long p9, TPanel* p10, TPanel* p11,
                                 TPanel* p12, TPanel* p13);
    virtual void set_fixed_position(long x, long y, long right, long bottom);

    char gap_04[0x8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x4];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int field_D8;
    char gap_DC[0x18];

    int get_string(int id, char* buffer, int length);
    char* get_string(int id);
    long xPosition();
    long yPosition();
    long width();
    long height();
    void set_tab_order(TPanel** panels, short count);
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    int get_text_rect(RECT* rect);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    void set_text(short state, long string_id);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();

    void set_ideal_size(long width, long height);
    int create_button(TPanel* parent, TButtonPanel** output,
                      char* text, long x, long y, long width, long height,
                      long font, long sound, long user, long flags);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height, long font,
                    long align, long center, long wrap);
    int create_text(TPanel* parent, TTextPanel** output, char* text,
                    long x, long y, long width, long height, long font,
                    long align, long center, long wrap);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, char* info, long id, long value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

extern RGE_Base_Game* rge_base_game;

class TPicturePanel : public TPanel {
public:
    char pic_name[12];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    void* pic;
    void* shape;

    virtual ~TPicturePanel();
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, char* name, long id, int size_from_pic,
               int keep_loaded);
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TTextPanel* title1;
    TTextPanel* title2;
    TButtonPanel* button[7];
    TTextPanel* ms_title_text;
    TTextPanel* ms_copy_text1;
    TTextPanel* ms_copy_text2;
    TTextPanel* warning_text;
    TPicturePanel* circle_p_pic;

    TRIBE_Screen_Main_Menu();
    virtual ~TRIBE_Screen_Main_Menu();
};

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu()
    : TScreenPanel("Main Menu") {
    RECT rect;
    TPanel* tab_list[5];
    char temp_str[0x200];
    int diff;
    int i;
    TButtonPanel** const button_base = this->button;
    TButtonPanel** clear_button = button_base;

    this->title1 = 0;
    this->title2 = 0;
    this->circle_p_pic = 0;
    this->ms_title_text = 0;
    this->ms_copy_text1 = 0;
    this->ms_copy_text2 = 0;
    this->warning_text = 0;

    for (i = 7; i != 0; --i) {
        *clear_button++ = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr1", 0xC383, 1) == 0) {
        this->field_D8 = 1;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    clear_button = button_base;
    for (long button_width = 0xB2; button_width < 0x1AC;
         button_width += 0x32, ++clear_button) {
        if (this->create_button(this, clear_button, "", 0, 0xAA,
                                button_width, 0x12C, 0x28, 0, 0, 0) == 0) {
            return;
        }
    }

    this->button[0]->set_text(0, 0x23F2);
    this->button[1]->set_text(0, 0x23F3);
    this->button[2]->set_text(0, 0x23F5);
    this->button[3]->set_text(0, 0x23F6);
    this->button[4]->set_text(0, 0x23F7);

    this->set_ideal_size(this->pnl_wid, this->pnl_hgt);

    long panel_height = this->pnl_hgt;
    this->create_text(this, &this->ms_title_text, 0x2419, 5,
                      panel_height - 0x3C, this->pnl_wid - 0x0A,
                      0x12, 10, 1, 0, 0);

    this->get_string(0x2424, temp_str + 4, 0x200);
    if (temp_str[4] == 0) {
        TTextPanel** copy1 = &this->ms_copy_text1;
        this->create_text(this, copy1, 0x241B, 5,
                          panel_height - 0x2A, 0x32, 0x12,
                          10, 0, 0, 0);

        if ((*copy1)->get_text_rect(&rect) != 0) {
            this->circle_p_pic = new TPicturePanel;
            if (this->circle_p_pic != 0) {
                this->circle_p_pic->setup(this->render_area, this,
                               rect.bottom - this->pnl_x + 3,
                               rect.right + 1, 0x0F, 0x0E,
                               "circlep2", 0xC4E6, 0, 1);

                long x = this->circle_p_pic->xPosition() - this->pnl_x +
                         this->circle_p_pic->width();
                TTextPanel** copy2 = &this->ms_copy_text2;
                this->create_text(this, copy2, 0x241C, x,
                                  rect.right, 0x1F4, 0x12, 10, 0, 0, 0);

                if ((*copy2)->get_text_rect(&rect) != 0) {
                    diff = (panel_height - rect.bottom - 5) / 2;
                    if (diff > 0) {
                        (*copy1)->set_fixed_position(
                            (*copy1)->xPosition() + diff,
                            (*copy1)->yPosition(),
                            (*copy1)->width(),
                            (*copy1)->height());
                        this->circle_p_pic->set_fixed_position(
                            this->circle_p_pic->xPosition() + diff,
                            this->circle_p_pic->yPosition(),
                            this->circle_p_pic->width(),
                            this->circle_p_pic->height());
                        (*copy2)->set_fixed_position(
                            (*copy2)->xPosition() + diff,
                            (*copy2)->yPosition(),
                            (*copy2)->width(),
                            (*copy2)->height());
                    }
                }
            }
        }
    } else {
        strcpy(temp_str + 4, this->get_string(0x241B));
        strcat(temp_str + 4, this->get_string(0x2424));
        strcat(temp_str + 4, " ");
        strcat(temp_str + 4, this->get_string(0x241C));

        this->create_text(this, &this->ms_copy_text1, temp_str + 4, 5,
                          panel_height - 0x2A, this->pnl_wid - 0x0A,
                          0x12, 10, 1, 0, 0);
    }

    this->create_text(this, &this->warning_text, 0x2425, 5,
                      panel_height - 0x18, this->pnl_wid - 0x0A,
                      0x12, 10, 1, 0, 0);

    this->set_ideal_size(0x280, 0x1E0);

    TPanel** tab_dst = tab_list;
    TButtonPanel** tab_src = button_base;
    for (i = 5; i != 0; --i) {
        *tab_dst++ = *tab_src++;
    }
    this->set_tab_order(tab_list, 5);
    this->set_curr_child(this->button[0]);
}
