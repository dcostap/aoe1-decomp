// VA: 0046D830 copyPath (1114B)
// pathsys.cpp

class PathingSystem {
public:
    char gap4[0x11DC40];
    int field_11DC44;
    
    void copyPath(int* dest);
};

void PathingSystem::copyPath(int* dest) {
    if (!dest) return;
    
    int* src = (int*)field_11DC44;
    if (!src) return;
    
    unsigned char flag = *(unsigned char*)((char*)src + 0x154);
    if (flag) {
        // Copy path data
        int* pathData = (int*)((char*)src + 0xA4);
    }
}
