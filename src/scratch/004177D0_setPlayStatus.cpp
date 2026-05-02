// UnitAIModule::setPlayStatus 
// VA: 004177D0 (131 bytes, EH-framed)

void* __cdecl operator_new(size_t sz);
void __cdecl operator_delete(void* p);

struct FakeDtor {
    ~FakeDtor() { }
};

class UnitAIModule {
public:
    char gap_00[0x12C];
    void* play_status;

    void setPlayStatus(void* status);
};

void UnitAIModule::setPlayStatus(void* status) {
    FakeDtor guard;  // forces EH frame with /GX
    if (play_status == 0) {
        void* ps = operator_new(0x1C8);
        if (ps != 0) {
            ((void(__fastcall*)(void*,int))0x0040FC30)(ps, 0);
        }
        play_status = ps;
    }
    if (play_status != 0 && status != 0) {
        ((void(__fastcall*)(void*,int,void*))0x00410050)(play_status, 0, status);
    }
}
