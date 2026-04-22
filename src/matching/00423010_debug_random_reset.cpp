extern char debug_random_log[0x19][0x64];
extern int debug_random_index;

void __cdecl debug_random_reset() {
    char (*entry)[0x64];

    entry = debug_random_log;
    do {
        (*entry)[0] = 0;
        entry = entry + 1;
    } while ((int)entry < (int)&debug_random_log[0x19]);
    debug_random_index = -1;
}
