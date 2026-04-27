// VA: 0050E130 TRIBE_Master_Building_Object::TRIBE_Master_Building_Object (EH-framed)
// PDB source: tm_b_obj.cpp

class TRIBE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(void* file, void* sprites, void* sounds, short id, int flag);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    TRIBE_Master_Building_Object(void* file, void* sprites, void* sounds, short id, int flag);
    int setup(void* file, void* sprites, void* sounds, short id);
};

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(void* file, void* sprites, void* sounds, short id, int flag)
    : TRIBE_Master_Combat_Object(file, sprites, sounds, id, 0)
{
    *(void**)this = (void*)0x576700;
    if (flag != 0) {
        this->setup(file, sprites, sounds, id);
    }
}
