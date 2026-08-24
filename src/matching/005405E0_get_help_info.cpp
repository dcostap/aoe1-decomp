// RGE_Main_View::get_help_info
// VA: 005405E0
// PDB-qualified owner/name: RGE_Main_View::get_help_info
// PDB source: vw_main.cpp:1926-1940
// Original body boundary: 005405E0-00540677; next symbol: 00540680.
// 152 bytes
//
// Exact-finish: typed object ownership, the proven TPanel virtual surface, and
// a qualified base call reproduce the original 152 bytes.
// The raw offset walkback was exact but was discarded by policy.
// BINARY NOTE: The original rereads object->master_obj before both helper calls.
// Keep both expressions direct to preserve that fault order and reload pattern.

#include <string.h>

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Tile;
class TDrawArea;

class RGE_Pick_Info {
public:
    float x;       // +0x00
    float y;       // +0x04
    short scr_x;   // +0x08
    short scr_y;   // +0x0A
    RGE_Static_Object* object; // +0x0C
    RGE_Tile* tile; // +0x10
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    int get_help_message(void);
    int get_help_page(void);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup(TDrawArea*, TPanel*, long, long, long, long,
                        unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*,
                                  TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char*& str_out, long& page_out,
                                        long param_3, long param_4);
    char* get_string(int id);
};

class RGE_Main_View : public TPanel {
public:
    unsigned char pick1(int key, int key_mod, long x, long y, RGE_Pick_Info* info, void* exclude, int flag);
protected:
    virtual unsigned char get_help_info(char*& str_out, long& page_out,
                                        long param_3, long param_4);
};
#endif

unsigned char RGE_Main_View::get_help_info(char*& str_out, long& page_out, long param_3, long param_4) {
    RGE_Pick_Info pickInfo;
    unsigned char result = this->pick1(0x29, 2, param_3, param_4, &pickInfo, 0, 1);

    if (result == 0x34) {
        // Use object field (+0x0C) not tile (+0x10) to match original stack offset
        int msgId = pickInfo.object->master_obj->get_help_message();
        char* msg = this->get_string(msgId);

        strcpy(str_out, msg);

        int pageId = pickInfo.object->master_obj->get_help_page();
        page_out = pageId;

        return 1;
    }

    return TPanel::get_help_info(str_out, page_out, param_3, param_4);
}
