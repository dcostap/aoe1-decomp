// VA: 00490FF0 TRIBE_Screen_Campaign_Selection::action
// scr_cams.cpp lines 196-241
// Attempt log:
// 1: natural source with /GX-style new/ctor EH context: exact except final base call uses lea ecx,[esi+4] due bad base model.
// 2: move virtual table surface to TEasy_Panel base so base subobject starts at offset 0.

class TPanel {
public:
    virtual void t0();
};
class TTextPanel;
class TRIBE_Screen_Name;

class TEasy_Panel {
public:
#define EPAD(n) virtual void e##n();
    EPAD(0) EPAD(1) EPAD(2) EPAD(3) EPAD(4) EPAD(5) EPAD(6) EPAD(7)
    EPAD(8) EPAD(9) EPAD(10) EPAD(11) EPAD(12) EPAD(13) EPAD(14) EPAD(15)
    EPAD(16) EPAD(17) EPAD(18) EPAD(19) EPAD(20) EPAD(21) EPAD(22) EPAD(23)
    EPAD(24) EPAD(25) EPAD(26) EPAD(27) EPAD(28) EPAD(29) EPAD(30) EPAD(31)
    EPAD(32) EPAD(33) EPAD(34) EPAD(35) EPAD(36) EPAD(37) EPAD(38) EPAD(39)
    EPAD(40) EPAD(41) EPAD(42) EPAD(43) EPAD(44)
#undef EPAD
    virtual long vB4(TPanel* panel, long code, unsigned long p3, unsigned long p4);
    long action(TPanel* panel, long code, unsigned long p3, unsigned long p4);
};

class RGE_Game_Info {
public:
    unsigned char set_current_campaign(long id);
};

class RGE_Base_Game {
public:
    char gap_00[4];
    RGE_Game_Info* player_game_info;
    void disable_input();
    void close();
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    int setCurrentPanel(const char* name, int modal);
    int destroyPanel(const char* name);
};

extern TPanelSystem panel_system;

class TTextPanel : public TPanel {
public:
    long get_id();
};

class TRIBE_Screen_Name {
public:
    char gap[0x4A0];
    TRIBE_Screen_Name();
};

class TRIBE_Screen_Campaign_Selection : public TEasy_Panel {
public:
    char gap_004[0x48C];
    TTextPanel* campaignList; // +0x490
    char gap_494[0x18];
    TPanel* scenarioList;     // +0x4AC
    char gap_4B0[0x0C];
    TPanel* okButton;         // +0x4BC
    TPanel* cancelButton;     // +0x4C0
    TPanel* close_button;     // +0x4C4
    int campaignsLoaded;      // +0x4C8

    void startGame();
    void fillScenarios();
    long action(TPanel* panel, long code, unsigned long p3, unsigned long p4);
};

void* __cdecl operator new(unsigned int size);

long TRIBE_Screen_Campaign_Selection::action(TPanel* panel, long code, unsigned long p3, unsigned long p4)
{
    if (panel != 0 && this->campaignsLoaded != 0) {
        TPanel* ok = this->okButton;
        if (panel == ok && code == 1) {
            this->startGame();
            return 1;
        }
        if (panel == this->cancelButton && code == 1) {
            rge_base_game->disable_input();
            new TRIBE_Screen_Name;
            panel_system.setCurrentPanel("Name Selection Screen", 0);
            panel_system.destroyPanel("Campaign Selection Screen");
            return 1;
        }
        if (panel == this->close_button && code == 1) {
            rge_base_game->close();
            return 1;
        }
        if (panel == this->campaignList && code == 1) {
            RGE_Game_Info* info = rge_base_game->player_game_info;
            info->set_current_campaign(this->campaignList->get_id());
            this->fillScenarios();
            return 1;
        }
        if (panel == this->scenarioList && code == 3) {
            this->vB4(ok, 1, 0, 0);
            return 1;
        }
    }
    return this->TEasy_Panel::action(panel, code, p3, p4);
}
