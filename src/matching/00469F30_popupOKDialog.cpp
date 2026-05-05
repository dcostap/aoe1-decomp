// attempt 2: natural strcpy/panel cleanup/message dialog setup; setup is called even if new returns null

#include <string.h>

class TPanel {};
class TEasy_Panel;

class TPanelSystem {
public:
    char gap_00[0x14];
    TPanel* panel(char* name);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TMessageDialog {
public:
    char data[0x4A4];
    TMessageDialog(char* name);
    long setup(TEasy_Panel* owner, char* info_file_name, long info_id, int a, int b, int buttons, char* title, int width, int height);
};

class TEasy_Panel {
public:
    char gap_000[0x340];
    char popup_info_file_name[260];
    long popup_info_id;

    void popupOKDialog(char* title, char* panel_name, int a, int b);
};

void TEasy_Panel::popupOKDialog(char* title, char* panel_name, int a, int b) {
    char temp_title[256];

    if (panel_name != 0 && *panel_name != 0) {
        strcpy(temp_title, panel_name);
    } else {
        strcpy(temp_title, "OKDialog");
    }

    if (panel_system.panel(temp_title) != 0) {
        panel_system.destroyPanel(temp_title);
    }

    TMessageDialog* dialog = new TMessageDialog(temp_title);
    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, a, b, 0, title, 0x5A, 0x1E);
}
