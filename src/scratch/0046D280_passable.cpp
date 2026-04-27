// VA: 0046D280 passable (1207B)
// pathsys.cpp

class PathingSystem {
public:
    char gap4[0x11DC3C];
    int field_11DC40;
    int field_11DC44;
    
    int passable(int* obj, float radius);
};

int PathingSystem::passable(int* obj, float radius) {
    int* map = (int*)field_11DC40;
    field_11DC44 = (int)obj;
    
    int* someField = *(int**)((char*)obj + 8);
    
    if (radius > 0.0f) {
        return 0;
    }
    return 1;
}
