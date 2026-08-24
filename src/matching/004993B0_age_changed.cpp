// VA: 004993B0 age_changed (237B)
// PDB owner: protected TRIBE_Screen_Game::age_changed, scr_game.cpp:3304-3331.
// Body: 004993B0-0049949C. 0049949D-0049949F are padding; 004994A0 is switch data.
// Do not treat the unresolved key_down_action as a sibling owner.
// FLAGS: config/flags/004993B0_age_changed.rsp (/GX; original scr_game.cpp EH context)
//
// Initial reconstruction: named age-panel/save-age ownership, the RGE player
// attribute array, and the natural get_string2/set_text/set_redraw/switch form.
// MATCH: this period-plausible reconstruction emits the original 237 bytes;
// the local class gaps preserve the proven +0x580/+0x710 ownership and do not
// use decompiler cursor arithmetic or compiler-steering code.

#if !defined(SCR_GAME_TU_CONTEXT)
class TTextPanel {
public:
    virtual ~TTextPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int mode);
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
    virtual void vfE4();
    virtual void set_text(char* text);

    void set_help_info(long help_id, long page_id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual char* vf1C();
    virtual char* vf20();
    virtual char* vf24();
    virtual char* get_string2(int id, long value, long value2,
                              char* buffer, int length);

    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class TScreenPanel {
public:
    virtual ~TScreenPanel();
    char gap_04[0x474];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x108];
    TTextPanel* age_panel;
    char gap_584[0x18C];
    int save_age;

protected:
    void age_changed();
};
#endif

void TRIBE_Screen_Game::age_changed() {
    char str[512];

    if (this->age_panel != 0) {
        RGE_Player* player = rge_base_game->get_player();
        this->save_age = (int)player->attributes[6];
        rge_base_game->get_string2(0x65, this->save_age, 0, str, 0x200);
        this->age_panel->set_text(str);
        this->age_panel->set_redraw(1);

        switch (this->save_age) {
        case 1:
            this->age_panel->set_help_info(0x1069, -1);
            break;
        case 2:
            this->age_panel->set_help_info(0x106A, -1);
            break;
        case 3:
            this->age_panel->set_help_info(0x106B, -1);
            break;
        case 4:
            this->age_panel->set_help_info(0x106C, -1);
            break;
        }
    }
}
