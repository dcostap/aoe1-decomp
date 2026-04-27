// VA: 004B36A0 ~TRIBE_Screen_Sed_Open
// scr_sedo.cpp lines 104-111

// attempt 2: restructure base class layout

class TPanel {
public:
    virtual ~TPanel();
};

class TScreenPanel : public TPanel {
public:
    virtual ~TScreenPanel();
    void delete_panel(TPanel** panel_ptr);
    char gap_004[0x474];    // +0x04 to +0x477
    TPanel* title;           // +0x478
};

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TPanel* list;            // +0x47C
    TPanel* scrollbar;       // +0x480
    TPanel* okButton;        // +0x484
    TPanel* cancelButton;    // +0x488
    TPanel* deleteButton;    // +0x48C

    ~TRIBE_Screen_Sed_Open();
};

TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open() {
    this->delete_panel(&this->title);
    this->delete_panel(&this->list);
    this->delete_panel(&this->scrollbar);
    this->delete_panel(&this->okButton);
    this->delete_panel(&this->cancelButton);
    this->delete_panel(&this->deleteButton);
}
