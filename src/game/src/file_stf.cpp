// Fully verified. Source of truth: file_stf.cpp.decomp @ 0x00449710
int compareFilenameStrings(const void* param_1, const void* param_2) {
    unsigned char bVar1;
    bool bVar2;
    const unsigned char* p1 = (const unsigned char*)param_1;
    const unsigned char* p2 = (const unsigned char*)param_2;

    while (true) {
        bVar1 = *p1;
        bVar2 = bVar1 < *p2;
        if (bVar1 != *p2) break;
        if (bVar1 == 0) {
            return 0;
        }
        bVar1 = p1[1];
        bVar2 = bVar1 < p2[1];
        if (bVar1 != p2[1]) break;
        p1 += 2;
        p2 += 2;
        if (bVar1 == 0) {
            return 0;
        }
    }
    return (1 - (int)bVar2) - (int)(bVar2 != 0);
}
