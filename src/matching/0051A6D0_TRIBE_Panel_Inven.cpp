// Destructor for TRIBE_Panel_Inven
// /GX is required here: the original has VC5 EH registration and destructor state tracking.

extern "C" void __cdecl free(void* block);
extern int TRIBE_Panel_Inven_vftable[];

#include "../../include/tpnl_inv_context.h"

TRIBE_Panel_Inven::~TRIBE_Panel_Inven() {
    if (this->save_attr != 0) {
        free(this->save_attr);
        this->save_attr = 0;
    }
    TShape* pics = (TShape*)this->pics;
    if (pics != 0) {
        delete pics;
        this->pics = 0;
    }
    this->TPanel::~TPanel();
}
