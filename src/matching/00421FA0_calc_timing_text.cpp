// VA: 00421FA0 RGE_Base_Game::calc_timing_text (144 B)
// PDB source: basegame.cpp
// Packet-grounded: divide timing counters by frame_count, sprintf
// Attempt log:
// try 1: inherited free-function shim saved EDI and used signed idiv/reversed eval order; broad mismatch.
// try 2: converted to real thiscall method with unsigned fields; still saved EDI and C vararg evaluation reversed the push/div order.
// try 3: reversed source varargs to match original push/eval order; order much better but still saved EDI for divisor and used ESI for buffer base.
// try 4: register-qualified divisor and used direct `(char*)this + offset` expressions instead of a named base local; this kept divisor in ESI, let VC5 adjust ECX by +0x404, and MATCHED.
// ABI audit: the PDB owner is protected virtual.  The declaration keeps the
// virtual destructor and +0x404 timing-text offset, and emits MAEXXZ.
// Grouped-context audit: the complete predecessor class changed this method's
// basin by 122 relocation-masked bytes. A narrow, vptr-accounted view of the
// two proven counter fields restores the original 144-byte grouped output.

extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);

#ifndef BASEGAME_SEGMENT_CONTEXT
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char pad0[0x400];
    char timing_text[0x100];       // +0x404
    unsigned long frame_count;     // +0x504
    char pad508[0x52C - 0x508];
    unsigned long fps;             // +0x52C

protected:
    virtual void calc_timing_text();
};
#define BASEGAME_TIMING_FRAME_COUNT (this->frame_count)
#define BASEGAME_TIMING_FPS (this->fps)
#else
// The grouped predecessor proves the complete owner class, but this method's
// exact local basin uses only the two named counter fields below.
struct RGE_Base_Game_Timing_Text_Overlay {
    void* vptr;
    char pad0[0x400];
    char timing_text[0x100];
    unsigned long frame_count;
    char pad508[0x52C - 0x508];
    unsigned long fps;
};
#define BASEGAME_TIMING_FRAME_COUNT \
    (((RGE_Base_Game_Timing_Text_Overlay*)this)->frame_count)
#define BASEGAME_TIMING_FPS \
    (((RGE_Base_Game_Timing_Text_Overlay*)this)->fps)
#endif

void RGE_Base_Game::calc_timing_text()
{
    register unsigned long divisor = BASEGAME_TIMING_FRAME_COUNT;
    if (divisor == 0)
        divisor = 1;

    sprintf(
        (char*)this + 0x404,
        "fps=%lu, rend=%lu, view=%lu, map=%lu, scr=%lu, draw=%lu, prog=%lu, ui=%lu, sfx=%lu, misc=%lu",
        *(unsigned long*)((char*)this + 0x51C),
        *(unsigned long*)((char*)this + 0x56C) / divisor,
        *(unsigned long*)((char*)this + 0x5EC) / divisor,
        *(unsigned long*)((char*)this + 0x60C) / divisor,
        *(unsigned long*)((char*)this + 0x58C) / divisor,
        *(unsigned long*)((char*)this + 0x54C) / divisor,
        *(unsigned long*)((char*)this + 0x66C) / divisor,
        *(unsigned long*)((char*)this + 0x6CC) / divisor,
        *(unsigned long*)((char*)this + 0x5AC) / divisor,
        BASEGAME_TIMING_FPS / divisor
    );
}

#undef BASEGAME_TIMING_FRAME_COUNT
#undef BASEGAME_TIMING_FPS
