// RESFILE_open_new_resource_file (0047EE90, 541 bytes, Res_file.cpp)
// Lines 70-233
//
// STATUS: PAUSED — multi-range parent-fragment alignment issue
//
// This function spans 3 body ranges + 2 parent-owned fragments (0047F00C, 0047F076).
// The checker concatenates only the 3 body ranges into the comparison buffer, skipping
// the fragments entirely. The rebuilt generates contiguous code including equivalent
// code for those fragment areas, so the byte-level comparison from offset ~380 onward
// compares fragment-equivalent code against completely different range-2 code —
// guaranteed misalignment, not real source-model drift.
//
// After restoring the natural Win32 imports, exact global-list ownership, strcmp
// surface, and mapped/file branch order, the first body range is byte-identical
// apart from relocation bytes and the one-byte INT3 parent-fragment boundary.
// The ~48% whole-function diff is misleading because the checker concatenates
// ranges while skipping the parent-owned INT3/message and list-validation blocks.
//
// Resolving this properly likely requires either:
//   - tooling that compares body ranges individually instead of concatenating, or
//   - parent-owned-fragment-aware comparison, or
//   - inline asm (int3) which is policy-restricted for real functions.
// Not forcing either approach right now per Boss direction. Leave in scratch.
//
// Attempt log:
// - attempt 1 (scratch): wrong layout, no EBP frame — 73% diff (most from tooling gap)
// - probes 1-5: added /Oy- per-function rsp, fixed init order — 64%
// - probes 6-11: clean if/else, decl/assign ordering — 55% (misleading, real range-1 gap is tiny)
// - bounded pass: swapped mapped/fHandle declarations, used period Win32/C
//   linkage, modeled the 0x114 node/0x40 header, inverted node setup, restored
//   typed g_resFileList, and used the compiler's strcmp idiom. Frame and the
//   first 0x17B-byte range now match structurally; the remaining mismatch starts
//   at the excluded INT3 fragment and includes extra rebuilt fragment calls.
// - decision: paused. Fragment alignment blocks whole-function exact comparison.

#include <stdlib.h>
#include <string.h>

typedef void* HANDLE;
typedef unsigned long DWORD;

extern "C" __declspec(dllimport) HANDLE __stdcall CreateFileA(
    const char*, DWORD, DWORD, void*, DWORD, DWORD, HANDLE);
extern "C" __declspec(dllimport) HANDLE __stdcall CreateFileMappingA(
    HANDLE, void*, DWORD, DWORD, DWORD, const char*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(HANDLE);
extern "C" __declspec(dllimport) void* __stdcall MapViewOfFile(
    HANDLE, DWORD, DWORD, DWORD, DWORD);
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(
    void*, const char*, const char*, unsigned int);

extern "C" int __cdecl __open(const char* path, int flags, ...);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" int __cdecl lseek(int fd, int offset, int whence);
extern "C" int __cdecl read(int fd, void* buf, unsigned size);

struct ResFileNode {
    void* data;
    int fd;
    void* directory;
    ResFileNode* next;
    char name[260];
};

struct resfile_header {
    char banner_msg[40];
    char version[4];
    char password[12];
    int num_res_types;
    int directory_size;
};

extern ResFileNode* g_resFileList;

void __cdecl RESFILE_open_new_resource_file(char* name, char* cmpName, char* path, int isMapped) {
    char resFile[260];
    char error_msg[80];
    resfile_header rHdr;
    void* mappedData = 0;
    int fHandle = -1;

    sprintf(resFile, "%s%s", path, name);

    if (isMapped == 0) {
        HANDLE hFile;
        HANDLE hMapping;

        hFile = CreateFileA(resFile, 0x80000000, 1, 0, 4, 0x80, 0);
        if (hFile == (HANDLE)-1) {
            sprintf(error_msg, "Error: Open_new_ResFile, mapped file %s not found.", name);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }

        hMapping = CreateFileMappingA(hFile, 0, 2, 0, 0, 0);
        CloseHandle(hFile);

        if (hMapping == 0) {
            MessageBoxA(0, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", 0x30);
            return;
        }

        mappedData = MapViewOfFile(hMapping, 4, 0, 0, 0);

        if (mappedData == 0) {
            MessageBoxA(0, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", 0x30);
            return;
        }

        CloseHandle(hMapping);
    } else {
        fHandle = __open(resFile, 0x8000);
        if (fHandle == -1) {
            sprintf(error_msg, "Error: Open_new_ResFile, file %s not Found.", name);
            MessageBoxA(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }
    }

    {
        ResFileNode* node;
        node = (ResFileNode*)malloc(0x114);
        if (node == 0) {
            MessageBoxA(0, "Error: Out of memory in Open_resfile.", "RESOURCE ERROR", 0x30);
            return;
        }

        strcpy(node->name, name);
        node->next = 0;

        if (isMapped == 0) {
            node->fd = -1;
            node->data = mappedData;
            node->directory = mappedData;
        } else {
            int n;
            node->fd = fHandle;
            node->data = 0;
            lseek(fHandle, 0, 1);
            n = read(fHandle, &rHdr, sizeof(rHdr));
            if (n != sizeof(rHdr)) {
                MessageBoxA(0, "Error: Reading resfile header.", "RESOURCE ERROR", 0x30);
                return;
            }
            node->directory = malloc(rHdr.directory_size);
            lseek(fHandle, 0, 0);
            n = read(fHandle, node->directory, rHdr.directory_size);
            if (n != rHdr.directory_size) {
                MessageBoxA(0, "Error: Reading resfile header data.", "RESOURCE ERROR", 0x30);
                return;
            }
        }

        {
            void* head;
            head = g_resFileList;
            if (head == 0) {
                g_resFileList = node;
            } else {
                ResFileNode* cur;
                cur = (ResFileNode*)head;
                while (cur->next != 0) {
                    cur = (ResFileNode*)cur->next;
                }
                cur->next = node;
            }
        }

        {
            if (strcmp((char*)node->directory + 0x2C, cmpName) != 0) {
                MessageBoxA(0, "Error: Open_ResFile, Corruption detected in resourcefile.", "RESOURCE ERROR", 0x30);
                return;
            }
        }

        if (strncmp((char*)node->directory + 0x28, "1.00", 4) != 0) {
            MessageBoxA(0, "Error: Open_ResFile, Resfile not correct version.", "RESOURCE ERROR", 0x30);
            return;
        }
    }
}
