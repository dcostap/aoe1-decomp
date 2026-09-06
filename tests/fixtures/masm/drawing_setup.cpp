extern "C" {
void __cdecl ASMSet_Shadowing(unsigned long, unsigned long, unsigned long, unsigned long);
void __cdecl ASMSet_Surface_Info(void*, void*, void*, long, long, long, long);
void __cdecl ASMSet_Color_Xform(int);
int __cdecl ASMGet_Color_Xform(void);
void __cdecl ASMSet_Xlate_Table(void*);
}

// Read the checked address operands to inspect private state without exporting it.
static unsigned long* store_target(unsigned char* procedure, int operand)
{
    if (procedure[operand - 1] != 0xA3) return 0;
    return *(unsigned long**)(procedure + operand);
}

int main()
{
    unsigned char* shadow = (unsigned char*)ASMSet_Shadowing;
    unsigned char* surface = (unsigned char*)ASMSet_Surface_Info;
    unsigned long* mask = store_target(shadow, 7);
    unsigned long* value = store_target(shadow, 20);
    unsigned long* offsets = store_target(surface, 7);
    unsigned long* heads = store_target(surface, 15);
    unsigned long* tails = store_target(surface, 23);
    unsigned long* min_y = store_target(surface, 31);
    unsigned long* max_y = store_target(surface, 39);
    unsigned long* min_x = store_target(surface, 47);
    unsigned long* max_x = store_target(surface, 55);
    unsigned long* xlate = store_target((unsigned char*)ASMSet_Xlate_Table, 7);
    unsigned long i;
    if (!mask || !value || !offsets || !heads || !tails || !min_y || !max_y || !min_x || !max_x || !xlate) return 1;
    for (i = 0; i < 65536; ++i) {
        unsigned long a = i ^ 0x12345678;
        unsigned long b = i ^ 0x87654321;
        unsigned long c = ~a;
        unsigned long d = ~b;
        ASMSet_Shadowing(a, b, c, d);
        if (mask[0] != a || mask[1] != c || mask[2] != a || mask[3] != c) return 2;
        if (value[0] != b || value[1] != d || value[2] != b || value[3] != d) return 3;
        ASMSet_Surface_Info((void*)a, (void*)b, (void*)c, a, b, c, d);
        if (*offsets != a || *heads != b || *tails != c) return 4;
        if (*min_x != a || *min_y != b || *max_x != c || *max_y != d) return 5;
        ASMSet_Xlate_Table((void*)d);
        if (*xlate != d) return 6;
        ASMSet_Color_Xform((int)a);
        if (ASMGet_Color_Xform() != (int)(a & 255)) return 7;
    }
    return 0;
}
