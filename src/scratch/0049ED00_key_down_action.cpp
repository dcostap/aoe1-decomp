// VA: 0049ED00 key_down_action (250B)
// Scr_main.cpp

class TPanel {
public:
    virtual ~TPanel();
};

class TScreenPanel : public TPanel {
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    char gap4[0x474];
    TPanel* field_478;
    TPanel* field_47C;
    TPanel* field_480[7];
    TPanel* field_49C;
    TPanel* field_4A0;
    TPanel* field_4A4;
    TPanel* field_4A8;
    TPanel* field_4AC;
    
    int key_down_action(int key);
};

extern int* rge_base_game;
extern int __cdecl get_paused();

int TRIBE_Screen_Main_Menu::key_down_action(int key) {
    if (get_paused()) return 0;
    
    int progMode = *(int*)((char*)rge_base_game + 0x1B0);
    if (progMode != 4 && progMode != 6 && progMode != 7) return 0;
    
    switch (key) {
    case 0x21:  // VK_PRIOR / PageUp
        return 1;
    case 0x22:  // VK_NEXT / PageDown
        return 1;
    default:
        return 0;
    }
}
