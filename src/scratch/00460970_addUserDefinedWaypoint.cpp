// VA: 00460970 addUserDefinedWaypoint (425B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x170];
    unsigned char field_174;
    
    void addUserDefinedWaypoint(int x, int y);
};

void RGE_Moving_Object::addUserDefinedWaypoint(int x, int y) {
    if (field_174 != 1) return;
    
    // Add waypoint
    int* vtable = *(int**)this;
    void (*func)(void*, int, int) = (void (*)(void*, int, int))vtable[0];
    func(this, x, y);
}
