// 0049C010 command_quick_chat
// 156 bytes, __thiscall, TRIBE_Screen_Game method
// probe 1: /GX EH, check resigned state, create TribeSendQuickMessageDialog

class TMessagePanel {
public:
    void show_message(const char* msg, char param, char param2, void* p, int a, int b);
};

class TPanel {
public:
    const char* get_string(int stringId);
};

class TribeSendQuickMessageDialog {
public:
};

void __cdecl TribeSendQuickMessageDialog_ctor(TribeSendQuickMessageDialog* self, TPanel* screen, int mode);

class RGE_Base_Game {
public:
    char gap_00[0x150];
    unsigned int prog_mode;
};

extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int size);

class TRIBE_Screen_Game : public TPanel {
public:
    char gap_00[0x7B4];
    unsigned int field_7B4;

    TMessagePanel* message_panel;

    void command_quick_chat();
};

void TRIBE_Screen_Game::command_quick_chat() {
    if (field_7B4 == 0 && rge_base_game->prog_mode == 5) {
        const char* msg = get_string(0xBFE);
        message_panel->show_message(msg, '2', 0, 0, 0, 0);
        return;
    }
    TribeSendQuickMessageDialog* dialog = (TribeSendQuickMessageDialog*)operator new(0x49C);
    if (dialog != 0) {
        TribeSendQuickMessageDialog_ctor(dialog, (TPanel*)this, 2);
    }
}
