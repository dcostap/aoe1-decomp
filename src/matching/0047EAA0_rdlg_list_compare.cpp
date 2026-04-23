extern "C" __declspec(dllimport) int __stdcall CompareStringA(unsigned long locale, unsigned long flags, const char* s1, int c1, const char* s2, int c2);

int __cdecl rdlg_list_compare(const void* a, const void* b) {
    int result = CompareStringA(0x400, 1, (const char*)a, -1, (const char*)b, -1);
    if (result == 1) {
        return -1;
    }
    return result == 3;
}
