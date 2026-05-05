// VA: 0047C0B0 TTextPanel::~TTextPanel (106 B)
// PDB source: Pnl_txt.cpp lines 84-92
// Flags: config/flags/0047C0B0_TTextPanel.rsp (default + /GX)
// Key insight: NEVER explicitly call the base destructor in /GX EH-framed
// destructors. VC5 auto-generates the implicit base destructor call, and an
// explicit `TPanel::~TPanel()` creates a duplicate call that shifts the
// EH state machine (extra `call` before `mov [esp+10h], -1`).

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);

class TPanel {
public:
    virtual ~TPanel();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();

    char gap_04[0x17C - 4];
    void* clip_rgn2;   // +0x17C
    int border_size;   // +0x180
    int spacer_size;   // +0x184

    void free_text();
};

TTextPanel::~TTextPanel()
{
    this->free_text();
    if (this->clip_rgn2 != 0) {
        DeleteObject(this->clip_rgn2);
        this->clip_rgn2 = 0;
    }
    // No explicit TPanel::~TPanel() call — VC5 auto-generates it.
    // An explicit call creates a duplicate call before eh_state = -1.
}
