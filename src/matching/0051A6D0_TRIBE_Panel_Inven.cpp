// Destructor for TRIBE_Panel_Inven
// /GX is required here: the original has VC5 EH registration and destructor state tracking.

extern "C" void __cdecl free(void* block);
extern int TRIBE_Panel_Inven_vftable[];

#ifndef TPNL_INV_SHARED_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TShape {
public:
    ~TShape();
};

class TRIBE_Panel_Inven : public TPanel {
public:
    void* pics;                 // +0F4h
    void* player;               // +0F8h
    short save_attr_num;        // +0FCh
    short gap_FE;
    short* save_attr;           // +100h

    virtual ~TRIBE_Panel_Inven();
};
#else
#include "../../include/tpnl_inv_context.h"
#endif

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
