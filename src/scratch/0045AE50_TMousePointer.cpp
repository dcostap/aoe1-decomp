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
// Left in scratch: behavior is straightforward but codegen is broad mismatch; not an accepted_drift candidate.

typedef unsigned long ulong;

struct RECT4 {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TShape;
class IDirectDrawSurface;

extern "C" ulong __cdecl debug_timeGetTime(char* file, int line);
#define STR_MOUSEPTR ((char*)0x00584BD0)

class TMousePointer {
public:
    TDrawArea* custom_draw; TDrawArea* render_area; TDrawArea* save_area; TDrawArea* primary_area;
    IDirectDrawSurface* restoreSurface; IDirectDrawSurface* renderSurface;
    TDrawArea* cursors[16]; TShape* Cursor_Shape; int Mouse_Mode; int Max_CX; int Max_CY;
    int cWidth; int cHeight; int gWidth; int gHeight; int mouse_x; int mouse_y; int save_x; int save_y;
    int facet; int game_facet; int next_facet; int last_facet; int d_top; int d_left; int d_bottom; int d_right;
    int g_top; int g_left; int g_bottom; int g_right; int save_area_valid;
    RECT4 save_rect; RECT4 mouse_rect; RECT4 cursor_rect; RECT4 new_save_rect; RECT4 restore_rect;
    char gap_10C[0x10]; int active; int drawn; char gap_124[4]; int Shutdown; int Setup; int GameMode; int GameEnabled;
    int MouseOnScreen; int Num_Cursors; int Max_Cursors; ulong LastDrawTime; long LastddError; char cursor_file[0x104]; int cursor_file_id;
    TMousePointer(int mode);
};

TMousePointer::TMousePointer(int mode)
{
    save_rect.top = 0;
    save_rect.right = 0;
    save_rect.left = 0;
    save_rect.bottom = 0;

    custom_draw = 0;
    render_area = 0;
    mouse_rect = save_rect;
    save_area = 0;
    primary_area = 0;
    Cursor_Shape = 0;
    Max_CX = 0;
    Max_CY = 0;
    cursor_rect = save_rect;
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
    new_save_rect = save_rect;
    d_top = 0;
    d_left = 0;
    d_bottom = 0;
    d_right = 0;
    g_top = 0;
    g_left = 0;
    g_bottom = 0;
    g_right = 0;
    restore_rect = save_rect;
    Shutdown = 0;
    Setup = 0;
    GameMode = 0;
    GameEnabled = 0;
    save_x = -32767;
    save_y = -32767;
    Mouse_Mode = mode;
    active = 0;
    drawn = 0;
    MouseOnScreen = 0;
    Num_Cursors = 0;
    Max_Cursors = 0;
    restoreSurface = 0;
    renderSurface = 0;
    cursor_file_id = -1;
    cursor_file[0] = 0;

    TDrawArea** p = cursors;
    int n = 16;
    do {
        *p++ = 0;
    } while (--n != 0);

    LastDrawTime = debug_timeGetTime(STR_MOUSEPTR, 100);
    LastDrawTime -= 36;
    save_area_valid = 0;
    LastddError = 0;
}
