#ifndef T_C_OBJ_CONTEXT_H
class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
};

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    unsigned char useSameZoneDropsite() const;
};
#endif

unsigned char TRIBE_Combat_Object::useSameZoneDropsite() const {
    int type = (int)((RGE_Static_Object*)this)->master_obj->object_group;
    if (type == 0x15 || type == 0x02) return 0;
    return 1;
}
