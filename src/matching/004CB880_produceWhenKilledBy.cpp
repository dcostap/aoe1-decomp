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
    unsigned char produceWhenKilledBy(int cause) const;
};
#endif

unsigned char TRIBE_Combat_Object::produceWhenKilledBy(int cause) const {
    int object_class;

    object_class = (int)((RGE_Static_Object*)this)->master_obj->object_group;
    if ((object_class != 9) && (object_class != 10)) {
        return 1;
    }
    if (cause != 4) {
        return 0;
    }
    return 1;
}
