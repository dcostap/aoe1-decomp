#pragma once

#include "GameViewPanel.h"

class TRIBE_World;
class TTextPanel;
class TMessagePanel;
class RGE_Panel_Tool_Box;
class TScrollBarPanel;
class TRIBE_Panel_Inven;
class TRIBE_Panel_Object;
class TRIBE_Panel_Time;
class TRIBE_Panel_Pop;
class TRIBE_Panel_Button;
struct TDigital;
class TShape;

class TRIBE_Screen_Game : public GameViewPanel {
public:
    TRIBE_Screen_Game();
    virtual ~TRIBE_Screen_Game();

    void handle_game_update();
    void game_mode_changed(int new_mode, int old_mode);
    void player_changed(int old_player, int new_player);
    void handle_pause();
    void handle_resume();
    void handleChatReceived(int from_player);
    void display_system_message(char* text);
    void setup_buttons();
    void reset_clocks();
    void reset_buttons();
    void set_map_buttons_redraw(RedrawMode param_1);
    virtual void set_redraw(RedrawMode param_1) override;
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) override;
    virtual long handle_user_command(uint param_1, long param_2) override;
    virtual void set_focus(int param_1) override;
    virtual void stop_sound_system() override;
    virtual int restart_sound_system() override;

private:
    struct RuntimeState {
        TShape* game_screen_pic;
        TShape* button_border1_pic;
        TShape* button_other_pic;
        TShape* button_border2_pic;
        TShape* button_border3_pic;
        TShape* button_cmd_pic;
        TShape* button_tech_pic;
        TShape* button_unit_pic;
        TShape* button_bldg_pics[5];
        TShape* more_cancel_pic;

        TRIBE_World* world;
        TPanel* main_view;
        TPanel* map_view;
        TTextPanel* pause_text;
        TTextPanel* age_panel;
        TTextPanel* fps_panel;
        TMessagePanel* score_panel[8];
        TTextPanel* log_text;
        TScrollBarPanel* log_scrollbar;
        TMessagePanel* text_line_panel;
        TTextPanel* quit_message_panel;
        TMessagePanel* message_panel[6];
        TMessagePanel* chat_panel[8];
        TRIBE_Panel_Inven* inven_panel;
        TRIBE_Panel_Object* object_panel;
        TRIBE_Panel_Time* time_panel;
        TRIBE_Panel_Time* countdown_clock[10];
        TRIBE_Panel_Pop* pop_panel;
        TRIBE_Panel_Button* button_panel[17];
        RGE_Panel_Tool_Box* tool_box;
        void* tech_list;
        void* make_list;
        void* bldg_list;
        void* trade_list;
        TDigital* game_over_sound;
        int chat_line;
        short last_item;
        short reserved;
    };

    static const int kScreenSize = 0x7C4;
    RuntimeState runtime;
    unsigned char shim_padding[kScreenSize - sizeof(GameViewPanel) - sizeof(RuntimeState)];
};

static_assert(sizeof(GameViewPanel) <= 0x7C4, "GameViewPanel exceeds TRIBE_Screen_Game size");
static_assert(sizeof(TRIBE_Screen_Game) == 0x7C4, "Size mismatch");
