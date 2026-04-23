class RGE_Game_World;

void rge_read(int file, void* data, int size);

class RGE_Static_Object {
public:
    virtual void vf00(void);
    int setup(int file, RGE_Game_World* world);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_04[0x4A];
    unsigned char field_4E;
    char gap_4F[0x39];
    int speed;

    int setup(int file, RGE_Game_World* world);
};

int RGE_Animated_Object::setup(int file, RGE_Game_World* world) {
    RGE_Static_Object::setup(file, world);
    this->field_4E = 0x14;
    rge_read(file, &this->speed, 4);
    return 1;
}
