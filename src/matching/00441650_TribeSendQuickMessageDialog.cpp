// VA: 00441650
// TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog()
// Source: dlg_smsg.cpp lines 532-535

// attempt 1: natural destructor with delete calls, default flags -> 96/106 bytes, missing EH prolog
// attempt 2: added /GX rsp -> EXACT MATCH (106/106, 0.0000%)
// FLAGS: /GX (needed for EH prolog in virtual destructor with delete calls)

#ifdef DLG_SMSG_CANONICAL_TU
#include "../../include/dlg_smsg_context.h"
#else
class TPanel;

class TEditPanel {
public:
    virtual ~TEditPanel();
};

class TTextPanel {
public:
    virtual ~TTextPanel();
};

class TEasy_Panel {
public:
    char pad_000[0x474];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char pad_478[0x18];  // 0x490 - 0x478 = 0x18
    virtual ~TDialogPanel();
};

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    TEditPanel* chatInput;   // +0x490
    TTextPanel* chatTitle;   // +0x494

    virtual ~TribeSendQuickMessageDialog();
};
#endif

TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog() {
    delete this->chatInput;
    delete this->chatTitle;
}
