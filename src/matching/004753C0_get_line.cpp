#include "../../include/pnl_drop_context.h"
#define PNL_DROP_CONTEXT

#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
    long get_line(char* param);
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_line(char* param);
};
#endif

int TDropDownPanel::get_line(char* param) {
    if (this->member_FC) {
        return this->member_FC->get_line(param);
    }
    return 0;
}
