// VA: 0046B0F0 PathingSystem ctor (349B)
// pathsys.cpp
// EH frame (/GX)

class PathingSystem {
public:
    int* vtable;
    char gap4[0x11DCE0];
    int field_11DCE4;
    int field_11DCE8;
    
    PathingSystem();
};

PathingSystem::PathingSystem() {
    vtable = 0;
    field_11DCE4 = 0;
    field_11DCE8 = 0;
}
