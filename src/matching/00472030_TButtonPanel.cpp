extern "C" void __cdecl free(void* ptr);

// The virtual base surface is required for the final direct call to
// TPanel::~TPanel. A free helper named destructor() selects the wrong symbol.
#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();

    char gap_04[0x194];
    char* text1[9];
    char* text2[9];
    char gap_1E0[0x1C];
    TButtonPanel** radio_buttons;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

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
}
