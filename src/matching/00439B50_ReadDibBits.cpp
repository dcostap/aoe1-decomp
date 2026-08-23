// ReadDibBits — first pass
// VA: 00439B50
#include "../../include/game_globals.h"

typedef int (__stdcall *_OpenFileFn)(char* name, void* buf, int mode);
typedef void* (__stdcall *_GlobalHandleFn)(void* mem);
typedef int (__stdcall *_GlobalUnlockFn)(void* handle);
typedef void* (__stdcall *_GlobalFreeFn)(void* handle);
typedef int (__stdcall *_HreadFn)(int file, void* buf, int count);
typedef int (__stdcall *_LcloseFn)(int file);

extern _OpenFileFn _OpenFile;
extern _GlobalHandleFn _GlobalHandle;
extern _GlobalUnlockFn _GlobalUnlock;
extern _GlobalFreeFn _GlobalFree;
extern _HreadFn _Hread;
extern _LcloseFn _Lclose;

struct tagBITMAPINFOHEADER;
tagBITMAPINFOHEADER* __cdecl DibReadBitmapInfo(int hf);

unsigned char* __cdecl ReadDibBits(char* param_1)
{
    char of[0x88];
    unsigned char* result = 0;
    
    int hf = _OpenFile(param_1, of, 0);
    if (hf == -1) return 0;
    
    void* info = DibReadBitmapInfo(hf);
    if (info) {
        _GlobalHandleFn gh = _GlobalHandle;
        int size = *(int*)((char*)info + 0x14);
        _GlobalUnlock(gh(info));
        _GlobalFree(gh(info));
        result = (unsigned char*)malloc(size);
        if (result)
            _Hread(hf, result, size);
    }
    _Lclose(hf);
    return result;
}
