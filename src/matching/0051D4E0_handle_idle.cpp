// PDB: C:\\msdev\\work\\age1_x1\\tpnl_pop.cpp:313-328.
// Qualified owner: ?handle_idle@TRIBE_Panel_Pop@@UAEJXZ.

#ifndef TPNL_POP_SHARED_CONTEXT
class TPanel {
public:
    long handle_idle();
};

class TRIBE_Panel_Pop : public TPanel {
public:
    long handle_idle();
};
#endif

long TRIBE_Panel_Pop::handle_idle() {
    TPanel::handle_idle();
    return 0;
}
