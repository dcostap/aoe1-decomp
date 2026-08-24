#ifndef T_B_OBJ_CONTEXT_H
class RGE_Static_Object;

class TRIBE_Building_Object {
public:
    char gap_00[0x48];
    unsigned char built;
    char gap_49[0x193];
    float build_pts;

    short get_construction_progress();
};
#endif

short TRIBE_Building_Object::get_construction_progress() {
    short points;
    RGE_Static_Object* obj;

    if (built != 0) {
        return 100;
    }
    obj = *(RGE_Static_Object**)((char*)this + 8);
    points = *(short*)((char*)obj + 0x15A);
    if (points == 0) {
        return 100;
    }
    return (short)(build_pts / (float)points * 100.0f);
}
