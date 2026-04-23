class RGE_Moving_Object_Master {
public:
    char gap_00[0x64];
    float speed_multiplier;
};

class RGE_Moving_Object_Type {
public:
    char gap_00[0xB8];
    float maximum_speed;
};

class RGE_Moving_Object {
public:
    char gap_00[0x04];
    RGE_Moving_Object_Type* type;
    int gap_0C;
    RGE_Moving_Object_Master* master;

    virtual float maximumSpeed(void);
};

float RGE_Moving_Object::maximumSpeed(void) {
    if (this->master != 0 && this->master->speed_multiplier > 0.0) {
        return this->type->maximum_speed * this->master->speed_multiplier;
    }
    return this->type->maximum_speed;
}
