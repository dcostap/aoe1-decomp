// VA: 0047A8A0 TScrollBarPanel::~TScrollBarPanel
// PDB: Pnl_scbr.cpp line 82
// BINARY NOTE: The shipped body stores the derived vptr, then tail-jumps to
// TPanel::~TPanel. Naming the real TPanel base recovers both relocations.
#ifndef PNL_SCBR_CANONICAL_TU
class TPanel {
public:
    virtual ~TPanel();
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};
#endif

TScrollBarPanel::~TScrollBarPanel() {
}
