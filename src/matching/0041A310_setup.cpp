class RGE_Game_World;

void rge_read(int file, void* data, int size);

class RGE_Static_Object {
public:
    virtual void vf00(void);

protected:
    virtual int setup(int file, RGE_Game_World* world);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_04[0x4A];
    unsigned char field_4E;
    char gap_4F[0x39];
    int speed;

protected:
    virtual int setup(int file, RGE_Game_World* world);
};

// BINARY NOTE: PDB owner is protected RGE_Animated_Object::setup in ani_obj.cpp,
// lines 67-75. The prior setup body is 0041A2C0-0041A302. This body is
// 0041A310-0041A342; the next function starts at 0041A350.
int RGE_Animated_Object::setup(int file, RGE_Game_World* world) {
    RGE_Static_Object::setup(file, world);
    this->field_4E = 0x14;
    rge_read(file, &this->speed, 4);
    return 1;
}
