// 004A5130 TribeMPSetupScreen::setupTabOrder
// 223 bytes, __thiscall, scr_mps.cpp lines 2752-2787
// The named panel surface preserves the proven +0xC8 tab-order slot.

#ifndef SCR_MPS_TU_CONTEXT

class TPanel;
class TDrawArea;
struct tagRECT;

class RGE_Base_Game {
public:
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;

class TribeMPSetupScreen {
public:
    virtual ~TribeMPSetupScreen();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual void set_state(short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);

    char gap_04[0x60C];
    TPanel* chatInput;
    char gap_614[0x0C];
    TPanel* gameSettingsButton;
    char gap_624[0xDC];
    TPanel* startButton;
    char gap_704[8];
    TPanel* cancelButton;
    char gap_710[4];
    TPanel* ready_button;

    void set_curr_child(TPanel* child);
    void setupTabOrder();
};

#endif

void TribeMPSetupScreen::setupTabOrder()
{
    TPanel* tabList[4];

    if (rge_base_game->singlePlayerGame()) {
        tabList[0] = startButton;
        tabList[1] = cancelButton;
        tabList[2] = gameSettingsButton;
        set_tab_order(tabList, 3);
        set_curr_child(startButton);
        return;
    }

    tabList[0] = chatInput;
    if (gameSettingsButton) {
        tabList[1] = startButton;
        tabList[2] = cancelButton;
        tabList[3] = gameSettingsButton;
        set_tab_order(tabList, 4);
        set_curr_child(chatInput);
        return;
    }

    tabList[1] = ready_button;
    tabList[2] = cancelButton;
    set_tab_order(tabList, 3);
    set_curr_child(chatInput);
}
