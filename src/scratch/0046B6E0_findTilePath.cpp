// VA: 0046B6E0 findTilePath (6946B)
// pathsys.cpp

class PathingSystem {
public:
    char gap4[0x11DC40];
    int field_11DC44;
    
    int findTilePath(int x, int y, int a3, int a4);
};

int PathingSystem::findTilePath(int x, int y, int a3, int a4) {
    if (x < 0) return 0;
    
    field_11DC44 = x;
    return 1;
}
