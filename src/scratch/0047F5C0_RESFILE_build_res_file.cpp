// VA: 0047F5C0 RESFILE_build_res_file (1669B)
// Res_file.cpp

#include <stdlib.h>
#include <string.h>

extern void* __cdecl open(const char* path, int flags);
extern int __cdecl write(int fd, const void* buf, unsigned count);
extern int __cdecl close(int fd);
extern void* __cdecl malloc(unsigned size);

int __cdecl RESFILE_build_res_file(const char* outFile) {
    char buffer[0x400];
    
    // Build a .RES file from source files
    // Open output file
    // Write header
    // Iterate through source files and add them
    
    return 0;
}
