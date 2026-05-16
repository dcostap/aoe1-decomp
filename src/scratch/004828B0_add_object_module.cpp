// Attempt log for 004828B0 RGE_RMM_Controller::add_object_module
// try 1: manual object_info stack buffer/stores from packet plus natural new/ctor; too small 672B.
// try 2: /GX flag probe; unchanged too small 672B.
// try 3: /Oy- flag probe; too small 656B.
// try 4: /O1 flag probe; too small 625B.
// try 5: added placement-new surface for natural ctor; compiles but no size improvement.
// try 6: reviewed stack-frame target 0x18D0 and local object_info offset; broad alloca/EH frame likely close.
// try 7: reviewed constants/register reuse; manual stores likely too expression-collapsed vs original scheduled register constants.
// try 8: reviewed land-copy loop; source loop shape matches behavior but not validated.
// try 9: reviewed final operator new/ctor argument order; plausible but size short.
// try 10: left in scratch; current source is a behavior scaffold, not exact-size.
// BLOCKER: rebuilt .text 672B vs original 695B; missing exact large aggregate initialization schedule/register-lifetime and ctor/EH state shape. Not accepted_drift-safe.

inline void* operator new(unsigned int, void* p) { return p; }
class RGE_Game_World { public: char pad[0x141c]; int land_num; };
class RGE_Land_Info { public: char pad0[8]; int x; int y; char stride_pad[0x34-0x10]; };
class RGE_RMM_Object_Generator { public: RGE_RMM_Object_Generator(void*, void*, RGE_Game_World*, void*, char); };
class RGE_RMM_Controller { public: char pad[0x0c]; void* map; void add_object_module(RGE_Game_World*, RGE_Land_Info*); };

void RGE_RMM_Controller::add_object_module(RGE_Game_World* world, RGE_Land_Info* lands)
{
    char object_info[0x18d0];
    int* p = (int*)object_info;
    int z = 0, one = 1, two = 2, three = 3, four = 4, six = 6, nine = 9, fifteen = 15, minus = -1;
    *(int*)(object_info + 0x129c) = six;
    *(int*)(object_info + 0x5c) = four;
    *(int*)(object_info + 0x70) = six;
    *(int*)(object_info + 0xa0) = six;
    *(int*)(object_info + 0xac) = four;
    *(int*)(object_info + 0xd0) = six;
    *(int*)(object_info + 4) = 0x6d; *(int*)(object_info+8)=z; object_info[0xc]=0; object_info[0xd]=0; *(int*)(object_info+0x10)=one; *(int*)(object_info+0x14)=z; *(int*)(object_info+0x18)=one; *(int*)(object_info+0x20)=minus; *(int*)(object_info+0x24)=z; *(int*)(object_info+0x28)=z; *(int*)(object_info+0x2c)=z;
    *(int*)(object_info+0x34)=0x53; *(int*)(object_info+0x38)=z; object_info[0x3c]=0; object_info[0x3d]=0; *(int*)(object_info+0x40)=one; *(int*)(object_info+0x44)=z; *(int*)(object_info+0x48)=three; *(int*)(object_info+0x50)=minus; *(int*)(object_info+0x54)=z; *(int*)(object_info+0x58)=two;
    *(int*)(object_info+0x64)=0x41; *(int*)(object_info+0x68)=z; object_info[0x6c]=1; object_info[0x6d]=1; *(int*)(object_info+0x74)=three; *(int*)(object_info+0x78)=10; *(int*)(object_info+0x7c)=three; *(int*)(object_info+0x80)=z; *(int*)(object_info+0x84)=minus; *(int*)(object_info+0x88)=minus; *(int*)(object_info+0x8c)=minus;
    *(int*)(object_info+0x94)=0x66; *(int*)(object_info+0x98)=minus; object_info[0x9c]=2; object_info[0x9d]=0; *(int*)(object_info+0xa4)=two; *(int*)(object_info+0xa8)=one; *(int*)(object_info+0xb0)=z; *(int*)(object_info+0xb4)=z; *(int*)(object_info+0xb8)=nine; *(int*)(object_info+0xbc)=fifteen;
    *(int*)(object_info+0xc4)=0x42; *(int*)(object_info+0xc8)=minus; object_info[0xcc]=2; object_info[0xcd]=0; *(int*)(object_info+0xd4)=two; *(int*)(object_info+0xd8)=one; *(int*)(object_info+0xdc)=four; *(int*)(object_info+0xe0)=z; *(int*)(object_info+0xe4)=z; *(int*)(object_info+0xe8)=nine; *(int*)(object_info+0xec)=fifteen;
    *(int*)(object_info+0xf4)=0x3b; *(int*)(object_info+0xf8)=minus; object_info[0xfc]=1; object_info[0xfd]=0; *(int*)(object_info+0x100)=5; *(int*)(object_info+0x104)=two; *(int*)(object_info+0x108)=one; *(int*)(object_info+0x10c)=three; *(int*)(object_info+0x110)=z; *(int*)(object_info+0x114)=z; *(int*)(object_info+0x118)=nine; *(int*)(object_info+0x11c)=fifteen;
    int count = world->land_num;
    if (count > 0) {
        int* dst = (int*)(object_info + 0x129c);
        char* src = (char*)lands + 0x0c;
        int i = 0;
        do { ++i; dst[-1] = *(int*)(src-4); dst[0] = *(int*)src; dst[1] = 0; dst[2] = i; src += 0x34; dst += 4; } while (i < count);
    }
    RGE_RMM_Object_Generator* gen = (RGE_RMM_Object_Generator*)operator new(0x1920);
    *(void**)(object_info) = gen;
    if (gen) new(gen) RGE_RMM_Object_Generator(this->map, this, world, object_info+4, 1);
}
