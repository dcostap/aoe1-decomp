// 00529F60 action_key_down (148 bytes)
// PDB: tribegam.cpp (TRIBE_Game::action_key_down)
//
// Earlier isolated source placed the F1 handler in the wrong block.
// The authentic grouped context restores the shipped block order and exact bytes.
// Field ownership is proved by wnd_proc at 00529580.

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
    virtual int action_key_down(unsigned long key, int param_2, int param_3,
                                int param_4, int param_5);
};
#endif

extern void (__stdcall *WinHelpA_tribe)(int, const char*, int, int);

int TRIBE_Game::action_key_down(unsigned long key, int param_2, int param_3,
                                int param_4, int param_5)
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
