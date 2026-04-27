// VA: 004C4D80 modify (125B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0x18];
    int field_1C;
    char gap20[0x100];
    int field_120;
    
    void modify(int operation, int value);
};

void RGE_Static_Object::modify(int operation, int value) {
    int op = operation & 0xFF;
    if (!field_1C) return;
    
    if (op == 0) {
        field_120 = value;
    } else if (op == 1) {
        field_120 = field_120 + value;
    }
}
