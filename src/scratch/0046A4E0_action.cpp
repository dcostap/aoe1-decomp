// attempt 1: dialog-name action filter; natural strcmp predicates inline under VC5
#include <string.h>

class TPanel { public: char* panelName(); };
class TPanelSystem { public: int destroyPanel(char* name); };
extern TPanelSystem panel_system;

class TEasy_Panel {
public:
    int action(TPanel* panel, long p2, long p3, long p4);
    int base_action(TPanel* panel, long p2, long p3, long p4);
};

int TEasy_Panel::action(TPanel* panel, long p2, long p3, long p4) {
    if (panel) {
        if (panel->panelName() && strcmp(panel->panelName(), "OKDialog") == 0) {
            if (p2 == 0 || p2 == 1) {
                panel_system.destroyPanel("OKDialog");
            }
            return 1;
        }
        if (panel->panelName() && strcmp(panel->panelName(), "YesNoDialog") == 0) {
            if (p2 == 0 || p2 == 1) {
                panel_system.destroyPanel("YesNoDialog");
            }
            return 1;
        }
        if (panel->panelName() && strcmp(panel->panelName(), "YesNoCancelDialog") == 0) {
            if (p2 == 0 || p2 == 1 || p2 == 2) {
                panel_system.destroyPanel("YesNoCancelDialog");
            }
            return 1;
        }
    }
    return this->base_action(panel, p2, p3, p4);
}
