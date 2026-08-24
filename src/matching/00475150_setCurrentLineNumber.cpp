#include "../../include/pnl_drop_context.h"
#define PNL_DROP_CONTEXT

#ifndef PNL_DROP_CONTEXT
class TDropDownPanel {
public:
    void setCurrentLineNumber(int p);
    void set_line(long line);
};
#endif

void TDropDownPanel::setCurrentLineNumber(int p) { this->set_line(p); }
