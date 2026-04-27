// VA: 0045C790 recycle_in_to_game (471B)
// move_obj.cpp
// EH frame (/GX)

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    void recycle_in_to_game(int a1);
};

void* __cdecl operator_new(unsigned size);

void RGE_Moving_Object::recycle_in_to_game(int a1) {
    void* buf = operator_new(0x0A);
    if (buf) {
        field_8 = (int)buf;
    }
}
