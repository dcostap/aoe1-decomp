// 004A4100 fillChat
// 135 bytes, __thiscall, TribeMPSetupScreen method
// probe 3: fix type mismatch

class RGE_Base_Game;
class TChat;

extern RGE_Base_Game* rge_base_game;
extern TChat* chat;

int RGE_Base_Game_singlePlayerGame(RGE_Base_Game* game);
int TTextPanel_numberLines(void* self);
void TTextPanel_delete_line(void* self, int index);
const char* TChat_GetChatMsg(TChat* self, int param);
void TTextPanel_word_wrap_append(void* self, const char* msg);
void TTextPanel_scroll(void* self, int dir, int a, int b);

class TribeMPSetupScreen {
public:
    void* chatBox;

    void fillChat(int param_1);
};

void TribeMPSetupScreen::fillChat(int param_1) {
    int single = RGE_Base_Game_singlePlayerGame(rge_base_game);
    if (single == 0) {
        int lines = TTextPanel_numberLines(chatBox);
        short bot = *(short*)((char*)chatBox + 0xFE);
        int need_scroll = (lines >= 1) && (bot == lines - 1);
        if (lines > 99) {
            TTextPanel_delete_line(chatBox, 0);
        }
        const char* msg = TChat_GetChatMsg(chat, param_1);
        TTextPanel_word_wrap_append(chatBox, msg);
        if (need_scroll) {
            TTextPanel_scroll(chatBox, 7, 0, 1);
        }
    }
}
