class SomeClass {
public:
    unsigned char keepGatheringWhenObjectIsOut(int param);
};
unsigned char SomeClass::keepGatheringWhenObjectIsOut(int param) {
    if (param == 0x32 || param == 0x2D) return 1;
    return 0;
}
