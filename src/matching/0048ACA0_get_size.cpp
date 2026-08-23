#include <string.h>

#ifndef SCENARIO_TU
class RGE_Scenario_Header {
public:
    char gap_00[0x10];
    char* description;

    long get_size();
};
#endif

long RGE_Scenario_Header::get_size() {
    unsigned int len;

    if (this->description != 0) {
        len = strlen(this->description) + 1;
    }
    else {
        len = 0;
    }
    return len + 0x0C;
}
