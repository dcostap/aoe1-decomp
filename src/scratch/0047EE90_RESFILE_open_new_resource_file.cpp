// RESFILE_open_new_resource_file (0047EE90, 541 bytes, Res_file.cpp)
// Lines 70-233
//
// STATUS: PAUSED — multi-range fragment alignment issue
//
// This function spans 3 body ranges + 2 parent-owned fragments (0047F00C, 0047F076).
// The checker concatenates only the 3 body ranges into the comparison buffer, skipping
// the fragments entirely. The rebuilt generates contiguous code including equivalent
// code for those fragment areas, so the byte-level comparison from offset ~380 onward
// compares fragment-equivalent code against completely different range-2 code —
// guaranteed misalignment, not real source-model drift.
//
// Within body range 1 (first 380 bytes) the rebuilt is very close: only the local-init
// store order (6 bytes at offset 34-39) differs, and string references are
// relocation-masked. The ~55%+ diff figure is misleading because of the concatenation
// gap.
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
// - decision: paused. Fragment alignment blocks exact comparison. See notes above.

#include <stdlib.h>
#include <string.h>

typedef void* HANDLE;
typedef unsigned long DWORD;

typedef HANDLE (__stdcall *CreateFileA_t)(const char*, DWORD, DWORD, void*, DWORD, DWORD, HANDLE);
typedef HANDLE (__stdcall *CreateFileMappingA_t)(HANDLE, void*, DWORD, DWORD, DWORD, const char*);
typedef int (__stdcall *CloseHandle_t)(HANDLE);
typedef void* (__stdcall *MapViewOfFile_t)(HANDLE, DWORD, DWORD, DWORD, DWORD);
typedef int (__stdcall *MessageBoxA_t)(void*, const char*, const char*, unsigned int);

extern CreateFileA_t CreateFileA_ptr;
extern CreateFileMappingA_t CreateFileMappingA_ptr;
extern CloseHandle_t CloseHandle_ptr;
extern MapViewOfFile_t MapViewOfFile_ptr;
extern MessageBoxA_t MessageBoxA_ptr;

extern int __cdecl _open(const char* path, int flags);
extern void* __cdecl malloc(unsigned size);
extern int sprintf(char* buf, const char* fmt, ...);
extern int __cdecl lseek(int fd, int offset, int whence);
extern int __cdecl read(int fd, void* buf, unsigned size);
extern int __cdecl strncmp(const char* s1, const char* s2, unsigned n);

extern void* g_resFileList;

typedef struct {
    void* data;
    int fd;
    void* directory;
    void* next;
    char name[260];
} ResFileNode;

void __cdecl RESFILE_open_new_resource_file(char* name, char* cmpName, char* path, int isMapped) {
    char resFile[260];
    char error_msg[80];
    struct { char g[0x3C]; int directory_size; } rHdr;
    int fHandle = -1;
    void* mappedData = 0;

    sprintf(resFile, "%s%s", path, name);

    if (isMapped == 0) {
        HANDLE hFile;
        HANDLE hMapping;

        hFile = CreateFileA_ptr(resFile, 0x80000000, 1, 0, 4, 0x80, 0);
        if (hFile == (HANDLE)-1) {
            sprintf(error_msg, "Error: Open_new_ResFile, mapped file %s not found.", name);
            MessageBoxA_ptr(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }

        hMapping = CreateFileMappingA_ptr(hFile, 0, 2, 0, 0, 0);
        CloseHandle_ptr(hFile);

        if (hMapping == 0) {
            MessageBoxA_ptr(0, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", 0x30);
            return;
        }

        mappedData = MapViewOfFile_ptr(hMapping, 4, 0, 0, 0);

        if (mappedData == 0) {
            MessageBoxA_ptr(0, "Error: Open_Mapped_ResFile, Could not map file.", "RESOURCE ERROR", 0x30);
            return;
        }

        CloseHandle_ptr(hMapping);
    } else {
        fHandle = _open(resFile, 0x8000);
        if (fHandle == -1) {
            sprintf(error_msg, "Error: Open_new_ResFile, file %s not Found.", name);
            MessageBoxA_ptr(0, error_msg, "RESOURCE ERROR", 0x30);
            return;
        }
    }

    {
        ResFileNode* node;
        node = (ResFileNode*)malloc(0x114);
        if (node == 0) {
            MessageBoxA_ptr(0, "Error: Out of memory in Open_resfile.", "RESOURCE ERROR", 0x30);
            return;
        }

        strcpy(node->name, name);
        node->next = 0;

        if (isMapped != 0) {
            int n;
            node->fd = fHandle;
            node->data = 0;
            lseek(fHandle, 0, 1);
            n = read(fHandle, &rHdr, sizeof(rHdr));
            if (n != sizeof(rHdr)) {
                MessageBoxA_ptr(0, "Error: Reading resfile header.", "RESOURCE ERROR", 0x30);
                return;
            }
            node->directory = malloc(rHdr.directory_size);
            lseek(fHandle, 0, 0);
            n = read(fHandle, node->directory, rHdr.directory_size);
            if (n != rHdr.directory_size) {
                MessageBoxA_ptr(0, "Error: Reading resfile header data.", "RESOURCE ERROR", 0x30);
                return;
            }
        } else {
            node->fd = -1;
            node->data = mappedData;
            node->directory = mappedData;
        }

        {
            void* head;
            head = *(void**)g_resFileList;
            if (head == 0) {
                *(ResFileNode**)&g_resFileList = node;
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
            char* a;
            char* b;
            a = (char*)node->directory + 0x2C;
            b = cmpName;
            while (*a != 0 && *a == *b) {
                a++;
                b++;
            }
            if (*a != *b) {
                MessageBoxA_ptr(0, "Error: Open_ResFile, Corruption detected in resourcefile.", "RESOURCE ERROR", 0x30);
                return;
            }
        }

        if (strncmp((char*)node->directory + 0x28, "1.00", 4) != 0) {
            MessageBoxA_ptr(0, "Error: Open_ResFile, Resfile not correct version.", "RESOURCE ERROR", 0x30);
            return;
        }
    }
}
