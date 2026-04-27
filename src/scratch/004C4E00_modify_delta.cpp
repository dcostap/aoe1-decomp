// VA: 004C4E00 modify_delta (139B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0x18];
    int field_1C;
    char gap20[0x100];
    int field_120;
    
    void modify_delta(int operation, int delta);
};

void RGE_Static_Object::modify_delta(int operation, int delta) {
    int op = operation & 0xFF;
    if (!field_1C) return;
    
    if (op == 0) {
        field_120 = field_120 + delta;
    } else if (op == 1) {
        field_120 = field_120 - delta;
    }
}
