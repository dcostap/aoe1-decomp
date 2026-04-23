// first pass: show the GAME PAUSED text, then unpause the text panel only if its flag says it is needed, then refresh the main view
// tried a raw vtable-call shape first; the mismatch stayed in the pause_text/main_view call basin
// tried raw slot casts and direct member-style calls; the remaining mismatch is still the early pause_text load / call-basin shape (first mismatch offset 9)

class TTextPanel;
class TRIBE_Main_View;

class TTextPanel {
public:
    void** vftable;
    char gap_04[0x68];
    int pause_flag;
};

class TRIBE_Main_View {
public:
    void** vftable;
};

typedef void (*TextVCall)(TTextPanel*, int);
typedef void (*ViewVCall)(TRIBE_Main_View*, int);

class TRIBE_Screen_Game {
public:
    char gap_00[0x584];
    TTextPanel* pause_text;
    char gap_588[0x330];
    TRIBE_Main_View* main_view;

    void handle_pause(void);
};

void TRIBE_Screen_Game::handle_pause(void) {
    ((TextVCall)pause_text->vftable[0x39])(pause_text, 0x2329);
    if (pause_text->pause_flag == 0) {
        ((TextVCall)pause_text->vftable[0x5])(pause_text, 1);
        ((TextVCall)pause_text->vftable[0x8])(pause_text, 1);
    }
    ((ViewVCall)main_view->vftable[0x8])(main_view, 1);
}
