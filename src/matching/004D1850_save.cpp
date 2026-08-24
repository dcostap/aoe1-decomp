#ifndef TACT_REP_CONTEXT_H
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

class RGE_Action {
public:
    virtual void save(int handle);
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    char gap_04[0x3C];
    unsigned char save_target_command_flag;

    void save(int handle);
};
#endif

void TRIBE_Action_Repair::save(int handle) {
    RGE_Action::save(handle);
    rge_write(handle, &this->save_target_command_flag, 1);
}
