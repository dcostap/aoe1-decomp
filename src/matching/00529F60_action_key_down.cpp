// 00529F60 action_key_down (148 bytes)
// PDB: tribegam.cpp (TRIBE_Game::action_key_down)
//
// Attempt log:
//   ~11 attempts. Main block layout matches (first 75 bytes identical).
//   45 bytes diff remaining: all in the F1 handler (field_1B0 != 1, key == 0x70).
//   Issue: VC5 places F1 handler INLINE (branch: jne to return1 at end) while
//   original places it OUT-OF-LINE (branch: je to F1 handler after return1).
//   All source restructures (goto labels, switch, dead returns, reversed conditions)
//   failed to flip this VC5 heuristic. Left in scratch with correct logic.
//
//   Remaining diff bytes:
//     0x4B-0x51: 74 09 b8 01 00 00 00 5e c2 (je to F1) vs 75 3e ... (jne to return1)
//     0x53-0x5C: c2 14 00 vs various inline F1 code
//     0x5D-0x71: rest of inline F1 handler
//     0x71-0x8B: trailing code (return1 at end vs inline)
//
//   Field offsets verified against wnd_proc (00529580):
//     [esi+0x1B0] = field_1B0 (game mode?)
//     [esi+0x10]  = field_10 (window handle for WinHelpA)

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Base_Game {
public:
    void* vtable;
    char gap_04[0x0C];
    int field_10;
    char gap_14[0x19C];
    int field_1B0;
    char gap_1B4[0x24];
    int field_1D8;

    int multiplayerGame();
};
#endif

#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game : public RGE_Base_Game {
public:
    void stop_video(unsigned char callback);
    int action_key_down(unsigned int key, int param_2, int param_3, int param_4, int param_5);
};
#endif

extern void (__stdcall *WinHelpA_tribe)(int, const char*, int, int);

int TRIBE_Game::action_key_down(unsigned int key, int param_2, int param_3, int param_4, int param_5)
{
    if (this->prog_mode == 1) {
        switch (key) {
        case 0x0D:
        case 0x20:
            this->stop_video(1);
            return 0;
        case 0x1B:
            this->stop_video(0);
            return 0;
        }
        return 1;
    }

    if (key != 0x70) {
        return 1;
    }
    if (!this->multiplayerGame() || (this->prog_mode != 4 && this->prog_mode != 6 && this->prog_mode != 7 && this->prog_mode != 5)) {
        WinHelpA_tribe((int)this->prog_window, "empires.hlp", 3, 0);
    }
    return 0;
}
