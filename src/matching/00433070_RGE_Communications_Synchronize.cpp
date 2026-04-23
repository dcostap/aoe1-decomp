class RGE_Communications_Synchronize {
public:
    char gap_00[0x30];

    ~RGE_Communications_Synchronize();
};

RGE_Communications_Synchronize::~RGE_Communications_Synchronize() {
    int* p = (int*)((char*)this + 0x38);
    int i = 0x37;

    do {
        p[-1] = 0;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[-2] = 0;
        p = (int*)((char*)p + 0x24);
        i = i - 1;
    } while (i != 0);
}
