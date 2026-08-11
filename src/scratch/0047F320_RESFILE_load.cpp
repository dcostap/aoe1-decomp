// VA: 0047F320 RESFILE_load (346B)
// Res_file.cpp
//
// Attempt log:
// - replaced the stale one-argument mapping placeholder with the four-argument
//   resource loader implied by the mangled call surface and the original calls.
// - baseline: typed locate outputs and Win32 error surface; frame matched but
//   source placed the error path after the success path (size +11, diff 263).
// - control-flow: positive locate result nested after the missing-resource
//   diagnostic; size/calls became exact (diff 181).
// - liveness: separate malloc result and the original error-buffer base matched
//   the full call set and moved the diff to 179 bytes.
// - declaration/order and pointer-result variants were codegen duplicates.
// - common-return control flow (return data inside the locate-success arm) moved
//   the result from 179 to 12 bytes and matched the PDB's shared line-483 return.
// - interleaving load_type=0, mapped-data address formation, and data_size=
//   resource_size recovered the original prologue and all 346 bytes of shape;
//   the remaining drift is one SIB base/index byte in the mapped LEA.
// - parameter-home alias and integer/pointer-address variants were rolled back:
//   they either widened the drift or compiled identically. Keep the natural
//   typed pointer expression as the living reconstruction.

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

extern int __cdecl RESFILE_locate_resource(unsigned long type, unsigned long id,
    int& file_handle, int& data_offset, uchar*& mapped_data, int& data_size);
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(
    void* hWnd, const char* text, const char* caption, unsigned int type);
extern "C" int __cdecl lseek(int fd, int offset, int whence);
extern "C" int __cdecl read(int fd, void* buffer, unsigned int count);

extern int DAT_0086B258;

uchar* __cdecl RESFILE_load(unsigned long type, unsigned long id,
    int& load_type, int& data_size)
{
    int file_handle;
    int data_offset;
    int resource_size;
    uchar* mapped_data;
    uchar* data;
    char error_string[100];

    load_type = -1;
    data_size = 0;

    if (RESFILE_locate_resource(type, id, file_handle, data_offset,
            mapped_data, resource_size) == 0) {
        if (DAT_0086B258 != 0) {
            sprintf(error_string,
                "ERROR: res_read_bin, resource type %4.4c , id %d",
                type, id);
            MessageBoxA(0, error_string, "RESOURCE ERROR", 0x30);
            return 0;
        }
    } else {
        if (mapped_data != 0) {
            load_type = 0;
            data = mapped_data + data_offset;
            data_size = resource_size;
        } else {
            load_type = 1;
            data = (uchar*)malloc(resource_size);
            data_size = resource_size;
            if (data == 0) {
                MessageBoxA(0, "Error: Out of memory in res_read_bin.",
                    "RESOURCE ERROR", 0x30);
                return 0;
            }

            lseek(file_handle, data_offset, 0);
            if (read(file_handle, data, resource_size) != resource_size) {
                MessageBoxA(0, "Error: unable to read resource",
                    "RESOURCE ERROR", 0x30);
                return 0;
            }
        }

        return data;
    }

    return 0;
}
