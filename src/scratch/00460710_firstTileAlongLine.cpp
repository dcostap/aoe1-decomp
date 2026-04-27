// VA: 00460710 firstTileAlongLine (441B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    int firstTileAlongLine(int* a, int* b);
};

int RGE_Moving_Object::firstTileAlongLine(int* a, int* b) {
    int ax = a[0];
    int ay = a[1];
    int bx = b[0];
    int by = b[1];
    
    int dx = bx - ax;
    int dy = by - ay;
    
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    
    return dx + dy;
}
