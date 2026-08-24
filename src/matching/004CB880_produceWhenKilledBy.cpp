#ifndef T_C_OBJ_CONTEXT_H
class TRIBE_Combat_Object_Type {
public:
    char gap_00[0x14];
    short object_class;
};

class TRIBE_Combat_Object {
public:
    void* vfptr;
    void* gap_04;
    TRIBE_Combat_Object_Type* type;

    unsigned char produceWhenKilledBy(int cause) const;
};
#endif

#ifdef T_C_OBJ_CONTEXT_H
#define type type_info
#endif

unsigned char TRIBE_Combat_Object::produceWhenKilledBy(int cause) const {
    int object_class;

    object_class = (int)this->type->object_class;
    if ((object_class != 9) && (object_class != 10)) {
        return 1;
    }
    if (cause != 4) {
        return 0;
    }
    return 1;
}

#ifdef T_C_OBJ_CONTEXT_H
#undef type
#endif
