// VA: 00460570 canLinePath (414B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    int canLinePath(int x1, int y1, int x2, int y2);
};

int RGE_Moving_Object::canLinePath(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    
    return (dx + dy);
}
