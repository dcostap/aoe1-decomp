// blocked by size ceiling: the minimal constructor shape still overflows the emitted .text budget
class TTextPanel;
class TButtonPanel;

class TDialogPanel {
public:
    TDialogPanel(char* param_1);
};

class TMessageDialog : public TDialogPanel {
public:
    unsigned char dlg_type;
    char gap_491[0x3];
    TTextPanel* text;
    TButtonPanel* button0;
    TButtonPanel* button1;
    TButtonPanel* button2;

    TMessageDialog(char* param_1);
};

TMessageDialog::TMessageDialog(char* param_1) : TDialogPanel(param_1) {
    dlg_type = 0;
    text = 0;
    button0 = 0;
    button1 = 0;
    button2 = 0;
}
