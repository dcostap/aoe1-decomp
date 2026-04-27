// attempt 1: natural EH-framed destructor with the two delete_panel calls, vptr restore, and base destructor tail
// attempt 2: tried multiple surface/layout baselines; the remaining gap is still the 4-byte offset on the panel member access
// leaving this in scratch paused because the current mismatch is a layout/register basin, not a behavior bug

class TPanel;

class TScreenPanel {
public:
    char gap_0[0x474];

    ~TScreenPanel();
    void delete_panel(TPanel** panel);
};

class TPanel {
public:
    virtual void scalar_deleting_destructor(unsigned int flags);
};

class TTextPanel;
class TButtonPanel;

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    virtual ~TRIBE_Screen_Main_Error();
};

TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error() {
    *(void**)this = (void*)0x573078;
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->cancel_button);
    this->TScreenPanel::~TScreenPanel();
}
