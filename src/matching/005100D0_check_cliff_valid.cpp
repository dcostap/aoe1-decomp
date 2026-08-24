// VA: 005100D0 check_cliff_valid (49B)
// tmap.cpp

#ifndef TMAP_GROUP_CONTEXT
struct TRIBE_Cliff_Info {
    int info[4];
};

class TRIBE_Map {
public:
    char gap_00[0x9B40];

    unsigned char check_cliff_valid(TRIBE_Cliff_Info param_1);
};
#endif

unsigned char TRIBE_Map::check_cliff_valid(TRIBE_Cliff_Info param_1) {
    int temp = param_1.info[0] * 4 + param_1.info[1];
    temp = param_1.info[2] + temp * 4;
    temp = param_1.info[3] + temp * 4;
    int value = *(int*)((char*)this + temp * 40 + 0x9B40);
    return value >= 0;
}
