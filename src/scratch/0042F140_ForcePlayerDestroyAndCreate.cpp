// tried a direct member-call version, then a cdecl Log wrapper with the handler passed as an extra arg; mismatch stayed at the early log-call prolog
// kept the vtable callback and AddSelfPlayer transition, but VC5 is still taking a different global-load / argument-push basin
// leaving in scratch: remaining delta is instruction order before the first Log call

class TDebuggingLog;
class TCommunications_Handler;
extern "C" void __cdecl Log(TDebuggingLog* log, const char* text, ...);

class TCommunications_Handler {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(int value);
    void AddSelfPlayer();
    void ForcePlayerDestroyAndCreate();
};

extern TDebuggingLog* DAT_0062C4FC;
extern TCommunications_Handler* DAT_0062C5EC;
extern int DAT_0062CF04;
extern const char* s_Force_Self_player_destroy_and_create;
extern const char* s_Create_called;

void TCommunications_Handler::ForcePlayerDestroyAndCreate() {
    Log(DAT_0062C4FC, s_Force_Self_player_destroy_and_create, this);
    DAT_0062C5EC->vf24(DAT_0062CF04);
    DAT_0062CF04 = 0;
    this->AddSelfPlayer();
    Log(DAT_0062C4FC, s_Create_called);
}
