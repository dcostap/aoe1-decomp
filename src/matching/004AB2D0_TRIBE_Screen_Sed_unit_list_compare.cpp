

#include "../../include/scr_sed_context.h"

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void* a, const void* b) {
    int result = CompareStringA(0x400, 1, (const char*)a, -1, (const char*)b, -1);
    if (result == 1) {
        return -1;
    }
    return result == 3;
}
