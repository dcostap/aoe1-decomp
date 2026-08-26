#include <windows.h>

void DibFree(tagBITMAPINFOHEADER* param_1) {
    void* handle = GlobalHandle(param_1);
    GlobalUnlock(handle);
    handle = GlobalHandle(param_1);
    GlobalFree(handle);
}
