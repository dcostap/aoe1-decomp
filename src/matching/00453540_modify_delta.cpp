#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short hp;
    float los;
    unsigned char obj_max;
    char gap_2D[0x3];
    float radius_x;
    float radius_y;
    char gap_38[0x44];
    short attribute_max_amount;

    void modify_delta(float value, unsigned char op);
};
#endif

void RGE_Master_Static_Object::modify_delta(float value, unsigned char op) {
    switch (op) {
        case 0:
            hp += (short)(long)value;
            break;
        case 1:
            los = (float)((double)value + (double)los);
            break;
        case 2:
            obj_max += (unsigned char)(long)value;
            break;
        case 3:
            radius_x = (float)((double)value + (double)radius_x);
            break;
        case 4:
            radius_y = (float)((double)value + (double)radius_y);
            break;
        case 14:
            attribute_max_amount += (short)(long)value;
            break;
    }
}
