class AsmProbe {
public:
    int value;
    void set(int value);
};

extern "C" void __cdecl ASMSet_Color_Xform(int color);
extern "C" unsigned long probe_color;

int main()
{
    AsmProbe object;
    object.value = 0;
    object.set(0x12345678);
    if (object.value != 0x12345678) return 1;
    ASMSet_Color_Xform(0x80FE1234);
    if (probe_color != 0x34343434) return 2;
    return 0;
}
