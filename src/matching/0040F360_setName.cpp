// 0040F360 AIPlay::setName
// BINARY NOTE: the original call passes the object base as the destination.

#ifndef AIPBOOK_CANONICAL_TU
#include <string.h>
class AIPlay {
public:
    char nameValue[65];
    void setName(char* name);
};
#endif

void AIPlay::setName(char* name) {
    if (name) {
        strncpy(this->nameValue, name, 64);
    }
}
