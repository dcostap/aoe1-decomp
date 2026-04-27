// VA: 0046B270 ~PathingSystem dtor (148B)
// pathsys.cpp
// EH frame (/GX)

class PathingSystem {
public:
    int* vtable;
    char gap4[0x11DCE0];
    int field_11DCE4;
    char gap11DCE8[0x4];
    int field_11DCEC;
    
    ~PathingSystem();
};

PathingSystem::~PathingSystem() {
    vtable = (int*)0x570E8C;
    
    int count = field_11DCE4;
    if (count > 0) {
        field_11DCEC = count;
    }
}
