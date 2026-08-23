// VA: 0041CFD0 RGE_Base_Game::run
// PDB source: basegame.cpp lines 1578-1640

#define P_GetMessageA      (*(int (__stdcall **)(void*, void*, unsigned int, unsigned int))0x88A7C0)
#define P_TranslateMessage (*(int (__stdcall **)(void*))0x88A7D0)
#define P_PeekMessageA     (*(int (__stdcall **)(void*, void*, unsigned int, unsigned int, unsigned int))0x88A7D4)
#define P_DispatchMessageA (*(int (__stdcall **)(void*))0x88A7D8)

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

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

#ifndef BASEGAME_GROUPED_TU
class TCommunications_Handler {
public:
    int IsPaused();
};

class RGE_Base_Game {
public:
    VPAD32(0)
    VPAD8(32)
    VPAD4(40)
    VPAD2(44)
    virtual int translate_message(void* msg); // slot 46, +0xB8
    virtual void idle();                      // slot 47, +0xBC

    char gap_004[0x18 - 0x004];
    int prog_active;                          // +0x18
    char gap_01C[0x18C - 0x01C];
    TCommunications_Handler* comm_handler;    // +0x18C
    char gap_190[0x1B0 - 0x190];
    int prog_mode;                            // +0x1B0

    int run();
};
#endif

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
#ifdef BASEGAME_GROUPED_TU
                    if (this->handle_message((tagMSG*)&msg.message) != 0) {
#else
                    if (this->translate_message(&msg.message) != 0) {
#endif
                        translate(&msg.message);
                        dispatch(&msg.message);
                    }
                } else {
#ifdef BASEGAME_GROUPED_TU
                    this->handle_idle();
#else
                    this->idle();
#endif
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
