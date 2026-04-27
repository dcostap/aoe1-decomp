// VA: 004603B0 canLinePath (442B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    int canLinePath(int* a, int* b);
};

int RGE_Moving_Object::canLinePath(int* a, int* b) {
    int ax = a[0];
    int ay = a[1];
    int bx = b[0];
    int by = b[1];
    
    int dx = ax - bx;
    int dy = ay - by;
    
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    
    return (dx + dy);
}
