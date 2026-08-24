#include "../../include/pnl_drop_context.h"
#define PNL_DROP_CONTEXT

#ifndef PNL_DROP_CONTEXT
struct InnerObj { char pad[0x15C]; int field_15C; };
class SomeClass {
public:
    void set_sorted(int val);
    char pad[0xFC];
    InnerObj* field_FC;
};
#endif
void TDropDownPanel::set_sorted(int val) {
    if (this->list_panel) {
        this->list_panel->sorted = val;
    }
}
