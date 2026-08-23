// VA: 00422030 RGE_Base_Game::show_timings (18 B)
// PDB/Ghidra: protected virtual RGE_Base_Game::show_timings(), basegame.cpp
// lines 4945-4948. The +0x10 window handle and +0x404 timing text offsets
// include the class vptr; the reduced pad preserves that canonical layout.
// Exact-finish notes: the original narrow nonvirtual declaration was an exact
// standalone baseline. A canonical virtual surface first shifted both fields
// by four bytes; changing the pre-handle pad from 0x10 to 0x0C restored exact
// code. The context guard only prevents a duplicate class in the late owner TU.

extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void* hWnd, const char* lpString);

#ifndef BASEGAME_SEGMENT_CONTEXT
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

protected:
    virtual void show_timings();
    char gap_0[0x0C];
    void* hwnd; // offset 0x10
    char gap_14[0x3F0];
    char timing_string[1]; // offset 0x404
};
#else
// The earlier grouped owner surface proves the two offsets but does not name
// these fields. This narrow view accounts for its vptr and no other members.
struct RGE_Base_Game_Show_Timings_Overlay {
    void* vptr;
    char gap_04[0x0C];
    void* hwnd;
    char gap_14[0x3F0];
    char timing_string[1];
};
#endif

void RGE_Base_Game::show_timings()
{
#ifdef BASEGAME_SEGMENT_CONTEXT
    RGE_Base_Game_Show_Timings_Overlay* view =
        (RGE_Base_Game_Show_Timings_Overlay*)this;
    SetWindowTextA(view->hwnd, view->timing_string);
#else
    SetWindowTextA(this->hwnd, this->timing_string);
#endif
}
