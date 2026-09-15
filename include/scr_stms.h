#ifndef AOE1_SCR_STMS_H
#define AOE1_SCR_STMS_H

// This header owns the status-message screen. Its base is canonical.
#include "Pnl_scr.h"

class TTextPanel;

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TTextPanel* message;

    TRIBE_Screen_Status_Message(char* name, char* message_in, char* info_file_in, long info_id_in);
    TRIBE_Screen_Status_Message(char* name, long message_in, char* info_file_in, long info_id_in);
    virtual ~TRIBE_Screen_Status_Message();
    void set_text(char* message_in);
    void set_text(long message_in);
};

typedef char scr_stms_screen_size_check[
    (sizeof(TRIBE_Screen_Status_Message) == 0x47C) ? 1 : -1];

#endif
