// 004A6330 action
// 130 bytes, __thiscall, TRIBE_Screen_Disconnect method
// probe 2: fix pointer type comparison

class TPanel;

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;
extern void* panel_system;
extern const char* s_Multiplayer_Disconnect_Screen;
extern const char* s_Status_Screen;

void TRIBE_Game_quit_game(RGE_Base_Game* game);
void TPanelSystem_destroyPanel(void* ps, const char* name);
void RGE_Base_Game_close(RGE_Base_Game* game);
long TEasy_Panel_action(void* self, TPanel* p1, long p2, unsigned long p3, unsigned long p4);

class TRIBE_Screen_Disconnect {
public:
    char gap_00[0x480];
    TPanel* cancel_button;
    TPanel* close_button;

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

long TRIBE_Screen_Disconnect::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if (param_1 != 0) {
        if (param_1 == cancel_button && param_2 == 1) {
            TRIBE_Game_quit_game(rge_base_game);
            TPanelSystem_destroyPanel(panel_system, s_Multiplayer_Disconnect_Screen);
            TPanelSystem_destroyPanel(panel_system, s_Status_Screen);
            return 1;
        }
        if (param_1 == close_button && param_2 == 1) {
            RGE_Base_Game_close(rge_base_game);
            return 1;
        }
    }
    return TEasy_Panel_action(this, param_1, param_2, param_3, param_4);
}
