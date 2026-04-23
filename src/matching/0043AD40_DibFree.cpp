extern "C" __declspec(dllimport) void* __stdcall GlobalHandle(void* p);
extern "C" __declspec(dllimport) void* __stdcall GlobalUnlock(void* h);
extern "C" __declspec(dllimport) void* __stdcall GlobalFree(void* h);

void DibFree(void* param_1) {
    void* handle = GlobalHandle(param_1);
    GlobalUnlock(handle);
    handle = GlobalHandle(param_1);
    GlobalFree(handle);
}
