// VA: 0049F240 ~TRIBE_Screen_Main_Error dtor (106B)
// Scr_main.cpp lines 426-429
// EH-framed destructor: delete_panel for message and cancel_button, then base dtor
// FLAGS: /GX (EH)

#include "../../include/scr_main_context.h"

#if 0
class TPanel {
public:
    char gap_00[0xF0];
    void delete_panel(TPanel** panel_ptr);
    virtual ~TPanel();
};

class TScreenPanel : public TPanel {
public:
    char gap[0x384];
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TPanel* message;             // +0x478
    TPanel* cancel_button;       // +0x47C
    TPanel* close_button;        // +0x480

    virtual ~TRIBE_Screen_Main_Error();
};
#endif

TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error() {
    this->delete_panel((TPanel**)&this->message);
    this->delete_panel((TPanel**)&this->cancel_button);
}
