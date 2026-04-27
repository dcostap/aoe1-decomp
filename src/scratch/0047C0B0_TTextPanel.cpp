// Pnl_txt.cpp:84-92, 106 bytes
// attempt 1: 80 bytes, too small, no /GX
// attempt 2: 55.7%, /GX added but stubs inlined away
// attempt 3: 56.6%, vptr=0 not 571BF8h, cleanup func=0 not 55E598h
// attempt 4: 56.6%, same
// attempt 5: 56.6%, same
// BEST: 55.7%. BLOCKER: vptr set to 0 (not 571BF8h), EH cleanup
//   function is 0 (not 55E598h), instruction ordering differs.
//   /GX needed for EH frame. Core logic (free_text, DeleteObject,
//   base dtor calls) all present but codegen basin differs.
extern int (*DeleteObject)(void*) = 0;

class TPanel {
public:
    virtual void vf00() {}
    ~TPanel() {}
};

class TTTextPanel : public TPanel {
public:
    virtual void vf01() {}
    char gap_04[0x17C - 4];
    void* clip_rgn2;  // +0x17C

    ~TTTextPanel();
};

TTTextPanel::~TTTextPanel() {
    ((void(*)(void*))0x47E380)(this);  // free_text
    if (clip_rgn2 != 0) {
        DeleteObject(clip_rgn2);
        clip_rgn2 = 0;
    }
    ((void(*)(void*))0x4649E0)(this);  // TPanel::~TPanel
}
