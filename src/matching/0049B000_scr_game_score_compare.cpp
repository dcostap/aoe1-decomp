// 0049B000 scr_game_score_compare
// 121 bytes, __cdecl, qsort comparison callback
// probe 3: param order was wrong - original loads a from [esp+8], b from [esp+4]

extern void* DAT_0086babc;
extern void* DAT_0086bac0;

int scr_game_score_compare(const void* param_b, const void* param_a) {
    DAT_0086babc = (void*)param_a;
    DAT_0086bac0 = (void*)param_b;

    int* a = (int*)param_a;
    int* b = (int*)param_b;

    if (a[4] > b[4]) return 1;
    if (a[4] < b[4]) return -1;
    if (a[2] > b[2]) return 1;
    if (a[2] < b[2]) return -1;
    if (a[3] > b[3]) return 1;
    if (a[3] < b[3]) return -1;
    if (a[1] > b[1]) return 1;
    return (a[1] >= b[1]) - 1;
}
