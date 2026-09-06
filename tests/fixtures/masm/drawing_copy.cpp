#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "../../../include/asm_draw.h"

extern "C" void __cdecl probe_codelet(void*, void**, unsigned char*, unsigned char*, unsigned long, unsigned long);

static void** copy_table;
static void** resume_slot;
static unsigned long fault_address, fault_operation;

static int fault_filter(EXCEPTION_POINTERS* info)
{
    if (info->ExceptionRecord->ExceptionCode != EXCEPTION_ACCESS_VIOLATION)
        return EXCEPTION_CONTINUE_SEARCH;
    fault_operation = info->ExceptionRecord->ExceptionInformation[0];
    fault_address = info->ExceptionRecord->ExceptionInformation[1];
    return EXCEPTION_EXECUTE_HANDLER;
}

static int copy_run(unsigned char* source, unsigned char* dest, unsigned long count)
{
    unsigned long group = count < 8 ? count : 8+(count&3);
    void* entry = copy_table[group*4+((unsigned long)dest&3)];
    void* saved_resume = *resume_slot;
    int failed = 0;
    fault_address = fault_operation = 0;
    __try {
        probe_codelet(entry, resume_slot, source, dest, count, 0xA1B2C3D4);
    } __except(fault_filter(GetExceptionInformation())) {
        failed = 1;
    }
    *resume_slot = saved_resume;
    return failed;
}

static int buffer_tests()
{
    unsigned char input[2048], actual[2048], expected[2048];
    for (unsigned long count=0; count<=512; ++count) {
        for (int sa=0; sa<4; ++sa) {
            for (int da=0; da<4; ++da) {
                for (int i=0; i<2048; ++i) input[i]=(unsigned char)(i*37+(i>>3)+count);
                memset(actual, 0xCD, sizeof(actual));
                memcpy(expected, actual, sizeof(actual));
                memcpy(expected+16+da, input+16+sa, count);
                if (copy_run(input+16+sa, actual+16+da, count)) return 1;
                if (memcmp(actual, expected, sizeof(actual))) return 2;
            }
        }
    }
    return 0;
}

static int fault_tests()
{
    SYSTEM_INFO system;
    GetSystemInfo(&system);
    unsigned long page = system.dwPageSize, old;
    unsigned char* source = (unsigned char*)VirtualAlloc(0, page*3, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
    unsigned char* dest = (unsigned char*)VirtualAlloc(0, page*3, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
    if (!source || !dest) return 80;
    if (!VirtualProtect(source, page, PAGE_NOACCESS, &old) ||
        !VirtualProtect(source+page*2, page, PAGE_NOACCESS, &old) ||
        !VirtualProtect(dest, page, PAGE_NOACCESS, &old) ||
        !VirtualProtect(dest+page*2, page, PAGE_NOACCESS, &old)) return 81;
    unsigned char* source_begin=source+page;
    unsigned char* source_end=source+page*2;
    unsigned char* dest_end=dest+page*2;
    for (unsigned long i=0; i<page; ++i) source_begin[i]=(unsigned char)(i*37+5);
    int result=0;
    unsigned char untouched[32];
    memset(untouched, 0xCD, sizeof(untouched));

    // A two-byte copy still reads a source DWORD.
    memset(dest+page, 0xCD, page);
    if (!copy_run(source_end-2, dest+page+16, 2) || fault_operation != 0 ||
        fault_address != (unsigned long)source_end || memcmp(dest+page, untouched, 32)) result=3;

    // The seven-byte, alignment-one block reads one byte before the source.
    memset(dest+page, 0xCD, page);
    if (!copy_run(source_begin, dest+page+17, 7) || fault_operation != 0 ||
        fault_address != (unsigned long)(source_begin-1) || memcmp(dest+page, untouched, 32)) result=4;

    // Alignment two reads source+2 before it writes the first destination bytes.
    memset(dest+page, 0xCD, page);
    if (!copy_run(source_end-4, dest+page+18, 7) || fault_operation != 0 ||
        fault_address != (unsigned long)source_end || memcmp(dest+page, untouched, 32)) result=5;

    // A failing final byte store leaves six copied bytes in the writable page.
    memset(dest+page, 0xCD, page);
    if (!copy_run(source_begin+16, dest_end-6, 7) || fault_operation != 1 ||
        fault_address != (unsigned long)dest_end || memcmp(dest_end-6, source_begin+16, 6)) result=6;

    VirtualFree(source, 0, MEM_RELEASE);
    VirtualFree(dest, 0, MEM_RELEASE);
    return result;
}

int main()
{
    // The probe derives these offsets from the assembled object, not fixed image addresses.
    unsigned char* getter=(unsigned char*)ASMGet_Color_Xform;
    if (*getter != 0xA1) return 90;
    unsigned char* color=(unsigned char*)*(unsigned long*)(getter+1);
    resume_slot=(void**)(color+TEST_RESUME_FROM_COLOR);
    copy_table=(void**)((unsigned char*)ASMDraw_HLine+TEST_COPY_FROM_HLINE);
    int result=buffer_tests();
    if (!result) result=fault_tests();
    printf("Sprite literal copy: %s (%d), 8208 buffer cases and 4 fault cases\n", result ? "FAILED" : "PASS", result);
    return result;
}
