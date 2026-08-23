class VISIBLE_UNIT_REC {
public:
    unsigned char gap_00[0x6];
    unsigned char pos_x;
    unsigned char pos_y;
};

class RGE_Combat_Object {
public:
    int id;
    void* master_obj;
    void* owner;
    unsigned char gap_10[0x28];
    float world_x;
    float world_y;
    unsigned char gap_40[0x154];
    VISIBLE_UNIT_REC* VUR_Ptrs[9];

    float base_teleport(float x, float y, float z);
    virtual float teleport(float x, float y, float z);
};

float RGE_Combat_Object::teleport(float x, float y, float z) {
    VISIBLE_UNIT_REC** vur;
    VISIBLE_UNIT_REC* rec;
    float result;
    int old_x;
    int old_y;
    int new_x;
    int new_y;
    int i;

    old_x = (int)world_x;
    old_y = (int)world_y;
    result = base_teleport(x, y, z);
    if (id >= 0) {
        new_x = (int)world_x;
        new_y = (int)world_y;
        if (new_x != old_x || new_y != old_y) {
            vur = VUR_Ptrs;
            for (i = 0; i < 9; ++i) {
                rec = *vur;
                if (rec != 0) {
                    rec->pos_x = (unsigned char)new_x;
                    rec->pos_y = (unsigned char)new_y;
                }
                ++vur;
            }
        }
    }
    return result;
}
