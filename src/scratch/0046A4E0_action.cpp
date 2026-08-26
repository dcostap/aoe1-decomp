// attempt 1: dialog-name action filter; natural strcmp predicates inline under VC5
#include <string.h>

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel { public: char* panelName(); };
class TPanelSystem { public: int destroyPanel(char* name); };
extern TPanelSystem panel_system;

class TEasy_Panel {
public:
    virtual long action(TPanel* panel, long p2, unsigned long p3, unsigned long p4);
    int base_action(TPanel* panel, long p2, unsigned long p3, unsigned long p4);
};
#endif

long TEasy_Panel::action(TPanel* panel, long p2, unsigned long p3, unsigned long p4) {
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
