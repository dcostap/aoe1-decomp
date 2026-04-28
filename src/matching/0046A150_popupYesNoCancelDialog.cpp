// 0046A150 TEasy_Panel::popupYesNoCancelDialog
// PDB: Panel_ez.cpp:1830-1834, 80 bytes
// FLAGS: default
//
// Fixed: removed `+ 4` from `text + 4` in recursive call.
// Previous author mis-traced the LEA offset (0x0C vs 0x10) and compensated
// with text+4, but the original passes &text[0] directly.
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
    this->popupYesNoCancelDialog(text, param_2, param_3, param_4);
}
