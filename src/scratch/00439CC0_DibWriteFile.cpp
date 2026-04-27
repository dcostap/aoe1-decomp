// DibWriteFile — first pass
// VA: 00439CC0
#include "../../include/game_globals.h"

typedef int (__stdcall *_LcreatFn)(char* name, int attr);
typedef int (__stdcall *_LwriteFn)(int fd, void* buf, int count);
typedef int (__stdcall *_LcloseFn)(int fd);

extern _LcreatFn _Lcreat;
extern _LwriteFn _Lwrite;
extern _LcloseFn _Lclose;

int __cdecl DibWriteFile(char* name, void* hdib, void* info, void* bits, int size)
{
    int fd = _Lcreat(name, 0);
    if (fd == -1) return 0;
    _Lwrite(fd, info, *(int*)((char*)info));
    _Lwrite(fd, bits, size);
    _Lclose(fd);
    return 1;
}
