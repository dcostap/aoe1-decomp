// VA: 0045D1F0 turn_towards (358B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    void turn_towards(int x, int y, int z);
};

int __cdecl sub_0045D150(int this_, int x, int y);

void RGE_Moving_Object::turn_towards(int x, int y, int z) {
    int angle = sub_0045D150((int)this, x, y);
    
    // Turn towards target
    field_8 = angle;
}
