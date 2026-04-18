class SomeClass {
public:
    const char* YesOrNo(int val);
};
extern char str_No[];   // 584100
extern char str_Yes[];  // 584118
const char* SomeClass::YesOrNo(int val) {
    if (val) return str_Yes;
    return str_No;
}
