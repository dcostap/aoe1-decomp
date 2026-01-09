#pragma once
#include "common.h"

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TTextPanel* message;                     // 0x478

    TRIBE_Screen_Status_Message(char* param_1, char* param_2, char* param_3, long param_4);
    TRIBE_Screen_Status_Message(char* param_1, long param_2, char* param_3, long param_4);
    ~TRIBE_Screen_Status_Message();
    void set_text(char* param_1);
    void set_text(long param_1);
};

static_assert(sizeof(TRIBE_Screen_Status_Message) == 0x47C, "TRIBE_Screen_Status_Message Size Mismatch");

