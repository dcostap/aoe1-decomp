// VA: 0040FA40 AIPlay::convertToIntType (279 bytes, 128 asm lines)
// Trying: explicit int local for strcmp result

#include <string.h>

extern char s_Attack[];
extern char s_Annoy[];
extern char s_Flank[];
extern char s_Recon[];

class AIPlay {
public:
    unsigned char convertToIntType(char *name) const;
};

unsigned char AIPlay::convertToIntType(char *name) const {
    int r;
    r = strcmp(name, s_Attack);
    if (r == 0) return 1;
    r = strcmp(name, s_Annoy);
    if (r == 0) return 2;
    r = strcmp(name, s_Flank);
    if (r == 0) return 3;
    r = strcmp(name, s_Recon);
    if (r == 0) return 4;
    return 0;
}
