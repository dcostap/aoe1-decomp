// 00476040 TEditPanel::sub_wnd_proc
// Attempt log:
// try 1: packet-grounded reconstruction of edit-control subclass procedure. Models paint/erase handling, keyboard forwarding, IME/context/menu bypass, scroll/caret synchronization, and mouse coordinate forwarding. Current source compiles too short (880B vs 994B).
// try 2: fixed local virtual surface and callback signatures enough to compile; still too short, indicating missing original branch/helper topology.
// try 3: temporary diagnostic extra SendMessage/Invalidate/HideCaret branch only reached 928B and was removed; no byte compare reached.
// try 4: modeled WM_PAINT/WM_ERASEBKGND paths: InvalidateRect and SelectObject/GetClientRect/FillRect with brush at +0x108.
// try 5: modeled key-message switch 0x100..0x104, parent filter at vtable +0x48, TAB GetKeyState(Alt/Ctrl/Shift), global +0x86b240 guard, parent command callback, Return/Escape handling.
// try 6: modeled no-parent Escape path with SendMessage(hwnd,0xc7,0,0), TAB swallow, and filter_key fallback.
// try 7: modeled WM_MOUSEMOVE/IME-ish 0x200 path through rge_base_game +0x1d0 and global +0x62c4c4/FUN_004203E0.
// try 8: modeled default edit proc forwarding plus EM_GETSEL before/after, InvalidateRect/HideCaret on selection change, update_from_edit on 0x302.
// try 9: modeled mouse button messages 0x201/0x202/0x204/0x205 by rebasing lParam through panel offsets +0xc/+0x10 and forwarding through router object.
// GIVEUP blockers: exact Win32/IAT import declarations and calling conventions, true TEditPanel/parent virtual layout at +0x48/+0xb4, correct DefWindowProc vs original subclass proc surface, and stack-local RECT/selection slot topology. No inline asm used; no accepted_drift proposal.

typedef unsigned int UINT;
typedef long LPARAM;
typedef unsigned int WPARAM;
typedef void* HWND;
typedef void* HDC;
typedef void* HBRUSH;
struct RECT { long left, top, right, bottom; };

extern "C" int __stdcall InvalidateRect(HWND, RECT*, int);
extern "C" void* __stdcall SelectObject(HDC, void*);
extern "C" int __stdcall GetClientRect(HWND, RECT*);
extern "C" int __stdcall FillRect(HDC, RECT*, HBRUSH);
extern "C" short __stdcall GetKeyState(int);
extern "C" long __stdcall SendMessageA(HWND, UINT, WPARAM, LPARAM);
extern "C" HWND __stdcall GetFocus();
extern "C" int __stdcall HideCaret(HWND);
extern "C" int __stdcall GetCaretPos(void*);
extern "C" int __stdcall ClientToScreen(HWND, void*);
extern "C" int __stdcall ScreenToClient(HWND, void*);
extern "C" int __stdcall SetCaretPos(int,int);
extern "C" long __stdcall DefWindowProcA(HWND, UINT, WPARAM, LPARAM);
extern int DAT_0086b240;
extern int DAT_0062c4c4;
class BaseGame { public: char gap[0x1d0]; int imeFlag; };
extern BaseGame* rge_base_game;
extern "C" void FUN_004203E0();
class SomePanel { public:
    virtual void f00(); virtual void f01(); virtual void f02(); virtual void f03(); virtual void f04(); virtual void f05(); virtual void f06(); virtual void f07(); virtual void f08(); virtual void f09(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual long key(HWND,UINT,WPARAM,LPARAM);
    virtual void g00(); virtual void g01(); virtual void g02(); virtual void g03(); virtual void g04(); virtual void g05(); virtual void g06(); virtual void g07(); virtual void g08(); virtual void g09(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15(); virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19(); virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23(); virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29(); virtual void g30(); virtual void g31(); virtual void g32(); virtual void g33(); virtual void g34(); virtual void g35(); virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39(); virtual void g40(); virtual void g41(); virtual void g42(); virtual void g43();
    virtual long command(void*,int,int,int);
};
class RouteObj { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual long route(HWND,UINT,WPARAM,LPARAM); };
extern RouteObj* get_router_00463D00(void*);

class TEditPanel {
public:
    void* vt; char gap04[0x1c]; void** owner; char gap24[0x1c]; SomePanel* parent; char gap44[0x28]; void* hwnd2; void* hwnd3;
    char gap74[0x80]; HWND hwnd; char gapf8[0x0c]; int locked; HBRUSH brush; char gap10c[4]; HWND editHwnd; char gap114[0x4c]; int ime1; int ime2;
    long sub_wnd_proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int filter_key(WPARAM vk);
    void update_from_edit();
};

long TEditPanel::sub_wnd_proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    RECT rc;
    int oldStart = 0, newStart = 0, oldEnd = 0, newEnd = 0;
    long ret = 0;

    if (this->hwnd && this->hwnd2 && this->hwnd3 && !this->locked) {
        if (msg == 0x0f) {
            InvalidateRect(hwnd, 0, 1);
        } else if (msg == 0x14) {
            if (this->brush) {
                HDC hdc = (HDC)wParam;
                SelectObject(hdc, this->brush);
                GetClientRect(hwnd, &rc);
                FillRect(hdc, &rc, this->brush);
                return 1;
            }
        } else if (msg <= 0x200) {
            switch (msg) {
            case 0x100:
            case 0x101:
            case 0x102:
            case 0x103:
            case 0x104:
                if (this->parent) {
                    if (this->parent->key(hwnd, msg, wParam, lParam)) return 0;
                    if (wParam == 9) {
                        int s = GetKeyState(0x12) < 0;
                        int c = GetKeyState(0x11) < 0;
                        int sh = GetKeyState(0x10) < 0;
                        DAT_0086b240 = 1;
                        this->parent->command((void*)9, s, c, sh);
                        DAT_0086b240 = 0;
                        return 0;
                    }
                    if (wParam == 0x0d) {
                        this->parent->command(this,0,0,0);
                        return 0;
                    }
                    if (wParam == 0x1b) {
                        if (!this->parent->command(this,1,0,0)) {
                            SendMessageA(this->hwnd,0xc7,0,0);
                            return 0;
                        }
                        return 0;
                    }
                } else if (wParam == 0x1b) {
                    SendMessageA(this->hwnd,0xc7,0,0);
                    return 0;
                }
                if (wParam == 9) return 0;
                if (!this->filter_key(wParam)) return 0;
                break;
            case 0x200:
                if (!rge_base_game->imeFlag) { DAT_0062c4c4 = 1; FUN_004203E0(); }
                break;
            }
        }
    }

    if (this->hwnd && msg != 0xb0) {
        SendMessageA(this->hwnd,0xb0,(WPARAM)&newStart,(LPARAM)&oldStart);
        ret = DefWindowProcA(hwnd,msg,wParam,lParam);
        if (wParam) {
            SendMessageA(this->hwnd,0xb0,(WPARAM)&oldEnd,(LPARAM)&newEnd);
            if (oldEnd != newStart || newEnd != oldStart) {
                InvalidateRect(this->hwnd,0,1);
                HideCaret(this->hwnd);
            }
        }
        if (msg == 0x302) this->update_from_edit();
        if (msg == 0x201 || msg == 0x202 || msg == 0x204 || msg == 0x205) {
            long x = (lParam & 0xffff) + (long)this->owner;
            long y = ((unsigned long)lParam >> 16) + (long)this->hwnd2;
            RouteObj* r = get_router_00463D00((void*)0x62e870);
            ret = r->route((HWND)this->owner[1], msg, wParam, (y << 16) | (x & 0xffff));
        }
        return ret;
    }
    ret = DefWindowProcA(hwnd,msg,wParam,lParam);
    return ret;
}
