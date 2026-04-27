// VA: 0045E970 doTrivialMove (3704B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x84];
    float field_88;
    char gap8C[0x4];
    int field_90;
    
    void doTrivialMove();
};

void RGE_Moving_Object::doTrivialMove() {
    float speed = field_88;
    if (speed > 0.0f) {
        field_90 = (int)speed;
    }
}
