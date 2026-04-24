extern void* rge_base_game;
extern void* panel_system;

class TRIBE_Game {
public:
    int start_menu();
    void close();
};

class TEasy_Panel {
public:
    void popupYesNoCancelDialog(int title, const char* body, int x, int y);
};

class TPanelSystem {
public:
    int destroyPanel(const char* name);
};

class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    unsigned char need_to_save();
    void command_quit();
};

void TRIBE_Screen_Sed::command_quit() {
    if (need_to_save()) {
        popupYesNoCancelDialog(0x2447, (const char*)0x586D18, 0x1C2, 0x64);
        return;
    }
    if (!((TRIBE_Game*)rge_base_game)->start_menu()) {
        ((TRIBE_Game*)rge_base_game)->close();
        return;
    }
    ((TPanelSystem*)0x62E870)->destroyPanel((const char*)0x584414);
}
