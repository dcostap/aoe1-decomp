#include "../../include/game_globals.h"
#include "../../include/scr_end_context.h"

// 00493C00 TribeEndScreen::~TribeEndScreen
// Source: scr_end.cpp lines 121-126
//
// The compiler-owned virtual child destructors preserve the four original
// destruction sites and their shipped order.
// Attempt log:
// Probe 1: EH-framed destructor, /GX, 4 child objects deleted via virtual dtor

TribeEndScreen::~TribeEndScreen()
{
    delete this->title;
    delete this->text;
    delete this->okButton;
    delete this->background;
}
