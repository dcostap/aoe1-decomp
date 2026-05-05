#include <stdio.h>

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    void* effects;
    long effect_num;
    RGE_Effects(char* file);
};

int main() {
    printf("%d\n", sizeof(RGE_Effects));
    return 0;
}
