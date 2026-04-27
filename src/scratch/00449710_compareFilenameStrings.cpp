// tried the direct two-byte loop; VC5 picked the wrong register basin and a non-matching return shape
// tried the decompiler-literal bool-temp spelling; first mismatch moved to the initial load/register order
// tried the donor TU include baseline, but there is no local common.h in this repo
// First-pass skeleton/partial — needs proper implementation
int __cdecl compareFilenameStrings(void* param_1, void* param_2) {
    unsigned char bVar1;
    bool bVar2;

    while (true) {
        bVar1 = *(unsigned char*)param_1;
        bVar2 = bVar1 < *(unsigned char*)param_2;
        if (bVar1 != *(unsigned char*)param_2) {
            break;
        }
        if (bVar1 == 0) {
            return 0;
        }
        bVar1 = *(unsigned char*)((int)param_1 + 1);
        bVar2 = bVar1 < *(unsigned char*)((int)param_2 + 1);
        if (bVar1 != *(unsigned char*)((int)param_2 + 1)) {
            break;
        }
        param_1 = (void*)((int)param_1 + 2);
        param_2 = (void*)((int)param_2 + 2);
        if (bVar1 == 0) {
            return 0;
        }
    }
    return (1 - (unsigned int)bVar2) - (unsigned int)(bVar2 != 0);
}
