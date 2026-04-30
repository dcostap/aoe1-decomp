// VA: 00411370 AIPlayBook::play (131 bytes)

#include <string.h>

struct AIPlay {
    char nameValue[0x608];
};

class AIPlayBook {
public:
    void* vtable_ptr;
    int numberPlaysValue;
    char pad_08[0x44];
    AIPlay* plays;

    AIPlay* play(char* name);
};

AIPlay* AIPlayBook::play(char* name) {
    int i;
    int r;
    int n;

    if (this->plays == 0) return 0;
    n = this->numberPlaysValue;
    if (n <= 0) return 0;

    i = 0;
    do {
        r = strcmp(this->plays[i].nameValue, name);
        if (r == 0) return &this->plays[i];
        i++;
    } while (i < n);

    return 0;
}
