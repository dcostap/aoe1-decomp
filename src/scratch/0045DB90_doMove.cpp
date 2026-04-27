// VA: 0045DB90 doMove (3543B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x10];
    float field_1C;
    
    void doMove(int x, int y);
};

void RGE_Moving_Object::doMove(int x, int y) {
    field_8 = x;
    field_1C = (float)y;
}
