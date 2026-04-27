// 0043E8E0 THelpDialog::THelpDialog
// Source: dlg_help.cpp lines 68-70
// public: __thiscall THelpDialog::THelpDialog(TEasy_Panel*,char*,char*,long,long,long)
//
// Attempt log:
// Probe 1: natural ctor with base init + setup_help call, default flags

#include "..\..\include\game_globals.h"

class TEasy_Panel;

// TDialogPanel — base class
class TDialogPanel {
public:
    virtual ~TDialogPanel();
    TDialogPanel(char* title);
};

// THelpDialog
class THelpDialog : public TDialogPanel {
public:
    void setup_help(TEasy_Panel* panel, char* s1, char* s2, long l1, long l2, long l3);

    THelpDialog(TEasy_Panel* panel, char* s1, char* s2, long l1, long l2, long l3);
};

THelpDialog::THelpDialog(TEasy_Panel* panel, char* s1, char* s2, long l1, long l2, long l3)
    : TDialogPanel("Help Dialog")
{
    this->setup_help(panel, s1, s2, l1, l2, l3);
}
