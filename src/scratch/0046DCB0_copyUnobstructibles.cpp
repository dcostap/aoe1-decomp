// VA: 0046DCB0 copyUnobstructibles (299B)
// pathsys.cpp

class PathingSystem {
public:
    char gap4[0x11DCE4];
    int field_11DCE8;
    char gap11DCEC[0x4];
    int field_11DCF0;
    
    void copyUnobstructibles(int* dest);
};

void PathingSystem::copyUnobstructibles(int* dest) {
    int count = field_11DCE8;
    if (count < 0) return;
    
    field_11DCF0 = count;
}
