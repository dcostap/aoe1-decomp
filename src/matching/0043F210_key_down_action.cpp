#ifdef DLG_LIST_SHARED_CONTEXT
#include "../../include/dlg_list_context.h"
#else
class TListDialog {
public:
    virtual ~TListDialog();
    long key_down_action(long p0, short p1, int p2, int p3, int p4);
};
#endif

long TListDialog::key_down_action(long p0, short p1, int p2, int p3, int p4) { return 0; }
