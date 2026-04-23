// tried the observed md->_padding_ chain with the exact constant/call argument list; mismatch stayed at the first instruction
// tried a split md/vtable/unit/action local shape to coax the same basin; VC5 still loaded the stack arg before the md chain
// leaving in scratch: remaining delta is prolog/load ordering, not the argument values or call target

class TribeMD;

class TribeMD {
public:
    char gap_00[0xF0];
    void* vtable;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMD* md;

    int stopUnit(int param_1, int param_2);
};

int TribeTacticalAIModule::stopUnit(int param_1, int param_2) {
    TribeMD* md = this->md;
    void* vtable = md->vtable;
    int unit = (int)*(short*)((char*)md + 0x4A);
    int action = param_2;
    ((int (__stdcall *)(int, int, int, int, int, int, int, int, int, int, int, int))(*(void**)((char*)vtable + 0x30)))(unit, param_1, 0x2C2, -1, -1, 0xBF800000, 0xBF800000, 0xBF800000, 0xBF800000, 1, 0, action);
    return 1;
}
