#ifndef SCR_MPS_TU_CONTEXT
#include "../scr_mps_set_text_context.h"
class TRIBE_Screen_Disconnect {
public:
    char gap_0[0x47C];
    TTextPanel* member_47C;

    void set_text(char* param);
};
#endif

void TRIBE_Screen_Disconnect::set_text(char* param) {
    this->member_47C->set_text(param);
}
