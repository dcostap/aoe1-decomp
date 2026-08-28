#ifndef AOE1_SCR_STMS_H
#define AOE1_SCR_STMS_H

// PDB source module: C:\\msdev\\work\\age1_x1\\scr_stms.cpp.
// This header owns the status-message screen. Its base is canonical.
#include "Pnl_scr.h"

class TTextPanel;

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TTextPanel* message;

    TRIBE_Screen_Status_Message(char*, char*, char*, long);
    TRIBE_Screen_Status_Message(char*, long, char*, long);
    virtual ~TRIBE_Screen_Status_Message();
    void set_text(char*);
    void set_text(long);
};

typedef char scr_stms_screen_size_check[
    (sizeof(TRIBE_Screen_Status_Message) == 0x47C) ? 1 : -1];

#endif
