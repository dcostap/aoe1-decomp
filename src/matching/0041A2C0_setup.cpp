class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Player;

// PDB owner: RGE_Animated_Object::setup in ani_obj.cpp, lines 55-63.
// Body boundary: 0041A2C0-0041A302. The next sibling starts at 0041A310.
class RGE_Static_Object {
public:
    virtual void vf00(void);
    int setup(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    void set_sleep_flag(unsigned char value);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_04[0x4A];
    unsigned char field_4E;
    char gap_4F[0x39];
    int speed;

protected:
    virtual int setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
};

int RGE_Animated_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    RGE_Static_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
    this->field_4E = 0x14;
    this->speed = 0;
    this->set_sleep_flag(0);
    return 1;
}
