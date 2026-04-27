// VA: 0046D770 printState (190B)
// pathsys.cpp

class PathingSystem {
public:
    char gap4[0x11DC28];
    int field_11DC2C;
    int field_11DC30;
    int field_11DC34;
    int field_11DC38;
    
    void printState(int* state);
};

void PathingSystem::printState(int* state) {
    int a = field_11DC38;
    int b = *(int*)((char*)state + 0x144);
    int c = field_11DC2C;
    
    if (a > 0) {
        field_11DC30 = b;
    }
}
