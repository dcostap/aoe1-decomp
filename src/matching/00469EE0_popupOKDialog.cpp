#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
};

class TEasy_Panel : public TPanel {
public:
    void popupOKDialog(char* title, char* text, int value1, int value2);
    void popupOKDialog(int string_id, char* text, int value1, int value2);
};
#endif

void TEasy_Panel::popupOKDialog(int string_id, char* text, int value1, int value2) {
    char title[256];

    get_string(string_id, title, 0x100);
    popupOKDialog(title, text, value1, value2);
}
