// VA: 0050F410 TRIBE_Map::TRIBE_Map
// FLAGS: config/flags/0050F410_TRIBE_Map.rsp (/nologo /c /O2 /Oy /GX)

#ifndef TMAP_GROUP_CONTEXT
class RGE_Sound;
class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Map(int, RGE_Sound**, unsigned char);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual ~TRIBE_Map();
    TRIBE_Map(int, RGE_Sound**, unsigned char);
    void data_load_random_map(int);
    void setup_cliff_type(long,long,long,long,long,long,long,long,float,float);
};
#endif

TRIBE_Map::TRIBE_Map(int p1, RGE_Sound** p2, unsigned char load)
    : RGE_Map(p1, p2, 0)
{
    *(void**)this = (void*)0x5767c8;
    if (load != 0) {
        this->data_load_random_map(p1);
    }

    int minus_one = -1;
    char* base = (char*)this;
    *(int*)(base + 0x8de4) = minus_one;
    *(int*)(base + 0x8de8) = minus_one;
    *(int*)(base + 0x8dec) = minus_one;
    *(int*)(base + 0x8df0) = minus_one;

    int* p = (int*)(base + 0x8e1c);
    for (int i = 0; i < 0x100; i++) {
        *(p - 1) = 0;
        *p = 0;
        *(p - 5) = 0;
        *(p - 4) = 0;
        *(p - 3) = 0;
        *(p - 2) = 0;
        *(p - 9) = minus_one;
        *(p - 8) = minus_one;
        *(p - 7) = minus_one;
        *(p - 6) = minus_one;
        p += 10;
    }

    setup_cliff_type(1,0,0,0,0x108,0x10,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,1,0,0,0x108,0x12,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,1,0,0x108,0x11,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,0,1,0x108,0x13,-1,-1,1.5f,1.5f);
    setup_cliff_type(-1,0,0,0,0x10a,0x14,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,-1,0,0,0x109,0x16,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,-1,0,0x10a,0x15,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,0,-1,0x109,0x17,-1,-1,1.5f,1.5f);
    setup_cliff_type(-1,1,0,0,0x10e,0,-1,-1,1.5f,2.0f);
    setup_cliff_type(0,-1,-1,0,0x110,9,-1,-1,1.0f,2.0f);
    setup_cliff_type(0,0,1,-1,0x10c,6,-1,-1,1.0f,1.5f);
    setup_cliff_type(1,0,0,1,0x108,3,-1,-1,1.5f,1.5f);
    setup_cliff_type(1,-1,0,0,0x10b,0xc,-1,-1,2.0f,1.5f);
    setup_cliff_type(0,1,1,0,0x108,0xf,-1,-1,1.5f,1.5f);
    setup_cliff_type(0,0,-1,1,0x10d,0xe,-1,-1,1.5f,1.0f);
    setup_cliff_type(-1,0,0,-1,0x10f,0xd,-1,-1,2.0f,1.0f);
    setup_cliff_type(1,0,1,0,0x108,4,0x108,5,1.5f,1.5f);
    setup_cliff_type(0,1,0,1,0x108,1,0x108,2,1.5f,1.5f);
    setup_cliff_type(-1,0,-1,0,0x10a,0xb,0x10a,10,1.5f,1.5f);
    setup_cliff_type(0,-1,0,-1,0x109,8,0x109,7,1.5f,1.5f);
}
