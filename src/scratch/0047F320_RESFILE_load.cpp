// VA: 0047F320 RESFILE_load (346B)
// Res_file.cpp

#include <stdlib.h>
#include <string.h>

extern void* g_resFileList;
extern void* __cdecl malloc(unsigned size);
extern void* __cdecl CreateFileMappingA(void* hFile, void* lpAttr, unsigned flProtect, unsigned dwMaxSizeHigh, unsigned dwMaxSizeLow, const char* lpName);
extern void* __cdecl MapViewOfFile(void* hMap, unsigned dwDesiredAccess, unsigned dwFileOffsetHigh, unsigned dwFileOffsetLow, unsigned dwNumBytesToMap);
extern int __cdecl close(int fd);

void* __cdecl RESFILE_load(const char* name) {
    void** cur = *(void***)g_resFileList;
    
    while (cur) {
        const char* curName = (const char*)cur + 0x10;
        if (strcmp(name, curName) == 0) {
            if (*(int*)cur == 0) {
                // Not yet mapped - create file mapping
                int fd = *(int*)((char*)cur + 4);
                if (fd == -1) return 0;
                
                void* hMap = CreateFileMappingA((void*)fd, 0, 2, 0, 0, 0);
                if (!hMap) return 0;
                
                void* view = MapViewOfFile(hMap, 4, 0, 0, 0);
                *(void**)cur = view;
                return view;
            }
            return *(void**)cur;
        }
        cur = (void**)cur[3];
    }
    
    return 0;
}
