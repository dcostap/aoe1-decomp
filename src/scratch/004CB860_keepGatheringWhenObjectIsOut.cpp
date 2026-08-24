#ifndef T_C_OBJ_CONTEXT_H
class SomeClass {
public:
    unsigned char keepGatheringWhenObjectIsOut(int param);
};
#endif
unsigned char SomeClass::keepGatheringWhenObjectIsOut(int param) {
    if (param == 0x32 || param == 0x2D) return 1;
    return 0;
}
