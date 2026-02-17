#pragma once
#include "common.h"
#include "TScreenPanel.h"

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TRIBE_Screen_Status_Message(char* panel_name, char* text, char* info_file, long info_id);
    TRIBE_Screen_Status_Message(char* panel_name, long text_id, char* info_file, long info_id);

    virtual ~TRIBE_Screen_Status_Message(); // vt[0] (0x0)

    void set_text(char* text);
    void set_text(long text_id);

    TTextPanel* message;
};
static_assert(sizeof(TRIBE_Screen_Status_Message) == 0x47C, "Size mismatch");
