#ifndef SCR_MPS_TU_CONTEXT
#include "../scr_mps_set_text_context.h"
class TRIBE_Screen_Wait {
public:
    char gap_0[0x478];
    TTextPanel* member_478;

    void set_text(long param);
};
#endif

void TRIBE_Screen_Wait::set_text(long param) {
    this->member_478->set_text(param);
}
