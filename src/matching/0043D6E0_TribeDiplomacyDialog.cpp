// VA: 0043D6E0 TribeDiplomacyDialog::~TribeDiplomacyDialog
// Source: dlg_dip.cpp lines 374-428
// 445 bytes, 163 asm, EH-framed destructor with /GX
//
// The dialog owns the panel arrays beginning immediately after its 0x490-byte
// TDialogPanel base.  The first cleanup loop is the source-level row walk
// through the four text arrays and four tribute-button arrays; using the
// playerVictoryScores row as the anchor preserves the original +/- offsets.
//
// Attempt log:
// - Prior attempt used an undersized one-vptr base and a locally defined
//   operator_delete, so the checker selected the free shim at the target VA.
// - Reconstructed the period TPanel -> TEasy_Panel -> TDialogPanel layout,
//   named the fields from the class dump, and used the real TShape destructor
//   and external operator_delete surfaces.

extern void __cdecl operator_delete(void*);

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    virtual ~TDialogPanel();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TShape {
public:
    ~TShape();
};

class TribeDiplomacyDialog : public TDialogPanel {
public:
    TTextPanel* title[8];
    TTextPanel* playerName[8];
    TTextPanel* playerVictoryScores[8];
    TTextPanel* playerCivilization[8];
    TTextPanel* needMarket;
    TButtonPanel* goldTributeButton[8];
    TButtonPanel* woodTributeButton[8];
    TButtonPanel* foodTributeButton[8];
    TButtonPanel* stoneTributeButton[8];
    TButtonPanel* allyButton[24];
    TButtonPanel* allianceButton;
    TButtonPanel* okButton;
    TButtonPanel* clearButton;
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TShape* buttonPics;
    TShape* backgroundPics;
    float foodTotal;
    float woodTotal;
    float goldTotal;
    float stoneTotal;
    TTextPanel* playerFood;
    TTextPanel* playerGold;
    TTextPanel* playerWood;
    TTextPanel* playerStone;
    float goldTributeAmount[8];
    float foodTributeAmount[8];
    float stoneTributeAmount[8];
    float woodTributeAmount[8];
    int cur_player_row;
    int tribute_flag;

    virtual ~TribeDiplomacyDialog();
};

TribeDiplomacyDialog::~TribeDiplomacyDialog()
{
    int count = 8;
    TTextPanel** row = this->playerVictoryScores;

    do {
        if (row[-16] != 0) {
            delete row[-16];
        }
        if (row[0] != 0) {
            delete row[0];
        }
        if (row[-8] != 0) {
            delete row[-8];
        }
        if (row[8] != 0) {
            delete row[8];
        }
        if (row[25] != 0) {
            delete row[25];
        }
        if (row[33] != 0) {
            delete row[33];
        }
        if (row[17] != 0) {
            delete row[17];
        }
        if (row[41] != 0) {
            delete row[41];
        }
        ++row;
        --count;
    } while (count != 0);

    row = (TTextPanel**)this->allyButton;
    count = 24;
    do {
        if (*row != 0) {
            delete *row;
        }
        ++row;
        --count;
    } while (count != 0);

    if (this->allianceButton != 0) {
        delete this->allianceButton;
    }
    if (this->okButton != 0) {
        delete this->okButton;
    }
    if (this->cancelButton != 0) {
        delete this->cancelButton;
    }
    if (this->clearButton != 0) {
        delete this->clearButton;
    }
    if (this->help_button != 0) {
        delete this->help_button;
    }
    if (this->playerFood != 0) {
        delete this->playerFood;
    }
    if (this->playerGold != 0) {
        delete this->playerGold;
    }
    if (this->playerWood != 0) {
        delete this->playerWood;
    }
    if (this->playerStone != 0) {
        delete this->playerStone;
    }
    if (this->needMarket != 0) {
        delete this->needMarket;
    }

    TShape* shape = this->buttonPics;
    if (shape != 0) {
        shape->~TShape();
        operator_delete(shape);
    }

    shape = this->backgroundPics;
    if (shape != 0) {
        shape->~TShape();
        operator_delete(shape);
    }
}
