#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"
#endif /* PNL_BTN_SHARED_CONTEXT */

// BINARY NOTE: PDB and vtable entries identify this override as TButtonPanel::set_rect.
void TButtonPanel::set_rect(long a, long b, long c, long d) {
    TPanel::set_rect(a, b, c, d);
}
