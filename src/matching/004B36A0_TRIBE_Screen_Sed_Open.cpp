// VA: 004B36A0 ~TRIBE_Screen_Sed_Open
// scr_sedo.cpp lines 104-111
//
// The shared scr_sedo surface keeps delete_panel on TScreenPanel and the
// derived panel slots at their proven offsets.

#include "../../include/scr_sedo_context.h"

TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open() {
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->list);
    this->delete_panel((TPanel**)&this->scrollbar);
    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->deleteButton);
}
