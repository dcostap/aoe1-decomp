// attempt 2: natural message dialog allocation with fallback resource name, then setup

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel;

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

    void popupYesNoDialog(char* title, char* message, int a, int b);
};
#endif

void TEasy_Panel::popupYesNoDialog(char* title, char* message, int a, int b) {
    TMessageDialog* dialog;

    if (message != 0 && *message != 0) {
        dialog = new TMessageDialog(message);
    } else {
        dialog = new TMessageDialog("YesNoDialog");
    }

    dialog->setup(this, this->popup_info_file_name, this->popup_info_id, a, b, 2, title, 0x5A, 0x1E);
}
