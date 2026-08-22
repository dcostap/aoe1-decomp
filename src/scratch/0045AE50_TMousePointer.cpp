// 0045AE50 TMousePointer::TMousePointer
// Source: Mouseptr.cpp lines 27-106
// Attempt log:
// 1: natural field-layout constructor from packet/decompiler; broad mismatch, but prologue/tail and cursor rep-stos loop close.
// 2: raw offset stores in original asm order; worsened because VC5 no longer kept save_rect base pointer/copy loads.
// 3: decompiler-style explicit lVar temps; worsened because VC5 proved the zero source and emitted direct stores.
// 4: aggregate RECT assignments are needed for the load/copy family, but VC5 reschedules independent zero stores too broadly.
// 5: tried raw pointer copy blocks with macros; generated fewer instructions and direct [esi+offset] loads, not original lea/copy shape.
// 6: restored natural source as best readable scratch basis.
// 7: expanded RECT aggregate assignments into per-field copies; worsened badly, so aggregate assignments are closer.
// 8: rewrote cursor zero loop as explicit pointer do/while; same codegen as for-loop (rep stosd), kept acceptable spelling.
// 9: split LastDrawTime assignment/subtract into two statements; no codegen change.
// 10: class-field declaration compaction did not affect emitted code; remaining blocker is broad VC5 store scheduling around RECT copies and zero stores.
// 11: corrected the constructor's canonical class order: Num_Cursors/Max_Cursors
// are at +10/+14, the cursor array starts at +18, and the surface pointers are
// at +11C/+120/+124. This is required by sibling Mouseptr methods and the type dump.
// 12: reordered RECT zero statements; size improved by four bytes but the copy
// schedule became less like the target, so restored the source order.
// 13: an explicit save_rect pointer improved resync metrics but added an early
// mouse_rect LEA and changed the first hunk; restored aggregate member copies.
// 14: PDB-guided state-order probes did not improve the canonical source basin.
// 15: restored the natural indexed cursor loop; VC5 still emits rep stosd.
// 16: chained RECT zero assignment changed the first hunk and was rolled back.
// Final: canonical layout and readable aggregate RECT initialization retained;
// no EH frame, vptr, member lifetime, or destructor work is proven for this body.
// Recovery probes: original Ghidra interleaving with a named RECT pointer and
// scalar copy temporaries grew the body to 477-483 bytes and was rolled back.
// A PDB-guided tail assignment order kept the 357-byte diff but did not improve
// positional output; the aggregate source order remains the clean basis.
// Fresh claim probe: binary-observed per-member RECT copy order grew the body
// by 58 bytes and moved the first mismatch to the prologue; rolled back.
// Fresh claim probe: moved the natural mouse_rect aggregate copy before the
// independent custom_draw/render_area stores; diff improved 357 -> 354 bytes,
// but the first mismatch stayed at save_rect scheduling. Kept this source order.
// Fresh claim probe: a named RECT4* save_rect_ptr for all aggregate copies
// follows the target's long-lived save_rect base and Ghidra's ptVar1 alias;
// diff improved 354 -> 340 bytes, size 425 -> 416, and shape 52.29 -> 53.21.
// Kept as the best typed reconstruction; first mismatch remains save_rect init.
// Fresh claim probes: direct top/right/bottom stores, full scalar Ghidra copies,
// SDK header context, canonical long widths, and mixed aggregate aliases did
// not beat the typed source. A target-PDB tail order moved diff 340 -> 338 and
// shape 53.21 -> 63.30 with the same 416-byte body; retained as current basis.
// Cursor-only and restore-only scalar interleaves increased size or diff.
// Revisit probe: the complete typed scalar RECT interleave reconstructed from
// the Ghidra statements grew the body to 471 bytes and worsened the diff to
// 419 bytes. Restored the natural aggregate-copy source.
// Revisit probes: replaced the forbidden absolute source-string address with
// the proven Mouseptr.cpp literal; strict diff stayed 338. Added the typed
// game_window RECT and long coordinate fields from the local type dump; bytes
// stayed unchanged. Direct aggregate copies from this->save_rect worsened to
// 354 bytes, while moving mouse_rect after the first pointer stores gave 339;
// both were rolled back. A const RECT alias and SDK RECT context were neutral.
// The direct per-field Ghidra interleave grew to 483 bytes and was rolled back.
// Left in scratch: behavior is straightforward but codegen is broad mismatch; not an accepted_drift candidate.
// Current-claim probes: direct top/right/bottom stores with a pointer-only left
// store improved shape but worsened strict diff to 343-359 bytes; changing the
// pointer declaration point did not recover the target hunk. Full member
// declarations and period string/stdio headers were codegen-neutral. A scalar
// mouse_rect copy worsened shape and strict diff. Moving the aggregate copy
// after the four initial area stores kept strict diff at 338 and improved only
// resync diagnostics; a cWidth reorder worsened strict diff to 339. Restored
// the pinned pointer-based aggregate source; the first mismatch remains at
// save_rect initialization (+0D).

#include <windows.h>

typedef unsigned long ulong;
typedef RECT RECT4;

class TDrawArea;
class TShape;
class IDirectDrawSurface;

extern "C" ulong __cdecl debug_timeGetTime(char* file, int line);

class TMousePointer {
public:
    int custom_draw; TDrawArea* render_area; TDrawArea* save_area; TDrawArea* primary_area;
    int Num_Cursors; int Max_Cursors; TDrawArea* cursors[16];
    TShape* Cursor_Shape; int Mouse_Mode; int Max_CX; int Max_CY;
    int cWidth; int cHeight; int gWidth; int gHeight; long mouse_x; long mouse_y; long save_x; long save_y;
    int facet; int game_facet; int next_facet; int last_facet; int d_top; int d_left; int d_bottom; int d_right;
    int g_top; int g_left; int g_bottom; int g_right; int save_area_valid;
    RECT4 save_rect; RECT4 mouse_rect; RECT4 cursor_rect; RECT4 new_save_rect; RECT4 restore_rect;
    RECT4 game_window; IDirectDrawSurface* restoreSurface; IDirectDrawSurface* renderSurface;
    IDirectDrawSurface* PrimarySurface; int active; int drawn; int Shutdown; int Setup; int GameMode; int GameEnabled;
    int MouseOnScreen; ulong LastDrawTime; long LastddError; char cursor_file[0x104]; int cursor_file_id;
    TMousePointer(int mode);
};

TMousePointer::TMousePointer(int mode)
{
    RECT4* save_rect_ptr = &this->save_rect;

    save_rect_ptr->top = 0;
    save_rect_ptr->right = 0;
    save_rect_ptr->left = 0;
    save_rect_ptr->bottom = 0;

    mouse_rect = *save_rect_ptr;
    custom_draw = 0;
    render_area = 0;
    save_area = 0;
    primary_area = 0;
    Cursor_Shape = 0;
    Max_CX = 0;
    Max_CY = 0;
    cursor_rect = *save_rect_ptr;
    cWidth = 0;
    cHeight = 0;
    gWidth = 0;
    gHeight = 0;
    mouse_x = 0;
    mouse_y = 0;
    facet = 0;
    game_facet = 0;
    next_facet = 0;
    last_facet = 0;
    new_save_rect = *save_rect_ptr;
    d_top = 0;
    d_left = 0;
    d_bottom = 0;
    d_right = 0;
    g_top = 0;
    g_left = 0;
    g_bottom = 0;
    g_right = 0;
    active = 0;
    drawn = 0;
    restore_rect = *save_rect_ptr;
    Shutdown = 0;
    Setup = 0;
    save_x = -32767;
    save_y = -32767;
    Mouse_Mode = mode;
    restoreSurface = 0;
    renderSurface = 0;
    GameMode = 0;
    GameEnabled = 0;
    MouseOnScreen = 0;
    Num_Cursors = 0;
    Max_Cursors = 0;
    cursor_file_id = -1;
    cursor_file[0] = 0;

    for (int i = 0; i < 16; ++i) {
        cursors[i] = 0;
    }

    LastDrawTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 100);
    LastDrawTime -= 36;
    save_area_valid = 0;
    LastddError = 0;
}
