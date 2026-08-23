// VA: 00492F80 TScrollTextPanel::set_text
// PDB donor: scr_cred.cpp lines 465-470

#include "../../include/scr_cred_context.h"

void TScrollTextPanel::set_text(char* text) {
    TTextPanel::set_text(text);
    this->last_time = 0;
    this->scroll = 0;
    this->done = 0;
}
