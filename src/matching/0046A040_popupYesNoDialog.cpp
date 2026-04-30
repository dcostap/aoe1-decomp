class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
};

class TEasy_Panel : public TPanel {
public:
    void popupYesNoDialog(char* text, char* param_2, int param_3, int param_4);
    void popupYesNoDialog(long string_id, char* param_2, int param_3, int param_4);
};

void TEasy_Panel::popupYesNoDialog(long string_id, char* param_2, int param_3, int param_4) {
    char text[256];

    this->get_string(string_id, text, 0x100);
    this->popupYesNoDialog(text, param_2, param_3, param_4);
}
