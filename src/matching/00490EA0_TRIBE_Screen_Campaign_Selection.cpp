// 00490EA0 TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection
// PDB: scr_cams.cpp:158-171, 240 bytes
// virtual __thiscall ~TRIBE_Screen_Campaign_Selection()
// FLAGS: /GX (EH)

#include "../../include/scr_cams_context.h"

TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection()
{
    // call delete_panel for each member panel
    delete_panel(&this->title);
    delete_panel(&this->campaignTitle);
    delete_panel((TPanel**)&this->campaignList);
    delete_panel(&this->campaignScrollbar);
    delete_panel(&this->scenarioTitle);
    delete_panel((TPanel**)&this->scenarioList);
    delete_panel(&this->scenarioScrollbar);
    delete_panel(&this->difficultyTitle);
    delete_panel((TPanel**)&this->difficultyDrop);
    delete_panel((TPanel**)&this->okButton);
    delete_panel((TPanel**)&this->cancelButton);
    delete_panel((TPanel**)&this->close_button);
}
