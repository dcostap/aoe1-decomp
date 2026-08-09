// VA: 0047F480 RESFILE_Extract_to_File (247B)
// Res_file.cpp lines 496-536
//
// Attempt log:
// - initial source was an unrelated linked-list placeholder; replaced with the
//   period-plausible resource extraction flow shown by the binary.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

extern uchar* __cdecl RESFILE_load(unsigned long type, unsigned long id,
    int& load_type, int& data_size);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(
    unsigned long length, char* path);
extern "C" __declspec(dllimport) unsigned int __stdcall GetTempFileNameA(
    const char* path, const char* prefix, unsigned int unique, char* name);

int __cdecl RESFILE_Extract_to_File(unsigned long type, unsigned long id,
    char* name, FILE*& file)
{
    int load_type;
    int data_size;
    char temp_path[260];
    uchar* data;

    file = 0;
    data = RESFILE_load(type, id, load_type, data_size);
    if (data == 0) {
        return 0;
    }

    if (GetTempPathA(0x104, temp_path) == 0) {
        strcpy(temp_path, ".");
    }

    if (GetTempFileNameA(temp_path, "temp", 0, name) != 0) {
        file = fopen(name, "w+");
        if (file != 0 && data_size > 0) {
            fwrite(data, data_size, 1, file);
            fseek(file, 0, 0);
        }
    }

    if (load_type == 1) {
        free(data);
    }

    return file != 0;
}
