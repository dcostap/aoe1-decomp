extern "C" void __cdecl free(void* ptr);

class TPanel {
public:
    void destructor(void);
};

class TButtonPanel {
public:
    virtual ~TButtonPanel();

    char gap_04[0x194];
    char* text1[9];
    char* text2[9];
    char gap_1E0[0x1C];
    TButtonPanel** radio_buttons;
};

TButtonPanel::~TButtonPanel() {
    int i;

    for (i = 0; i < 9; i++) {
        if (text1[i] != 0) {
            free(text1[i]);
            text1[i] = 0;
        }
        if (text2[i] != 0) {
            free(text2[i]);
            text2[i] = 0;
        }
    }
    if (radio_buttons != 0) {
        free(radio_buttons);
        radio_buttons = 0;
    }
    ((TPanel*)this)->destructor();
}
