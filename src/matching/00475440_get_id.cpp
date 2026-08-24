#include "../../include/pnl_drop_context.h"
#define PNL_DROP_CONTEXT

#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_id(long param);
};
#endif

int TDropDownPanel::get_id(long param) {
    if (this->member_FC) {
        return this->member_FC->get_id(param);
    }
    return 0;
}
