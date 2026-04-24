// tried the stack-buffer wrapper with both direct text+4 and a separate textp; the get_string call shape matched, but the forwarded dialog still loads the text pointer from [esp+10h] instead of [esp+0Ch]
// leaving this in scratch because the remaining gap is a one-dword address-shape drift in the second call, not a changed call set or behavior
class TPanel {
public:
    int get_string(int param_1, char* param_2, int param_3);
};

class TEasy_Panel : public TPanel {
public:
    void popupYesNoCancelDialog(char* param_1, char* param_2, int param_3, int param_4);
};

void TEasy_Panel::popupYesNoCancelDialog(char* param_1, char* param_2, int param_3, int param_4) {
    char text[256];
    this->get_string((int)param_1, text, 0x100);
    this->popupYesNoCancelDialog(text + 4, param_2, param_3, param_4);
}
