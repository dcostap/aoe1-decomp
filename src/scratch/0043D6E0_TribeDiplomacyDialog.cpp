// VA: 0043D6E0 TribeDiplomacyDialog::~TribeDiplomacyDialog
// Source: dlg_dip.cpp lines 374-428
// 445 bytes, 163 asm, EH-framed destructor with /GX
// FLAGS: config/flags/0043D6E0_TribeDiplomacyDialog.rsp = /nologo /c /O2 /Oy /GX
// Attempt 2: all 8 arrays in loop 1, more complete layout

#include <stdlib.h>

extern void *__cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void *ptr);
void __cdecl operator_delete(void *ptr) { free(ptr); }

// Forward declare helper functions
void __stdcall sub_4B8DD0(void* ptr);
void __cdecl sub_54B660(void* ptr);

class TButtonPanel {
public:
    virtual ~TButtonPanel();
};

class TComboBox : public TButtonPanel {
public:
    virtual ~TComboBox();
};

class TListPanel : public TButtonPanel {
public:
    virtual ~TListPanel();
};

class TScrollPanel : public TButtonPanel {
public:
    virtual ~TScrollPanel();
};

class BaseDialog {
public:
    virtual ~BaseDialog();
};

class TribeDiplomacyDialog : public BaseDialog {
public:
    virtual ~TribeDiplomacyDialog();

    // 8 groups of 8 pointers each = 64 pointers covering offsets +0x490 to +0x590
    TButtonPanel* group0[8];    // +0x490
    char gap_4B0[0x8];          // align to 8 bytes... actually let me be more precise
    TButtonPanel* group1[8];    // +0x4B0
    TButtonPanel* group2[8];    // +0x4D0
    TButtonPanel* group3[8];    // +0x4F0
    TButtonPanel* unk_510;      // +0x510 individual
    TButtonPanel* group4[8];    // +0x514 (goldTributeButton in check_gold)
    TButtonPanel* group5[8];    // +0x534
    TButtonPanel* group6[8];    // +0x554
    TButtonPanel* group7[8];    // +0x574
    // 24 sequential pointers:
    TButtonPanel* unk_594[24];  // +0x594
    // Individual checks
    TButtonPanel* unk_5F4;
    TButtonPanel* unk_5F8;
    TButtonPanel* unk_5FC;
    TButtonPanel* unk_600;
    TButtonPanel* unk_604;
    // Arrays needing manual destructor+operator_delete
    TComboBox* combo_608;
    TListPanel* list_60C;
    // Scroll panels
    TScrollPanel* scroll_620;
    TScrollPanel* scroll_624;
    TScrollPanel* scroll_628;
    TScrollPanel* scroll_62C;
};

TribeDiplomacyDialog::~TribeDiplomacyDialog()
{
    int i, j;

    // Loop 1: 8 groups of 8 pointers each, accessed via offset pattern
    // VC5 generates an ESI walking pointer for this pattern
    for (i = 0; i < 8; i++) {
        if (group0[i]) delete group0[i];
        if (group1[i]) delete group1[i];
        if (group2[i]) delete group2[i];
        if (group3[i]) delete group3[i];
        if (group4[i]) delete group4[i];
        if (group5[i]) delete group5[i];
        if (group6[i]) delete group6[i];
        if (group7[i]) delete group7[i];
    }

    // Loop 2: 24 sequential pointers
    for (j = 0; j < 24; j++) {
        if (unk_594[j]) delete unk_594[j];
    }

    // Individual null-check+delete
    if (unk_5F4) delete unk_5F4;
    if (unk_5F8) delete unk_5F8;
    if (unk_600) delete unk_600;
    if (unk_5FC) delete unk_5FC;
    if (unk_604) delete unk_604;
    if (unk_510) delete unk_510;

    // Manual destructor + operator_delete for combo/list
    if (combo_608) {
        sub_4B8DD0(combo_608);
        sub_54B660(combo_608);
    }
    if (list_60C) {
        sub_4B8DD0(list_60C);
        sub_54B660(list_60C);
    }

    // Scroll panels
    // Note: original checks +0x620, +0x624, +0x628, +0x62C individually
    if (scroll_620) delete scroll_620;
    if (scroll_624) delete scroll_624;
    if (scroll_628) delete scroll_628;
    if (scroll_62C) delete scroll_62C;

    // Base class destructor
    this->BaseDialog::~BaseDialog();
}
