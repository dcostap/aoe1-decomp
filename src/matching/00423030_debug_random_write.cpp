// first pass: open the debug random log, walk the fixed 0x64 stride block, then mark the write complete
// the only real shape here is the file-open guard plus the pointer/index loop and final flag store
#include <stdio.h>

extern int debug_random_index;
extern int wrote_debug_random_log;

void debug_random_write(void) {
    FILE* file;
    int index;
    long ptr;
    const char* marker;

    file = fopen("c:\\aoerand.txt", "w");
    if (file == 0) {
        return;
    }

    index = 0;
    ptr = 0x5B2378;
    while (ptr < 0x62C498) {
        if (index == debug_random_index) {
            marker = ">";
        }
        else {
            marker = " ";
        }
        fprintf(file, "%s%d - %s\n", marker, index, (char*)ptr);
        ptr += 0x64;
        index++;
    }

    fclose(file);
    wrote_debug_random_log = 1;
}
