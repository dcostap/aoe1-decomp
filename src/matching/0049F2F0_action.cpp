#include "../../include/scr_main_context.h"

#if 0
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

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    char gap_478[0x4];
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};
#endif

long TRIBE_Screen_Main_Error::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    TPanel* panel;
    long state;
    
    // Load both params immediately to force register allocation
    panel = param_1;
    state = param_2;
    
    // Check NULL case first
    if (panel == 0) {
        goto call_parent;
    }
    
    // Check cancel button
    if (panel == (TPanel*)this->cancel_button && state == 1) {
        rge_base_game->close();
        return 1;
    }
    
    // Check close button
    if (panel == (TPanel*)this->close_button && state == 1) {
        rge_base_game->close();
        return 1;
    }

call_parent:
    return this->TEasy_Panel::action(panel, state, param_3, param_4);
}
