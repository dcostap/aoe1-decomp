#ifndef AOE1_DLG_ABT_H
#define AOE1_DLG_ABT_H

// This header owns only TribeAboutDialog.
#include "pnl_dlg.h"

class TButtonPanel;
class TPicturePanel;
class TScreenPanel;
class TTextPanel;

class TribeAboutDialog : public TDialogPanel {
  public:
    TTextPanel* title_text;
    TTextPanel* version_text;
    TTextPanel* ms_copy_text1;
    TTextPanel* ms_copy_text2;
    TTextPanel* ens_copy_text;
    TTextPanel* genie_copy_text;
    TTextPanel* pid_label_text;
    TTextPanel* pid_text;
    TTextPanel* warning_text;
    TTextPanel* background;
    TButtonPanel* credits_button;
    TButtonPanel* close_button;
    TPicturePanel* circle_p_pic;

    TribeAboutDialog(TScreenPanel* parentPanel);
    virtual ~TribeAboutDialog();

  protected:
    virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);

  public:
    virtual void draw();
};

typedef char dlg_abt_dialog_size_check[(sizeof(TribeAboutDialog) == 0x4C4) ? 1 : -1];

#endif
