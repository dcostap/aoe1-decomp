// attempt 1: code shape totally wrong (VC5 pushes ebx/ebp, uses edi for this, wrong virtual call shape)
// attempt 2: very close, je 0x47 vs 0x46 (1 byte jump drift), id at +0x48 vs +0x4A
// attempt 3: id offset fixed but virtual call register pattern still differs (mov esi,[eax+58]+add eax,58 vs mov eax,[eax+58]+mov esi,[eax])
// Left in scratch after 3 attempts
// Remaining: 1 byte je offset drift (0x47 vs 0x46) from VC5 virtual call register allocation choice
// Original: mov eax,[eax+58]; mov esi,[eax]; mov ecx,eax; call [esi+0C]
// VC5: mov esi,[eax+58]; add eax,58; mov ecx,eax; call [esi+0C]

float float_zero;

class ICommandModule {
public:
    virtual void unknown0() = 0;
    virtual void unknown1() = 0;
    virtual void unknown2() = 0;
    virtual void give_attribute(int id, int param1, int param2, int param3) = 0;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    void* world;
    char gap_40[0xA];
    short id;
    char gap_4C[0x4];
    float* attributes;

    unsigned char command_give_attribute(int param1, int param2, float param3);
};

unsigned char RGE_Player::command_give_attribute(int param1, int param2, float param3) {
    if (param2 != -1 && param3 != float_zero) {
        if (param3 <= attributes[param2]) {
            int p3 = *(int*)&param3;
            ICommandModule* cmds = (ICommandModule*)((char*)world + 0x58);
            cmds->give_attribute(id, param1, param2, p3);
            return 1;
        }
    }
    return 0;
}
