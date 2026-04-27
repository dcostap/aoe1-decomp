// VA: 0045F820 canPath (419B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    int canPath(int x, int y, int z);
};

int RGE_Moving_Object::canPath(int x, int y, int z) {
    if (x < 0) return 0;
    if (y < 0) return 0;
    
    return 1;
}
