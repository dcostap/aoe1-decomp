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

extern IDirectPlay_obj_fpdc* DAT_0062c5ec;
extern void* DAT_0062cf04;

class TCommunications_Handler {
public:
    int AddSelfPlayer(void);
    void ForcePlayerDestroyAndCreate(void);
};

void TCommunications_Handler::ForcePlayerDestroyAndCreate() {
    debug_log_fpdc(DAT_0062c4fc, DAT_00583294);
    DAT_0062c5ec->vtbl->DestroyPlayer(DAT_0062c5ec, DAT_0062cf04);
    DAT_0062cf04 = 0;
    this->AddSelfPlayer();
    debug_log_fpdc(DAT_0062c4fc, DAT_00583284);
}
