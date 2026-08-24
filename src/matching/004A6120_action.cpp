#ifndef SCR_MPS_TU_CONTEXT
class TPanel;
class TButtonPanel;

class TEasy_Panel {
public:
    char gap_04[0x474];

    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_Base_Game {
public:
    void close();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    TButtonPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};
#endif

long TRIBE_Screen_Wait::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    if ((param_1 != 0) && (param_1 == (TPanel*)this->close_button) && (param_2 == 1)) {
        rge_base_game->close();
        return 1;
    }
    return this->TScreenPanel::action(param_1, param_2, param_3, param_4);
}
