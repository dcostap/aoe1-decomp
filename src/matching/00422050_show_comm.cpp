// VA: 00422050 RGE_Base_Game::show_comm (64 B)
// PDB source: basegame.cpp:4954-4960
// The target is the first owner after the proven late basegame segment.
// Keep the panel and communications fields at their binary offsets.
// Exact-finish notes: the prior public narrow class was an exact standalone
// body, but its owner symbol used public access. The canonical protected
// virtual declaration now emits the PDB owner symbol without changing bytes.
// A fresh /O2 /Oy /GX grouped compile of basegame_late_tu.cpp extracts the
// same 64-byte body after its four compatible relocations are masked, and
// reaches the end of show_comm at 00422090.
// BINARY NOTE: GetCommInfo reads comm_handler first. sprintf then formats its
// result, and SetWindowTextA rereads prog_window before the final publication.
// Keep these direct expressions. They preserve call order, invalid-state
// faults, malformed input state, the shared local-buffer address, and the
// imported global call. No null or string validation is added.
class TCommunications_Handler;

#ifndef BASEGAME_SEGMENT_CONTEXT
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

protected:
    virtual void show_comm(void);
    char gap_04[0x0C];
    void* prog_window;
    char gap_14[0x178];
    TCommunications_Handler* comm_handler;
};
#else
// The preceding authentic owner supplies the canonical class and virtual
// surface. This narrow view names only the two fields proved by this method.
struct RGE_Base_Game_Show_Comm_Overlay {
    char gap_00[0x10];
    void* prog_window;
    char gap_14[0x178];
    TCommunications_Handler* comm_handler;
};
#endif

class TCommunications_Handler {
public:
    char* GetCommInfo(unsigned char param_1);
    void SetMyGameOptions(char* data, int size);
#ifdef BASEGAME_SEGMENT_CONTEXT
    void* GetMyGameOptions(unsigned long* size);
#endif
};

extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_comm(void) {
    char str[256];
#ifdef BASEGAME_SEGMENT_CONTEXT
    RGE_Base_Game_Show_Comm_Overlay* view =
        (RGE_Base_Game_Show_Comm_Overlay*)this;
    sprintf(str, "%s", view->comm_handler->GetCommInfo(1));
    SetWindowTextA(view->prog_window, str);
#else
    sprintf(str, "%s", this->comm_handler->GetCommInfo(1));
    SetWindowTextA(this->prog_window, str);
#endif
}
