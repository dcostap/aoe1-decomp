// VA: 00411400 AIPlayBook::playNumber (113 bytes)

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

    int playNumber(char* name);
};

int AIPlayBook::playNumber(char* name) {
    int i = 0;
    int r;
    int n;

    if (this->plays == 0) return -1;
    n = this->numberPlaysValue;
    if (n <= 0) return -1;

    do {
        r = strcmp(this->plays[i].nameValue, name);
        if (r == 0) return i;
        i++;
    } while (i < n);

    return -1;
}
