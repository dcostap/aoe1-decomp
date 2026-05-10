// Pnl_pic.cpp:153-169, 117 bytes
// attempt 1: 96 bytes, offsets wrong
// attempt 2: 65.8%, offsets correct, no push edi, no redundant test
// attempt 3: 65.8%, same
// attempt 4: 112 bytes, temp var too small
// attempt 5: 65.8%, same as attempt 2
// BEST kept: 65.8% positional, 29.1% edit diff. BLOCKER: VC5 optimizes away
// redundant null test (line 157/164), uses ecx instead of edi, reloads ptr from
// member (not saved in reg). Original has extra push edi/pop edi and redundant
// test edi,edi.
// Additional tries: explicit p/s locals selected desired saved-pointer idea but
// produced 112-byte .text (too small for configured compare); virtual destructors,
// volatile locals, byte-offset member loads, and raw own_pic tests stayed too small.
// Reverted to compiling direct-member source because it is the best validated
// default-flags result. No accepted_drift: broad register/prologue/call-shape drift.
// 2026-05-10 StarryZephyr pass: rechecked baseline and retried explicit p/s locals to
// encourage saved-pointer use. It again produced the 112-byte too-small family, still
// no push edi/redundant test. Restored direct-member baseline.
extern void __cdecl operator_delete(void*);

class TPicture {
public:
    virtual void vf00();
    void destroy();
};

class TShape {
public:
    virtual void vf00();
    void destroy();
};

class TPicturePanel {
public:
    virtual void vf00();
    char gap_04[0x10C - 4];
    void* own_pic;      // +0x10C
    char gap_110[4];
    TPicture* pic;      // +0x114
    TShape* shape;      // +0x118

    void free_pic();
};

void TPicturePanel::free_pic() {
    if (pic != 0) {
        if (own_pic != 0 && pic != 0) {
            pic->destroy();
            operator_delete(pic);
        }
        pic = 0;
    }
    if (shape != 0) {
        if (own_pic != 0 && shape != 0) {
            shape->destroy();
            operator_delete(shape);
        }
        shape = 0;
    }
    own_pic = 0;
}
