extern void* DAT_0062c4fc;
extern char DAT_00583294[];
extern char DAT_00583284[];
void __cdecl debug_log_fpdc(void* log, const char* msg);

struct IDirectPlay_vtbl_fpdc {
    char gap_00[0x24];
    int (__stdcall* DestroyPlayer)(void* thisptr, void* player);
};

struct IDirectPlay_obj_fpdc {
    IDirectPlay_vtbl_fpdc* vtbl;
};

#if !defined(COM_HAND_TU_CONTEXT)
extern IDirectPlay_obj_fpdc* DAT_0062c5ec;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern void* DAT_0062cf04;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    int AddSelfPlayer(void);
    void ForcePlayerDestroyAndCreate(void);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::ForcePlayerDestroyAndCreate() {
    debug_log_fpdc(DAT_0062c4fc, DAT_00583294);
    DAT_0062c5ec->Send(DAT_0062cf04, 0, 0, 0, 0);
    DAT_0062cf04 = 0;
    this->AddSelfPlayer();
    debug_log_fpdc(DAT_0062c4fc, DAT_00583284);
}
