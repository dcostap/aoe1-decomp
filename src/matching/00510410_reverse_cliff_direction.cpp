class SomeClass {
public:
    int reverse_cliff_direction(int dir);
};
int SomeClass::reverse_cliff_direction(int dir) {
    int result = dir + 2;
    if (result >= 4) result -= 4;
    return result;
}
