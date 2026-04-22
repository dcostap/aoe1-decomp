class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world, unsigned char flag);
};

class TRIBE_Master_Building_Object : public RGE_Master_Static_Object {
public:
    unsigned char alignment(float* x, float* y, RGE_Game_World* world, unsigned char flag);
};

unsigned char TRIBE_Master_Building_Object::alignment(float* x, float* y, RGE_Game_World* world, unsigned char flag) {
    return RGE_Master_Static_Object::alignment(x, y, world, 1);
}
