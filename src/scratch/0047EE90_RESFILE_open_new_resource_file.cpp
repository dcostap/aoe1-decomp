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
// - current pass: removing the first header-error MessageBox as an early-return
//   probe reduced the extra ordered calls from four to three, but changed the
//   executable's error behavior; restored the natural typed error path.
// - current pass: typed node->directory as resfile_header and used named
//   version/password fields; emitted code was unchanged, so the first hunk is
//   the parent-owned header-error fragment rather than directory layout.
// - shardE pass: rechecked the canonical source and donor evidence; the first
//   mismatch remains the manifest-excluded 0047F00C error fragment, so no
//   behavior-changing probe was kept.
// - luna-r2 probe 12: inverted the header-read guard into a natural success
//   block; error layout moved, but size grew 4 bytes, exact-block coverage
//   fell 8.2%, and diff grew 5 bytes. Restored the clean negative guard.
// - current revisit: replaced the generic ResFileNode/void* surface with the
//   canonical ResFileHdr ownership (mapped_file, handle, header, next,
//   res_name) shared by the adjacent resource-file reader. The emitted code
//   and metrics were unchanged; the source now has the correct typed global
//   identity. The first body range remains an island match, while the checker
//   still crosses the excluded 0047F00C and 0047F076 parent fragments.
// - Accepted-drift blocker: when the first 0x40-byte header read is short, the
//   executable runs INT3 at 0047F00B before the error dialog. The natural
//   rebuild goes directly to MessageBoxA. Inline assembly is forbidden, and a
//   DebugBreak call would change stack and exception context. Keep in scratch.
//   ORIGINAL BUG: The shipped fault order is INT3, then the header error dialog.
// - fresh audit: inventory body ranges are 0047EE90-0047F00B, 0047F027-0047F075,
//   and 0047F122-0047F173. The rebuilt matches each range's instruction shape;
//   the checker still compares them as one contiguous stream. Its four extra
//   calls are the header-error, list-validation, and version blocks owned by
//   0047F00C/0047F076, not a missing API or cleanup operation in this source.
// - fresh claim validation: --rebuild kept the owner symbol, 0x19C frame, and
//   the 19 original calls. It still built 739 bytes against 541 bytes. The
//   first hunk is the required 0047F00C header-error fragment. The other three
//   extra calls are in the required 0047F076 publication and version fragment.
//   The target source is unchanged and remains the pinned clean source.

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

struct resfile_header;

struct ResFileHdr {
    unsigned char* mapped_file;
    int handle;
    resfile_header* header;
    ResFileHdr* next;
    char res_name[260];
};

struct resfile_header {
    char banner_msg[40];
    char version[4];
    char password[12];
    int num_res_types;
    int directory_size;
};

extern ResFileHdr* g_resFileList;

void __cdecl RESFILE_open_new_resource_file(char* name, char* cmpName, char* path, int isMapped) {
    char resFile[260];
    char error_msg[80];
    resfile_header rHdr;
    unsigned char* mappedData = 0;
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

        mappedData = (unsigned char*)MapViewOfFile(hMapping, 4, 0, 0, 0);

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
        ResFileHdr* node;
        node = (ResFileHdr*)malloc(0x114);
        if (node == 0) {
            MessageBoxA(0, "Error: Out of memory in Open_resfile.", "RESOURCE ERROR", 0x30);
            return;
        }

        // BINARY NOTE: The shipped copy has no length guard for a malformed name.
        strcpy(node->res_name, name);
        node->next = 0;

        if (isMapped == 0) {
            node->handle = -1;
            node->mapped_file = mappedData;
            node->header = (resfile_header*)mappedData;
        } else {
            int n;
            node->handle = fHandle;
            node->mapped_file = 0;
            lseek(fHandle, 0, 1);
            n = read(fHandle, &rHdr, sizeof(rHdr));
            if (n != sizeof(rHdr)) {
                MessageBoxA(0, "Error: Reading resfile header.", "RESOURCE ERROR", 0x30);
                return;
            }
            node->header = (resfile_header*)malloc(rHdr.directory_size);
            lseek(fHandle, 0, 0);
            n = read(fHandle, node->header, rHdr.directory_size);
            if (n != rHdr.directory_size) {
                MessageBoxA(0, "Error: Reading resfile header data.", "RESOURCE ERROR", 0x30);
                return;
            }
        }

        {
            ResFileHdr* head;
            head = g_resFileList;
            if (head == 0) {
                g_resFileList = node;
            } else {
                ResFileHdr* cur;
                cur = head;
                while (cur->next != 0) {
                    cur = cur->next;
                }
                cur->next = node;
            }
        }

        {
            // BINARY NOTE: Publication occurs before password and version checks.
            // Failure returns keep the published node and any raw file handle.
            if (strcmp(node->header->password, cmpName) != 0) {
                MessageBoxA(0, "Error: Open_ResFile, Corruption detected in resourcefile.", "RESOURCE ERROR", 0x30);
                return;
            }
        }

        if (strncmp(node->header->version, "1.00", 4) != 0) {
            MessageBoxA(0, "Error: Open_ResFile, Resfile not correct version.", "RESOURCE ERROR", 0x30);
            return;
        }
    }
}
