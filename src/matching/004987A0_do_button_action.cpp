// VA: 004987A0 do_button_action (419B)
// scr_game.cpp:2968-3026
//
// Natural reconstruction of the two command-dispatch switches.  The full
// command switch is the enabled arm; the restricted switch handles disabled
// user commands and shares its common handlers with the full arm.
// Attempt log:
// - natural restricted-first ordering preserved behavior but emitted the
//   restricted jump table before the full table (345 differing bytes).
// - placing the enabled full switch before the disabled restricted arm
//   reproduced the oracle's two tables and all 32 direct calls (2 bytes left).
// - the train-mode expression is flag ? -1 : 1; this restores the original
//   neg/sbb/and/inc sequence. MATCH.
// PDB-qualified owner: protected __thiscall
// TRIBE_Screen_Game::do_button_action(int, int, int),
// ?do_button_action@TRIBE_Screen_Game@@IAEXHHH@Z.
// BINARY NOTE: The owned body is 004987A0-00498942.  The NOP at 00498943
// and switch tables from 00498944 are outside the function boundary.
// BINARY NOTE: world is the TRIBE_World member at +0x5B4; score_displayed is
// the derived field at +0x11C.  The score arm reads it before its call.
// BINARY NOTE: action calls this owner at 0049877D.  The dispatch has no
// writes; each arm preserves the shipped call and pop/ret 0xC cleanup.

#if !defined(SCR_GAME_TU_CONTEXT)
extern int allow_user_commands;

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_004[0x474];

    void setup_popup_help();
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_004[0x100];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x18];
    unsigned char score_displayed;
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x13C];
    TRIBE_World* world;

    void command_work();
    void command_move();
    void command_build();
    void command_trade();
    void command_stop();
    void command_unload();
    void command_trade_with(int value);
    void command_research(int value);
    void command_train(int value, short mode);
    void command_building(int value);
    void command_cancel_building();
    void command_stand_ground();
    void command_attack_ground();
    void command_trade_attribute(int value);
    void command_heal();
    void command_convert();
    void command_attack();
    void command_repair();
    void command_unselect();
    void command_group();
    void command_ungroup();
    void command_cancel();
    void command_more();
    void command_chat();
    void command_diplomacy();
    void command_menu();
    void command_score(int value);

protected:
    void do_button_action(int action, int value, int flag);
};
#endif

void TRIBE_Screen_Game::do_button_action(int action, int value, int flag) {
    if (allow_user_commands != 0) {
        switch (action) {
        case 1:
            this->command_work();
            return;
        case 2:
            this->command_move();
            return;
        case 3:
            this->command_build();
            return;
        case 4:
            this->command_trade();
            return;
        case 5:
            this->command_stop();
            return;
        case 6:
            this->command_unselect();
            return;
        case 7:
            this->command_unload();
            return;
        case 8:
            this->command_group();
            return;
        case 9:
            this->command_ungroup();
            return;
        case 0xB:
            this->command_cancel();
            return;
        case 0xC:
            this->command_more();
            return;
        case 0xD:
            this->command_chat();
            return;
        case 0xE:
            this->command_diplomacy();
            return;
        case 0xF:
            this->command_menu();
            return;
        case 0x10:
            this->command_trade_with(value);
            return;
        case 0x11:
            this->command_research(value);
            return;
        case 0x12:
            this->command_train(value, flag ? -1 : 1);
            return;
        case 0x13:
            this->command_building(value);
            return;
        case 0x14:
            this->command_cancel_building();
            return;
        case 0x15:
            this->setup_popup_help();
            return;
        case 0x16:
            this->command_stand_ground();
            return;
        case 0x17:
            this->command_attack_ground();
            return;
        case 0x18:
            this->command_score(this->world->score_displayed == 0);
            return;
        case 0x19:
            this->command_trade_attribute(0);
            return;
        case 0x1A:
            this->command_trade_attribute(1);
            return;
        case 0x1B:
            this->command_trade_attribute(2);
            return;
        case 0x1C:
            this->command_heal();
            return;
        case 0x1D:
            this->command_convert();
            return;
        case 0x1E:
            this->command_attack();
            return;
        case 0x1F:
            this->command_repair();
            return;
        case 0x20:
            this->command_train(value, 1);
            return;
        case 0x21:
            this->command_train(value, -1);
            return;
        default:
            return;
        }
    }

    switch (action) {
    case 6:
        this->command_unselect();
        return;
    case 8:
        this->command_group();
        return;
    case 9:
        this->command_ungroup();
        return;
    case 0xB:
        this->command_cancel();
        return;
    case 0xC:
        this->command_more();
        return;
    case 0xD:
        this->command_chat();
        return;
    case 0xE:
        this->command_diplomacy();
        return;
    case 0xF:
        this->command_menu();
        return;
    case 0x15:
        this->setup_popup_help();
        return;
    case 0x18:
        this->command_score(this->world->score_displayed == 0);
        return;
    default:
        return;
    }
}
