// TRIBE_Mission_Screen::action
// VA: 004B89A0
// PDB: scr_vc.cpp:266-293
//
// Baseline reconstruction: typed screen fields, the proven
// RGE_Base_Game -> RGE_World -> RGE_Scenario chain, and the direct
// TEasy_Panel base action.  Text-button actions fall through to the base
// handler.  Their message result goes directly to list->setText().

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void set_active(int active);
    virtual void vf18();
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void set_ideal_size(long width, long height);

    char gap_04[0x3C];
};

class TTextPanel : public TPanel {
public:
    virtual void setText(char* text);
};

class TButtonPanel : public TPanel {
};

class TScrollBarPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_40[0x434];
    virtual ~TEasy_Panel();
    long action(TPanel* sender, long actionType,
                unsigned long param3, unsigned long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
    char gap_474[4];
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Scenario {
public:
    char* Get_message(long id);
};

class RGE_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_World* world;
    char gap_3F8[0x608];
    int save_paused;

    int singlePlayerGame();
    void set_paused(int paused, int non_user_pause);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int create_game_screen();
};

extern TRIBE_Game* rge_base_game;

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;                 // +0x478
    TTextPanel* list;                  // +0x47C
    TScrollBarPanel* scroll_bar;       // +0x480
    TButtonPanel* ok_button;           // +0x484
    TButtonPanel* text_buttons[3];     // +0x488
    unsigned char game_flag;           // +0x494
    char pad_495[3];
    void* vc_back_bmp;                 // +0x498

    long action(TPanel* sender, long actionType,
                unsigned long param3, unsigned long param4);
};

long TRIBE_Mission_Screen::action(TPanel* sender, long actionType,
                                  unsigned long param3, unsigned long param4)
{
    if (actionType == 1) {
        if (sender == this->text_buttons[0]) {
            this->list->setText(rge_base_game->world->scenario->Get_message(4));
        }

        if (sender == this->text_buttons[1]) {
            this->list->setText(rge_base_game->world->scenario->Get_message(0));
        }

        if (sender == this->text_buttons[2]) {
            this->list->setText(rge_base_game->world->scenario->Get_message(1));
        }

        if (sender == this->ok_button) {
            if (this->game_flag != 0) {
                panel_system.setCurrentPanel((char*)"Game Screen", 0);
                if (rge_base_game->singlePlayerGame() == 1 &&
                    rge_base_game->save_paused == 0) {
                    rge_base_game->set_paused(0, 0);
                }
            } else {
                rge_base_game->create_game_screen();
            }

            panel_system.destroyPanel((char*)"Mission Dialog");
            return 1;
        }
    }

    return TEasy_Panel::action(sender, actionType, param3, param4);
}
