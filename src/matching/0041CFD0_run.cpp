// VA: 0041CFD0 RGE_Base_Game::run
// PDB source: basegame.cpp lines 1578-1640

#define P_GetMessageA      (*(int (__stdcall **)(void*, void*, unsigned int, unsigned int))0x88A7C0)
#define P_TranslateMessage (*(int (__stdcall **)(void*))0x88A7D0)
#define P_PeekMessageA     (*(int (__stdcall **)(void*, void*, unsigned int, unsigned int, unsigned int))0x88A7D4)
#define P_DispatchMessageA (*(int (__stdcall **)(void*))0x88A7D8)



struct MSG_PART {
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    long pt_x;
    long pt_y;
    int pad_18;
};
struct tagMSG;


int RGE_Base_Game::run()
{
    MSG_PART msg;
    int (__stdcall *translate)(void*) = P_TranslateMessage;
    int (__stdcall *peek)(void*, void*, unsigned int, unsigned int, unsigned int) = P_PeekMessageA;
    int (__stdcall *dispatch)(void*) = P_DispatchMessageA;

    while (1) {
        if (this->prog_active != 0 && (this->prog_mode == 4 || this->prog_mode == 2)) {
            TCommunications_Handler* comm = this->comm_handler;
            if (comm == 0 || comm->IsPaused() == 0) {
                if (peek(&msg.message, 0, 0, 0, 1) != 0) {
                    if (msg.wParam == 0x12) {
                        return msg.lParam;
                    }
                    if (this->handle_message((tagMSG*)&msg.message) != 0) {
                        translate(&msg.message);
                        dispatch(&msg.message);
                    }
                } else {
                    this->handle_idle();
                }
                continue;
            }
        }

        if (P_GetMessageA(&msg.message, 0, 0, 0) == 0) {
            return msg.lParam;
        }
        translate(&msg.message);
        dispatch(&msg.message);
    }
}
