// 004A61A0 TRIBE_Screen_Disconnect
// 200 bytes, __thiscall, TRIBE_Screen_Disconnect constructor
// probe 2: /GX EH, call base ctor, init members, setup

class TPanel;
class TTextPanel;
class TButtonPanel;

extern const char* s_Multiplayer_Disconnect_Screen;
extern void* rge_base_game;
extern const char* s_scr3;
void* rge_base_game_draw_area(void);

void TScreenPanel_ctor(void* self, const char* name);
int TScreenPanel_setup(void* self, void* draw_area, const char* font, int color, int param);
void TEasy_Panel_set_ideal_size(void* self, int w, int h);
void TEasy_Panel_create_text(void* self, TPanel* parent, TTextPanel** target, int stringId, int x, int y, int w, int h, int a, int b, int c, int d);

class TRIBE_Screen_Disconnect {
public:
    int mode;
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    void ctor(int param_1);
};

void TRIBE_Screen_Disconnect::ctor(int param_1) {
    TScreenPanel_ctor(this, s_Multiplayer_Disconnect_Screen);
    this->mode = param_1;
    this->message = 0;
    this->cancel_button = 0;
    this->close_button = 0;
    int r = TScreenPanel_setup(this, rge_base_game_draw_area(), s_scr3, 0xC385, 0);
    if (r == 0) {
        *(int*)this = 1;
    } else {
        TEasy_Panel_set_ideal_size(this, 0x280, 0x1E0);
        TEasy_Panel_create_text(this, (TPanel*)this, &message, 0x4C0, 0x28, 0x28, 0x230, 400, 4, 1, 1, 1);
    }
}
