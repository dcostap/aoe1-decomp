// VA: 0045B760 TMousePointer::update_mouse_position
// PDB source: Mouseptr.cpp lines 567-717
// attempt log:
// 1: helper body with decompiler fields compiled but treated this as stack parameter; 88.21% positional diff.
// 2: switched to Poll.cpp TMousePointer field layout; body shrank to 752 bytes, close early WinAPI/point conversion but wrong this-load/prologue and game-window offsets.
// 3: tried free __fastcall wrapper to force ECX; VC5/build extraction still selected stack-this family, no improvement.
// 4: corrected game/window field order from Poll.cpp; early bounds now use +118/+11C etc, proving layout mismatch with this function's observed +138/+13C remains.
// 5: kept natural RECT assignment for cursor_rect=new_save_rect; size near original but scheduling/registers differ through clipping tail.
// left in scratch: needs exact TMousePointer layout for Mouseptr.cpp around +0x138/+0x140 and method/prototype context that preserves ECX this.

typedef unsigned char uchar;
struct POINT { long x; long y; };
struct RECT4 { long left; long top; long right; long bottom; };
extern "C" int (__stdcall* const GetCursorPos)(POINT*);
extern "C" int (__stdcall* const ScreenToClient)(void*, POINT*);

struct TDrawSystem { char gap[0x479]; uchar ScreenMode; };
class TDrawArea { public: TDrawSystem* DrawSystem; void* Wnd; char gap08[0x10]; int Width; int Height; };
class TShape;

class TMousePointer {
public:
    TDrawArea* custom_draw; TDrawArea* render_area; TDrawArea* save_area; TDrawArea* primary_area;
    char gap_10[8]; TDrawArea* cursors[16]; TShape* Cursor_Shape; int Mouse_Mode; int Max_CX; int Max_CY;
    int cWidth; int cHeight; int gWidth; int gHeight; int mouse_x; int mouse_y; int save_x; int save_y;
    int facet; int game_facet; int next_facet; int last_facet; int d_top; int d_left; int d_bottom; int d_right;
    int g_top; int g_left; int g_bottom; int g_right; int save_area_valid;
    RECT4 save_rect; RECT4 mouse_rect; RECT4 cursor_rect; RECT4 new_save_rect; RECT4 restore_rect;
    char gap_10C[0x10]; void* restoreSurface; char gap_120[4]; void* PrimarySurface; int active; int drawn; int Shutdown; int Setup; int GameMode; int GameEnabled;
    int MouseOnScreen; unsigned long LastDrawTime; long LastddError;
};

int __fastcall update_mouse_position(TMousePointer* this_, int unused) {
#define this this_
    POINT point;
    int in_game;
    if (this->custom_draw == 0) return 0;
    GetCursorPos(&point);
    if (this->render_area->DrawSystem->ScreenMode == 1) {
        ScreenToClient(this->render_area->Wnd, &point);
        if (point.x > 0x8000) point.x -= 0x10000;
        if (point.y > 0x8000) point.y -= 0x10000;
    }
    this->mouse_x = point.x;
    this->mouse_y = point.y;
    if (this->GameMode != 0 && this->GameEnabled != 0 && this->mouse_x >= this->g_top && this->mouse_x < this->g_bottom && point.y >= this->g_left && point.y < this->g_right) {
        this->next_facet = this->game_facet; in_game = 1;
    } else {
        this->next_facet = this->facet; in_game = 0;
    }
    if (this->save_area_valid != 0 && point.x == this->save_x && point.y == this->save_y && this->next_facet == this->last_facet) return 0;
    this->save_x = point.x; this->save_y = point.y;
    this->new_save_rect.left = 0; this->new_save_rect.top = 0;
    if (in_game != 0) {
        this->new_save_rect.bottom = this->gHeight;
        this->new_save_rect.right = this->gWidth;
        this->mouse_rect.left = this->mouse_x - this->g_left;
        this->mouse_rect.top = this->mouse_y - this->g_top;
        this->mouse_rect.right = this->g_right + this->mouse_x;
    } else {
        this->new_save_rect.right = this->cWidth;
        this->new_save_rect.bottom = this->cHeight;
        this->mouse_rect.left = this->mouse_x - this->d_left;
        this->mouse_rect.top = this->mouse_y - this->d_top;
        this->mouse_rect.right = this->d_right + this->mouse_x;
    }
    this->mouse_rect.bottom = (in_game ? this->g_bottom : this->d_bottom) + this->mouse_y;
    this->cursor_rect = this->new_save_rect;
    if (this->mouse_rect.right >= 0 && this->mouse_rect.bottom >= 0) {
        TDrawArea* da = this->render_area;
        if (this->mouse_rect.left <= da->Width && this->mouse_rect.top <= da->Height) {
            if (this->mouse_rect.left < 0) { this->cursor_rect.left = -this->mouse_rect.left; this->new_save_rect.right -= this->cursor_rect.left; this->mouse_rect.left = 0; }
            if (this->mouse_rect.right > da->Width) { int t = this->mouse_rect.right - da->Width; this->cursor_rect.right -= t; this->new_save_rect.right -= t; this->mouse_rect.right = da->Width; }
            if (this->mouse_rect.top < 0) { this->cursor_rect.top = -this->mouse_rect.top; this->new_save_rect.bottom -= this->cursor_rect.top; this->mouse_rect.top = 0; }
            if (this->mouse_rect.bottom > da->Height) { int t = this->mouse_rect.bottom - da->Height; this->cursor_rect.bottom -= t; this->new_save_rect.bottom -= t; this->mouse_rect.bottom = da->Height; }
            this->MouseOnScreen = 1; return 1;
        }
    }
    this->MouseOnScreen = 0; return 1;
#undef this
}
