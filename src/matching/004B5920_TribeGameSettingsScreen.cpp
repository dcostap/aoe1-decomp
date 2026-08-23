// VA: 004B5920 TribeGameSettingsScreen::~TribeGameSettingsScreen
// PDB source: scr_set.cpp, lines 495-548.
// BINARY NOTE: The control members use TPanel::delete_panel in the exact
// shipped order. The two heap arrays use CRT free, then the base destructor.

#include "../../include/scr_set_context.h"

extern "C" void __cdecl free(void*);

TribeGameSettingsScreen::~TribeGameSettingsScreen()
{
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->timeDrop);
    this->delete_panel((TPanel**)&this->timeLabel);
    this->delete_panel((TPanel**)&this->scoreDrop);
    this->delete_panel((TPanel**)&this->scoreLabel);
    this->delete_panel((TPanel**)&this->victoryFixedText);
    this->delete_panel((TPanel**)&this->difficultyLabel);
    this->delete_panel((TPanel**)&this->difficultyDrop);
    this->delete_panel((TPanel**)&this->ageLabel);
    this->delete_panel((TPanel**)&this->ageDrop);
    this->delete_panel((TPanel**)&this->resourcesLabel);
    this->delete_panel((TPanel**)&this->resourcesDrop);
    this->delete_panel((TPanel**)&this->scenarioTitle);
    this->delete_panel((TPanel**)&this->scenarioPlayersTitle);
    this->delete_panel((TPanel**)&this->scenarioList);
    this->delete_panel((TPanel**)&this->scenarioScrollbar);
    this->delete_panel((TPanel**)&this->missionTitle);
    this->delete_panel((TPanel**)&this->missionText);
    this->delete_panel((TPanel**)&this->missionScrollbar);
    this->delete_panel((TPanel**)&this->pathingLabel);
    this->delete_panel((TPanel**)&this->pathingDrop);
    this->delete_panel((TPanel**)&this->limitLabel);
    this->delete_panel((TPanel**)&this->limitDrop);

    char* p = (char*)this + 0x534;
    int n = 4;
    do {
        this->delete_panel((TPanel**)(p - 0x10));
        this->delete_panel((TPanel**)p);
        p += 4;
        --n;
    } while (n != 0);

    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);

    if (this->scenarioMission != 0) {
        int i = 0;
        if (this->scenarioCount > 0) {
            do {
                if (this->scenarioMission[i] != 0)
                    free(this->scenarioMission[i]);
                ++i;
            } while (i < this->scenarioCount);
        }
        free(this->scenarioMission);
    }
    if (this->scenarioFixed != 0)
        free(this->scenarioFixed);
}
