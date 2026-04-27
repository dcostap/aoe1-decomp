// attempt 1: size correct (125) but 30.4% diff - Release had null check + thiscall (ecx) pattern
// attempt 2: added __cdecl for virtual Release - got push eax pattern but extra 'add esp,4' cleanup
// attempt 3: EXACT MATCH - __stdcall virtual functions match COM IUnknown pattern (push eax, no cleanup)
//   Key: COM interfaces use __stdcall for vtable dispatch, not thiscall

struct GUID {};

extern "C" int __stdcall DirectPlayCreate(const GUID* dpid, void** ppDirectPlay, unsigned long param);

class TCommunications_Services {
public:
    char pad[0x2580];
    int ServiceCount;

    int GetServiceCount();
    void SetServiceName(int index, const char* name);
    void EnumServiceGUID(int index, const GUID* guid);
    void SetServiceActive(int index, int active);
    int IncServiceCount();
};

struct IDirectPlay {
    virtual int __stdcall QueryInterface(const GUID* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

int __stdcall DPEnumCallback(const GUID* param_1, char* param_2, unsigned long param_3, unsigned long param_4, void* param_5) {
    TCommunications_Services* this_ptr = (TCommunications_Services*)param_5;
    int count = this_ptr->GetServiceCount();
    this_ptr->SetServiceName(count, param_2);
    this_ptr->EnumServiceGUID(count, param_1);

    IDirectPlay* dp;
    int result = DirectPlayCreate(param_1, (void**)&dp, 0);

    if (result == 0) {
        this_ptr->SetServiceActive(count, 1);
        dp->Release();
        this_ptr->IncServiceCount();
        return 1;
    }

    this_ptr->SetServiceActive(count, 0);
    this_ptr->IncServiceCount();
    return 1;
}
