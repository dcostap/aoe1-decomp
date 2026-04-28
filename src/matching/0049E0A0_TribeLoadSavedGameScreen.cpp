// 0049E0A0 TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen
// Source: scr_load.cpp lines 124-132, size 170 bytes
// Attempt log:
// first: wrong offsets (+4 instead of +478) - base class needs 0x478 size.

struct TPanel {
    virtual ~TPanel();
    void delete_panel(TPanel** panel);
    char gap_00[0x474];  // TPanel base data fills to 0x478
};

struct TScreenPanel : public TPanel {
    virtual ~TScreenPanel();
};
// sizeof(TScreenPanel) = 4(vtable) + 0x474(gap) = 0x478

struct TribeLoadSavedGameScreen : public TScreenPanel {
    TPanel* screenTitle;      // +0x478
    TPanel* listTitle;        // +0x47C
    TPanel* list;             // +0x480
    TPanel* scrollbar;        // +0x484
    TPanel* okButton;         // +0x488
    TPanel* cancelButton;     // +0x48C
    TPanel* deleteButton;     // +0x490

    virtual ~TribeLoadSavedGameScreen();
};

TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen() {
    this->delete_panel(&this->screenTitle);
    this->delete_panel(&this->listTitle);
    this->delete_panel(&this->list);
    this->delete_panel(&this->scrollbar);
    this->delete_panel(&this->okButton);
    this->delete_panel(&this->cancelButton);
    this->delete_panel(&this->deleteButton);
}
